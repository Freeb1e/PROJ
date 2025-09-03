// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSampler__Syms.h"


VL_ATTR_COLD void VSampler___024root__trace_init_sub__TOP__0(VSampler___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root__trace_init_sub__TOP__0\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+33,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+36,0,"random",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 95,0);
    tracep->declBit(c+39,0,"mode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"bin_sampling",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+41,0,"rej_sampling",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+42,0,"rej_cnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+43,0,"rej_fail",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("Sampler", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+33,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+36,0,"random",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 95,0);
    tracep->declBit(c+39,0,"mode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"bin_sampling",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+41,0,"rej_sampling",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+42,0,"rej_cnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+43,0,"rej_fail",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"free",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+3,0,"Binomial_sampling",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+4,0,"Reject_sampling",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+5,0,"current_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declArray(c+6,0,"random_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 95,0);
    tracep->declBus(c+9,0,"rej_cnt_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declArray(c+10,0,"temp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 95,0);
    tracep->declArray(c+13,0,"temp2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 95,0);
    tracep->declBus(c+16,0,"rej_cnt_once",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("u_BinomialCalc1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+17,0,"random_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+18,0,"coeff_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+19,0,"hm_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+20,0,"hm_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+21,0,"coeff_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_BinomialCalc2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+22,0,"random_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+23,0,"coeff_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+24,0,"hm_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+25,0,"hm_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+26,0,"coeff_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_RejectSampling", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+4,0,"random_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+41,0,"sampled_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+16,0,"rej_cnt_once",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+43,0,"rej_fail",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"random1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+28,0,"random2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+29,0,"coeff1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+30,0,"coeff2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+31,0,"sampsuccess1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"sampsuccess2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VSampler___024root__trace_init_top(VSampler___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root__trace_init_top\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VSampler___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VSampler___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VSampler___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VSampler___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VSampler___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VSampler___024root__trace_register(VSampler___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root__trace_register\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VSampler___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VSampler___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VSampler___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VSampler___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VSampler___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root__trace_const_0\n"); );
    // Init
    VSampler___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSampler___024root*>(voidSelf);
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VSampler___024root__trace_full_0_sub_0(VSampler___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VSampler___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root__trace_full_0\n"); );
    // Init
    VSampler___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSampler___024root*>(voidSelf);
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VSampler___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VSampler___024root__trace_full_0_sub_0(VSampler___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSampler___024root__trace_full_0_sub_0\n"); );
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.Sampler__DOT__free));
    bufp->fullCData(oldp+2,(vlSelfRef.Sampler__DOT__counter),3);
    bufp->fullSData(oldp+3,((0xfffU & vlSelfRef.Sampler__DOT__temp1[0U])),12);
    bufp->fullIData(oldp+4,((0xffffffU & vlSelfRef.Sampler__DOT__temp2[0U])),24);
    bufp->fullCData(oldp+5,(vlSelfRef.Sampler__DOT__current_cycle),3);
    bufp->fullWData(oldp+6,(vlSelfRef.Sampler__DOT__random_reg),96);
    bufp->fullCData(oldp+9,(vlSelfRef.Sampler__DOT__rej_cnt_reg),4);
    bufp->fullWData(oldp+10,(vlSelfRef.Sampler__DOT__temp1),96);
    bufp->fullWData(oldp+13,(vlSelfRef.Sampler__DOT__temp2),96);
    bufp->fullCData(oldp+16,(vlSelfRef.Sampler__DOT__rej_cnt_once),3);
    bufp->fullCData(oldp+17,((0x3fU & vlSelfRef.Sampler__DOT__temp1[0U])),6);
    bufp->fullCData(oldp+18,(((VL_GTS_III(32, 0U, VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw))) 
                               << 2U) | (3U & (VL_GTS_III(32, 0U, 
                                                          VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw)))
                                                ? (- (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw))
                                                : (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw))))),3);
    bufp->fullCData(oldp+19,((3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                           >> 5U)) 
                                    + ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                              >> 4U)) 
                                       + (1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                                >> 3U)))))),2);
    bufp->fullCData(oldp+20,((3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                           >> 2U)) 
                                    + ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                              >> 1U)) 
                                       + (1U & vlSelfRef.Sampler__DOT__temp1[0U]))))),2);
    bufp->fullCData(oldp+21,(vlSelfRef.Sampler__DOT__u_BinomialCalc1__DOT__coeff_raw),3);
    bufp->fullCData(oldp+22,((0x3fU & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                       >> 6U))),6);
    bufp->fullCData(oldp+23,(((VL_GTS_III(32, 0U, VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw))) 
                               << 2U) | (3U & (VL_GTS_III(32, 0U, 
                                                          VL_EXTENDS_II(32,3, (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw)))
                                                ? (- (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw))
                                                : (IData)(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw))))),3);
    bufp->fullCData(oldp+24,((3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                           >> 0xbU)) 
                                    + ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                              >> 0xaU)) 
                                       + (1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                                >> 9U)))))),2);
    bufp->fullCData(oldp+25,((3U & ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                           >> 8U)) 
                                    + ((1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                              >> 7U)) 
                                       + (1U & (vlSelfRef.Sampler__DOT__temp1[0U] 
                                                >> 6U)))))),2);
    bufp->fullCData(oldp+26,(vlSelfRef.Sampler__DOT__u_BinomialCalc2__DOT__coeff_raw),3);
    bufp->fullSData(oldp+27,((0xfffU & vlSelfRef.Sampler__DOT__temp2[0U])),12);
    bufp->fullSData(oldp+28,((0xfffU & (vlSelfRef.Sampler__DOT__temp2[0U] 
                                        >> 0xcU))),12);
    bufp->fullSData(oldp+29,(((0xd01U > (0xfffU & vlSelfRef.Sampler__DOT__temp2[0U]))
                               ? (0xfffU & vlSelfRef.Sampler__DOT__temp2[0U])
                               : 0U)),12);
    bufp->fullSData(oldp+30,(((0xd01U > (0xfffU & (
                                                   vlSelfRef.Sampler__DOT__temp2[0U] 
                                                   >> 0xcU)))
                               ? (0xfffU & (vlSelfRef.Sampler__DOT__temp2[0U] 
                                            >> 0xcU))
                               : 0U)),12);
    bufp->fullBit(oldp+31,((0xd01U > (0xfffU & vlSelfRef.Sampler__DOT__temp2[0U]))));
    bufp->fullBit(oldp+32,((0xd01U > (0xfffU & (vlSelfRef.Sampler__DOT__temp2[0U] 
                                                >> 0xcU)))));
    bufp->fullBit(oldp+33,(vlSelfRef.clk));
    bufp->fullBit(oldp+34,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+35,(vlSelfRef.en));
    bufp->fullWData(oldp+36,(vlSelfRef.random),96);
    bufp->fullBit(oldp+39,(vlSelfRef.mode));
    bufp->fullCData(oldp+40,(vlSelfRef.bin_sampling),6);
    bufp->fullIData(oldp+41,(vlSelfRef.rej_sampling),24);
    bufp->fullCData(oldp+42,(vlSelfRef.rej_cnt),4);
    bufp->fullBit(oldp+43,(vlSelfRef.rej_fail));
    bufp->fullBit(oldp+44,(vlSelfRef.done));
}
