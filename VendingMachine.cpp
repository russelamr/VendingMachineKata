//Vending Machine Implementation
#include "VendingMachine.h"

VendingMachine::VendingMachine(){
    mPerfectQuarter.weightInGrams = quarterWeightInGrams;
    mPerfectQuarter.thicknessInMilliMeters = quarterThicknessInMilliMeters;
    mPerfectQuarter.diameterInMilliMeters = quarterDiameterInMilliMeters;
    mPerfectNickel.weightInGrams = nickelWeightInGrams;
    mPerfectNickel.thicknessInMilliMeters = nickelThicknessInMilliMeters;
    mPerfectNickel.diameterInMilliMeters = nickelDiameterInMilliMeters;
    mPerfectDime.weightInGrams = dimeWeightInGrams;
    mPerfectDime.thicknessInMilliMeters = dimeThicknessInMilliMeters;
    mPerfectDime.diameterInMilliMeters = dimeDiameterInMilliMeters;
    mPerfectPenny.weightInGrams = pennyWeightInGrams;
    mPerfectPenny.thicknessInMilliMeters = pennyThicknessInMilliMeters;
    mPerfectPenny.diameterInMilliMeters = pennyDiameterInMilliMeters;
	mCurrentMessage = INSERT_COIN;
	mCurrentlyInExactChangeMode = true;
	mCurrentAmountInsertedInCents = 0;
	mCurrentStockOfCandy = 0;
	mCurrentStockOfChips = 0;
	mCurrentStockOfCola = 0;
}

void VendingMachine::InsertCoin(Coin inputCoin){
	bool coinAccepted = false;
    if(CheckForAValidCoin(inputCoin, mPerfectQuarter) ){
        mCurrentAmountInsertedInCents += quarterValueInCents;
		mCurrentMessage = CreateNewMessageInDollarsWithAmountCents(AMOUNT, mCurrentAmountInsertedInCents);
		coinAccepted = true;
    } else if(CheckForAValidCoin(inputCoin, mPerfectNickel)){
        mCurrentAmountInsertedInCents += nickelValueInCents;
		mCurrentMessage = CreateNewMessageInDollarsWithAmountCents(AMOUNT,mCurrentAmountInsertedInCents);
		coinAccepted = true;
    } else if(CheckForAValidCoin(inputCoin, mPerfectDime)){
        mCurrentAmountInsertedInCents += dimeValueInCents;
		mCurrentMessage = CreateNewMessageInDollarsWithAmountCents(AMOUNT,mCurrentAmountInsertedInCents);
		coinAccepted = true;
    } else { 
        mCurrentMessage = COIN_REJECTED;
		coinAccepted = false;
    }
	if(coinAccepted){
		mChangeInCurrentTransaction.push_back(inputCoin);
	} else {
		mChangeInReturnSlot.push_back(inputCoin);
	}
}

bool VendingMachine::FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon){
    return fabs(value1 - value2) <= epsilon;
}

bool VendingMachine::CheckForAValidCoin(Coin inputCoin, Coin validCoin){
    if(!FloatValuesAreWithinEpsilon(inputCoin.weightInGrams, validCoin.weightInGrams, mVendingMachineWeightToleranceInGrams)) 
        return false;
    if(!FloatValuesAreWithinEpsilon(inputCoin.thicknessInMilliMeters, validCoin.thicknessInMilliMeters, mVendingMachineThicknessToleranceInMilliMeters)) 
        return false;
    if(!FloatValuesAreWithinEpsilon(inputCoin.diameterInMilliMeters, validCoin.diameterInMilliMeters, mVendingMachineDiameterToleranceInMilliMeters)) 
        return false;
    return true;
}

std::string VendingMachine::GetCurrentMessage(){
	std::string messageToPrint = mCurrentMessage;
	
	//Some values should get reset to after viewed once
	if(mCurrentMessage.compare(THANK_YOU) == 0){
		mCurrentMessage = INSERT_COIN;
	} else if(mCurrentMessage.find(PRICE) == 0){
		mCurrentMessage = INSERT_COIN;
	}
	
	if(mCurrentlyInExactChangeMode && mCurrentMessage.compare(INSERT_COIN) == 0 ){
		messageToPrint = EXACT_CHANGE_ONLY;
	}
	
	return messageToPrint;
}

void VendingMachine::SelectProduct(ProductType productType){
	int productCostInCents = 0;
	switch (productType){
		case COLA:
			mCurrentMessage = AttemptToPurchaseItem(mCurrentAmountInsertedInCents, colaCostInCents, mCurrentStockOfCola);
			break;
		case CANDY:
			mCurrentMessage = AttemptToPurchaseItem(mCurrentAmountInsertedInCents, candyCostInCents, mCurrentStockOfCandy);
			break;
		case CHIPS:
			mCurrentMessage = AttemptToPurchaseItem(mCurrentAmountInsertedInCents, chipsCostInCents, mCurrentStockOfChips);
			break;
		default:
			mCurrentMessage = INVALID_SELECTION;
			return;
	}
}

std::string VendingMachine::CreateNewMessageInDollarsWithAmountCents(std::string tagToPutBeforeAmount, int amountInCents){
	std::stringstream ss;
	float amountInDollars = static_cast<float>(amountInCents) * centsToDollars;
	ss << std::fixed << std::setprecision(2) << amountInDollars;
	return tagToPutBeforeAmount + ss.str();
}

