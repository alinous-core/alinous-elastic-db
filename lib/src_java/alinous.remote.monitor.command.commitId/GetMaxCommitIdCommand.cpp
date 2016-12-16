#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {





bool GetMaxCommitIdCommand::__init_done = __init_static_variables();
bool GetMaxCommitIdCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GetMaxCommitIdCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GetMaxCommitIdCommand::GetMaxCommitIdCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx), commitId(0)
{
	this->type = AbstractMonitorCommand::TYPE_GET_MAX_COMMIT_ID;
}
void GetMaxCommitIdCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_GET_MAX_COMMIT_ID;
}
 GetMaxCommitIdCommand::~GetMaxCommitIdCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GetMaxCommitIdCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"GetMaxCommitIdCommand", L"~GetMaxCommitIdCommand");
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void GetMaxCommitIdCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
}
void GetMaxCommitIdCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
}
void GetMaxCommitIdCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
}
long long GetMaxCommitIdCommand::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
}}}}}

