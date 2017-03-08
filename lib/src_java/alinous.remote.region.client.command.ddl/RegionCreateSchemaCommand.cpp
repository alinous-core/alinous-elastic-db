#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command/NodeRegionConnectCommand.h"
#include "alinous.remote.region.client.command.ddl/RegionCreateSchemaCommand.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace ddl {





bool RegionCreateSchemaCommand::__init_done = __init_static_variables();
bool RegionCreateSchemaCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionCreateSchemaCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionCreateSchemaCommand::RegionCreateSchemaCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), schemaName(nullptr)
{
	this->type = AbstractNodeRegionCommand::TYPE_CREATE_SCHEMA;
}
void RegionCreateSchemaCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_CREATE_SCHEMA;
}
 RegionCreateSchemaCommand::~RegionCreateSchemaCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionCreateSchemaCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionCreateSchemaCommand", L"~RegionCreateSchemaCommand");
	__e_obj1.add(this->schemaName, this);
	schemaName = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void RegionCreateSchemaCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			nodeRegionServer->createSchema(this->schemaName, ctx);
		}
		catch(AlinousException* e)
		{
			handleError(e, ctx);
			AlinousCore* core = nodeRegionServer->getCore(ctx);
			core->logError(e, ctx);
		}
	}
	writeByteStream(outStream, ctx);
}
void RegionCreateSchemaCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	__GC_MV(this, &(this->schemaName), buff->getString(ctx), String);
	readErrorFromStream(buff, ctx);
}
String* RegionCreateSchemaCommand::getSchemaName(ThreadContext* ctx) throw() 
{
	return schemaName;
}
void RegionCreateSchemaCommand::setSchemaName(String* schemaName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schemaName), schemaName, String);
}
void RegionCreateSchemaCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(256, ctx));
	buff->putInt(NodeRegionConnectCommand::TYPE_CREATE_SCHEMA, ctx);
	buff->putString(this->schemaName, ctx);
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
void RegionCreateSchemaCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

