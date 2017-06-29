CC      = g++
CFLAGS  = -g -Wall
LDLIBS = -lcppunit

all: vendingMachineTester

vendingMachineTester: VendingMachine.o VendingMachineTester.o main.o
	$(CC) -o vendingMachineTester VendingMachine.o VendingMachineTester.o main.o $(LDLIBS)

main.o: VendingMachine.h VendingMachineTester.h main.cpp 
	$(CC) $(CFLAGS) -c main.cpp
    
VendingMachineTester.o: VendingMachine.h VendingMachineTester.h VendingMachineTester.cpp 
	$(CC) $(CFLAGS) -c VendingMachineTester.cpp
	
vendingMachine.o: VendingMachine.h VendingMachine.cpp 
	$(CC) $(CFLAGS) -c VendingMachine.cpp

clean: 
	$(RM) vendingMachineTester *.o *~
    
test:
	./vendingMachineTester.exe