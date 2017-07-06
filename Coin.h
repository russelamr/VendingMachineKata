#ifndef COIN_H
#define COIN_H
    
struct Coin{
    float weightInGrams;
    float diameterInMilliMeters;
    float thicknessInMilliMeters;
};

static float const quarterWeightInGrams = 5.670f;
static float const nickelWeightInGrams = 5.000f;
static float const dimeWeightInGrams = 2.268f;
static float const pennyWeightInGrams = 2.50f;
static float const quarterThicknessInMilliMeters = 1.75f;
static float const nickelThicknessInMilliMeters = 1.95f;
static float const dimeThicknessInMilliMeters = 1.35f;
static float const pennyThicknessInMilliMeters = 1.52f;
static float const quarterDiameterInMilliMeters = 24.26f;
static float const nickelDiameterInMilliMeters = 21.21f;
static float const dimeDiameterInMilliMeters = 17.91f;
static float const pennyDiameterInMilliMeters = 19.0f;
static float const quarterValueInDollars = 0.25f;
static float const nickelValueInDollars = 0.05f;
static float const dimeValueInDollars = 0.10f;
static float const pennyValueInDollars = 0.01f;


#endif //COIN_H