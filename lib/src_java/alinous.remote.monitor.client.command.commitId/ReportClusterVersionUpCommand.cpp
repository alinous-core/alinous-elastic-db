#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command.commitId/GetMaxCommitIdCommand.h"
#include "alinous.remote.monitor.client.command.commitId/NewCommitIdCommand.h"
#include "alinous.remote.monitor.client.command.commitId/NewTransactionCommand.h"
#include "alinous.remote.monitor.client.command.commitId/ReportSchemaVersionCommand.h"
#include "alinous.remote.monitor.client.command.commitId/ReportClusterVersionUpCommand.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace commitId {





bool ReportClusterVersionUpCommand::__init_done = __init_static_variables();
bool ReportClusterVersionUpCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ReportClusterVersionUpCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ReportClusterVersionUpCommand::ReportClusterVersionUpCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx), nodeClusterRevision(0)
{
	this->type = AbstractMonitorCommand::TYPE_REPORT_CLUSTER_UPDATED;
}
void ReportClusterVersionUpCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_REPORT_CLUSTER_UPDATED;
}
 ReportClusterVersionUpCommand::~ReportClusterVersionUpCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ReportClusterVersionUpCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ReportClusterVersionUpCommand", L"~ReportClusterVersionUpCommand");
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void ReportClusterVersionUpCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	monitorServer->updateNodeClusterVersion(this->nodeClusterRevision, ctx);
	writeByteStream(outStream, ctx);
}
void ReportClusterVersionUpCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->nodeClusterRevision = buff->getLong(ctx);
}
long long ReportClusterVersionUpCommand::getNodeClusterRevision(ThreadContext* ctx) throw() 
{
	return nodeClusterRevision;
}
void ReportClusterVersionUpCommand::setNodeClusterRevision(long long nodeClusterRevision, ThreadContext* ctx) throw() 
{
	this->nodeClusterRevision = nodeClusterRevision;
}
void ReportClusterVersionUpCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractMonitorCommand::TYPE_REPORT_CLUSTER_UPDATED, ctx);
	buff->putLong(this->nodeClusterRevision, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void ReportClusterVersionUpCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

