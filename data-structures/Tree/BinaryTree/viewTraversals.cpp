#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        data = data;
        left = NULL;
        right = NULL;
    }
};

void traversalCode(Node* root){
    // node, [level ,hd]
    queue<pair<Node*, pair<int, int>>> q;
    map<int, vector<int>> hdMap;
    map<int, vector<int>> levelMap;
    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()){
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();

        Node* node = temp.first;
        int level = temp.second.first;
        int hd = temp.second.second;

        hdMap[hd].push_back(node->data);
        levelMap[level].push_back(node->data);

        if(node->left != NULL){
            q.push(make_pair(root, make_pair(level+1, hd-1)));
        }
        if(node->right){
            q.push(make_pair(root, make_pair(level+1, hd+1)));
        }
    }

    for(auto &it:hdMap){
        cout << it.first << " : [";
        for(auto &val: it.second){
            cout << val << " ";
        }
        cout << " ]" << endl;
    }
}

int main(){
    Node* root;
    root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    traversalCode(root);
}