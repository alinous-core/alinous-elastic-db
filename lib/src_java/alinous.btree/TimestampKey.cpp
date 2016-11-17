#include "includes.h"


namespace alinous {namespace btree {





constexpr const int TimestampKey::BASE_SIZE;
bool TimestampKey::__init_done = __init_static_variables();
bool TimestampKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimestampKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimestampKey::TimestampKey(long long mills, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), value(0)
{
	this->value = mills;
}
void TimestampKey::__construct_impl(long long mills, ThreadContext* ctx) throw() 
{
	this->value = mills;
}
 TimestampKey::~TimestampKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimestampKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TimestampKey", L"~TimestampKey");
	if(!prepare){
		return;
	}
}
int TimestampKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	long long diff = (static_cast<TimestampKey*>(this))->value - (static_cast<TimestampKey*>(another))->value;
	if(diff == (long long)0)
	{
		return 0;
	}
		else 
	{
		return diff > (long long)0 ? 1 : -1;
	}
}
bool TimestampKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<TimestampKey*>(obj))->value;
}
bool TimestampKey::equals(TimestampKey* obj, ThreadContext* ctx) throw() 
{
	return this->value == obj->value;
}
void TimestampKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeKey::TYPE_TIMESTAMP, ctx);
	builder->putLong(value, ctx);
}
int TimestampKey::size(ThreadContext* ctx) throw() 
{
	return IBTreeKey::TYPE_SIZE + BASE_SIZE;
}
String* TimestampKey::toString(ThreadContext* ctx) throw() 
{
	return Long::toString(value, ctx);
}
int TimestampKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

