// Vending Machine Header
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

enum Coin { 
    QUARTER, 
    DIME, 
    NICKEL,
    PENNY,
    INVALID};

class VendingMachine
{
public:
    VendingMachine();
    Coin InsertCoin(float coinWeightInGrams);
private:
    static float const vending_machine_weight_tolerance = 0.001f;
};

#endif