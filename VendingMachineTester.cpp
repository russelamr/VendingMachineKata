//Implementation fo the Vending Machine Tester
#include "VendingMachineTester.h"

CPPUNIT_TEST_SUITE_REGISTRATION( VendingMachineTester );

void VendingMachineTester::testInsertQuarter(void)
{
    CPPUNIT_ASSERT( mVendingMachine.InsertCoin(5.670f));
}

void VendingMachineTester::setUp(void)
{
    //Nothing to setup yet
}

void VendingMachineTester::tearDown(void)
{
    //Nothing to tear down yet
}