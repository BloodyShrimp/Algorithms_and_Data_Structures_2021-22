#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <float.h>
#include "graph.hpp"

#define INF DBL_MAX
#define NULLVERT -1

class Answer
{
public:
    std::vector<std::vector<double>> dist;
    std::vector<std::vector<int>> next;
    Answer(std::vector<std::vector<double>> _dist, std::vector<std::vector<int>> _next)
    {
        dist = _dist;
        next = _next;
    }
};

Answer floydWarshall(Graph _graph)
{
    int vert_amount = _graph.vertex_count();
    std::vector<std::vector<double>> dist(vert_amount, std::vector<double>(vert_amount, INF));
    std::vector<std::vector<int>> next(vert_amount, std::vector<int>(vert_amount, NULLVERT));

    auto edge_it = _graph.edges_begin();
    auto end_edge = _graph.edges_end();

    while (edge_it != end_edge)
    {
        dist[edge_it.show_x()][edge_it.show_y()] = (*edge_it).weight;
        next[edge_it.show_x()][edge_it.show_y()] = edge_it.show_y();
        ++edge_it;
    }

    auto vertex_it = _graph.vertices_begin();
    auto end_vertex = _graph.vertices_end();

    while (vertex_it != end_vertex)
    {
        dist[vertex_it.show_index()][vertex_it.show_index()] = 0;
        next[vertex_it.show_index()][vertex_it.show_index()] = vertex_it.show_index();
        ++vertex_it;
    }

    for (int k = 0; k < vert_amount; k++)
    {
        for (int i = 0; i < vert_amount; i++)
        {
            for (int j = 0; j < vert_amount; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    return Answer(dist, next);
}

std::vector<int> path_reconstruction(int _x, int _y, std::vector<std::vector<int>> _next)
{
    std::vector<int> recon_path;
    int x = _x;
    int y = _y;
    if (_next[x][y] == NULLVERT)
    {
        recon_path.clear();
        return recon_path;
    }
    recon_path.push_back(x);
    while(x != y)
    {
        x = _next[x][y];
        recon_path.push_back(x);
    }
    x = _y;
    y = _x;
    if (_next[x][y] == NULLVERT)
    {
        recon_path.clear();
        return recon_path;
    }
    while(x != y)
    {
        x = _next[x][y];
        recon_path.push_back(x);
    }
    return recon_path;
}

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Nieprawidłowa liczba argumentów" << std::endl;
        std::exit(1);
    }
    std::string filename = argv[1];

    std::ifstream read_file(filename);
    std::string text_line;

    int metal_amount;

    getline(read_file, text_line);
    metal_amount = std::stoi(text_line);

    Graph graph(metal_amount);
    auto vertex_it = graph.vertices_begin();

    for (int i = 0; i < metal_amount; i++)
    {
        getline(read_file, text_line);
        (*vertex_it).value = std::stod(text_line);
        ++vertex_it;
    }

    while (getline(read_file, text_line))
    {
        size_t pos = text_line.find(" ");
        int source = std::stoi(text_line.substr(0, pos)) - 1;
        text_line.erase(0, pos + 1);
        pos = text_line.find(" ");
        int target = std::stoi(text_line.substr(0, pos)) - 1;
        text_line.erase(0, pos + 1);
        pos = text_line.find(" ");
        double price = std::stod(text_line.substr(0, pos));
        auto edge = graph.connect(graph.vertex_by_index(source), graph.vertex_by_index(target));
        (*edge).weight = price;
    }

    auto result = floydWarshall(graph);
    auto paths = result.dist;
    auto roads = result.next;

    std::vector<std::vector<double>> costs(metal_amount, std::vector<double>(metal_amount, INF));

    for (int i = 0; i < metal_amount; i++)
    {
        for (int j = 0; j < metal_amount; j++)
        {
            costs[i][j] = paths[i][j] + paths[j][i] + ((*graph.vertex_by_index(j)).value / 2);
        }
    }

    std::vector<double> final_price(metal_amount, -1.0);
    std::vector<int> best_transmutation(metal_amount, -1);

    for (int i = 0; i < metal_amount; i++)
    {
        auto row = costs[i];
        auto min_it = std::min_element(row.begin(), row.end());
        double min_value = *min_it;
        int min_index = std::distance(row.begin(), min_it);
        final_price[i] = min_value;
        best_transmutation[i] = min_index;
    }

    double clo;

    for (int i = 0; i < metal_amount; i++)
    {
        auto best_path = path_reconstruction(i, best_transmutation[i], roads);
        std::string path_str = "";
        for (auto c : best_path)
        {
            path_str = path_str + std::to_string(c+1) + "-";
        }
        path_str = path_str.substr(0, path_str.size()-1);
        clo = (*graph.vertex_by_index(i)).value / 2;
        std::cout << i+1 << " (cło: " << clo << " d/lb) : " << path_str << " (cło i reagenty: " << final_price[i] << " d/lb)" << std::endl;
    }
}