#include "Xor4.h"
#include "verilated.h"

/* Creating a struct for the testcases, similar to unit testing */

struct TestCase {
  const char* name;
  uint8_t a;
  uint8_t expected_output;
};

/* These are essentially unit tests, but the program remembers the previous
state*/
TestCase test_cases[] {
  {"0001", 1, 1},
  {"0010", 2, 1},
  {"0100", 4, 1},
  {"0111", 7, 1},
  {"1000", 8, 1},
  {"1011", 11, 1},
  {"1101", 13, 1},
  {"1110", 14, 1},
  {"0000", 0, 0},
  {"0011", 3, 0},
  {"0101", 5, 0},
  {"0110", 6, 0},
  {"1001", 9, 0},
  {"1010", 10, 0},
  {"1100", 12, 0},
  {"1111", 15, 0},
  {"expected failure", 15, 1}
};

int main(int argc, char** argv, char **env) {
  /* The main function */
  Verilated::commandArgs (argc, argv); // Verilator initialization
  Xor4* xor4 = new Xor4; // Making an instance of the class

  // Initializing the xor module. 
  xor4->a = 0;
  xor4->y = 0;
  xor4->eval();

  // While !(Verilated::gotFinish())
  int num_test_cases = sizeof(test_cases)/sizeof(TestCase); // Get size

  for (int k = 0; k < num_test_cases; k++) {
    TestCase *test_case = &test_cases[k]; // Running the current test case

    xor4->a = test_case->a;
    xor4->eval(); // Confirm the input

    if (xor4->y == test_case->expected_output)  {
      // The test result came out as expected
      printf("%s: passed\n", test_case->name);
    } else {
      // When the testcase failed
      printf("%s: failed (expected %04x, but got %04x)\n", test_case->name,
      test_case->expected_output, xor4->y);
    }
  }


  xor4->final();
  delete xor4;
  exit(0);
}
