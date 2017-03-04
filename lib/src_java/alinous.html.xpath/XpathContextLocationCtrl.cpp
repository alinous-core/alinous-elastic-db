#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/AbstractContainerStatement.h"
#include "alinous.html.xpath/XpathOrStatement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath/XpathString.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/NumberValue.h"
#include "alinous.html.xpath/XpathReference.h"
#include "alinous.html.xpath/Xpath2Compare.h"
#include "alinous.html.xpath/XpathNumber.h"
#include "alinous.html.xpath/XpathFunctionArgument.h"
#include "alinous.html.xpath/IXpathFunction.h"
#include "alinous.html.xpath/XpathFunction.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath/XpathNotStatement.h"
#include "alinous.html.xpath/XpathAndStatement.h"
#include "alinous.html.xpath/XPathParser.h"

namespace alinous {namespace html {namespace xpath {



constexpr EnumBase __XpathContextLocationCtrl__CtrlType::__DEFAULT_NULL;
constexpr EnumBase __XpathContextLocationCtrl__CtrlType::current;
constexpr EnumBase __XpathContextLocationCtrl__CtrlType::parent;
constexpr EnumBase __XpathContextLocationCtrl__CtrlType::children;
constexpr EnumBase __XpathContextLocationCtrl__CtrlType::all;


bool XpathContextLocationCtrl::__init_done = __init_static_variables();
bool XpathContextLocationCtrl::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathContextLocationCtrl", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathContextLocationCtrl::XpathContextLocationCtrl(XpathContextLocationCtrl::CtrlType type, ThreadContext* ctx) throw()  : IObject(ctx)
{
	this->type = type;
}
void XpathContextLocationCtrl::__construct_impl(XpathContextLocationCtrl::CtrlType type, ThreadContext* ctx) throw() 
{
	this->type = type;
}
 XpathContextLocationCtrl::~XpathContextLocationCtrl() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathContextLocationCtrl::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathContextLocationCtrl", L"~XpathContextLocationCtrl");
	if(!prepare){
		return;
	}
}
XpathContextLocationCtrl::CtrlType XpathContextLocationCtrl::getType(ThreadContext* ctx) throw() 
{
	return type;
}
String* XpathContextLocationCtrl::toString(ThreadContext* ctx) throw() 
{
	switch(this->type) {
	case XpathContextLocationCtrl::CtrlType::all:
		return ConstStr::getCNST_STR_1788();
	case XpathContextLocationCtrl::CtrlType::current:
		return ConstStr::getCNST_STR_950();
	case XpathContextLocationCtrl::CtrlType::parent:
		return ConstStr::getCNST_STR_1244();
	case XpathContextLocationCtrl::CtrlType::children:
		return ConstStr::getCNST_STR_1007();
	default:
		break ;
	}
	return nullptr;
}
}}}

