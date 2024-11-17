#include "VLed.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);

    VLed* top = new VLed(contextp); // Vled, Verilog instance creation

    // CLK simulation, and input simulation
    for (int i = 0; i < 10; ++i) {
        // Generating CLK signal. Verilog wire = {0,1}
        top->i_Clk = (i % 2 == 0); // Gives High==1 when True, Low==0 when False 

        if (i % 2 == 0){
            // It gives CLK=True==HIGH
            top->i_Switch = 1;
            //std::cout <<"Pierwszy If "<< std::endl;
        }
        else{
            // CLK=False==LOW
            top->i_Switch = 0;
            //std::cout <<"Drugi If "<< std::endl;
        }

        // One Cycle Simulation
        top->eval();
        std::cout <<"Current Clk state: " << (i%2 == 0) << std::endl;
        // Wyświetlanie wartości wyjściowej o_led1
        if (i % 2 == 1) { // 
            std::cout << "Cycle: " << i / 2
                      << " | Clk: " << (i % 2 == 0)
                      << " | i_Switch: " << (int)top->i_Switch
                      << " | o_led1: " << (int)top->o_led1
                      << std::endl;
        }
    }

    delete top;
    delete contextp;
    return 0;
}
