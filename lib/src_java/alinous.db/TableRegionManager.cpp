#include "includes.h"


namespace alinous {namespace db {





bool TableRegionManager::__init_done = __init_static_variables();
bool TableRegionManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableRegionManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableRegionManager::~TableRegionManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableRegionManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableRegionManager", L"~TableRegionManager");
	__e_obj1.add(this->regions, this);
	regions = nullptr;
	if(!prepare){
		return;
	}
}
void TableRegionManager::addRegion(ITableRegion* region, ThreadContext* ctx) throw() 
{
	this->regions->add(region, ctx);
}
LocalTableRegion* TableRegionManager::getLocalRegion(ThreadContext* ctx) throw() 
{
	int maxLoop = this->regions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITableRegion* region = this->regions->get(i, ctx);
		if(region->getRegionType(ctx) == ITableRegion::LOCAL_REGION)
		{
			return static_cast<LocalTableRegion*>(region);
		}
	}
	return nullptr;
}
TableSchemaCollection* TableRegionManager::getSchema(String* name, ThreadContext* ctx) throw() 
{
	TableSchemaCollection* col = (new(ctx) TableSchemaCollection(ctx));
	int maxLoop = this->regions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITableRegion* region = this->regions->get(i, ctx);
		ITableSchema* sc = region->getSchema(name, ctx);
		if(sc != nullptr)
		{
			col->addScheme(sc, ctx);
		}
	}
	return col;
}
void TableRegionManager::commitCreateTable(String* regionName, String* schemaName, TableMetadata* tblMeta, AlinousDatabase* database, AlinousCore* core, ThreadContext* ctx)
{
	if(regionName == nullptr)
	{
		regionName = ConstStr::getCNST_STR_1595();
	}
	int maxLoop = this->regions->size(ctx);
	ITableRegion* region = nullptr;
	for(int i = 0; i != maxLoop; ++i)
	{
		ITableRegion* rg = this->regions->get(i, ctx);
		if(rg->getRegionName(ctx)->equals(regionName, ctx))
		{
			region = rg;
			break ;
		}
	}
	region->createSchema(schemaName, ctx);
	region->createTable(schemaName, tblMeta, database->workerThreadsPool, core, database->getBtreeCache(ctx), ctx);
}
}}

