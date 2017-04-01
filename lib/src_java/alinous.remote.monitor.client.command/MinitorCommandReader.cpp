#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command.commitId/GetMaxCommitIdCommand.h"
#include "alinous.remote.monitor.client.command.commitId/NewCommitIdCommand.h"
#include "alinous.remote.monitor.client.command.commitId/NewTransactionCommand.h"
#include "alinous.remote.monitor.client.command.commitId/ReportClusterVersionUpCommand.h"
#include "alinous.remote.monitor.client.command.commitId/ReportSchemaVersionCommand.h"
#include "alinous.remote.socket/NetworkBinalyUtils.h"
#include "alinous.remote.monitor.client.command/FinishConnectionCommand.h"
#include "alinous.remote.monitor.client.command/TerminateCommand.h"
#include "alinous.remote.monitor.client.command/VoidCommand.h"
#include "alinous.remote.monitor.client.command/MonitorConnectCommand.h"
#include "alinous.remote.monitor.client.command/GetRegionNodeInfoCommand.h"
#include "alinous.remote.monitor.client.command/AllocOidCommand.h"
#include "alinous.remote.monitor.client.command/MinitorCommandReader.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {





bool MinitorCommandReader::__init_done = __init_static_variables();
bool MinitorCommandReader::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MinitorCommandReader", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MinitorCommandReader::MinitorCommandReader(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void MinitorCommandReader::__construct_impl(ThreadContext* ctx) throw() 
{
}
 MinitorCommandReader::~MinitorCommandReader() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MinitorCommandReader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
AbstractMonitorCommand* MinitorCommandReader::readFromStream(InputStream* stream, ThreadContext* ctx)
{
	int size = NetworkBinalyUtils::readInt(stream, ctx) - 4 * 2;
	int type = NetworkBinalyUtils::readInt(stream, ctx);
	AbstractMonitorCommand* cmd = nullptr;
	switch(type) {
	case AbstractMonitorCommand::TYPE_FINISH:
		cmd = (new(ctx) FinishConnectionCommand(ctx));
		break ;
	case AbstractMonitorCommand::TYPE_TERMINATE:
		cmd = (new(ctx) TerminateCommand(ctx));
		break ;
	case AbstractMonitorCommand::TYPE_VOID:
		cmd = (new(ctx) VoidCommand(ctx));
		break ;
	case AbstractMonitorCommand::TYPE_CONNECT:
		cmd = (new(ctx) MonitorConnectCommand(ctx));
		break ;
	case AbstractMonitorCommand::TYPE_GET_MAX_COMMIT_ID:
		cmd = (new(ctx) GetMaxCommitIdCommand(ctx));
		break ;
	case AbstractMonitorCommand::TYPE_NEW_MAX_COMMIT_ID:
		cmd = (new(ctx) NewCommitIdCommand(ctx));
		break ;
	case AbstractMonitorCommand::TYPE_GET_REGION_INFO:
		cmd = (new(ctx) GetRegionNodeInfoCommand(ctx));
		break ;
	case AbstractMonitorCommand::TYPE_NEW_TRANSACTION:
		cmd = (new(ctx) NewTransactionCommand(ctx));
		break ;
	case AbstractMonitorCommand::TYPE_REPORT_SCHEMA_UPDATED:
		cmd = (new(ctx) ReportSchemaVersionCommand(ctx));
		break ;
	case AbstractMonitorCommand::TYPE_REPORT_CLUSTER_UPDATED:
		cmd = (new(ctx) ReportClusterVersionUpCommand(ctx));
		break ;
	case AbstractMonitorCommand::TYPE_ALLOC_OID:
		cmd = (new(ctx) AllocOidCommand(ctx));
		break ;
	default:
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3583(), ctx));
		break;
	}
	cmd->readFromStream(stream, size, ctx);
	return cmd;
}
void MinitorCommandReader::__cleanUp(ThreadContext* ctx){
}
}}}}}

