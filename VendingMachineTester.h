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
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    void testInsertQuarter();
    void testInsertNickel();
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
private:

    VendingMachine mVendingMachine;
};

#endif //VENDINGMACHINETESTER_H