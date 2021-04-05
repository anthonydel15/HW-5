# Makefile for compiling a single program
# Also includes testing command
#
#

#Variables
CFLAGS = -Wall -std=c++11
CC = g++

# Replace with your own file names in the following two lines.
a.out: pizza.cc
	$(CC) $(CFLAGS) pizza.cc -o a.out


########################### DO NOT MODIFY THIS RULE ############################
#                           make and run the tests                             #
################################################################################
run_tests:
	#sh _TEST/configure.sh
	#$(CC) $(CFLAGS) _TEST/TEST_cases.cc -o _TEST/run_tests && ./_TEST/run_tests -s
	
	# test functionality and show output
	$(CC) $(CFLAGS) pizza.cc -o _TEST/a.out
	sh _TEST/run_tests.sh
#	rm -rf ./_TEST/NO_MAIN.cc ./_TEST/run_tests
################################################################################



clean:
	rm -rf a.out *.o _TEST/a.out _TEST/NO_MAIN.cc _TEST/run_tests
