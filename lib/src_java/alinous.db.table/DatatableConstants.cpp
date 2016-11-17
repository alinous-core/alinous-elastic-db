#include "includes.h"


namespace alinous {namespace db {namespace table {




constexpr const int DatatableConstants::capacity;
constexpr const int DatatableConstants::BLOCK_SIZE;
constexpr const int DatatableConstants::maxCache;
bool DatatableConstants::__init_done = __init_static_variables();
bool DatatableConstants::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatatableConstants", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatatableConstants::~DatatableConstants() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatatableConstants::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}

