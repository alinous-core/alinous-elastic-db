/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_FASTCOPY_H_
#define SYSTEM_FASTCOPY_H_

namespace alinous {

class FastCopy{
public:
	inline static void copy(void* const dest, const void* const src, size_t size) throw() {
		::memcpy(dest, src, size);

	}
	inline static void copyA(void* const dest, const void* const src, size_t size) throw() {
		size_t remain = size;

		long long* destl = (long long*)dest;
		long long* srcl = (long long*)src;

		while(remain >= 64){
			*destl++ = *srcl++;
			*destl++ = *srcl++;
			*destl++ = *srcl++;
			*destl++ = *srcl++;

			*destl++ = *srcl++;
			*destl++ = *srcl++;
			*destl++ = *srcl++;
			*destl++ = *srcl++;

			remain -= 64;
		}
	//	if(remain == 0){return;}

		if(remain >= 32){
			*destl++ = *srcl++;
			*destl++ = *srcl++;
			*destl++ = *srcl++;
			*destl++ = *srcl++;

			remain -= 32;
		}

	//	if(remain == 0){return;}

		if(remain >= 16){
			*destl++ = *srcl++;
			*destl++ = *srcl++;

			remain -= 16;
		}

		if(remain >= 8){
			*destl++ = *srcl++;

			remain -= 8;
		}

		short* dests = (short*)destl;
		short* srcs = (short*)srcl;
		while(remain >= 2){
			*dests++ = *srcs++;
			remain -= 2;
		}

		char* destb = (char*)dests;
		char* srcb = (char*)srcs;
		while(remain > 0){
			*destb++ = *srcb++;
			remain--;
		}
	}
};

}


#endif /* SYSTEM_FASTCOPY_H_ */
