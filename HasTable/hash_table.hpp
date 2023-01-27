#ifndef HAS_TABLE_HPP
#define HAS_TABLE_HPP
#include "hash_table.h"

template <typename HashObject>
HashTable<HashObject>::HashTable(int size) 
: currentSize{size}
, theList(size)
{}

template <typename HashObject>
void HashTable<HashObject>::makeEmpty() {
    for (auto& it : theList) {
        it.clear();
    }
}

template <typename HashObject>
bool HashTable<HashObject>::contains(const HashObject& rhs) {
    auto& wichList = theList[myHash(rhs)];
    return std::find(std::begin(wichList), std::end(wichList), rhs) != std::end(wichList);
}

template <typename HashObject>
bool  HashTable<HashObject>::remove(const HashObject& rhs) {
    auto& whichList = theList[myHash(rhs)];
    auto it = std::find(theList.begin(), theList.end(), rhs);
    if (it == theList.end()) {
        return false;
    }
    whichList.erase(rhs);
    --currentSize;
    return true;

}


template <typename HashObject>
bool HashTable<HashObject>::insert(const HashObject& rhs) {
    auto& wichList = theList[myHash(rhs)];
    if (std::find(wichList.begin(), wichList.end(), rhs) != wichList.end());
    wichList.push_back(rhs);
    if (++currentSize > theList.size()) {
        this->reHash();
    }
    return true;
}

template <typename HashObject>
bool HashTable<HashObject>::insert(HashObject&& rhs) {
    auto& wichList = theList[myHash(rhs)];
    if (std::find(wichList.begin(), wichList.end(), rhs) != wichList.end());
    wichList.push_back(rhs);
    if (++currentSize > theList.size()) {
        this->reHash();
    }
    return true;
}


template <typename HashObject>
size_t HashTable<HashObject>::myHash(const HashObject& rhs) {
    static Hash<HashObject> hf;
    return (hf(rhs) % theList.size());
}

template <typename HashObject>
void HashTable<HashObject>::reHash() {
    std::vector<std::list<HashObject>> newTable(2 * currentSize);
    newTable = theList;
    theList.clear();
    theList = newTable;
}

#endif // HAS_TABLE_HPP
