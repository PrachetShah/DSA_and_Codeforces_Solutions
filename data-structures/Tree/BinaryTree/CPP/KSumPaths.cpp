#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void printArr(vector<int> arr, int start, int end){
    for(int i=start; i<end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solveKPath(Node* root, int k, vector<int> &path, int &count){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    solveKPath(root->left, k, path, count);
    solveKPath(root->right, k, path, count);
    
    int SUM = 0;
    int n = path.size();
    for(int i=n-1; i>=0; i--){
        SUM += path[i];
        if(SUM==k){
            count++;
            printArr(path, i, n);
        }
    }
    path.pop_back();
}

void KSumPaths(Node* root, int k){
    int count = 0;
    vector<int> path;
    solveKPath(root, k, path, count);
    cout << "Total K Sum Paths are: " << count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
                1
        2               3
    4       5       6       7
        1               8      9
                           120  100
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(1);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(100);
    root->right->right->right->left = new Node(120);

    cout << "\nPreorder Traversal of Tree is: ";
    preOrder(root);
    cout << endl;
    cout << "Paths are:\n";
    KSumPaths(root, 9);
    return 0;
}