#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"

namespace alinous {namespace buffer {namespace storage {





bool FileStorageEntry::__init_done = __init_static_variables();
bool FileStorageEntry::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileStorageEntry", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileStorageEntry::FileStorageEntry(ThreadContext* ctx) throw()  : IObject(ctx), position(0), oid(0), used(0), data(nullptr)
{
}
void FileStorageEntry::__construct_impl(ThreadContext* ctx) throw() 
{
}
 FileStorageEntry::~FileStorageEntry() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileStorageEntry::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileStorageEntry", L"~FileStorageEntry");
	__e_obj1.add(this->data, this);
	data = nullptr;
	if(!prepare){
		return;
	}
}
long long FileStorageEntry::getEntrySize(ThreadContext* ctx) throw() 
{
	return data->limit(ctx) + 16;
}
long long FileStorageEntry::getDataSize(ThreadContext* ctx) throw() 
{
	return data->limit(ctx);
}
bool FileStorageEntry::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<FileStorageEntry*>(obj) != 0)))
	{
		return false;
	}
	FileStorageEntry* entry = dynamic_cast<FileStorageEntry*>(obj);
	if(this->position != entry->position)
	{
		return false;
	}
	return true;
}
void FileStorageEntry::__cleanUp(ThreadContext* ctx){
}
}}}

