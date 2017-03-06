#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command/TerminateCommand.h"
#include "alinous.remote.monitor.client.command/FinishConnectionCommand.h"
#include "alinous.remote.monitor.client.command/VoidCommand.h"
#include "alinous.remote.monitor.client.command/MonitorConnectCommand.h"
#include "alinous.remote.monitor.client.command/GetRegionNodeInfoCommand.h"
#include "alinous.remote.monitor.client.command/MinitorCommandReader.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {





constexpr const int AbstractMonitorCommand::TYPE_VOID;
constexpr const int AbstractMonitorCommand::TYPE_FINISH;
constexpr const int AbstractMonitorCommand::TYPE_CONNECT;
constexpr const int AbstractMonitorCommand::TYPE_GET_MAX_COMMIT_ID;
constexpr const int AbstractMonitorCommand::TYPE_NEW_MAX_COMMIT_ID;
constexpr const int AbstractMonitorCommand::TYPE_GET_REGION_INFO;
constexpr const int AbstractMonitorCommand::TYPE_NEW_TRANSACTION;
constexpr const int AbstractMonitorCommand::TYPE_REPORT_SCHEMA_UPDATED;
constexpr const int AbstractMonitorCommand::TYPE_REPORT_CLUSTER_UPDATED;
constexpr const int AbstractMonitorCommand::TYPE_TERMINATE;
bool AbstractMonitorCommand::__init_done = __init_static_variables();
bool AbstractMonitorCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractMonitorCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractMonitorCommand::AbstractMonitorCommand(ThreadContext* ctx) throw()  : IObject(ctx), type(0), errorMessage(nullptr), retCode(0)
{
}
void AbstractMonitorCommand::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractMonitorCommand::~AbstractMonitorCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractMonitorCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractMonitorCommand", L"~AbstractMonitorCommand");
	__e_obj1.add(this->errorMessage, this);
	errorMessage = nullptr;
	if(!prepare){
		return;
	}
}
int AbstractMonitorCommand::getType(ThreadContext* ctx) throw() 
{
	return type;
}
AbstractMonitorCommand* AbstractMonitorCommand::sendCommand(AlinousSocket* socket, ThreadContext* ctx)
{
	OutputStream* out = socket->getOutputStream(ctx);
	writeByteStream(out, ctx);
	out->flush(ctx);
	InputStream* stream = socket->getInputStream(ctx);
	AbstractMonitorCommand* cmd = MinitorCommandReader::readFromStream(stream, ctx);
	return cmd;
}
bool AbstractMonitorCommand::hasError(ThreadContext* ctx) throw() 
{
	return this->errorMessage != nullptr;
}
List<String>* AbstractMonitorCommand::getErrorMessage(ThreadContext* ctx) throw() 
{
	return errorMessage;
}
void AbstractMonitorCommand::handleError(Throwable* e, ThreadContext* ctx) throw() 
{
	GCUtils<List<String> >::mv(this, &(this->errorMessage), (new(ctx) ArrayList<String>(ctx)), ctx);
	Throwable* cur = e;
	while(cur != nullptr)
	{
		String* msg = e->getMessage(ctx);
		this->errorMessage->add(msg, ctx);
		cur = cur->getCause(ctx);
	}
}
void AbstractMonitorCommand::writeErrorByteStream(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	bool er = hasError(ctx);
	buff->putBoolean(er, ctx);
	if(er)
	{
		int maxLoop = this->errorMessage->size(ctx);
		buff->putInt(maxLoop, ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			String* msg = this->errorMessage->get(i, ctx);
			buff->putString(msg, ctx);
		}
	}
}
void AbstractMonitorCommand::readErrorFromStream(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	GCUtils<List<String> >::mv(this, &(this->errorMessage), (new(ctx) ArrayList<String>(ctx)), ctx);
	bool er = buff->getBoolean(ctx);
	if(er)
	{
		int maxLoop = buff->getInt(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			String* msg = buff->getString(ctx);
			this->errorMessage->add(msg, ctx);
		}
	}
}
void AbstractMonitorCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

