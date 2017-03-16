#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageConnectCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command.ddl/CreateTableCommand.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace ddl {





bool CreateTableCommand::__init_done = __init_static_variables();
bool CreateTableCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CreateTableCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CreateTableCommand::CreateTableCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), metadaata(nullptr)
{
	this->type = AbstractRemoteStorageCommand::TYPE_CREATE_TABLE;
}
void CreateTableCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractRemoteStorageCommand::TYPE_CREATE_TABLE;
}
 CreateTableCommand::~CreateTableCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CreateTableCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CreateTableCommand", L"~CreateTableCommand");
	__e_obj1.add(this->metadaata, this);
	metadaata = nullptr;
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void CreateTableCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			tableStorageServer->createTable(this->metadaata, ctx);
		}
		catch(InterruptedException* e)
		{
			tableStorageServer->logError(e, ctx);
			handleError(e, ctx);
		}
		catch(BTreeException* e)
		{
			tableStorageServer->logError(e, ctx);
			handleError(e, ctx);
		}
		catch(DatabaseException* e)
		{
			tableStorageServer->logError(e, ctx);
			handleError(e, ctx);
		}
		catch(AlinousException* e)
		{
			tableStorageServer->logError(e, ctx);
			handleError(e, ctx);
		}
	}
	writeByteStream(outStream, ctx);
}
void CreateTableCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->metadaata), TableMetadata::fromNetwork(buff, ctx), TableMetadata);
	}
	readErrorFromStream(buff, ctx);
}
TableMetadata* CreateTableCommand::getMetadaata(ThreadContext* ctx) throw() 
{
	return metadaata;
}
void CreateTableCommand::setMetadaata(TableMetadata* metadaata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->metadaata), metadaata, TableMetadata);
}
void CreateTableCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(RemoteStorageConnectCommand::TYPE_CREATE_TABLE, ctx);
	bool isnull = (this->metadaata == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->metadaata->writeData(buff, ctx);
	}
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void CreateTableCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

