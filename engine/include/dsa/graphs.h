#ifndef DSA_GRAPHS_H
#define DSA_GRAPHS_H
#include "core_types.h"
#include "logger.h"

// Basic Adjacency Matrix Graph
typedef struct {
    int num_nodes;
    bool is_directed;
    int matrix[20][20]; // Fixed size for MVP
} Graph;

void dsa_graph_bfs(SimulationContext* ctx, Graph* g, int start);
void dsa_graph_dfs(SimulationContext* ctx, Graph* g, int start);
void dsa_graph_dijkstra(SimulationContext* ctx, Graph* g, int start);
#endif
