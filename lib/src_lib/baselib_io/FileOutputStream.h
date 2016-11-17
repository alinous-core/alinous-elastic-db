/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_FILEOUTPUTSTREAM_H_
#define BASELIB_IO_FILEOUTPUTSTREAM_H_

namespace java { namespace io {

class FileOutputStream : public OutputStream {
public:
	FileOutputStream(File *file, ThreadContext* ctx);
	FileOutputStream(File* file, bool append, ThreadContext* ctx);
	FileOutputStream(UnicodeString* fileName, ThreadContext* ctx);
	FileOutputStream(UnicodeString* fileName, bool append, ThreadContext* ctx);

private:
	class FileBuffer{
	public:
		long int size;
		int num;
		ByteBuffer* buff;
		ByteBuffer* flushbuff;
		ByteBuffer* one;
		ByteBuffer* two;

		int fd;

		SysMutex mutex;
		SysThread* th;

		FileBuffer(int fd);
		~FileBuffer();
		static void* doFlush(void* param);
		void flush();
		void join();
		void write(IArrayObjectPrimitive<char>* buffer, int off, int len);
		void write(int b);
	};


	void openFile(File *file, int mode, ThreadContext* ctx);
public:
	virtual ~FileOutputStream();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	virtual int available(ThreadContext* ctx);
	virtual void flush(ThreadContext* ctx);
	virtual void close(ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<char>* buffer, int off, int len, ThreadContext* ctx);
	virtual void write(int b, ThreadContext* ctx);
protected:
	File* file;
	int fd;
	FileBuffer* _fb;
};

}} /* namespace alinous */

#endif /* BASELIB_IO_FILEOUTPUTSTREAM_H_ */
