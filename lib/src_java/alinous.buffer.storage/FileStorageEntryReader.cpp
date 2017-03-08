#include "include/global.h"


#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"

namespace alinous {namespace buffer {namespace storage {





bool FileStorageEntryReader::__init_done = __init_static_variables();
bool FileStorageEntryReader::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileStorageEntryReader", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileStorageEntryReader::FileStorageEntryReader(IFileStorage* storage, ThreadContext* ctx) throw()  : IObject(ctx), storage(nullptr), block(nullptr)
{
	__GC_MV(this, &(this->storage), storage, IFileStorage);
	__GC_MV(this, &(this->block), (new(ctx) FileStorageBlock(storage->getFileAccess(ctx), storage->getBLOCK_SIZE(ctx), ctx)), FileStorageBlock);
}
void FileStorageEntryReader::__construct_impl(IFileStorage* storage, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->storage), storage, IFileStorage);
	__GC_MV(this, &(this->block), (new(ctx) FileStorageBlock(storage->getFileAccess(ctx), storage->getBLOCK_SIZE(ctx), ctx)), FileStorageBlock);
}
 FileStorageEntryReader::~FileStorageEntryReader() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileStorageEntryReader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileStorageEntryReader", L"~FileStorageEntryReader");
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->block, this);
	block = nullptr;
	if(!prepare){
		return;
	}
}
FileStorageEntry* FileStorageEntryReader::readFirstEntry(ThreadContext* ctx)
{
	FileStorageEntry* entry = (new(ctx) FileStorageEntry(ctx));
	storage->getGate(ctx)->enter(ctx);
	{
		try
		{
			storage->getFirstEntry(entry, block, ctx);
		}
		catch(Throwable* e)
		{
			storage->getGate(ctx)->exit(ctx);
			throw e;
		}
	}
	storage->getGate(ctx)->exit(ctx);
	return entry;
}
FileStorageEntry* FileStorageEntryReader::read(long long filePointer, ThreadContext* ctx)
{
	ConcurrentGate* gate = storage->getGate(ctx);
	gate->enter(ctx);
	{
		try
		{
			FileStorageEntry* entry = (new(ctx) FileStorageEntry(ctx));
			read(filePointer, entry, ctx);
			gate->exit(ctx);
			return entry;
		}
		catch(Throwable* e)
		{
			gate->exit(ctx);
			throw e;
		}
	}
}
void FileStorageEntryReader::end(ThreadContext* ctx) throw() 
{
}
FileStorageEntry* FileStorageEntryReader::read(long long filePointer, FileStorageEntry* entry, ThreadContext* ctx)
{
	if(!this->storage->isOpened(ctx))
	{
		throw (new(ctx) IOException(ConstStr::getCNST_STR_1670(), ctx));
	}
	entry->position = filePointer;
	storage->loadBlocks(filePointer, entry, block, ctx);
	return entry;
}
void FileStorageEntryReader::__cleanUp(ThreadContext* ctx){
}
}}}

