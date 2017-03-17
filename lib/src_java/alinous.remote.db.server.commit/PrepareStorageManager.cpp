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
 PrepareStorageManager::PrepareStorageManager(String* tmpDir, long long strxId, ThreadContext* ctx) throw()  : IObject(ctx), tmpDir(nullptr), strxId(0), filePath(nullptr)
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
	__e_obj1.add(this->filePath, this);
	filePath = nullptr;
	if(!prepare){
		return;
	}
}
String* PrepareStorageManager::getFilePath(ThreadContext* ctx) throw() 
{
	if(this->filePath != nullptr)
	{
		return filePath;
	}
	StringBuilder* buff = (new(ctx) StringBuilder(256, ctx));
	buff->append(this->tmpDir, ctx);
	if(!this->tmpDir->endsWith(ConstStr::getCNST_STR_949(), ctx) && !this->tmpDir->endsWith(ConstStr::getCNST_STR_1789(), ctx))
	{
		buff->append(ConstStr::getCNST_STR_949(), ctx);
	}
	buff->append(ConstStr::getCNST_STR_3592(), ctx)->append(Long::toString(this->strxId, ctx), ctx)->append(ConstStr::getCNST_STR_949(), ctx);
	__GC_MV(this, &(this->filePath), buff->toString(ctx), String);
	return this->filePath;
}
void PrepareStorageManager::__cleanUp(ThreadContext* ctx){
}
}}}}}

