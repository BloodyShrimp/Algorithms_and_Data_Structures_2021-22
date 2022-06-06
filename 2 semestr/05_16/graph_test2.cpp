#include <cppunit/extensions/HelperMacros.h>

#include "graph.hpp"
#include <string>
using namespace std;

class Palacz01 : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Palacz01);
    CPPUNIT_TEST(testPierwszy);
    CPPUNIT_TEST(testDrugi);
    CPPUNIT_TEST_SUITE_END();

public:

    void testPierwszy(){
        Graph g(5);
        
        auto i = g.vertices_begin();
        auto e = g.vertices_end();
        for(int a = 0; a<5; a++){
            CPPUNIT_ASSERT(!g.are_connected(e,i));
            cout << 1 << endl;
            ++i;
        }
        i = g.vertices_begin();
        while (i != e) {
            (*i).label="a";
            ++i;
        }
        (*e).label="a";
        string temp;
        i = g.vertices_begin();
        e = g.vertices_end();
        while (i != e) {
            temp+=(*i).label;
            ++i;
        }
        temp+=(*e).label;
        CPPUNIT_ASSERT(temp.length()==5);
        CPPUNIT_ASSERT(temp[0]=='a');
        CPPUNIT_ASSERT(temp[3]=='a');
        CPPUNIT_ASSERT(temp[4]=='a');
        i = g.vertices_begin();
        e = i;

        for(int a = 0; a<5; a++){//5 krawedzi wychodzi z pierwszego wierzcholka kazda do jednego wierzcholka
            g.connect(e,i);
            ++i;
        }
        i=g.vertices_begin();
        for(int a = 0; a<5; a++){
            CPPUNIT_ASSERT(g.are_connected(e,i));
            ++i;
        }
        g.disconnect(e,e);
        CPPUNIT_ASSERT(!g.are_connected(e,e));
        g.connect(e,e);

        auto p = g.edges_begin();
        auto q = g.edges_end();
        int it =0;
        while (p != q) {
            (*p).weight=it;
            it++;
            ++p;
        }
        it=0;
        p = g.edges_begin();
        while (p != q) {//ustawia wagi czterech krawedzi wychodzacych z pierwszego wierzcholka 0 1 2 3 
            CPPUNIT_ASSERT((*p).weight==it);
            it++;
            ++p;
        }
        it=0;

        i = g.vertices_begin();
        auto r = i.outedges_begin();
        auto s = i.outedges_end();
        while (r != s) {//sprawdza wagi czterech krawedzi wychodzacych z pierwszego wierzcholka 0 1 2 3 
            CPPUNIT_ASSERT((*r).weight==it);
            it++;
            ++r;
        }
        


    }

    void testDrugi(){
        Graph g(5);

        auto i =  g.vertices_begin();
        auto e =  g.vertices_end();

        for(int a = 0; a<5; a++){//5 krawedzi przychodzi do pierwszego wierzcholka kazda do jednego wierzcholka
            g.connect(i,e);
            ++i;
        }
        auto p = g.edges_begin();  
        auto q = g.edges_end();  
        int it=0;
        while (p != q) {//ustawia wagi czterech krawedzi przychodzacych do pierwszego wierzcholka 0 1 2 3 
            (*p).weight=it;
            it++;
            ++p;
        }
        it=0;

        i = g.vertices_begin();
        auto t = i.inedges_begin();
        auto u = i.inedges_end();
        while (t != u) {//sprawdza wagi czterech krawedzi przychodzacych do pierwszego wierzcholka 0 1 2 3 
            CPPUNIT_ASSERT((*t).weight==it);
            it++;
            ++t;
        }
        CPPUNIT_ASSERT(g.vertex_count()==5);
        CPPUNIT_ASSERT(g.edge_count()==5);
        g.connect(g.vertices_begin(),g.vertices_begin());
        p = g.edges_begin();
        CPPUNIT_ASSERT(p.source()==g.vertices_begin());
        CPPUNIT_ASSERT(p.destination()==g.vertices_begin());


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
        CPPUNIT_ASSERT( 2 + 2 == 4 );
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Palacz01);
CPPUNIT_TEST_SUITE_REGISTRATION(Palacz02);
