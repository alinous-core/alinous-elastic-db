/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */



#ifndef BASELIB_IO_RANDOMACCESSFILE_H_
#define BASELIB_IO_RANDOMACCESSFILE_H_


namespace java {
namespace io {

using ::alinous::io::DiskCacheManager;
using ::alinous::io::MMapSegment;
using ::alinous::io::MMapSegments;

using ::java::util::ArrayList;

class RandomAccessFile : public virtual IObject {
	constexpr static long long PAGE_NUM_CACHE{4};
public:
	inline RandomAccessFile(DiskCacheManager* diskCacheManager, File* file, UnicodeString* mode, ThreadContext* ctx)
			: IObject(ctx)
	{
		this->diskCacheManager = __GC_INS(this, diskCacheManager, DiskCacheManager);
		this->file = __GC_INS(this, file, File);
		this->mode = __GC_INS(this, mode, UnicodeString);
		this->position = 0;

		this->pageSize = ::sysconf(_SC_PAGE_SIZE);
		this->fd = 0;

		openMMap(ctx);
	}

	inline RandomAccessFile(DiskCacheManager* diskCacheManager, UnicodeString* filePath, UnicodeString* mode, ThreadContext* ctx) : IObject(ctx), diskCacheManager(diskCacheManager) {
		this->diskCacheManager = __GC_INS(this, diskCacheManager, DiskCacheManager);
		this->file = __GC_INS(this, new File(filePath, ctx), File);
		this->mode = __GC_INS(this, mode, UnicodeString);
		this->position = 0;

		this->pageSize = ::sysconf(_SC_PAGE_SIZE) * 4;
		this->fd = 0;

		openMMap(ctx);
	}

	virtual ~RandomAccessFile(){
		ThreadContext *ctx = ThreadContext::getCurentContext();
		__releaseRegerences(false, ctx);
	}

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		if(this->file != nullptr){
			closeMMap(ctx);

			__GC_DEC(this, this->file, File);
			__GC_DEC(this, this->mode, UnicodeString);
			__GC_DEC(this, this->diskCacheManager, DiskCacheManager);

			this->file = nullptr;
			this->mode = nullptr;
		}
	}


private:
	int fd;
	long long pageSize;
	long long fileSize;
	MMapSegments* segments;
	DiskCacheManager* diskCacheManager;

	inline void openMMap(ThreadContext* ctx){
		if(!this->file->exists(ctx)){
			UnicodeString* path = this->file->getAbsolutePath(ctx);
			char* cpath = path->toCString(ctx);
			fd = ::open(cpath, O_RDWR | O_CREAT, S_IRWXU | S_IRUSR | S_IRGRP | S_IWGRP);
			delete [] cpath;
		}

		if(this->fd <= 0){
			UnicodeString* path = this->file->getAbsolutePath(ctx);
			char* cpath = path->toCString(ctx);
			fd = ::open(cpath, O_RDWR);
			delete [] cpath;

			if(fd < 0){
				throw new IOException(new UnicodeString(L"Failed in opening file", ctx), ctx);
			}
		}

		//
		this->position = 0;

		this->fileSize = this->file->length(ctx);

		if(this->fileSize > 0){
			long long segmentSize = this->pageSize * PAGE_NUM_CACHE;
			segments = new MMapSegments(this->diskCacheManager, this->fd, segmentSize, this->fileSize);
		}else{
			this->segments = nullptr;
		}
	}

	inline bool isOpened(){
		return this->segments != nullptr;
	}
	inline void closeMMap(ThreadContext* ctx){
		if(this->segments != nullptr){
			delete this->segments;
			this->segments = nullptr;
		}
	}

public:
	inline void close(ThreadContext* ctx) {
		closeMMap(ctx);

		::close(this->fd);
		this->fd = 0;
	}

