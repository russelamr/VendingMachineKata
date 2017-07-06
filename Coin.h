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
static int const quarterValueInCents = 25;
static int const nickelValueInCents = 5;
static int const dimeValueInCents = 10;
static int const pennyValueInCents = 1;
static float const centsToDollars = .01f;
static float const dollarsToCents = 100.f;

#endif //COIN_H