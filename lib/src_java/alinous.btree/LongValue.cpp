#include "includes.h"


namespace alinous {namespace btree {





const LongValue::ValueFetcher LongValue:: __fetcher = (LongValue::ValueFetcher(nullptr));
bool LongValue::__init_done = __init_static_variables();
bool LongValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LongValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LongValue::LongValue(long long v, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), value(0)
{
	this->value = v;
}
void LongValue::__construct_impl(long long v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 LongValue::~LongValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LongValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LongValue", L"~LongValue");
	if(!prepare){
		return;
	}
}
int LongValue::diskSize(ThreadContext* ctx) throw() 
{
	return IBTreeValue::TYPE_SIZE + 8;
}
void LongValue::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeValue::TYPE_LONG, ctx);
	builder->putLong(value, ctx);
}
bool LongValue::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<LongValue*>(obj))->value;
}
bool LongValue::equals(LongValue* obj, ThreadContext* ctx) throw() 
{
	return this->value == obj->value;
}
IValueFetcher* LongValue::getFetcher(ThreadContext* ctx) throw() 
{
	return LongValue::fetcher;
}
}}

namespace alinous {namespace btree {





bool LongValue::ValueFetcher::__init_done = __init_static_variables();
bool LongValue::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LongValue::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LongValue::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LongValue::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* LongValue::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	IBTreeValue* value = (new(ctx) LongValue(fetcher->fetchLong(ctx), ctx));
	return value;
}
}}