	inline long long getFilePointer(ThreadContext* ctx) {
		return this->position;
	}
	inline void seek(long long pos, ThreadContext* ctx) {
		this->position = pos;
	}
	int skipBytes(int count, ThreadContext* ctx) {
	    if (count > 0) {
	        long long currentPos = getFilePointer(ctx), eof = length(ctx);
	        int newCount = (int) ((currentPos + count > eof) ? eof - currentPos
	                : count);
	        seek(currentPos + newCount, ctx);
	        return newCount;
	    }

	    return 0;
	}
	inline long long length(ThreadContext* ctx) {
		return fileSize;
	}
	inline void setLength(long long newLength, ThreadContext* ctx) {
		long long newSize = newLength - this->fileSize;
		const long long numBlocks = newSize / this->pageSize;
		const long long modBytes = newSize % this->pageSize;

		::lseek(this->fd, 0, SEEK_END);

		int n;
		char *tmp = new char[this->pageSize]{};
		for(int i = 0; i != numBlocks; ++i){
			n = ::write(this->fd, tmp, this->pageSize);
			if(n != this->pageSize){
				throw new IOException(ctx);
			}
		}

		n = ::write(this->fd, tmp, modBytes);
		if(n != modBytes){
			throw new IOException(ctx);
		}

		delete [] tmp;

		this->fileSize = this->file->length(ctx);

		if(this->segments == nullptr){
			openMMap(ctx);
		}else{
			this->segments->onResized(this->fileSize, ctx);
		}

	}

	inline int read(long long position, ThreadContext* ctx) {
		MMapSegment* seg = this->segments->getSegment(position, ctx);
		int oneByte = seg->read(position);

		seg->decUserCount();

		return oneByte;
	}
	inline int read(ThreadContext* ctx) {
		int oneByte = read(this->position++, ctx);
		return oneByte;
	}

	inline long read(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx) {
		long red = read(0, buffer, 0, buffer->length, ctx);
		this->position += red;
		return red;
	}

	inline long read(IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx){
		long nread = read(this->position, buffer, 0, buffer->length, ctx);
		this->position += nread;

		return nread;
	}

	inline long read(long long position, IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx) {
		return read(position, buffer, 0, buffer->length, ctx);
	}

	inline long read(long long position, IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx){
		long long fileRemain = this->fileSize - position;
		long long bytesToRead = fileRemain > count ? count : fileRemain;
		long long pos = position;
		int off = offset;
		int cnt = 0;

		while(bytesToRead > 0){
			MMapSegment* seg = this->segments->getSegment(pos, ctx);
			long long read = seg->read(pos, buffer, off, bytesToRead, ctx);

			cnt += read;
			off += read;
			pos += read;

			bytesToRead -= read;

			seg->decUserCount();
		}

		return cnt;
	}

	inline long read(long long position, char* buffer, int offset, int count, ThreadContext* ctx){
		long long fileRemain = this->fileSize - position;
		long long bytesToRead = fileRemain > count ? count : fileRemain;
		long long pos = position;
		int off = offset;
		int cnt = 0;

		while(bytesToRead > 0){
			MMapSegment* seg = this->segments->getSegment(pos, ctx);
			long long read = seg->read(pos, buffer, off, bytesToRead, ctx);

			cnt += read;
			off += read;
			pos += read;
			bytesToRead -= read;

			seg->decUserCount();
		}

		return cnt;
	}

	inline void readFully(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx) {
	    readFully(buffer, 0, buffer->length, ctx);
	}

	inline void readFully(IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx) {
		if (buffer == nullptr) {
			throw new NullPointerException(ctx);
		}
		// avoid int overflow
		if (offset < 0 || offset > buffer->length || count < 0
				|| count > buffer->length - offset) {
			throw new IndexOutOfBoundsException(ctx);
		}
		while (count > 0) {
			int result = read(buffer, offset, count, ctx);
			if (result < 0) {
				throw new EOFException(ctx);
			}
			offset += result;
			count -= result;
		}
	}

	inline bool readBoolean(ThreadContext* ctx) {
	    int temp = this->read(ctx);
	    if (temp < 0) {
	        throw new EOFException(ctx);
	    }
	    return temp != 0;
	}

	inline char readByte(ThreadContext* ctx) {
	    int temp = this->read(ctx);
	    if (temp < 0) {
	        throw new EOFException(ctx);
	    }
	    return (char) temp;
	}

