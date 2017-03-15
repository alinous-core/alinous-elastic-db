#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.region.server.schema.strategy/UniqueCheckOperation.h"
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
 InsertPrepareCommand::InsertPrepareCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), uniqueCheckOps(GCUtils<List<UniqueCheckOperation> >::ins(this, (new(ctx) ArrayList<UniqueCheckOperation>(ctx)), ctx, __FILEW__, __LINE__, L"")), records(GCUtils<List<ClientNetworkRecord> >::ins(this, (new(ctx) ArrayList<ClientNetworkRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), nodeAccessRef(nullptr)
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
	__e_obj1.add(this->nodeAccessRef, this);
	nodeAccessRef = nullptr;
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void InsertPrepareCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void InsertPrepareCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
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
void InsertPrepareCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
}
void InsertPrepareCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

