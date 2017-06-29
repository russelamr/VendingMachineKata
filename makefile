CC      = g++
CFLAGS  = -g -Wall
LDLIBS = -lcppunit

all: vendingMachineTester

vendingMachineTester: VendingMachine.o VendingMachineTester.o
	$(CC) -o vendingMachineTester VendingMachine.o VendingMachineTester.o $(LDLIBS)

tester.o: VendingMachineTester.cpp VendingMachine.h
	$(CC) $(CFLAGS) -c VendingMachineTester.cpp
	
vendingMachine.o: VendingMachine.h VendingMachine.cpp 
	$(CC) $(CFLAGS) -c VendingMachine.cpp

clean: 
	$(RM) vendingMachineTester *.o *~