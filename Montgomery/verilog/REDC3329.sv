`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// combany: 
// Engineer: 
// 
// Create Date: 2025/08/28 13:29:54
// Design Name: 
// Module Name: REDC3329
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

module REDC3329_pipeline(
    input clk,
    input rst_n,
    input en,
    input [11:0] a,
    input [11:0] b,
    output busy,
    output done,
    output reg [11:0] r
);
    parameter WIDTH = 12;
    parameter MOD = 3329;
    parameter MOD_INV = 3327;
    parameter R2_MOD = 2385;

    reg [WIDTH-1:0] A,B;
    reg [WIDTH-1:0] A_MONT, B_MONT;
    reg [WIDTH-1:0] r_MONT;
    wire [WIDTH-1:0] A_MONT_buffer,B_MONT_buffer;
    wire [WIDTH-1:0] r_MONT_buffer;
    reg  [WIDTH-1:0] r_buffer;
    reg [3:0] data_valid;

    always_ff@(posedge clk or negedge rst_n)begin
        if(!rst_n)begin
            A<=0;
            B<=0;     
        end else begin           
            data_valid[0]<=en;
            if(en)begin
                A<=a;
                B<=b;
            end
            data_valid[1]<=data_valid[0];
            data_valid[2]<=data_valid[1];
            data_valid[3]<=data_valid[2];
            A_MONT<=A_MONT_buffer;
            B_MONT<=B_MONT_buffer;
            r_MONT<=r_MONT_buffer;
            r<=r_buffer;
        end
    end
    
    assign busy=|data_valid;
    assign done=data_valid[3];
   
    REDC_unit_comb REDC_unit_comb_inst1(
        .a(A),
        .b(R2_MOD),
        .r(A_MONT_buffer)
    );
    REDC_unit_comb REDC_unit_comb_inst2(
        .a(B),
        .b(R2_MOD),
        .r(B_MONT_buffer)
    );
    REDC_unit_comb REDC_unit_comb_inst3(
        .a(A_MONT),
        .b(B_MONT),
        .r(r_MONT_buffer)
    );
    REDC_unit_comb REDC_unit_comb_inst4(
        .a(r_MONT),
        .b(1),
        .r(r_buffer)
    );

    
endmodule

module REDC3329_comb(
   // input clk,
   // input rst_n,
    //input en,
    input [WIDTH-1:0] a,
    input [WIDTH-1:0] b,
   // output busy,
    //output done,
    output [WIDTH-1:0] r
    );
    parameter WIDTH = 12;
    parameter MOD = 3329;
    parameter MOD_INV = 3327;
    parameter R2_MOD = 2385; 

    wire [WIDTH-1:0] A_MONT, B_MONT;
    wire [WIDTH-1:0] r_MONT;
    REDC_unit_comb REDC_unit_comb_inst1(
        .a(a),
        .b(R2_MOD),
        .r(A_MONT)
    );
    REDC_unit_comb REDC_unit_comb_inst2(
        .a(b),
        .b(R2_MOD),
        .r(B_MONT)
    );
    REDC_unit_comb REDC_unit_comb_inst3(
        .a(A_MONT),
        .b(B_MONT),
        .r(r_MONT)
    );
    REDC_unit_comb REDC_unit_comb_inst4(
        .a(r_MONT),
        .b(1),
        .r(r)
    );
endmodule

module REDC_unit_comb(
    input [11:0] a,
    input [11:0] b,
    output [11:0] r
);
    parameter WIDTH = 12;
    parameter MOD = 3329;
    parameter MOD_INV = 3327;
    wire [2*WIDTH-1:0] T;
    wire [WIDTH-1:0] m;
    assign T=a*b;
    assign m=((T[WIDTH-1:0])*MOD_INV)&({WIDTH{1'b1}});
    wire [2*WIDTH-1:0] result_raw;
    assign result_raw=(T+m*MOD)>>WIDTH;
    wire [12:0] r_raw;
    assign r_raw=(result_raw[12:0]>=MOD)?(result_raw[12:0]-MOD):result_raw[12:0];
    assign r=r_raw[11:0];
endmodule
