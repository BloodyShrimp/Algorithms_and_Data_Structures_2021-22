#include <cppunit/extensions/HelperMacros.h>

#include "set.hpp"
#include <string>
#include <iostream>

class Werk : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Werk);
    CPPUNIT_TEST(testInsertContains);
    CPPUNIT_TEST(testRemoveContains);
    CPPUNIT_TEST(testUnion);
    CPPUNIT_TEST(testIntersection);
    CPPUNIT_TEST(testDifference);
    CPPUNIT_TEST_SUITE_END();

public:
    void testInsertContains()
    {
        Set<std::string> set;
        set.insert("Dwa");
        set.insert("Trzy");
        set.insert("Piec");
        set.insert("Siedem");
        set.insert("Jedenascie");
        set.insert("Trzynascie");
        CPPUNIT_ASSERT(!set.contains("Jeden"));
        CPPUNIT_ASSERT(set.contains("Dwa"));
        CPPUNIT_ASSERT(set.contains("Trzy"));
        CPPUNIT_ASSERT(!set.contains("Cztery"));
        CPPUNIT_ASSERT(set.contains("Piec"));
        CPPUNIT_ASSERT(!set.contains("Szesc"));
        CPPUNIT_ASSERT(set.contains("Siedem"));
        CPPUNIT_ASSERT(!set.contains("Osiem"));
        CPPUNIT_ASSERT(!set.contains("Dziewiec"));
        CPPUNIT_ASSERT(!set.contains("Dziesiec"));
        CPPUNIT_ASSERT(set.contains("Jedenascie"));
        CPPUNIT_ASSERT(!set.contains("Dwanascie"));
        CPPUNIT_ASSERT(set.contains("Trzynascie"));
    }

    void testRemoveContains()
    {
        Set<std::string> set;
        set.insert("Dwa");
        set.insert("Trzy");
        set.insert("Piec");
        set.insert("Siedem");
        set.insert("Jedenascie");
        set.insert("Trzynascie");
        CPPUNIT_ASSERT(set.contains("Siedem"));
        set.remove("Siedem");
        CPPUNIT_ASSERT(!set.contains("Siedem"));
        CPPUNIT_ASSERT(set.contains("Trzynascie"));
        set.remove("Trzynascie");
        CPPUNIT_ASSERT(!set.contains("Trzynascie"));
    }

    void testUnion()
    {
        Set<int> set1;
        Set<int> set2;
        int i;
        
        for (i = 0; i < 10; i++)
        {
            set1.insert(i);
        }
        for (i = 5; i < 15; i++)
        {
            set2.insert(i);
        }

        set1.Union(set2);

        for (i = 0; i < 15; i++)
        {
            CPPUNIT_ASSERT(set1.contains(i));
        }
        CPPUNIT_ASSERT(!set1.contains(15));
    }

    void testIntersection()
    {
        Set<int> set1;
        Set<int> set2;
        int i;
        
        for (i = 0; i < 10; i++)
        {
            set1.insert(i);
        }
        for (i = 5; i < 15; i++)
        {
            set2.insert(i);
        }

        set1.intersection(set2);

        for (i = 0; i < 15; i++)
        {
            if (i < 5 || i > 9)
            {
                CPPUNIT_ASSERT(!set1.contains(i));
            }
            else
            {
                CPPUNIT_ASSERT(set1.contains(i));
            }
        }

        Set<int> set3;
        Set<int> set4;
        for (i = 0; i < 10; i++)
        {
            set3.insert(i);
        }
        for (i = 10; i < 20; i++)
        {
            set4.insert(i);
        }

        set3.intersection(set4);
        for (i = 0; i < 20; i++)
        {
            CPPUNIT_ASSERT(!set3.contains(i));
        }
    }

    void testDifference()
    {
        Set<std::string> set1;
        Set<std::string> set2;

        set1.insert("to be");
        set1.insert("or not to be");
        set1.insert("that is the question");
        set2.insert("what does it mean");
        set2.insert("to be");
        set2.insert("truly free");
        set2.insert("that is the question");

        set2.difference(set1);
        CPPUNIT_ASSERT(set2.contains("what does it mean"));
        CPPUNIT_ASSERT(!set2.contains("to be"));
        CPPUNIT_ASSERT(set2.contains("truly free"));
        CPPUNIT_ASSERT(!set2.contains("that is the question"));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Werk);
