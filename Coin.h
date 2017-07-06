#ifndef COIN_H
#define COIN_H

enum Coin_Type { 
    QUARTER, 
    DIME, 
    NICKEL,
    PENNY,
    INVALID_COIN};
	
struct Coin{
	float weightInGrams;
	float diameterInMilliMeters;
	float thicknessInMilliMeters;
};


#endif //COIN_H