// Vending Machine Header
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

enum Coin { 
    QUARTER, 
    DIME, 
    NICKEL,
    PENNY,
    INVALID_COIN};

class VendingMachine
{
public:
    VendingMachine();
    Coin InsertCoin(float coinWeightInGrams, float coinDiameterInMilliMeters, float coinTicknessInMilliMeters);
private:
	bool FloatValuesAreWithinEpsilon(float value1,float value2, float epsilon);
	bool CheckIfQuarter(float coinWeightInGrams, float coinDiameterInMilliMeters, float coinTicknessInMilliMeters);
	bool CheckIfNickel(float coinWeightInGrams, float coinDiameterInMilliMeters, float coinTicknessInMilliMeters);
    static float const quarterWeightInGrams = 5.670f;
    static float const nickelWeightInGrams = 5.000f;
	static float const quarterThicknessInMilliMeters = 1.75f;
	static float const nickelThicknessInMilliMeters = 1.95f;
	static float const quarterDiameterInMilliMeters = 24.26f;
	static float const nickelDiameterInMilliMeters = 21.21f;
	static float const vendingMachineWeightToleranceInGrams = 0.01f;
    static float const vendingMachineThicknessToleranceInMilliMeters = 0.01f;
	static float const vendingMachineDiameterToleranceInMilliMeters = 0.01f;
    
};

#endif