//Implementation fo the Vending Machine Tester
#include "VendingMachineTester.h"

CPPUNIT_TEST_SUITE_REGISTRATION( VendingMachineTester );

bool VendingMachineTester::CheckIfCoinsAreEqual(Coin inputCoin, Coin validCoin){
	if(!VendingMachine::FloatValuesAreWithinEpsilon(inputCoin.weightInGrams, validCoin.weightInGrams, testerWeightToleranceInGrams)) 
        return false;
    if(!VendingMachine::FloatValuesAreWithinEpsilon(inputCoin.thicknessInMilliMeters, validCoin.thicknessInMilliMeters, testerThicknessToleranceInMilliMeters)) 
        return false;
    if(!VendingMachine::FloatValuesAreWithinEpsilon(inputCoin.diameterInMilliMeters, validCoin.diameterInMilliMeters, testerDiameterToleranceInMilliMeters)) 
        return false;
    return true;
}

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

void VendingMachineTester::testSelectChipsWithValidFunds(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(CHIPS);
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(THANK_YOU ) == 0);
}

void VendingMachineTester::testSelectChipsWithInvalidFunds(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(CHIPS);
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(PRICE_50_CENTS ) == 0);
}

void VendingMachineTester::testSelectInvalidSelection(){
	mVendingMachine.SelectProduct(static_cast<ProductType>(-1));
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(INVALID_SELECTION) == 0);
}

void VendingMachineTester::testInitialMessage(){
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(INSERT_COIN) == 0);
}

void VendingMachineTester::testResetMessageAfterThankYou(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(CHIPS);
	mVendingMachine.GetCurrentMessage();
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(INSERT_COIN) == 0);
}

void VendingMachineTester::testResetMessageAfterPriceMessage(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(CHIPS);
	mVendingMachine.GetCurrentMessage();
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(INSERT_COIN ) == 0);
}

void VendingMachineTester::testMessageDoesNotResetWithTheCurrentAmountInput(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.GetCurrentMessage();
    CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(AMOUNT_25_CENTS ) == 0);
}

void VendingMachineTester::testWhenCandyIsSoldOut(){
	mVendingMachine.SetStockOfCandy(1);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Dime);
	mVendingMachine.InsertCoin(Nickel);
	mVendingMachine.SelectProduct(CANDY);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Dime);
	mVendingMachine.InsertCoin(Nickel);
	mVendingMachine.SelectProduct(CANDY);
	CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(SOLD_OUT) == 0);
}

void VendingMachineTester::testWhenChipsAreSoldOut(){
	mVendingMachine.SetStockOfChips(1);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(CHIPS);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(CHIPS);
	CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(SOLD_OUT) == 0);
}

void VendingMachineTester::testWhenColaIsSoldOut(){
	mVendingMachine.SetStockOfCola(1);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(COLA);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(COLA);
	CPPUNIT_ASSERT( mVendingMachine.GetCurrentMessage().compare(SOLD_OUT) == 0);
}

void VendingMachineTester::testIfAQuarterWillBeReturnedWhenChipsPurchased(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.SelectProduct(CHIPS);
	std::vector<Coin> change = mVendingMachine.RemoveChangeFromTheChangeReturnSlot();
	CPPUNIT_ASSERT(CheckIfCoinsAreEqual(change.at(0), Quarter) && change.size() == 1);
}

void VendingMachineTester::testIfADimeWillBeReturnedWhenChipsPurchased(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Dime);
	mVendingMachine.SelectProduct(CHIPS);
	std::vector<Coin> change = mVendingMachine.RemoveChangeFromTheChangeReturnSlot();
	CPPUNIT_ASSERT(CheckIfCoinsAreEqual(change.at(0), Dime) && change.size() == 1);
}

void VendingMachineTester::testIfMultipleCoinsWillBeReturnedWhenChipsPurchased(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Nickel);
	mVendingMachine.InsertCoin(Dime);
	mVendingMachine.SelectProduct(CHIPS);
	std::vector<Coin> change = mVendingMachine.RemoveChangeFromTheChangeReturnSlot();
	CPPUNIT_ASSERT(CheckIfCoinsAreEqual(change.at(0), Quarter) &&
		CheckIfCoinsAreEqual(change.at(1), Quarter) &&
		CheckIfCoinsAreEqual(change.at(2), Dime) &&
		CheckIfCoinsAreEqual(change.at(3), Nickel) &&
		change.size() == 4);
}

void VendingMachineTester::testReturnChangeWhenOnlyOneQuarterIsPicked(){
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.ReturnCoinsInCurrentTransactionIntoTheChangeReturnSlot();
	std::vector<Coin> change = mVendingMachine.RemoveChangeFromTheChangeReturnSlot();
	CPPUNIT_ASSERT(CheckIfCoinsAreEqual(change.at(0), Quarter) && change.size() == 1);
}

