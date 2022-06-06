#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>

#include "graph.hpp"
#include <vector>
#include <algorithm>
#include <random>

#define VERTEXMAX 6

void shiftRight(Graph::vertex_iter &it, int pos){
    for (int i = 0; i < pos; i++) ++it;
}

std::vector<Graph::vertex_iter> getIters(Graph g, int size){
    std::vector<Graph::vertex_iter> v{};
    for (int i = 0; i < size; i++){
        auto it = g.vertices_begin();
        shiftRight(it, i);
        v.push_back(it);
    }
    return v;
}

/*
 * Graf 1:
 *
 *  1 → 2
 *  ↓ ↖ ↓
 *  4 ← 3
 *  ↓
 *  5 ← 6
 */
const static std::vector<std::pair<int, int>> graph1 = {
        {0,1},
        {1,2},
        {0,3},
        {2,3},
        {2, 0},
        {3,4},
        {5,4}
};

/*
 * Graf 2:
 *
 * 1 → 2 → 3
 * ↓ ↖
 * 4 ← 6
 * ↓
 * 5
 */
const static std::vector<std::pair<int, int>> graph2 = {
        {0,1},
        {1,2},
        {0,3},
        {3,1},
        {3, 4},
        {5,3}
};

/*
 * Graf 3
 *
 *     3
 *   ↙   ↖
 * 4 ← 6 → 2
 * ↓ ↗   ↗
 * 5 → 1
 */
const static std::vector<std::pair<int, int>> graph3 = {
        {0,1},
        {1,2},
        {2,3},
        {3,4},
        {4, 0},
        {4,5},
        {5,3},
        {5,1}
};

Graph* graphFaker(const std::vector<std::pair<int, int>>& edgesCoords){
    Graph *g = new Graph(VERTEXMAX);
    std::vector<Graph::vertex_iter> v{};
    for (int i = 0; i < 6; i++){
        auto it = g->vertices_begin();
        shiftRight(it, i);
        it->label = std::to_string(i);
        v.push_back(it);
    }
    for(auto pair: edgesCoords) {
        auto it = g->connect(v[pair.first], v[pair.second]);
        it->weight = 1.0f;
    }
    return g;
}

class BaseGraphTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(BaseGraphTests);
    CPPUNIT_TEST(vertexTest);
    CPPUNIT_TEST(edgeTest);
    CPPUNIT_TEST(connectionTests);
    CPPUNIT_TEST_SUITE_END();


public:

    void vertexTest(){

        auto randChar = []() -> char
        {
            const std::string charset = "0123456789"
                                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                        "abcdefghijklmnopqrstuvwxyz";
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, charset.size() - 1);
            return charset[dist(gen)];
        };

        Graph graph = Graph(10);
        std::vector<std::string> labels{};
        auto it = graph.vertices_begin();
        int i = 0;
        while (it != graph.vertices_end()){
            std::string str(10, 0);
            std::generate_n(str.begin(), 10, randChar);
            labels.push_back(str);
            it->label = str;
            i++;
            ++it;
        }
        CPPUNIT_ASSERT(i == 10);
        CPPUNIT_ASSERT_EQUAL(graph.vertex_count(),10);

        //check random labels
        std::vector<int> vertexesToCheck{};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 9);
        for (int j = 0; j < 5; j++) {
            vertexesToCheck.push_back(dist(gen));
        }
        for(auto index: vertexesToCheck){
            auto iter = graph.vertices_begin();
            shiftRight(iter, index);
            CPPUNIT_ASSERT(labels[index] == iter->label);
        }
    }

    void edgeTest(){
        std::vector<Graph*> graphs = {
                graphFaker(graph1),
                graphFaker(graph2),
                graphFaker(graph3)
        };

        std::vector<int> edgeExpectedCount = {
                static_cast<int>(graph1.size()),
                static_cast<int>(graph2.size()),
                static_cast<int>(graph3.size())
        };

        for (int i = 0; i < 3; i++){
            auto g = graphs[i];
            auto graph = *g;
            auto edgesCount = edgeExpectedCount[i];

            CPPUNIT_ASSERT_EQUAL(graph.edge_count(), edgesCount);
            int j = 0;

            auto it = graph.edges_begin();
            while(it != graph.edges_end()){
                CPPUNIT_ASSERT_EQUAL(it->weight, 1.0);
                j++;
                ++it;
            }

            CPPUNIT_ASSERT_EQUAL(j, edgesCount);
        }
    }

    void connectionTests(){
        Graph* g = graphFaker(graph1);

        auto it1 = g->vertices_begin(), it2 = g->vertices_begin();
        shiftRight(it2,4);

        CPPUNIT_ASSERT_EQUAL(g->are_connected(it1,it2),false);
        CPPUNIT_ASSERT_EQUAL(g->vertex_count(),6);

        auto it = g->edges_begin();
        while(it != g->edges_end()){
            auto itSrc = it.source(), itDsc = it.destination();
            CPPUNIT_ASSERT_EQUAL(g->are_connected(itSrc, itDsc),true);
            g->disconnect(itSrc,itDsc);
            CPPUNIT_ASSERT_EQUAL(g->are_connected(itSrc, itDsc),false);
            ++it;
        }


        delete g;
    }
};

class SpecialItersTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(SpecialItersTests);
    CPPUNIT_TEST(outedgeTraversalTest1);
    CPPUNIT_TEST(outedgeTraversalTest2);
    CPPUNIT_TEST(outedgeTraversalTest3);
    CPPUNIT_TEST(inedgeTraversalTest1);
    CPPUNIT_TEST(inedgeTraversalTest2);
    CPPUNIT_TEST(inedgeTraversalTest3);
    CPPUNIT_TEST_SUITE_END();

    Graph *g1, *g2, *g3;

public:
    void setUp(){
        g1 = graphFaker(graph1);
        g2 = graphFaker(graph2);
        g3 = graphFaker(graph3);
    }

    void tearDown(){
        delete g1;
        delete g2;
        delete g3;
    }


    void outedgeTraversalTest1(){
        auto g = g1;
        auto vertex1 = g->vertices_begin(),
             vertex2 = g->vertices_begin();

        shiftRight(vertex2, 4);
        traverseOut(vertex1,{true, true, false, true, false, false});
        traverseOut(vertex2,{false, false, false, false, false, false});
    }
    void outedgeTraversalTest2(){
        auto g = g2;
        auto vertex1 = g->vertices_begin(),
                vertex2 = g->vertices_begin();

        shiftRight(vertex2, 5);

        traverseOut(vertex1,{true, true, false, true, false, false});
        traverseOut(vertex2,{false, false, false, true, false, true});
    }
    void outedgeTraversalTest3(){
        auto g = g3;
        auto vertex1 = g->vertices_begin(),
                vertex2 = g->vertices_begin();

        shiftRight(vertex2, 5);

        traverseOut(vertex1,{true, true, false, false, false, false});
        traverseOut(vertex2,{false, true, false, true, false, true});
    }
    void inedgeTraversalTest1(){
        auto g = g1;
        auto vertex1 = g->vertices_begin(),
                vertex2 = g->vertices_begin();

        shiftRight(vertex2, 4);

        traverseIn(vertex1,{true,false,true,false,false,false});
        traverseIn(vertex2,{false, false, false, true, true, true});
    }
    void inedgeTraversalTest2(){
        auto g = g2;
        auto vertex1 = g->vertices_begin(),
                vertex2 = g->vertices_begin();

        shiftRight(vertex2, 1);

        traverseIn(vertex1,{false, false, false, false, false, false});
        traverseIn(vertex2,{true, true, false, true, false, false});
    }
    void inedgeTraversalTest3(){
        auto g = g3;
        auto vertex1 = g->vertices_begin(),
                vertex2 = g->vertices_begin();

        shiftRight(vertex2, 1);

        traverseIn(vertex1,{true, false, false, false, true, false});
        traverseIn(vertex2,{true, true, false, false, false, true});
    }

    static void traverseOut(Graph::vertex_iter& iter, std::vector<bool> expected){
        std::vector<bool> result = {false, false, false, false, false, false};
        auto it = iter.outedges_begin();
        auto end = iter.outedges_end();
        while(it != end){
            result[std::stoi(it.source()->label)] = true;
            result[std::stoi(it.destination()->label)] = true;
            ++it;
        }
        for(int i = 0; i < 6; i++){
            CPPUNIT_ASSERT_EQUAL(result[i],expected[i]);
        }
    }

    static void traverseIn(Graph::vertex_iter& iter, std::vector<bool> expected){
        std::vector<bool> result = {false, false, false, false, false, false};
        auto it = iter.inedges_begin();
        auto end = iter.inedges_end();
        while(it != end){
            result[std::stoi(it.source()->label)] = true;
            result[std::stoi(it.destination()->label)] = true;
            ++it;
        }
        for(int i = 0; i < 6; i++){
            CPPUNIT_ASSERT_EQUAL(result[i],expected[i]);
        }
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(BaseGraphTests);
CPPUNIT_TEST_SUITE_REGISTRATION(SpecialItersTests);