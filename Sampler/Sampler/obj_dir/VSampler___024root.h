// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSampler.h for the primary calling header

#ifndef VERILATED_VSAMPLER___024ROOT_H_
#define VERILATED_VSAMPLER___024ROOT_H_  // guard

#include "verilated.h"


class VSampler__Syms;

class alignas(VL_CACHE_LINE_BYTES) VSampler___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(en,0,0);
    VL_IN8(mode,0,0);
    VL_OUT8(bin_sampling,5,0);
    VL_OUT8(rej_cnt,3,0);
    VL_OUT8(rej_fail,0,0);
    VL_OUT8(done,0,0);
    CData/*0:0*/ Sampler__DOT__free;
    CData/*2:0*/ Sampler__DOT__counter;
    CData/*2:0*/ Sampler__DOT__current_cycle;
    CData/*3:0*/ Sampler__DOT__rej_cnt_reg;
    CData/*2:0*/ Sampler__DOT__rej_cnt_once;
    CData/*2:0*/ Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw;
    CData/*2:0*/ Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    VL_INW(random,95,0,3);
    VL_OUT(rej_sampling,23,0);
    VlWide<3>/*95:0*/ Sampler__DOT__random_reg;
    VlWide<3>/*95:0*/ Sampler__DOT__temp1;
    VlWide<3>/*95:0*/ Sampler__DOT__temp2;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VSampler__Syms* const vlSymsp;

    // CONSTRUCTORS
    VSampler___024root(VSampler__Syms* symsp, const char* v__name);
    ~VSampler___024root();
    VL_UNCOPYABLE(VSampler___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
