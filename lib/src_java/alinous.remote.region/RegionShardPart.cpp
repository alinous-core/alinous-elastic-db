#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.region/NodeReference.h"
#include "alinous.remote.region/NodeTableReference.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.remote.region/NodeCluster.h"
#include "alinous.remote.region/NodeTableClaster.h"
#include "alinous.remote.region/NodeRegionSchema.h"
#include "alinous.remote.region/RegionShardPart.h"
#include "alinous.remote.region/RegionShardTable.h"
#include "alinous.remote.region/NodeReferenceManager.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.region/NodeRegionResponceAction.h"
#include "alinous.remote.region/NodeRegionResponceActionFactory.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.region/RegionInsertExecutor.h"
#include "alinous.remote.region/RegionTpcExecutorPool.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.remote.region/RegionTableLockManager.h"

namespace alinous {namespace remote {namespace region {





bool RegionShardPart::__init_done = __init_static_variables();
bool RegionShardPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionShardPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionShardPart::RegionShardPart(NodeTableReference* nodeRef, ThreadContext* ctx) throw()  : IObject(ctx), partitionRange(nullptr), nodeAccessRef(nullptr)
{
	__GC_MV(this, &(this->partitionRange), nodeRef->getRange(ctx), TablePartitionRangeCollection);
	__GC_MV(this, &(this->nodeAccessRef), nodeRef->getNodeAccessRef(ctx), NodeReference);
}
void RegionShardPart::__construct_impl(NodeTableReference* nodeRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->partitionRange), nodeRef->getRange(ctx), TablePartitionRangeCollection);
	__GC_MV(this, &(this->nodeAccessRef), nodeRef->getNodeAccessRef(ctx), NodeReference);
}
 RegionShardPart::~RegionShardPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionShardPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionShardPart", L"~RegionShardPart");
	__e_obj1.add(this->partitionRange, this);
	partitionRange = nullptr;
	__e_obj1.add(this->nodeAccessRef, this);
	nodeAccessRef = nullptr;
	if(!prepare){
		return;
	}
}
TablePartitionRangeCollection* RegionShardPart::getPartitionRange(ThreadContext* ctx) throw() 
{
	return partitionRange;
}
NodeReference* RegionShardPart::getNodeAccessRef(ThreadContext* ctx) throw() 
{
	return nodeAccessRef;
}
void RegionShardPart::__cleanUp(ThreadContext* ctx){
}
}}}

