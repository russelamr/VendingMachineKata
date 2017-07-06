//Vending Machine Implementation
#include "VendingMachine.h"
#include <Math.h>

VendingMachine::VendingMachine(){
    //Nothing to do in the constructor yet
}

Coin VendingMachine::InsertCoin(float coinWeightInGrams, float coinDiameterInMilliMeters, float coinTicknessInMilliMeters){
    if(coinWeightInGrams > 5.01f){
        if( FloatValuesAreWithinEpsilon(coinTicknessInMilliMeters,quarterThicknessInMilliMeters,vendingMachineThicknessToleranceInMilliMeters) &&
		   FloatValuesAreWithinEpsilon(coinDiameterInMilliMeters, quarterDiameterInMilliMeters, vendingMachineDiameterToleranceInMilliMeters)){
			return QUARTER;
        } else {
            return INVALID_COIN;
        }
    } else {
        return NICKEL;
    }
}

bool VendingMachine::FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon){
	return fabs(value1 - value2) <= epsilon;
}