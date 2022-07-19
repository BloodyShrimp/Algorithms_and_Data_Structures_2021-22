#ifndef GRAPH
#define GRAPH
#include <string>
#include <vector>
#include <iostream>

class Graph
{
private:
    class edge;
    class vertex;
    std::vector<std::vector<edge>> edges;
    std::vector<vertex> vertices;
    int vertices_amount = 0;
    int edges_amount = 0;

public:
    class vertex_iter;
    class edge_iter;
    class outedge_iter;
    class inedge_iter;
    Graph(int vertex_count);                              // konstruktor
    ~Graph();                                             // zwalniający zasoby destruktor
    int vertex_count();                                   // zwraca liczbę wierzchołków
    int edge_count();                                     // zwraca liczbę krawędzi
    edge_iter connect(vertex_iter src, vertex_iter dst);  // dodaje krawędź, zwraca iterator ją pokazujący
    void disconnect(vertex_iter src, vertex_iter dst);    // usuwa krawędź
    bool are_connected(vertex_iter src, vertex_iter dst); // sprawdza, czy dwa wierzchołki są połączone krawędzią
    vertex_iter vertices_begin();
    vertex_iter vertices_end();
    edge_iter edges_begin();
    edge_iter edges_end();
    vertex_iter vertex_by_index(int index);
};

class Graph::vertex_iter
{
private:
    Graph *graph;
    vertex *current_vertex;
    int current_index;

public:
    vertex_iter(Graph *graph_);
    vertex_iter(Graph *graph_, int index);
    bool operator==(vertex_iter other);
    bool operator!=(vertex_iter other);
    vertex_iter &operator++(); // przesuń się na następny wierzchołek i zwróć referencję do samego siebie
    vertex &operator*();       // zwróć referencję do obiektu z atrybutami bieżącego wierzchołka
    vertex *operator->();      // zwróć wskaźnik do obiektu z atrybutami wierzchołka
    outedge_iter outedges_begin();
    outedge_iter outedges_end();
    inedge_iter inedges_begin();
    inedge_iter inedges_end();
    int show_index();
};

class Graph::edge_iter
{
private:
    Graph *graph;
    edge *current_edge;
    int current_x;
    int current_y;

public:
    edge_iter(Graph *graph_);
    edge_iter(Graph *graph_, int x, int y);
    bool operator==(edge_iter other);
    bool operator!=(edge_iter other);
    edge_iter &operator++();
    edge &operator*();
    edge *operator->();
    vertex_iter source();
    vertex_iter destination();
};

class Graph::outedge_iter
{
private:
    Graph *graph;
    edge *current_edge;
    int current_x;
    int current_y;

public:
    outedge_iter(Graph *graph_, vertex_iter *vertex_);
    bool operator==(outedge_iter other);
    bool operator!=(outedge_iter other);
    outedge_iter &operator++();
    edge &operator*();
    edge *operator->();
    vertex_iter source();
    vertex_iter destination();
};

class Graph::inedge_iter
{
private:
    Graph *graph;
    edge *current_edge;
    int current_x;
    int current_y;

public:
    inedge_iter(Graph *graph_, vertex_iter *vertex_);
    bool operator==(inedge_iter other);
    bool operator!=(inedge_iter other);
    inedge_iter &operator++();
    edge &operator*();
    edge *operator->();
    vertex_iter source();
    vertex_iter destination();
};

class Graph::edge
{
public:
    double weight = 0;
    bool presence = false;
};

class Graph::vertex
{
public:
    std::string label = "";
};

#endif // GRAPH
