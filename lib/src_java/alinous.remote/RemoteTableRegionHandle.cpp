#include "includes.h"


namespace alinous {namespace remote {





bool RemoteTableRegionHandle::__init_done = __init_static_variables();
bool RemoteTableRegionHandle::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableRegionHandle", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableRegionHandle::RemoteTableRegionHandle(String* name, ThreadContext* ctx) throw()  : IObject(ctx), ITableRegion(ctx), name(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
}
void RemoteTableRegionHandle::__construct_impl(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
 RemoteTableRegionHandle::~RemoteTableRegionHandle() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableRegionHandle::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteTableRegionHandle", L"~RemoteTableRegionHandle");
	__e_obj1.add(this->name, this);
	name = nullptr;
	if(!prepare){
		return;
	}
}
int RemoteTableRegionHandle::getRegionType(ThreadContext* ctx) throw() 
{
	return ITableRegion::REMOTE_REGION;
}
String* RemoteTableRegionHandle::getRegionName(ThreadContext* ctx) throw() 
{
	return this->name;
}
TableSchema* RemoteTableRegionHandle::getSchema(String* name, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void RemoteTableRegionHandle::createSchema(String* schemaName, ThreadContext* ctx) throw() 
{
}
void RemoteTableRegionHandle::createTable(String* schemaName, TableMetadata* tblMeta, ThreadContext* ctx)
{
}
}}

