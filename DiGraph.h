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
    friend class Node;
    friend class Edge;
    Node* findNode(vector<Node *> &list, string &key);
    vector<Node*> nodes;
    Node* findNode(string &key);
    Edge* findEdge(string &key);
    bool doesExist(vector<Node*> &list, Node * node);



public:
    void removeNode(string key);
    void removeConnectedEdges(Node * sadNode);
    void addNode(string key);
    void addEdge(string key, string key2, float weight);
    vector<Node*> getNeighbours (string key);
    vector<Edge*> getEdges(string key);
    vector<Node*>getnodes();
    void editEdge(string key, string key2, float weight);
    void removeEdge(string key, string key2);

    bool doesEdgeExist(vector<Node *> &list, string &key1, string &key2);
};


#endif //P3_DIGRAPH_H
