// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vuart__pch.h"

//============================================================
// Constructors

Vuart::Vuart(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vuart__Syms(contextp(), _vcname__, this)}
    , i_Clk{vlSymsp->TOP.i_Clk}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vuart::Vuart(const char* _vcname__)
    : Vuart(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vuart::~Vuart() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vuart___024root___eval_debug_assertions(Vuart___024root* vlSelf);
#endif  // VL_DEBUG
void Vuart___024root___eval_static(Vuart___024root* vlSelf);
void Vuart___024root___eval_initial(Vuart___024root* vlSelf);
void Vuart___024root___eval_settle(Vuart___024root* vlSelf);
void Vuart___024root___eval(Vuart___024root* vlSelf);

void Vuart::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vuart::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vuart___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vuart___024root___eval_static(&(vlSymsp->TOP));
        Vuart___024root___eval_initial(&(vlSymsp->TOP));
        Vuart___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vuart___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vuart::eventsPending() { return false; }

uint64_t Vuart::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vuart::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vuart___024root___eval_final(Vuart___024root* vlSelf);

VL_ATTR_COLD void Vuart::final() {
    Vuart___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vuart::hierName() const { return vlSymsp->name(); }
const char* Vuart::modelName() const { return "Vuart"; }
unsigned Vuart::threads() const { return 1; }
void Vuart::prepareClone() const { contextp()->prepareClone(); }
void Vuart::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vuart::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vuart::trace()' called on model that was Verilated without --trace option");
}
