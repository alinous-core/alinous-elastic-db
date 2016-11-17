/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEMCALLS_H_
#define SYSTEMCALLS_H_


typedef unsigned char uint8_t;
//typedef unsigned long uint32_t;
//typedef unsigned long long uint64_t;



#ifdef __linux__
	#include <malloc.h>
	#include <memory.h>

	#define __memset(ptr, v, size) memset(ptr, v, size)
	#define __memcpy(dest, src, size) memcpy(dest, src, size)
#elif WIN32
	#include <malloc.h>
	#include <memory.h>

	#define __malloc(size) new char[size]
	#define __free(ptr) delete [] ptr
	#define __memset(ptr, v, size) memset(ptr, v, size)
	#define __memcpy(dest, src, size) memcpy(dest, src, size)
#endif





#endif /* SYSTEMCALLS_H_ */
