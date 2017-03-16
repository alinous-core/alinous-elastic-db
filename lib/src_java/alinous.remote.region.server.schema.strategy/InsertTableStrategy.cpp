#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
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
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.db.client.command.dml/InsertPrepareCommand.h"
#include "alinous.remote.region.server.schema.strategy/RegionShardPartAccess.h"
#include "alinous.remote.region.server.schema.strategy/RegionPartitionTableAccess.h"
#include "alinous.remote.region.server.schema.strategy/NodeListBinarySearcher.h"
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
 InsertTableStrategy::InsertTableStrategy(long long commitId, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw()  : IObject(ctx), commitId(0), tableAccess(nullptr), nodeSearcher(nullptr), nodeStrategy(GCUtils<HashMap<String,InsertNodeAccessStrategy> >::ins(this, (new(ctx) HashMap<String,InsertNodeAccessStrategy>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	this->commitId = commitId;
	__GC_MV(this, &(this->tableAccess), tableAccess, RegionPartitionTableAccess);
	__GC_MV(this, &(this->nodeSearcher), (new(ctx) NodeListBinarySearcher(tableAccess->getShardParts(ctx), ctx)), NodeListBinarySearcher);
}
void InsertTableStrategy::__construct_impl(long long commitId, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
	__GC_MV(this, &(this->tableAccess), tableAccess, RegionPartitionTableAccess);
	__GC_MV(this, &(this->nodeSearcher), (new(ctx) NodeListBinarySearcher(tableAccess->getShardParts(ctx), ctx)), NodeListBinarySearcher);
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
	__e_obj1.add(this->nodeSearcher, this);
	nodeSearcher = nullptr;
	__e_obj1.add(this->nodeStrategy, this);
	nodeStrategy = nullptr;
	if(!prepare){
		return;
	}
}
List<InsertPrepareCommand>* InsertTableStrategy::toPrepareCommand(DbVersionContext* vctx, long long newCommitId, ThreadContext* ctx) throw() 
{
	List<InsertPrepareCommand>* list = (new(ctx) ArrayList<InsertPrepareCommand>(ctx));
	Iterator<String>* it = this->nodeStrategy->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* nodestr = it->next(ctx);
		InsertNodeAccessStrategy* strategy = this->nodeStrategy->get(nodestr, ctx);
		InsertPrepareCommand* cmd = strategy->toCommand(ctx);
		cmd->setNewCommitId(newCommitId, ctx);
		cmd->setVctx(vctx, ctx);
		list->add(cmd, ctx);
	}
	return list;
}
void InsertTableStrategy::build(ArrayList<ClientNetworkRecord>* list, ThreadContext* ctx)
{
	TableMetadata* meta = tableAccess->getMetadata(ctx);
	TableMetadataUniqueCollection* uniqueCollection = meta->getUniques(ctx);
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
void InsertTableStrategy::buildNodeStrategy(ClientNetworkRecord* record, TableMetadataUniqueCollection* uniqueCollection, ThreadContext* ctx)
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
	}
	buildRecordStrategy(list, record, ctx);
}
void InsertTableStrategy::buildRecordStrategy(List<RegionShardPartAccess>* nodeList, ClientNetworkRecord* record, ThreadContext* ctx)
{
	RegionShardPartAccess* access = nodeSearcher->searchNode(record, ctx);
	InsertNodeAccessStrategy* nodeStoragegy = getInsertNodeAccessStorategy(access->getNodeAccessRef(ctx), ctx);
	nodeStoragegy->addRecord(record, ctx);
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
			nodeStoragegy->addUniqueCheckOperation(unique->getUniqueColList(ctx), values, ctx);
			continue;
		}
		List<VariantValue>* values = key->makeValues(record, ctx);
		if(ranges->isInRange(key, values, ctx))
		{
			nodeStoragegy->addUniqueCheckOperation(unique->getUniqueColList(ctx), values, ctx);
		}
	}
}
void InsertTableStrategy::buildUniqueStrategy(RegionShardPartAccess* node, ClientNetworkRecord* record, TableMetadataUniqueCollection* uniqueCollection, ThreadContext* ctx) throw() 
{
	ArrayList<ScanUnique>* list = uniqueCollection->getUniqueList(ctx);
	InsertNodeAccessStrategy* nodeStoragegy = nullptr;
	NodeReference* nodeAccessRef = node->getNodeAccessRef(ctx);
	TablePartitionRangeCollection* ranges = node->getPartitionRange(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanUnique* unique = list->get(i, ctx);
		TablePartitionKey* key = unique->getCoveredKey(ctx);
		if(nodeStoragegy == nullptr)
		{
			nodeStoragegy = getInsertNodeAccessStorategy(nodeAccessRef, ctx);
		}
		List<VariantValue>* values = key->makeValues(record, ctx);
		if(ranges->isInRange(key, values, ctx))
		{
			nodeStoragegy->addUniqueCheckOperation(unique->getUniqueColList(ctx), values, ctx);
		}
	}
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

