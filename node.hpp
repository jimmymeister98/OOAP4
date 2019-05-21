
//=============================================================================
#ifndef _NODE_HPP
#define _NODE_HPP

#include <vector>
#include <string>
#include "edge.hpp"
#include "liste.hpp"


class Node {

public:

    Node();

    Node(std::string key);

    Node(const Node &old);

    ~Node();

    std::string getKey();

    std::vector<Edge *> getEdges();

    void setKey(std::string key);

    void addEdge(Edge *edge);


private:

    std::string node_key;
    std::vector<Edge *> edges;

    friend class Edge;

    friend class DiGraph;
};

#endif
