/*
It can be used to find the Shorted Path in Directed/Unidrected Cyclic Weighted Graph with positive edges (DAG)
For edge with negative weight, we use Bellman Ford Algorithm

Before:
Adjancency List for Weighted Graph:
unordered_map<int, list<pair<int, int>>> adjList
Priority Queue/Set (since both stores smallest element first)

Algo:
1. Initialise INF Distance array
2. Start with Source node and add {dis, src} in Priority Queue/Set

** WE USE PQ here because we need node whose distance is currently the least to travel all the nodes from **

3. While PQ is not empty, keep updating the distance array

Time Complexity: O(ElogV)
Space Complexity: O(N)

Applications of Dijkstra’s Algorithm:
1. Google maps uses Dijkstra algorithm to show shortest distance between source and destination.
2. In computer networking, Dijkstra’s algorithm forms the basis for various routing protocols, such as OSPF (Open Shortest Path First) 
    and IS-IS (Intermediate System to Intermediate System).
3. Transportation and traffic management systems use Dijkstra’s algorithm to optimize traffic flow, minimize congestion, and 
    plan the most efficient routes for vehicles.
4. Airlines use Dijkstra’s algorithm to plan flight paths that minimize fuel consumption, reduce travel time.
5. Dijkstra’s algorithm is applied in electronic design automation for routing connections on integrated circuits and very-large-scale 
    integration (VLSI) chips.
*/

#include<bits/stdc++.h>

using namespace std;

void createAdList(unordered_map<int, vector<pair<int, int>>> &adjacencyList, int edges){
    for(int i=0; i<edges; i++){
        cout << "Enter Nodes between edge: ";
        int node1, node2, dis;
        cin >> node1 >> node2;

        cout << "Enter Distance between nodes: ";
        cin >> dis;

        adjacencyList[node1].push_back({node2, dis});
        adjacencyList[node2].push_back({node1, dis});
    }
}

void createAdList(unordered_map<int, vector<pair<int, int>>> &adjacencyList, vector<vector<int>> edges){
    for(int i=0; i<edges.size(); i++){
        int node1 = edges[i][0];
        int node2 = edges[i][1], dis = edges[i][2];
        adjacencyList[node1].push_back({node2, dis});
        adjacencyList[node2].push_back({node1, dis});
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
        if(i==INT_MAX){
            cout << "INF" << " ";
        }else{
            cout << i << " ";
        }
    }
    cout << "}\n";
}

void dijsktraPQ(unordered_map<int, vector<pair<int, int>>> adjacencyList, vector<int> &distance, int src, int nodes){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    distance[src] = 0;

    while(!pq.empty()){
        auto val = pq.top();
        int node = val.second, dis = val.first;
        pq.pop();

        for(auto neighbour: adjacencyList[node]){
            if(dis+neighbour.second < distance[neighbour.first]){
                // no need to delete the record here since PQ automatically puts lowest one first when pushed 
                // unlike set which wont change order for new entry of same distance. 
                // For Eg: if (9, 4) exists in set and new is pushed for (5, 4)
                distance[neighbour.first] = dis+neighbour.second;
                pq.push({distance[neighbour.first], neighbour.first});
            }
        }
    }
}

void dijsktraSet(unordered_map<int, vector<pair<int, int>>> adjacencyList, vector<int> &distance, int src, int nodes){
    set<pair<int, int>> s;
    s.insert({0, src});
    distance[src] = 0;

    while(!s.empty()){
        auto val = *(s.begin());
        int node = val.second, dis = val.first;
        s.erase(s.begin());

        for(auto neighbour: adjacencyList[node]){
            if(dis+neighbour.second < distance[neighbour.first]){
                // if record already exists in set with a given distance then delete it
                auto record = s.find({distance[neighbour.first], neighbour.first});
                if(record != s.end()){
                    s.erase(record);
                }

                distance[neighbour.first] = dis+neighbour.second;
                s.insert({distance[neighbour.first], neighbour.first});
            }
        }
    }
}

int main(){
    int nodes, edges;
    cout << "Enter Number of Nodes: ";
    cin >> nodes;
    cout << "Enter Number of Edges: ";
    cin >> edges;

    // adjancency list
    unordered_map<int, vector<pair<int, int>>> adjacencyList;
    vector<vector<int>> edgeList = {{0,1,7}, {0,2,1}, {0,3,2}, {1,2,3}, {1,3,5}, {1,4,1}, {3,4,7}};
    // createAdList(adjacencyList, edges);
    createAdList(adjacencyList, edgeList);
    printAdList(adjacencyList);

    vector<int> distance(nodes, INT_MAX);

    int src = 0;
    dijsktraPQ(adjacencyList, distance, src, nodes);
    cout << "Shortest Distance using Dijsktra's Algo with PQ from Src: ";
    print(distance);

    vector<int> distance2(nodes, INT_MAX);
    dijsktraSet(adjacencyList, distance2, src, nodes);
    cout << "Shortest Distance using Dijsktra's Algo with Set from Src: ";
    print(distance2);
    
    return 0;
}