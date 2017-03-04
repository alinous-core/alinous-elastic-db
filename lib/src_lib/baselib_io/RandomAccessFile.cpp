/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

#include "java.lang/Comparable.h"
#include "java.lang/Number.h"
#include "java.lang/Double.h"
#include "java.lang/Float.h"


namespace java {
namespace io {

inline double RandomAccessFile::readDouble(ThreadContext* ctx) {
   return Double::longBitsToDouble(readLong(ctx), ctx);
}

inline float RandomAccessFile::readFloat(ThreadContext* ctx) {
	return Float::intBitsToFloat(readInt(ctx), ctx);
}

IArrayObject<MMapSegment>* RandomAccessFile::getSegments(long long position, long long size, ThreadContext* ctx) {
	ArrayList<MMapSegment>* list = new(ctx) ArrayList<MMapSegment>(ctx);
	long long endPosition = position + size;
	long long pos = position;

	while(true){
		MMapSegment* seg = this->segments->getSegment(pos, ctx);
		list->add(seg, ctx);

		pos = seg->lastOfSegment;
		if(endPosition <= pos){
			break;
		}
	}


	return list->toArray(ctx);
}



}}

