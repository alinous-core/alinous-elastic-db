#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"

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
 DbVersionContext::DbVersionContext(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), commitId(0), trxId(0), schemaVersion(0), nodeClusterVersion(0)
{
}
void DbVersionContext::__construct_impl(ThreadContext* ctx) throw() 
{
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
void DbVersionContext::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->commitId = buff->getLong(ctx);
	this->trxId = buff->getLong(ctx);
	this->schemaVersion = buff->getLong(ctx);
	this->nodeClusterVersion = buff->getLong(ctx);
}
void DbVersionContext::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putLong(this->commitId, ctx);
	buff->putLong(this->trxId, ctx);
	buff->putLong(this->schemaVersion, ctx);
	buff->putLong(this->nodeClusterVersion, ctx);
}
void DbVersionContext::__cleanUp(ThreadContext* ctx){
}
}}}

