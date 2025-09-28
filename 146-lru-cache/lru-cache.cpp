#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp; // key -> node
    Node* head; // dummy head
    Node* tail; // dummy tail

    // helper: remove node from DLL
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // helper: add node right after head (MRU position)
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        int val = node->value;

        // move node to front (MRU)
        removeNode(node);
        addToFront(node);

        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // update existing node
            Node* node = mp[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
        } else {
            if ((int)mp.size() == capacity) {
                // remove LRU (node before tail)
                Node* lru = tail->prev;
                mp.erase(lru->key);
                removeNode(lru);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            addToFront(newNode);
            mp[key] = newNode;
        }
    }
};
