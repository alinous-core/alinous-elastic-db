#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {





bool NodeRegionVoidCommand::__init_done = __init_static_variables();
bool NodeRegionVoidCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionVoidCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionVoidCommand::NodeRegionVoidCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx)
{
	this->type = NodeRegionVoidCommand::TYPE_VOID;
}
void NodeRegionVoidCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = NodeRegionVoidCommand::TYPE_VOID;
}
 NodeRegionVoidCommand::~NodeRegionVoidCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionVoidCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void NodeRegionVoidCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
}
void NodeRegionVoidCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
}
void NodeRegionVoidCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	ByteBuffer* buffer = ByteBuffer::allocate(256, ctx);
	buffer->putInt(this->type, ctx);
	IArrayObjectPrimitive<char>* bytes = buffer->array(ctx);
	out->write(bytes, ctx);
}
}}}}

