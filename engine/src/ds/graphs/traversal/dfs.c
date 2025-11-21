#include "dsa/graphs.h"

static void dfs_recursive(SimulationContext* ctx, Graph* g, int u, bool visited[]) {
    visited[u] = true;
    dsa_log_graph(ctx, OP_GRAPH_VISIT_NODE, u, 0, 0);
    
    for (int v = 0; v < g->num_nodes; v++) {
        if (g->matrix[u][v] != 0 && !visited[v]) {
            dsa_log_graph(ctx, OP_GRAPH_TRAVERSE_EDGE, u, v, 0);
            dfs_recursive(ctx, g, v, visited);
        }
    }
}

void dsa_graph_dfs(SimulationContext* ctx, Graph* g, int start) {
    bool visited[MAX_NODES] = {0};
    dsa_log_info(ctx, "Starting DFS");
    dfs_recursive(ctx, g, start, visited);
}
