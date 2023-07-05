`timescale 1ns/1ps

module flopr (
  input logic clk,
  input logic reset,
  input logic [3:0] d,
  output logic [3:0] q
);
// Choosing to take the synchronous reset implementation, since the async one
// has some sketchiness associated with it.
always_ff @(posedge clk)
  if (reset) q <= 4'b0;
  else q <= d;
  
endmodule


module flopenr (
  input logic clk,
  input logic reset,
  input logic en,
  input logic [3:0] d,
  output logic [3:0] q
);
// This is a flip-flop async reset enable register

always_ff @(posedge clk, posedge reset)
  if (reset) q <= 4'b0;
  else if (en) q <= d;

endmodule

module sync(
  input logic clk,
  input logic d,
  output logic q);

logic n1;

always_ff @(posedge clk)
  begin
    n1 <= d; // Non-blocking
    q <= n1; // Non-blocking
  end
endmodule