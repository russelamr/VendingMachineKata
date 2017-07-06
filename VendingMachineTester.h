//Vending Machine Tester Header
#ifndef VENDINGMACHINETESTER_H
#define VENDINGMACHINETESTER_H

#include <cppunit/extensions/HelperMacros.h>

#include "VendingMachine.h"

class VendingMachineTester : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(VendingMachineTester);
    CPPUNIT_TEST(testInsertQuarter);
    CPPUNIT_TEST(testInsertNickel);
	CPPUNIT_TEST(testInsertDime);
	CPPUNIT_TEST(testInsertPenny);
    CPPUNIT_TEST(testInsertCoinAQuarterWithNotEnoughThickness);
    CPPUNIT_TEST(testInsertCoinAQuarterWithTooMuchThickness);
	CPPUNIT_TEST(testInsertCoinAQuarterWithNotEnoughDiameter);
    CPPUNIT_TEST(testInsertCoinAQuarterWithTooMuchDiameter);
	CPPUNIT_TEST(testInsertCoinAQuarterWithNotEnoughWeight);
    CPPUNIT_TEST(testInsertCoinAQuarterWithTooMuchWeight);
	CPPUNIT_TEST(testInsertCoinANickelWithNotEnoughThickness);
    CPPUNIT_TEST(testInsertCoinANickelWithTooMuchThickness);
	CPPUNIT_TEST(testInsertCoinANickelWithNotEnoughDiameter);
    CPPUNIT_TEST(testInsertCoinANickelWithTooMuchDiameter);
	CPPUNIT_TEST(testInsertCoinANickelWithNotEnoughWeight);
    CPPUNIT_TEST(testInsertCoinANickelWithTooMuchWeight);
	CPPUNIT_TEST(testInsertCoinADimeWithNotEnoughThickness);
    CPPUNIT_TEST(testInsertCoinADimeWithTooMuchThickness);
	CPPUNIT_TEST(testInsertCoinADimeWithNotEnoughDiameter);
    CPPUNIT_TEST(testInsertCoinADimeWithTooMuchDiameter);
	CPPUNIT_TEST(testInsertCoinADimeWithNotEnoughWeight);
    CPPUNIT_TEST(testInsertCoinADimeWithTooMuchWeight);
	//CPPUNIT_TEST(testSelectColaWithValidFunds);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    void testInsertQuarter();
    void testInsertNickel();
	void testInsertDime();
	void testInsertPenny();
    void testInsertCoinAQuarterWithNotEnoughThickness();
    void testInsertCoinAQuarterWithTooMuchThickness();
	void testInsertCoinAQuarterWithNotEnoughDiameter();
    void testInsertCoinAQuarterWithTooMuchDiameter();
	void testInsertCoinAQuarterWithNotEnoughWeight();
    void testInsertCoinAQuarterWithTooMuchWeight();
	void testInsertCoinANickelWithNotEnoughThickness();
    void testInsertCoinANickelWithTooMuchThickness();
	void testInsertCoinANickelWithNotEnoughDiameter();
    void testInsertCoinANickelWithTooMuchDiameter();
	void testInsertCoinANickelWithNotEnoughWeight();
    void testInsertCoinANickelWithTooMuchWeight();
	void testInsertCoinADimeWithNotEnoughThickness();
    void testInsertCoinADimeWithTooMuchThickness();
	void testInsertCoinADimeWithNotEnoughDiameter();
    void testInsertCoinADimeWithTooMuchDiameter();
	void testInsertCoinADimeWithNotEnoughWeight();
    void testInsertCoinADimeWithTooMuchWeight();
	//void testSelectColaWithValidFunds();
private:

    VendingMachine mVendingMachine;
	Coin Quarter;
	Coin Nickel;
	Coin Dime;
	Coin Penny;
};

#endif //VENDINGMACHINETESTER_H