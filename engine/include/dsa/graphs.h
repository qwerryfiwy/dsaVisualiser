#ifndef DSA_GRAPHS_H
#define DSA_GRAPHS_H

#include "core_types.h"
#include "logger.h"
#include <stdbool.h>

#define MAX_NODES 32
#define INF 999999

// Simple Adjacency Matrix Graph for Visualization MVP
typedef struct {
    int num_nodes;
    bool is_directed;
    int matrix[MAX_NODES][MAX_NODES]; 
    // matrix[u][v] = weight (0 or INF if no edge)
} Graph;

// --- CORE ---
Graph* dsa_graph_create(SimulationContext* ctx, int nodes, bool directed);
void dsa_graph_add_edge(SimulationContext* ctx, Graph* g, int u, int v, int w);

// --- TRAVERSAL ---
void dsa_graph_bfs(SimulationContext* ctx, Graph* g, int start_node);
void dsa_graph_dfs(SimulationContext* ctx, Graph* g, int start_node);
bool dsa_graph_detect_cycle(SimulationContext* ctx, Graph* g);
void dsa_graph_topological_sort(SimulationContext* ctx, Graph* g);

// --- SHORTEST PATH ---
void dsa_graph_dijkstra(SimulationContext* ctx, Graph* g, int start_node);
void dsa_graph_bellman_ford(SimulationContext* ctx, Graph* g, int start_node);
void dsa_graph_floyd_warshall(SimulationContext* ctx, Graph* g);

// --- MST ---
void dsa_graph_prim(SimulationContext* ctx, Graph* g);
void dsa_graph_kruskal(SimulationContext* ctx, Graph* g);

#endif // DSA_GRAPHS_H
