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
}

CoinType VendingMachine::InsertCoin(Coin inputCoin){
    if(CheckForAValidCoin(inputCoin, Quarter) ){
        return QUARTER;
    } else if(CheckForAValidCoin(inputCoin, Nickel)){
        return NICKEL;
    } else if(CheckForAValidCoin(inputCoin, Dime)){
        return DIME;
    } else if(CheckForAValidCoin(inputCoin, Penny)){
        return PENNY;
    }else { 
        return INVALID_COIN;
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

void VendingMachine::SelectProduct(ProductType productType){
    currentMessage = "THANK YOU!";
}