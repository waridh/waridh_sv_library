module divideby3FSM(
  input logic clk,
  input logic reset,
  output logic y
);

typedef enum logic [1:0] {S0, S1, S2} statetype;
statetype state, nextstate;

// State register
always_ff @ (posedge clk, posedge reset)
  if (reset)  state <= S0;
  else        state <= nextstate;

// Next state logic
always_comb
  case(state)
    S0:       nextstate = S1;
    S1:       nextstate = S2;
    S2:       nextstate = S0;
    default:  nextstate = S0;
  endcase

// Output logic
assign y = (state == S0);

endmodule

module patternMoore(
  input logic clk,
  input logic reset,
  input logic a,
  output logic y
);
// Defining the three states
typedef enum logic [1:0] {S0, S1, S2} statetype;
statetype state, nextstate;

// State registers
always_ff @(posedge clk, posedge reset)
  if (reset) state <= S0;
  else state <= nextstate;

// Next state logic
always_comb
  case(state)
    S0: if (a)  nextstate = S0;
        else    nextstate = S1;
    S1: if (a)  nextstate = S2;
        else    nextstate = S1;
    S2: if (a)  nextstate = S0;
        else    nextstate = S1;
    default:    nextstate = S0;
  endcase

// Output logic
assign y = (state == S2);

endmodule

module patternMealy(input logic clk,
  input logic reset,
  input logic a,
  output logic y);

typedef enum logic {S0, S1} statetype;
statetype state, nextstate;

// State register
always_ff @(posedge clk, posedge reset)
  if (reset) state <= S0;
  else state <= nextstate;

// Next state logic
always_comb
  case(state)
    S0: if (a)  nextstate = S0;
        else    nextstate = S1;
    S1: if (a)  nextstate = S0;
        else    nextstate = S1;
    default:    nextstate = S0;
  endcase

// output logic
assign y = (a & state == S1);

endmodule


// Unsigned multiplier
module multiplier(input logic [3:0] a, b,
                  output logic [7:0] y);

assign y = a * b;
endmodule

// Signed multiplier
module signed_multiplier(input logic signed [3:0] a, b,
                          output logic signed [7:0] y);
assign y = a * b;
endmodule
