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

void VendingMachineTester::testInsertDime()
{
    CPPUNIT_ASSERT( DIME == mVendingMachine.InsertCoin(2.268f, 17.91f, 1.35f));
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

void VendingMachineTester::testInsertCoinANickelWithNotEnoughThickness()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.670f, 24.26f, 1.73f));
}

void VendingMachineTester::testInsertCoinANickelWithTooMuchThickness()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.670f, 24.26f, 1.77f));
}

void VendingMachineTester::testInsertCoinANickelWithNotEnoughDiameter()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.670f, 24.24f, 1.75f));
}

void VendingMachineTester::testInsertCoinANickelWithTooMuchDiameter()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.670f, 24.28f, 1.75f));
}

void VendingMachineTester::testInsertCoinANickelWithNotEnoughWeight()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.690f, 24.26f, 1.75f));
}

void VendingMachineTester::testInsertCoinANickelWithTooMuchWeight()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(5.650f, 24.26f, 1.75f));
}

void VendingMachineTester::testInsertCoinADimeWithNotEnoughThickness()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(2.268f, 17.91f, 1.33f));
}

void VendingMachineTester::testInsertCoinADimeWithTooMuchThickness()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(2.268f, 17.91f, 1.37f));
}

void VendingMachineTester::testInsertCoinADimeWithNotEnoughDiameter()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(2.268f, 17.89f, 1.35f));
}

void VendingMachineTester::testInsertCoinADimeWithTooMuchDiameter()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(2.268f, 17.93f, 1.35f));
}

void VendingMachineTester::testInsertCoinADimeWithNotEnoughWeight()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(2.248f, 17.91f, 1.35f));
}

void VendingMachineTester::testInsertCoinADimeWithTooMuchWeight()
{
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(2.288f, 17.91f, 1.35f));
}

void VendingMachineTester::setUp()
{
    //Nothing to setup yet
}

void VendingMachineTester::tearDown()
{
    //Nothing to tear down yet
}