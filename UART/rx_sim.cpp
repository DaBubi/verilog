#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vrx.h"

vluint64_t main_time = 0;       
double sc_time_stamp () {       
    return main_time; 
}

void print_binary(unsigned int value, int bit_count){
    for (int i = bit_count -1; i>=0; i--){
        printf("%d", (value >> i) & 1);
    }
}

int main(int argc, char** argv, char** env) {
    Verilated::commandArgs(argc, argv);
    Vrx* top = new Vrx;

    
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("simx.vcd");

    // Zmienne do symulacji
    bool clk = 0;
    bool rx_serial = 1;
    bool enable = 0;


    while (main_time < 110000) { 
        if ((main_time % 10) == 1) {  
            clk = !clk;
        }

        top->rx_Clk = clk;
        top->i_RX_serial = rx_serial;
        top->enable = enable;

        
        if (main_time == 10)  enable = 1; 

        if (main_time >= 90 && main_time < 104170 * 10 && (main_time % 10417 == 0)) {
            static int bit_count = 0;
            static bool bits[] = {0, 1, 0, 0, 0, 0, 1, 0, 0, 1};
            rx_serial = bits[bit_count++];
            if (bit_count == 10) bit_count = 0;
        }

    
        top->eval();

        tfp->dump(main_time);

        if (main_time % 1000 == 0) {
            printf("Time:%lu o_RX_valid:%d o_RX_active:%d o_RX_byte:%x error:%x bit_counter:", 
                main_time, top->o_RX_valid, top->o_RX_active, top->o_RX_byte, top->error);
            
            print_binary(top->bit_counter, 4); 
            printf(" oversample_counter:");
            print_binary(top->oversample_counter, 4); 
            printf(" o_RX_buffer:");
            print_binary(top->o_RX_buffer, 10); 
            printf(" STATE:");
            print_binary(top->state, 3);
            printf(" INPUT:%d\n", top->i_RX_serial);
        }

        main_time++;
    }
    
    tfp->close();
    delete top;
    delete tfp;
    exit(0);
}