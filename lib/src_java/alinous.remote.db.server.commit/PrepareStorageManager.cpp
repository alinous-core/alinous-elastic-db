#include "include/global.h"


#include "alinous.remote.db.server.commit/PrepareStorageManager.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {





bool PrepareStorageManager::__init_done = __init_static_variables();
bool PrepareStorageManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"PrepareStorageManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 PrepareStorageManager::PrepareStorageManager(String* tmpDir, long long strxId, ThreadContext* ctx) throw()  : IObject(ctx), tmpDir(nullptr), strxId(0)
{
	__GC_MV(this, &(this->tmpDir), tmpDir, String);
}
void PrepareStorageManager::__construct_impl(String* tmpDir, long long strxId, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tmpDir), tmpDir, String);
}
 PrepareStorageManager::~PrepareStorageManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void PrepareStorageManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"PrepareStorageManager", L"~PrepareStorageManager");
	__e_obj1.add(this->tmpDir, this);
	tmpDir = nullptr;
	if(!prepare){
		return;
	}
}
void PrepareStorageManager::__cleanUp(ThreadContext* ctx){
}
}}}}}

