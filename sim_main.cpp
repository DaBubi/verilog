#include "VLed.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);

    VLed* top = new VLed(contextp); // Vled, Verilog instance creation

    top->i_Switch = 1;

    // CLK simulation, and input simulation
    for (int i = 0; i < 10; ++i) {
        // Generating CLK signal. Verilog wire = {0,1}
        top->i_Clk = (i % 2 == 0); // Gives High==1 when True, Low==0 when False 
        std::cout<<"---------------------"<< std::endl;
        std::cout <<"i: "<< i << std::endl;

        
        if (i==4 || i==8){
            top->i_Switch = 0;
        }
        // ITS IMPORANT NOT TO SWITCH i_Switch too fast, so the condition inside our module have a time to react
        else if(i==6){
            top->i_Switch=1;
        }
        // One Cycle Simulation
        top->eval();

        // Simulation output on negedge
        if (i % 2 == 1) { // 
            std::cout << "Negedge Cycle: " << i / 2
                      << " | Clk: " << (i % 2 == 0)
                      << " | i_Switch: " << (int)top->i_Switch
                      << " | o_led1: " << (int)top->o_led1
                      << std::endl;
        }
        // Simulation output on posedge
        if (i % 2 == 0) { // 
            std::cout << "Posedge Cycle: " << i / 2
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
