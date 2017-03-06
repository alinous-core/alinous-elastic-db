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





bool FinishConnectionCommand::__init_done = __init_static_variables();
bool FinishConnectionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FinishConnectionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FinishConnectionCommand::FinishConnectionCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_FINISH;
}
void FinishConnectionCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_FINISH;
}
 FinishConnectionCommand::~FinishConnectionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FinishConnectionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void FinishConnectionCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
void FinishConnectionCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void FinishConnectionCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractMonitorCommand::TYPE_FINISH, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void FinishConnectionCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

