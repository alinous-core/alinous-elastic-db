#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.server/StorageTransaction.h"

namespace alinous {namespace remote {namespace db {namespace server {





bool StorageTransaction::__init_done = __init_static_variables();
bool StorageTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StorageTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StorageTransaction::StorageTransaction(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw()  : IObject(ctx), isolationLevel(0), vctx(nullptr), datadir(nullptr), tmpDir(nullptr), server(nullptr)
{
	this->isolationLevel = isolationLevel;
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
	__GC_MV(this, &(this->datadir), datadir, String);
	__GC_MV(this, &(this->server), server, RemoteTableStorageServer);
}
void StorageTransaction::__construct_impl(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() 
{
	this->isolationLevel = isolationLevel;
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
	__GC_MV(this, &(this->datadir), datadir, String);
	__GC_MV(this, &(this->server), server, RemoteTableStorageServer);
}
 StorageTransaction::~StorageTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StorageTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StorageTransaction", L"~StorageTransaction");
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	__e_obj1.add(this->datadir, this);
	datadir = nullptr;
	__e_obj1.add(this->tmpDir, this);
	tmpDir = nullptr;
	__e_obj1.add(this->server, this);
	server = nullptr;
	if(!prepare){
		return;
	}
}
String* StorageTransaction::getTmpDir(ThreadContext* ctx) throw() 
{
	if(this->tmpDir != nullptr)
	{
		return this->tmpDir;
	}
	StringBuilder* buff = (new(ctx) StringBuilder(256, ctx));
	buff->append(this->datadir, ctx);
	if(!this->datadir->endsWith(ConstStr::getCNST_STR_949(), ctx) && !this->datadir->endsWith(ConstStr::getCNST_STR_1789(), ctx))
	{
		buff->append(ConstStr::getCNST_STR_949(), ctx);
	}
	buff->append(ConstStr::getCNST_STR_3586(), ctx);
	String* strTrxId = Long::toString(this->vctx->getTrxId(ctx), ctx);
	buff->append(strTrxId, ctx);
	__GC_MV(this, &(this->tmpDir), buff->toString(ctx), String);
	return this->tmpDir;
}
int StorageTransaction::getIsolationLevel(ThreadContext* ctx) throw() 
{
	return isolationLevel;
}
DbVersionContext* StorageTransaction::getVctx(ThreadContext* ctx) throw() 
{
	return vctx;
}
void StorageTransaction::dispose(ThreadContext* ctx) throw() 
{
}
void StorageTransaction::__cleanUp(ThreadContext* ctx){
}
}}}}

