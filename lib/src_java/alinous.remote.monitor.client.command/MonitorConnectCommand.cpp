#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command/TerminateCommand.h"
#include "alinous.remote.monitor.client.command/FinishConnectionCommand.h"
#include "alinous.remote.monitor.client.command/VoidCommand.h"
#include "alinous.remote.monitor.client.command/MonitorConnectCommand.h"
#include "alinous.remote.monitor.client.command/GetRegionNodeInfoCommand.h"
#include "alinous.remote.monitor.client.command/MinitorCommandReader.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {





bool MonitorConnectCommand::__init_done = __init_static_variables();
bool MonitorConnectCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MonitorConnectCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MonitorConnectCommand::MonitorConnectCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx), connected(0)
{
	this->type = AbstractMonitorCommand::TYPE_CONNECT;
}
void MonitorConnectCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_CONNECT;
}
 MonitorConnectCommand::~MonitorConnectCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MonitorConnectCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MonitorConnectCommand", L"~MonitorConnectCommand");
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void MonitorConnectCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	int res = buff->getInt(ctx);
	this->connected = (res == 1);
}
void MonitorConnectCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	this->connected = true;
	writeByteStream(outStream, ctx);
}
bool MonitorConnectCommand::isConnected(ThreadContext* ctx) throw() 
{
	return connected;
}
void MonitorConnectCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractMonitorCommand::TYPE_CONNECT, ctx);
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
void MonitorConnectCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

