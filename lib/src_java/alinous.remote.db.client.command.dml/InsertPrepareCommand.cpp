#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.server.schema.strategy/UniqueCheckOperation.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.db.client.command.dml/InsertPrepareCommand.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace dml {





bool InsertPrepareCommand::__init_done = __init_static_variables();
bool InsertPrepareCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InsertPrepareCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InsertPrepareCommand::InsertPrepareCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), uniqueCheckOps(GCUtils<List<UniqueCheckOperation> >::ins(this, (new(ctx) ArrayList<UniqueCheckOperation>(ctx)), ctx, __FILEW__, __LINE__, L"")), records(GCUtils<List<ClientNetworkRecord> >::ins(this, (new(ctx) ArrayList<ClientNetworkRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), newCommitId(0), vctx(nullptr), schemaName(nullptr), tableName(nullptr), isolationLevel(0), nodeAccessRef(nullptr)
{
	this->type = AbstractRemoteStorageCommand::TYPE_INSERT_PREPARE;
}
void InsertPrepareCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractRemoteStorageCommand::TYPE_INSERT_PREPARE;
}
 InsertPrepareCommand::~InsertPrepareCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InsertPrepareCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InsertPrepareCommand", L"~InsertPrepareCommand");
	__e_obj1.add(this->uniqueCheckOps, this);
	uniqueCheckOps = nullptr;
	__e_obj1.add(this->records, this);
	records = nullptr;
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	__e_obj1.add(this->schemaName, this);
	schemaName = nullptr;
	__e_obj1.add(this->tableName, this);
	tableName = nullptr;
	__e_obj1.add(this->nodeAccessRef, this);
	nodeAccessRef = nullptr;
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void InsertPrepareCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			tableStorageServer->prepareInsert(this->schemaName, this->tableName, newCommitId, uniqueCheckOps, records, vctx, isolationLevel, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			AlinousCore* core = tableStorageServer->getCore(ctx);
			core->logError(e, ctx);
			handleError(e, ctx);
		}
	}
	this->uniqueCheckOps->clear(ctx);
	this->records->clear(ctx);
	writeByteStream(outStream, ctx);
}
void InsertPrepareCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->newCommitId = buff->getLong(ctx);
	__GC_MV(this, &(this->vctx), DbVersionContext::fromNetwork(buff, ctx), DbVersionContext);
	__GC_MV(this, &(this->schemaName), buff->getString(ctx), String);
	__GC_MV(this, &(this->tableName), buff->getString(ctx), String);
	this->isolationLevel = buff->getInt(ctx);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		UniqueCheckOperation* op = UniqueCheckOperation::fromNetwork(buff, ctx);
		this->uniqueCheckOps->add(op, ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = ClientNetworkRecord::fromNetwork(buff, ctx);
		this->records->add(record, ctx);
	}
}
void InsertPrepareCommand::addUniqueCheck(UniqueCheckOperation* op, ThreadContext* ctx) throw() 
{
	this->uniqueCheckOps->add(op, ctx);
}
void InsertPrepareCommand::addRecord(ClientNetworkRecord* record, ThreadContext* ctx) throw() 
{
	this->records->add(record, ctx);
}
NodeReference* InsertPrepareCommand::getNodeAccessRef(ThreadContext* ctx) throw() 
{
	return nodeAccessRef;
}
void InsertPrepareCommand::setNodeAccessRef(NodeReference* nodeAccessRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->nodeAccessRef), nodeAccessRef, NodeReference);
}
long long InsertPrepareCommand::getNewCommitId(ThreadContext* ctx) throw() 
{
	return newCommitId;
}
void InsertPrepareCommand::setNewCommitId(long long newCommitId, ThreadContext* ctx) throw() 
{
	this->newCommitId = newCommitId;
}
DbVersionContext* InsertPrepareCommand::getVctx(ThreadContext* ctx) throw() 
{
	return vctx;
}
void InsertPrepareCommand::setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
}
String* InsertPrepareCommand::getSchemaName(ThreadContext* ctx) throw() 
{
	return schemaName;
}
void InsertPrepareCommand::setSchemaName(String* schemaName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schemaName), schemaName, String);
}
String* InsertPrepareCommand::getTableName(ThreadContext* ctx) throw() 
{
	return tableName;
}
void InsertPrepareCommand::setTableName(String* tableName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableName), tableName, String);
}
int InsertPrepareCommand::getIsolationLevel(ThreadContext* ctx) throw() 
{
	return isolationLevel;
}
void InsertPrepareCommand::setIsolationLevel(int isolationLevel, ThreadContext* ctx) throw() 
{
	this->isolationLevel = isolationLevel;
}
void InsertPrepareCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(1024 * 2, ctx));
	buff->putInt(this->type, ctx);
	buff->putLong(this->newCommitId, ctx);
	this->vctx->writeData(buff, ctx);
	buff->putString(this->schemaName, ctx);
	buff->putString(this->tableName, ctx);
	buff->putInt(this->isolationLevel, ctx);
	int maxLoop = this->uniqueCheckOps->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		UniqueCheckOperation* op = this->uniqueCheckOps->get(i, ctx);
		op->writeData(buff, ctx);
	}
	maxLoop = this->records->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = this->records->get(i, ctx);
		record->writeData(buff, ctx);
	}
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void InsertPrepareCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

