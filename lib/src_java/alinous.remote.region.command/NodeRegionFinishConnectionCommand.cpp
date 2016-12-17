#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {





bool NodeRegionFinishConnectionCommand::__init_done = __init_static_variables();
bool NodeRegionFinishConnectionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionFinishConnectionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionFinishConnectionCommand::NodeRegionFinishConnectionCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx)
{
	this->type = NodeRegionVoidCommand::TYPE_FINISH;
}
void NodeRegionFinishConnectionCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = NodeRegionVoidCommand::TYPE_FINISH;
}
 NodeRegionFinishConnectionCommand::~NodeRegionFinishConnectionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionFinishConnectionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void NodeRegionFinishConnectionCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
}
void NodeRegionFinishConnectionCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
}
void NodeRegionFinishConnectionCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	ByteBuffer* buffer = ByteBuffer::allocate(256, ctx);
	buffer->putInt(this->type, ctx);
	IArrayObjectPrimitive<char>* bytes = buffer->array(ctx);
	out->write(bytes, ctx);
}
}}}}

