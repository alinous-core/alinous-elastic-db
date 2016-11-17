/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef INCLUDE_MACRO_DEFS_H_
#define INCLUDE_MACRO_DEFS_H_


#ifdef __GNUC__
//#define FORCE_INLINE __attribute__((always_inline))
#define FORCE_INLINE
#else
#define FORCE_INLINE
#endif


#define __builtin_prefetch_array(a, pos, rw, loc) __builtin_prefetch(a->raw->root[pos], rw, loc)
#define __builtin_prefetch_array_root(a, rw, loc) __builtin_prefetch(a->raw->root, rw, loc)

#endif /* INCLUDE_MACRO_DEFS_H_ */
