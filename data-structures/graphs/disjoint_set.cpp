/*
Disjoint Set is a Data Structure which can be used to implement Kruskal's Algorithm
It uses 2 things:
1. Parent Set
2. Union By Rank Method and Path Compression

First find parent of all nodes and declare rank for all nodes as 0

at each step for union(x,y)
find parent of x & y
find rank of parent[x] & parent[y]
if rankX == rankY:
    parent[Y] = x
    rank[x]++
if rank[X] < rank[Y]
    parent[x] = y
    attach all child nodes of X to y (path compression)
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
    unionSet(2,3, parent, rank);
    unionSet(4,5, parent, rank);
    unionSet(6,7, parent, rank);
    unionSet(5,6, parent, rank);
    unionSet(3,7, parent, rank);

    cout << "Parent Set: ";
    print(parent);

    cout << "Rank Set: ";
    print(rank);
    
    return 0;
}