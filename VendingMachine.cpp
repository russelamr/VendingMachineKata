//Vending Machine Implementation
#include "VendingMachine.h"
#include <Math.h>

VendingMachine::VendingMachine(){
    //Nothing to do in the constructor yet
}

Coin VendingMachine::InsertCoin(float coinWeightInGrams, float coinDiameterInMilliMeters, float coinTicknessInMilliMeters){
    if(CheckIfQuarter(coinWeightInGrams, coinDiameterInMilliMeters,coinTicknessInMilliMeters) ){
		return QUARTER;
    } else if(CheckIfNickel(coinWeightInGrams, coinDiameterInMilliMeters,coinTicknessInMilliMeters)){
        return NICKEL;
    } else { 
		return INVALID_COIN;
	}
}

bool VendingMachine::FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon){
	return fabs(value1 - value2) <= epsilon;
}

bool VendingMachine::CheckIfQuarter(float coinWeightInGrams, float coinDiameterInMilliMeters, float coinTicknessInMilliMeters){
	if(!FloatValuesAreWithinEpsilon(coinWeightInGrams, quarterWeightInGrams, vendingMachineWeightToleranceInGrams)) 
		return false;
    if(!FloatValuesAreWithinEpsilon(coinTicknessInMilliMeters,quarterThicknessInMilliMeters,vendingMachineThicknessToleranceInMilliMeters)) 
		return false;
	if(!FloatValuesAreWithinEpsilon(coinDiameterInMilliMeters, quarterDiameterInMilliMeters, vendingMachineDiameterToleranceInMilliMeters)) 
		return false;
	return true;
}

bool VendingMachine::CheckIfNickel(float coinWeightInGrams, float coinDiameterInMilliMeters, float coinTicknessInMilliMeters){
	if(!FloatValuesAreWithinEpsilon(coinWeightInGrams, nickelWeightInGrams, vendingMachineWeightToleranceInGrams)) 
		return false;
    if(!FloatValuesAreWithinEpsilon(coinTicknessInMilliMeters,nickelThicknessInMilliMeters,vendingMachineThicknessToleranceInMilliMeters)) 
		return false;
	if(!FloatValuesAreWithinEpsilon(coinDiameterInMilliMeters, nickelDiameterInMilliMeters, vendingMachineDiameterToleranceInMilliMeters)) 
		return false;
	return true;
}