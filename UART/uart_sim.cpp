#include "Vuart.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>
#include <termios.h>
#include <unistd.h>

// Char reading from terminal
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
    // Verilator initialization
    Verilated::commandArgs(argc, argv);

    // UART instance created
    Vuart* top = new Vuart;

    // Simulation of UART module continuously:
    std::cout << "UART Simulation. Enter ASCI symbol: (q to end simulation):" << std::endl;
    while (true) {
        char input_char = getch();
        if (input_char == 'q') break;

        top->Input_bit = 0; 
        top->eval();
        for (int i = 0; i < 8; ++i) {
            top->Input_bit = (input_char >> i) & 1; 
            top->eval();
        }
        top->Input_bit = 1;
        top->eval();

        while (!top->tx_done) {
            top->i_Clk = !top->i_Clk;
            top->eval();
        }

        std::cout << "Receved: " << input_char << std::endl;
    }

    // Delete Verilator instance after simulation
    delete top;
    return 0;
}