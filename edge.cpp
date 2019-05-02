
#include "edge.hpp"

Edge::Edge(void) {

}

Edge::Edge(Node *start, Node *end, double new_weight) {
    startnode = start;
    endnode = end;
    weight = new_weight;
}

Edge::Edge(const Edge &old) {
    startnode = old.startnode;
    endnode = old.endnode;
    weight = old.weight;
}

Edge::~Edge() {
    // Nothing to do ?
}

