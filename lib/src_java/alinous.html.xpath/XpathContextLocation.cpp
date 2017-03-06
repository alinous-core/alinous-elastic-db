#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchingException.h"
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





bool XpathContextLocation::__init_done = __init_static_variables();
bool XpathContextLocation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathContextLocation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathContextLocation::XpathContextLocation(ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx), ctrls(GCUtils<ArrayList<XpathContextLocationCtrl> >::ins(this, (new(ctx) ArrayList<XpathContextLocationCtrl>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void XpathContextLocation::__construct_impl(ThreadContext* ctx) throw() 
{
}
 XpathContextLocation::~XpathContextLocation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathContextLocation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathContextLocation", L"~XpathContextLocation");
	__e_obj1.add(this->ctrls, this);
	ctrls = nullptr;
	if(!prepare){
		return;
	}
}
void XpathContextLocation::addCtrl(XpathContextLocationCtrl* ctrl, ThreadContext* ctx) throw() 
{
	this->ctrls->add(ctrl, ctx);
}
void XpathContextLocation::setupLocation(MatchCursor* cursor, ThreadContext* ctx)
{
	XpathContext::ScanPolicy policy = cursor->getScanPolicy(ctx);
	Iterator<XpathContextLocationCtrl>* it = this->ctrls->iterator(ctx);
	while(it->hasNext(ctx))
	{
		XpathContextLocationCtrl* ctrl = it->next(ctx);
		XpathContextLocationCtrl::CtrlType type = ctrl->getType(ctx);
		switch(type) {
		case XpathContextLocationCtrl::CtrlType::all:
			policy = XpathContext::ScanPolicy::scan_all_inherited_children;
			break ;
		case XpathContextLocationCtrl::CtrlType::children:
			policy = XpathContext::ScanPolicy::scan_children;
			break ;
		case XpathContextLocationCtrl::CtrlType::current:
			policy = XpathContext::ScanPolicy::scan_this_only;
			break ;
		case XpathContextLocationCtrl::CtrlType::parent:
			cursor->gotoParent(ctx);
			break ;
		default:
			break ;
		}
	}
	cursor->caluculateScanPolicy(policy, ctx);
}
String* XpathContextLocation::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	Iterator<XpathContextLocationCtrl>* it = this->ctrls->iterator(ctx);
	while(it->hasNext(ctx))
	{
		buff->append(it->next(ctx)->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
void XpathContextLocation::__cleanUp(ThreadContext* ctx){
}
}}}

