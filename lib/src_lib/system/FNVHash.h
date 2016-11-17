/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_FNVHASH_H_
#define SYSTEM_FNVHASH_H_


namespace alinous {

/**
 * FNV Constants
 */
static const uint32_t FNV_OFFSET_BASIS_32 = 2166136261U;
static const uint64_t FNV_OFFSET_BASIS_64 = 14695981039346656037U;

static const uint32_t FNV_PRIME_32 = 16777619U;
static const uint64_t FNV_PRIME_64 = 1099511628211LLU;


class FNVHash {
public:
	static uint32_t fnv_1_hash_32(uint8_t *bytes, size_t length) throw();
	static uint64_t fnv_1_hash_64(uint8_t *bytes, size_t length) throw();
};

} /* namespace alinous */

#endif /* SYSTEM_FNVHASH_H_ */
