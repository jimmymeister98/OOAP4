//
// Created by arisl on 01.05.2019.
//

#ifndef OOA_PRAKTIKUM_3_DOTGRAPHVISUALIZER_HPP
#define OOA_PRAKTIKUM_3_DOTGRAPHVISUALIZER_HPP

#include "DiGraph.h"

class DotGraphVisualizer {  // TODO: Implementieren
public:
    /* Gibt den übergebenen Graphen auf der Konsole in der DOT-Notation aus. Bei-
       spiele hierzu ﬁnden Sie im Anhang in den Abbildungen 3 bis 5. */
    void visualize(DiGraph &graph) {
        cout << "digraph {" << endl;    // Start
        cout << "\tnode [shape = circle];" << endl;   // Set shape of node to circle

        // print all
        for (Node * node : graph.getnodes())
            for (Edge * edge : node->getEdges()) {
                cout << "\t\"" << edge->getStartNode()->getKey() << "\"\t";

                if (edge->getStartNode()->getKey().size() + 2 <= 7) // If text to small, add tab
                    cout << "\t";

                cout << "->\t\"" << edge->getEndNode()->getKey() << "\"\t";

                if (edge->getEndNode()->getKey().size() + 2 <= 7)   // If text to small, add tab
                    cout << "\t";

                cout << "[label=" << edge->getWeight() << "];" << endl;
            }
        cout << "}" << endl;    // End
    }
};

#endif //OOA_PRAKTIKUM_3_DOTGRAPHVISUALIZER_HPP
