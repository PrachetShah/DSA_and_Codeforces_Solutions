#include<bits/stdc++.h>

using namespace std;

bool DFS(int src, int parent, map<int, vector<int>> &adList, vector<int> &visited){
    visited[src] = 1;
    for(auto nbr: adList[src]){
        if(visited[nbr] && nbr != parent){
            return true;
        }else if(!visited[nbr]){
            if(DFS(nbr, src, adList, visited)){
                return true;
            }
        }
    }
    return false;
}

bool isCyclicBfs(int V, map<int, vector<int>> adList){
    vector<int> visited(V, 0);
    for(int i=0; i<V; i++){
       if(!visited[i]){
            bool ans = DFS(i, -1, adList, visited);
            if(ans){
            return true;
        }
       }
    }
    return false;
}

int main(){
    map<int, vector<int>> adList = {
        {0, {1, 2}},
        {1, {0, 3}},
        {2, {0, 1}},
        {3, {1}}
    };
    bool result = isCyclicBfs(4, adList);
    cout << (result ? "Cycle detected" : "No cycle") << endl;
    return 0;
}