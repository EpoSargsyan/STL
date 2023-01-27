#ifndef HASH_H
#define HASH_H
#include <cstddef>


template <typename Key>
class Hash {
public:
    size_t operator() (const Key& ) const;
};

#endif // HASH_H
