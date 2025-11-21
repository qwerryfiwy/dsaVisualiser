#include "dsa/stacks_queues.h"

int dsa_queue_rotten_oranges(SimulationContext* ctx, int32_t* grid, int rows, int cols) {
    dsa_log_info(ctx, "Rotten Oranges BFS");
    // Requires Queue of coordinates.
    // 2 = Rotten, 1 = Fresh, 0 = Empty
    
    // Visual: Scan grid
    for(int i=0; i<rows*cols; i++) {
        if (grid[i] == 2) {
            dsa_log_grid(ctx, OP_GRID_HIGHLIGHT, i/cols, i%cols, 2, 0);
        }
    }
    return -1; // Stub return
}
