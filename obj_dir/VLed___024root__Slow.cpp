// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLed.h for the primary calling header

#include "VLed__pch.h"
#include "VLed__Syms.h"
#include "VLed___024root.h"

void VLed___024root___ctor_var_reset(VLed___024root* vlSelf);

VLed___024root::VLed___024root(VLed__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VLed___024root___ctor_var_reset(this);
}

void VLed___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VLed___024root::~VLed___024root() {
}
