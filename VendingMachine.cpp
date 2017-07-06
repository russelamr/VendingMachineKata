//Vending Machine Implementation
#include "VendingMachine.h"

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
	currentAmountInsertedInDollars = 0.f;
}

void VendingMachine::InsertCoin(Coin inputCoin){
    if(CheckForAValidCoin(inputCoin, Quarter) ){
        currentAmountInsertedInDollars += quarterValueInDollars;
		currentMessage = CreateNewMessageWithNewInstertedAmount(currentAmountInsertedInDollars);
    } else if(CheckForAValidCoin(inputCoin, Nickel)){
        currentAmountInsertedInDollars += nickelValueInDollars;
		currentMessage = CreateNewMessageWithNewInstertedAmount(currentAmountInsertedInDollars);
    } else if(CheckForAValidCoin(inputCoin, Dime)){
        currentAmountInsertedInDollars += dimeValueInDollars;
		currentMessage = CreateNewMessageWithNewInstertedAmount(currentAmountInsertedInDollars);
    } else { 
        currentMessage = "COIN REJECTED";
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
	currentAmountInsertedInDollars = 0.f;
}

void VendingMachine::SelectProduct(ProductType productType){
    currentMessage = "THANK YOU!";
}

std::string VendingMachine::CreateNewMessageWithNewInstertedAmount(float amountCurrentlyInserted){
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << amountCurrentlyInserted;
	return "AMOUNT: " + ss.str();
	
}