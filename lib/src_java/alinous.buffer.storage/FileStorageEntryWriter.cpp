#include "includes.h"


namespace alinous {namespace buffer {namespace storage {





bool FileStorageEntryWriter::__init_done = __init_static_variables();
bool FileStorageEntryWriter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileStorageEntryWriter", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileStorageEntryWriter::~FileStorageEntryWriter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileStorageEntryWriter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileStorageEntryWriter", L"~FileStorageEntryWriter");
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->block, this);
	block = nullptr;
	__e_obj1.add(this->block2, this);
	block2 = nullptr;
	__e_obj1.add(this->block3, this);
	block3 = nullptr;
	if(!prepare){
		return;
	}
}
FileStorageEntryWriter* FileStorageEntryWriter::init(IFileStorage* storage, ThreadContext* ctx)
{
	__GC_MV(this, &(this->storage), storage, IFileStorage);
	__GC_MV(this, &(block), (new(ctx) FileStorageBlock(storage->getFileAccess(ctx), storage->getBLOCK_SIZE(ctx), ctx)), FileStorageBlock);
	__GC_MV(this, &(block2), (new(ctx) FileStorageBlock(storage->getFileAccess(ctx), storage->getBLOCK_SIZE(ctx), ctx)), FileStorageBlock);
	__GC_MV(this, &(block3), (new(ctx) FileStorageBlock(storage->getFileAccess(ctx), storage->getBLOCK_SIZE(ctx), ctx)), FileStorageBlock);
	return this;
}
void FileStorageEntryWriter::write(FileStorageEntry* entry, ThreadContext* ctx)
{
	storage->getGate(ctx)->close(ctx);
	if(entry->position <= (long long)0)
	{
		{
			try
			{
				insertNewEntry(entry, ctx);
			}
			catch(Throwable* e)
			{
				storage->getGate(ctx)->open(ctx);
				throw e;
			}
		}
		storage->getGate(ctx)->open(ctx);
		return;
	}
	{
		try
		{
			storage->updateEntry(entry, block, block2, block3, ctx);
		}
		catch(Throwable* e)
		{
			storage->getGate(ctx)->open(ctx);
			throw e;
		}
	}
	storage->getGate(ctx)->open(ctx);
}
void FileStorageEntryWriter::end(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->storage), nullptr, IFileStorage);
	__GC_MV(this, &(this->block), nullptr, FileStorageBlock);
	__GC_MV(this, &(this->block2), nullptr, FileStorageBlock);
}
void FileStorageEntryWriter::insertNewEntry(FileStorageEntry* entry, ThreadContext* ctx)
{
	long long totalByteSize = entry->getEntrySize(ctx);
	long long pos = storage->alloc(totalByteSize, block, block2, ctx);
	entry->position = pos;
	if(entry->oid <= (long long)0)
	{
		entry->oid = storage->newOid(ctx);
	}
	storage->updateEntry(entry, block, block2, block3, ctx);
}
}}}

