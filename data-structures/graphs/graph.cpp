#include<bits/stdc++.h>

using namespace std;

void createAdMatrix(vector<vector<int>> &adjacencyMatrix, int nodes){
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(i==j)
                continue;
            cout << "Enter Edge for " << i << "->" << j << ": ";
            cin >> adjacencyMatrix[i][j];
        }
    }
}

void printAdMatrix(vector<vector<int>> adjacencyMatrix){
    for(int i=0; i<adjacencyMatrix.size(); i++){
        for(int j=0; j<adjacencyMatrix.size(); j++){
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

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

void BFS(map<int, vector<int>> AdList, int startNode){
    map<int, bool> visited;
    queue<int> q;

    q.push(startNode);
    visited[startNode] = 1;

    cout << "BFS Traversal of Graph: ";

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto s: AdList[node]){
            if(!visited[s])
                q.push(s);  
                visited[s] = 1;
        }
    }
    cout << "\n";
    return;
}

void DFS(map<int, vector<int>> adList, int startNode){
    map<int, bool> visited;
    stack<int> s;
    s.push(startNode);
    visited[startNode] = 1;

    cout << "DFS Traversal of Graph: ";
    while(!s.empty()){
        int node = s.top();
        s.pop();
        cout << node << " ";
        
        for(auto vertice: adList[node]){
            if(!visited[vertice]){
                s.push(vertice);
                visited[vertice] = 1;
            }
        }

    }
    cout << "\n";
}

int main(){
    int nodes, edges;
    cout << "Enter Nodes of Graph: ";
    cin >> nodes;
    cout << "Enter Nodes of Edges: ";
    cin >> edges;

    // adjacency matrix
    vector<vector<int>> adjacencyMatrix (nodes, vector<int> (nodes, 0));
    // createAdMatrix(adjacencyMatrix, nodes);
    // printAdMatrix(adjacencyMatrix);

    // adjancency list
    map<int, vector<int>> adjacencyList;
    createAdList(adjacencyList, nodes, edges);
    printAdList(adjacencyList);

    // BFS Traversal of Graph
    BFS(adjacencyList, 0);
    
    // DFS Traversal of Graph
    DFS(adjacencyList, 0);
    return 0;
}