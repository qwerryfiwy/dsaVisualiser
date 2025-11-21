#include "dsa/graphs.h"
#include <stdlib.h>

void dsa_graph_bfs(SimulationContext* ctx, Graph* g, int start) {
    bool visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    dsa_log_info(ctx, "Starting BFS");

    // Enqueue Start
    visited[start] = true;
    queue[rear++] = start;
    dsa_log_graph(ctx, OP_GRAPH_VISIT_NODE, start, 0, 0);

    while (front < rear) {
        int u = queue[front++];
        
        // Check neighbors
        for (int v = 0; v < g->num_nodes; v++) {
            if (g->matrix[u][v] != 0 && !visited[v]) {
                dsa_log_graph(ctx, OP_GRAPH_TRAVERSE_EDGE, u, v, 0); // Show edge travel
                visited[v] = true;
                queue[rear++] = v;
                dsa_log_graph(ctx, OP_GRAPH_VISIT_NODE, v, 0, 0); // Mark visited
            }
        }
    }
}
