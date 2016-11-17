/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_MEMORYINTERFACE_H_
#define GC_MEMORYINTERFACE_H_

namespace alinous {

class MemoryInterface{
public:
	MemoryInterface() throw() {}
	virtual ~MemoryInterface() throw() {}

public:
	RawArrayMemAlloc* alloc;
};

}


#endif /* GC_MEMORYINTERFACE_H_ */
