
#include "edge.hpp"
using namespace std;
Edge::Edge() {

}

Edge::Edge(Node *start, Node *end, double new_weight) {
    this->startnode = start;
    this->endnode = end;
    this->weight = new_weight;
}

Edge::Edge(const Edge &old) {
    this->startnode = old.startnode;
    this->endnode = old.endnode;
    this->weight = old.weight;
}
Edge::~Edge() {
this->startnode = nullptr;
this->endnode = nullptr;
delete this;
}

float Edge::getWeight() {
    return this->weight;
}

Node * Edge::getStartNode() {
    return this->startnode;
}

Node * Edge::getEndNode() {
    return this->endnode;
}
void Edge::setWeight(float weight) {
    this->weight = weight;
}

void Edge::setStartNode(Node * node) {
    this->startnode = node;
}

void Edge::setEndNode(Node * node) {
    this->endnode = node;
}





