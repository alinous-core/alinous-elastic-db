#include "includes.h"


namespace alinous {namespace db {namespace table {namespace scan {




constexpr const int IndexScannerLockRequirement::NO_LOCK;
constexpr const int IndexScannerLockRequirement::INSTANT_SHARE;
constexpr const int IndexScannerLockRequirement::EXPLICIT_SHARE;
constexpr const int IndexScannerLockRequirement::INSTANT_UPDATE;
constexpr const int IndexScannerLockRequirement::EXPLICIT_UPDATE;
bool IndexScannerLockRequirement::__init_done = __init_static_variables();
bool IndexScannerLockRequirement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexScannerLockRequirement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexScannerLockRequirement::~IndexScannerLockRequirement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexScannerLockRequirement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}}

