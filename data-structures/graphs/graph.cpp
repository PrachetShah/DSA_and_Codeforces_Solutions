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

bool DFS(int src, int parent, map<int, bool> &visited, map<int, vector<int>> adj){
    visited[src] = true;
    for(auto nbr: adj[src]){
        if(!visited[nbr]){
            DFS(nbr, src, visited, adj);
        }else if(parent != nbr){
            return true;
        }
    }
    return false;
}

void isCyclicDFS(int nodes, map<int, vector<int>> adj){
    map<int, bool> visited;
    int parent = -1;
    int src = 0;
    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            if(DFS(i, -1, visited, adj)){
                cout << "Cycle Found in Graph via DFS" << endl;
                return;
            }
        }
    }
    cout << "Cycle Not Found in Graph via DFS" << endl;
    return;
}


bool isCyclicBFS(int src, unordered_map<int, bool> &visited, map<int, vector<int>> adj){
    unordered_map<int, int> parent;
    visited[src] = 1;
    parent[src] = -1;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neighbour: adj[node]){
            if(visited[neighbour] && neighbour!=parent[node]){
                return true;
            }else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = node;
            }
        }
    }
    return false;
}

void cycleDetectBFS(int nodes, map<int, vector<int>> adj){
    // Handling Disconnected Nodes
    unordered_map<int, bool> visited;
    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans){
                cout << "Cycle Exists in Graph via BFS\n";
                return;
            }
        }
    }
    cout << "Cyle Does not Exist in Graph via BFS\n";
}

int main(){
    int nodes, edges;
    cout << "Enter Number of Nodes: ";
    cin >> nodes;
    cout << "Enter Number of Edges: ";
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
    
    
    // cout << "Cycle Detection DFS Traversal of Graph Recursive" << endl;
    isCyclicDFS(nodes, adjacencyList);

    // Cycle Detection in Undirected Graph using BFS, in DFS, just replace queue with stack and its done
    // FOR UNDIRECTED GRAPHS
    cycleDetectBFS(nodes, adjacencyList);
    return 0;
}