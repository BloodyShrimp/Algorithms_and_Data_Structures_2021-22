#include <cppunit/extensions/HelperMacros.h>
#include <string>

#include "set.hpp"

class Taras : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Taras);
    CPPUNIT_TEST(testBasics);
    CPPUNIT_TEST(testUnion);
    CPPUNIT_TEST(testIntersection);
    CPPUNIT_TEST(testDifference);
    CPPUNIT_TEST_SUITE_END();

public:
    void testBasics()
    {
        Set<int> set;

        for (int i = 0; i <= 10; i++)
        {
            set.insert(i);
        }
        for (int i = 0; i <= 10; i++)
        {
            CPPUNIT_ASSERT(set.contains(i));
        }
        for (int i = 1; i <= 10; i += 2)
        {
            set.remove(i);
        }
        for (int i = 0; i <= 10; i += 2)
        {
            CPPUNIT_ASSERT(set.contains(i));
            CPPUNIT_ASSERT(!(set.contains(i + 1)));
        }
    }

    void testUnion()
    {
        Set<int> set_1, set_2;

        for (int i = 2; i <= 10; i += 2)
        {
            set_1.insert(i - 1);
            set_2.insert(i);
        }

        set_1.Union(set_2);

        for (int i = 2; i <= 10; i += 2)
        {
            CPPUNIT_ASSERT(set_1.contains(i));
            CPPUNIT_ASSERT(set_1.contains(i - 1));
            CPPUNIT_ASSERT(set_2.contains(i));
            CPPUNIT_ASSERT(!(set_2.contains(i - 1)));
        }
    }

    void testIntersection()
    {
        Set<int> set_1, set_2;

        for (int i = 0; i <= 7; i++)
        {
            set_1.insert(i);
        }
        for (int i = 5; i <= 10; i++)
        {
            set_2.insert(i);
        }

        set_1.intersection(set_2);

        for (int i = 0; i <= 4; i++)
        {
            CPPUNIT_ASSERT(!(set_1.contains(i)));
        }
        for (int i = 5; i <= 7; i++)
        {
            CPPUNIT_ASSERT(set_1.contains(i));
        }
        for (int i = 8; i <= 10; i++)
        {
            CPPUNIT_ASSERT(!(set_1.contains(i)));
        }
    }

    void testDifference()
    {
        Set<int> set_1, set_2;

        for (int i = 0; i <= 7; i++)
        {
            set_1.insert(i);
        }
        for (int i = 5; i <= 10; i++)
        {
            set_2.insert(i);
        }

        set_1.difference(set_2);

        for (int i = 0; i <= 4; i++)
        {
            CPPUNIT_ASSERT(set_1.contains(i));
        }
        for (int i = 5; i <= 10; i++)
        {
            CPPUNIT_ASSERT(!(set_1.contains(i)));
        }
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Taras);