void VendingMachine::SetStockOfCandy(unsigned int stockOfCandy){
	mCurrentStockOfCandy = stockOfCandy;
}

void VendingMachine::SetStockOfChips(unsigned int stockOfChips){
	mCurrentStockOfChips = stockOfChips;
}

void VendingMachine::SetStockOfCola(unsigned int stockOfCola){
	mCurrentStockOfCola = stockOfCola;
}

std::string VendingMachine::AttemptToPurchaseItem(int amountInsertedInCents, int productCostInCents, int &currentStock){
	if(currentStock > 0){
		if(amountInsertedInCents < productCostInCents){
			return CreateNewMessageInDollarsWithAmountCents(PRICE, productCostInCents);
		} else {
			SortCoinsIntoTheirRespectiveChangeSlots(mChangeInCurrentTransaction);
			currentStock--;
			MakeChange(amountInsertedInCents - productCostInCents);
			return THANK_YOU;
		}
	} else {
		return SOLD_OUT;
	}
}

std::vector<Coin> VendingMachine::RemoveChangeFromTheChangeReturnSlot(){
	std::vector<Coin> mChangeInReturnSlotThatIsToBeReturned = mChangeInReturnSlot;
	mChangeInReturnSlot.clear();
	return mChangeInReturnSlotThatIsToBeReturned;
}

void VendingMachine::MakeChange(int amountToBeTurnedIntoChangeInCents){
	int numberOfQuartersToBeReturned = amountToBeTurnedIntoChangeInCents / quarterValueInCents;
	AddOneTypeOfCurrencyToReturnSlot(numberOfQuartersToBeReturned, mCurrentStockOfQuarters);
	int amountLeftToBeTurnedIntoChangeInCents = amountToBeTurnedIntoChangeInCents % quarterValueInCents;
	
	int numberOfDimesToBeReturned = amountLeftToBeTurnedIntoChangeInCents / dimeValueInCents;
	AddOneTypeOfCurrencyToReturnSlot(numberOfDimesToBeReturned, mCurrentStockOfDimes);
	amountLeftToBeTurnedIntoChangeInCents = amountLeftToBeTurnedIntoChangeInCents % dimeValueInCents;
	
	int numberOfNickelsToBeReturned = amountLeftToBeTurnedIntoChangeInCents / nickelValueInCents;
	AddOneTypeOfCurrencyToReturnSlot(numberOfNickelsToBeReturned, mCurrentStockOfNickels);
	
	CheckForTheExactChangeCondition();
}

void VendingMachine::AddOneTypeOfCurrencyToReturnSlot(int numberOfCoinsToAdd, std::vector<Coin> &vectorOfTypeOfCoinsToReturn){
	for(int i=0; i< numberOfCoinsToAdd; i++) {
		mChangeInReturnSlot.push_back(vectorOfTypeOfCoinsToReturn.back());
		vectorOfTypeOfCoinsToReturn.pop_back();
	}
}

void VendingMachine::ReturnCoinsInCurrentTransactionIntoTheChangeReturnSlot(){
	mCurrentMessage = INSERT_COIN;
	mChangeInReturnSlot.insert(mChangeInReturnSlot.end(), mChangeInCurrentTransaction.begin(), mChangeInCurrentTransaction.end());
}

void VendingMachine::SetStockOfDimes(unsigned int numberOfDimes){
	mCurrentStockOfDimes.clear();
	for(int i = 0; i < numberOfDimes; i++){
		mCurrentStockOfDimes.push_back(mPerfectDime);
	}
	CheckForTheExactChangeCondition();
}

void VendingMachine::SetStockOfNickels(unsigned int numberOfNickels){
	mCurrentStockOfNickels.clear();
	for(int i = 0; i < numberOfNickels; i++){
		mCurrentStockOfNickels.push_back(mPerfectNickel);
	}
	CheckForTheExactChangeCondition();
}

void VendingMachine::SetStockOfQuarters(unsigned int numberOfQuarters){
	for(int i = 0; i < numberOfQuarters; i++){
		mCurrentStockOfQuarters.push_back(mPerfectQuarter);
	}
}

void VendingMachine::SortCoinsIntoTheirRespectiveChangeSlots(std::vector<Coin> coins){
	for (std::vector<Coin>::iterator it = coins.begin() ; it != coins.end(); ++it){
		Coin inputCoin = *it;
        if(CheckForAValidCoin(inputCoin, mPerfectQuarter) ){
			mCurrentStockOfQuarters.push_back(inputCoin);
		} else if(CheckForAValidCoin(inputCoin, mPerfectNickel)){
			mCurrentStockOfNickels.push_back(inputCoin);
		} else if(CheckForAValidCoin(inputCoin, mPerfectDime)){
			mCurrentStockOfDimes.push_back(inputCoin);
		} else { 
			mChangeInReturnSlot.push_back(inputCoin);
		}
	}
}

void VendingMachine::CheckForTheExactChangeCondition(){
	if(mCurrentStockOfNickels.size() == 0 || mCurrentStockOfDimes.size() == 0){
		mCurrentlyInExactChangeMode = true;
	} else {
		mCurrentlyInExactChangeMode = false;
	}
}