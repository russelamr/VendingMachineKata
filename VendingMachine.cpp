//Vending Machine Implementation
#include "VendingMachine.h"
#include <iostream>

VendingMachine::VendingMachine(){
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
	currentMessage = INSERT_COIN;
	currentlyInExactChangeMode = true;
	currentAmountInsertedInCents = 0;
	currentStockOfCandy = 0;
	currentStockOfChips = 0;
	currentStockOfCola = 0;
}

void VendingMachine::InsertCoin(Coin inputCoin){
	bool coinAccepted = false;
    if(CheckForAValidCoin(inputCoin, Quarter) ){
        currentAmountInsertedInCents += quarterValueInCents;
		currentMessage = CreateNewMessageInDollarsWithAmountCents(AMOUNT, currentAmountInsertedInCents);
		coinAccepted = true;
    } else if(CheckForAValidCoin(inputCoin, Nickel)){
        currentAmountInsertedInCents += nickelValueInCents;
		currentMessage = CreateNewMessageInDollarsWithAmountCents(AMOUNT,currentAmountInsertedInCents);
		coinAccepted = true;
    } else if(CheckForAValidCoin(inputCoin, Dime)){
        currentAmountInsertedInCents += dimeValueInCents;
		currentMessage = CreateNewMessageInDollarsWithAmountCents(AMOUNT,currentAmountInsertedInCents);
		coinAccepted = true;
    } else { 
        currentMessage = COIN_REJECTED;
		coinAccepted = false;
    }
	if(coinAccepted){
		changeInCurrentTransaction.push_back(inputCoin);
	} else {
		changeInReturnSlot.push_back(inputCoin);
	}
}

bool VendingMachine::FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon){
    return fabs(value1 - value2) <= epsilon;
}

bool VendingMachine::CheckForAValidCoin(Coin inputCoin, Coin validCoin){
    if(!FloatValuesAreWithinEpsilon(inputCoin.weightInGrams, validCoin.weightInGrams, vendingMachineWeightToleranceInGrams)) 
        return false;
    if(!FloatValuesAreWithinEpsilon(inputCoin.thicknessInMilliMeters, validCoin.thicknessInMilliMeters, vendingMachineThicknessToleranceInMilliMeters)) 
        return false;
    if(!FloatValuesAreWithinEpsilon(inputCoin.diameterInMilliMeters, validCoin.diameterInMilliMeters, vendingMachineDiameterToleranceInMilliMeters)) 
        return false;
    return true;
}

std::string VendingMachine::GetCurrentMessage(){
	std::string messageToPrint = currentMessage;
	
	//Some values should get reset to after viewed once
	if(currentMessage.compare(THANK_YOU) == 0){
		currentMessage = INSERT_COIN;
	} else if(currentMessage.find(PRICE) == 0){
		currentMessage = INSERT_COIN;
	}
	
	if(currentlyInExactChangeMode && currentMessage.compare(INSERT_COIN) == 0 ){
		messageToPrint = EXACT_CHANGE_ONLY;
	}
	
	return messageToPrint;
}

void VendingMachine::SelectProduct(ProductType productType){
	int productCostInCents = 0;
	switch (productType){
		case COLA:
			currentMessage = AttemptToPurchaseItem(currentAmountInsertedInCents, colaCostInCents, currentStockOfCola);
			break;
		case CANDY:
			currentMessage = AttemptToPurchaseItem(currentAmountInsertedInCents, candyCostInCents, currentStockOfCandy);
			break;
		case CHIPS:
			currentMessage = AttemptToPurchaseItem(currentAmountInsertedInCents, chipsCostInCents, currentStockOfChips);
			break;
		default:
			currentMessage = INVALID_SELECTION;
			return;
	}
}

std::string VendingMachine::CreateNewMessageInDollarsWithAmountCents(std::string tagToPutBeforeAmount, int amountInCents){
	std::stringstream ss;
	float amountInDollars = static_cast<float>(amountInCents) * centsToDollars;
	ss << std::fixed << std::setprecision(2) << amountInDollars;
	return tagToPutBeforeAmount + ss.str();
}

void VendingMachine::SetStockOfCandy(int stockOfCandy){
	currentStockOfCandy = stockOfCandy;
}

void VendingMachine::SetStockOfChips(int stockOfChips){
	currentStockOfChips = stockOfChips;
}

void VendingMachine::SetStockOfCola(int stockOfCola){
	currentStockOfCola = stockOfCola;
}

