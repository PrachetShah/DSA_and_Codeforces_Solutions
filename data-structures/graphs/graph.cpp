#include<bits/stdc++.h>

using namespace std;

void printAdMatrix(vector<vector<int>> adjacencyMatrix){
    for(int i=0; i<adjacencyMatrix.size(); i++){
        for(int j=0; j<adjacencyMatrix.size(); j++){
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void createAdList(map<int, vector<int>> &adjacencyList, int nodes){
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(i==j)
                continue;
            cout << "Edge " << i << "->" << j << "?";
            int val;
            cin >> val;
            if(val) adjacencyList[i].push_back(j);
        }
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

int main(){
    int nodes;
    cout << "Enter Nodes of Graph: ";
    cin >> nodes;

    // adjacency matrix
    vector<vector<int>> adjacencyMatrix (nodes, vector<int> (nodes, 0));

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(i==j)
                continue;
            cout << "Enter Edge for " << i << "->" << j << ": ";
            cin >> adjacencyMatrix[i][j];
        }
    }
    printAdMatrix(adjacencyMatrix);

    // adjancency list
    map<int, vector<int>> adjacencyList;
    createAdList(adjacencyList, nodes);
    printAdList(adjacencyList);
    return 0;
}