ifeq ($(OS),Windows_NT) 
RM = del 

else
RM = rm -rf
endif

all: clean build build_tests run_tests

build:
			
			g++ -o main main.c computing.c 
build_tests:
			
			g++ -o tests tests.c computing.c 
run_tests:
			tests
clean: 
			$(RM)  main.exe tests.exe