all: build build_test run_test gcov

build:
			g++ -o main main.cpp Student.cpp workflow.cpp
build_test: 
			g++ --coverage -o test test.cpp Student.cpp workflow.cpp 
run_test:
			./test
gcov:
			gcov workflow.cpp
			gcov Student.cpp	
		

 