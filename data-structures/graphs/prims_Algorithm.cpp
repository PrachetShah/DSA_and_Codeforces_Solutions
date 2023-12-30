/*
Spanning Tree: https://www.geeksforgeeks.org/spanning-tree/
1. A Spanning tree does not exist for a disconnected graph.
2. For a connected graph having 'N' vertices then the number of edges in the spanning tree for that graph will be 'N-1'.
3. A Spanning tree does not have any cycle.

Minimum Spanning Tree(MST):
A minimum spanning tree (MST) is defined as a spanning tree that has the minimum weight among all the possible spanning trees.
To find MST, we can make use of Prim's or Kruskal's Algorithm.

Prim's Algorithm:
1. Create Key, Parent, MST/Visited Data Structure
2. Mark parent[src]=-1 and key[src]=0
3. Write a For Loop which runs for number of nodes
    i. Write for loop to Ffnd Mini Key Val node && MST[node]==false
    ii. MST[node] = true
    iii. For n: ADJACENT[node]
        1) if key[n] < n.weigth
            parent[n] = node
            key[n] = n.weigth
4. Print Parent Node which can be used to create the MST or return sum of MST

TC: O(n^2), O(n)
using MinHeap, we can find Min Ele in O(1)
which will make TC: O(n) and Sc: O(nlogn)
*/

#include<bits/stdc++.h>

using namespace std;

void createAdList(unordered_map<int, vector<pair<int, int>>> &adjacencyList, int edges){
    for(int i=0; i<edges; i++){
        cout << "Enter Nodes between edge: ";
        int node1, node2, weight;
        cin >> node1 >> node2;

        cout << "Enter Weight between nodes: ";
        cin >> weight;

        adjacencyList[node1].push_back({node2, weight});
        adjacencyList[node2].push_back({node1, weight});
    }
}

void createAdList(unordered_map<int, vector<pair<int, int>>> &adjacencyList, vector<vector<int>> edges){
    for(int i=0; i<edges.size(); i++){
        int node1 = edges[i][0];
        int node2 = edges[i][1], weight = edges[i][2];
        adjacencyList[node1].push_back({node2, weight});
        adjacencyList[node2].push_back({node1, weight});
    }
}

void printAdList(unordered_map<int, vector<pair<int, int>>> adjacencyList){
    for(auto s: adjacencyList){
        cout << s.first << ": ";
        for(int i=0; i<s.second.size(); i++){
            cout << "{" << s.second[i].first << "," << s.second[i].second << "}" << " ";
        }
        cout << "\n";
    }
}

void print(vector<int> arr){
    cout << "{ ";
    for(auto i: arr){
        cout << i << " ";
    }
    cout << "}\n";
}


int main(){
    int nodes, edges;
    cout << "Enter Number of Nodes: ";
    cin >> nodes;
    cout << "Enter Number of Edges: ";
    cin >> edges;

    // adjancency list
    unordered_map<int, vector<pair<int, int>>> adjacencyList;
    vector<vector<int>> edgeList = {{0,1,2}, {0,3,6}, {1,2,3}, {1,3,8}, {1,4,5}, {2,4,7}};
    // createAdList(adjacencyList, edges);
    createAdList(adjacencyList, edgeList);
    printAdList(adjacencyList);

    // Set up all the data structures
    vector<int> key(nodes, INT_MAX);
    vector<int> parent(nodes, -1);
    vector<bool> mst(nodes, false);
    int src = 0;

    // Step1: Mark src node key and mst as 0 and true
    key[src] = 0;
    parent[src] = -1;

    for(int i=0; i<nodes; i++){
        int mini = INT_MAX, mini_node=0;
        // step2: find minimum key from key array whose mst is not visited
        for(int j=0; j<nodes; j++){
            if(key[j] < mini && mst[j]==false){
                mini = key[j];
                mini_node = j;
            }
        }

        // step3: mark min dist node as true in MST
        mst[mini_node] = true;

        // step4: for all adjacent nodes, check if key smaller, if smaller update the key and update parents
        for(auto neighbour: adjacencyList[mini_node]){
            int node = neighbour.first, weight = neighbour.second;
            if(mst[node]==false && weight<key[node]){
                parent[node] = mini_node;
                key[node] = weight;
            }
        }
    }

    // step5: make answer from parent array
    vector<pair<pair<int, int>, int>> result;
    for(int i=1; i<nodes; i++){
        result.push_back({{parent[i], i}, key[i]});
    }

    cout << "Parent Array is: ";
    print(parent);

    cout << "Sum of MST: " << accumulate(key.begin(), key.end(), 0);

    return 0;
}