#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageConnectCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command.ddl/CreateSchemaCommand.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace ddl {





bool CreateSchemaCommand::__init_done = __init_static_variables();
bool CreateSchemaCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CreateSchemaCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CreateSchemaCommand::CreateSchemaCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), schemaName(nullptr)
{
	this->type = AbstractRemoteStorageCommand::TYPE_CREATE_SCHEMA;
}
void CreateSchemaCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractRemoteStorageCommand::TYPE_CREATE_SCHEMA;
}
 CreateSchemaCommand::~CreateSchemaCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CreateSchemaCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CreateSchemaCommand", L"~CreateSchemaCommand");
	__e_obj1.add(this->schemaName, this);
	schemaName = nullptr;
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void CreateSchemaCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			tableStorageServer->createSchema(schemaName, ctx);
		}
		catch(AlinousException* e)
		{
			tableStorageServer->logError(e, ctx);
			handleError(e, ctx);
		}
	}
	writeByteStream(outStream, ctx);
}
void CreateSchemaCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	buff->putString(this->schemaName, ctx);
	readErrorFromStream(buff, ctx);
}
String* CreateSchemaCommand::getSchemaName(ThreadContext* ctx) throw() 
{
	return schemaName;
}
void CreateSchemaCommand::setSchemaName(String* schemaName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schemaName), schemaName, String);
}
void CreateSchemaCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(RemoteStorageConnectCommand::TYPE_CREATE_SCHEMA, ctx);
	buff->putString(this->schemaName, ctx);
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void CreateSchemaCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

