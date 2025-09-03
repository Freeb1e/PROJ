`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2025/09/01 15:15:05
// Design Name: 
// Module Name: Sampler
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Sampler (
    input               clk,
    input               rst_n,
    input               en,
    input        [95:0] random,
    input               mode,

    output       [5:0]  bin_sampling,
    output       [23:0] rej_sampling,
    output      [3:0]  rej_cnt,
    output              rej_fail,
    output          reg done
);
    reg free;
    reg [2:0] counter;
    wire [11:0] Binomial_sampling;
    wire [23:0] Reject_sampling;
    reg [2:0] current_cycle;
    reg [95:0] random_reg; 
    reg [3:0] rej_cnt_reg;
    assign rej_cnt = (counter==current_cycle) ? (rej_cnt_reg+rej_cnt_once) : 4'b0;
    always_ff @(posedge clk or negedge rst_n) begin
        if(!rst_n)begin
            free<=1'b1;
            counter<=3'd0;
        end else if(en&&free) begin
            current_cycle <= (mode==1) ? 3'd3 : 3'd7;
            free<=1'b0;
            counter<=3'd0;
            random_reg<=random;
            done<=1'b0;
            rej_cnt_reg<=4'b0;
        end else if(!free) begin
            if(counter==current_cycle) begin
                free<=1'b1;
                counter<=3'd0;
                done<=1'b1;
                rej_cnt_reg<=rej_cnt_reg;
            end else begin
                counter<=counter+3'd1;
                done<=1'b0;
                rej_cnt_reg<=rej_cnt_reg + {1'b0, rej_cnt_once};
            end 
        end else begin
                done<=1'b0;
            end
    end
    wire [95:0] temp1 = (random_reg >> (counter * 12));
    assign Binomial_sampling = temp1[11:0];

    //mode 0: binomial sampling
    HammingCalc u_BinomialCalc1 (
        .random_in(Binomial_sampling[5:0]),
        .coeff_out(bin_sampling[2:0])
    );
    HammingCalc u_BinomialCalc2 (
        .random_in(Binomial_sampling[11:6]),
        .coeff_out(bin_sampling[5:3])
    );
    //mode 1: Reject sampling
    wire [95:0] temp2 = (random_reg >> (counter * 24));
    assign Reject_sampling = temp2[23:0];
    wire [2:0] rej_cnt_once;
    RejectSampling u_RejectSampling (
        .random_in(Reject_sampling),
        .sampled_out(rej_sampling),
        .rej_cnt_once(rej_cnt_once),
        .rej_fail(rej_fail) 
    );
endmodule

module HammingCalc (
    input       [5:0]  random_in,
    output      [2:0]  coeff_out
);
    wire [1:0] hm_high,hm_low;
    wire signed [2:0] coeff_raw;
    assign hm_high = random_in[5] + random_in[4] + random_in[3];
    assign hm_low  = random_in[2] + random_in[1] + random_in[0];
    assign coeff_raw = hm_high - hm_low;
    assign coeff_out[2] =(coeff_raw < 0);
    assign coeff_out[1:0] = (coeff_raw<0) ? -coeff_raw[1:0] : coeff_raw[1:0];
endmodule

module RejectSampling(
    input [23:0] random_in,
    output [23:0] sampled_out,
    output [2:0] rej_cnt_once,
    output rej_fail
);
    wire [11:0] random1,random2;
    wire [11:0] coeff1,coeff2;
    wire sampsuccess1,sampsuccess2;
    assign random1 = random_in[11:0];
    assign random2 = random_in[23:12];
    assign sampsuccess1 = (random1 < 3329);
    assign sampsuccess2 = (random2 < 3329);
    assign coeff1 = (sampsuccess1)? random1:12'b0;
    assign coeff2 = (sampsuccess2)? random2:12'b0;
    assign sampled_out = {coeff2, coeff1};
    assign rej_fail = !sampsuccess1 && !sampsuccess2;
    assign rej_cnt_once = {2'b0, sampsuccess1} + {2'b0, sampsuccess2};
endmodule
