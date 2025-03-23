#include<bits/stdc++.h>

using namespace std;

/*
This is a combination problem of Djikstra's + 1D DP
*/

using pll = pair<unsigned long long, long long>;
using ll = unsigned long long;
const int MOD = 1e9+7;

// TC: O(ElovV), SC: O(V+E)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // adj list
        vector<vector<pair<int, int>>> adj(n);
        for(auto road: roads){
            int u = road[0];
            int v = road[1];
            ll d = road[2];
            adj[u].push_back({d, v});
            adj[v].push_back({d, u});
        }
        
        // minHeap
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        // USING LLONG_MAX is imp here, else edge cases will fail
        vector<ll> shortestTime(n, LLONG_MAX);
        vector<int> pathCount(n, 0);
        
        // currTime, start
        pq.push({0, 0});
        shortestTime[0] = 0;
        pathCount[0] = 1;

        while(!pq.empty()){
            auto node = pq.top();
            ll currTime = node.first;
            ll currNode = node.second;
            pq.pop();
            
            if(currTime > shortestTime[currNode]){
                continue;
            }
            for(auto neighbor: adj[currNode]){
                ll roadTime = neighbor.first;
                ll nbr = neighbor.second;
    
                if(roadTime + currTime < shortestTime[nbr]){
                    shortestTime[nbr] = roadTime+currTime;
                    pathCount[nbr] = pathCount[currNode];
                    pq.push({shortestTime[nbr], nbr});
                }else if(roadTime + currTime == shortestTime[nbr]){
                    pathCount[nbr] += pathCount[currNode];
                    pathCount[nbr] %= MOD;
                }
            }
        }

        return pathCount[n-1];
    }
};