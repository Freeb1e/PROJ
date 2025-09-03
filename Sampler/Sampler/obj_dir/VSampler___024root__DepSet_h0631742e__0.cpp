// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSampler.h for the primary calling header

#include "VSampler__pch.h"
#include "VSampler___024root.h"

void VSampler___024root___eval_act(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_act\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VSampler___024root___nba_sequent__TOP__0(VSampler___024root* vlSelf);

void VSampler___024root___eval_nba(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_nba\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VSampler___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void VSampler___024root___nba_sequent__TOP__0(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___nba_sequent__TOP__0\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vdly__Sampler__DOT__current_cycle;
    __Vdly__Sampler__DOT__current_cycle = 0;
    CData/*0:0*/ __Vdly__Sampler__DOT__free;
    __Vdly__Sampler__DOT__free = 0;
    CData/*2:0*/ __Vdly__Sampler__DOT__counter;
    __Vdly__Sampler__DOT__counter = 0;
    CData/*3:0*/ __Vdly__Sampler__DOT__rej_cnt_reg;
    __Vdly__Sampler__DOT__rej_cnt_reg = 0;
    // Body
    __Vdly__Sampler__DOT__free = vlSelfRef.Sampler__DOT__free;
    __Vdly__Sampler__DOT__current_cycle = vlSelfRef.Sampler__DOT__current_cycle;
    __Vdly__Sampler__DOT__rej_cnt_reg = vlSelfRef.Sampler__DOT__rej_cnt_reg;
    __Vdly__Sampler__DOT__counter = vlSelfRef.Sampler__DOT__counter;
    if (vlSelfRef.rst_n) {
        if (((IData)(vlSelfRef.en) & (IData)(vlSelfRef.Sampler__DOT__free))) {
            __Vdly__Sampler__DOT__current_cycle = ((IData)(vlSelfRef.mode)
                                                    ? 3U
                                                    : 7U);
            __Vdly__Sampler__DOT__free = 0U;
            __Vdly__Sampler__DOT__counter = 0U;
            vlSelfRef.Sampler__DOT__random_reg[0U] 
                = vlSelfRef.random[0U];
            vlSelfRef.Sampler__DOT__random_reg[1U] 
                = vlSelfRef.random[1U];
            vlSelfRef.Sampler__DOT__random_reg[2U] 
                = vlSelfRef.random[2U];
            vlSelfRef.done = 0U;
            __Vdly__Sampler__DOT__rej_cnt_reg = 0U;
        } else if (vlSelfRef.Sampler__DOT__free) {
            vlSelfRef.done = 0U;
        } else if (((IData)(vlSelfRef.Sampler__DOT__counter) 
                    == (IData)(vlSelfRef.Sampler__DOT__current_cycle))) {
            __Vdly__Sampler__DOT__rej_cnt_reg = vlSelfRef.Sampler__DOT__rej_cnt_reg;
            __Vdly__Sampler__DOT__free = 1U;
            __Vdly__Sampler__DOT__counter = 0U;
            vlSelfRef.done = 1U;
        } else {
            __Vdly__Sampler__DOT__counter = (7U & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.Sampler__DOT__counter)));
            __Vdly__Sampler__DOT__rej_cnt_reg = (0xfU 
                                                 & ((IData)(vlSelfRef.Sampler__DOT__rej_cnt_reg) 
                                                    + (IData)(vlSelfRef.Sampler__DOT__rej_cnt_once)));
            vlSelfRef.done = 0U;
        }
    } else {
        __Vdly__Sampler__DOT__free = 1U;
        __Vdly__Sampler__DOT__counter = 0U;
    }
    vlSelfRef.Sampler__DOT__free = __Vdly__Sampler__DOT__free;
    vlSelfRef.Sampler__DOT__current_cycle = __Vdly__Sampler__DOT__current_cycle;
    vlSelfRef.Sampler__DOT__rej_cnt_reg = __Vdly__Sampler__DOT__rej_cnt_reg;
    vlSelfRef.Sampler__DOT__counter = __Vdly__Sampler__DOT__counter;
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

void VSampler___024root___eval_triggers__act(VSampler___024root* vlSelf);

bool VSampler___024root___eval_phase__act(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_phase__act\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VSampler___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VSampler___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VSampler___024root___eval_phase__nba(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_phase__nba\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VSampler___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSampler___024root___dump_triggers__nba(VSampler___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VSampler___024root___dump_triggers__act(VSampler___024root* vlSelf);
#endif  // VL_DEBUG

void VSampler___024root___eval(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VSampler___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("Sampler.sv", 23, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VSampler___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("Sampler.sv", 23, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VSampler___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VSampler___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VSampler___024root___eval_debug_assertions(VSampler___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root___eval_debug_assertions\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.en & 0xfeU)))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY(((vlSelfRef.mode & 0xfeU)))) {
        Verilated::overWidthError("mode");}
}
#endif  // VL_DEBUG
