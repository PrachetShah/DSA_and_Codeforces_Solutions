#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int _key, int _value){
        key = _key;
        value = _value;
        prev = NULL;
        next = NULL;
    }
};


class LRUCache{
    public:
    int capacity;
    map<int, Node*> nodes;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int cap){
        capacity = cap;
        nodes.clear();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_){
        // O(1)
        if(nodes.find(key_) != nodes.end()){
            Node* nodeToinsert = nodes[key_];
            deleteNode(nodeToinsert);
            insertAfterHead(nodeToinsert);
            return nodeToinsert->value;
        }
        return -1;
    }

    void put(int key, int value){
        if(nodes.find(key) != nodes.end()){
            Node* node = nodes[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        }else{
            if(nodes.size()==capacity){
                // full capacity
                Node* node = tail->prev;
                nodes.erase(node->key);
                deleteNode(node);   
            }
            // insert the new node
            Node* nodeToInsert = new Node(key, value);
            nodes[key] = nodeToInsert;
            insertAfterHead(nodeToInsert);
        }
    }

    private:
    void deleteNode(Node* node){
        Node* temp = node;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    void insertAfterHead(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
};

int main(){
    LRUCache* lru = new LRUCache(2);
    lru->put(1, 1);
    lru->put(2, 2);
    cout << lru->get(1) << endl;
    lru->put(3, 3);
    cout << lru->get(2) << endl;
    lru->put(4, 4);
    cout << lru->get(1) << endl;
    cout << lru->get(2) << endl;
    cout << lru->get(3) << endl;
    cout << lru->get(4) << endl;
}