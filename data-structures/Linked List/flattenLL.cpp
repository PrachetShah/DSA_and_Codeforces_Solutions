#include<bits/stdc++.h>

using namespace std;


struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

Node* merge(Node* list1, Node* list2){
    Node* dummy = new Node(-1);
    Node* head = dummy;
    while(list1 && list2){
        if(list1->data <= list2->data){
            dummy->bottom = list1;
            list1 = list1->bottom;
        }else{
            dummy->bottom = list2;
            list2 = list2->bottom;
        }
        dummy = dummy->bottom;
    }
    if(list1){
        dummy->bottom = list1;
    }
    if(list2){
        dummy->bottom = list2;
    }
    return head->bottom;
}


class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(root == NULL || root->next == NULL){
            return root;
        }
        // root->next = flatten(root->next);
        root = merge(root, flatten(root->next));
        return root;
    }
};