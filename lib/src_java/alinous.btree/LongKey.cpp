#include "includes.h"


namespace alinous {namespace btree {





constexpr const int LongKey::BASE_SIZE;
bool LongKey::__init_done = __init_static_variables();
bool LongKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LongKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LongKey::LongKey(long long v, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), value(0)
{
	this->value = v;
}
void LongKey::__construct_impl(long long v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 LongKey::~LongKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LongKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LongKey", L"~LongKey");
	if(!prepare){
		return;
	}
}
void LongKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeKey::TYPE_LONG, ctx);
	builder->putLong(value, ctx);
}
int LongKey::size(ThreadContext* ctx) throw() 
{
	return IBTreeKey::TYPE_SIZE + BASE_SIZE;
}
int LongKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	long long diff = (static_cast<LongKey*>(this))->value - (static_cast<LongKey*>(another))->value;
	if(diff == (long long)0)
	{
		return 0;
	}
		else 
	{
		return diff > (long long)0 ? 1 : -1;
	}
}
bool LongKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<LongKey*>(obj))->value;
}
bool LongKey::equals(LongKey* obj, ThreadContext* ctx) throw() 
{
	return this->value == obj->value;
}
String* LongKey::toString(ThreadContext* ctx) throw() 
{
	return Long::toString(value, ctx);
}
int LongKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

