// Network Delay problem using Djisktras algorithm with Min Heap
#include<bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

class Solution {
public:
    // Bellman Ford Algorithm -> TC: O(VE) Good for neg weights, but Djikstras is more optimal
    int networkDelayBellmanFord(vector<vector<int>>& times, int n, int k){
       vector<int> dist(n+1, INT_MAX);
       dist[k] = 0;
       for(int i=0; i<n; i++){
            for(vector<int> e: times){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(dist[u]!=INT_MAX && dist[v] > dist[u]+w){
                    dist[v] = dist[u]+w;
                }
            }
       }
       int maxWait = 0;
       for(int i=1; i<=n; i++){
           maxWait = max(maxWait, dist[i]);
       }
       return maxWait == INT_MAX ? -1 : maxWait;
    }

    // Djisktra's Algorithm Approach -> TC: ((E+V)logV)
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // since nodes are from 1->n keep n+1 nodes
        vector<vector<pii>> adList(n+1);
        // min heap
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> distance(n+1, INT_MAX);

        for(auto it: times){
            adList[it[0]].push_back({it[1], it[2]});
        }

        pq.push({0, k});
        distance[k] = 0;

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adList[node]){
                if(distance[it.first] > dis+it.second){
                    pq.push({dis+it.second, it.first});
                    distance[it.first] = dis + it.second;
                }
            }
        }

        int ans = 0;
        for(int i=1; i<=n ;i++){
            if(distance[i]==INT_MAX) return -1;
            ans = max(ans, distance[i]);
        }
        return ans;
    }
};

int main(){
    return 0;
}