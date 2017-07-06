//Implementation fo the Vending Machine Tester
#include "VendingMachineTester.h"

CPPUNIT_TEST_SUITE_REGISTRATION( VendingMachineTester );

void VendingMachineTester::testInsertQuarter()
{
    CPPUNIT_ASSERT( QUARTER == mVendingMachine.InsertCoin(5.670f, 24.26f, 1.75f));
}

void VendingMachineTester::testInsertNickel()
{
    CPPUNIT_ASSERT( NICKEL == mVendingMachine.InsertCoin(5.0f, 21.21f, 1.95f));
}

void VendingMachineTester::testInsertCoinAQuarterWithNotEnoughThickness()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.670f, 24.26f, 1.73f));
}

void VendingMachineTester::testInsertCoinAQuarterWithTooMuchThickness()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.670f, 24.26f, 1.77f));
}

void VendingMachineTester::testInsertCoinAQuarterWithNotEnoughDiameter()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.670f, 24.24f, 1.75f));
}

void VendingMachineTester::testInsertCoinAQuarterWithTooMuchDiameter()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.670f, 24.28f, 1.75f));
}

void VendingMachineTester::testInsertCoinAQuarterWithNotEnoughWeight()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.690f, 24.26f, 1.75f));
}

void VendingMachineTester::testInsertCoinAQuarterWithTooMuchWeight()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.650f, 24.26f, 1.75f));
}

void VendingMachineTester::setUp()
{
    //Nothing to setup yet
}

void VendingMachineTester::tearDown()
{
    //Nothing to tear down yet
}