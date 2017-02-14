#include "includes.h"


namespace alinous {namespace buffer {namespace storage {





constexpr const int FileStorage::DATA_BEGIN;
bool FileStorage::__init_done = __init_static_variables();
bool FileStorage::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileStorage", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileStorage::FileStorage(DiskCacheManager* diskCache, File* f, String* mode, ThreadContext* ctx) throw()  : IObject(ctx), IFileStorage(ctx), hashCode(0), diskCache(nullptr), rfile(nullptr), file(nullptr), mode(nullptr), totalSize(0), currentPosition(0), serialOid(0), freeScanEntry(0), numBlocks(0), BLOCK_SIZE(0), opened(0), allocationLock(nullptr), gate(nullptr)
{
	__GC_MV(this, &(this->diskCache), diskCache, DiskCacheManager);
	__GC_MV(this, &(this->file), f, File);
	__GC_MV(this, &(this->mode), mode, String);
	__GC_MV(this, &(this->allocationLock), (new(ctx) Mutex(ctx)), Mutex);
	this->totalSize = 0;
	if(this->file->exists(ctx))
	{
		this->totalSize = this->file->length(ctx);
	}
	__GC_MV(this, &(this->gate), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
	this->hashCode = this->file->getAbsolutePath(ctx)->hashCode(ctx);
}
void FileStorage::__construct_impl(DiskCacheManager* diskCache, File* f, String* mode, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->diskCache), diskCache, DiskCacheManager);
	__GC_MV(this, &(this->file), f, File);
	__GC_MV(this, &(this->mode), mode, String);
	__GC_MV(this, &(this->allocationLock), (new(ctx) Mutex(ctx)), Mutex);
	this->totalSize = 0;
	if(this->file->exists(ctx))
	{
		this->totalSize = this->file->length(ctx);
	}
	__GC_MV(this, &(this->gate), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
	this->hashCode = this->file->getAbsolutePath(ctx)->hashCode(ctx);
}
 FileStorage::~FileStorage() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileStorage::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileStorage", L"~FileStorage");
	__e_obj1.add(this->diskCache, this);
	diskCache = nullptr;
	__e_obj1.add(this->rfile, this);
	rfile = nullptr;
	__e_obj1.add(this->file, this);
	file = nullptr;
	__e_obj1.add(this->mode, this);
	mode = nullptr;
	__e_obj1.add(this->allocationLock, this);
	allocationLock = nullptr;
	__e_obj1.add(this->gate, this);
	gate = nullptr;
	if(!prepare){
		return;
	}
}
bool FileStorage::isCreated(ThreadContext* ctx) throw() 
{
	return this->file->exists(ctx);
}
FileStorageEntryWriter* FileStorage::getWriter(ThreadContext* ctx)
{
	FileStorageEntryWriter* writer = (new(ctx) FileStorageEntryWriter(ctx))->init(this, ctx);
	return writer;
}
FileStorageEntryReader* FileStorage::getReader(ThreadContext* ctx)
{
	FileStorageEntryReader* reader = (new(ctx) FileStorageEntryReader(this, ctx));
	return reader;
}
void FileStorage::flush(IArrayObjectPrimitive<char>* data, int len, long long startFilePosition, ThreadContext* ctx) throw() 
{
}
long long FileStorage::alloc(long long totalBytes, FileStorageBlock* block, FileStorageBlock* block2, ThreadContext* ctx)
{
	long long BLOCK_DATA_SIZE_MASK = block->BLOCK_DATA_SIZE - 1;
	long long numBlocks = (totalBytes & BLOCK_DATA_SIZE_MASK) == (long long)0 ? totalBytes / block->BLOCK_DATA_SIZE : totalBytes / block->BLOCK_DATA_SIZE + 1;
	this->allocationLock->lock(ctx);
	if(numBlocks == (long long)1)
	{
		long long ret = allocSingleBlockEntry(totalBytes, block, ctx);
		this->allocationLock->unlock(ctx);
		return ret;
	}
	long long alloced = 0;
	long long allocBytes = totalBytes;
	long long pos = this->freeScanEntry;
	long long firstBlock = 0;
	long long lastBlock = 0;
	if(pos + block->BLOCK_SIZE > this->totalSize)
	{
		long long newLength = this->totalSize * 2;
		this->rfile->setLength(newLength, ctx);
		this->totalSize = newLength;
	}
	while(alloced != numBlocks)
	{
		block->loadBlock(this, pos, ctx);
		if(block->isFree(ctx) && firstBlock == (long long)0)
		{
			allocBytes -= block->BLOCK_DATA_SIZE;
			block->usedBytes = ((short)block->BLOCK_DATA_SIZE);
			block->next = 0;
			block->syncBlockHeader(this, ctx);
			block->write2Disk(ctx);
			firstBlock = pos;
			lastBlock = pos;
			alloced ++ ;
		}
				else 
		{
			if(block->isFree(ctx))
			{
				if(allocBytes >= block->BLOCK_DATA_SIZE)
				{
					allocBytes -= block->BLOCK_DATA_SIZE;
					block->usedBytes = ((short)block->BLOCK_DATA_SIZE);
				}
								else 
				{
					block->usedBytes = ((short)allocBytes);
					allocBytes = 0;
				}
				block->next = 0;
				block->syncBlockHeader(this, ctx);
				block->write2Disk(ctx);
				block2->loadBlock(this, lastBlock, ctx);
				block2->next = pos;
				block2->syncBlockHeader(this, ctx);
				block2->write2Disk(ctx);
				lastBlock = pos;
				alloced ++ ;
			}
						else 
			{
				block->write2Disk(ctx);
			}
		}
		pos = block->nextBlockPosition(ctx);
		if(pos + block->BLOCK_SIZE > this->totalSize)
		{
			long long newLength = this->totalSize * 2;
			this->rfile->setLength(newLength, ctx);
			this->totalSize = newLength;
		}
	}
	this->freeScanEntry = pos + block->BLOCK_SIZE;
	this->numBlocks += alloced;
	syncStatus(ctx);
	this->allocationLock->unlock(ctx);
	return firstBlock;
}
void FileStorage::updateEntry(FileStorageEntry* entry, FileStorageBlock* block, FileStorageBlock* block2, FileStorageBlock* block3, ThreadContext* ctx)
{
	long long dataSizeRemain = entry->getEntrySize(ctx);
	entry->data->position(0, ctx);
	IArrayObjectPrimitive<char>* array = entry->data->array(ctx);
	int offset = 0;
	block->loadBlock(this, entry->position, ctx);
	block->resetSize(ctx);
	block->writeLongData(this, 0, entry->oid, ctx);
	dataSizeRemain -= 8;
	block->writeLongData(this, 8, entry->getDataSize(ctx), ctx);
	dataSizeRemain -= 8;
	int firstRemainDataCap = ((int)(block->BLOCK_DATA_SIZE - 16));
	int firstWriteSize = ((int)(dataSizeRemain > (long long)firstRemainDataCap ? firstRemainDataCap : dataSizeRemain));
	block->writeData(this, (long long)16, array, offset, firstWriteSize, ctx);
	offset += firstWriteSize;
	dataSizeRemain -= firstWriteSize;
	block->syncBlockHeader(this, ctx);
	while(dataSizeRemain != (long long)0)
	{
		if(!block->hasNext(ctx))
		{
			long long totalBytes = dataSizeRemain;
			short lastUsed = block->usedBytes;
			block->next = alloc(totalBytes, block2, block3, ctx);
			block->usedBytes = lastUsed;
			block->syncBlockHeader(this, ctx);
			block->write2Disk(ctx);
		}
				else 
		{
			block->write2Disk(ctx);
		}
		block->loadChildNextBlock(this, ctx);
		block->usedBytes = 0;
		firstWriteSize = ((int)(dataSizeRemain > block->BLOCK_DATA_SIZE ? block->BLOCK_DATA_SIZE : dataSizeRemain));
		block->writeData(this, (long long)0, array, offset, firstWriteSize, ctx);
		block->syncBlockHeader(this, ctx);
		offset += firstWriteSize;
		dataSizeRemain -= firstWriteSize;
	}
	block->write2Disk(ctx);
	if(block->hasNext(ctx))
	{
		long long removePos = block->next;
		block->loadBlock(this, removePos, ctx);
		block->next = 0;
		block->syncBlockHeader(this, ctx);
		block->write2Disk(ctx);
		removeEntryBlocks(removePos, block, ctx);
	}
}
void FileStorage::removeEntryBlocks(long long position, FileStorageBlock* workBlock, ThreadContext* ctx)
{
	if(position < this->freeScanEntry)
	{
		this->freeScanEntry = position;
		syncStatus(ctx);
	}
	workBlock->loadBlock(this, position, ctx);
	long long next = workBlock->next;
	workBlock->next = 0;
	workBlock->usedBytes = 0;
	workBlock->syncBlockHeader(this, ctx);
	workBlock->write2Disk(ctx);
	while(next != (long long)0)
	{
		workBlock->loadBlock(this, next, ctx);
		next = workBlock->next;
		workBlock->next = 0;
		workBlock->usedBytes = 0;
		workBlock->syncBlockHeader(this, ctx);
		workBlock->write2Disk(ctx);
	}
}
void FileStorage::getFirstEntry(FileStorageEntry* entry, FileStorageBlock* workBlock, ThreadContext* ctx)
{
	workBlock->loadBlock(this, (long long)DATA_BEGIN, ctx);
	while(workBlock->isFree(ctx))
	{
		workBlock->closeWrapper(ctx);
		workBlock->loadNextBlock(this, ctx);
	}
	workBlock->closeWrapper(ctx);
	loadBlocks(workBlock->getCurrentPosition(ctx), entry, workBlock, ctx);
}
void FileStorage::loadBlocks(long long position, FileStorageEntry* entry, FileStorageBlock* workBlock, ThreadContext* ctx)
{
	workBlock->loadBlock(this, position, ctx);
	entry->position = position;
	entry->oid = workBlock->readLong(this, (long long)0, ctx);
	entry->used = workBlock->readLong(this, (long long)8, ctx);
	if(entry->data == nullptr || entry->data->capacity(ctx) < (int)entry->used)
	{
		__GC_MV(entry, &(entry->data), ByteBuffer::allocate(((int)entry->used), ctx), ByteBuffer);
	}
	entry->data->clear(ctx);
	long long arrayOffset = 0;
	arrayOffset += workBlock->read(this, (long long)16, entry->data, (long long)0, ctx);
	while(workBlock->hasNext(ctx))
	{
		workBlock->closeWrapper(ctx);
		workBlock->loadChildNextBlock(this, ctx);
		arrayOffset += workBlock->read(this, (long long)0, entry->data, arrayOffset, ctx);
	}
	workBlock->closeWrapper(ctx);
}
ConcurrentFileAccess* FileStorage::getFileAccess(ThreadContext* ctx) throw() 
{
	return rfile;
}
void FileStorage::syncStatus(ThreadContext* ctx)
{
	ByteBuffer* buff = ByteBuffer::allocate(40, ctx);
	buff->putLong(this->totalSize, ctx);
	buff->putLong(this->serialOid, ctx);
	buff->putLong(this->numBlocks, ctx);
	buff->putLong(this->freeScanEntry, ctx);
	buff->putLong(this->BLOCK_SIZE, ctx);
	this->rfile->write((long long)0, buff->array(ctx), 0, 40, ctx);
	this->currentPosition = this->rfile->getFilePointer(ctx);
}
bool FileStorage::isOpened(ThreadContext* ctx) throw() 
{
	return this->opened;
}
void FileStorage::open(ThreadContext* ctx)
{
	__GC_MV(this, &(this->rfile), (new(ctx) ConcurrentFileAccess(this->diskCache, this->file, this->mode, ctx)), ConcurrentFileAccess);
	this->opened = true;
	this->currentPosition = this->rfile->getFilePointer(ctx);
	IArrayObjectPrimitive<char>* bytes = ArrayAllocatorPrimitive<char>::allocatep(ctx, 40);
	this->rfile->read((long long)0, bytes, ctx);
	ByteBuffer* buff = ByteBuffer::wrap(bytes, ctx);
	this->totalSize = buff->getLong(ctx);
	this->serialOid = buff->getLong(ctx);
	this->numBlocks = buff->getLong(ctx);
	this->freeScanEntry = buff->getLong(ctx);
	this->BLOCK_SIZE = buff->getLong(ctx);
	this->currentPosition = this->rfile->getFilePointer(ctx);
}
void FileStorage::createStorage(long long capacity, long long BLOCK_SIZE, ThreadContext* ctx)
{
	if(this->opened)
	{
		close(ctx);
	}
	if(this->file->exists(ctx))
	{
		this->file->_delete(ctx);
	}
	{
		try
		{
			__GC_MV(this, &(this->rfile), (new(ctx) ConcurrentFileAccess(this->diskCache, this->file, this->mode, ctx)), ConcurrentFileAccess);
			this->rfile->setLength(capacity, ctx);
			ByteBuffer* buff = ByteBuffer::allocate(40, ctx);
			buff->putLong(capacity, ctx);
			buff->putLong((long long)0, ctx);
			buff->putLong((long long)0, ctx);
			buff->putLong((long long)FileStorage::DATA_BEGIN, ctx);
			buff->putLong(BLOCK_SIZE, ctx);
			this->rfile->write((long long)0, buff->array(ctx), 0, 40, ctx);
			this->currentPosition = this->rfile->getFilePointer(ctx);
			totalSize = capacity;
			freeScanEntry = FileStorage::DATA_BEGIN;
			this->BLOCK_SIZE = BLOCK_SIZE;
		}
		catch(Throwable* e)
		{
			close(ctx);
			throw e;
		}
	}
	close(ctx);
}
void FileStorage::close(ThreadContext* ctx) throw() 
{
	{
		try
		{
			syncStatus(ctx);
			this->rfile->close(ctx);
			__GC_MV(this, &(this->rfile), nullptr, ConcurrentFileAccess);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
		}
	}
	this->opened = false;
}
long long FileStorage::getTotalSize(ThreadContext* ctx) throw() 
{
	return this->totalSize;
}
long long FileStorage::getCurrentPosition(ThreadContext* ctx) throw() 
{
	return currentPosition;
}
long long FileStorage::getlastOid(ThreadContext* ctx) throw() 
{
	return this->serialOid - 1;
}
long long FileStorage::newOid(ThreadContext* ctx) throw() 
{
	return ++this->serialOid;
}
long long FileStorage::getNextOid(ThreadContext* ctx) throw() 
{
	return this->serialOid + 1;
}
long long FileStorage::getFreeScanEntry(ThreadContext* ctx) throw() 
{
	return freeScanEntry;
}
long long FileStorage::getNumBlocks(ThreadContext* ctx) throw() 
{
	return numBlocks;
}
long long FileStorage::getBLOCK_SIZE(ThreadContext* ctx) throw() 
{
	return BLOCK_SIZE;
}
ConcurrentGate* FileStorage::getGate(ThreadContext* ctx) throw() 
{
	return gate;
}
void FileStorage::writeLong(long long value, ThreadContext* ctx)
{
	this->rfile->writeLong(value, ctx);
	this->totalSize += SIZE_LONG;
	this->currentPosition += SIZE_LONG;
}
void FileStorage::writeByte(char value, ThreadContext* ctx)
{
	this->rfile->write((int)value, ctx);
	this->totalSize += SIZE_BYTE;
	this->currentPosition += SIZE_BYTE;
}
void FileStorage::writeBytes(IArrayObjectPrimitive<char>* values, ThreadContext* ctx)
{
	this->rfile->write(values, ctx);
	this->totalSize += values->length;
	this->currentPosition += values->length;
}
IArrayObjectPrimitive<char>* FileStorage::readBytes(int len, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* by = ArrayAllocatorPrimitive<char>::allocatep(ctx, len);
	this->rfile->read(by, 0, len, ctx);
	this->totalSize += SIZE_BYTE * len;
	this->currentPosition += SIZE_BYTE * len;
	return by;
}
char FileStorage::readByte(ThreadContext* ctx)
{
	char value = this->rfile->readByte(ctx);
	this->totalSize += SIZE_BYTE;
	this->currentPosition += SIZE_BYTE;
	return value;
}
long long FileStorage::readLong(ThreadContext* ctx)
{
	long long value = this->rfile->readLong(ctx);
	this->totalSize += SIZE_LONG;
	this->currentPosition += SIZE_LONG;
	return value;
}
void FileStorage::seek(long long position, ThreadContext* ctx)
{
	this->rfile->seek(position, ctx);
	this->currentPosition = this->rfile->getFilePointer(ctx);
}
long long FileStorage::allocSingleBlockEntry(long long totalBytes, FileStorageBlock* block, ThreadContext* ctx)
{
	long long pos = this->freeScanEntry;
	long long firstBlock = 0;
	while(true)
	{
		block->loadBlock(this, pos, ctx);
		if(block->isFree(ctx))
		{
			block->usedBytes = ((short)totalBytes);
			block->next = 0;
			block->syncBlockHeader(this, ctx);
			block->write2Disk(ctx);
			firstBlock = pos;
			break ;
		}
		block->closeWrapper(ctx);
		pos = block->nextBlockPosition(ctx);
		if(pos + block->BLOCK_SIZE > this->totalSize)
		{
			long long newLength = this->totalSize * 2;
			this->rfile->setLength(newLength, ctx);
		}
	}
	pos = block->nextBlockPosition(ctx);
	if(pos + block->BLOCK_SIZE > this->totalSize)
	{
		long long newLength = this->totalSize * 2;
		this->rfile->setLength(newLength, ctx);
		this->totalSize = newLength;
	}
	this->freeScanEntry = pos;
	this->numBlocks ++ ;
	syncStatus(ctx);
	return firstBlock;
}
}}}

