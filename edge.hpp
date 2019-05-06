
#ifndef _EDGE_HPP
#define _EDGE_HPP

class Node;


class Edge {
private:
    // Zum Speichern der Adressen der verbundenen Knoten.
    Node *startnode;
    Node *endnode;

    // Zum Speichern des Kantengewichts.
    float weight;

public:
    Edge();
    Edge(Node *start, Node *end, double new_weight);
    Edge(const Edge &old);    // Copy-Constructor
    ~Edge();

    float getWeight();
    Node * getStartNode();
    Node * getEndNode();
    void setWeight(float weight);
    void setStartNode(Node * node);
    void setEndNode(Node * node);
};




#endif
