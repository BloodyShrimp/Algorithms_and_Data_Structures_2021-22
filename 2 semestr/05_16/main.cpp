#include <iostream>
#include "graph.hpp"

int main()
{
    Graph graf(3);
    auto i = graf.vertices_begin();
    auto e = graf.vertices_end();
    while (i != e)
    {
        (*i).label = "dupa";
        ++i;
    }
    graf.connect(Graph::vertex_iter(&graf, 1), Graph::vertex_iter(&graf, 2));
    graf.connect(Graph::vertex_iter(&graf, 0), Graph::vertex_iter(&graf, 1));
    graf.connect(Graph::vertex_iter(&graf, 0), Graph::vertex_iter(&graf, 2));

    auto iter = graf.vertices_begin();
    auto it = iter.inedges_begin();
    auto end = iter.inedges_end();
    while (it != end)
    {
        // result[std::stoi(it.source()->label)] = true;
        // result[std::stoi(it.destination()->label)] = true;
        ++it;
    }

    // int kupa = 0;

    // auto it = graf.edges_begin();
    // while (it != graf.edges_end())
    // {
    //     std::cout << kupa << std::endl;
    //     auto itSrc = it.source(), itDsc = it.destination();
    //     // CPPUNIT_ASSERT_EQUAL(g->are_connected(itSrc, itDsc),true);
    //     graf.disconnect(itSrc, itDsc);
    //     // CPPUNIT_ASSERT_EQUAL(g->are_connected(itSrc, itDsc),false);
    //     kupa++;
    //     ++it;
    // }

    // std::cout << graf.are_connected(Graph::vertex_iter(&graf, 1), Graph::vertex_iter(&graf, 2));
    // auto a = graf.vertices_begin().inedges_begin();
    // auto b = graf.vertices_begin().inedges_end();

    // int waga = 0;
    // while (a != b)
    // {
    //     (*a).weight = waga;
    //     ++a;
    //     waga++;
    // }
    // a = graf.edges_begin();
    // b = graf.edges_end();

    // while (a != b)
    // {
    //     std::cout << a.source().show_index() << a.destination().show_index() << std::endl;
    //     ++a;
    // }
}