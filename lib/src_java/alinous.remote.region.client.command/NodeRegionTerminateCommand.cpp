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





bool NodeRegionTerminateCommand::__init_done = __init_static_variables();
bool NodeRegionTerminateCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionTerminateCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionTerminateCommand::NodeRegionTerminateCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx)
{
	this->type = NodeRegionVoidCommand::TYPE_TERMINATE;
}
void NodeRegionTerminateCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = NodeRegionVoidCommand::TYPE_TERMINATE;
}
 NodeRegionTerminateCommand::~NodeRegionTerminateCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionTerminateCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void NodeRegionTerminateCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
void NodeRegionTerminateCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void NodeRegionTerminateCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(NodeRegionConnectCommand::TYPE_TERMINATE, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
void NodeRegionTerminateCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

