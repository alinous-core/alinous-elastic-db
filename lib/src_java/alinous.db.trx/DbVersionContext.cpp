#include "includes.h"


namespace alinous {namespace db {namespace trx {





bool DbVersionContext::__init_done = __init_static_variables();
bool DbVersionContext::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbVersionContext", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbVersionContext::~DbVersionContext() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbVersionContext::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbVersionContext", L"~DbVersionContext");
	if(!prepare){
		return;
	}
}
long long DbVersionContext::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void DbVersionContext::setCommitId(long long commitId, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
}
long long DbVersionContext::getSchemaVersion(ThreadContext* ctx) throw() 
{
	return schemaVersion;
}
void DbVersionContext::setSchemaVersion(long long schemaVersion, ThreadContext* ctx) throw() 
{
	this->schemaVersion = schemaVersion;
}
long long DbVersionContext::getNodeClusterVersion(ThreadContext* ctx) throw() 
{
	return nodeClusterVersion;
}
void DbVersionContext::setNodeClusterVersion(long long nodeClusterVersion, ThreadContext* ctx) throw() 
{
	this->nodeClusterVersion = nodeClusterVersion;
}
long long DbVersionContext::getTrxId(ThreadContext* ctx) throw() 
{
	return trxId;
}
void DbVersionContext::setTrxId(long long trxId, ThreadContext* ctx) throw() 
{
	this->trxId = trxId;
}
}}}

