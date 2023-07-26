V = verilator

gen_xor4:
	$V -Wall -cc verilog_source/xor4.sv --prefix Xor4 --exe test_source/xor4_test.cpp

gen_minority:
	$V -Wall -cc verilog_source/minority.sv --prefix Minority --exe test_source/minority_test.cpp

gen_hex_display:
	$V -Wall -cc verilog_source/hex_display_segment.sv --prefix SegmentDisplay --exe test_source/segment_display.cpp

clean:
	rm -rf obj_dir
