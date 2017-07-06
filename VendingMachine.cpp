//Vending Machine Implementation
#include "VendingMachine.h"
#include <iostream>

VendingMachine::VendingMachine(){
    //Nothing to do in the constructor yet
}

Coin VendingMachine::InsertCoin(float coinWeightInGrams, float coinDiameterInMilliMeters, float coinTicknessInMilliMeters){
    if(coinWeightInGrams > 5.01f){
        if( coinTicknessInMilliMeters > (quarterThicknessInMilliMeters - vendingMachineThicknessToleranceInMilliMeters) &&
        coinTicknessInMilliMeters < (quarterThicknessInMilliMeters + vendingMachineThicknessToleranceInMilliMeters)){
			return QUARTER;
        } else {
            return INVALID_COIN;
        }
    } else {
        return NICKEL;
    }
}