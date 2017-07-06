// Vending Machine Header
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include "Coin.h"

class VendingMachine
{
public:
    VendingMachine();
    Coin_Type InsertCoin(Coin inputCoin);
private:
    bool FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon);
    bool CheckForAValidCoin(Coin inputCoin, Coin validCoin);
    Coin Quarter;
    Coin Nickel;
    Coin Dime;
    Coin Penny;
    static float const vendingMachineWeightToleranceInGrams = 0.01f;
    static float const vendingMachineThicknessToleranceInMilliMeters = 0.01f;
    static float const vendingMachineDiameterToleranceInMilliMeters = 0.01f;  
    };

#endif //VENDINGMACHINE_H