#include "includes.h"


namespace alinous {namespace btree {





constexpr const int IntKey::BASE_SIZE;
bool IntKey::__init_done = __init_static_variables();
bool IntKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IntKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IntKey::IntKey(int v, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), value(0)
{
	this->value = v;
}
void IntKey::__construct_impl(int v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 IntKey::~IntKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IntKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IntKey", L"~IntKey");
	if(!prepare){
		return;
	}
}
void IntKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeKey::TYPE_INT, ctx);
	builder->putInt(value, ctx);
}
int IntKey::size(ThreadContext* ctx) throw() 
{
	return IBTreeKey::TYPE_SIZE + BASE_SIZE;
}
int IntKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	return (static_cast<IntKey*>(this))->value - (static_cast<IntKey*>(another))->value;
}
bool IntKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<IntKey*>(obj))->value;
}
bool IntKey::equals(IntKey* obj, ThreadContext* ctx) throw() 
{
	return this->value == obj->value;
}
String* IntKey::toString(ThreadContext* ctx) throw() 
{
	return Integer::toString(value, ctx);
}
int IntKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