void VendingMachineTester::testReturnChangeWhenOnlyOneNickelIsPicked(){
	mVendingMachine.InsertCoin(Nickel);
	mVendingMachine.ReturnCoinsInCurrentTransactionIntoTheChangeReturnSlot();
	std::vector<Coin> change = mVendingMachine.RemoveChangeFromTheChangeReturnSlot();
	CPPUNIT_ASSERT(CheckIfCoinsAreEqual(change.at(0), Nickel) && change.size() == 1);
}

void VendingMachineTester::testReturnChangeWhenMultipleCoinsAreInsterted(){
	mVendingMachine.InsertCoin(Nickel);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Nickel);
	mVendingMachine.InsertCoin(Dime);
	mVendingMachine.ReturnCoinsInCurrentTransactionIntoTheChangeReturnSlot();
	std::vector<Coin> change = mVendingMachine.RemoveChangeFromTheChangeReturnSlot();
	CPPUNIT_ASSERT(
		CheckIfCoinsAreEqual(change.at(0), Nickel) && 
		CheckIfCoinsAreEqual(change.at(1), Quarter) && 
		CheckIfCoinsAreEqual(change.at(2), Nickel) && 
		CheckIfCoinsAreEqual(change.at(3), Dime) && 
		change.size() == 4);
}

void VendingMachineTester::testVendingMachineShowsInsertCoinAfterChangeIsReturned(){
	mVendingMachine.InsertCoin(Nickel);
	mVendingMachine.ReturnCoinsInCurrentTransactionIntoTheChangeReturnSlot();
	CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(INSERT_COIN) == 0);
}

void VendingMachineTester::testVendingMachineDoesNotTryToReturnTheSameChangeMultipleTimes(){
	mVendingMachine.InsertCoin(Nickel);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.ReturnCoinsInCurrentTransactionIntoTheChangeReturnSlot();
	mVendingMachine.RemoveChangeFromTheChangeReturnSlot();
	std::vector<Coin> change = mVendingMachine.RemoveChangeFromTheChangeReturnSlot();
	CPPUNIT_ASSERT(change.size() == 0);
}

void VendingMachineTester::testIfRejectedCoinCanBeReceivedOutOfTheChangeReturnSlot(){
	Coin invalidCoin;
	invalidCoin.weightInGrams = 99.0f;
	invalidCoin.diameterInMilliMeters = 99.0f;
	invalidCoin.thicknessInMilliMeters = 99.0f;
	mVendingMachine.InsertCoin(Penny);
	mVendingMachine.InsertCoin(invalidCoin);
	std::vector<Coin> change = mVendingMachine.RemoveChangeFromTheChangeReturnSlot();
	CPPUNIT_ASSERT( 
		change.size() == 2  &&
		CheckIfCoinsAreEqual(change.at(0), Penny) &&
		CheckIfCoinsAreEqual(change.at(1), invalidCoin)
		);
}

void VendingMachineTester::testIfExactChangeMessageWillBeDisplayedIfVendingMachineDoesNotStockEnoughDimesToGiveBack(){
	mVendingMachine.SetStockOfDimes(0);
	CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(EXACT_CHANGE_ONLY) == 0);
}

void VendingMachineTester::testIfExactChangeMessageWillBeDisplayedIfVendingMachineDoesNotStockEnoughNickelsToGiveBack(){
	mVendingMachine.SetStockOfNickels(0);
	CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(EXACT_CHANGE_ONLY) == 0);
}

void VendingMachineTester::testIfExactChangeMessageWillBeDisplayedIfVendingMachineDoesNotHaveEnoughNickelsToGiveBackAfterPurchase(){
	mVendingMachine.SetStockOfNickels(1);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Dime);
	mVendingMachine.InsertCoin(Dime);
	mVendingMachine.SelectProduct(CANDY);
	CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(EXACT_CHANGE_ONLY) == 0);
}

void VendingMachineTester::testIfExactChangeMessageWillBeDisplayedIfVendingMachineDoesNotHaveEnoughDimesToGiveBackAfterPurchase(){
	mVendingMachine.SetStockOfDimes(1);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);
	mVendingMachine.InsertCoin(Quarter);;
	mVendingMachine.SelectProduct(CANDY);
	CPPUNIT_ASSERT(mVendingMachine.GetCurrentMessage().compare(EXACT_CHANGE_ONLY) == 0);
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
	mVendingMachine.SetStockOfCandy(5);
	mVendingMachine.SetStockOfChips(5);
	mVendingMachine.SetStockOfCola(5);
	mVendingMachine.SetStockOfDimes(10);
	mVendingMachine.SetStockOfNickels(10);
}

void VendingMachineTester::tearDown(){
    //Nothing to tear down yet
}