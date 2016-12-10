#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {





bool FinishRemoteStorageConnectionCommand::__init_done = __init_static_variables();
bool FinishRemoteStorageConnectionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FinishRemoteStorageConnectionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FinishRemoteStorageConnectionCommand::FinishRemoteStorageConnectionCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_FINISH;
}
void FinishRemoteStorageConnectionCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_FINISH;
}
 FinishRemoteStorageConnectionCommand::~FinishRemoteStorageConnectionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FinishRemoteStorageConnectionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void FinishRemoteStorageConnectionCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
}
void FinishRemoteStorageConnectionCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	ByteBuffer* buffer = ByteBuffer::allocate(256, ctx);
	buffer->putInt(this->type, ctx);
	IArrayObjectPrimitive<char>* bytes = buffer->array(ctx);
	out->write(bytes, ctx);
}
}}}}

