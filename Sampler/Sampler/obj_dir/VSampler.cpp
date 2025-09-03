// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSampler__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VSampler::VSampler(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VSampler__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , en{vlSymsp->TOP.en}
    , mode{vlSymsp->TOP.mode}
    , bin_sampling{vlSymsp->TOP.bin_sampling}
    , rej_cnt{vlSymsp->TOP.rej_cnt}
    , rej_fail{vlSymsp->TOP.rej_fail}
    , done{vlSymsp->TOP.done}
    , random{vlSymsp->TOP.random}
    , rej_sampling{vlSymsp->TOP.rej_sampling}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VSampler::VSampler(const char* _vcname__)
    : VSampler(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VSampler::~VSampler() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VSampler___024root___eval_debug_assertions(VSampler___024root* vlSelf);
#endif  // VL_DEBUG
void VSampler___024root___eval_static(VSampler___024root* vlSelf);
void VSampler___024root___eval_initial(VSampler___024root* vlSelf);
void VSampler___024root___eval_settle(VSampler___024root* vlSelf);
void VSampler___024root___eval(VSampler___024root* vlSelf);

void VSampler::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSampler::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSampler___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VSampler___024root___eval_static(&(vlSymsp->TOP));
        VSampler___024root___eval_initial(&(vlSymsp->TOP));
        VSampler___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VSampler___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VSampler::eventsPending() { return false; }

uint64_t VSampler::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VSampler::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VSampler___024root___eval_final(VSampler___024root* vlSelf);

VL_ATTR_COLD void VSampler::final() {
    VSampler___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VSampler::hierName() const { return vlSymsp->name(); }
const char* VSampler::modelName() const { return "VSampler"; }
unsigned VSampler::threads() const { return 1; }
void VSampler::prepareClone() const { contextp()->prepareClone(); }
void VSampler::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VSampler::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VSampler___024root__trace_decl_types(VerilatedVcd* tracep);

void VSampler___024root__trace_init_top(VSampler___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSampler___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSampler___024root*>(voidSelf);
    VSampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VSampler___024root__trace_decl_types(tracep);
    VSampler___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VSampler___024root__trace_register(VSampler___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VSampler::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VSampler::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VSampler___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
