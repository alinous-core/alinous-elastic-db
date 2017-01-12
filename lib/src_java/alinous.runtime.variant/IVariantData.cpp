#include "includes.h"


namespace alinous {namespace runtime {namespace variant {




constexpr const int IVariantData::TYPE_STRING;
constexpr const int IVariantData::TYPE_LONG;
constexpr const int IVariantData::TYPE_INT;
constexpr const int IVariantData::TYPE_SHORT;
constexpr const int IVariantData::TYPE_CHAR;
constexpr const int IVariantData::TYPE_BYTE;
constexpr const int IVariantData::TYPE_FLOAT;
constexpr const int IVariantData::TYPE_DOUBLE;
constexpr const int IVariantData::TYPE_BOOL;
constexpr const int IVariantData::TYPE_BIG_DECIMAL;
constexpr const int IVariantData::TYPE_TIME;
constexpr const int IVariantData::TYPE_TIMESTAMP;
constexpr const int IVariantData::TYPE_NULL;
String* IVariantData::ATTR_VALUE = ConstStr::getCNST_STR_1147();
bool IVariantData::__init_done = __init_static_variables();
bool IVariantData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IVariantData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IVariantData::~IVariantData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IVariantData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ICommandData::__releaseRegerences(true, ctx);
}
}}}

