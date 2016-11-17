#include "includes.h"


namespace alinous {namespace btree {





constexpr const int DoubleKey::BASE_SIZE;
bool DoubleKey::__init_done = __init_static_variables();
bool DoubleKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DoubleKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DoubleKey::DoubleKey(double v, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), value(0)
{
	this->value = v;
}
void DoubleKey::__construct_impl(double v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 DoubleKey::~DoubleKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DoubleKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DoubleKey", L"~DoubleKey");
	if(!prepare){
		return;
	}
}
int DoubleKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	return ((int)((static_cast<DoubleKey*>(this))->value - (static_cast<DoubleKey*>(another))->value));
}
bool DoubleKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<DoubleKey*>(obj))->value;
}
bool DoubleKey::equals(DoubleKey* obj, ThreadContext* ctx) throw() 
{
	return this->value == obj->value;
}
void DoubleKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeKey::TYPE_DOUBLE, ctx);
	builder->putDouble(this->value, ctx);
}
int DoubleKey::size(ThreadContext* ctx) throw() 
{
	return IBTreeKey::TYPE_SIZE + BASE_SIZE;
}
int DoubleKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

