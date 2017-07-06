// Vending Machine Header
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <Math.h>
#include <string>
#include <sstream>
#include <iomanip>

#include "Coin.h"
#include "Product.h"

class VendingMachine
{
public:
    VendingMachine();
	void ResetStateOfVendingMachine();
    void InsertCoin(Coin inputCoin);
	void SelectProduct(ProductType productType);
	std::string GetCurrentMessage();
private:
    bool FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon);
    bool CheckForAValidCoin(Coin inputCoin, Coin validCoin);
	std::string CreateNewMessageWithNewInstertedAmount(float amountCurrentlyInserted);
    Coin Quarter;
    Coin Nickel;
    Coin Dime;
    Coin Penny;
	std::string currentMessage;
	float currentAmountInsertedInDollars;
    static float const vendingMachineWeightToleranceInGrams = 0.01f;
    static float const vendingMachineThicknessToleranceInMilliMeters = 0.01f;
    static float const vendingMachineDiameterToleranceInMilliMeters = 0.01f;  
    };

#endif //VENDINGMACHINE_H