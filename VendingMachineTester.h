//Vending Machine Tester Header
#include <cppunit/extensions/HelperMacros.h>

#include "VendingMachine.h"

class VendingMachineTester : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(VendingMachineTester);
    CPPUNIT_TEST(testInsertQuarter);
    CPPUNIT_TEST(testInsertNickel);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    void testInsertQuarter();
    void testInsertNickel();

private:

    VendingMachine mVendingMachine;
};