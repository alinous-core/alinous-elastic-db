#include "includes.h"


namespace alinous {namespace db {namespace table {





const LocalOidCounter::ValueFetcher LocalOidCounter:: __fetcher = (LocalOidCounter::ValueFetcher(nullptr));
bool LocalOidCounter::__init_done = __init_static_variables();
bool LocalOidCounter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LocalOidCounter", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LocalOidCounter::LocalOidCounter(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), nextOid(0)
{
	this->nextOid = 1;
}
void LocalOidCounter::__construct_impl(ThreadContext* ctx) throw() 
{
	this->nextOid = 1;
}
 LocalOidCounter::LocalOidCounter(long long nextOid, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), nextOid(0)
{
	this->nextOid = nextOid;
}
void LocalOidCounter::__construct_impl(long long nextOid, ThreadContext* ctx) throw() 
{
	this->nextOid = nextOid;
}
 LocalOidCounter::~LocalOidCounter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LocalOidCounter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LocalOidCounter", L"~LocalOidCounter");
	if(!prepare){
		return;
	}
}
long long LocalOidCounter::newOid(ThreadContext* ctx) throw() 
{
	long long oid = this->nextOid;
	this->nextOid ++ ;
	return oid;
}
void LocalOidCounter::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putLong(this->nextOid, ctx);
}
int LocalOidCounter::diskSize(ThreadContext* ctx)
{
	int total = 8;
	return total;
}
bool LocalOidCounter::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this == obj;
}
IValueFetcher* LocalOidCounter::getFetcher(ThreadContext* ctx) throw() 
{
	return fetcher;
}
LocalOidCounter* LocalOidCounter::fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	LocalOidCounter* value = (new(ctx) LocalOidCounter(fetcher->fetchLong(ctx), ctx));
	return value;
}
}}}

namespace alinous {namespace db {namespace table {





bool LocalOidCounter::ValueFetcher::__init_done = __init_static_variables();
bool LocalOidCounter::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LocalOidCounter::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LocalOidCounter::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LocalOidCounter::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* LocalOidCounter::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	IBTreeValue* value = (new(ctx) LocalOidCounter(fetcher->fetchLong(ctx), ctx));
	return value;
}
}}}

