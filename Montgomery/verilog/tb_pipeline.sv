`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2025/08/28 14:08:00
// Design Name: 
// Module Name: tb_pipeline
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


module tb_pipeline(

    );
    reg [11:0] a, b;
    reg clk, rst_n, en;
    wire [11:0] r;
    wire busy, done;
    reg [11:0] theory;
    reg [11:0] theory_shift[3:0];
    wire [11:0] theory_buf;
    assign theory_buf = theory_shift[3];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            theory_shift[0] <= 0;
            theory_shift[1] <= 0;
            theory_shift[2] <= 0;
            theory_shift[3] <= 0;
        end else begin
            theory_shift[0] <= theory;
            theory_shift[1] <= theory_shift[0];
            theory_shift[2] <= theory_shift[1];
            theory_shift[3] <= theory_shift[2];
        end
    end

    REDC3329_pipeline #(
        .WIDTH    (12),
        .MOD      (3329),
        .MOD_INV  (3327),
        .R2_MOD   (2385))
    u_REDC3329_pipeline(
        .clk    (clk),
        .rst_n  (rst_n),
        .en     (en),
        .a      (a),
        .b      (b),
        .busy   (busy),
        .done   (done),
        .r      (r)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        rst_n = 0;
        en = 0;
        a = 0;
        b = 0;
        #10 rst_n = 1;
        for (int i = 0; i < 4096; i = i + 1) begin
            for (int j = 0; j < 4096; j = j + 1) begin
                a = i;
                b = j;
                theory = (a * b) % 3329;
                @(negedge clk);
                //wait(done);
                $display("a=%d, b=%d, r=%d, theory_buf=%d", a, b, r, theory_buf);
            end
            @(posedge clk);
            en=0;
            repeat(1000) @(negedge clk);
            en=1;
        end
        $finish;
    end
    wire wrong;
    assign wrong = (done && (r != theory_buf));
endmodule
