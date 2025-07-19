#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool possible(int c, int node, unordered_map<int, vector<int>> adList, vector<int> color){
        for(auto nbr: adList[node]){
            if(color[nbr] == c){
                return false;
            }
        }
        return true;
    }
    bool f(int node, unordered_map<int, vector<int>> &adList, vector<int> &color, 
    int m, int V){
        if(node == V){
            return true;
        }
        for(int c=1; c<=m; c++){
            if(possible(c, node, adList, color)){
                color[node] = c;
                if(f(node+1, adList, color, m, V)){
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        unordered_map<int, vector<int>> adList;
        for(auto val: edges){
            adList[val[0]].push_back(val[1]);
            adList[val[1]].push_back(val[0]);
        }
        vector<int> color(v, 0);
        int node = 0;
        return f(node, adList, color, m, v);
    }
};