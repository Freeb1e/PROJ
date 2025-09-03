// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSampler.h for the primary calling header

#include "VSampler__pch.h"
#include "VSampler__Syms.h"
#include "VSampler___024root.h"

void VSampler___024root___ctor_var_reset(VSampler___024root* vlSelf);

VSampler___024root::VSampler___024root(VSampler__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VSampler___024root___ctor_var_reset(this);
}

void VSampler___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VSampler___024root::~VSampler___024root() {
}
