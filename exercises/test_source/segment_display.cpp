#include "SegmentDisplay.h"
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
  {"0", 0, 0b0111111},
  {"1", 1, 0b0000110},
  {"2", 2, 0b1011011},
  {"3", 3, 0b1001111},
  {"4", 4, 0b1100110},
  {"5", 5, 0b1101101},
  {"6", 6, 0b1111101},
  {"7", 7, 0b0000111},
  {"8", 8, 0b1111111},
  {"9", 9, 0b1101111},
  {"A", 10, 0b1110111},
  {"B", 11, 0b1111100},
  {"C", 12, 0b0111001},
  {"D", 13, 0b1011110},
  {"E", 14, 0b1111001},
  {"F", 15, 0b1110001},
};

void print_segment(int segment_input) {
  /* This function will print seven segment art */

    //First line
    if (segment_input & 1) printf(" _ ");

    printf("\n");

    //Second line
    if (segment_input & (1 << 5))
        printf("|");
    else
        printf(" ");

    if (segment_input & (1 << 6))
        printf("_");
    else
        printf(" ");

    if (segment_input & (1 << 1)) printf("|");

    printf("\n");

    //Third line
    if (segment_input & (1 << 4))
        printf("|");
    else
        printf(" ");

    if (segment_input & (1 << 3))
        printf("_");
    else
        printf(" ");

    if (segment_input & (1 << 2)) printf("|");

    printf("\n");
}

int main(int argc, char** argv, char **env) {
  /* The main function */
  Verilated::commandArgs (argc, argv); // Verilator initialization
  SegmentDisplay * segment_display = new SegmentDisplay; // Making an instance of the class

  // Initializing the xor module. 
  segment_display->a = 0;
  segment_display->eval();

  // While !(Verilated::gotFinish())
  int num_test_cases = sizeof(test_cases)/sizeof(TestCase); // Get size

  for (int k = 0; k < num_test_cases; k++) {
    TestCase *test_case = &test_cases[k]; // Running the current test case

    segment_display->a = test_case->a;
    segment_display->eval(); // Confirm the input

    /* Printing the segment to show that I can*/
    print_segment(segment_display->y);

    if (segment_display->y == test_case->expected_output)  {
      // The test result came out as expected
      printf("%s: passed\n", test_case->name);
    } else {
      // When the testcase failed
      printf("%s: failed (expected %04x, but got %04x)\n", test_case->name,
      test_case->expected_output, segment_display->y);
    }
  }


  segment_display->final();
  delete segment_display;
  exit(0);
}
