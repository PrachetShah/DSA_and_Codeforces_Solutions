#include<bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data_){
        val = data_;
    }
};

void serHelper(TreeNode* root, string &str){
    if(root==NULL){
        str += "N";
        return;
    }
    // serialising it in preorder
    str += to_string(root->val);
    serHelper(root->left, str);
    serHelper(root->right, str);
}
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string ser;
    serHelper(root, ser);
    cout << ser;
    return ser;
}

// Decodes your encoded data to tree.
TreeNode* desHelper(string data, int &index){
    if(data[index] == 'N'){
        index++;
        return NULL;
    }
    TreeNode* node = new TreeNode(data[index] - '0');
    index++;
    node->left = desHelper(data, index);
    node->right = desHelper(data, index);
    return node;
}
TreeNode* deserialize(string data) {
    int index = 0;
    return desHelper(data, index); 
}

int main(){

}