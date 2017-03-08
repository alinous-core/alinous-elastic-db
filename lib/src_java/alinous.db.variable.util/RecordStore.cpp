#include "include/global.h"


#include "alinous.db.variable.util/RecordStore.h"

namespace alinous {namespace db {namespace variable {namespace util {





bool RecordStore::__init_done = __init_static_variables();
bool RecordStore::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RecordStore", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RecordStore::RecordStore(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void RecordStore::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RecordStore::~RecordStore() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RecordStore::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void RecordStore::__cleanUp(ThreadContext* ctx){
}
}}}}

