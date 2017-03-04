#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileAccessWrapper.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"

namespace alinous {namespace buffer {namespace storage {





bool FileStorageEntryBuilder::__init_done = __init_static_variables();
bool FileStorageEntryBuilder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileStorageEntryBuilder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileStorageEntryBuilder::FileStorageEntryBuilder(ThreadContext* ctx) throw()  : IObject(ctx), buff(nullptr)
{
	__GC_MV(this, &(this->buff), ByteBuffer::allocate(1024, ctx), ByteBuffer);
}
void FileStorageEntryBuilder::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->buff), ByteBuffer::allocate(1024, ctx), ByteBuffer);
}
 FileStorageEntryBuilder::FileStorageEntryBuilder(int cap, ThreadContext* ctx) throw()  : IObject(ctx), buff(nullptr)
{
	__GC_MV(this, &(this->buff), ByteBuffer::allocate(cap, ctx), ByteBuffer);
}
void FileStorageEntryBuilder::__construct_impl(int cap, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->buff), ByteBuffer::allocate(cap, ctx), ByteBuffer);
}
 FileStorageEntryBuilder::~FileStorageEntryBuilder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileStorageEntryBuilder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileStorageEntryBuilder", L"~FileStorageEntryBuilder");
	__e_obj1.add(this->buff, this);
	buff = nullptr;
	if(!prepare){
		return;
	}
}
void FileStorageEntryBuilder::reset(ThreadContext* ctx) throw() 
{
	this->buff->position(0, ctx);
}
void FileStorageEntryBuilder::reloadBuffer(int cap, ThreadContext* ctx) throw() 
{
	if(this->buff != nullptr || this->buff->capacity(ctx) < cap)
	{
		__GC_MV(this, &(this->buff), ByteBuffer::allocate(cap, ctx), ByteBuffer);
	}
}
void FileStorageEntryBuilder::putLong(long long value, ThreadContext* ctx) throw() 
{
	if(this->buff->remaining(ctx) < 8)
	{
		realloc(8, ctx);
	}
	this->buff->putLong(value, ctx);
}
void FileStorageEntryBuilder::putInt(int value, ThreadContext* ctx) throw() 
{
	if(this->buff->remaining(ctx) < 4)
	{
		realloc(4, ctx);
	}
	this->buff->putInt(value, ctx);
}
void FileStorageEntryBuilder::putShort(short value, ThreadContext* ctx) throw() 
{
	if(this->buff->remaining(ctx) < 2)
	{
		realloc(2, ctx);
	}
	this->buff->putShort(value, ctx);
}
void FileStorageEntryBuilder::putChar(wchar_t value, ThreadContext* ctx) throw() 
{
	if(this->buff->remaining(ctx) < 2)
	{
		realloc(2, ctx);
	}
	this->buff->putChar(value, ctx);
}
void FileStorageEntryBuilder::putFloat(float fl, ThreadContext* ctx) throw() 
{
	if(this->buff->remaining(ctx) < 4)
	{
		realloc(4, ctx);
	}
	this->buff->putFloat(fl, ctx);
}
void FileStorageEntryBuilder::putDouble(double dbl, ThreadContext* ctx) throw() 
{
	if(this->buff->remaining(ctx) < 8)
	{
		realloc(8, ctx);
	}
	this->buff->putDouble(dbl, ctx);
}
void FileStorageEntryBuilder::putBoolean(bool value, ThreadContext* ctx) throw() 
{
	if(value)
	{
		putByte(((char)1), ctx);
	}
		else 
	{
		putByte(((char)0), ctx);
	}
}
void FileStorageEntryBuilder::putByte(char value, ThreadContext* ctx) throw() 
{
	if(this->buff->remaining(ctx) < 1)
	{
		realloc(1, ctx);
	}
	buff->put(value, ctx);
}
void FileStorageEntryBuilder::putString(String* value, ThreadContext* ctx) throw() 
{
	int length = value->length(ctx) * 2 + 4;
	if(this->buff->remaining(ctx) < length)
	{
		realloc(length, ctx);
	}
	int max = value->length(ctx);
	this->buff->putInt(max, ctx);
	for(int i = 0; i != max; ++i)
	{
		this->buff->putChar(value->charAt(i, ctx), ctx);
	}
}
FileStorageEntry* FileStorageEntryBuilder::toEntry(ThreadContext* ctx) throw() 
{
	return toEntry((long long)0, ctx);
}
FileStorageEntry* FileStorageEntryBuilder::toEntry(long long position, ThreadContext* ctx) throw() 
{
	FileStorageEntry* entry = (new(ctx) FileStorageEntry(ctx));
	return toEntry(entry, position, ctx);
}
FileStorageEntry* FileStorageEntryBuilder::toEntry(FileStorageEntry* entry, long long position, ThreadContext* ctx) throw() 
{
	int pos = this->buff->position(ctx);
	this->buff->limit(pos, ctx);
	this->buff->position(0, ctx);
	entry->position = position;
	entry->used = this->buff->limit(ctx);
	entry->oid = 0;
	__GC_MV(entry, &(entry->data), this->buff, ByteBuffer);
	return entry;
}
IArrayObjectPrimitive<char>* FileStorageEntryBuilder::toBytes(ThreadContext* ctx) throw() 
{
	buff->limit(buff->position(ctx), ctx);
	return buff->array(ctx);
}
void FileStorageEntryBuilder::realloc(int need, ThreadContext* ctx) throw() 
{
	if(this->buff->remaining(ctx) < need)
	{
		int nextCap = this->buff->capacity(ctx) * 2;
		ByteBuffer* buffLast = this->buff;
		__GC_MV(this, &(this->buff), ByteBuffer::allocate(nextCap, ctx), ByteBuffer);
		this->buff->put(buffLast->array(ctx), 0, buffLast->position(ctx), ctx);
	}
}
}}}

