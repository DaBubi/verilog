// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vout.h for the primary calling header

#include "Vout__pch.h"
#include "Vout__Syms.h"
#include "Vout___024root.h"

void Vout___024root___ctor_var_reset(Vout___024root* vlSelf);

Vout___024root::Vout___024root(Vout__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vout___024root___ctor_var_reset(this);
}

void Vout___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vout___024root::~Vout___024root() {
}
