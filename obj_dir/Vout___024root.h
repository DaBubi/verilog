// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vout.h for the primary calling header

#ifndef VERILATED_VOUT___024ROOT_H_
#define VERILATED_VOUT___024ROOT_H_  // guard

#include "verilated.h"


class Vout__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vout___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_Clk,0,0);
    VL_IN8(i_Switch,0,0);
    VL_OUT8(o_led1,0,0);
    CData/*0:0*/ Led__DOT__r_led1;
    CData/*0:0*/ Led__DOT__r_Switch;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i_Clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vout__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vout___024root(Vout__Syms* symsp, const char* v__name);
    ~Vout___024root();
    VL_UNCOPYABLE(Vout___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
