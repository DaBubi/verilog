// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLed.h for the primary calling header

#include "VLed__pch.h"
#include "VLed___024root.h"

VL_ATTR_COLD void VLed___024root___eval_static__TOP(VLed___024root* vlSelf);

VL_ATTR_COLD void VLed___024root___eval_static(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_static\n"); );
    // Body
    VLed___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void VLed___024root___eval_static__TOP(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->Led__DOT__r_led1 = 0U;
    vlSelf->Led__DOT__r_Switch = 0U;
}

VL_ATTR_COLD void VLed___024root___eval_initial(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__i_Clk__0 = vlSelf->i_Clk;
}

VL_ATTR_COLD void VLed___024root___eval_final(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VLed___024root___dump_triggers__stl(VLed___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VLed___024root___eval_phase__stl(VLed___024root* vlSelf);

VL_ATTR_COLD void VLed___024root___eval_settle(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_settle\n"); );
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
            VLed___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("Led.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VLed___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VLed___024root___dump_triggers__stl(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VLed___024root___stl_sequent__TOP__0(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___stl_sequent__TOP__0\n"); );
    // Body
    VL_WRITEF("r_Switch: %b, i_Switch: %b, i_CLK: %b\n",
              1,vlSelf->Led__DOT__r_Switch,1,(IData)(vlSelf->i_Switch),
              1,vlSelf->i_Clk);
    vlSelf->o_led1 = vlSelf->Led__DOT__r_led1;
}

VL_ATTR_COLD void VLed___024root___eval_stl(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VLed___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VLed___024root___eval_triggers__stl(VLed___024root* vlSelf);

VL_ATTR_COLD bool VLed___024root___eval_phase__stl(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VLed___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VLed___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VLed___024root___dump_triggers__ico(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VLed___024root___dump_triggers__act(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(negedge i_Clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VLed___024root___dump_triggers__nba(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(negedge i_Clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VLed___024root___ctor_var_reset(VLed___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VLed__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VLed___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_Clk = VL_RAND_RESET_I(1);
    vlSelf->i_Switch = VL_RAND_RESET_I(1);
    vlSelf->o_led1 = VL_RAND_RESET_I(1);
    vlSelf->Led__DOT__r_led1 = VL_RAND_RESET_I(1);
    vlSelf->Led__DOT__r_Switch = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__i_Clk__0 = VL_RAND_RESET_I(1);
}
