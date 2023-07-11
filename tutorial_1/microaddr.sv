
/* Packages can only contain typedefs and functions */
package microaddr;
// Looking at a different way to do states. Also has verilator additions.
typedef enum logic [1:0] {
  HOLD, RESET, INC, LOAD
} cmd /* verilator public */;

endpackage : microaddr
