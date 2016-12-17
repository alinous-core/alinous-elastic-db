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
 RemoteRegionRef::RemoteRegionRef(RegionRef* ref, ThreadContext* ctx) throw()  : IObject(ctx), ITableRegion(ctx), config(nullptr), pool(nullptr), url(nullptr), info(nullptr)
{
	__GC_MV(this, &(this->config), ref, RegionRef);
	__GC_MV(this, &(this->url), ref->getUrl(ctx), String);
}
void RemoteRegionRef::__construct_impl(RegionRef* ref, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->config), ref, RegionRef);
	__GC_MV(this, &(this->url), ref->getUrl(ctx), String);
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
	__e_obj1.add(this->pool, this);
	pool = nullptr;
	__e_obj1.add(this->url, this);
	url = nullptr;
	__e_obj1.add(this->info, this);
	info = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteRegionRef::init(ThreadContext* ctx)
{
	IArrayObject<String>* segs = this->url->split(ConstStr::getCNST_STR_381(), ctx);
	if(segs->length != 2)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3479(), ctx));
	}
	String* host = segs->get(0);
	int port = 0;
	{
		try
		{
			port = Integer::parseInt(segs->get(1), ctx);
		}
		catch(NumberFormatException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3480(), e, ctx));
		}
	}
	__GC_MV(this, &(this->info), (new(ctx) RegionConnectionInfo(host, port, ctx)), RegionConnectionInfo);
	RegionClientConnectionFactory* factory = (new(ctx) RegionClientConnectionFactory(info, ctx));
	__GC_MV(this, &(this->pool), (new(ctx) SocketConnectionPool(factory, ctx)), SocketConnectionPool);
}
int RemoteRegionRef::getRegionType(ThreadContext* ctx) throw() 
{
	return ITableRegion::REMOTE_REGION;
}
String* RemoteRegionRef::getRegionName(ThreadContext* ctx) throw() 
{
	return this->config->getName(ctx);
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
}}}}

