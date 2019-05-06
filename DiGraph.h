//
// Created by jimmy on 06.05.19.
//

#ifndef P3_DIGRAPH_H
#define P3_DIGRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include "node.hpp"
using namespace std;


class DiGraph {
private:
    vector<Node*> nodes;
    Node* findNode(string &key);
    bool doesExist(vector<Node*> &list, Node * node);


public:
    void addNode(string key);
    void addEdge(string key, string key2, float weight);
    vector<Node*> getNeighbours (string key);
    vector<Edge*> getEdges(string key);
    vector<Node*>getnodes();
};


#endif //P3_DIGRAPH_H
