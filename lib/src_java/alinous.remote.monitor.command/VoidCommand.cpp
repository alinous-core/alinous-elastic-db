#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {





bool VoidCommand::__init_done = __init_static_variables();
bool VoidCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VoidCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VoidCommand::VoidCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_VOID;
}
void VoidCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_VOID;
}
 VoidCommand::~VoidCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VoidCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void VoidCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
}
void VoidCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
}
void VoidCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	ByteBuffer* buffer = ByteBuffer::allocate(256, ctx);
	buffer->putInt(this->type, ctx);
	IArrayObjectPrimitive<char>* bytes = buffer->array(ctx);
	out->write(bytes, ctx);
}
}}}}

