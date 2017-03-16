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
#include "alinous.remote.region.client.command.dml/ClientInsertDataCommand.h"
#include "alinous.remote.region.client.command.dml/ClientTpcCommitSessionCommand.h"
#include "alinous.remote.socket/NetworkBinalyUtils.h"
#include "alinous.remote.region.client.command/NodeRegionFinishConnectionCommand.h"
#include "alinous.remote.region.client.command/NodeRegionTerminateCommand.h"
#include "alinous.remote.region.client.command/NodeRegionVoidCommand.h"
#include "alinous.remote.region.client.command/GetSchemaFromRegionCommand.h"
#include "alinous.remote.region.client.command/NodeRegionCommandReader.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {





bool NodeRegionCommandReader::__init_done = __init_static_variables();
bool NodeRegionCommandReader::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionCommandReader", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionCommandReader::NodeRegionCommandReader(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void NodeRegionCommandReader::__construct_impl(ThreadContext* ctx) throw() 
{
}
 NodeRegionCommandReader::~NodeRegionCommandReader() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionCommandReader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
AbstractNodeRegionCommand* NodeRegionCommandReader::readFromStream(InputStream* stream, ThreadContext* ctx)
{
	int size = NetworkBinalyUtils::readInt(stream, ctx) - 4 * 2;
	int type = NetworkBinalyUtils::readInt(stream, ctx);
	AbstractNodeRegionCommand* cmd = nullptr;
	switch(type) {
	case AbstractNodeRegionCommand::TYPE_FINISH:
		cmd = (new(ctx) NodeRegionFinishConnectionCommand(ctx));
		break ;
	case AbstractNodeRegionCommand::TYPE_TERMINATE:
		cmd = (new(ctx) NodeRegionTerminateCommand(ctx));
		break ;
	case AbstractNodeRegionCommand::TYPE_VOID:
		cmd = (new(ctx) NodeRegionVoidCommand(ctx));
		break ;
	case AbstractNodeRegionCommand::TYPE_CONNECT:
		cmd = (new(ctx) NodeRegionConnectCommand(ctx));
		break ;
	case AbstractNodeRegionCommand::TYPE_GET_SCHEMA_FROM_REGION:
		cmd = (new(ctx) GetSchemaFromRegionCommand(ctx));
		break ;
	case AbstractNodeRegionCommand::TYPE_CREATE_SCHEMA:
		cmd = (new(ctx) RegionCreateSchemaCommand(ctx));
		break ;
	case AbstractNodeRegionCommand::TYPE_CREATE_TABLE:
		cmd = (new(ctx) RegionCreateTableCommand(ctx));
		break ;
	case AbstractNodeRegionCommand::TYPE_INSERT_DATA:
		cmd = (new(ctx) ClientInsertDataCommand(ctx));
		break ;
	case AbstractNodeRegionCommand::TYPE_TPC_COMMIT_SESSION:
		cmd = (new(ctx) ClientTpcCommitSessionCommand(ctx));
		break ;
	default:
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3601(), ctx));
		break;
	}
	cmd->readFromStream(stream, size, ctx);
	return cmd;
}
void NodeRegionCommandReader::__cleanUp(ThreadContext* ctx){
}
}}}}}

