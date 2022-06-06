#include "graph.hpp"

//----------------------------------------------------------------------
// GRAPH
//----------------------------------------------------------------------

Graph::Graph(int vertex_count)
{
    vertices_amount = vertex_count;
    for (int i = 0; i < vertex_count; i++)
    {
        edges.push_back(std::vector<Graph::edge>());
        vertices.push_back(vertex());
        for (int j = 0; j < vertex_count; j++)
        {
            edges[i].push_back(edge());
        }
    }
}

Graph::~Graph()
{
}

int Graph::vertex_count()
{
    return vertices_amount;
}

int Graph::edge_count()
{
    return edges_amount;
}

Graph::edge_iter Graph::connect(vertex_iter src, vertex_iter dst)
{
    edges[src.show_index()][dst.show_index()].presence = true;
    edges_amount++;
    return edge_iter(this, src.show_index(), dst.show_index());
}

void Graph::disconnect(vertex_iter src, vertex_iter dst)
{
    edges[src.show_index()][dst.show_index()].presence = false;
}

bool Graph::are_connected(vertex_iter src, vertex_iter dst)
{
    return edges[src.show_index()][dst.show_index()].presence;
}

Graph::vertex_iter Graph::vertices_begin()
{
    vertex_iter iter(this, 0);
    return iter;
}

Graph::vertex_iter Graph::vertices_end()
{
    vertex_iter iter(this, vertices_amount);
    return iter;
}

Graph::edge_iter Graph::edges_begin()
{
    edge_iter iter(this);
    return iter;
}

Graph::edge_iter Graph::edges_end()
{
    edge_iter iter(this, vertices_amount, 0);
    // for (int i = 0; i < edges_amount; i++)
    // {
    //     ++iter;
    // }
    return iter;
}

//----------------------------------------------------------------------
// VERTEX_ITER
//----------------------------------------------------------------------

Graph::vertex_iter::vertex_iter(Graph *graph_)
{
    graph = graph_;
    current_vertex = &graph->vertices[0];
    current_index = 0;
}

Graph::vertex_iter::vertex_iter(Graph *graph_, int index)
{
    graph = graph_;
    current_vertex = &graph->vertices[index];
    current_index = index;
}

bool Graph::vertex_iter::operator==(vertex_iter other)
{
    return current_vertex == other.current_vertex;
}

bool Graph::vertex_iter::operator!=(vertex_iter other)
{
    return current_vertex != other.current_vertex;
}

Graph::vertex_iter &Graph::vertex_iter::operator++()
{
    current_index++;
    current_vertex = &graph->vertices[current_index];
    return *this;
}

Graph::vertex &Graph::vertex_iter::operator*()
{
    return *current_vertex;
}

Graph::vertex *Graph::vertex_iter::operator->()
{
    return current_vertex;
}

Graph::outedge_iter Graph::vertex_iter::outedges_begin()
{
    outedge_iter iter(graph, this);
    return iter;
}

