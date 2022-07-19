#include <iostream>
#include <string>
#include <fstream>
#include "graph.hpp"

int find_longest_path(Graph::vertex_iter _vertex_iter, int depth)
{
    auto in_edge_iter = _vertex_iter.inedges_begin();
    auto in_edge_end = _vertex_iter.inedges_end();
    int new_depth = 0;
    int highest_depth = depth;
    while (in_edge_iter != in_edge_end)
    {
        new_depth = find_longest_path(in_edge_iter.source(), depth + 1);
        if (new_depth > highest_depth)
        {
            highest_depth = new_depth;
        }
        ++in_edge_iter;
    }
    return highest_depth;
}

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Nieprawidłowa liczba argumentów" << std::endl;
        std::exit(1);
    }
    std::string filename = argv[1];
    std::string przedmiot = argv[2];
    int przedmiot_index = -1;

    std::ifstream read_file(filename);
    std::string text_line;

    int subject_number;

    getline(read_file, text_line);
    subject_number = std::stoi(text_line);

    Graph graph(subject_number);
    auto vertex_it = graph.vertices_begin();

    for (int i = 0; i < subject_number; i++)
    {
        getline(read_file, text_line);
        (*vertex_it).label = text_line;
        if (text_line == przedmiot)
        {
            przedmiot_index = i;
        }
        ++vertex_it;
    }

    if (przedmiot_index == -1)
    {
        std::cout << "Nie ma takiego przedmiotu" << std::endl;
        std::exit(1);
    }

    while (getline(read_file, text_line))
    {
        int source = std::stoi(text_line.substr(0, text_line.find(" "))) - 1;
        int target = std::stoi(text_line.substr(text_line.find(" ") + 1)) - 1;
        graph.connect(graph.vertex_by_index(source), graph.vertex_by_index(target));
    }

    vertex_it = graph.vertex_by_index(przedmiot_index);
    int longest_path = 0;
    longest_path = find_longest_path(vertex_it, 1);
    std::cout << longest_path << std::endl;
}