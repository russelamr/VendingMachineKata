//Implementation fo the Vending Machine Tester
#include "VendingMachineTester.h"

CPPUNIT_TEST_SUITE_REGISTRATION( VendingMachineTester );

void VendingMachineTester::testInsertQuarter(){
	mVendingMachine.InsertCoin(Quarter);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare( AMOUNT_25_CENTS)  == 0 );
}

void VendingMachineTester::testInsertNickel(){
	mVendingMachine.InsertCoin(Nickel);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(AMOUNT_05_CENTS) == 0 );
}

void VendingMachineTester::testInsertDime(){
    mVendingMachine.InsertCoin(Dime);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(AMOUNT_10_CENTS) == 0);
}

void VendingMachineTester::testInsertPenny(){
    mVendingMachine.InsertCoin(Penny);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinAQuarterWithNotEnoughThickness(){
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.73f;
	mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinAQuarterWithTooMuchThickness(){
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.77f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinAQuarterWithNotEnoughDiameter(){
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.24f;
    coin.thicknessInMilliMeters = 1.75f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinAQuarterWithTooMuchDiameter(){
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.28f;
    coin.thicknessInMilliMeters = 1.75f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinAQuarterWithNotEnoughWeight(){
    Coin coin;
    coin.weightInGrams = 5.690f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.75f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinAQuarterWithTooMuchWeight(){
    Coin coin;
    coin.weightInGrams = 5.650f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.75f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinANickelWithNotEnoughThickness(){
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.73f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinANickelWithTooMuchThickness(){
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.77f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinANickelWithNotEnoughDiameter(){
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.24f;
    coin.thicknessInMilliMeters = 1.75f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinANickelWithTooMuchDiameter(){
    Coin coin;
    coin.weightInGrams = 5.670f;
    coin.diameterInMilliMeters = 24.28f;
    coin.thicknessInMilliMeters = 1.75f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinANickelWithNotEnoughWeight(){
    Coin coin;
    coin.weightInGrams = 5.690f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.75f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinANickelWithTooMuchWeight(){
    Coin coin;
    coin.weightInGrams = 5.650f;
    coin.diameterInMilliMeters = 24.26f;
    coin.thicknessInMilliMeters = 1.75f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinADimeWithNotEnoughThickness(){
    Coin coin;
    coin.weightInGrams = 2.268f;
    coin.diameterInMilliMeters = 17.91f;
    coin.thicknessInMilliMeters = 1.33f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinADimeWithTooMuchThickness(){
    Coin coin;
    coin.weightInGrams = 2.268f;
    coin.diameterInMilliMeters = 17.91f;
    coin.thicknessInMilliMeters = 1.37f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinADimeWithNotEnoughDiameter(){
    Coin coin;
    coin.weightInGrams = 2.268f;
    coin.diameterInMilliMeters = 17.89f;
    coin.thicknessInMilliMeters = 1.35f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinADimeWithTooMuchDiameter(){
    Coin coin;
    coin.weightInGrams = 2.268f;
    coin.diameterInMilliMeters = 17.93f;
    coin.thicknessInMilliMeters = 1.35f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinADimeWithNotEnoughWeight(){
    Coin coin;
    coin.weightInGrams = 2.248f;
    coin.diameterInMilliMeters = 17.91f;
    coin.thicknessInMilliMeters = 1.35f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testInsertCoinADimeWithTooMuchWeight(){
    Coin coin;
    coin.weightInGrams = 2.288f;
    coin.diameterInMilliMeters = 17.91f;
    coin.thicknessInMilliMeters = 1.35f;
    mVendingMachine.InsertCoin(coin);
    CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(COIN_REJECTED) == 0 );
}

void VendingMachineTester::testSelectColaWithValidFunds(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(COLA);
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(THANK_YOU ) == 0);
}

void VendingMachineTester::testSelectColaWithInvalidFunds(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(COLA);
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(PRICE_100_CENTS ) == 0);
}

void VendingMachineTester::testSelectCandyWithValidFunds(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Dime);
	mVendingMachine.InsertCoin(Nickel);
	mVendingMachine.SelectProduct(CANDY);
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(THANK_YOU ) == 0);
}

void VendingMachineTester::testSelectCandyWithInvalidFunds(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(CANDY);
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(PRICE_65_CENTS ) == 0);
}

void VendingMachineTester::setUp(){
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

void VendingMachineTester::tearDown(){
    //Nothing to tear down yet
}