Graph::outedge_iter Graph::vertex_iter::outedges_end()
{
    outedge_iter iter(graph, this);
    int j = 0;
    for(int i = 0; i < graph->vertices_amount; i++)
    {
        if(graph->edges[this->show_index()][i].presence)
        {
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        ++iter;
    }
    return iter;
}

Graph::inedge_iter Graph::vertex_iter::inedges_begin()
{
    inedge_iter iter(graph, this);
    return iter;
}

Graph::inedge_iter Graph::vertex_iter::inedges_end()
{
    inedge_iter iter(graph, this);
    int j = 0;
    for(int i = 0; i < graph->vertices_amount; i++)
    {
        if(graph->edges[i][this->show_index()].presence)
        {
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        ++iter;
    }
    return iter;
}

int Graph::vertex_iter::show_index()
{
    return current_index;
}

//----------------------------------------------------------------------
// EDGE_ITER
//----------------------------------------------------------------------

Graph::edge_iter::edge_iter(Graph *graph_)
{
    graph = graph_;
    current_edge = &graph->edges[0][0];
    current_x = 0;
    current_y = 0;
    while (current_edge->presence == false)
    {
        ++*this;
    }
}

Graph::edge_iter::edge_iter(Graph *graph_, int x, int y)
{
    graph = graph_;
    current_edge = &graph->edges[x][y];
    current_x = x;
    current_y = y;
    // if (current_edge->presence == false)
    // {
    //     ++*this;
    // }
}

bool Graph::edge_iter::operator==(edge_iter other)
{
    return current_edge == other.current_edge;
}

bool Graph::edge_iter::operator!=(edge_iter other)
{
    return current_edge != other.current_edge;
}

Graph::edge_iter &Graph::edge_iter::operator++()
{
    do
    {
        current_y++;
        if (current_y == graph->vertex_count())
        {
            current_y = 0;
            current_x++;
        }
        current_edge = &graph->edges[current_x][current_y];
        if (current_x == graph->vertices_amount)
        {
            break;
        }
    } while (current_edge->presence == false);
    return *this;
}

Graph::edge &Graph::edge_iter::operator*()
{
    return *current_edge;
}

Graph::edge *Graph::edge_iter::operator->()
{
    return current_edge;
}

Graph::vertex_iter Graph::edge_iter::source()
{
    return vertex_iter(graph, current_x);
}

Graph::vertex_iter Graph::edge_iter::destination()
{
    return vertex_iter(graph, current_y);
}

//----------------------------------------------------------------------
// OUTEDGE_ITER
//----------------------------------------------------------------------

Graph::outedge_iter::outedge_iter(Graph *graph_, vertex_iter *vertex_)
{
    graph = graph_;
    current_edge = &graph->edges[vertex_->show_index()][0];
    current_x = vertex_->show_index();
    current_y = 0;
    if (current_edge->presence == false)
    {
        ++*this;
    }
}

bool Graph::outedge_iter::operator==(outedge_iter other)
{
    return current_edge == other.current_edge;
}

bool Graph::outedge_iter::operator!=(outedge_iter other)
{
    return current_edge != other.current_edge;
}

Graph::outedge_iter &Graph::outedge_iter::operator++()
{
    if(current_y == graph->vertices_amount)
    {
        return *this;
    }
    do
    {
        current_y++;
        current_edge = &graph->edges[current_x][current_y];
        if (current_y == graph->vertices_amount)
        {
            break;
        }
    } while (current_edge->presence == false);
    return *this;
}

Graph::edge &Graph::outedge_iter::operator*()
{
    return *current_edge;
}

Graph::edge *Graph::outedge_iter::operator->()
{
    return current_edge;
}

Graph::vertex_iter Graph::outedge_iter::source()
{
    return vertex_iter(graph, current_x);
}

Graph::vertex_iter Graph::outedge_iter::destination()
{
    return vertex_iter(graph, current_y);
}

//----------------------------------------------------------------------
// INEDGE_ITER
//----------------------------------------------------------------------

Graph::inedge_iter::inedge_iter(Graph *graph_, vertex_iter *vertex_)
{
    graph = graph_;
    current_edge = &graph->edges[0][vertex_->show_index()];
    current_y = vertex_->show_index();
    current_x = 0;
    if (current_edge->presence == false)
    {
        ++*this;
    }
}

bool Graph::inedge_iter::operator==(inedge_iter other)
{
    return current_edge == other.current_edge;
}

bool Graph::inedge_iter::operator!=(inedge_iter other)
{
    return current_edge != other.current_edge;
}

Graph::inedge_iter &Graph::inedge_iter::operator++()
{
    if(current_x == graph->vertices_amount)
    {
        return *this;
    }
    do
    {
        current_x++;
        current_edge = &graph->edges[current_x][current_y];
        if (current_x == graph->vertices_amount)
        {
            break;
        }
    } while (current_edge->presence == false);
    return *this;
}

Graph::edge &Graph::inedge_iter::operator*()
{
    return *current_edge;
}

Graph::edge *Graph::inedge_iter::operator->()
{
    return current_edge;
}

Graph::vertex_iter Graph::inedge_iter::source()
{
    return vertex_iter(graph, current_x);
}

Graph::vertex_iter Graph::inedge_iter::destination()
{
    return vertex_iter(graph, current_y);
}