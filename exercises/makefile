V = verilator

gen_xor4:
	$V -Wall -cc verilog_source/xor4.sv --prefix Xor4 --exe test_source/xor4_test.cpp

gen_minority:
	$V -Wall -cc verilog_source/minority.sv --prefix Minority --exe test_source/minority_test.cpp

gen_hex_display:
	$V -Wall -cc verilog_source/hex_display_segment.sv --prefix SegmentDisplay --exe test_source/segment_display.cpp

gen_mux8:
	$V -Wall -cc verilog_source/mux8.sv --prefix Mux8 --exe test_source/mux8_test.cxx

gen_struct1:
	$V -Wall -cc verilog_source/structural_logic1.sv --prefix StructLogic1 --exe test_source/structural_logic_test1.cxx

clean:
	rm -rf obj_dir
