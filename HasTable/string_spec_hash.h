#ifndef STRING_SPEC_HASH_H
#define STRING_SPEC_HASH_H
#include "hash.h"
#include <string>


template <>
class Hash<std::string> {
public:
    size_t operator() (const std::string&) const;
};

#endif // STRING_SPEC_HASH_H
