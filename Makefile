build: compile_main
	g++ -o ./bin/calc.out ./obj/calculator.o ./obj/adder-module.o ./obj/subtractor-module.o ./obj/multiplier-module.o ./obj/divider-module.o ./obj/main.o

compile_main: compile_calculator compile_module
	g++ -c -o ./obj/main.o ./src/main.cc

compile_calculator:
	g++ -c -o ./obj/calculator.o ./src/calculator.cc

compile_module:
	g++ -c -o ./obj/adder-module.o ./src/adder-module.cc
	g++ -c -o ./obj/subtractor-module.o ./src/subtractor-module.cc
	g++ -c -o ./obj/multiplier-module.o ./src/multiplier-module.cc
	g++ -c -o ./obj/divider-module.o ./src/divider-module.cc
