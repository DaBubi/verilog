// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vout.h for the primary calling header

#include "Vout__pch.h"
#include "Vout___024root.h"

VL_ATTR_COLD void Vout___024root___eval_static__TOP(Vout___024root* vlSelf);

VL_ATTR_COLD void Vout___024root___eval_static(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_static\n"); );
    // Body
    Vout___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vout___024root___eval_static__TOP(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->Led__DOT__r_led1 = 0U;
    vlSelf->Led__DOT__r_Switch = 0U;
}

VL_ATTR_COLD void Vout___024root___eval_initial(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__i_Clk__0 = vlSelf->i_Clk;
}

VL_ATTR_COLD void Vout___024root___eval_final(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vout___024root___dump_triggers__stl(Vout___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vout___024root___eval_phase__stl(Vout___024root* vlSelf);

VL_ATTR_COLD void Vout___024root___eval_settle(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vout___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("out.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vout___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vout___024root___dump_triggers__stl(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vout___024root___stl_sequent__TOP__0(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->o_led1 = vlSelf->Led__DOT__r_led1;
}

VL_ATTR_COLD void Vout___024root___eval_stl(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vout___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vout___024root___eval_triggers__stl(Vout___024root* vlSelf);

VL_ATTR_COLD bool Vout___024root___eval_phase__stl(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vout___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vout___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vout___024root___dump_triggers__act(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge i_Clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vout___024root___dump_triggers__nba(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge i_Clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vout___024root___ctor_var_reset(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_Clk = VL_RAND_RESET_I(1);
    vlSelf->i_Switch = VL_RAND_RESET_I(1);
    vlSelf->o_led1 = VL_RAND_RESET_I(1);
    vlSelf->Led__DOT__r_led1 = VL_RAND_RESET_I(1);
    vlSelf->Led__DOT__r_Switch = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__i_Clk__0 = VL_RAND_RESET_I(1);
}
