#include <cppunit/extensions/HelperMacros.h>

#include "set.hpp"
#include <string>
#include <iostream>

class Palacz01 : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Palacz01);
    CPPUNIT_TEST(testPierwszy);
    CPPUNIT_TEST(testDrugi);
    CPPUNIT_TEST_SUITE_END();

public:
    void testPierwszy()
    {
        Set<int> s;
        int i;
        for (i = 0; i < 10; ++i)
        {
            CPPUNIT_ASSERT(!s.contains(i));
        }
        for (i = 0; i < 10; i += 2)
        {
            s.insert(i);
        }
        for (i = 0; i < 10; i += 2)
        {
            CPPUNIT_ASSERT(s.contains(i));
            CPPUNIT_ASSERT(!s.contains(i + 1));
        }
        for (i = 9; i >= 0; --i)
        {
            s.remove(i);
        }
        for (i = 9; i >= 0; i -= 2)
        {
            s.insert(i);
        }
        for (i = 0; i < 10; i += 2)
        {
            CPPUNIT_ASSERT(!s.contains(i));
            CPPUNIT_ASSERT(s.contains(i + 1));
        }
    }

    void testDrugi()
    {
        Set<std::string> s1;
        s1.insert("foo");
        s1.insert("bar");

        Set<std::string> s2;
        s2.insert("bar");
        s2.insert("baz");

        s1.intersection(s2);

        CPPUNIT_ASSERT(s1.contains("bar"));
        CPPUNIT_ASSERT(!s1.contains("foo"));
        CPPUNIT_ASSERT(!s1.contains("baz"));
    }
};

class Palacz02 : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Palacz02);
    CPPUNIT_TEST(testTrzeci);
    CPPUNIT_TEST_SUITE_END();

public:
    void testTrzeci()
    {
        CPPUNIT_ASSERT(2 + 2 == 4);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Palacz01);
CPPUNIT_TEST_SUITE_REGISTRATION(Palacz02);
