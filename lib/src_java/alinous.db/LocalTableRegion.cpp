#include "includes.h"


namespace alinous {namespace db {





bool LocalTableRegion::__init_done = __init_static_variables();
bool LocalTableRegion::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LocalTableRegion", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LocalTableRegion::LocalTableRegion(RecordCacheEngine* cacheEngine, String* dataDir, ISystemLog* logger, AlinousDatabase* database, ThreadContext* ctx) throw()  : IObject(ctx), ITableRegion(ctx), schemas(nullptr)
{
	__GC_MV(this, &(this->schemas), (new(ctx) SchemaManager(cacheEngine, dataDir, logger, database, ctx)), SchemaManager);
}
void LocalTableRegion::__construct_impl(RecordCacheEngine* cacheEngine, String* dataDir, ISystemLog* logger, AlinousDatabase* database, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schemas), (new(ctx) SchemaManager(cacheEngine, dataDir, logger, database, ctx)), SchemaManager);
}
 LocalTableRegion::~LocalTableRegion() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LocalTableRegion::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LocalTableRegion", L"~LocalTableRegion");
	__e_obj1.add(this->schemas, this);
	schemas = nullptr;
	if(!prepare){
		return;
	}
}
SchemaManager* LocalTableRegion::getSchemaManager(ThreadContext* ctx) throw() 
{
	return this->schemas;
}
int LocalTableRegion::getRegionType(ThreadContext* ctx) throw() 
{
	return ITableRegion::LOCAL_REGION;
}
String* LocalTableRegion::getRegionName(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1595();
}
TableSchema* LocalTableRegion::getSchema(String* name, ThreadContext* ctx) throw() 
{
	return this->schemas->getSchema(name, ctx);
}
void LocalTableRegion::createSchema(String* schemaName, ThreadContext* ctx) throw() 
{
	this->schemas->createSchema(schemaName, ctx);
}
void LocalTableRegion::createTable(String* schemaName, TableMetadata* tblMeta, ThreadContext* ctx)
{
	this->schemas->createTable(schemaName, tblMeta, ctx);
}
}}

