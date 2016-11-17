/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_FILEINPUTSTREAM_H_
#define BASELIB_IO_FILEINPUTSTREAM_H_

namespace java { namespace io {

class FileInputStream : public InputStream {
public:
	FileInputStream(File *file, ThreadContext* ctx);
	FileInputStream(UnicodeString* fileName, ThreadContext* ctx);

private:
	void openFile(File *file, ThreadContext* ctx);
public:

	virtual ~FileInputStream();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() ;
	virtual int available(ThreadContext* ctx);
	virtual void close(ThreadContext* ctx);
	virtual int read(ThreadContext* ctx);
	virtual int read(IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx);
	virtual int read(IArrayObjectPrimitive<char>* b, ThreadContext* ctx);
	long long skip(long long count);
protected:
	File* file;
	FILE* desc;
};

}} /* namespace alinous */

#endif /* BASELIB_IO_FILEINPUTSTREAM_H_ */
