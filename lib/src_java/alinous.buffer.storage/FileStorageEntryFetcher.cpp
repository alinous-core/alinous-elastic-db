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





bool FileStorageEntryFetcher::__init_done = __init_static_variables();
bool FileStorageEntryFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileStorageEntryFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileStorageEntryFetcher::FileStorageEntryFetcher(FileStorageEntry* entry, ThreadContext* ctx) throw()  : IObject(ctx), buff(nullptr), position(0), oid(0)
{
	__GC_MV(this, &(this->buff), entry->data, ByteBuffer);
	this->buff->position(0, ctx);
	this->position = entry->position;
	this->oid = entry->oid;
}
void FileStorageEntryFetcher::__construct_impl(FileStorageEntry* entry, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->buff), entry->data, ByteBuffer);
	this->buff->position(0, ctx);
	this->position = entry->position;
	this->oid = entry->oid;
}
 FileStorageEntryFetcher::FileStorageEntryFetcher(IArrayObjectPrimitive<char>* array, ThreadContext* ctx) throw()  : IObject(ctx), buff(nullptr), position(0), oid(0)
{
	__GC_MV(this, &(this->buff), ByteBuffer::wrap(array, ctx), ByteBuffer);
}
void FileStorageEntryFetcher::__construct_impl(IArrayObjectPrimitive<char>* array, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->buff), ByteBuffer::wrap(array, ctx), ByteBuffer);
}
 FileStorageEntryFetcher::FileStorageEntryFetcher(ThreadContext* ctx) throw()  : IObject(ctx), buff(nullptr), position(0), oid(0)
{
	__GC_MV(this, &(this->buff), nullptr, ByteBuffer);
}
void FileStorageEntryFetcher::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->buff), nullptr, ByteBuffer);
}
 FileStorageEntryFetcher::~FileStorageEntryFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileStorageEntryFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileStorageEntryFetcher", L"~FileStorageEntryFetcher");
	__e_obj1.add(this->buff, this);
	buff = nullptr;
	if(!prepare){
		return;
	}
}
void FileStorageEntryFetcher::load(FileStorageEntry* entry, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->buff), entry->data, ByteBuffer);
	this->buff->position(0, ctx);
}
void FileStorageEntryFetcher::close(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->buff), nullptr, ByteBuffer);
}
long long FileStorageEntryFetcher::fetchLong(ThreadContext* ctx) throw() 
{
	return this->buff->getLong(ctx);
}
int FileStorageEntryFetcher::fetchInt(ThreadContext* ctx) throw() 
{
	return this->buff->getInt(ctx);
}
short FileStorageEntryFetcher::fetchShort(ThreadContext* ctx) throw() 
{
	return buff->getShort(ctx);
}
wchar_t FileStorageEntryFetcher::fetchChar(ThreadContext* ctx) throw() 
{
	return buff->getChar(ctx);
}
char FileStorageEntryFetcher::fetchByte(ThreadContext* ctx) throw() 
{
	return this->buff->get(ctx);
}
bool FileStorageEntryFetcher::fetchBoolean(ThreadContext* ctx) throw() 
{
	return !(fetchByte(ctx) == (char)0);
}
float FileStorageEntryFetcher::fetchFloat(ThreadContext* ctx) throw() 
{
	return this->buff->getFloat(ctx);
}
double FileStorageEntryFetcher::fetchDouble(ThreadContext* ctx) throw() 
{
	return this->buff->getDouble(ctx);
}
String* FileStorageEntryFetcher::fetchString(ThreadContext* ctx) throw() 
{
	int charength = buff->getInt(ctx);
	StringBuffer* str = (new(ctx) StringBuffer(ctx));
	for(int i = 0; i != charength; i ++ )
	{
		wchar_t ch = this->buff->getChar(ctx);
		str->append(ch, ctx);
	}
	return str->toString(ctx);
}
long long FileStorageEntryFetcher::getPosition(ThreadContext* ctx) throw() 
{
	return position;
}
long long FileStorageEntryFetcher::getOid(ThreadContext* ctx) throw() 
{
	return oid;
}
}}}

