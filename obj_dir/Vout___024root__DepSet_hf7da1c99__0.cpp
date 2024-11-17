// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vout.h for the primary calling header

#include "Vout__pch.h"
#include "Vout___024root.h"

void Vout___024root___eval_act(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vout___024root___nba_sequent__TOP__0(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (((~ (IData)(vlSelf->i_Switch)) & (IData)(vlSelf->Led__DOT__r_Switch))) {
        vlSelf->Led__DOT__r_led1 = (1U & (~ (IData)(vlSelf->Led__DOT__r_led1)));
    }
    vlSelf->o_led1 = vlSelf->Led__DOT__r_led1;
    vlSelf->Led__DOT__r_Switch = vlSelf->i_Switch;
}

void Vout___024root___eval_nba(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vout___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vout___024root___eval_triggers__act(Vout___024root* vlSelf);

bool Vout___024root___eval_phase__act(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vout___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vout___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vout___024root___eval_phase__nba(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vout___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vout___024root___dump_triggers__nba(Vout___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vout___024root___dump_triggers__act(Vout___024root* vlSelf);
#endif  // VL_DEBUG

void Vout___024root___eval(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vout___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("out.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vout___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("out.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vout___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vout___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vout___024root___eval_debug_assertions(Vout___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vout__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vout___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_Clk & 0xfeU))) {
        Verilated::overWidthError("i_Clk");}
    if (VL_UNLIKELY((vlSelf->i_Switch & 0xfeU))) {
        Verilated::overWidthError("i_Switch");}
}
#endif  // VL_DEBUG
