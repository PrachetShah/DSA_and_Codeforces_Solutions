#include<bits/stdc++.h>

using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* random;

    Node(int data_){
        val = data_;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* curr = head;
        Node* clone;
        // add dummy to list
        while(curr != NULL){
            clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = curr->next->next;
        }

        // join random
        curr = head;
        while(curr != NULL){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // split lists
        curr = head;
        Node* cloneHead = curr->next;
        clone = curr->next;
        while(curr!=NULL){
            Node* next = curr->next->next;
            Node* clone = curr->next;
            curr->next = next;
            if(next != NULL){
                clone->next = next->next;
            }
            curr = next;
        }

        return cloneHead;
    }
};

void printLL(Node* head){
    Node* curr = head;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
}

// Solution using HashMap
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // create a map
        unordered_map<Node*,Node*>oldtonew;
        Node* curr = head;

        while(curr){
            oldtonew[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr=head;
        
        while(curr!=NULL){
            Node* copy = oldtonew[curr];
            copy->next = oldtonew[curr->next];
            copy->random = oldtonew[curr->random];
            curr = curr->next;
        }
        return oldtonew[head];
    }
};

int main(){}