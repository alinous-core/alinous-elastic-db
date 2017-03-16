#include "include/global.h"


#include "alinous.btree/IBTree.h"
#include "alinous.remote.db.server.commit/InsertStore.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {





bool InsertStore::__init_done = __init_static_variables();
bool InsertStore::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InsertStore", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InsertStore::InsertStore(ThreadContext* ctx) throw()  : IObject(ctx), store(nullptr)
{
}
void InsertStore::__construct_impl(ThreadContext* ctx) throw() 
{
}
 InsertStore::~InsertStore() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InsertStore::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InsertStore", L"~InsertStore");
	__e_obj1.add(this->store, this);
	store = nullptr;
	if(!prepare){
		return;
	}
}
InsertStore* InsertStore::init(ThreadContext* ctx) throw() 
{
	return this;
}
void InsertStore::__cleanUp(ThreadContext* ctx){
}
}}}}}