	inline unsigned short readChar(long long position, ThreadContext* ctx) {
		unsigned short value;
		read(position, (char*)&value, 0, sizeof(unsigned short), ctx);

		return value;
	}

	inline wchar_t readChar(ThreadContext* ctx){
		wchar_t value = readChar(this->position, ctx);
    	this->position += sizeof(unsigned short);
    	return value;
    }

	inline int readInt(long long position, ThreadContext* ctx) {
    	int32_t value;
    	read(position, (char*)&value, 0, sizeof(int32_t), ctx);

    	return value;
    }

	inline int readInt(ThreadContext* ctx) {
    	int32_t value = readInt(this->position, ctx);
    	this->position += sizeof(int32_t);
    	return value;
    }

	inline long long readLong(long long position, ThreadContext* ctx) {
    	long long value;
    	read(position, (char*)&value, 0, sizeof(long long), ctx);

     	return value;
    }

	inline long long readLong(ThreadContext* ctx) {
    	long long value = readLong(this->position, ctx);
    	this->position += sizeof(long long);
    	return value;
    }

	inline double readDouble(ThreadContext* ctx);

	inline float readFloat(ThreadContext* ctx);

	inline short readShort(long long position, ThreadContext* ctx) {
    	short value;
    	read(position, (char*)&value, 0, sizeof(short), ctx);

     	return value;
     }

	inline short readShort(ThreadContext* ctx) {
    	short value = readShort(this->position, ctx);
    	this->position += sizeof(short);
    	return value;
    }

	inline int readUnsignedByte(ThreadContext* ctx){
    	int temp = this->read(ctx);
    	if (temp < 0) {
    		throw new EOFException(ctx);
    	}
    	return temp;
    }

	inline int readUnsignedShort(ThreadContext* ctx) {
    	IArrayObjectPrimitive<char>* buffer = new ArrayObjectPrimitive<char>(2, ctx);
    	if (read(buffer, 0, buffer->length, ctx) != buffer->length) {
    		throw new EOFException(ctx);
    	}
    	return ((buffer->get(0) & 0xff) << 8) + (buffer->get(1) & 0xff);
    }

	inline UnicodeString* readLine(ThreadContext* ctx) {
		StringBuffer* line = new StringBuffer(80, ctx); // Typical line length
		bool foundTerminator = false;
		long unreadPosition = 0;
		while (true) {
			int nextByte = read(ctx);
			switch (nextByte) {
			case -1:
				return line->length(ctx) != 0 ? line->toString(ctx) : nullptr;
			case '\r':
				if (foundTerminator) {
					seek(unreadPosition, ctx);
					return line->toString(ctx);
				}
				foundTerminator = true;
				/* Have to be able to peek ahead one byte */
				unreadPosition = getFilePointer(ctx);
				break;
			case '\n':
				return line->toString(ctx);
			default:
				if (foundTerminator) {
					seek(unreadPosition, ctx);
					return line->toString(ctx);
				}
				line->append((char) nextByte, ctx);
			}
		}
	}

	inline void write(long long position, int oneByte, ThreadContext* ctx) {
		MMapSegment* seg = this->segments->getSegment(position, ctx);
		seg->write(position, oneByte);
		seg->decUserCount();
	}

	inline long write(int oneByte, ThreadContext* ctx){
		write(this->position, oneByte, ctx);
		this->position += 1;

		return 1;
	}

	inline long write(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx)  {
		write(buffer, 0, buffer->length, ctx);
		return buffer->length;
	}

	inline int write(long long position, IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx) {
		int n = 0;
		long long pos = position;
		int off = offset;
		int cnt = count;
		while(n != count){
			MMapSegment* seg = this->segments->getSegment(pos, ctx);

			int wrote = seg->write(pos, buffer, off, cnt, ctx);
			n += wrote;
			cnt -= wrote;
			off += wrote;
			pos += wrote;

			seg->decUserCount();
		}
		return count;
	}

