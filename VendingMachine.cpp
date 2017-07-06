//Vending Machine Implementation
#include "VendingMachine.h"
#include <Math.h>

VendingMachine::VendingMachine(){
    //Nothing to do in the constructor yet
}

Coin VendingMachine::InsertCoin(float coinWeightInGrams, float coinDiameterInMilliMeters, float coinTicknessInMilliMeters){
    if(FloatValuesAreWithinEpsilon(coinWeightInGrams, quarterWeightInGrams, vendingMachineWeightToleranceInGrams)){
        if( FloatValuesAreWithinEpsilon(coinTicknessInMilliMeters,quarterThicknessInMilliMeters,vendingMachineThicknessToleranceInMilliMeters) &&
		   FloatValuesAreWithinEpsilon(coinDiameterInMilliMeters, quarterDiameterInMilliMeters, vendingMachineDiameterToleranceInMilliMeters)){
			return QUARTER;
        } else {
            return INVALID_COIN;
        }
    } else if(FloatValuesAreWithinEpsilon(coinWeightInGrams, nickelWeightInGrams, vendingMachineWeightToleranceInGrams)){
        return NICKEL;
    } else { 
		return INVALID_COIN;
	}
}

bool VendingMachine::FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon){
	return fabs(value1 - value2) <= epsilon;
}