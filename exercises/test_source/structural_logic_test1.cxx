#include "StructLogic1.h"
#include "verilated.h"

/* Creating a struct for the testcases, similar to unit testing */

struct TestCase {
  const char* name;
  uint8_t input;
  uint8_t expected_output;
};

/* These are essentially unit tests, but the program remembers the previous
state*/

TestCase test_cases[] = {
  {"0", 0, 1},
  {"1", 1, 0},
  {"2", 2, 0},
  {"3", 3, 1},
  {"4", 4, 1},
  {"5", 5, 1},
  {"6", 6, 0},
  {"7", 7, 0},
};

int bit_idx (int value, int idx) {
  if (value & (1 << idx)) return 1; else return 0;
}

void three_bits(int * a, int * b, int * c, int value) {
  *a = bit_idx(value, 2); *b = bit_idx(value, 1); *c = bit_idx(value, 0);
}

int main(int argc, char** argv, char **env) {
  /* The main function */
  Verilated::commandArgs (argc, argv); // Verilator initialization
  StructLogic1 * structlogic1 = new StructLogic1; // Making an instance of the class

  // Initializing the xor module. 
  structlogic1->a = 0;
  structlogic1->b = 0;
  structlogic1->c = 0;

  int a, b, c;
  structlogic1->eval();

  // While !(Verilated::gotFinish())
  int num_test_cases = sizeof(test_cases)/sizeof(TestCase); // Get size

  for (int k = 0; k < num_test_cases; k++) {
    TestCase *test_case = &test_cases[k]; // Running the current test case

    three_bits(
      &a,
      &b,
      &c,
      test_case->input);

    structlogic1->a = a;
    structlogic1->b = b;
    structlogic1->c = c;

    structlogic1->eval(); // Confirm the input

    if (structlogic1->y == test_case->expected_output)  {
      // The test result came out as expected
      printf("%s: passed\n", test_case->name);
    } else {
      // When the testcase failed
      printf("%s: failed (expected %01x, but got %01x)\n", test_case->name,
      test_case->expected_output, structlogic1->y);
    }
  }


  structlogic1->final();
  delete structlogic1;
  exit(0);
}
