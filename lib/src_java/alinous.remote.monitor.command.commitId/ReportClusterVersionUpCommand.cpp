#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/RemoteNodeReference.h"
#include "alinous.system.config.remote/Region.h"
#include "alinous.remote.monitor/NodeInfo.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.monitor.command.data/RegionInfoData.h"
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.system.config.remote/Regions.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.remote.monitor/RegionNodeInfoManager.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.monitor.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.command.commitId/GetMaxCommitIdCommand.h"
#include "alinous.remote.monitor.command.commitId/NewCommitIdCommand.h"
#include "alinous.remote.monitor.command.commitId/NewTransactionCommand.h"
#include "alinous.remote.monitor.command.commitId/ReportSchemaVersionCommand.h"
#include "alinous.remote.monitor.command.commitId/ReportClusterVersionUpCommand.h"

namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {





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
}}}}}

