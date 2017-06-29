//Implementation fo the Vending Machine Tester
#include "VendingMachineTester.h"

CPPUNIT_TEST_SUITE_REGISTRATION( VendingMachineTester );

void VendingMachineTester::testInsertQuarter()
{
    CPPUNIT_ASSERT( QUARTER == mVendingMachine.InsertCoin(5.670f));
}

void VendingMachineTester::testInsertNickel()
{
    CPPUNIT_ASSERT( NICKEL == mVendingMachine.InsertCoin(5.0f));
}

void VendingMachineTester::setUp()
{
    //Nothing to setup yet
}

void VendingMachineTester::tearDown()
{
    //Nothing to tear down yet
}