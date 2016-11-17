#include "includes.h"


namespace alinous {namespace btree {





const StringValue::ValueFetcher StringValue:: __fetcher = (StringValue::ValueFetcher(nullptr));
constexpr const int StringValue::BASE_SIZE;
bool StringValue::__init_done = __init_static_variables();
bool StringValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StringValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StringValue::StringValue(String* fetchString, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), fetchString, String);
}
void StringValue::__construct_impl(String* fetchString, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), fetchString, String);
}
 StringValue::~StringValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StringValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StringValue", L"~StringValue");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
}
int StringValue::diskSize(ThreadContext* ctx) throw() 
{
	return IBTreeValue::TYPE_SIZE + BASE_SIZE + (value->length(ctx) * 2);
}
void StringValue::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeValue::TYPE_INT, ctx);
	builder->putString(value, ctx);
}
bool StringValue::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value->equals(obj, ctx);
}
IValueFetcher* StringValue::getFetcher(ThreadContext* ctx) throw() 
{
	return StringValue::fetcher;
}
}}

namespace alinous {namespace btree {





bool StringValue::ValueFetcher::__init_done = __init_static_variables();
bool StringValue::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StringValue::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StringValue::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StringValue::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* StringValue::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	IBTreeValue* value = (new(ctx) StringValue(fetcher->fetchString(ctx), ctx));
	return value;
}
}}