std::string VendingMachine::AttemptToPurchaseItem(int amountInsertedInCents, int productCostInCents, int &currentStock){
	if(currentStock > 0){
		if(amountInsertedInCents < productCostInCents){
			return CreateNewMessageInDollarsWithAmountCents(PRICE, productCostInCents);
		} else {
			SortCoinsIntoTheirRespectiveChangeSlots(changeInCurrentTransaction);
			currentStock--;
			MakeChange(amountInsertedInCents - productCostInCents);
			return THANK_YOU;
		}
	} else {
		return SOLD_OUT;
	}
}

std::vector<Coin> VendingMachine::RemoveChangeFromTheChangeReturnSlot(){
	std::vector<Coin> changeInReturnSlotThatIsToBeReturned = changeInReturnSlot;
	changeInReturnSlot.clear();
	return changeInReturnSlotThatIsToBeReturned;
}

void VendingMachine::MakeChange(int amountToBeTurnedIntoChangeInCents){
	int numberOfQuartersToBeReturned = amountToBeTurnedIntoChangeInCents / quarterValueInCents;
	AddOneTypeOfCurrencyToReturnSlot(numberOfQuartersToBeReturned, currentStockOfQuarters);
	int amountLeftToBeTurnedIntoChangeInCents = amountToBeTurnedIntoChangeInCents % quarterValueInCents;
	int numberOfDimesToBeReturned = amountLeftToBeTurnedIntoChangeInCents / dimeValueInCents;
	AddOneTypeOfCurrencyToReturnSlot(numberOfDimesToBeReturned, currentStockOfDimes);
	amountLeftToBeTurnedIntoChangeInCents = amountLeftToBeTurnedIntoChangeInCents % dimeValueInCents;
	int numberOfNickelsToBeReturned = amountLeftToBeTurnedIntoChangeInCents / nickelValueInCents;
	AddOneTypeOfCurrencyToReturnSlot(numberOfNickelsToBeReturned, currentStockOfNickels);
	
	if(currentStockOfNickels.size() == 0){
		currentlyInExactChangeMode = true;
	}
	
	if(currentStockOfDimes.size() == 0){
		currentlyInExactChangeMode = true;
	}
}

void VendingMachine::AddOneTypeOfCurrencyToReturnSlot(int numberOfCoinsToAdd, std::vector<Coin> &vectorOfTypeOfCoinsToReturn){
	for(int i=0; i< numberOfCoinsToAdd; i++) {
		changeInReturnSlot.push_back(vectorOfTypeOfCoinsToReturn.back());
		vectorOfTypeOfCoinsToReturn.pop_back();
	}
}

void VendingMachine::ReturnCoinsInCurrentTransactionIntoTheChangeReturnSlot(){
	currentMessage = INSERT_COIN;
	changeInReturnSlot.insert(changeInReturnSlot.end(), changeInCurrentTransaction.begin(), changeInCurrentTransaction.end());
}

void VendingMachine::SetStockOfDimes(int numberOfDimes){
	currentStockOfDimes.clear();
	for(int i = 0; i < numberOfDimes; i++){
		currentStockOfDimes.push_back(Dime);
	}
	if(currentStockOfDimes.size() == 0){
		currentlyInExactChangeMode = true; 
	} else {
		currentlyInExactChangeMode = false;
	}
}

void VendingMachine::SetStockOfNickels(int numberOfNickels){
	currentStockOfNickels.clear();
	for(int i = 0; i < numberOfNickels; i++){
		currentStockOfNickels.push_back(Nickel);
	}
	if(currentStockOfNickels.size() == 0){
		currentlyInExactChangeMode = true;
	} else {
		currentlyInExactChangeMode = false;
	}
}

void VendingMachine::SetStockOfQuarters(int numberOfQuarters){
	for(int i = 0; i < numberOfQuarters; i++){
		currentStockOfQuarters.push_back(Quarter);
	}
}

void VendingMachine::SortCoinsIntoTheirRespectiveChangeSlots(std::vector<Coin> coins){
	for (std::vector<Coin>::iterator it = coins.begin() ; it != coins.end(); ++it){
		Coin inputCoin = *it;
        if(CheckForAValidCoin(inputCoin, Quarter) ){
			currentStockOfQuarters.push_back(inputCoin);
		} else if(CheckForAValidCoin(inputCoin, Nickel)){
			currentStockOfNickels.push_back(inputCoin);
		} else if(CheckForAValidCoin(inputCoin, Dime)){
			currentStockOfDimes.push_back(inputCoin);
		} else { 
			changeInReturnSlot.push_back(inputCoin);
		}
	}
}