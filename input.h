//
// Created by jimmy on 20.05.19.
//

#ifndef P3_INPUT_H
#define P3_INPUT_H

//
// Created by jimmy on 20.05.19.
//
// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include "DiGraph.h"

using namespace std;

void input() {
    ifstream ifs("eingabe.txt");
    DiGraph graph;
    if (!ifs.eof()) {  //solange der inputstream nicht (e)nd (o)f (f)ile
        string data;
        while (getline(ifs, data)) { //check die linie mit dem string vom inputfilestream
            if (data[0] == '*') { //Wenn anfanng der zeile == * dann..
                cout << "Knoten" << endl;//debug
                int index;
                index = data.find('*'); //wenn aus irgendeinem grund der index ==-1 ist dann abbrechen
                if (index == -1)
                    throw "error";
                string name = data.substr(1); //Nimm den rest der line und pack ihn in nen string
                graph.addNode(name);          //in graph

            } else if (data[0] == '#') {    // wenn anfang der zeile == #

                cout << "kante" << endl;
                int index3, index4;
                index3 = data.find(';');   // indices zum aufteilen einrichten
                index4 = data.find(';', index3 + 1);//vierter index von index3+1 da hier getrennt wird
                string key1 = data.substr(1, index3 - 1); //substring von position 2 also nach dem # bis eins vor dem ;
                string key2 = data.substr(index3 + 1, index4 - (index3 + 1)); //von index 3 +1 bis index4-i3+1
                string weightStr = data.substr(index4 + 1);//weight bis ende
                float weight = stof(weightStr);//cast to float
                graph.addEdge(key1, key2, weight);
                //find aus stl benutzen find(vector.begin, vector.end)
            }


        }

    }
    DotGraphVisualizer dgv;
    dgv.visualize(graph);

}


#endif //P3_INPUT_H
