#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.region.server.schema.strategy/RegionShardPartAccess.h"
#include "alinous.remote.region.server.schema.strategy/RegionPartitionTableAccess.h"
#include "alinous.remote.region.server.schema.strategy/InsertNodeAccessStrategy.h"
#include "alinous.remote.region.server.schema.strategy/InsertTableStrategy.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {





bool InsertTableStrategy::__init_done = __init_static_variables();
bool InsertTableStrategy::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InsertTableStrategy", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InsertTableStrategy::InsertTableStrategy(long long commitId, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw()  : IObject(ctx), commitId(0), tableAccess(nullptr), nodeStrategy(GCUtils<HashMap<String,InsertNodeAccessStrategy> >::ins(this, (new(ctx) HashMap<String,InsertNodeAccessStrategy>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	this->commitId = commitId;
	__GC_MV(this, &(this->tableAccess), tableAccess, RegionPartitionTableAccess);
}
void InsertTableStrategy::__construct_impl(long long commitId, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
	__GC_MV(this, &(this->tableAccess), tableAccess, RegionPartitionTableAccess);
}
 InsertTableStrategy::~InsertTableStrategy() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InsertTableStrategy::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InsertTableStrategy", L"~InsertTableStrategy");
	__e_obj1.add(this->tableAccess, this);
	tableAccess = nullptr;
	__e_obj1.add(this->nodeStrategy, this);
	nodeStrategy = nullptr;
	if(!prepare){
		return;
	}
}
void InsertTableStrategy::build(ArrayList<ClientNetworkRecord>* list, ThreadContext* ctx) throw() 
{
	TableMetadataUniqueCollection* uniqueCollection = tableAccess->getMetadata(ctx)->getUniques(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = list->get(i, ctx);
		buildNodeStrategy(record, uniqueCollection, ctx);
	}
}
long long InsertTableStrategy::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void InsertTableStrategy::buildNodeStrategy(ClientNetworkRecord* record, TableMetadataUniqueCollection* uniqueCollection, ThreadContext* ctx) throw() 
{
	List<RegionShardPartAccess>* list = this->tableAccess->getShardParts(ctx);
	bool fullCover = uniqueCollection->isFullCover(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		RegionShardPartAccess* node = list->get(i, ctx);
		if(fullCover)
		{
			buildUniqueStrategy(node, record, uniqueCollection, ctx);
		}
				else 
		{
			addUniqueCheck(node, record, uniqueCollection, ctx);
		}
		buildRecordStrategy(node, record, ctx);
	}
}
void InsertTableStrategy::addUniqueCheck(RegionShardPartAccess* node, ClientNetworkRecord* record, TableMetadataUniqueCollection* uniqueCollection, ThreadContext* ctx) throw() 
{
	ArrayList<ScanUnique>* list = uniqueCollection->getUniqueList(ctx);
	NodeReference* nodeAccessRef = node->getNodeAccessRef(ctx);
	InsertNodeAccessStrategy* nodeStoragegy = getInsertNodeAccessStorategy(nodeAccessRef, ctx);
	TablePartitionRangeCollection* ranges = node->getPartitionRange(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanUnique* unique = list->get(i, ctx);
		TablePartitionKey* key = unique->getCoveredKey(ctx);
		if(key == nullptr)
		{
			List<VariantValue>* values = unique->makeValues(record, ctx);
			nodeStoragegy->addUniqueCheck(unique->getUniqueColList(ctx), values, ctx);
			continue;
		}
		List<VariantValue>* values = key->makeValues(record, ctx);
		if(ranges->isInRange(key, values, ctx))
		{
			nodeStoragegy->addUniqueCheck(unique->getUniqueColList(ctx), values, ctx);
		}
	}
}
void InsertTableStrategy::buildUniqueStrategy(RegionShardPartAccess* node, ClientNetworkRecord* record, TableMetadataUniqueCollection* uniqueCollection, ThreadContext* ctx) throw() 
{
}
void InsertTableStrategy::buildRecordStrategy(RegionShardPartAccess* node, ClientNetworkRecord* record, ThreadContext* ctx) throw() 
{
}
InsertNodeAccessStrategy* InsertTableStrategy::getInsertNodeAccessStorategy(NodeReference* nodeAccessRef, ThreadContext* ctx) throw() 
{
	String* key = nodeAccessRef->toString(ctx);
	InsertNodeAccessStrategy* nodeAccess = this->nodeStrategy->get(key, ctx);
	if(nodeAccess == nullptr)
	{
		nodeAccess = (new(ctx) InsertNodeAccessStrategy(nodeAccessRef, ctx));
		this->nodeStrategy->put(key, nodeAccess, ctx);
	}
	return nodeAccess;
}
void InsertTableStrategy::__cleanUp(ThreadContext* ctx){
}
}}}}}}

