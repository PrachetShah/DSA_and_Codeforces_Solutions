#include<bits/stdc++.h>

using namespace std;

/*
In BFS,
we visit all nodes at K stop level, and keep track of minimum cost to the destination

In Bellman Ford -> we keep a temp array 
We are allowed only K+1 stops, meaning we need to track the shortest path considering at most K intermediate edges.
If we modify dist directly, an edge might get updated with a value derived from a path that has more than the allowed stops.

In Djikstras
In Dijkstra’s algorithm, we typically maintain a distance array to store the shortest known distance to each node, 
helping us avoid unnecessary exploration. However, in Cheapest Flights Within K Stops, we don’t use a distance array because:
-> Stops Restriction Matters More than Distance Alone: A node can be reached at a lower cost but with more stops. 
If we store only the minimum cost in a distance array and ignore the stop count, we might prematurely mark a node as "visited" 
and never revisit it.
*/
using vi = vector<int>;

int findCheapestPriceBFS( int n, vector<vector<int>>& flights, int src, int dst, int K ) { 
	// Create adjList
	unordered_map<int, vector< pair<int,int> > > adjList;
	for( auto flight : flights )
		adjList[flight[0]].push_back( { flight[1], flight[2] } );

	/* BFS starting from src */
	queue< pair<int,int> > q; // < node, dist_from_src > pair
	q.push( { src, 0 } );
	int srcToTgtDist = INT_MAX; // result

	while( !q.empty() && K-- >= 0 ) {
		int size = q.size();
		for( int i = 0; i < size; i++ ) {
			auto curr = q.front(); q.pop();
			for( auto nbr : adjList[curr.first] ) {
				if( srcToTgtDist < curr.second + nbr.second ) continue;

				q.push( { nbr.first, curr.second + nbr.second } );

				// update distance from src to dst
				if( dst == nbr.first ) 
					srcToTgtDist = min(srcToTgtDist, curr.second + nbr.second);
			}
		}
	}
	return srcToTgtDist == INT_MAX ? -1 : srcToTgtDist;
}


int findCheapestPriceBellmanFord(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // Bellman
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for(int i=0; i<=k; i++){
        vector<int> tmp(dist);
        for(auto fli: flights){
            int u = fli[0];
            int v = fli[1];
            int w = fli[2];
            if(dist[u] != INT_MAX){
                tmp[v] = min(tmp[v], dist[u]+w);
            }
        }
        dist = tmp;
    }
    return dist[dst]==INT_MAX ? -1 : dist[dst];
}


int findCheapestPriceDjikstra(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // create adjacency list
    unordered_map<int,vector<pair<int, int>>> adjList;
    for( auto f : flights )
        adjList[f[0]].push_back( { f[1], f[2] } );
    
    // minHeap based on cost of distance from source
    priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
    minHeap.push( { 0, src, 0 } ); // cost, vertex, hops
    
    vector<int> visited(n, INT_MAX);

    while( !minHeap.empty() ) {
        auto t = minHeap.top(); minHeap.pop();
        int cost = t[0];
        int curr = t[1];
        int stop = t[2];
        if( curr == dst )
            return cost;

        if (stop > k || visited[curr] <= stop) continue;
        
        visited[curr] = min(visited[curr], stop);
        
        for( auto nbr : adjList[curr] )
            minHeap.push( { cost+nbr.second, nbr.first, stop+1 } );
    }
    return -1;
}