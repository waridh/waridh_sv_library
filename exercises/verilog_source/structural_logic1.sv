`include "verilog_source/mux8.sv"

module structural_logic1(
  input logic a, b, c,
  output logic y
);

logic d0, d1, d2, d3, d4, d5, d6, d7;
logic [2:0] s;
mux8 mux8_inst (s,
  d0, d1, d2, d3, d4, d5, d6, d7, y
  );

always_comb begin
  s[0] = c;
  s[1] = b;
  s[2] = a;
  d0 = 1;
  d1 = 0;
  d2 = 0;
  d3 = 1;
  d4 = 1;
  d5 = 1;
  d6 = 0;
  d7 = 0;
end // always_comb

endmodule
