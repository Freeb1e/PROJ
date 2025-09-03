// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSampler.h for the primary calling header

#include "VSampler__pch.h"
#include "VSampler___024root.h"

VL_ATTR_COLD void VSampler___024root___eval_static(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_static\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void VSampler___024root___eval_initial(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_initial\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VSampler___024root___eval_final(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_final\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSampler___024root___dump_triggers__stl(VSampler___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VSampler___024root___eval_phase__stl(VSampler___024root* vlSelf);

VL_ATTR_COLD void VSampler___024root___eval_settle(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_settle\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VSampler___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("Sampler.sv", 23, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VSampler___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSampler___024root___dump_triggers__stl(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___dump_triggers__stl\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VSampler___024root___stl_sequent__TOP__0(VSampler___024root* vlSelf);
VL_ATTR_COLD void VSampler___024root____Vm_traceActivitySetAll(VSampler___024root* vlSelf);

VL_ATTR_COLD void VSampler___024root___eval_stl(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_stl\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VSampler___024root___stl_sequent__TOP__0(vlSelf);
        VSampler___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void VSampler___024root___stl_sequent__TOP__0(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___stl_sequent__TOP__0\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_SHIFTR_WWI(96,96,32, vlSelfRef.Sampler__DOT__temp1, vlSelfRef.Sampler__DOT__random_reg, 
                  ((IData)(0xcU) * (IData)(vlSelfRef.Sampler__DOT__counter)));
    VL_SHIFTR_WWI(96,96,32, vlSelfRef.Sampler__DOT__temp2, vlSelfRef.Sampler__DOT__random_reg, 
                  ((IData)(0x18U) * (IData)(vlSelfRef.Sampler__DOT__counter)));
    vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw 
        = (7U & ((3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                               >> 5U)) + ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                                 >> 4U)) 
                                          + (1U & (
                                                   vlSelfRef.Sampler__DOT__temp1[0U] 
                                                   >> 3U))))) 
                 - (3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                 >> 2U)) + ((1U & (
                                                   vlSelfRef.Sampler__DOT__temp1[0U] 
                                                   >> 1U)) 
                                            + (1U & 
                                               vlSelfRef.Sampler__DOT__temp1[0U]))))));
    vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw 
        = (7U & ((3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                               >> 0xbU)) + ((1U & (
                                                   vlSelfRef.Sampler__DOT__temp1[0U] 
                                                   >> 0xaU)) 
                                            + (1U & 
                                               (vlSelfRef.Sampler__DOT__temp1[0U] 
                                                >> 9U))))) 
                 - (3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                 >> 8U)) + ((1U & (
                                                   vlSelfRef.Sampler__DOT__temp1[0U] 
                                                   >> 7U)) 
                                            + (1U & 
                                               (vlSelfRef.Sampler__DOT__temp1[0U] 
                                                >> 6U)))))));
    vlSelfRef.rej_sampling = ((((0xd01U > (0xfffU & 
                                           (vlSelfRef.Sampler__DOT__temp2[0U] 
                                            >> 0xcU)))
                                 ? (0xfffU & (vlSelfRef.Sampler__DOT__temp2[0U] 
                                              >> 0xcU))
                                 : 0U) << 0xcU) | (
                                                   (0xd01U 
                                                    > 
                                                    (0xfffU 
                                                     & vlSelfRef.Sampler__DOT__temp2[0U]))
                                                    ? 
                                                   (0xfffU 
                                                    & vlSelfRef.Sampler__DOT__temp2[0U])
                                                    : 0U));
    vlSelfRef.rej_fail = (1U & (~ ((0xd01U > (0xfffU 
                                              & vlSelfRef.Sampler__DOT__temp2[0U])) 
                                   | (0xd01U > (0xfffU 
                                                & (vlSelfRef.Sampler__DOT__temp2[0U] 
                                                   >> 0xcU))))));
    vlSelfRef.Sampler__DOT__rej_cnt_once = (7U & ((0xd01U 
                                                   > 
                                                   (0xfffU 
                                                    & vlSelfRef.Sampler__DOT__temp2[0U])) 
                                                  + 
                                                  (0xd01U 
                                                   > 
                                                   (0xfffU 
                                                    & (vlSelfRef.Sampler__DOT__temp2[0U] 
                                                       >> 0xcU)))));
    vlSelfRef.bin_sampling = (((VL_GTS_III(32, 0U, 
                                           VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw))) 
                                << 5U) | (0x18U & (
                                                   (VL_GTS_III(32, 0U, 
                                                               VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw)))
                                                     ? 
                                                    (- (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw))
                                                     : (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw)) 
                                                   << 3U))) 
                              | ((VL_GTS_III(32, 0U, 
                                             VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw))) 
                                  << 2U) | (3U & (VL_GTS_III(32, 0U, 
                                                             VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw)))
                                                   ? 
                                                  (- (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw))
                                                   : (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw)))));
    vlSelfRef.rej_cnt = (((IData)(vlSelfRef.Sampler__DOT__counter) 
                          == (IData)(vlSelfRef.Sampler__DOT__current_cycle))
                          ? (0xfU & ((IData)(vlSelfRef.Sampler__DOT__rej_cnt_reg) 
                                     + (IData)(vlSelfRef.Sampler__DOT__rej_cnt_once)))
                          : 0U);
}

VL_ATTR_COLD void VSampler___024root___eval_triggers__stl(VSampler___024root* vlSelf);

VL_ATTR_COLD bool VSampler___024root___eval_phase__stl(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_phase__stl\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VSampler___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VSampler___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSampler___024root___dump_triggers__act(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___dump_triggers__act\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VSampler___024root___dump_triggers__nba(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___dump_triggers__nba\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VSampler___024root____Vm_traceActivitySetAll(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root____Vm_traceActivitySetAll\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void VSampler___024root___ctor_var_reset(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___ctor_var_reset\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(96, vlSelf->random);
    vlSelf->mode = VL_RAND_RESET_I(1);
    vlSelf->bin_sampling = VL_RAND_RESET_I(6);
    vlSelf->rej_sampling = VL_RAND_RESET_I(24);
    vlSelf->rej_cnt = VL_RAND_RESET_I(4);
    vlSelf->rej_fail = VL_RAND_RESET_I(1);
    vlSelf->done = VL_RAND_RESET_I(1);
    vlSelf->Sampler__DOT__free = VL_RAND_RESET_I(1);
    vlSelf->Sampler__DOT__counter = VL_RAND_RESET_I(3);
    vlSelf->Sampler__DOT__current_cycle = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(96, vlSelf->Sampler__DOT__random_reg);
    vlSelf->Sampler__DOT__rej_cnt_reg = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(96, vlSelf->Sampler__DOT__temp1);
    VL_RAND_RESET_W(96, vlSelf->Sampler__DOT__temp2);
    vlSelf->Sampler__DOT__rej_cnt_once = VL_RAND_RESET_I(3);
    vlSelf->Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw = VL_RAND_RESET_I(3);
    vlSelf->Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
