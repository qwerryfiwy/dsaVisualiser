#include "dsa/graphs.h"
#include <limits.h>

static int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void dsa_graph_prim(SimulationContext* ctx, Graph* g) {
    int parent[MAX_NODES]; 
    int key[MAX_NODES];   
    bool mstSet[MAX_NODES]; 

    dsa_log_info(ctx, "Starting Prim's MST");

    for (int i = 0; i < g->num_nodes; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }

    key[0] = 0;     
    parent[0] = -1; 

    for (int count = 0; count < g->num_nodes - 1; count++) {
        int u = minKey(key, mstSet, g->num_nodes);
        mstSet[u] = true;
        dsa_log_graph(ctx, OP_GRAPH_VISIT_NODE, u, 0, 0);

        for (int v = 0; v < g->num_nodes; v++) {
            if (g->matrix[u][v] && mstSet[v] == false && g->matrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->matrix[u][v];
                dsa_log_graph(ctx, OP_GRAPH_TRAVERSE_EDGE, u, v, key[v]); // Candidate edge
            }
        }
    }
}
