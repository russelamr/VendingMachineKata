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
	void SetStockOfCandy(unsigned int stockOfCandy);
	void SetStockOfChips(unsigned int stockOfChips);
	void SetStockOfCola(unsigned int stockOfCola);
	void SetStockOfDimes(unsigned int numberOfDimes);
	void SetStockOfNickels(unsigned int numberOfNickels);
	void SetStockOfQuarters(unsigned int numberOfQuarters);
	void ReturnCoinsInCurrentTransactionIntoTheChangeReturnSlot();
	std::string GetCurrentMessage();
	std::vector<Coin> RemoveChangeFromTheChangeReturnSlot();
	static bool FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon);
private:
    bool CheckForAValidCoin(Coin inputCoin, Coin validCoin);
	std::string CreateNewMessageInDollarsWithAmountCents(std::string tagToPutBeforeAmount, unsigned int amountInCents);
	std::string AttemptToPurchaseItem(unsigned int amountInsertedInCents, unsigned int productCostInCents, unsigned int &currentStock);
	void MakeChange(unsigned int amountToBeTurnedIntoChangeInCents);
	void AddOneTypeOfCurrencyToReturnSlot(unsigned int numberOfCoinsToAdd, std::vector<Coin> &vectorOfTypeOfCoinsToReturn);
	void SortCoinsIntoTheirRespectiveChangeSlots(std::vector<Coin> coins);
	void CheckForTheExactChangeCondition();
    Coin mPerfectQuarter;
    Coin mPerfectNickel;
    Coin mPerfectDime;
    Coin mPerfectPenny;
	std::string mCurrentMessage;
	std::vector<Coin> mChangeInReturnSlot;
	std::vector<Coin> mChangeInCurrentTransaction;
	std::vector<Coin> mCurrentStockOfQuarters;
	std::vector<Coin> mCurrentStockOfDimes;
	std::vector<Coin> mCurrentStockOfNickels;
	unsigned int mCurrentAmountInsertedInCents;
	unsigned int mCurrentStockOfCandy;
	unsigned int mCurrentStockOfChips;
	unsigned int mCurrentStockOfCola;
	bool mCurrentlyInExactChangeMode;
    static float const mVendingMachineWeightToleranceInGrams = 0.01f;
    static float const mVendingMachineThicknessToleranceInMilliMeters = 0.01f;
    static float const mVendingMachineDiameterToleranceInMilliMeters = 0.01f;  
    };

#endif //VENDINGMACHINE_H