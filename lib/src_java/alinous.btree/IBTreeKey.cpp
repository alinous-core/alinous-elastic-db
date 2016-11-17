#include "includes.h"


namespace alinous {namespace btree {




constexpr const int IBTreeKey::TYPE_SIZE;
constexpr const int IBTreeKey::TYPE_INT;
constexpr const int IBTreeKey::TYPE_LONG;
constexpr const int IBTreeKey::TYPE_STRING;
constexpr const int IBTreeKey::TYPE_TIMESTAMP;
constexpr const int IBTreeKey::TYPE_DOUBLE;
constexpr const int IBTreeKey::TYPE_BTREE_INDEX_KEY;
constexpr const int IBTreeKey::TYPE_SCAN_RESULT_INDEX_KEY;
bool IBTreeKey::__init_done = __init_static_variables();
bool IBTreeKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IBTreeKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IBTreeKey::~IBTreeKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IBTreeKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	Comparable<IBTreeKey>::__releaseRegerences(true, ctx);
}
}}

