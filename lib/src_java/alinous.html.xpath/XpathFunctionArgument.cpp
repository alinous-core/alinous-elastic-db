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





bool XpathFunctionArgument::__init_done = __init_static_variables();
bool XpathFunctionArgument::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathFunctionArgument", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathFunctionArgument::XpathFunctionArgument(IXpathElement* element, ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx), element(nullptr)
{
	__GC_MV(this, &(this->element), element, IXpathElement);
}
void XpathFunctionArgument::__construct_impl(IXpathElement* element, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->element), element, IXpathElement);
}
 XpathFunctionArgument::~XpathFunctionArgument() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathFunctionArgument::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathFunctionArgument", L"~XpathFunctionArgument");
	__e_obj1.add(this->element, this);
	element = nullptr;
	if(!prepare){
		return;
	}
}
IXpathElement* XpathFunctionArgument::getElement(ThreadContext* ctx) throw() 
{
	return element;
}
void XpathFunctionArgument::setElement(IXpathElement* element, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->element), element, IXpathElement);
}
String* XpathFunctionArgument::toString(ThreadContext* ctx) throw() 
{
	return this->element->toString(ctx);
}
void XpathFunctionArgument::__cleanUp(ThreadContext* ctx){
}
}}}

