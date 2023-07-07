module inv(
  input logic [3:0] a,
  output logic [3:0] y
);

always_comb
y = ~a;
endmodule

module fulladder(
  input logic a, b, cin,
  output logic s, cout
);

logic p, g;

always_comb
  begin
    p = a ^ b;
    g = a & b;
    s = p ^ cin;
    cout = g | (p & cin);
  end
endmodule

module sevenseg(
  input logic [3:0] data,
  output logic [6:0] segments
);

always_comb
  case(data)
    // 
    0: segments = 7'b111_1110;
    1: segments = 7'b011_0000;
    2: segments = 7'b110_1101;
    3: segments = 7'b111_1001;
    4: segments = 7'b011_0011;
    5: segments = 7'b101_1011;
    6: segments = 7'b101_1111;
    7: segments = 7'b111_0000;
    8: segments = 7'b111_1111;
    9: segments = 7'b111_0011;
    default: segments = 7'b000_0000;
  endcase
endmodule

module decoder(
input logic [2:0] a,
output logic [7:0] y
);

always_comb
  case(a)
    3'b000: y = 8'b0000_0001;
    3'b001: y = 8'b0000_0010;
    3'b010: y = 8'b0000_0100;
    3'b011: y = 8'b0000_1000;
    3'b100: y = 8'b0001_0000;
    3'b101: y = 8'b0010_0000;
    3'b110: y = 8'b0100_0000;
    3'b111: y = 8'b1000_0000;
    default: y = 8'bxxxx_xxxx; //In case of x or z input.
  endcase
endmodule

module priority_casez(input logic [3:0] a,
                     output logic [3:0] y);
always_comb
  casez(a)
    4'b1???: y = 4'b1000;
    4'b01??: y = 4'b0100;
    4'b001?: y = 4'b0010;
    4'b0001: y = 4'b0001;
    default: y = 4'b0000;
  endcase
endmodule