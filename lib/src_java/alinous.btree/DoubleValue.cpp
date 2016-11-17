#include "includes.h"


namespace alinous {namespace btree {





const DoubleValue::ValueFetcher DoubleValue:: __fetcher = (DoubleValue::ValueFetcher(nullptr));
bool DoubleValue::__init_done = __init_static_variables();
bool DoubleValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DoubleValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DoubleValue::DoubleValue(double v, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), value(0)
{
	this->value = v;
}
void DoubleValue::__construct_impl(double v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 DoubleValue::~DoubleValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DoubleValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DoubleValue", L"~DoubleValue");
	if(!prepare){
		return;
	}
}
void DoubleValue::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeValue::TYPE_DOUBLE, ctx);
	builder->putDouble(value, ctx);
}
int DoubleValue::diskSize(ThreadContext* ctx) throw() 
{
	return IBTreeValue::TYPE_SIZE + 8;
}
double DoubleValue::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
bool DoubleValue::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<DoubleValue*>(obj))->value;
}
IValueFetcher* DoubleValue::getFetcher(ThreadContext* ctx) throw() 
{
	return DoubleValue::fetcher;
}
}}

namespace alinous {namespace btree {





bool DoubleValue::ValueFetcher::__init_done = __init_static_variables();
bool DoubleValue::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DoubleValue::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DoubleValue::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DoubleValue::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* DoubleValue::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	IBTreeValue* value = (new(ctx) DoubleValue(fetcher->fetchDouble(ctx), ctx));
	return value;
}
}}

