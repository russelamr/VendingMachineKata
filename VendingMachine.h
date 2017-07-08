// Vending Machine Header
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <Math.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

#include "Coin.h"
#include "Product.h"
#include "VendingMachineStrings.h"

class VendingMachine
{
public:
    VendingMachine();
    void InsertCoin(Coin inputCoin);
	void SelectProduct(ProductType productType);
	void SetStockOfCandy(int stockOfCandy);
	void SetStockOfChips(int stockOfChips);
	void SetStockOfCola(int stockOfCola);
	void SetStockOfDimes(int numberOfDimes);
	void SetStockOfNickels(int numberOfNickels);
	void SetStockOfQuarters(int numberOfQuarters);
	void ReturnCoinsInCurrentTransactionIntoTheChangeReturnSlot();
	std::string GetCurrentMessage();
	std::vector<Coin> RemoveChangeFromTheChangeReturnSlot();
	static bool FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon);
private:
    bool CheckForAValidCoin(Coin inputCoin, Coin validCoin);
	std::string CreateNewMessageInDollarsWithAmountCents(std::string tagToPutBeforeAmount, int amountInCents);
	std::string AttemptToPurchaseItem(int amountInsertedInCents, int productCostInCents, int &currentStock);
	void MakeChange(int amountToBeTurnedIntoChangeInCents);
	void AddOneTypeOfCurrencyToReturnSlot(int numberOfCoinsToAdd, std::vector<Coin> &vectorOfTypeOfCoinsToReturn);
	void SortCoinsIntoTheirRespectiveChangeSlots(std::vector<Coin> coins);
    Coin Quarter;
    Coin Nickel;
    Coin Dime;
    Coin Penny;
	std::string currentMessage;
	std::vector<Coin> changeInReturnSlot;
	std::vector<Coin> changeInCurrentTransaction;
	int currentAmountInsertedInCents;
	int currentStockOfCandy;
	int currentStockOfChips;
	int currentStockOfCola;
	std::vector<Coin> currentStockOfQuarters;
	std::vector<Coin> currentStockOfDimes;
	std::vector<Coin> currentStockOfNickels;
	bool currentlyInExactChangeMode;
    static float const vendingMachineWeightToleranceInGrams = 0.01f;
    static float const vendingMachineThicknessToleranceInMilliMeters = 0.01f;
    static float const vendingMachineDiameterToleranceInMilliMeters = 0.01f;  
    };

#endif //VENDINGMACHINE_H