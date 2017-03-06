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





bool VoidCommand::__init_done = __init_static_variables();
bool VoidCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VoidCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VoidCommand::VoidCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_VOID;
}
void VoidCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_VOID;
}
 VoidCommand::~VoidCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VoidCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void VoidCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
void VoidCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void VoidCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractMonitorCommand::TYPE_VOID, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void VoidCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

