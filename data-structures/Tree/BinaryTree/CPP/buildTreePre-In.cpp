#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data_){
        data = data_;
    }
};

Node* helper(vector<int> preorder, vector<int> inorder, int &preIndex, map<int, int> inorderMap, int s, int e){
    if(preIndex == preorder.size()){
        return  NULL;
    }
    int val = preorder[preIndex];
    Node* root = new Node(val);
    int leftEnd = inorderMap[preorder[preIndex]];
    preIndex++;
    root->left = helper(preorder, inorder, preIndex, inorderMap, s, leftEnd-1);
    root->right = helper(preorder, inorder, preIndex, inorderMap, leftEnd+1, e);
    return root;
}

Node* buildTree(vector<int> preorder, vector<int> inorder){
    int preIndex = 0;
    map<int, int> inorderMap;
    for(int i=0; i<inorder.size(); i++){
        inorderMap[inorder[i]] = i;
    }
    Node* tree = helper(preorder, inorder, preIndex, inorderMap, 0, inorder.size()-1);
    return tree;
}

void printTree(Node* root){
    if(root == NULL){
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

void printArr(vector<int> arr){
    for(auto num: arr){
        cout << num << " ";
    }
    cout << "\n";
}

int main(){
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    Node* root = buildTree(preorder, inorder);
    cout << "Inorder: ";
    printArr(inorder);
    cout << "\nPost Order from Tree: ";
    printTree(root);

}