#include "Vuart.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>
#include <termios.h>
#include <unistd.h>

// Funkcja do odczytu pojedynczego znaku z klawiatury (bez Entera)
char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main(int argc, char** argv) {
    // Inicjalizacja Verilatora
    Verilated::commandArgs(argc, argv);

    // Tworzenie instancji modułu UART
    Vuart* top = new Vuart;

    // Symulacja w ciągłej pracy
    std::cout << "Symulacja UART. Wprowadź znaki (q aby zakończyć):" << std::endl;
    while (true) {
        // Odczytaj znak z klawiatury
        char input_char = getch();
        if (input_char == 'q') break; // Zakończ symulację po wpisaniu 'q'

        // Symulacja wysłania znaku przez UART (bit po bicie)
        top->i_RX_serial = 0; // Start bit
        top->eval();
        for (int i = 0; i < 8; ++i) {
            top->i_RX_serial = (input_char >> i) & 1; // Bity danych
            top->eval();
        }
        top->i_RX_serial = 1; // Stop bit
        top->eval();

        // Oczekiwanie na odpowiedź UART
        while (!top->o_TX_done) {
            top->i_Clk = !top->i_Clk;
            top->eval();
        }

        // Wyświetlenie odebranego znaku
        std::cout << "Odebrano i wysłano: " << input_char << std::endl;
    }

    // Zakończenie symulacji
    delete top;
    return 0;
}