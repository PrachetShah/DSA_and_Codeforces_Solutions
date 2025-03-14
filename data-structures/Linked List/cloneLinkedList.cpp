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
    private:
        void insertAtTail(Node* &head, Node* &tail, int d){
            Node* newNode = new Node(d);
            if(head==NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            else{
                tail ->next = newNode;
                tail = newNode;
            }
        }
public:
    Node* copyRandomList(Node* head) {
        // create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }
        
        // create a map
        unordered_map<Node*,Node*>oldtonew;
        Node* original = head;
        Node* clone = cloneHead;
        while(original != NULL && clone!=NULL){
            oldtonew[original]=clone;
            original = original->next;
            clone = clone->next;
        }
        original=head;
        clone = cloneHead;
        
        while(original!=NULL){
            clone->random = oldtonew[original->random];
            original = original->next;
            clone = clone->next;
        }
        return cloneHead;
    }
};

int main(){}