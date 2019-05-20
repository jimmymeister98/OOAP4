//
// Created by jimmy on 06.05.19.
//

#include "DiGraph.h"


Node *DiGraph::findNode(vector<Node *> &list, string &key) {
    for (Node *node : list)    // for-each loop | (for each Node*  in  nodes)
        if (node->getKey() == key)
            return node;

    return nullptr;
}


void DiGraph::addNode(string key) {
    Node *newNode = new Node(key);
    nodes.push_back(newNode);
}

bool DiGraph::doesEdgeExist(vector<Node *> &list, string &key1, string &key2) {
    Node *node = findNode(list, key1);
    if (node == nullptr)
        return false;
    for (Edge *edge : node->edges)
        if (edge->getEndNode()->getKey() == key2)
            return true;
    return false;
}


void DiGraph::addEdge(string key1, string key2, float weight) {
    if (doesEdgeExist(nodes, key1, key2))
        throw runtime_error("Die Edge \"" + key1 + " -> " + key2 +
                            "\" existiert bereits und kann deshalb nicht hinzugef\201gt werden!");

    Node *startNode = findNode(nodes, key1);
    if (startNode == nullptr)
        throw runtime_error("Die Node \"" + key1 + "\" existiert nicht, daher kann die Edge \"" + key1 + " -> " + key2 +
                            "\" nicht hinzugef\201gt werden!");

    Node *endNode = findNode(nodes, key2);
    if (endNode == nullptr)
        throw runtime_error("Die Node \"" + key2 + "\" existiert nicht, daher kann die Edge \"" + key1 + " -> " + key2 +
                            "\" nicht hinzugef\201gt werden!");

    Edge *newEdge = new Edge(startNode, endNode, weight);
    startNode->addEdge(newEdge);

}

vector<Node *> DiGraph::getNeighbours(string key) {
    Node *node = findNode(key);

    vector<Node *> neighbours;
    if (node == nullptr)
        return neighbours; // return empty vector

    // Add all outwards facing edges
    for (Edge *edge : node->getEdges())
        neighbours.push_back(edge->getEndNode());

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

void DiGraph::removeEdge(string key1, string key2) {
    Node *startNode = findNode(key1);
    Node *endNode = findNode(key2);
    vector<Edge *> Edges = startNode->getEdges();
    for (int i = 0; i < startNode->edges.size(); i++) {
        if (Edges[i]->endnode == endNode) {
            delete startNode->edges[i];
            startNode->edges.erase(startNode->edges.begin() + i);
            return;
        }
    }

}


void DiGraph::removeConnectedEdges(
        Node *sadNode) {    // node will be very sad because he wont have connections after this | this is so sad - can we get 420 updoots?
    for (Node *node : nodes)
        for (int i = 0; i < node->edges.size(); i++)
            if (node->edges[i]->getStartNode() == sadNode || node->edges[i]->getEndNode() == sadNode) {
                delete node->edges[i];  // free allocated memory first
                node->edges.erase(node->edges.begin() + i); // remove edge at index i
                i--;    // to accommodate for the removal of one entry
            }
}


void DiGraph::removeNode(string key) {
    Node *removingNode = findNode(nodes, key);
    if (removingNode == nullptr)
        throw runtime_error("Die Node \"" + key + "\" ist nicht im Graphen und kann deshalb nicht entfernt werden!");

    removeConnectedEdges(removingNode); // firstly, remove all the edges to and from the node that we want to remove
    for (int i = 0; i < nodes.size(); i++)  // then, remove the node itself
        if (nodes[i] == removingNode) {
            delete nodes[i];    // free the allocated memory first
            nodes.erase(nodes.begin() + i);
            break;  // done
        }
}







/*Edge *DiGraph::findEdge(string &key) {
    for (Edge* node : nodes)
        if (node->getKey() == key)
            return Edge;
    cout <<"Konnte Knoten \""<< key <<"\" nicht finden!"<< endl;
    return nullptr;
}
*/