#ifndef HAS_TABLE_H
#define HAS_TABLE_H
#include <vector>
#include <list>
#include <cstddef>
#include <algorithm>
#include <iostream>
#include "hash.h"


template <typename HashObject>
class HashTable {
public:
    explicit HashTable(int size = 101);
public:
    void makeEmpty();
    bool contains(const HashObject& ) ;
    bool insert(const HashObject&);
    bool insert(HashObject&&);
    bool remove(const HashObject&);
private:
    size_t myHash(const HashObject&);
    void reHash();
private:
    std::vector<std::list<HashObject>> theList;
    int currentSize;
};


#endif // HAS_TABLE_H
