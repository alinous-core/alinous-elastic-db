#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.monitor.client.command.data/OidSchemaContainer.h"
#include "alinous.remote.monitor.client.command/MinitorCommandReader.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command/ReportMaxOidCommand.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {





bool ReportMaxOidCommand::__init_done = __init_static_variables();
bool ReportMaxOidCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ReportMaxOidCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ReportMaxOidCommand::ReportMaxOidCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx), oids(nullptr)
{
	this->type = AbstractMonitorCommand::TYPE_REPORT_OID;
}
void ReportMaxOidCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_REPORT_OID;
}
 ReportMaxOidCommand::~ReportMaxOidCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ReportMaxOidCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ReportMaxOidCommand", L"~ReportMaxOidCommand");
	__e_obj1.add(this->oids, this);
	oids = nullptr;
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void ReportMaxOidCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void ReportMaxOidCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
OidSchemaContainer* ReportMaxOidCommand::getOids(ThreadContext* ctx) throw() 
{
	return oids;
}
void ReportMaxOidCommand::setOids(OidSchemaContainer* oids, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->oids), oids, OidSchemaContainer);
}
void ReportMaxOidCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
}
void ReportMaxOidCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

