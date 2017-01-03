#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {





bool TerminateCommand::__init_done = __init_static_variables();
bool TerminateCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TerminateCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TerminateCommand::TerminateCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_TERMINATE;
}
void TerminateCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_TERMINATE;
}
 TerminateCommand::~TerminateCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TerminateCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void TerminateCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
void TerminateCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void TerminateCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractMonitorCommand::TYPE_TERMINATE, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
}}}}

