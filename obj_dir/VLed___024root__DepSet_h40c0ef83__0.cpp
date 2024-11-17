// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLed.h for the primary calling header

#include "VLed__pch.h"
#include "VLed__Syms.h"
#include "VLed___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VLed___024root___dump_triggers__ico(VLed___024root* vlSelf);
#endif  // VL_DEBUG

void VLed___024root___eval_triggers__ico(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VLed___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VLed___024root___dump_triggers__act(VLed___024root* vlSelf);
#endif  // VL_DEBUG

void VLed___024root___eval_triggers__act(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((~ (IData)(vlSelf->i_Clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__i_Clk__0)));
    vlSelf->__Vtrigprevexpr___TOP__i_Clk__0 = vlSelf->i_Clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VLed___024root___dump_triggers__act(vlSelf);
    }
#endif
}
