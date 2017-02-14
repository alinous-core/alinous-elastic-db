#include "includes.h"


namespace alinous {namespace buffer {namespace storage {





bool FileAccessWrapper::__init_done = __init_static_variables();
bool FileAccessWrapper::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileAccessWrapper", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileAccessWrapper::~FileAccessWrapper() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileAccessWrapper::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileAccessWrapper", L"~FileAccessWrapper");
	__e_obj1.add(this->segs, this);
	segs = nullptr;
	__e_obj1.add(this->buffer, this);
	buffer = nullptr;
	if(!prepare){
		return;
	}
}
FileAccessWrapper* FileAccessWrapper::init(ConcurrentFileAccess* access, long long currentPosition, long long blockSize, ThreadContext* ctx)
{
	this->fileSize = access->length(ctx);
	this->basePosition = currentPosition;
	this->position = 0;
	__GC_MV(this, &(this->segs), access->getSegments(currentPosition, blockSize, ctx), IArrayObject<MMapSegment>);
	__GC_MV(this, &(this->buffer), ByteBuffer::allocate(32, ctx), ByteBuffer);
	return this;
}
void FileAccessWrapper::close(ThreadContext* ctx) throw() 
{
	int maxLoop = this->segs->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		MMapSegment* seg = this->segs->get(i);
		seg->decUserCount(ctx);
	}
}
long long FileAccessWrapper::read(long long position, IArrayObjectPrimitive<char>* buffer, long long offset, int count, ThreadContext* ctx)
{
	long long fileRemain = this->fileSize - position;
	long long bytesToRead = fileRemain > (long long)count ? count : fileRemain;
	long long pos = position;
	long long off = offset;
	int cnt = 0;
	while(bytesToRead > (long long)0)
	{
		MMapSegment* seg = getSegment(pos, ctx);
		long long read = seg->read(pos, buffer, ((int)off), ((int)bytesToRead), ctx);
		cnt += read;
		off += read;
		pos += read;
		bytesToRead -= read;
	}
	return cnt;
}
long long FileAccessWrapper::write(long long position, IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx)
{
	int n = 0;
	long long pos = position;
	int off = offset;
	int cnt = count;
	while(n != count)
	{
		MMapSegment* seg = getSegment(pos, ctx);
		int wrote = ((int)seg->write(pos, buffer, off, cnt, ctx));
		n += wrote;
		cnt = cnt - wrote;
		off += wrote;
		pos += wrote;
	}
	return count;
}
void FileAccessWrapper::setPosition(int i, ThreadContext* ctx) throw() 
{
	this->position = i + this->basePosition;
}
void FileAccessWrapper::putShort(short value, ThreadContext* ctx)
{
	this->buffer->clear(ctx);
	this->buffer->putShort(value, ctx)->position(0, ctx);
	write(this->position, this->buffer->array(ctx), 0, 2, ctx);
	this->position += 2;
}
void FileAccessWrapper::putLong(long long value, ThreadContext* ctx)
{
	this->buffer->clear(ctx);
	this->buffer->putLong(value, ctx)->position(0, ctx);
	write(this->position, this->buffer->array(ctx), 0, 8, ctx);
	this->position += 8;
}
void FileAccessWrapper::put(IArrayObjectPrimitive<char>* data, int offset, int count, ThreadContext* ctx)
{
	this->position += write(this->position, data, offset, count, ctx);
}
short FileAccessWrapper::getShort(ThreadContext* ctx)
{
	buffer->clear(ctx);
	read(this->position, buffer->array(ctx), (long long)0, 2, ctx);
	this->position += 2;
	return buffer->getShort(0, ctx);
}
long long FileAccessWrapper::getLong(ThreadContext* ctx)
{
	buffer->clear(ctx);
	read(this->position, buffer->array(ctx), (long long)0, 8, ctx);
	this->position += 8;
	return buffer->getLong(0, ctx);
}
int FileAccessWrapper::read(IArrayObjectPrimitive<char>* buffer, long long offset, int count, ThreadContext* ctx)
{
	long long red = read(this->position, buffer, offset, count, ctx);
	this->position += red;
	return ((int)red);
}
MMapSegment* FileAccessWrapper::getSegment(long long position, ThreadContext* ctx) throw() 
{
	int maxLoop = this->segs->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		MMapSegment* seg = this->segs->get(i);
		if(seg->lastOfSegment > position)
		{
			return seg;
		}
	}
	return nullptr;
}
}}}

