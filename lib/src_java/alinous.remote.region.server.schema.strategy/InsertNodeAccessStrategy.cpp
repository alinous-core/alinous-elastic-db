#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.region.server.schema.strategy/UniqueCheckOperation.h"
#include "alinous.remote.db.client.command.dml/InsertPrepareCommand.h"
#include "alinous.remote.region.server.schema.strategy/InsertNodeAccessStrategy.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {





bool InsertNodeAccessStrategy::__init_done = __init_static_variables();
bool InsertNodeAccessStrategy::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InsertNodeAccessStrategy", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InsertNodeAccessStrategy::InsertNodeAccessStrategy(NodeReference* nodeAccessRef, ThreadContext* ctx) throw()  : IObject(ctx), nodeAccessRef(nullptr), uniqueCheckOps(GCUtils<HashMap<String,UniqueCheckOperation> >::ins(this, (new(ctx) HashMap<String,UniqueCheckOperation>(ctx)), ctx, __FILEW__, __LINE__, L"")), records(GCUtils<List<ClientNetworkRecord> >::ins(this, (new(ctx) ArrayList<ClientNetworkRecord>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->nodeAccessRef), nodeAccessRef, NodeReference);
}
void InsertNodeAccessStrategy::__construct_impl(NodeReference* nodeAccessRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->nodeAccessRef), nodeAccessRef, NodeReference);
}
 InsertNodeAccessStrategy::~InsertNodeAccessStrategy() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InsertNodeAccessStrategy::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InsertNodeAccessStrategy", L"~InsertNodeAccessStrategy");
	__e_obj1.add(this->nodeAccessRef, this);
	nodeAccessRef = nullptr;
	__e_obj1.add(this->uniqueCheckOps, this);
	uniqueCheckOps = nullptr;
	__e_obj1.add(this->records, this);
	records = nullptr;
	if(!prepare){
		return;
	}
}
InsertPrepareCommand* InsertNodeAccessStrategy::toCommand(ThreadContext* ctx) throw() 
{
	InsertPrepareCommand* cmd = (new(ctx) InsertPrepareCommand(ctx));
	cmd->setNodeAccessRef(this->nodeAccessRef, ctx);
	Iterator<String>* it = this->uniqueCheckOps->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* colstr = it->next(ctx);
		UniqueCheckOperation* op = this->uniqueCheckOps->get(colstr, ctx);
		cmd->addUniqueCheck(op, ctx);
	}
	int maxLoop = this->records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = this->records->get(i, ctx);
		cmd->addRecord(record, ctx);
	}
	return cmd;
}
void InsertNodeAccessStrategy::addRecord(ClientNetworkRecord* record, ThreadContext* ctx) throw() 
{
	this->records->add(record, ctx);
}
void InsertNodeAccessStrategy::addUniqueCheckOperation(List<TableColumnMetadata>* uniqueColList, List<VariantValue>* values, ThreadContext* ctx) throw() 
{
	UniqueCheckOperation* op = getOperation(uniqueColList, ctx);
	op->addValue(values, ctx);
}
NodeReference* InsertNodeAccessStrategy::getNodeAccessRef(ThreadContext* ctx) throw() 
{
	return nodeAccessRef;
}
UniqueCheckOperation* InsertNodeAccessStrategy::getOperation(List<TableColumnMetadata>* uniqueColList, ThreadContext* ctx) throw() 
{
	String* key = TableColumnMetadata::arrayToString(uniqueColList, ctx);
	UniqueCheckOperation* op = this->uniqueCheckOps->get(key, ctx);
	if(op == nullptr)
	{
		op = (new(ctx) UniqueCheckOperation(uniqueColList, ctx));
		this->uniqueCheckOps->put(key, op, ctx);
	}
	return op;
}
void InsertNodeAccessStrategy::__cleanUp(ThreadContext* ctx){
}
}}}}}}

