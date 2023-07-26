module minority(
  input logic a, b, c,
  output logic y
);

always_comb begin
  if ((a + b + c) < 2) y = 1;
  else y = 0;
end // always_comb
endmodule // minority
