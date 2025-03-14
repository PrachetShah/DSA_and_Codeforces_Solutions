#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int data_){
        data = data_;
    }
};

Node* flatten(Node* head) {
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr != NULL){
        if(curr->child != NULL){
            // recursive call to keep digging
            Node* next = curr->next;
            curr->next = flatten(curr->child);
            curr->next->prev = curr;
            curr->child = NULL;
            
            // connecting flattened child with next by finding tail
            while(curr->next != NULL){
                curr = curr->next;
            }

            // attach tail(curr) with next pointer
            if(next!=NULL){
                curr->next = next;
                next->prev = curr;
            }   
        }
        curr = curr->next;
    }
    return head;
}

int main(){
    return 0;
}