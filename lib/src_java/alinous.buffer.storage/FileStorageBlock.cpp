#include "includes.h"


namespace alinous {namespace buffer {namespace storage {





bool FileStorageBlock::__init_done = __init_static_variables();
bool FileStorageBlock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileStorageBlock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileStorageBlock::FileStorageBlock(ConcurrentFileAccess* access, long long BLOCK_SIZE, ThreadContext* ctx) throw()  : IObject(ctx), BLOCK_SIZE(128), BLOCK_HEADER_OFFSET(10), BLOCK_DATA_SIZE(118), usedBytes(0), next(0), access(nullptr), wraapper(nullptr), currentPosition(0)
{
	this->BLOCK_SIZE = BLOCK_SIZE;
	this->BLOCK_DATA_SIZE = this->BLOCK_SIZE - BLOCK_HEADER_OFFSET;
	__GC_MV(this, &(this->access), access, ConcurrentFileAccess);
}
void FileStorageBlock::__construct_impl(ConcurrentFileAccess* access, long long BLOCK_SIZE, ThreadContext* ctx) throw() 
{
	this->BLOCK_SIZE = BLOCK_SIZE;
	this->BLOCK_DATA_SIZE = this->BLOCK_SIZE - BLOCK_HEADER_OFFSET;
	__GC_MV(this, &(this->access), access, ConcurrentFileAccess);
}
 FileStorageBlock::~FileStorageBlock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileStorageBlock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileStorageBlock", L"~FileStorageBlock");
	__e_obj1.add(this->access, this);
	access = nullptr;
	__e_obj1.add(this->wraapper, this);
	wraapper = nullptr;
	if(!prepare){
		return;
	}
}
void FileStorageBlock::loadBlock(FileStorage* storage, long long position, ThreadContext* ctx)
{
	this->currentPosition = position;
	__GC_MV(this, &(this->wraapper), (new(ctx) FileAccessWrapper(ctx))->init(access, this->currentPosition, this->BLOCK_SIZE, ctx), FileAccessWrapper);
	this->wraapper->setPosition(0, ctx);
	this->usedBytes = this->wraapper->getShort(ctx);
	this->next = this->wraapper->getLong(ctx);
}
void FileStorageBlock::closeWrapper(ThreadContext* ctx) throw() 
{
	this->wraapper->close(ctx);
	__GC_MV(this, &(this->wraapper), nullptr, FileAccessWrapper);
}
void FileStorageBlock::write2Disk(ThreadContext* ctx)
{
	this->wraapper->close(ctx);
	__GC_MV(this, &(this->wraapper), nullptr, FileAccessWrapper);
}
void FileStorageBlock::close(ThreadContext* ctx) throw() 
{
	this->wraapper->close(ctx);
	__GC_MV(this, &(this->wraapper), nullptr, FileAccessWrapper);
}
void FileStorageBlock::resetSize(ThreadContext* ctx) throw() 
{
	this->usedBytes = 0;
}
void FileStorageBlock::syncBlockHeader(FileStorage* storage, ThreadContext* ctx)
{
	this->wraapper->setPosition(0, ctx);
	this->wraapper->putShort(usedBytes, ctx);
	this->wraapper->putLong(next, ctx);
}
void FileStorageBlock::writeData(FileStorage* storage, long long positionOffset, IArrayObjectPrimitive<char>* data, int offset, int count, ThreadContext* ctx)
{
	this->wraapper->setPosition(((int)(BLOCK_HEADER_OFFSET + positionOffset)), ctx);
	this->wraapper->put(data, offset, count, ctx);
	this->usedBytes += count;
}
void FileStorageBlock::writeLongData(FileStorage* storage, int offset, long long value, ThreadContext* ctx)
{
	this->wraapper->setPosition(((int)(BLOCK_HEADER_OFFSET + offset)), ctx);
	this->wraapper->putLong(value, ctx);
	this->usedBytes += 8;
}
void FileStorageBlock::writeShortData(FileStorage* storage, int offset, short value, ThreadContext* ctx)
{
	this->wraapper->setPosition(((int)(BLOCK_HEADER_OFFSET + offset)), ctx);
	this->wraapper->putShort(value, ctx);
	this->usedBytes += 2;
}
long long FileStorageBlock::readLong(FileStorage* storage, long long positionOffset, ThreadContext* ctx)
{
	this->wraapper->setPosition(((int)(BLOCK_HEADER_OFFSET + positionOffset)), ctx);
	return this->wraapper->getLong(ctx);
}
short FileStorageBlock::readShort(FileStorage* storage, long long positionOffset, ThreadContext* ctx)
{
	this->wraapper->setPosition(((int)(BLOCK_HEADER_OFFSET + positionOffset)), ctx);
	return this->wraapper->getShort(ctx);
}
void FileStorageBlock::read(FileStorage* storage, long long positionOffset, ByteBuffer* bbuff, ThreadContext* ctx)
{
	this->wraapper->setPosition(((int)(BLOCK_HEADER_OFFSET + positionOffset)), ctx);
	IArrayObjectPrimitive<char>* array = bbuff->array(ctx);
	this->wraapper->read(array, 0, ((int)(this->usedBytes - positionOffset)), ctx);
}
bool FileStorageBlock::isFree(ThreadContext* ctx) throw() 
{
	return usedBytes == (short)0;
}
bool FileStorageBlock::hasNext(ThreadContext* ctx) throw() 
{
	return next != (long long)0;
}
void FileStorageBlock::loadChildNextBlock(FileStorage* storage, ThreadContext* ctx)
{
	loadBlock(storage, this->next, ctx);
}
void FileStorageBlock::loadNextBlock(FileStorage* storage, ThreadContext* ctx)
{
	long long next = nextBlockPosition(ctx);
	loadBlock(storage, next, ctx);
}
long long FileStorageBlock::nextBlockPosition(ThreadContext* ctx) throw() 
{
	return this->currentPosition + BLOCK_SIZE;
}
long long FileStorageBlock::getCurrentPosition(ThreadContext* ctx) throw() 
{
	return currentPosition;
}
void FileStorageBlock::setCurrentPosition(long long currentPosition, ThreadContext* ctx) throw() 
{
	this->currentPosition = currentPosition;
}
int FileStorageBlock::necessaryBlocks(long long bytes, long long BLOCK_SIZE, ThreadContext* ctx) throw() 
{
	long long BLOCK_SIZE_MASK = BLOCK_SIZE - 1;
	int size = (bytes & BLOCK_SIZE_MASK) == (long long)0 ? ((int)(bytes / BLOCK_SIZE)) : ((int)(bytes / BLOCK_SIZE + 1));
	return size;
}
}}}

