// This file will be dedicated to making unit tests

module testinv();
  logic [3:0] a, y;

  inv dut(a, y);

  initial begin
    a = 0; #10;
    assert(y === 1) else $error("0 failed.");
    a = 1; #10;
    assert(y === 0) else $error("1 failed.");
  end

endmodule
