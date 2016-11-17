#include "includes.h"


namespace alinous {namespace db {namespace table {




constexpr const int IDatabaseRecord::NORMAL_RECORD;
constexpr const int IDatabaseRecord::TRX_CACHE;
constexpr const int IDatabaseRecord::DOM_VARIABLE;
constexpr const int IDatabaseRecord::NULL_PADDING;
bool IDatabaseRecord::__init_done = __init_static_variables();
bool IDatabaseRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDatabaseRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDatabaseRecord::~IDatabaseRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDatabaseRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IBTreeValue::__releaseRegerences(true, ctx);
}
}}}

