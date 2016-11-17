/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_FILEREADER_H_
#define BASELIB_IO_FILEREADER_H_

#include "includes.h"

namespace java { namespace io {

class FileReader : public InputStreamReader {
public:
	FileReader(File* file, ThreadContext* ctx) : IObject(ctx), InputStreamReader(new FileInputStream(file, ctx), ctx){

	}
	FileReader(String* filename, ThreadContext* ctx) : IObject(ctx), InputStreamReader(new FileInputStream(filename, ctx), ctx){

	}

	virtual ~FileReader(){
		ThreadContext *ctx = ThreadContext::getCurentContext();
		__releaseRegerences(false, ctx);
	}
	void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		InputStreamReader::__releaseRegerences(prepare, ctx);
	}
};

}}


#endif /* BASELIB_IO_FILEREADER_H_ */
