//Vending Machine Implementation
#include "VendingMachine.h"
#include <Math.h>
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
}

Coin_Type VendingMachine::InsertCoin(float coinWeightInGrams, float coinDiameterInMilliMeters, float coinTicknessInMilliMeters){
    if(CheckForAValidCoin(coinWeightInGrams, coinDiameterInMilliMeters,coinTicknessInMilliMeters, Quarter) ){
		return QUARTER;
    } else if(CheckForAValidCoin(coinWeightInGrams, coinDiameterInMilliMeters,coinTicknessInMilliMeters, Nickel)){
        return NICKEL;
    } else if(CheckForAValidCoin(coinWeightInGrams, coinDiameterInMilliMeters,coinTicknessInMilliMeters, Dime)){
        return DIME;
    } else { 
		return INVALID_COIN;
	}
}

bool VendingMachine::FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon){
	return fabs(value1 - value2) <= epsilon;
}

bool VendingMachine::CheckForAValidCoin(float inputCoinWeightInGrams, float inputCoinDiameterInMilliMeters, float inputCoinTicknessInMilliMeters,
	Coin validCoin){
	if(!FloatValuesAreWithinEpsilon(inputCoinWeightInGrams, validCoin.weightInGrams, vendingMachineWeightToleranceInGrams)) 
		return false;
    if(!FloatValuesAreWithinEpsilon(inputCoinTicknessInMilliMeters, validCoin.thicknessInMilliMeters, vendingMachineThicknessToleranceInMilliMeters)) 
		return false;
	if(!FloatValuesAreWithinEpsilon(inputCoinDiameterInMilliMeters, validCoin.diameterInMilliMeters, vendingMachineDiameterToleranceInMilliMeters)) 
		return false;
	return true;
}