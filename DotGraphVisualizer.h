//
// Created by aris on 01.05.2019.
//

#ifndef OOA_PRAKTIKUM_3_DOTGRAPHVISUALIZER_HPP
#define OOA_PRAKTIKUM_3_DOTGRAPHVISUALIZER_HPP

#include "DiGraph.h"
#include <iostream>
#include <fstream>
using namespace std;
class DotGraphVisualizer {  //
public:

    /* Gibt den übergebenen Graphen auf der Konsole in der DOT-Notation aus. Bei-
       spiele hierzu ﬁnden Sie im Anhang in den Abbildungen 3 bis 5. */
    void visualize(DiGraph &graph,string name) {

        ofstream myfile;
        myfile.open (name,ios::out);

        if (myfile.is_open())
        {
        myfile << "digraph {" << endl;    // Start
        myfile << "\tnode [shape = circle];" << endl;   // Set shape of node to circle

        // print all
        for (Node * node : graph.getnodes())
            for (Edge * edge : node->getEdges()) {
                myfile << "\t\"" << edge->getStartNode()->getKey() << "\"\t";

                if (edge->getStartNode()->getKey().size() + 2 <= 7) // If text to small, add tab
                    myfile << "\t";

                myfile << "->\t\"" << edge->getEndNode()->getKey() << "\"\t";

                if (edge->getEndNode()->getKey().size() + 2 <= 7)   // If text to small, add tab
                    myfile << "\t";

                myfile << "[label=" << edge->getWeight() << "];" << endl;
            }
        myfile << "}" << endl;    // End
        myfile.close();
    } else
    cout<<"Konnte datei nicht oeffnen";}
};

#endif //OOA_PRAKTIKUM_3_DOTGRAPHVISUALIZER_HPP
