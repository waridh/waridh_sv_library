#include "Minority.h"
#include "verilated.h"

struct TestCase {
  const char* name;
  uint8_t a;
  uint8_t b;
  uint8_t c;
  uint8_t expected_output;
};

TestCase testcases[] {
  {"basic pass", 0, 0, 0, 1},
  {"basic false", 1, 1, 1, 0},
  {"2 input, 0 output", 1, 0, 1, 0},
  {"1 input, 1 output", 0, 1, 0, 1}
};

int main(int argc, char ** argv, char ** env ) {
  Verilated::commandArgs(argc, argv);
  Minority * minority = new Minority;

  // Initializing the module
  minority->a = 0;
  minority->b = 0;
  minority->c = 0;
  minority->eval();

  //Setting the number of test cases
  int number_cases = sizeof(testcases)/sizeof(TestCase);

  for (int i = 0; i < number_cases; i++) {
    TestCase * testcase = &testcases[i];
    
    // Setting the state of the module to match those of the case
    minority->a = testcase->a;
    minority->b = testcase->b;
    minority->c = testcase->c;
    minority->eval();

    // Conditional checking
    if (minority->y == testcase->expected_output) {
      printf("%s: passed\n", testcase->name);
    } else {
      printf("%s: failed (expected %04x, but got %04x)\n", testcase->name, testcase->expected_output, minority->y);
    }
  }

  minority->final();
  delete minority;
  exit(0);
}
