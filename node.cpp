

#include "node.hpp"

Node::Node() {

}

Node::Node(std::string key) {
    this->node_key = key;
}

Node::Node(const Node &old) {
    this->node_key = old.node_key;
}

Node::~Node() {
    // Nothing to do
}

std::string Node::getKey() {
    return this->node_key;
}

std::vector<Edge *> Node::getEdges() {        // Normally, this would return exact vector of this Edge, but we ...
    return std::vector<Edge *>(this->edges);  // ... return a copy of the vector (this->edges)
}

void Node::setKey(std::string key) {
    this->node_key = key;
}

void Node::addEdge(Edge *edge) {
    this->edges.push_back(edge);
}
