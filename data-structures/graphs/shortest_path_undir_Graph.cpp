/*
Shortest path in undirected graph

DIFF With Djikstras: 

The approach you've implemented using Breadth-First Search (BFS) is a simple algorithm to find the shortest path in an unweighted graph.
It explores the graph layer by layer, starting from the source node, and marks the distance to each node from the source. The parent 
array is then used to reconstruct the path from the destination back to the source.

Dijkstra's algorithm, on the other hand, is designed for finding the shortest path in a weighted graph. It takes into account the 
weights of the edges between nodes and uses a priority queue (min-heap) to always explore the node with the minimum known distance 
first. Dijkstra's algorithm guarantees the correctness of the shortest path because it always selects the node with the minimum 
distance at each step.
*/
#include<bits/stdc++.h>

using namespace std;

void createAdList(map<int, vector<int>> &adjacencyList, int nodes, int edges){
    for(int i=0; i<edges; i++){
        cout << "Enter Nodes between edge: ";
        int node1, node2;
        cin >> node1 >> node2;
        adjacencyList[node1].push_back(node2);
        adjacencyList[node2].push_back(node1);
    }
}

void printAdList(map<int, vector<int>> adjacencyList){
    for(auto s: adjacencyList){
        cout << s.first << ": ";
        for(int i=0; i<s.second.size(); i++){
            cout << s.second[i] << " ";
        }
        cout << "\n";
    }
}


void shortestPath(int nodes, map<int, vector<int>> adjacencyList, int destination){
    /* 
    1. find parents of all nodes using BFS
    2. Find by backtracking from destination to source based on parent list
    3. Reverse the answer as Dest->Sour ==> Dour->Dest
    */

    // Applying BFS
    vector<bool> visited(nodes, false);
    vector<int> parent(nodes, 0);
    parent[0] = -1;
    visited[0] = true;
    
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto neigh: adjacencyList[front]){
            if(!visited[neigh]){
                q.push(neigh);
                parent[neigh] = front;
                visited[neigh] = true;
            }
        }
    }

    // print parent
    cout << "Parent Vector: ";
    for(auto i: parent){
        cout << i << " ";
    }
    cout << "\n";

    // find inverse of route by going dest->source
    string path;
    int i = parent.size()-1;
    while(i != -1){
        path += to_string(i) + " ";
        i = parent[i];
    }
    reverse(path.begin(), path.end());
    cout << "Path: " << path;
}

int main(){
    int nodes, edges;
    cout << "Enter Number of Nodes: ";
    cin >> nodes;
    cout << "Enter Number of Edges: ";
    cin >> edges;

    // adjancency list
    map<int, vector<int>> adjacencyList;
    createAdList(adjacencyList, nodes, edges);
    printAdList(adjacencyList);

    shortestPath(nodes, adjacencyList, 7);
}