#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommand.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {





bool ClientScanCommand::__init_done = __init_static_variables();
bool ClientScanCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientScanCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientScanCommand::ClientScanCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx)
{
	this->type = AbstractNodeRegionCommand::TYPE_SCAN;
}
void ClientScanCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_SCAN;
}
 ClientScanCommand::~ClientScanCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientScanCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void ClientScanCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void ClientScanCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
void ClientScanCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
}
void ClientScanCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

