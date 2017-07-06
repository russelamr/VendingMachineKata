//Implementation fo the Vending Machine Tester
#include "VendingMachineTester.h"

CPPUNIT_TEST_SUITE_REGISTRATION( VendingMachineTester );

void VendingMachineTester::testInsertQuarter()
{
    CPPUNIT_ASSERT( QUARTER == mVendingMachine.InsertCoin(Quarter));
}

void VendingMachineTester::testInsertNickel()
{
    CPPUNIT_ASSERT( NICKEL == mVendingMachine.InsertCoin(Nickel));
}

void VendingMachineTester::testInsertDime()
{
    CPPUNIT_ASSERT( DIME == mVendingMachine.InsertCoin(Dime));
}

void VendingMachineTester::testInsertPenny()
{
    CPPUNIT_ASSERT( PENNY == mVendingMachine.InsertCoin(Penny));
}

void VendingMachineTester::testInsertCoinAQuarterWithNotEnoughThickness()
{
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.73f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinAQuarterWithTooMuchThickness()
{
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.77f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinAQuarterWithNotEnoughDiameter()
{
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.24f;
    coin.thicknessInMilliMeters = 1.75f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinAQuarterWithTooMuchDiameter()
{
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.28f;
    coin.thicknessInMilliMeters = 1.75f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinAQuarterWithNotEnoughWeight()
{
    Coin coin;
    coin.weightInGrams = 5.690f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.75f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinAQuarterWithTooMuchWeight()
{
    Coin coin;
    coin.weightInGrams = 5.650f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.75f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinANickelWithNotEnoughThickness()
{
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.73f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinANickelWithTooMuchThickness()
{
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.77f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinANickelWithNotEnoughDiameter()
{
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.24f;
    coin.thicknessInMilliMeters = 1.75f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinANickelWithTooMuchDiameter()
{
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.28f;
    coin.thicknessInMilliMeters = 1.75f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinANickelWithNotEnoughWeight()
{
    Coin coin;
    coin.weightInGrams = 5.690f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.75f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinANickelWithTooMuchWeight()
{
    Coin coin;
    coin.weightInGrams = 5.650f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.75f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinADimeWithNotEnoughThickness()
{
    Coin coin;
    coin.weightInGrams = 2.268f;
    coin.diameterInMilliMeters = 17.91f;
    coin.thicknessInMilliMeters = 1.33f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinADimeWithTooMuchThickness()
{
    Coin coin;
    coin.weightInGrams = 2.268f;
    coin.diameterInMilliMeters = 17.91f;
    coin.thicknessInMilliMeters = 1.37f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinADimeWithNotEnoughDiameter()
{
    Coin coin;
    coin.weightInGrams = 2.268f;
    coin.diameterInMilliMeters = 17.89f;
    coin.thicknessInMilliMeters = 1.35f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinADimeWithTooMuchDiameter()
{
    Coin coin;
    coin.weightInGrams = 2.268f;
    coin.diameterInMilliMeters = 17.93f;
    coin.thicknessInMilliMeters = 1.35f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinADimeWithNotEnoughWeight()
{
    Coin coin;
    coin.weightInGrams = 2.248f;
    coin.diameterInMilliMeters = 17.91f;
    coin.thicknessInMilliMeters = 1.35f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::testInsertCoinADimeWithTooMuchWeight()
{
    Coin coin;
    coin.weightInGrams = 2.288f;
    coin.diameterInMilliMeters = 17.91f;
    coin.thicknessInMilliMeters = 1.35f;
    CPPUNIT_ASSERT( INVALID_COIN == mVendingMachine.InsertCoin(coin));
}

void VendingMachineTester::setUp()
{
    Quarter.weightInGrams = quarterWeightInGrams;
	Quarter.thicknessInMilliMeters = quarterThicknessInMilliMeters;
	Quarter.diameterInMilliMeters = quarterDiameterInMilliMeters;
	Nickel.weightInGrams = nickelWeightInGrams;
	Nickel.thicknessInMilliMeters = nickelThicknessInMilliMeters;
	Nickel.diameterInMilliMeters = nickelDiameterInMilliMeters;
	Dime.weightInGrams = dimeWeightInGrams;
	Dime.thicknessInMilliMeters = dimeThicknessInMilliMeters;
	Dime.diameterInMilliMeters = dimeDiameterInMilliMeters;
	Penny.weightInGrams = pennyWeightInGrams;
	Penny.thicknessInMilliMeters = pennyThicknessInMilliMeters;
	Penny.diameterInMilliMeters = pennyDiameterInMilliMeters;
}

void VendingMachineTester::tearDown()
{
    //Nothing to tear down yet
}