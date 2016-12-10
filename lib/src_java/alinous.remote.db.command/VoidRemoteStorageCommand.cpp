#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {





bool VoidRemoteStorageCommand::__init_done = __init_static_variables();
bool VoidRemoteStorageCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VoidRemoteStorageCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VoidRemoteStorageCommand::VoidRemoteStorageCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_VOID;
}
void VoidRemoteStorageCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_VOID;
}
 VoidRemoteStorageCommand::~VoidRemoteStorageCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VoidRemoteStorageCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void VoidRemoteStorageCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
}
void VoidRemoteStorageCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	ByteBuffer* buffer = ByteBuffer::allocate(256, ctx);
	buffer->putInt(this->type, ctx);
	IArrayObjectPrimitive<char>* bytes = buffer->array(ctx);
	out->write(bytes, ctx);
}
}}}}

