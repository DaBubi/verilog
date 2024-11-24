// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vuart.h for the primary calling header

#ifndef VERILATED_VUART___024ROOT_H_
#define VERILATED_VUART___024ROOT_H_  // guard

#include "verilated.h"


class Vuart__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vuart___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_Clk,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__i_Clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vuart__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vuart___024root(Vuart__Syms* symsp, const char* v__name);
    ~Vuart___024root();
    VL_UNCOPYABLE(Vuart___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
