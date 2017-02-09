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
 LocalTableRegion::LocalTableRegion(String* dataDir, ISystemLog* logger, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, LocalCommitIdPublisher* publisher, ThreadContext* ctx) throw()  : IObject(ctx), ITableRegion(ctx), schemas(nullptr), publisher(nullptr)
{
	__GC_MV(this, &(this->schemas), (new(ctx) SchemaManager(dataDir, logger, threadPool, core, cache, ctx)), SchemaManager);
	__GC_MV(this, &(this->publisher), publisher, LocalCommitIdPublisher);
}
void LocalTableRegion::__construct_impl(String* dataDir, ISystemLog* logger, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, LocalCommitIdPublisher* publisher, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schemas), (new(ctx) SchemaManager(dataDir, logger, threadPool, core, cache, ctx)), SchemaManager);
	__GC_MV(this, &(this->publisher), publisher, LocalCommitIdPublisher);
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
	__e_obj1.add(this->publisher, this);
	publisher = nullptr;
	if(!prepare){
		return;
	}
}
SchemaManager* LocalTableRegion::getSchemaManager(ThreadContext* ctx) throw() 
{
	return this->schemas;
}
void LocalTableRegion::setSchemaManager(SchemaManager* schemas, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schemas), schemas, SchemaManager);
}
int LocalTableRegion::getRegionType(ThreadContext* ctx) throw() 
{
	return ITableRegion::LOCAL_REGION;
}
String* LocalTableRegion::getRegionName(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1677();
}
TableSchema* LocalTableRegion::getSchema(String* name, ThreadContext* ctx) throw() 
{
	return this->schemas->getSchema(name, ctx);
}
void LocalTableRegion::createSchema(String* schemaName, ThreadContext* ctx) throw() 
{
	this->schemas->createSchema(schemaName, ctx);
}
void LocalTableRegion::createTable(String* schemaName, TableMetadata* tblMeta, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	this->publisher->addSchemaVersion(ctx);
	this->schemas->createTable(schemaName, tblMeta, threadPool, core, cache, ctx);
}
void LocalTableRegion::syncSchemes(ThreadContext* ctx) throw() 
{
}
void LocalTableRegion::dispose(ThreadContext* ctx) throw() 
{
}
long long LocalTableRegion::getSchemeVersion(ThreadContext* ctx) throw() 
{
	return this->publisher->getSchemaVersion(ctx);
}
}}

