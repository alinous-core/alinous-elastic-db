#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {





String* AlinousAttrs::ALINOUS_IF = ConstStr::getCNST_STR_1713();
String* AlinousAttrs::ALINOUS_INNER = ConstStr::getCNST_STR_1714();
String* AlinousAttrs::ALINOUS_TAGID = ConstStr::getCNST_STR_1715();
String* AlinousAttrs::ALINOUS_TARGET = ConstStr::getCNST_STR_1716();
String* AlinousAttrs::ALINOUS_ITERATE = ConstStr::getCNST_STR_1717();
String* AlinousAttrs::ALINOUS_VARIABLE = ConstStr::getCNST_STR_1718();
String* AlinousAttrs::ALINOUS_MSG = ConstStr::getCNST_STR_1719();
String* AlinousAttrs::ALINOUS_MSG_TARGET = ConstStr::getCNST_STR_1720();
String* AlinousAttrs::ALINOUS_FORM = ConstStr::getCNST_STR_1721();
String* AlinousAttrs::ALINOUS_BACK = ConstStr::getCNST_STR_1722();
String* AlinousAttrs::ALINOUS_VALIDATE_TYPE = ConstStr::getCNST_STR_1723();
String* AlinousAttrs::ALINOUS_VALIDATE_IF = ConstStr::getCNST_STR_1724();
String* AlinousAttrs::ALINOUS_REGEX = ConstStr::getCNST_STR_1725();
String* AlinousAttrs::ALINOUS_PARAM = ConstStr::getCNST_STR_1726();
String* AlinousAttrs::ALINOUS_TYPE = ConstStr::getCNST_STR_1727();
String* AlinousAttrs::ALINOUS_NO_FORM_CACHE = ConstStr::getCNST_STR_1728();
String* AlinousAttrs::ALINOUS_IGNOREBLANK = ConstStr::getCNST_STR_1729();
String* AlinousAttrs::ALINOUS_IGNORE_SELF_ITERATE = ConstStr::getCNST_STR_1730();
String* AlinousAttrs::ALINOUS_EXTRACT = ConstStr::getCNST_STR_1731();
String* AlinousAttrs::ALINOUS_COMPONENT = ConstStr::getCNST_STR_1732();
String* AlinousAttrs::ALINOUS_COMPONENT_ID = ConstStr::getCNST_STR_1733();
String* AlinousAttrs::ALINOUS_COMPONENT_WIDTH = ConstStr::getCNST_STR_1734();
String* AlinousAttrs::ALINOUS_COMPONENT_EDIT = ConstStr::getCNST_STR_1735();
String* AlinousAttrs::ALINOUS_COMPONENT_VIEW = ConstStr::getCNST_STR_1736();
String* AlinousAttrs::ALINOUS_COMPONENT_VIEWTYPE = ConstStr::getCNST_STR_1737();
String* AlinousAttrs::ALINOUS_COMPONENT_ROOT = ConstStr::getCNST_STR_1738();
String* AlinousAttrs::VALUE_TRUE = ConstStr::getCNST_STR_372();
String* AlinousAttrs::VALUE_FALSE = ConstStr::getCNST_STR_1081();
String* AlinousAttrs::VALUE_VIEWTYPE_FRAME = ConstStr::getCNST_STR_1739();
String* AlinousAttrs::VALUE_VIEWTYPE_INNER = ConstStr::getCNST_STR_1740();
String* AlinousAttrs::ALINOUS_ALINOUS_FORM = ConstStr::getCNST_STR_1741();
bool AlinousAttrs::__init_done = __init_static_variables();
bool AlinousAttrs::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousAttrs", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousAttrs::~AlinousAttrs() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousAttrs::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
bool AlinousAttrs::isAlinousAttr(String* attrStr, ThreadContext* ctx) throw() 
{
	attrStr = attrStr->toLowerCase(ctx);
	return attrStr->equals(ALINOUS_IF, ctx) || attrStr->equals(ALINOUS_INNER, ctx) || attrStr->equals(ALINOUS_TAGID, ctx) || attrStr->equals(ALINOUS_TARGET, ctx) || attrStr->equals(ALINOUS_ITERATE, ctx) || attrStr->equals(ALINOUS_VARIABLE, ctx) || attrStr->equals(ALINOUS_MSG, ctx) || attrStr->equals(ALINOUS_MSG_TARGET, ctx) || attrStr->equals(ALINOUS_FORM, ctx) || attrStr->equals(ALINOUS_BACK, ctx) || attrStr->equals(ALINOUS_VALIDATE_TYPE, ctx) || attrStr->equals(ALINOUS_VALIDATE_IF, ctx) || attrStr->equals(ALINOUS_REGEX, ctx) || attrStr->equals(ALINOUS_PARAM, ctx) || attrStr->equals(ALINOUS_TYPE, ctx) || attrStr->equals(ALINOUS_NO_FORM_CACHE, ctx) || attrStr->equals(ALINOUS_IGNOREBLANK, ctx) || attrStr->equals(ALINOUS_IGNORE_SELF_ITERATE, ctx) || attrStr->equals(ALINOUS_EXTRACT, ctx) || attrStr->equals(ALINOUS_COMPONENT, ctx) || attrStr->equals(ALINOUS_COMPONENT_ID, ctx) || attrStr->equals(ALINOUS_COMPONENT_WIDTH, ctx) || attrStr->equals(ALINOUS_COMPONENT_EDIT, ctx) || attrStr->equals(ALINOUS_COMPONENT_VIEW, ctx) || attrStr->equals(ALINOUS_COMPONENT_VIEWTYPE, ctx) || attrStr->equals(ALINOUS_COMPONENT_ROOT, ctx) || attrStr->equals(ALINOUS_ALINOUS_FORM, ctx);
}
}}}

