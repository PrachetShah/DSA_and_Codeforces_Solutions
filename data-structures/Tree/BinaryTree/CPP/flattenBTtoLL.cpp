/*
Flatten Binary Tree to LL using Morris Traversal which does it in O(1) space
*/

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
    }
};
class Solution{
    public:
    Node* prev = nullptr;
    // 1. Reursion
    void flatten(Node* root){
        // O(n), O(n)
        if(root==nullptr){
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

    // 2. Iterative
    void flattenIterative(Node* root){
        // O(n), O(n)
        stack<Node*> st;
        st.push(root);

        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
            if(!st.empty()){
                curr->right = st.top();
            }
            curr -> left = NULL;
        }
    }

    // 3. Morris Traversal O(2n)->O(n), SC: O(1)
    void flattenMorris(Node* root){
        Node* curr = root;
        while(curr){
            if(curr->left != NULL){
                Node* pre = curr->left;
                while(pre->right){
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

int main(){

}