#include "includes.h"


namespace alinous {namespace remote {namespace region {





bool NodeReferenceManager::__init_done = __init_static_variables();
bool NodeReferenceManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeReferenceManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeReferenceManager::~NodeReferenceManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeReferenceManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeReferenceManager", L"~NodeReferenceManager");
	__e_obj1.add(this->tablesDictinary, this);
	tablesDictinary = nullptr;
	if(!prepare){
		return;
	}
}
Map<String,NodeReference>* NodeReferenceManager::getTablesDictinary(ThreadContext* ctx) throw() 
{
	return tablesDictinary;
}
}}}

