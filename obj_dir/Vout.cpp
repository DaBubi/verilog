// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vout__pch.h"

//============================================================
// Constructors

Vout::Vout(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vout__Syms(contextp(), _vcname__, this)}
    , i_Clk{vlSymsp->TOP.i_Clk}
    , i_Switch{vlSymsp->TOP.i_Switch}
    , o_led1{vlSymsp->TOP.o_led1}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vout::Vout(const char* _vcname__)
    : Vout(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vout::~Vout() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vout___024root___eval_debug_assertions(Vout___024root* vlSelf);
#endif  // VL_DEBUG
void Vout___024root___eval_static(Vout___024root* vlSelf);
void Vout___024root___eval_initial(Vout___024root* vlSelf);
void Vout___024root___eval_settle(Vout___024root* vlSelf);
void Vout___024root___eval(Vout___024root* vlSelf);

void Vout::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vout::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vout___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vout___024root___eval_static(&(vlSymsp->TOP));
        Vout___024root___eval_initial(&(vlSymsp->TOP));
        Vout___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vout___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vout::eventsPending() { return false; }

uint64_t Vout::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vout::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vout___024root___eval_final(Vout___024root* vlSelf);

VL_ATTR_COLD void Vout::final() {
    Vout___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vout::hierName() const { return vlSymsp->name(); }
const char* Vout::modelName() const { return "Vout"; }
unsigned Vout::threads() const { return 1; }
void Vout::prepareClone() const { contextp()->prepareClone(); }
void Vout::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vout::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vout::trace()' called on model that was Verilated without --trace option");
}
