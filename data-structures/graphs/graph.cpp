#include<bits/stdc++.h>

using namespace std;

void printMatrix(vector<vector<int>> adjacencyMatrix){
    for(int i=0; i<adjacencyMatrix.size(); i++){
        for(int j=0; j<adjacencyMatrix.size(); j++){
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int nodes;
    cout << "Enter Nodes of Graph: ";
    cin >> nodes;

    vector<vector<int>> adjacencyMatrix (nodes, vector<int> (nodes, 0));

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(i==j)
                continue;
            cout << "Enter Edge for " << i << "->" << j << ": ";
            cin >> adjacencyMatrix[i][j];
        }
    }

    printMatrix(adjacencyMatrix);
    return 0;
}