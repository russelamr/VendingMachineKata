CC      = g++
CFLAGS  = -g -Wall

all: vendingMachineTester clean

vendingMachineTester: tester.o vendingMachine.o
	$(CC) -o vendingMachineTester 

tester.o: tester.cpp tester.h vendingMachine.h
	$(CC) $(CFLAGS) -c tester.cpp
	
vendingMachine.o: vendingMachine.cpp vendingMachine.h
	$(CC) $(CFLAGS) -c vendingMachine.cpp

clean: 
	$(RM) vendingMachineTester *.o *~