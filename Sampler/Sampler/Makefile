.PHONY: build run RUN clean

build:
	verilator --trace -cc Sampler.sv --exe tb_Sampler.cpp --top-module Sampler -Mdir obj_dir
	$(MAKE) -C obj_dir -f VSampler.mk VSampler

run: build
	./obj_dir/VSampler

RUN: run

clean:
	rm -rf obj_dir waveform.vcd