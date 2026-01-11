/*
In BST, L<N<R
Inorder of BST is always the Sorted Array
So inorder traversal would give the sorted array by default in it
*/
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int _data){
        data = _data;
    }
};

void inorderOptimal(Node* root, int &cnt, int &ans, int k){
    if(root == NULL){
        return;
    }
    inorderOptimal(root->left, cnt, ans, k);
    cnt++;
    if(cnt == k){
        ans = root->data;
        return;
    }
    inorderOptimal(root->right, cnt, ans, k);
}

int main(){
    return 0;
}