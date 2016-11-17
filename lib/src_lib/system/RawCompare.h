/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_RAWCOMPARE_H_
#define SYSTEM_RAWCOMPARE_H_

#include "include/global.h"

namespace alinous {

class ThreadContext;

struct RawCompare {
public:
	int operator() (const void* const a, const void* const b, const ThreadContext* const ctx) const throw(){
		long long diff = (long long)a - (long long)b;
		if(diff == 0){
			return 0;
		}
		return diff > 0 ? 1 : -1;
	}
};


} /* namespace alinous */



#endif /* SYSTEM_RAWCOMPARE_H_ */
