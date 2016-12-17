#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {





bool RemoteRegionRef::__init_done = __init_static_variables();
bool RemoteRegionRef::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteRegionRef", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteRegionRef::RemoteRegionRef(RegionRef* ref, ThreadContext* ctx) throw()  : IObject(ctx), ITableRegion(ctx), config(nullptr)
{
	__GC_MV(this, &(this->config), ref, RegionRef);
}
void RemoteRegionRef::__construct_impl(RegionRef* ref, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->config), ref, RegionRef);
}
 RemoteRegionRef::~RemoteRegionRef() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteRegionRef::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteRegionRef", L"~RemoteRegionRef");
	__e_obj1.add(this->config, this);
	config = nullptr;
	if(!prepare){
		return;
	}
}
int RemoteRegionRef::getRegionType(ThreadContext* ctx) throw() 
{
	return 0;
}
String* RemoteRegionRef::getRegionName(ThreadContext* ctx) throw() 
{
	return nullptr;
}
ITableSchema* RemoteRegionRef::getSchema(String* name, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void RemoteRegionRef::createSchema(String* schemaName, ThreadContext* ctx) throw() 
{
}
void RemoteRegionRef::createTable(String* schemaName, TableMetadata* tblMeta, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
RegionRef* RemoteRegionRef::getConfig(ThreadContext* ctx) throw() 
{
	return config;
}
}}}}

