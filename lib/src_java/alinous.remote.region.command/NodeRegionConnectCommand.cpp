#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {





bool NodeRegionConnectCommand::__init_done = __init_static_variables();
bool NodeRegionConnectCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionConnectCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionConnectCommand::~NodeRegionConnectCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionConnectCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void NodeRegionConnectCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
}
void NodeRegionConnectCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
}
}}}}

