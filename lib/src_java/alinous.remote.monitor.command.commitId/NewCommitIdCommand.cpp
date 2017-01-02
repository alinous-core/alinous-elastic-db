#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {





bool NewCommitIdCommand::__init_done = __init_static_variables();
bool NewCommitIdCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NewCommitIdCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NewCommitIdCommand::NewCommitIdCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx), commitId(0)
{
	this->type = AbstractMonitorCommand::TYPE_NEW_MAX_COMMIT_ID;
}
void NewCommitIdCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_NEW_MAX_COMMIT_ID;
}
 NewCommitIdCommand::~NewCommitIdCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NewCommitIdCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NewCommitIdCommand", L"~NewCommitIdCommand");
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void NewCommitIdCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
}
void NewCommitIdCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
long long NewCommitIdCommand::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void NewCommitIdCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
}
}}}}}

