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
	currentMessage = "";
	currentAmountInsertedInCents= 0.f;
}

void VendingMachine::InsertCoin(Coin inputCoin){
    if(CheckForAValidCoin(inputCoin, Quarter) ){
        currentAmountInsertedInCents += quarterValueInCents;
		currentMessage = CreateNewMessageInDollarsWithAmountCents(AMOUNT, currentAmountInsertedInCents);
    } else if(CheckForAValidCoin(inputCoin, Nickel)){
        currentAmountInsertedInCents += nickelValueInCents;
		currentMessage = CreateNewMessageInDollarsWithAmountCents(AMOUNT,currentAmountInsertedInCents);
    } else if(CheckForAValidCoin(inputCoin, Dime)){
        currentAmountInsertedInCents += dimeValueInCents;
		currentMessage = CreateNewMessageInDollarsWithAmountCents(AMOUNT,currentAmountInsertedInCents);
    } else { 
        currentMessage = COIN_REJECTED;
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
	return currentMessage;
}

void VendingMachine::ResetStateOfVendingMachine(){
	currentAmountInsertedInCents = 0.f;
}

void VendingMachine::SelectProduct(ProductType productType){
	int productCostInCents = 0;
	switch (productType){
		case COLA:
			productCostInCents = colaCostInCents;
			break;
		case CANDY:
			productCostInCents = candyCostInCents;
			break;
	}
	if(currentAmountInsertedInCents < productCostInCents){
		currentMessage = CreateNewMessageInDollarsWithAmountCents(PRICE, productCostInCents);
	} else {
		currentMessage = THANK_YOU;
	}
}

std::string VendingMachine::CreateNewMessageInDollarsWithAmountCents(std::string tagToPutBeforeAmount, int amountInCents){
	std::stringstream ss;
	float amountInDollars = static_cast<float>(amountInCents) * centsToDollars;
	ss << std::fixed << std::setprecision(2) << amountInDollars;
	return tagToPutBeforeAmount + ss.str();
	
}