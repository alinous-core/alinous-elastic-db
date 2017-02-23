#include "includes.h"


namespace alinous {namespace db {namespace table {





bool LocalOidPublisher::__init_done = __init_static_variables();
bool LocalOidPublisher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LocalOidPublisher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LocalOidPublisher::~LocalOidPublisher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LocalOidPublisher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LocalOidPublisher", L"~LocalOidPublisher");
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
long long LocalOidPublisher::newOid(String* tableFullName, ThreadContext* ctx) throw() 
{
	long long oid = -1;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		LocalOidCounter* counter = this->tables->get(tableFullName, ctx);
		if(counter == nullptr)
		{
			counter = (new(ctx) LocalOidCounter(ctx));
			this->tables->put(tableFullName, counter, ctx);
		}
		oid = counter->newOid(ctx);
	}
	return oid;
}
void LocalOidPublisher::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeValue::TYPE_LOCAL_ID_PUBLISHER, ctx);
	int maxLoop = this->tables->size(ctx);
	builder->putInt(maxLoop, ctx);
	Iterator<String>* it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* table = it->next(ctx);
		builder->putString(table, ctx);
		LocalOidCounter* counter = this->tables->get(table, ctx);
		counter->appendToEntry(builder, ctx);
	}
}
int LocalOidPublisher::diskSize(ThreadContext* ctx)
{
	int total = 4;
	total += 4;
	Iterator<String>* it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* table = it->next(ctx);
		total += 4 + table->length(ctx) * 2;
		LocalOidCounter* counter = this->tables->get(table, ctx);
		total += counter->diskSize(ctx);
	}
	return total;
}
IValueFetcher* LocalOidPublisher::getFetcher(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool LocalOidPublisher::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this == obj;
}
LocalOidPublisher* LocalOidPublisher::fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	LocalOidPublisher* publisher = (new(ctx) LocalOidPublisher(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* table = fetcher->fetchString(ctx);
		LocalOidCounter* counter = LocalOidCounter::fromFetcher(fetcher, ctx);
		publisher->tables->put(table, counter, ctx);
	}
	return publisher;
}
}}}

