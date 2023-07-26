module xor4(
  input logic [3:0] a,
  output logic y
);

always_comb begin

  // There is no simplification for the circuit
  case (a)
  1: y = 1;
  2: y = 1;
  4: y = 1;
  7: y = 1;
  8: y = 1;
  11: y = 1;
  13: y = 1;
  14: y = 1;
  default: y = 0;
  endcase
end // always_comb

endmodule // xor4
