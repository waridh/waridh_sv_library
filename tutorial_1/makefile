

verilate: microaddr.sv microaddr_counter.sv
	verilator -Wall -cc microaddr.sv microaddr_counter.sv --prefix Microaddr

run_test:
	verilator -Wall -cc microaddr.sv microaddr_counter.sv --prefix Microaddr --exe microaddr_counter_test.cpp -CFLAGS "-std=c++11"

clean:
	rm -rf obj_dir
