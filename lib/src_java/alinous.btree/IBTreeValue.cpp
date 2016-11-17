#include "includes.h"


namespace alinous {namespace btree {




constexpr const int IBTreeValue::TYPE_SIZE;
constexpr const int IBTreeValue::TYPE_INT;
constexpr const int IBTreeValue::TYPE_LONG;
constexpr const int IBTreeValue::TYPE_STRING;
constexpr const int IBTreeValue::TYPE_TIMESTAMP;
constexpr const int IBTreeValue::TYPE_DOUBLE;
constexpr const int IBTreeValue::TYPE_SCHEME;
constexpr const int IBTreeValue::TYPE_CACHE_RECORD;
constexpr const int IBTreeValue::TYPE_DATABASE_RECORD;
constexpr const int IBTreeValue::TYPE_SCAN_RESULT_RECORD;
constexpr const int IBTreeValue::TYPE_DOM_VARIABLE_RECORD;
constexpr const int IBTreeValue::TYPE_TABLE_INDEX_VALUE;
constexpr const int IBTreeValue::TYPE_PADDING_RECORD;
bool IBTreeValue::__init_done = __init_static_variables();
bool IBTreeValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IBTreeValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IBTreeValue::~IBTreeValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IBTreeValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}

