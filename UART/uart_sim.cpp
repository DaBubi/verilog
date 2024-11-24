#include "Vuart.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv){
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);

    Vuart* top = new Vuart(contextp);

    bool tr = true;

    
    //Evaluation of one cycle
    top->eval();

    // Delete instances
    delete top;
    delete contextp;
    return 0;
}