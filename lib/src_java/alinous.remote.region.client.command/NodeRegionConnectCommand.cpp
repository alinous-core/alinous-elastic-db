#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command/NodeRegionConnectCommand.h"
#include "alinous.remote.region.client.command.ddl/RegionCreateSchemaCommand.h"
#include "alinous.remote.region.client.command.ddl/RegionCreateTableCommand.h"
#include "alinous.remote.region.client.command.dml/ClientClearSelectSessionCommand.h"
#include "alinous.remote.region.client.command.dml/ClientInsertDataCommand.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommand.h"
#include "alinous.remote.region.client.command.dml/ClientScanEndCommand.h"
#include "alinous.remote.region.client.command.dml/ClientTpcCommitSessionCommand.h"
#include "alinous.remote.region.client.command/NodeRegionFinishConnectionCommand.h"
#include "alinous.remote.region.client.command/NodeRegionTerminateCommand.h"
#include "alinous.remote.region.client.command/NodeRegionVoidCommand.h"
#include "alinous.remote.region.client.command/GetSchemaFromRegionCommand.h"
#include "alinous.remote.region.client.command/NodeRegionCommandReader.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {





bool NodeRegionConnectCommand::__init_done = __init_static_variables();
bool NodeRegionConnectCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionConnectCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionConnectCommand::NodeRegionConnectCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), connected(0)
{
	this->type = NodeRegionConnectCommand::TYPE_CONNECT;
}
void NodeRegionConnectCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = NodeRegionConnectCommand::TYPE_CONNECT;
}
 NodeRegionConnectCommand::~NodeRegionConnectCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionConnectCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeRegionConnectCommand", L"~NodeRegionConnectCommand");
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void NodeRegionConnectCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	int res = buff->getInt(ctx);
	this->connected = (res == 1);
}
void NodeRegionConnectCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	this->connected = true;
	writeByteStream(outStream, ctx);
}
bool NodeRegionConnectCommand::isConnected(ThreadContext* ctx) throw() 
{
	return connected;
}
void NodeRegionConnectCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(NodeRegionConnectCommand::TYPE_CONNECT, ctx);
	if(this->connected)
	{
		buff->putInt(1, ctx);
	}
		else 
	{
		buff->putInt(0, ctx);
	}
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void NodeRegionConnectCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

