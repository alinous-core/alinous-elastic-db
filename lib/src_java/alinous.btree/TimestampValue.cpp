#include "includes.h"


namespace alinous {namespace btree {





const TimestampValue::ValueFetcher TimestampValue:: __fetcher = (TimestampValue::ValueFetcher(nullptr));
bool TimestampValue::__init_done = __init_static_variables();
bool TimestampValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimestampValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimestampValue::TimestampValue(long long v, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), value(0)
{
	this->value = v;
}
void TimestampValue::__construct_impl(long long v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 TimestampValue::~TimestampValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimestampValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TimestampValue", L"~TimestampValue");
	if(!prepare){
		return;
	}
}
void TimestampValue::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeValue::TYPE_TIMESTAMP, ctx);
	builder->putLong(value, ctx);
}
int TimestampValue::diskSize(ThreadContext* ctx) throw() 
{
	return IBTreeValue::TYPE_SIZE + 8;
}
long long TimestampValue::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
bool TimestampValue::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<TimestampValue*>(obj))->value;
}
IValueFetcher* TimestampValue::getFetcher(ThreadContext* ctx) throw() 
{
	return TimestampValue::fetcher;
}
}}

namespace alinous {namespace btree {





bool TimestampValue::ValueFetcher::__init_done = __init_static_variables();
bool TimestampValue::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimestampValue::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimestampValue::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimestampValue::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* TimestampValue::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	IBTreeValue* value = (new(ctx) TimestampValue(fetcher->fetchLong(ctx), ctx));
	return value;
}
}}

