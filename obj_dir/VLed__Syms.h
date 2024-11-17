// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VLED__SYMS_H_
#define VERILATED_VLED__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VLed.h"

// INCLUDE MODULE CLASSES
#include "VLed___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VLed__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VLed* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VLed___024root                 TOP;

    // CONSTRUCTORS
    VLed__Syms(VerilatedContext* contextp, const char* namep, VLed* modelp);
    ~VLed__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
