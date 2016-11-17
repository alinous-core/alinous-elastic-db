#include "includes.h"


namespace alinous {namespace db {namespace table {





DatabaseTableIdPublisher* DatabaseTableIdPublisher::instance = nullptr;
bool DatabaseTableIdPublisher::__init_done = __init_static_variables();
bool DatabaseTableIdPublisher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseTableIdPublisher", L"__init_static_variables");
		__GC_MV(nullptr, &(instance), nullptr, DatabaseTableIdPublisher);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseTableIdPublisher::DatabaseTableIdPublisher(ThreadContext* ctx) throw()  : IObject(ctx), tableIdSerial(0), ids(GCUtils<HashMap<String,Integer> >::ins(this, (new(ctx) HashMap<String,Integer>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	this->tableIdSerial = 1;
}
void DatabaseTableIdPublisher::__construct_impl(ThreadContext* ctx) throw() 
{
	this->tableIdSerial = 1;
}
 DatabaseTableIdPublisher::~DatabaseTableIdPublisher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseTableIdPublisher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DatabaseTableIdPublisher", L"~DatabaseTableIdPublisher");
	__e_obj1.add(this->ids, this);
	ids = nullptr;
	if(!prepare){
		return;
	}
}
int DatabaseTableIdPublisher::getId(String* name, ThreadContext* ctx) throw() 
{
	if(instance == nullptr)
	{
		__GC_MV(nullptr, &(instance), (new(ctx) DatabaseTableIdPublisher(ctx)), DatabaseTableIdPublisher);
	}
	Integer* id = instance->ids->get(name, ctx);
	if(id != nullptr)
	{
		return id->intValue(ctx);
	}
	int ret = instance->tableIdSerial;
	instance->tableIdSerial ++ ;
	instance->ids->put(name, (new(ctx) Integer(ret, ctx)), ctx);
	return ret;
}
String* DatabaseTableIdPublisher::idToName(int id, ThreadContext* ctx) throw() 
{
	if(instance == nullptr)
	{
		__GC_MV(nullptr, &(instance), (new(ctx) DatabaseTableIdPublisher(ctx)), DatabaseTableIdPublisher);
	}
	Iterator<String>* it = instance->ids->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		Integer* value = instance->ids->get(key, ctx);
		if(value->intValue(ctx) == id)
		{
			return key;
		}
	}
	return nullptr;
}
}}}

