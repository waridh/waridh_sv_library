#include "Microaddr_microaddr.h"
#include "Microaddr.h"
#include "verilator.h"

/* Creating a struct for the testcases, similar to unit testing */

struct TestCase {
  const char* name;
  uint8_t reset;
  uint8_t cmd;
  uint16_t load_addr;

}

main() {
  /* The main function */
}
