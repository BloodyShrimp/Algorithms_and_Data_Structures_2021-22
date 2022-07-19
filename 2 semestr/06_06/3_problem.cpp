#include <iostream>
#include <random>
#include <list>
#include "graph.hpp"

// węzły to pola w labyryncie
// krawędzie to ściany między polami
// na początku labyrint to siatka ściań
// modeluję labyrint za pomocą algorytmu Prima usuwając sukcesywnie ściany

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Nieprawidłowa liczba argumentów" << std::endl;
        std::exit(1);
    }

    int rows = std::stoi(argv[1]);
    int columns = std::stoi(argv[2]);

    Graph graph(rows * columns);
    auto horizontal_vertex_it = graph.vertices_begin();
    auto vertical_vertex_it = graph.vertices_begin();
    auto right_of = graph.vertex_by_index(1);
    auto below_of = graph.vertex_by_index(columns);

    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < columns - 1; j++)
        {
            graph.connect(horizontal_vertex_it, right_of);
            graph.connect(right_of, horizontal_vertex_it);
            ++right_of;
            ++horizontal_vertex_it;
        }
        ++right_of;
        ++horizontal_vertex_it;
        for (int j = 0; j < columns; j++)
        {
            graph.connect(vertical_vertex_it, below_of);
            graph.connect(below_of, vertical_vertex_it);
            ++below_of;
            ++vertical_vertex_it;
        }
    }
    for (int j = 0; j < columns - 1; j++)
    {
        graph.connect(horizontal_vertex_it, right_of);
        graph.connect(right_of, horizontal_vertex_it);
        ++right_of;
        ++horizontal_vertex_it;
    }

    std::list<Graph::outedge_iter> walls;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, rows * columns - 1);
    int random_vertex = dist(rng);

    auto vertex_it = graph.vertex_by_index(random_vertex);
    (*vertex_it).visited = true;

    if (vertex_it.outedges_begin() != vertex_it.outedges_end())
    {
        auto outedge_it = vertex_it.outedges_begin();
        while (outedge_it != vertex_it.outedges_end())
        {
            walls.push_front(outedge_it);
            ++outedge_it;
        }
    }
    while (!walls.empty())
    {
        std::uniform_int_distribution<std::mt19937::result_type> dist_walls(0, walls.size() - 1);
        int random_wall = dist_walls(rng);
        auto walls_it = walls.begin();
        for (int i = 0; i < random_wall; i++)
        {
            ++walls_it;
        }
        
        if ((*(*walls_it).destination()).visited == false)
        {
            vertex_it = (*walls_it).destination();
            (*(*walls_it).destination()).visited = true;
            (*(*walls_it).source()).visited = true;
            graph.disconnect((*walls_it).source(), (*walls_it).destination());
            graph.disconnect((*walls_it).destination(), (*walls_it).source());
            if (vertex_it.outedges_begin() != vertex_it.outedges_end())
            {
                auto outedge_it = vertex_it.outedges_begin();
                while (outedge_it != vertex_it.outedges_end())
                {
                    walls.push_front(outedge_it);
                    ++outedge_it;
                }
            }
        }
        walls.erase(walls_it);
    }

    horizontal_vertex_it = graph.vertices_begin();
    vertical_vertex_it = graph.vertices_begin();
    right_of = graph.vertex_by_index(1);
    below_of = graph.vertex_by_index(columns);

    for (int j = 0; j < columns; j++)
    {
        std::cout << "+-";
    }
    std::cout << "+" << std::endl;

    for (int i = 0; i < rows - 1; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < columns - 1; j++)
        {
            if (!graph.are_connected(horizontal_vertex_it, right_of))
            {
                std::cout << " ";
            }
            else
            {
                std::cout << "|";
            }
            ++right_of;
            ++horizontal_vertex_it;
            std::cout << " ";
        }
        ++right_of;
        ++horizontal_vertex_it;
        std::cout << "|\n+";

        for (int j = 0; j < columns; j++)
        {
            if (!graph.are_connected(vertical_vertex_it, below_of))
            {
                std::cout << " +";
            }
            else
            {
                std::cout << "-+";
            }
            ++below_of;
            ++vertical_vertex_it;
        }
        std::cout << "\n";
    }
    std::cout << "| ";
    for (int j = 0; j < columns - 1; j++)
    {
        if (!graph.are_connected(horizontal_vertex_it, right_of))
        {
            std::cout << " ";
        }
        else
        {
            std::cout << "|";
        }
        ++right_of;
        ++horizontal_vertex_it;
        std::cout << " ";
    }
    std::cout << "|\n";
    for (int j = 0; j < columns; j++)
    {
        std::cout << "+-";
    }
    std::cout << "+" << std::endl;
}