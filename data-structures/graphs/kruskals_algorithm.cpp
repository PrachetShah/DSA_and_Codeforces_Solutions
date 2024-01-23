/*
Kruskal’s algorithm is used to find the MST of a given weighted graph. 

Algorithm:
1. Sort all the edges in non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it. 
3. Repeat step#2 until there are (V-1) edges in the spanning tree.

To check Cycle:
 Use Union Find Method
*/

#include<bits/stdc++.h>

using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n+1; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }
    // Path Compression
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){  
        parent[u] = v;
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

void print(vector<int> x){
    for(int i=0; i<x.size(); i++){
        cout << x[i] << " ";
    }
    cout << "\n";
}

int main(){
    int n=7;
    vector<int> parent(n+1, 0);
    vector<int> rank(n+1, 0);

    makeSet(parent, rank, n);
    // creating DS such as {{wt, u, v}, ...}
    vector<vector<int>> edgeList = {{2,1,2}, {1,1,4}, {4,1,5}, {9,4,5}, {5,4,3}, {3,2,4}, {3,2,3}, {7,2,6}, {8,3,6}};
    
    // Sorting it to start forming MST
    sort(edgeList.begin(), edgeList.end());

    int minWeight = 0;

    for(int i=0; i<edgeList.size(); i++){
        int u = findParent(parent, edgeList[i][1]);
        int v = findParent(parent, edgeList[i][2]);
        int w = edgeList[i][0];

        if(u != v){
            // union
            unionSet(u, v, parent, rank);
            minWeight += w;
        }
    }

    cout << "Minimum Weight of Spanning Tree: " << minWeight << endl;
    return 0;
}