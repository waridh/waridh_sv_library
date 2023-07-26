module hex_display_segment(
  input logic[4:0] a,
  output logic[6:0] y
);

always_comb begin
  case(a)
    0: y = 7'b0111111;
    1: y = 7'b0000110;
    2: y = 7'b1011011;
    3: y = 7'b1001111;
    4: y = 7'b1100110;
    5: y = 7'b1101101;
    6: y = 7'b1111101;
    7: y = 7'b0000111;
    8: y = 7'b1111111;
    9: y = 7'b1101111;
    10: y = 7'b1110111;
    11: y = 7'b1111100;
    12: y = 7'b0111001;
    13: y = 7'b1011110;
    14: y = 7'b1111001;
    15: y = 7'b1110001;
    default: y = 0;
  endcase
end // always_comb
endmodule // hex_display_segment
