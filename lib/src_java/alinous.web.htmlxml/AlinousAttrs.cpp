#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {





String* AlinousAttrs::ALINOUS_IF = ConstStr::getCNST_STR_1774();
String* AlinousAttrs::ALINOUS_INNER = ConstStr::getCNST_STR_1775();
String* AlinousAttrs::ALINOUS_TAGID = ConstStr::getCNST_STR_1776();
String* AlinousAttrs::ALINOUS_TARGET = ConstStr::getCNST_STR_1777();
String* AlinousAttrs::ALINOUS_ITERATE = ConstStr::getCNST_STR_1778();
String* AlinousAttrs::ALINOUS_VARIABLE = ConstStr::getCNST_STR_1779();
String* AlinousAttrs::ALINOUS_MSG = ConstStr::getCNST_STR_1780();
String* AlinousAttrs::ALINOUS_MSG_TARGET = ConstStr::getCNST_STR_1781();
String* AlinousAttrs::ALINOUS_FORM = ConstStr::getCNST_STR_1782();
String* AlinousAttrs::ALINOUS_BACK = ConstStr::getCNST_STR_1783();
String* AlinousAttrs::ALINOUS_VALIDATE_TYPE = ConstStr::getCNST_STR_1784();
String* AlinousAttrs::ALINOUS_VALIDATE_IF = ConstStr::getCNST_STR_1785();
String* AlinousAttrs::ALINOUS_REGEX = ConstStr::getCNST_STR_1786();
String* AlinousAttrs::ALINOUS_PARAM = ConstStr::getCNST_STR_1787();
String* AlinousAttrs::ALINOUS_TYPE = ConstStr::getCNST_STR_1788();
String* AlinousAttrs::ALINOUS_NO_FORM_CACHE = ConstStr::getCNST_STR_1789();
String* AlinousAttrs::ALINOUS_IGNOREBLANK = ConstStr::getCNST_STR_1790();
String* AlinousAttrs::ALINOUS_IGNORE_SELF_ITERATE = ConstStr::getCNST_STR_1791();
String* AlinousAttrs::ALINOUS_EXTRACT = ConstStr::getCNST_STR_1792();
String* AlinousAttrs::ALINOUS_COMPONENT = ConstStr::getCNST_STR_1793();
String* AlinousAttrs::ALINOUS_COMPONENT_ID = ConstStr::getCNST_STR_1794();
String* AlinousAttrs::ALINOUS_COMPONENT_WIDTH = ConstStr::getCNST_STR_1795();
String* AlinousAttrs::ALINOUS_COMPONENT_EDIT = ConstStr::getCNST_STR_1796();
String* AlinousAttrs::ALINOUS_COMPONENT_VIEW = ConstStr::getCNST_STR_1797();
String* AlinousAttrs::ALINOUS_COMPONENT_VIEWTYPE = ConstStr::getCNST_STR_1798();
String* AlinousAttrs::ALINOUS_COMPONENT_ROOT = ConstStr::getCNST_STR_1799();
String* AlinousAttrs::VALUE_TRUE = ConstStr::getCNST_STR_372();
String* AlinousAttrs::VALUE_FALSE = ConstStr::getCNST_STR_1132();
String* AlinousAttrs::VALUE_VIEWTYPE_FRAME = ConstStr::getCNST_STR_1800();
String* AlinousAttrs::VALUE_VIEWTYPE_INNER = ConstStr::getCNST_STR_1801();
String* AlinousAttrs::ALINOUS_ALINOUS_FORM = ConstStr::getCNST_STR_1802();
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