	inline long write(long long position, char* buffer, int offset, int count, ThreadContext* ctx)  {
		int n = 0;
		long long pos = position;
		int off = offset;
		int cnt = count;
		while(n != count){
			MMapSegment* seg = this->segments->getSegment(pos, ctx);

			int wrote = seg->write(pos, buffer, off, cnt, ctx);
			n += wrote;
			cnt = cnt - wrote;
			off += wrote;
			pos += wrote;

			seg->decUserCount();
		}
		return count;
	}

	inline void write(IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx) {
		 int red = write(this->position, buffer, offset, count, ctx);
		 this->position += red;
	}

	inline void writeBoolean(bool val, ThreadContext* ctx) {
		write(val ? 1 : 0, ctx);
	}

	inline void writeByte(int val, ThreadContext* ctx) {
		write(val & 0xFF, ctx);
	}

	inline void writeBytes(UnicodeString* str, ThreadContext* ctx) {
		writeChars(str, ctx);
	}

	inline void writeChar(int val, ThreadContext* ctx)  {
		unsigned short ch = val;
		write(position, (char*)&ch, 0, sizeof(short), ctx);

		this->position += sizeof(short);

	}

	inline long writeChar(long long position, int val, ThreadContext* ctx) {
		unsigned short ch = val;
		write(position, (char*)&ch, 0, sizeof(short), ctx);

		return sizeof(short);
	}

	inline long writeChars(long long position, UnicodeString* str, ThreadContext* ctx) {
		const int max = str->length(ctx);
		long long pos = position;
		for(int i = 0; i != max; ++i){
			writeChar(pos, str->charAt(i, ctx), ctx);
			pos += 2;
		}

		return max * 2;
	}

	inline void writeChars(UnicodeString* str, ThreadContext* ctx) {
		writeChars(position, str, ctx);
		this->position += str->length(ctx) * 2;
	}

	inline void writeDouble(long long position, double val, ThreadContext* ctx) {
		write(position, (char*)&val, 0, sizeof(double), ctx);
	}

	inline void writeDouble(double val, ThreadContext* ctx) {
		writeDouble(this->position, val, ctx);
		this->position += sizeof(double);
	}

	inline void writeFloat(long long position, float val, ThreadContext* ctx) {
		write(position, (char*)&val, 0, sizeof(float), ctx);
	}

	inline void writeFloat(float val, ThreadContext* ctx) {
		writeFloat(this->position, val, ctx);
		this->position += sizeof(float);
	}

	inline void writeInt(long long position, int32_t val, ThreadContext* ctx) {
		write(position, (char*)&val, 0, 4, ctx);

	}

	inline void writeInt(int val, ThreadContext* ctx) {
		writeInt(this->position, val, ctx);
		this->position += 4;
	}

	inline long writeLong(long long position, long long val, ThreadContext* ctx) {
		write(position, (char*)&val, 0, 8, ctx);
		return 8;
	}

	inline void writeLong(long long val, ThreadContext* ctx) {
		writeLong(this->position, val, ctx);
		this->position += 8;
	}

	inline int writeShort(long long position, int val, ThreadContext* ctx) {
		write(position, (char*)&val, 0, 2, ctx);
		return 2;
	}

	inline void writeShort(int val, ThreadContext* ctx) {
		writeChar(val, ctx);
		this->position += 8;
	}

	IArrayObject<MMapSegment>* getSegments(long long position, long long size, ThreadContext* ctx);

private:
	File* file;
	UnicodeString* mode;
	long long position;
};

} /* namespace io */
} /* namespace java */

namespace alinous {
namespace io {

using namespace java::io;

class ConcurrentFileAccess : public RandomAccessFile {
public:
	ConcurrentFileAccess(DiskCacheManager* diskCache, File* file, UnicodeString* mode, ThreadContext* ctx) : IObject(ctx), RandomAccessFile(diskCache, file, mode, ctx) {

	}

	ConcurrentFileAccess(DiskCacheManager* diskCache, UnicodeString* filePath, UnicodeString* mode, ThreadContext* ctx) : IObject(ctx), RandomAccessFile(diskCache, filePath, mode, ctx) {

	}
};

}}

#endif /* BASELIB_IO_RANDOMACCESSFILE_H_ */
