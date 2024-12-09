#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vrx.h" // Wygenerowane przez Verilator z Twojego modułu rx.sv

vluint64_t main_time = 0;       // Symulowany czas
double sc_time_stamp () {       // Funkcja wymagana przez Verilator
    return main_time; 
}
void print_binary(unsigned int value, int bit_count){
    for (int i = bit_count -1; i>=0; i--){
        printf("%d", (value >> i) & 1);
    }
}
int main(int argc, char** argv, char** env) {
    Verilated::commandArgs(argc, argv);
    Vrx* top = new Vrx; // Tworzenie instancji modułu top

    // Inicjalizacja VCD dla śledzenia sygnałów
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("simx.vcd");

    // Zmienne do symulacji
    bool clk = 0;
    bool rx_serial = 1;
    bool enable = 0;

    while (main_time < 1200) { // Czas symulacji w cyklach zegara
        if ((main_time % 10) == 1) {  // Przełączanie zegara co 10 jednostek czasu
            clk = !clk;
        }

        top->rx_Clk = clk;
        top->i_RX_serial = rx_serial;
        top->enable = enable;

        // Ustawienie zmiennych wejściowych zgodnie z testbench'em
        if (main_time == 10)  enable = 1; // enable po 10 jednostkach czasu

        if (main_time >= 90 && main_time <= 900 && (main_time % 80 == 10)) {
            // Generowanie sekwencji bitów
            static int bit_count = 0;
            static bool bits[] = {0, 1, 0, 0, 0, 0, 1, 0, 0, 1};
            rx_serial = bits[bit_count++];
            if (bit_count == 10) bit_count = 0;
        }

        // Symulacja jednego cyklu zegara
        top->eval();

        // Zapis do VCD
        tfp->dump(main_time);

        // Wypisywanie stanu
        if (main_time % 10 == 0) {
            printf("Time:%lu o_RX_valid:%d o_RX_active:%d o_RX_byte:%x error:%x bit_counter:%x oversample_counter:%x o_RX_buffer:%x STATE:%x INPUT:%x\n", 
                   main_time, top->o_RX_valid, top->o_RX_active, top->o_RX_byte, top->error, 
                   top->bit_counter, top->oversample_counter, top->o_RX_buffer, top->state, top->i_RX_serial);
        }

        main_time++;
    }

    tfp->close();
    delete top;
    delete tfp;
    exit(0);
}