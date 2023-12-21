/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, 
vertex u comes before v in the ordering.

Note: Topological Sorting for a graph is not possible if the graph is not a DAG.

Applications of Topological Sorting:
- Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. 

- In computer science, applications of this type arise in:
1. Instruction scheduling
2. Ordering of formula cell evaluation when recomputing formula values in spreadsheets
3. Logic synthesis
4. Determining the order of compilation tasks to perform in make files
5. Data serialization
6. Resolving symbol dependencies in linkers
*/

#include<bits/stdc++.h>

using namespace std;

void createAdListDirected(map<int, vector<int>> &adjacencyList, int nodes, int edges){
    for(int i=0; i<edges; i++){
        cout << "Enter Nodes between edge: ";
        int node1, node2;
        cin >> node1 >> node2;
        adjacencyList[node1].push_back(node2);
        // adjacencyList[node2].push_back(node1);
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

void dfs(int i, unordered_map<int, bool> &visited, stack<int> &s, map<int, vector<int>> adjacencyList){
    visited[i] = true;
    for(auto neighbour: adjacencyList[i]){
        if(!visited[neighbour]) {
            dfs(neighbour, visited, s, adjacencyList);
        }
    }
    s.push(i);
}

vector<int> topologicalSortDFS(int nodes, map<int, vector<int>> adjacencyList){
    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            dfs(i, visited, s, adjacencyList);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

vector<int> topologicalSortKahn(int nodes, map<int, vector<int>> adjacencyList){
    vector<int> indegree(nodes);
    for(auto i: adjacencyList){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    // push 0 indegree to queue
    queue<int> q;
    for(int i=0; i<nodes; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        // neighbour indegree update
        for(auto neighour: adjacencyList[front]){
            indegree[neighour]--;
            if(indegree[neighour] == 0){
                q.push(neighour);
            }
        }
    }

    return ans;
}

int main(){
    int nodes, edges;
    cout << "Enter Number of Nodes: ";
    cin >> nodes;
    cout << "Enter Number of Edges: ";
    cin >> edges;

    // Directed adjancency list
    map<int, vector<int>> adjacencyList;
    createAdListDirected(adjacencyList, nodes, edges);
    printAdList(adjacencyList);

    // Topological Sort using DFS
    vector<int> ans1 = topologicalSortDFS(nodes, adjacencyList);
    cout << "Topological Sort using DFS: ";
    for(auto i: ans1){
        cout << i << " ";
    }
    cout << "\n";

    // Topological Sort Using Kahn's Algorithm (BFS)
    vector<int> ans = topologicalSortKahn(nodes, adjacencyList);
    cout << "Topological Sort using Kahn's: ";
    for(auto i: ans){
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}