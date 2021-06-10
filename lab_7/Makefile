all: build build_test 

build:
			g++ -o main main.cpp Student.cpp workflow.cpp
build_test: 
			
			g++ --coverage test.cpp Student.cpp workflow.cpp -o test
            ./test
	        gcov workflow.cpp
            gcov Student.cpp	
		

 