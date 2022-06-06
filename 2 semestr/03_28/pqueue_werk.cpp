#include <cppunit/extensions/HelperMacros.h>

#include "pqueue.hpp"
#include <string>
#include <iostream>

class Werk : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Werk);
    CPPUNIT_TEST(test1);
    CPPUNIT_TEST(test2);
    CPPUNIT_TEST(test3);
    CPPUNIT_TEST(test4);
    CPPUNIT_TEST(test5);
    CPPUNIT_TEST_SUITE_END();

public:
    void test1()
    {
        PQueue<std::string> kolejka;
        kolejka.enqueue("Azor", 13);
        kolejka.enqueue("Burek", 5);
        kolejka.enqueue("Czarek", 4);
        kolejka.enqueue("Dobby", 15);
        kolejka.enqueue("Efel", 4);
        kolejka.enqueue("Filo", 13);
        kolejka.enqueue("Gbur", 7);
        std::string tekst;
        tekst = kolejka.front();
        CPPUNIT_ASSERT(tekst == "Dobby");
        tekst = kolejka.dequeue();
        CPPUNIT_ASSERT(tekst == "Dobby");
        tekst = kolejka.dequeue();
        CPPUNIT_ASSERT(tekst == "Azor" || tekst == "Filo");
        tekst = kolejka.dequeue();
        CPPUNIT_ASSERT(tekst == "Filo" || tekst == "Azor");
        tekst = kolejka.dequeue();
        CPPUNIT_ASSERT(tekst == "Gbur");
        tekst = kolejka.dequeue();
        CPPUNIT_ASSERT(tekst == "Burek");
        tekst = kolejka.dequeue();
        CPPUNIT_ASSERT(tekst == "Czarek" || tekst == "Efel");
        tekst = kolejka.dequeue();
        CPPUNIT_ASSERT(tekst == "Efel" || tekst == "Czarek");
    }

    void test2()
    {
        PQueue<std::string> kolejka;
        kolejka.enqueue("Jeden", 58);
        kolejka.enqueue("Dwa", 25);
        kolejka.enqueue("Trzy", 14);
        kolejka.enqueue("Cztery", 1);
        kolejka.enqueue("Piec", 0);
        kolejka.enqueue("Szesc", -1);
        kolejka.enqueue("Siedem", -13);
        CPPUNIT_ASSERT(kolejka.dequeue() == "Jeden");
        CPPUNIT_ASSERT(kolejka.dequeue() == "Dwa");
        CPPUNIT_ASSERT(kolejka.dequeue() == "Trzy");
        CPPUNIT_ASSERT(kolejka.dequeue() == "Cztery");
        CPPUNIT_ASSERT(kolejka.dequeue() == "Piec");
        CPPUNIT_ASSERT(kolejka.dequeue() == "Szesc");
        CPPUNIT_ASSERT(kolejka.dequeue() == "Siedem");
    }

    void test3()
    {
        PQueue<std::string> kolejka;
        kolejka.enqueue("1", 1);
        kolejka.enqueue("2", 2);
        kolejka.enqueue("3", 3);
        kolejka.enqueue("4", 4);
        kolejka.enqueue("5", 5);
        kolejka.enqueue("6", 6);
        kolejka.enqueue("7", 7);
        kolejka.enqueue("8", 8);
        kolejka.enqueue("9", 9);
        kolejka.enqueue("10", 10);
        CPPUNIT_ASSERT(kolejka.dequeue() == "10");
        CPPUNIT_ASSERT(kolejka.dequeue() == "9");
        CPPUNIT_ASSERT(kolejka.dequeue() == "8");
        CPPUNIT_ASSERT(kolejka.dequeue() == "7");
        CPPUNIT_ASSERT(kolejka.dequeue() == "6");
        CPPUNIT_ASSERT(kolejka.dequeue() == "5");
        CPPUNIT_ASSERT(kolejka.dequeue() == "4");
        CPPUNIT_ASSERT(kolejka.dequeue() == "3");
        CPPUNIT_ASSERT(kolejka.dequeue() == "2");
        CPPUNIT_ASSERT(kolejka.dequeue() == "1");
    }

    void test4()
    {
        PQueue<int> kolejka;
        bool error = false;

        try
        {
            kolejka.front();
        }
        catch (std::logic_error const &ex)
        {
            error = true;
        }
        if (!error)
        {
            CPPUNIT_FAIL("Expected std::logic_error");
        }
    }

    void test5()
    {
        PQueue<int> kolejka;
        bool error = false;

        try
        {
            kolejka.dequeue();
        }
        catch (std::logic_error const &ex)
        {
            error = true;
        }
        if (!error)
        {
            CPPUNIT_FAIL("Expected std::logic_error");
        }
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Werk);
