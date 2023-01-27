#ifndef STRING_SPEC_HASH_HPP
#define STRING_SPEC_HASH_HPP
#include "string_spec_hash.h"


size_t Hash<std::string>::operator() (const std::string& rhs) const{
    size_t hashValue = 0;
    for (auto& ch : rhs) {
        hashValue = 37 * hashValue + ch;
    }
    return hashValue;
}

#endif // STRING_SPEC_HASH_HPP
