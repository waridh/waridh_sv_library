// This file will be dedicated to making unit tests
`timescale 1ns/1ps
module testinv();
  logic [3:0] a, y;

  inv dut(a, y);

  initial begin
    a = 0; #10;
    assert(y === 14) else $error("0 failed.");
    a = 1; #10;
    assert(y === 14) else $error("1 failed.");
    a = 2; #10;
    assert(y === 13) else $error("2 failed.");
    a = 3; #10;
    assert(y === 12) else $error("3 failed.");
    a = 4; #10;
    assert(y === 11) else $error("4 failed.");
    a = 5; #10;
    assert(y === 10) else $error("5 failed.");
    a = 6; #10;
    assert(y === 9) else $error("6 failed.");
    a = 7; #10;
    assert(y === 8) else $error("7 failed.");
    a = 8; #10;
    assert(y === 7) else $error("8 failed.");
    a = 9; #10;
    assert(y === 6) else $error("9 failed.");
    a = 10; #10;
    assert(y === 5) else $error("10 failed.");
    a = 11; #10;
    assert(y === 4) else $error("11 failed.");
    a = 12; #10;
    assert(y === 3) else $error("12 failed.");
    a = 13; #10;
    assert(y === 2) else $error("13 failed.");
    a = 14; #10;
    assert(y === 1) else $error("14 failed.");
    a = 15; #10;
    assert(y === 0) else $error("15 failed.");
  end
endmodule
