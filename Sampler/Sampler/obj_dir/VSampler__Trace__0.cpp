// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSampler__Syms.h"


void VSampler___024root__trace_chg_0_sub_0(VSampler___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VSampler___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root__trace_chg_0\n"); );
    // Init
    VSampler___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSampler___024root*>(voidSelf);
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VSampler___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VSampler___024root__trace_chg_0_sub_0(VSampler___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root__trace_chg_0_sub_0\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.Sampler__DOT__free));
        bufp->chgCData(oldp+1,(vlSelfRef.Sampler__DOT__counter),3);
        bufp->chgSData(oldp+2,((0xfffU & vlSelfRef.Sampler__DOT__temp1[0U])),12);
        bufp->chgIData(oldp+3,((0xffffffU & vlSelfRef.Sampler__DOT__temp2[0U])),24);
        bufp->chgCData(oldp+4,(vlSelfRef.Sampler__DOT__current_cycle),3);
        bufp->chgWData(oldp+5,(vlSelfRef.Sampler__DOT__random_reg),96);
        bufp->chgCData(oldp+8,(vlSelfRef.Sampler__DOT__rej_cnt_reg),4);
        bufp->chgWData(oldp+9,(vlSelfRef.Sampler__DOT__temp1),96);
        bufp->chgWData(oldp+12,(vlSelfRef.Sampler__DOT__temp2),96);
        bufp->chgCData(oldp+15,(vlSelfRef.Sampler__DOT__rej_cnt_once),3);
        bufp->chgCData(oldp+16,((0x3fU & vlSelfRef.Sampler__DOT__temp1[0U])),6);
        bufp->chgCData(oldp+17,(((VL_GTS_III(32, 0U, 
                                             VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw))) 
                                  << 2U) | (3U & (VL_GTS_III(32, 0U, 
                                                             VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw)))
                                                   ? 
                                                  (- (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw))
                                                   : (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw))))),3);
        bufp->chgCData(oldp+18,((3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                              >> 5U)) 
                                       + ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                                 >> 4U)) 
                                          + (1U & (
                                                   vlSelfRef.Sampler__DOT__temp1[0U] 
                                                   >> 3U)))))),2);
        bufp->chgCData(oldp+19,((3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                              >> 2U)) 
                                       + ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                                 >> 1U)) 
                                          + (1U & vlSelfRef.Sampler__DOT__temp1[0U]))))),2);
        bufp->chgCData(oldp+20,(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw),3);
        bufp->chgCData(oldp+21,((0x3fU & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                          >> 6U))),6);
        bufp->chgCData(oldp+22,(((VL_GTS_III(32, 0U, 
                                             VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw))) 
                                  << 2U) | (3U & (VL_GTS_III(32, 0U, 
                                                             VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw)))
                                                   ? 
                                                  (- (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw))
                                                   : (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw))))),3);
        bufp->chgCData(oldp+23,((3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                              >> 0xbU)) 
                                       + ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                                 >> 0xaU)) 
                                          + (1U & (
                                                   vlSelfRef.Sampler__DOT__temp1[0U] 
                                                   >> 9U)))))),2);
        bufp->chgCData(oldp+24,((3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                              >> 8U)) 
                                       + ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                                 >> 7U)) 
                                          + (1U & (
                                                   vlSelfRef.Sampler__DOT__temp1[0U] 
                                                   >> 6U)))))),2);
        bufp->chgCData(oldp+25,(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw),3);
        bufp->chgSData(oldp+26,((0xfffU & vlSelfRef.Sampler__DOT__temp2[0U])),12);
        bufp->chgSData(oldp+27,((0xfffU & (vlSelfRef.Sampler__DOT__temp2[0U] 
                                           >> 0xcU))),12);
        bufp->chgSData(oldp+28,(((0xd01U > (0xfffU 
                                            & vlSelfRef.Sampler__DOT__temp2[0U]))
                                  ? (0xfffU & vlSelfRef.Sampler__DOT__temp2[0U])
                                  : 0U)),12);
        bufp->chgSData(oldp+29,(((0xd01U > (0xfffU 
                                            & (vlSelfRef.Sampler__DOT__temp2[0U] 
                                               >> 0xcU)))
                                  ? (0xfffU & (vlSelfRef.Sampler__DOT__temp2[0U] 
                                               >> 0xcU))
                                  : 0U)),12);
        bufp->chgBit(oldp+30,((0xd01U > (0xfffU & vlSelfRef.Sampler__DOT__temp2[0U]))));
        bufp->chgBit(oldp+31,((0xd01U > (0xfffU & (
                                                   vlSelfRef.Sampler__DOT__temp2[0U] 
                                                   >> 0xcU)))));
    }
    bufp->chgBit(oldp+32,(vlSelfRef.clk));
    bufp->chgBit(oldp+33,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+34,(vlSelfRef.en));
    bufp->chgWData(oldp+35,(vlSelfRef.random),96);
    bufp->chgBit(oldp+38,(vlSelfRef.mode));
    bufp->chgCData(oldp+39,(vlSelfRef.bin_sampling),6);
    bufp->chgIData(oldp+40,(vlSelfRef.rej_sampling),24);
    bufp->chgCData(oldp+41,(vlSelfRef.rej_cnt),4);
    bufp->chgBit(oldp+42,(vlSelfRef.rej_fail));
    bufp->chgBit(oldp+43,(vlSelfRef.done));
}

void VSampler___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root__trace_cleanup\n"); );
    // Init
    VSampler___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSampler___024root*>(voidSelf);
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
