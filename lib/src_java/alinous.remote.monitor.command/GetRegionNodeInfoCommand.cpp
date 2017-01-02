#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {





bool GetRegionNodeInfoCommand::__init_done = __init_static_variables();
bool GetRegionNodeInfoCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GetRegionNodeInfoCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GetRegionNodeInfoCommand::GetRegionNodeInfoCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_GET_REGION_INFO;
}
void GetRegionNodeInfoCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_GET_REGION_INFO;
}
 GetRegionNodeInfoCommand::~GetRegionNodeInfoCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GetRegionNodeInfoCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void GetRegionNodeInfoCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
}
void GetRegionNodeInfoCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
void GetRegionNodeInfoCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
}
}}}}

