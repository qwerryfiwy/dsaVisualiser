#ifndef DSA_CORE_TYPES_H
#define DSA_CORE_TYPES_H
#include <stdint.h>
#include <stddef.h>

// -- 1. OPCODES --
// The "Language" of visualization.
typedef enum {
    OP_NOOP = 0,

    // --- 1. ARRAYS & SORTING ---
    OP_ARR_HIGHLIGHT,       // Highlight index i (pivot, iterator)
    OP_ARR_COMPARE,         // Compare arr[i] vs arr[j]
    OP_ARR_SWAP,            // Swap values at arr[i] and arr[j]
    OP_ARR_WRITE,           // Set arr[i] = value
    OP_ARR_COPY,            // Copy range (MergeSort)

    // --- 2. LINKED LISTS ---
    OP_LIST_VISIT,          // Highlight node
    OP_LIST_NEXT,           // Animate pointer traversal ->
    OP_LIST_PREV,           // Animate pointer traversal <-
    OP_LIST_INSERT,         // Insert Node X after Y
    OP_LIST_DELETE,         // Unlink Node X
    OP_LIST_HEAD_UPDATE,    // Update Head pointer
    OP_LIST_TAIL_UPDATE,    // Update Tail pointer

    // --- 3. BINARY TREES (BST, AVL, RB) ---
    OP_TREE_VISIT,          // Traverse Node
    OP_TREE_COMPARE,        // Compare Node Key vs Search Key
    OP_TREE_LINK_LEFT,      // Set A.left = B
    OP_TREE_LINK_RIGHT,     // Set A.right = B
    OP_TREE_ROTATE_LEFT,    // AVL/RB Rotation
    OP_TREE_ROTATE_RIGHT,   // AVL/RB Rotation
    OP_TREE_SET_HEIGHT,     // Update AVL height
    OP_TREE_SET_COLOR,      // Update Red-Black color

    // --- 4. HEAPS & PRIORITY QUEUES ---
    OP_HEAP_SIFT_UP,        // Bubble value up
    OP_HEAP_SIFT_DOWN,      // Bubble value down
    OP_HEAP_EXTRACT_MIN,    // Remove root
    OP_HEAP_COMPARE_IDX,    // Compare heap array indices

    // --- 5. MULTI-WAY TREES (B-Trees, B+, Tries) ---
    OP_MTREE_SPLIT_NODE,    // B-Tree: Split full node
    OP_MTREE_MERGE_NODE,    // B-Tree: Merge underflow nodes
    OP_MTREE_PROMOTE_KEY,   // B-Tree: Move key up to parent
    OP_MTREE_SHIFT_KEYS,    // Shift keys in node to make space
    OP_TRIE_NEXT_CHAR,      // Traverse edge labeled 'c'

    // --- 6. GRAPH TRAVERSAL (BFS, DFS) ---
    OP_GRAPH_VISIT_NODE,    // Mark discovered
    OP_GRAPH_LEAVE_NODE,    // Mark finished (DFS black)
    OP_GRAPH_TRAVERSE_EDGE, // Animate movement A -> B
    
    // --- 7. PATHFINDING (Dijkstra, A*, Prim, Kruskal) ---
    OP_PATH_RELAX_EDGE,     // "Relaxing" edge (checking distance)
    OP_PATH_UPDATE_DIST,    // Found shorter path, update table
    OP_PATH_VISIT_SET,      // Add to "Visited/Closed" set
    OP_PATH_HEURISTIC,      // A* Heuristic calculation visual

    // --- 8. DISJOINT SET UNION (DSU) ---
    OP_DSU_MAKE_SET,        // Create new singleton
    OP_DSU_FIND,            // Recursive find step
    OP_DSU_PATH_COMPRESS,   // Point node directly to root
    OP_DSU_UNION,           // Link root A to root B

    // --- 9. BACKTRACKING & RECURSION (N-Queens, Sudoku) ---
    OP_BACKTRACK_TRY,       // Tentatively place value (Green?)
    OP_BACKTRACK_FAIL,      // Constraint check failed (Red flash)
    OP_BACKTRACK_UNDO,      // Revert state (remove Queen)
    OP_BACKTRACK_STACK_PUSH,// Visualize recursion stack depth
    OP_BACKTRACK_STACK_POP, // Return from recursion

    // --- 10. GRID / DP / MATRIX ---
    OP_GRID_UPDATE,         // Set Cell[r][c] = value
    OP_GRID_HIGHLIGHT,      // Highlight Cell[r][c]
    OP_GRID_ARROW,          // Draw dependency arrow (DP subproblems)

    // --- 11. MEMORY & META ---
    OP_ALLOC,               // Visual Malloc
    OP_FREE,                // Visual Free
    OP_MESSAGE,             // Log message
    OP_SNAPSHOT,            // Checkpoint
    OP_ERROR
} OpCode;

// -- 2. EVENT PAYLOAD --
// Universal container for data.
// We map pointers to 'u64_id' and grid coords to r/c.
typedef union {
    // ARRAYS: 1D indices
    struct {
        int32_t idx_a;
        int32_t idx_b;
        int32_t value;         // Value involved
    } array; 

    // GRIDS/MATRICES: 2D coordinates (DP, Backtracking)
    struct {
        int32_t row;
        int32_t col;
        int32_t value;
        int32_t old_value;     // Useful for "Undo" animations
    } grid;

    // NODES: Pointer IDs (Lists, Trees, Graphs)
    struct {
        uint64_t node_a;       // Source / Parent
        uint64_t node_b;       // Target / Child
        int32_t weight;        // Edge weight or Key value
        int32_t metadata;      // Height, Color, Balance, Rank
    } graph;

    // B-TREES / MULTI-WAY: Specifics for complex nodes
    struct {
        uint64_t node_id;
        int32_t key_index;     // Index within the B-Tree node
        int32_t value;
    } mtree;

    // PATHFINDING: Distance tracking
    struct {
        uint64_t node_id;
        double distance;       // Current shortest dist
        double heuristic;      // A* h-score
    } path;

    // TEXT: Logging
    struct {
        char text[64];
    } info;

    // ALLOC: Memory tracking
    struct {
        uint64_t ptr_id;
        int32_t size;
        int32_t type_id;       // 0=Node, 1=Array, 2=Edge
    } alloc;

} EventPayload;

// -- 3. THE EVENT --
typedef struct {
    uint32_t step_id;   
    OpCode op;          
    EventPayload data;  
} SimulationEvent;

// -- 4. CONTEXT --
typedef struct {
    SimulationEvent* event_buffer;
    size_t capacity;
    size_t count;
    int detailed_mode; 
} SimulationContext;

#endif // DSA_CORE_TYPES_H