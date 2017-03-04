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
}}}

