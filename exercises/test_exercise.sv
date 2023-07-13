`timescale 1ns/1ps
module test_xor4();
  logic [3:0] a;
  logic y;

  xor4 dut(a, y);

  initial begin
    for (int i = 0; i < 16; i++) begin
      a = i; #10;
    end
  end

endmodule
