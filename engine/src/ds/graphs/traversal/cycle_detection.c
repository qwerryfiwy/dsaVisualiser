#include "dsa/graphs.h"

// Helper for directed cycle
static bool isCyclicUtil(SimulationContext* ctx, Graph* g, int u, bool visited[], bool recStack[]) {
    if (!visited[u]) {
        visited[u] = true;
        recStack[u] = true;
        dsa_log_graph(ctx, OP_GRAPH_VISIT_NODE, u, 0, 0);

        for (int v = 0; v < g->num_nodes; v++) {
            if (g->matrix[u][v]) {
                if (!visited[v] && isCyclicUtil(ctx, g, v, visited, recStack))
                    return true;
                else if (recStack[v]) {
                    dsa_log_info(ctx, "Cycle Detected");
                    dsa_log_graph(ctx, OP_GRAPH_TRAVERSE_EDGE, u, v, 0); // Back edge
                    return true;
                }
            }
        }
    }
    recStack[u] = false; // Pop recursion stack
    return false;
}

bool dsa_graph_detect_cycle(SimulationContext* ctx, Graph* g) {
    bool visited[MAX_NODES] = {0};
    bool recStack[MAX_NODES] = {0};
    dsa_log_info(ctx, "Detecting Cycle");
    
    for (int i = 0; i < g->num_nodes; i++)
        if (isCyclicUtil(ctx, g, i, visited, recStack))
            return true;
    return false;
}
