#include "includes.h"


namespace alinous {namespace btree {





constexpr const int StringKey::BASE_SIZE;
bool StringKey::__init_done = __init_static_variables();
bool StringKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StringKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StringKey::StringKey(String* str, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), str, String);
}
void StringKey::__construct_impl(String* str, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), str, String);
}
 StringKey::~StringKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StringKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StringKey", L"~StringKey");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
}
void StringKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeKey::TYPE_STRING, ctx);
	builder->putString(value, ctx);
}
int StringKey::size(ThreadContext* ctx) throw() 
{
	return IBTreeKey::TYPE_SIZE + BASE_SIZE + (value->length(ctx) * 2);
}
int StringKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	return (static_cast<StringKey*>(this))->value->compareTo((static_cast<StringKey*>(another))->value, ctx);
}
bool StringKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value->equals(obj, ctx);
}
bool StringKey::equals(StringKey* obj, ThreadContext* ctx) throw() 
{
	return this->value->equals(obj->value, ctx);
}
int StringKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

