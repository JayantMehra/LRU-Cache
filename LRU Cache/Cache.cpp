//
//  Cache.cpp
//  LRU Cache
//
//  Created by Jayant Mehra on 9/13/18.
//  Copyright © 2018 Jayant Mehra. All rights reserved.
//

#include "Cache.h"
#include <utility>

string Cache::getValue(int key) {
    if (map.find(key) == map.end())
        return "";              //  Not Found
    
    LinkedListNode* item = map.find(key)->second;
    if (item != head) {
        removeFromLinkedList(item);
        insertAtFront(item);
    }
    
    return item->value;
}

void Cache::removeFromLinkedList(Cache::LinkedListNode *node) {
    if (node->prev != nullptr)
        node->prev->next = node->next;
    
    if (node->next != nullptr)
        node->next->prev = node->prev;
    
    if (node == head)
        head = node->next;
    
    if (node == tail)
        tail = node->prev;
}

void Cache::insertAtFront(Cache::LinkedListNode *node) {
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else{
        head->prev = node;
        node->next = head;
        head = node;
    }
}

bool Cache::removeKey(int key) {
    if (map.find(key) == map.end())
        return false;
    LinkedListNode* node = map.find(key)->second;
    removeFromLinkedList(node);
    delete node;
    map.erase(key);
    return true;
}

bool Cache::setKeyValue(int key, string value) {
    removeKey(key);
    
    if (map.size() >= maxCacheSize && tail != nullptr) {
        removeKey(tail->key);
    }
    
    LinkedListNode* node = new LinkedListNode(key, value);
    insertAtFront(node);
    map.insert(make_pair(key, node));
    
    return true;
}


