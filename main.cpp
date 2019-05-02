#include <string>
#include <iostream>

#include "node.hpp"


using namespace std;


int main(int argc, char ** argv){

    Node *p;
    Node *q;

    p = new Node ("Jupp");
    q = new Node ("Sepp");

    Edge e(p,q,42.0);


}
