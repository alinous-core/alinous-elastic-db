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
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command.dml/ClientInsertDataCommand.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {





bool ClientInsertDataCommand::__init_done = __init_static_variables();
bool ClientInsertDataCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientInsertDataCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientInsertDataCommand::ClientInsertDataCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), list(GCUtils<ArrayList<ClientNetworkRecord> >::ins(this, (new(ctx) ArrayList<ClientNetworkRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), commitId(0), schema(nullptr), table(nullptr), vctx(nullptr), isolationLevel(0)
{
	this->type = AbstractNodeRegionCommand::TYPE_INSERT_DATA;
}
void ClientInsertDataCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_INSERT_DATA;
}
 ClientInsertDataCommand::~ClientInsertDataCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientInsertDataCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientInsertDataCommand", L"~ClientInsertDataCommand");
	__e_obj1.add(this->list, this);
	list = nullptr;
	__e_obj1.add(this->schema, this);
	schema = nullptr;
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void ClientInsertDataCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			nodeRegionServer->insertData(this->list, this->commitId, this->schema, this->table, this->vctx, this->isolationLevel, ctx);
		}
		catch(AlinousException* e)
		{
			AlinousCore* core = nodeRegionServer->getCore(ctx);
			core->logError(e, ctx);
			handleError(e, ctx);
		}
	}
	this->list->clear(ctx);
	writeByteStream(outStream, ctx);
}
void ClientInsertDataCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->commitId = buff->getLong(ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->schema), buff->getString(ctx), String);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->table), buff->getString(ctx), String);
	}
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = (new(ctx) ClientNetworkRecord(ctx));
		record->readData(buff, ctx);
		this->list->add(record, ctx);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->vctx), (new(ctx) DbVersionContext(ctx)), DbVersionContext);
		this->vctx->readData(buff, ctx);
	}
	this->isolationLevel = buff->getInt(ctx);
	readErrorFromStream(buff, ctx);
}
ArrayList<ClientNetworkRecord>* ClientInsertDataCommand::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void ClientInsertDataCommand::setList(ArrayList<ClientNetworkRecord>* list, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<ClientNetworkRecord> >::mv(this, &(this->list), list, ctx);
}
long long ClientInsertDataCommand::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void ClientInsertDataCommand::setCommitId(long long commitId, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
}
String* ClientInsertDataCommand::getSchema(ThreadContext* ctx) throw() 
{
	return schema;
}
void ClientInsertDataCommand::setSchema(String* schema, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schema), schema, String);
}
String* ClientInsertDataCommand::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void ClientInsertDataCommand::setTable(String* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, String);
}
DbVersionContext* ClientInsertDataCommand::getVctx(ThreadContext* ctx) throw() 
{
	return vctx;
}
void ClientInsertDataCommand::setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
}
int ClientInsertDataCommand::getIsolationLevel(ThreadContext* ctx) throw() 
{
	return isolationLevel;
}
void ClientInsertDataCommand::setIsolationLevel(int isolationLevel, ThreadContext* ctx) throw() 
{
	this->isolationLevel = isolationLevel;
}
void ClientInsertDataCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(this->type, ctx);
	buff->putLong(this->commitId, ctx);
	bool isnull = (this->schema == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->schema, ctx);
	}
	isnull = (this->table == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->table, ctx);
	}
	int maxLoop = this->list->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = this->list->get(i, ctx);
		record->writeData(buff, ctx);
	}
	isnull = (this->vctx == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vctx->writeData(buff, ctx);
	}
	buff->putInt(this->isolationLevel, ctx);
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
void ClientInsertDataCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

