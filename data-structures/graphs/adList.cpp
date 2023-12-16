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