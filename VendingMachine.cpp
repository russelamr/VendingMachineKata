//Vending Machine Implementation
#include "VendingMachine.h"

VendingMachine::VendingMachine(){
    //Nothing to do in the constructor yet
}

Coin VendingMachine::InsertCoin(float coinWeightInGrams){
    if(coinWeightInGrams > 5.01f){
        return QUARTER;
    } else {
        return NICKEL;
    }
}