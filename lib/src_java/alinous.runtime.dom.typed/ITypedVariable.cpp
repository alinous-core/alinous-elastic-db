#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {




constexpr const int ITypedVariable::TYPE_BOOL;
constexpr const int ITypedVariable::TYPE_BYTE;
constexpr const int ITypedVariable::TYPE_CHAR;
constexpr const int ITypedVariable::TYPE_DOUBLE;
constexpr const int ITypedVariable::TYPE_FLOAT;
constexpr const int ITypedVariable::TYPE_INT;
constexpr const int ITypedVariable::TYPE_LONG;
constexpr const int ITypedVariable::TYPE_SHORT;
constexpr const int ITypedVariable::TYPE_STRING;
constexpr const int ITypedVariable::TYPE_BIGDECIMAL;
constexpr const int ITypedVariable::TYPE_TIME;
constexpr const int ITypedVariable::TYPE_TIMESTAMP;
constexpr const int ITypedVariable::TYPE_ARRAY;
constexpr const int ITypedVariable::TYPE_CLASS_OBJECT;
String* ITypedVariable::TYPED_VARIABLE = ConstStr::getCNST_STR_1149();
bool ITypedVariable::__init_done = __init_static_variables();
bool ITypedVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ITypedVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ITypedVariable::~ITypedVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ITypedVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IAlinousVariable::__releaseRegerences(true, ctx);
}
}}}}

