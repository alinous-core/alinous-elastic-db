#include "includes.h"


namespace alinous {namespace remote {namespace socket {





bool NetworkBinaryBuffer::__init_done = __init_static_variables();
bool NetworkBinaryBuffer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NetworkBinaryBuffer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NetworkBinaryBuffer::NetworkBinaryBuffer(int capacity, ThreadContext* ctx) throw()  : IObject(ctx), buff(nullptr), lastPos(0)
{
	__GC_MV(this, &(this->buff), ByteBuffer::allocate(capacity, ctx), ByteBuffer);
	this->buff->clear(ctx);
	int tmp = 0;
	this->buff->putInt(tmp, ctx);
}
void NetworkBinaryBuffer::__construct_impl(int capacity, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->buff), ByteBuffer::allocate(capacity, ctx), ByteBuffer);
	this->buff->clear(ctx);
	int tmp = 0;
	this->buff->putInt(tmp, ctx);
}
 NetworkBinaryBuffer::NetworkBinaryBuffer(IArrayObjectPrimitive<char>* src, ThreadContext* ctx) throw()  : IObject(ctx), buff(nullptr), lastPos(0)
{
	__GC_MV(this, &(this->buff), ByteBuffer::wrap(src, ctx), ByteBuffer);
	this->buff->clear(ctx);
}
void NetworkBinaryBuffer::__construct_impl(IArrayObjectPrimitive<char>* src, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->buff), ByteBuffer::wrap(src, ctx), ByteBuffer);
	this->buff->clear(ctx);
}
 NetworkBinaryBuffer::~NetworkBinaryBuffer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NetworkBinaryBuffer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NetworkBinaryBuffer", L"~NetworkBinaryBuffer");
	__e_obj1.add(this->buff, this);
	buff = nullptr;
	if(!prepare){
		return;
	}
}
IArrayObjectPrimitive<char>* NetworkBinaryBuffer::toBinary(ThreadContext* ctx) throw() 
{
	int pos = this->buff->position(ctx);
	this->buff->position(0, ctx);
	this->buff->putInt(pos, ctx);
	this->buff->position(0, ctx);
	this->lastPos = pos;
	return buff->array(ctx);
}
int NetworkBinaryBuffer::getPutSize(ThreadContext* ctx) throw() 
{
	return this->lastPos;
}
void NetworkBinaryBuffer::putByte(char b, ThreadContext* ctx) throw() 
{
	extend(1, ctx);
	this->buff->put(b, ctx);
}
char NetworkBinaryBuffer::getByte(ThreadContext* ctx) throw() 
{
	return this->buff->get(ctx);
}
void NetworkBinaryBuffer::putBytes(IArrayObjectPrimitive<char>* src, int start, int count, ThreadContext* ctx) throw() 
{
	extend(count, ctx);
	this->buff->put(src, start, count, ctx);
}
void NetworkBinaryBuffer::putBytes(IArrayObjectPrimitive<char>* src, ThreadContext* ctx) throw() 
{
	putBytes(src, 0, src->length, ctx);
}
IArrayObjectPrimitive<char>* NetworkBinaryBuffer::getBytes(int count, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<char>* dst = ArrayAllocatorPrimitive<char>::allocatep(ctx, count);
	this->buff->get(dst, ctx);
	return dst;
}
void NetworkBinaryBuffer::putChar(wchar_t value, ThreadContext* ctx) throw() 
{
	extend(2, ctx);
	this->buff->putChar(value, ctx);
}
wchar_t NetworkBinaryBuffer::getChar(ThreadContext* ctx) throw() 
{
	return this->buff->getChar(ctx);
}
void NetworkBinaryBuffer::putShort(short value, ThreadContext* ctx) throw() 
{
	extend(2, ctx);
	this->buff->putShort(value, ctx);
}
short NetworkBinaryBuffer::getShort(ThreadContext* ctx) throw() 
{
	return this->getShort(ctx);
}
void NetworkBinaryBuffer::putInt(int value, ThreadContext* ctx) throw() 
{
	extend(4, ctx);
	this->buff->putInt(value, ctx);
}
int NetworkBinaryBuffer::getInt(ThreadContext* ctx) throw() 
{
	return this->buff->getInt(ctx);
}
void NetworkBinaryBuffer::putLong(long long value, ThreadContext* ctx) throw() 
{
	extend(8, ctx);
	this->buff->putLong(value, ctx);
}
long long NetworkBinaryBuffer::getLong(ThreadContext* ctx) throw() 
{
	return this->buff->getLong(ctx);
}
void NetworkBinaryBuffer::putString(String* str, ThreadContext* ctx) throw() 
{
	int length = str->length(ctx);
	int expcap = 4 + length * 2;
	extend(expcap, ctx);
	this->buff->putInt(length, ctx);
	int maxLoop = str->length(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		wchar_t ch = str->charAt(i, ctx);
		this->buff->putChar(ch, ctx);
	}
}
String* NetworkBinaryBuffer::getString(ThreadContext* ctx) throw() 
{
	StringBuffer* strBuff = (new(ctx) StringBuffer(ctx));
	int maxLoop = this->buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		wchar_t ch = this->buff->getChar(ctx);
		strBuff->append(ch, ctx);
	}
	return strBuff->toString(ctx);
}
void NetworkBinaryBuffer::clear(ThreadContext* ctx) throw() 
{
	this->buff->clear(ctx);
}
void NetworkBinaryBuffer::extend(int length, ThreadContext* ctx) throw() 
{
	int remain = this->buff->remaining(ctx);
	if(remain < length)
	{
		int cap = this->buff->capacity(ctx);
		cap = cap * 2;
		IArrayObjectPrimitive<char>* bytes = this->buff->array(ctx);
		int len = this->buff->position(ctx);
		__GC_MV(this, &(this->buff), ByteBuffer::allocate(cap, ctx), ByteBuffer);
		this->buff->clear(ctx);
		this->buff->put(bytes, 0, len, ctx);
	}
}
}}}

