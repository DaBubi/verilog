// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLed.h for the primary calling header

#include "VLed__pch.h"
#include "VLed___024root.h"

void VLed___024root___eval_act(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_act\n"); );
}

VL_INLINE_OPT void VLed___024root___nba_sequent__TOP__0(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___nba_sequent__TOP__0\n"); );
    // Body
    VL_WRITEF("r_Switch: %b, i_Switch: %b, i_CLK: %b\n",
              1,vlSelf->Led__DOT__r_Switch,1,(IData)(vlSelf->i_Switch),
              1,vlSelf->i_Clk);
    if (((~ (IData)(vlSelf->i_Switch)) & (IData)(vlSelf->Led__DOT__r_Switch))) {
        vlSelf->Led__DOT__r_led1 = (1U & (~ (IData)(vlSelf->Led__DOT__r_led1)));
    }
    vlSelf->o_led1 = vlSelf->Led__DOT__r_led1;
    vlSelf->Led__DOT__r_Switch = vlSelf->i_Switch;
}

void VLed___024root___eval_nba(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VLed___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VLed___024root___eval_triggers__act(VLed___024root* vlSelf);

bool VLed___024root___eval_phase__act(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VLed___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VLed___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VLed___024root___eval_phase__nba(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VLed___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VLed___024root___dump_triggers__nba(VLed___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VLed___024root___dump_triggers__act(VLed___024root* vlSelf);
#endif  // VL_DEBUG

void VLed___024root___eval(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VLed___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("Led.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VLed___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("Led.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VLed___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VLed___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VLed___024root___eval_debug_assertions(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_Clk & 0xfeU))) {
        Verilated::overWidthError("i_Clk");}
    if (VL_UNLIKELY((vlSelf->i_Switch & 0xfeU))) {
        Verilated::overWidthError("i_Switch");}
}
#endif  // VL_DEBUG
