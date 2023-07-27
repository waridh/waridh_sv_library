#include "Mux8.h"
#include "verilated.h"

/* Creating a struct for the testcases, similar to unit testing */

struct TestCase {
  const char* name;
  uint8_t a;
  uint8_t s;
  uint8_t expected_output;
};

/* These are essentially unit tests, but the program remembers the previous
state*/
TestCase test_cases[] {
  {"0", 0, 0, 0},
  {"Random 1", 0b11011000, 4, 1},
  {"Test3", 0b11011100, 5, 0}
};

int bit_idx ( int value, int idx ) {
  if (value & (1 << idx)) return 1; else return 0;
}

int main(int argc, char** argv, char **env) {
  /* The main function */
  Verilated::commandArgs (argc, argv); // Verilator initialization
  Mux8 * mux8 = new Mux8; // Making an instance of the class

  // Initializing the xor module. 
  mux8->d0 = 0;
  mux8->d1 = 0;
  mux8->d2 = 0;
  mux8->d3 = 0;
  mux8->d4 = 0;
  mux8->d5 = 0;
  mux8->d6 = 0;
  mux8->d7 = 0;
  mux8->s = 0;
  mux8->eval();

  // While !(Verilated::gotFinish())
  int num_test_cases = sizeof(test_cases)/sizeof(TestCase); // Get size

  for (int k = 0; k < num_test_cases; k++) {
    TestCase *test_case = &test_cases[k]; // Running the current test case

    mux8->d0 = bit_idx(test_case->a, 0);
    mux8->d1 = bit_idx(test_case->a, 1);
    mux8->d2 = bit_idx(test_case->a, 2);
    mux8->d3 = bit_idx(test_case->a, 3);
    mux8->d4 = bit_idx(test_case->a, 4);
    mux8->d5 = bit_idx(test_case->a, 5);
    mux8->d6 = bit_idx(test_case->a, 6);
    mux8->d7 = bit_idx(test_case->a, 7);
    mux8->s = test_case->s;
    mux8->eval(); // Confirm the input

    if (mux8->y == test_case->expected_output)  {
      // The test result came out as expected
      printf("%s: passed\n", test_case->name);
    } else {
      // When the testcase failed
      printf("%s: failed (expected %01x, but got %01x)\n", test_case->name,
      test_case->expected_output, mux8->y);
    }
  }


  mux8->final();
  delete mux8;
  exit(0);
}
