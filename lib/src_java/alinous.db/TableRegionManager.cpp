#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.lock/LockObject.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"

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
 TableRegionManager::TableRegionManager(ThreadContext* ctx) throw()  : IObject(ctx), regions(GCUtils<List<ITableRegion> >::ins(this, (new(ctx) ArrayList<ITableRegion>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void TableRegionManager::__construct_impl(ThreadContext* ctx) throw() 
{
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
		regionName = ConstStr::getCNST_STR_1683();
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
	if(region == nullptr)
	{
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1686(), ctx));
	}
	region->createSchema(schemaName, ctx);
	region->createTable(schemaName, tblMeta, database->workerThreadsPool, core, database->getBtreeCache(ctx), ctx);
}
List<ITableRegion>* TableRegionManager::getRegions(ThreadContext* ctx) throw() 
{
	return regions;
}
void TableRegionManager::dispose(ThreadContext* ctx) throw() 
{
	int maxLoop = this->regions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITableRegion* reg = this->regions->get(i, ctx);
		reg->dispose(ctx);
	}
}
void TableRegionManager::syncSchemaVersion(DbVersionContext* vctx, ThreadContext* ctx)
{
	int maxLoop = this->regions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITableRegion* region = this->regions->get(i, ctx);
		long long schemaVer = region->getSchemeVersion(ctx);
		if(schemaVer < vctx->getSchemaVersion(ctx))
		{
			region->syncSchemes(ctx);
		}
	}
}
void TableRegionManager::__cleanUp(ThreadContext* ctx){
}
}}

