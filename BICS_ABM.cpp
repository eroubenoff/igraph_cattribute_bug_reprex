#include<igraph.h>
#include<vector>
#include<string>
#include<iostream>
#include "BICS_ABM.h"
using namespace std;

void test_routine(igraph_t* graph) {

    igraph_vector_t temp_v;
    igraph_vector_init(&temp_v, igraph_ecount(graph));
    SETEANV(graph, "type", &temp_v);
    SETEANV(graph, "duration", &temp_v);

    igraph_vector_int_t edges_to_delete;
    igraph_vector_int_init(&edges_to_delete, 10);
    for (int i = 0; i < 10; i++) {
        VECTOR(edges_to_delete)[i] = i * 10;
    }
    igraph_delete_edges(graph, igraph_ess_vector(&edges_to_delete));
    igraph_vector_int_destroy(&edges_to_delete);

    /* Pull edge attribute vector */
    igraph_vector_resize(&temp_v, 0);
    EANV(graph, "type", &temp_v);
    cout << "Number of edges in graph: " << igraph_ecount(graph) << "; Number of items in attribute vector: " << igraph_vector_size(&temp_v) << endl;
    igraph_vector_destroy(&temp_v);

}



