#include "dsa/graphs.h"
#include <stdlib.h>

Graph* dsa_graph_create(SimulationContext* ctx, int nodes, bool directed) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->num_nodes = nodes;
    g->is_directed = directed;
    
    dsa_log_info(ctx, "Creating Graph (Adj Matrix)");
    
    for(int i=0; i<nodes; i++) {
        for(int j=0; j<nodes; j++) {
            g->matrix[i][j] = 0; // 0 represents no edge here
        }
        dsa_log_graph(ctx, OP_ALLOC, i, 0, 0); // Visualize Node creation
    }
    return g;
}

void dsa_graph_add_edge(SimulationContext* ctx, Graph* g, int u, int v, int w) {
    if (u >= g->num_nodes || v >= g->num_nodes) return;
    
    g->matrix[u][v] = w;
    dsa_log_graph(ctx, OP_GRAPH_TRAVERSE_EDGE, u, v, w); // Visual: Create Edge
    
    if (!g->is_directed) {
        g->matrix[v][u] = w;
    }
}
