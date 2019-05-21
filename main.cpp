#include <iostream>
#include <vector>
#include "DiGraph.h"
#include "DotGraphVisualizer.h"
#include "input.h"
#include <cctype>

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
    DiGraph graph;
    while (true) {
        cout << "Was m\224chtest du machen?\n"
                "-1: Beenden\n"
                " 1: Node hinzuf\201gen\n"
                " 2: Edge hinzuf\201gen\n"
                " 3: Node l\224schen\n"
                " 4: Edge l\224schen\n"
                " 5: Kantengewicht \204ndern\n"
                " 6: Alle Nodes und Edges l\224schen\n"
                " 7: Graph in Datei speichern\n"
                " 8: Graph aus Datei laden\n"<<endl;

        int inputcase;
        cin >> inputcase;
        cin.clear();
        cin.ignore();
        cout << "##########################################################\n";
        //try {
        switch (inputcase) {
            case -1:
                break;

            case 1: {
                cout << "Node hinzuf\201gen - bitte Node-Bezeichnung angeben:";
                string name;
                //cin >> name;
                getline(cin, name);
                graph.addNode(name);
                cout << "Node " << name << " wurde hinzugefügt\n";
                break;
            }
            case 2: {
                cout << "Edge hinzuf\201gen\n";
                string node1, node2, catcher;
                cout << "Bereits existierende StartNode angeben";
                getline(cin, node1);
                cin.clear();
                cout << "Bereits existierende EndNode angeben";
                getline(cin, node2);
                cin.clear();
                float weight;
                cout << "Gewicht angeben(in Ganz oder Kommazahlen)";
                getline(cin, catcher);
                char tester;
                bool isdigittest = false;
                int size = catcher.length();
                for (int i = 0; i < size; i++) {
                    tester = catcher[i];
                    if ((tester >= '0' && tester <= '9') || tester == '.') {
                        isdigittest = true;
                    }
                }
                if (isdigittest == false) {
                    cout << "Hab ich nicht ganz oder kommazahlen gesagt??" << endl;
                    break;
                }
                float zahl = stof(catcher);
                graph.addEdge(node1, node2, zahl);
                cout << "eingetragen" << endl;
                break;
            }
            case 3: {
                cout << "Node loeschen - Existierende Node angeben" << endl;
                string name;
                getline(cin, name);
                graph.removeNode(name);
                cout << "Node \"" << name << "\" erfolgreich entfernt!" << endl;
                break;

            }

              case 4: { // Edge löschen
                  cout << "Edge loeschen:\nBitte Start-Node angeben:";
                  string startNode;
                  getline(cin, startNode);

                  cout << "Bitte End-Node angeben:";
                  string endNode;
                  getline(cin, endNode);

                  graph.removeEdge(startNode, endNode);
                 // cout << "Edge \"" << startNode << " -> " << endNode << "\" erfolgreich entfernt!" << endl;
                  break;
              }


            case 5: { // Kantengewicht ändern
                cout << "Edge Gewicht \204ndern:\nBitte Start-Node angeben:";
                string Node1;
                getline(cin, Node1);

                cout << "Bitte End-Node angeben:";
                string Node2;
                getline(cin, Node2);

                cout << "Neues Gewicht angeben(in Ganz oder Kommazahlen)";
                string catcher;
                getline(cin, catcher);
                char tester;
                bool isdigittest = false;
                int size = catcher.length();
                for (int i = 0; i < size; i++) {
                    tester = catcher[i];
                    if ((tester >= '0' && tester <= '9') || tester == '.') {
                        isdigittest = true;
                    }
                }
                if (isdigittest == false) {
                    cout << "Hab ich nicht ganz oder kommazahlen gesagt??" << endl;
                    break;

                }
                float zahl = stof(catcher);
                graph.editEdge(Node1,Node2,zahl);
                break;

            }
            case 6:{
                graph.clear();
                cout<<"Graph wurde komplett geleert"<<endl;
            }

            case 7:{
                cout << "Graph in Datei speichern - Datei wird im executable ordner gespeichert";
                DotGraphVisualizer dot;

                string name;
                getline(cin,name);

                dot.visualize(graph,name);
                cout << "Graph wurde erfolgreich nach \"" << name << "\" gespeichert!" << endl;
                break;





            }
            case 8:{

                cout << "Graph aus Datei laden - Bitte namen angeben mit .txt am ende";
                string name;
                getline(cin,name);
                input(name);
                cout << "Graph wurde erfolgreich nach \"" << name << "\" gespeichert!" << endl;
                break;

            }
                default: {// Falsche Eingabe
                      throw runtime_error("Ungueltige Eingabe, bitte eine der aufgefuehrten Optionen waehlen!");

            }

            /*   catch (runtime_error & error) {
                   cout << "@@@ ERROR: " << error.what() << endl;
               }*/

            //  testDriver();
            // DiGraph graph;
            // input(); //Lese aus datei ein und gib übersetzt in datei aus

        }

    }
}
