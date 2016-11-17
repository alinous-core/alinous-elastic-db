#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace result {





constexpr const int AbstructSelectResult::ALL_COLUMNS;
constexpr const int AbstructSelectResult::COLUMN;
constexpr const int AbstructSelectResult::FUNCTION;
bool AbstructSelectResult::__init_done = __init_static_variables();
bool AbstructSelectResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstructSelectResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstructSelectResult::~AbstructSelectResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstructSelectResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstructSelectResult", L"~AbstructSelectResult");
	__e_obj1.add(this->outputName, this);
	outputName = nullptr;
	if(!prepare){
		return;
	}
}
}}}}

