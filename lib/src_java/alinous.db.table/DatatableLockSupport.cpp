#include "includes.h"


namespace alinous {namespace db {namespace table {





bool DatatableLockSupport::__init_done = __init_static_variables();
bool DatatableLockSupport::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatatableLockSupport", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatatableLockSupport::DatatableLockSupport(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw()  : IObject(ctx), DataTableStorageSupport(schema, name, baseDir, ctx)
{
}
void DatatableLockSupport::__construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() 
{
}
 DatatableLockSupport::~DatatableLockSupport() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatatableLockSupport::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DataTableStorageSupport::__releaseRegerences(true, ctx);
}
void DatatableLockSupport::lockStorage(ThreadContext* ctx)
{
	this->storageLock->close(ctx);
}
void DatatableLockSupport::unlockStorage(ThreadContext* ctx)
{
	this->storageLock->open(ctx);
}
void DatatableLockSupport::sharelockStorage(ThreadContext* ctx)
{
	this->storageLock->enter(ctx);
}
void DatatableLockSupport::shareunlockStorage(ThreadContext* ctx) throw() 
{
	this->storageLock->exit(ctx);
}
}}}

