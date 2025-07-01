#include<bits/stdc++.h>

using namespace std;

bool BFS(int src, int V, map<int, vector<int>> &adList, vector<int> &visited){
    queue<int> q;
    q.push(src);
    vector<int> parent(V, 0);
    parent[src] = -1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = 1;

        for(int nbr: adList[node]){
            if(visited[nbr] && nbr != parent[node]){
                return true;
            }else if(!visited[nbr]){
                parent[nbr] = node;
                visited[nbr] = 1;
                q.push(nbr);
            }
        }
    }
    return false;
}

bool isCyclicBfs(int V, map<int, vector<int>> adList){
    vector<int> visited(V, 0);
    for(int i=0; i<V; i++){
        if(!visited[i]){
            bool ans = BFS(i, V, adList, visited);
            if(ans){
                return true;
            }
        }
    }
    return false;
}