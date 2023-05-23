#include<igraph.h>
#include<iostream>
#include "BICS_ABM.h"

using namespace std;

#define MAXCHAR 1000



int main(int argc, char **argv) {

    igraph_t graph;
    igraph_set_attribute_table(&igraph_cattribute_table);
    igraph_full(&graph, 100, false, false);

    test_routine(&graph);
    cout << "Ran routine" << endl;

    DELALL(&graph);
    igraph_destroy(&graph);

    return 0;

}

