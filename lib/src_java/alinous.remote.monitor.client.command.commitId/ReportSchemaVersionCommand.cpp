#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.monitor.client.command/MinitorCommandReader.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command.commitId/ReportSchemaVersionCommand.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace commitId {





bool ReportSchemaVersionCommand::__init_done = __init_static_variables();
bool ReportSchemaVersionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ReportSchemaVersionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ReportSchemaVersionCommand::ReportSchemaVersionCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_REPORT_SCHEMA_UPDATED;
}
void ReportSchemaVersionCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_REPORT_SCHEMA_UPDATED;
}
 ReportSchemaVersionCommand::~ReportSchemaVersionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ReportSchemaVersionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void ReportSchemaVersionCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	monitorServer->updateSchemaVersion(ctx);
	writeByteStream(outStream, ctx);
}
void ReportSchemaVersionCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
}
void ReportSchemaVersionCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractMonitorCommand::TYPE_REPORT_SCHEMA_UPDATED, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void ReportSchemaVersionCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

