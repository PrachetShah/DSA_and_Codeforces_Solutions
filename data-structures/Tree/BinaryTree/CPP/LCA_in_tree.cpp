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

Node* solveLca(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data==n2){
        return root;
    }
    Node* leftAns = solveLca(root->left, n1, n2);
    Node* rightAns = solveLca(root->right, n1, n2);
    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }else if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }else{
        return NULL;
    }
}

bool checkNodeExists(Node* root, int x){
    if(root==NULL){
        return false;
    }
    if(root->data == x || checkNodeExists(root->left, x) || checkNodeExists(root->right, x)){
        return true;
    }else{
        return false;
    }
}

void LCA(Node* root, int n1, int n2){
    if(checkNodeExists(root, n1) && checkNodeExists(root, n2)){
        Node* ans = solveLca(root, n1, n2);
        if(ans != NULL){
            cout << "LCA of " << n1 << " & " << n2 << " is " << ans->data << endl;
        }else{
            cout << "LCA of " << n1 << " & " << n2 << " is NULL" << endl;
        }
    }else{
        cout << "Both Node does not exist in the tree" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
                1
        2               3
    4       5       6       7
                       8      9
                           120  100
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(100);
    root->right->right->right->left = new Node(120);

    preOrder(root);
    cout << endl;
    LCA(root, 4, 6);
    LCA(root, 4, 5);
    LCA(root, 6, 7);
    return 0;
}