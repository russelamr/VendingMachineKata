// Vending Machine Header
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <Math.h>
#include <string>

#include "Coin.h"
#include "Product.h"

class VendingMachine
{
public:
    VendingMachine();
    CoinType InsertCoin(Coin inputCoin);
	void SelectProduct(ProductType productType);
	std::string GetCurrentMessage();
private:
    bool FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon);
    bool CheckForAValidCoin(Coin inputCoin, Coin validCoin);
    Coin Quarter;
    Coin Nickel;
    Coin Dime;
    Coin Penny;
	std::string currentMessage;
    static float const vendingMachineWeightToleranceInGrams = 0.01f;
    static float const vendingMachineThicknessToleranceInMilliMeters = 0.01f;
    static float const vendingMachineDiameterToleranceInMilliMeters = 0.01f;  
    };

#endif //VENDINGMACHINE_H