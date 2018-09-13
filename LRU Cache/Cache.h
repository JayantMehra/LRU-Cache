//
//  Cache.h
//  LRU Cache
//
//  Created by Jayant Mehra on 9/13/18.
//  Copyright © 2018 Jayant Mehra. All rights reserved.
//

#ifndef Cache_h
#define Cache_h

#include <unordered_map>
#include <string>
using namespace std;

class Cache {
public:
    Cache(int maxSize = 10);
    string getValue(int key);
    bool removeKey(int key);
    bool setKeyValue(int key, string value);
    
private:
    int maxCacheSize;
    
    struct LinkedListNode {
        int key;
        string value;
        LinkedListNode* next;
        LinkedListNode* prev;
        
        LinkedListNode(int k, string v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };
    
    unordered_map<int, LinkedListNode*> map;
    LinkedListNode* head;
    LinkedListNode* tail;
    
    void removeFromLinkedList(LinkedListNode* node);
    void insertAtFront(LinkedListNode* node);
    
};

inline
Cache::Cache(int maxSize) {
    maxCacheSize = maxSize;
    head = nullptr;
    tail = nullptr;
}

#endif /* Cache_h */
