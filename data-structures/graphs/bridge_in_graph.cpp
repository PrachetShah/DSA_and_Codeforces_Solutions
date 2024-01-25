/*
Required 4 DS:
1. Discovery
2. Lowest Poss
3. Parent
4. Visited
*/

#include<bits/stdc++.h>

using namespace std;

void printAdList(unordered_map<int, vector<pair<int, int>>> adjacencyList){
    for(auto s: adjacencyList){
        cout << s.first << ": ";
        for(int i=0; i<s.second.size(); i++){
            cout << "{" << s.second[i].first << "," << s.second[i].second << "}" << " ";
        }
        cout << "\n";
    }
}

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, 
    vector<vector<int>> &result, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> adjacencyList){
        visited[node] = true;
        disc[node] = low[node] = timer++;

        for(auto nbr: adjacencyList[node]){
            if(nbr == parent){
                continue;
            }
            if(!visited[nbr]){
                dfs(nbr, node, timer, disc, low, result, visited, adjacencyList);
                low[node] = min(low[node], low[nbr]);
                // check edge is bridge
                if(low[nbr] > disc[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }else{
                // back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e){
    // adj list
    unordered_map<int, vector<int>> adjacencyList;
    for(int i=0; i<edges.size(); i++){
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        adjacencyList[node1].push_back(node2);
        adjacencyList[node2].push_back(node1);
    }

    int timer = 0;
    int parent = -1;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> visited;
    vector<vector<int>> result;

    // dfs
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, parent, timer, disc, low, result, visited, adjacencyList);
        }
    }

    return result;
}

int main(){
    int v = 6;
    int e = 7;
    vector<vector<int>> edges = {{1,2}, {1, 0}, {2, 0}, {0, 4}, {4,5}, {4,3}, {3, 5}};
    vector<vector<int>> result = findBridges(edges, v, e);

    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[0].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}