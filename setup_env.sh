#!/bin/bash

echo "🚀 Initializing THE DEFINITIVE DSA Platform Structure..."

# --- ARRAYS ---
mkdir -p engine/src/ds/arrays/core
mkdir -p engine/src/ds/arrays/searching
mkdir -p engine/src/ds/arrays/sorting
mkdir -p engine/src/ds/arrays/problems

touch engine/src/ds/arrays/core/{creation.c,insertion.c,deletion.c,update_access.c,resize.c,reverse.c,rotate.c}
touch engine/src/ds/arrays/searching/{linear_search.c,binary_search.c,jump_search.c,exponential_search.c,ternary_search.c,interpolation_search.c}
touch engine/src/ds/arrays/sorting/{bubble_sort.c,selection_sort.c,insertion_sort.c,merge_sort.c,quick_sort.c,heap_sort.c,shell_sort.c,counting_sort.c,radix_sort.c,bucket_sort.c,timsort.c}
touch engine/src/ds/arrays/problems/{two_pointers.c,sliding_window.c,kadane.c,prefix_sum.c,difference_array.c,binary_search_variations.c,dutch_national_flag.c,histogram_rect.c,trapping_rainwater.c,stock_buy_sell.c,product_subarray.c,lis_binary_search.c}

# --- LINKED LISTS ---
mkdir -p engine/src/ds/lists/singly
mkdir -p engine/src/ds/lists/doubly
mkdir -p engine/src/ds/lists/circular

touch engine/src/ds/lists/singly/{insertion.c,deletion.c,search.c,reverse.c,middle_element.c,cycle_detect.c,merge_lists.c,intersection.c,palindrome.c,rotate_list.c,nth_node_end.c,add_numbers.c}
touch engine/src/ds/lists/doubly/{insertion.c,deletion.c,reverse.c,sorted_insert.c,union_intersection.c}
touch engine/src/ds/lists/circular/{insertion.c,deletion.c,split_halves.c}

# --- STACKS & QUEUES ---
mkdir -p engine/src/ds/stacks_queues/stacks
mkdir -p engine/src/ds/stacks_queues/queues

touch engine/src/ds/stacks_queues/stacks/{core_ops.c,infix_postfix.c,evaluate_postfix.c,balanced_parens.c,next_greater.c,stock_span.c,min_stack.c,histogram_area.c}
touch engine/src/ds/stacks_queues/queues/{core_ops.c,circular_queue.c,deque.c,sliding_window_max.c,rotten_oranges.c}

# --- TREES & HEAPS ---
mkdir -p engine/src/ds/trees/general
mkdir -p engine/src/ds/trees/binary
mkdir -p engine/src/ds/trees/bst
mkdir -p engine/src/ds/trees/avl
mkdir -p engine/src/ds/trees/heaps

touch engine/src/ds/trees/general/core.c
touch engine/src/ds/trees/binary/{core_ops.c,traversals.c,properties.c,views.c,boundary.c,zigzag.c,lca.c,mirror.c}
touch engine/src/ds/trees/bst/{core_ops.c,validate.c,kth_element.c,predecessor_successor.c,lca_bst.c}
touch engine/src/ds/trees/avl/{core.c,rotations.c,balance.c}
touch engine/src/ds/trees/heaps/{min_heap.c,max_heap.c,heapify.c,priority_queue.c,k_largest_smallest.c,median_stream.c,task_scheduler.c}

# --- HASHING ---
mkdir -p engine/src/ds/hashing/table
mkdir -p engine/src/ds/hashing/problems

touch engine/src/ds/hashing/table/{direct_address.c,chaining.c,open_addressing.c,rehashing.c}
touch engine/src/ds/hashing/problems/{two_sum.c,subarray_zero_sum.c,longest_consecutive.c}

# --- GRAPHS ---
mkdir -p engine/src/ds/graphs/core
mkdir -p engine/src/ds/graphs/traversal
mkdir -p engine/src/ds/graphs/shortest_path
mkdir -p engine/src/ds/graphs/mst
mkdir -p engine/src/ds/graphs/advanced

touch engine/src/ds/graphs/core/{adjacency_list.c,adjacency_matrix.c,union_find.c}
touch engine/src/ds/graphs/traversal/{bfs.c,dfs.c,connected_components.c,bipartite.c,topological_sort.c,cycle_detection.c}
touch engine/src/ds/graphs/shortest_path/{dijkstra.c,bellman_ford.c,floyd_warshall.c}
touch engine/src/ds/graphs/mst/{kruskal.c,prim.c}
touch engine/src/ds/graphs/advanced/{articulation_points.c,bridges.c,kosaraju_scc.c,tarjan_scc.c}

# --- DP ---
mkdir -p engine/src/ds/dp/classic
mkdir -p engine/src/ds/dp/grid

touch engine/src/ds/dp/classic/{fibonacci.c,climbing_stairs.c,knapsack_01.c,knapsack_unbounded.c,lcs.c,lis.c,edit_distance.c,matrix_chain_mult.c,coin_change.c,rod_cutting.c,partition_subset.c}
touch engine/src/ds/dp/grid/min_path_sum.c

# --- STRINGS ---
mkdir -p engine/src/ds/strings/matching
mkdir -p engine/src/ds/strings/ops
mkdir -p engine/src/ds/strings/trie

touch engine/src/ds/strings/matching/{kmp.c,rabin_karp.c,z_algorithm.c,lps_array.c}
touch engine/src/ds/strings/ops/{longest_palindrome.c,anagrams.c,sliding_window_str.c}
touch engine/src/ds/strings/trie/trie_core.c

# --- ADVANCED ---
mkdir -p engine/src/ds/advanced
touch engine/src/ds/advanced/{btree.c,red_black_tree.c,segment_tree.c,fenwick_tree.c,suffix_array.c,suffix_tree.c,lru_cache.c,sparse_table.c,hld.c}

echo "✅ DEFINITIVE DSA STRUCTURE CREATED."
