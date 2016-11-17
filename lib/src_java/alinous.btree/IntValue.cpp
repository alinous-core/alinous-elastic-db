#include "includes.h"


namespace alinous {namespace btree {





const IntValue::ValueFetcher IntValue:: __fetcher = (IntValue::ValueFetcher(nullptr));
bool IntValue::__init_done = __init_static_variables();
bool IntValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IntValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IntValue::IntValue(int v, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), value(0)
{
	this->value = v;
}
void IntValue::__construct_impl(int v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 IntValue::~IntValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IntValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IntValue", L"~IntValue");
	if(!prepare){
		return;
	}
}
int IntValue::diskSize(ThreadContext* ctx) throw() 
{
	return IBTreeValue::TYPE_SIZE + 4;
}
void IntValue::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeValue::TYPE_INT, ctx);
	builder->putInt(value, ctx);
}
int IntValue::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
IValueFetcher* IntValue::getFetcher(ThreadContext* ctx) throw() 
{
	return IntValue::fetcher;
}
bool IntValue::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<IntValue*>(obj))->value;
}
bool IntValue::equals(IntValue* obj, ThreadContext* ctx) throw() 
{
	return this->value == obj->value;
}
}}

namespace alinous {namespace btree {





bool IntValue::ValueFetcher::__init_done = __init_static_variables();
bool IntValue::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IntValue::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IntValue::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IntValue::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* IntValue::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	IBTreeValue* value = (new(ctx) IntValue(fetcher->fetchInt(ctx), ctx));
	return value;
}
}}

