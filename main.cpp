#include <iostream>
#include <vector>
#include "DiGraph.h"
#include "DotGraphVisualizer.h"
#include "input.h"

using namespace std;

/*int testDriver() {

    cout << "Creating graph and adding Nodes... " << endl;

    DiGraph graph;
    graph.addNode("Krefeld");
    graph.addNode("Koeln");
    graph.addNode("Duesseldorf");
    graph.addNode("Wuppertal");
    //graph.removeNode("Buxtehude");  //Test error throw
    //graph.removeNode("Krefeld");    //Test error throw

    cout << "Done!" << endl << "Adding Edges ..." << endl;

    graph.addEdge("Krefeld", "Koeln", 59.0);
    graph.addEdge("Krefeld", "Duesseldorf", 4.1);
    graph.addEdge("Duesseldorf", "Koeln", 44.0);
    graph.addEdge("Koeln", "Wuppertal", 52.2);
    graph.editEdge("Koeln", "Wuppertal", 4.4);
    graph.addEdge("Wuppertal", "Duesseldorf", 69.9);
    graph.removeEdge("Krefeld","Duesseldorf"); //todo
    graph.removeNode("Wuppertal");


    cout << "Done!" << endl << "Getting and printing neighbours of Wuppertal..." << endl;
    vector<Node*> wuppNeigh = graph.getNeighbours("Wuppertal");
    for (Node * node : wuppNeigh)
        cout << node->getKey() << endl;

    cout << "Done!" << endl << "Visualizing now..." << endl;
    DotGraphVisualizer dgv;
    dgv.visualize(graph);

    cout << "Done!" << endl << "Done testing!" << endl;
}
*/
int main() {
    //  testDriver();
    // DiGraph graph;
    input(); //Lese aus datei ein und gib übersetzt in datei aus


    return 0;
}
