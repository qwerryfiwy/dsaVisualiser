#include "dsa/graphs.h"
#include <limits.h>

// Finds min distance vertex from set of vertices not yet processed
static int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void dsa_graph_dijkstra(SimulationContext* ctx, Graph* g, int src) {
    int dist[MAX_NODES]; 
    bool sptSet[MAX_NODES]; // Shortest Path Tree Set

    dsa_log_info(ctx, "Starting Dijkstra");

    for (int i = 0; i < g->num_nodes; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        dsa_log_path(ctx, OP_PATH_UPDATE_DIST, i, -1.0, 0); // Init to INF
    }

    dist[src] = 0;
    dsa_log_path(ctx, OP_PATH_UPDATE_DIST, src, 0.0, 0);

    for (int count = 0; count < g->num_nodes - 1; count++) {
        int u = minDistance(dist, sptSet, g->num_nodes);
        if (u == -1) break;

        sptSet[u] = true;
        dsa_log_graph(ctx, OP_GRAPH_VISIT_NODE, u, 0, 0); // Mark as finalized

        for (int v = 0; v < g->num_nodes; v++) {
            if (!sptSet[v] && g->matrix[u][v] && dist[u] != INT_MAX 
                && dist[u] + g->matrix[u][v] < dist[v]) {
                
                dsa_log_path(ctx, OP_PATH_RELAX_EDGE, v, 0, 0); // Visual: Check edge
                
                dist[v] = dist[u] + g->matrix[u][v];
                dsa_log_path(ctx, OP_PATH_UPDATE_DIST, v, (double)dist[v], 0);
            }
        }
    }
}
