/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace alinous {
uint32_t FNVHash::fnv_1_hash_32(uint8_t *bytes, size_t length) throw() {
    uint32_t hash;
    size_t i;

    hash = FNV_OFFSET_BASIS_32;
    for( i = 0 ; i < length ; ++i) {
        hash = (FNV_PRIME_32 * hash) ^ (bytes[i]);
    }

    return hash;
}
uint64_t FNVHash::fnv_1_hash_64(uint8_t *bytes, size_t length) throw(){
    uint64_t hash;
    size_t i;

    hash = FNV_OFFSET_BASIS_64;
    for( i = 0 ; i < length ; ++i) {
        hash = (FNV_PRIME_64 * hash) ^ (bytes[i]);
    }

    return hash;
}
}

