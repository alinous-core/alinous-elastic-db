#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {





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
	default:
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3494(), ctx));
		break;
	}
	cmd->readFromStream(stream, size, ctx);
	return cmd;
}
}}}}

