#include "Microaddr_microaddr.h"
#include "Microaddr.h"
#include "verilated.h"

/* Creating a struct for the testcases, similar to unit testing */

struct TestCase {
  const char* name;
  uint8_t reset;
  uint8_t cmd;
  uint16_t load_addr;
  uint16_t expected_addr;
};

/* These are essentially unit tests, but the program remembers the previous
state*/
TestCase test_cases[] {
  {"reset", 1, Microaddr_microaddr::cmd::HOLD, 0, 0},
  {"inc", 0, Microaddr_microaddr::cmd::INC, 0, 1},
  { "none", 0, Microaddr_microaddr::cmd::HOLD, 0, 1},
  {"reset2", 1, Microaddr_microaddr::cmd::HOLD, 0, 0},
  { "load", 0, Microaddr_microaddr::cmd::LOAD, 0xFA, 0xFA},
  { "inc2", 0, Microaddr_microaddr::cmd::INC, 0, 0xFB},
  { "reset3", 1, Microaddr_microaddr::cmd::HOLD, 0, 0},
};

int main(int argc, char** argv, char **env) {
  /* The main function */
  Verilated::commandArgs (argc, argv); // Verilator initialization
  Microaddr* counter = new Microaddr; // Making an instance of the class

  // Initializing the counter module. Very object like.
  counter->clk = 0;
  counter->reset = 0;
  counter->cmd = Microaddr_microaddr::HOLD;
  counter->load_addr = 0;
  counter->eval();

  // While !(Verilated::gotFinish())
  int num_test_cases = sizeof(test_cases)/sizeof(TestCase); // Get size

  for (int k = 0; k < num_test_cases; k++) {
    TestCase *test_case = &test_cases[k]; // Running the current test case

    counter->cmd = test_case->cmd;
    counter->reset = test_case->reset;
    counter->load_addr = test_case->load_addr;
    counter->eval(); // Confirm the input

    counter->clk = 1; // Posedge clock
    counter->eval();
    counter->clk = 0; // Negedge clock
    counter->eval();

    if (counter->addr == test_case->expected_addr)  {
      // The test result came out as expected
      printf("%s: passed\n", test_case->name);
    } else {
      // When the testcase failed
      printf("%s: failed (expected %04x, but got %04x)\n", test_case->name,
      test_case->expected_addr, counter->addr);
    }
  }


  counter->final();
  delete counter;
  exit(0);
}
