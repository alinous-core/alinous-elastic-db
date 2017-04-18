#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.remote.region.server/NodeRegionResponceAction.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command/NodeRegionConnectCommand.h"
#include "alinous.remote.region.client.command.ddl/RegionCreateSchemaCommand.h"
#include "alinous.remote.region.client.command.ddl/RegionCreateTableCommand.h"
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





constexpr const int AbstractNodeRegionCommand::TYPE_VOID;
constexpr const int AbstractNodeRegionCommand::TYPE_FINISH;
constexpr const int AbstractNodeRegionCommand::TYPE_CONNECT;
constexpr const int AbstractNodeRegionCommand::TYPE_TERMINATE;
constexpr const int AbstractNodeRegionCommand::TYPE_GET_SCHEMA_FROM_REGION;
constexpr const int AbstractNodeRegionCommand::TYPE_CREATE_SCHEMA;
constexpr const int AbstractNodeRegionCommand::TYPE_CREATE_TABLE;
constexpr const int AbstractNodeRegionCommand::TYPE_INSERT_DATA;
constexpr const int AbstractNodeRegionCommand::TYPE_TPC_COMMIT_SESSION;
constexpr const int AbstractNodeRegionCommand::TYPE_SCAN;
constexpr const int AbstractNodeRegionCommand::TYPE_SCAN_END;
bool AbstractNodeRegionCommand::__init_done = __init_static_variables();
bool AbstractNodeRegionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractNodeRegionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractNodeRegionCommand::AbstractNodeRegionCommand(ThreadContext* ctx) throw()  : IObject(ctx), type(0), errorMessage(nullptr)
{
}
void AbstractNodeRegionCommand::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractNodeRegionCommand::~AbstractNodeRegionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractNodeRegionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractNodeRegionCommand", L"~AbstractNodeRegionCommand");
	__e_obj1.add(this->errorMessage, this);
	errorMessage = nullptr;
	if(!prepare){
		return;
	}
}
int AbstractNodeRegionCommand::getType(ThreadContext* ctx) throw() 
{
	return type;
}
AbstractNodeRegionCommand* AbstractNodeRegionCommand::sendCommand(AlinousSocket* socket, ThreadContext* ctx)
{
	OutputStream* out = socket->getOutputStream(ctx);
	writeByteStream(out, ctx);
	out->flush(ctx);
	InputStream* stream = socket->getInputStream(ctx);
	AbstractNodeRegionCommand* cmd = NodeRegionCommandReader::readFromStream(stream, ctx);
	return cmd;
}
bool AbstractNodeRegionCommand::hasError(ThreadContext* ctx) throw() 
{
	return this->errorMessage != nullptr;
}
List<String>* AbstractNodeRegionCommand::getErrorMessage(ThreadContext* ctx) throw() 
{
	return errorMessage;
}
void AbstractNodeRegionCommand::handleError(Throwable* e, ThreadContext* ctx) throw() 
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
void AbstractNodeRegionCommand::writeErrorByteStream(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
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
void AbstractNodeRegionCommand::readErrorFromStream(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	bool er = buff->getBoolean(ctx);
	if(er)
	{
		GCUtils<List<String> >::mv(this, &(this->errorMessage), (new(ctx) ArrayList<String>(ctx)), ctx);
		int maxLoop = buff->getInt(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			String* msg = buff->getString(ctx);
			this->errorMessage->add(msg, ctx);
		}
	}
}
void AbstractNodeRegionCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

