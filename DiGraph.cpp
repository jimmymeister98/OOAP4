//
// Created by jimmy on 06.05.19.
//

#include "DiGraph.h"


void DiGraph::addNode(string key) {
    Node *newNode = new Node(key);
    nodes.push_back(newNode);
}

void DiGraph::addEdge(string key1, string key2, float weight) {
    Node *startNode = findNode(key1);
    Node *endNode = findNode(key2);
    Edge *newEdge = new Edge(startNode, endNode, weight);//in konstruktor 1
    startNode->addEdge(newEdge); //konstruktor 2
}

vector<Node *> DiGraph::getNeighbours(string key) {
    Node *node = findNode(key);

    vector<Node *> neighbours;
    if (node == nullptr)
        return neighbours;

    for (Edge *edge : node->getEdges()) // alternativ normaler for loop
        neighbours.push_back(edge->getEndNode()); //kopiert end nodes in neighbours

    for (Node *nodeSearch : nodes)
        for (Edge *edgeSearch : nodeSearch->getEdges())
            if (edgeSearch->getEndNode() == node && !doesExist(neighbours, nodeSearch))
                neighbours.push_back(nodeSearch);
}

Node *DiGraph::findNode(string &key) {
    for (Node *node : nodes)
        if (node->getKey() == key)
            return node;

    cout << "Konnte Knoten \"" << key << "\" nicht finden!" << endl;
    return nullptr;
}

bool DiGraph::doesExist(vector<Node *> &list, Node *node) {


    for (Node *nodeSearch : list)
        if (nodeSearch == node)
            return true;

    return false;
}

vector<Edge *> DiGraph::getEdges(string key) {

    return vector<Edge *>(findNode(key)->getEdges());
}

vector<Node *> DiGraph::getnodes() {
    return vector<Node *>(nodes);
}

void DiGraph::editEdge(string key1, string key2, float weight) {
    Node *startNode = findNode(key1);
    Node *endNode = findNode(key2);

    for (Edge *edge : startNode->getEdges())
        if (startNode == findNode(key1))
            if (endNode == findNode(key2))
                edge->setWeight(weight);

}

/*Edge *DiGraph::findEdge(string &key) {
    for (Edge* node : nodes)
        if (node->getKey() == key)
            return Edge;
    cout <<"Konnte Knoten \""<< key <<"\" nicht finden!"<< endl;
    return nullptr;
}
*/