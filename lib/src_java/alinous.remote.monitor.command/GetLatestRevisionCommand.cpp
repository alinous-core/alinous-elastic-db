#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {





bool GetLatestRevisionCommand::__init_done = __init_static_variables();
bool GetLatestRevisionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GetLatestRevisionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GetLatestRevisionCommand::GetLatestRevisionCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_GET_LATEST_REVISION;
}
void GetLatestRevisionCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_GET_LATEST_REVISION;
}
 GetLatestRevisionCommand::~GetLatestRevisionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GetLatestRevisionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void GetLatestRevisionCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
}
void GetLatestRevisionCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
}
void GetLatestRevisionCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
}
}}}}

