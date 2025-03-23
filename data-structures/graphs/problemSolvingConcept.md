What I've learned after solving LeetCode graph problems so far:

- Start by trying `BFS` or `DFS` for traversal, reachability, and basic graph exploration.

- Then consider `Union-Find` (Disjoint Set Union), especially for cycle detection or connected components in undirected graphs.

- If the graph is directed, think about `Kahn’s algorithm` (Topological Sort) for ordering tasks or detecting cycles.

- For pathfinding problems:

```
    Use `Dijkstra’s` algorithm for shortest paths with positive weights.

    Use `Floyd-Warshall` for all-pairs shortest paths (good for smaller graphs).

    Use `Bellman-Ford` if negative weights or negative cycles are involved.
```

- If none of these approaches work, consider `DP with graphs`, especially in `DAGs using topological order`.

NOTE : Be careful with integer overflow—graph problems often reach `INT_MAX`, so use `LLONG_MAX` when your logic seems right but the output is incorrect.
