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
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/StringValue.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath/NumberValue.h"
#include "alinous.html.xpath/XpathFunctionArgument.h"
#include "alinous.html.xpath/IXpathFunction.h"
#include "alinous.html.xpath.function/First.h"
#include "alinous.html.xpath.function/Last.h"
#include "alinous.html.xpath/XpathFunction.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/XpathReference.h"
#include "alinous.html.xpath/Xpath2Compare.h"
#include "alinous.html.xpath/XpathNumber.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath/XpathNotStatement.h"
#include "alinous.html.xpath/XpathAndStatement.h"
#include "alinous.html.xpath/XPathParser.h"

namespace alinous {namespace html {namespace xpath {





bool XpathNumber::__init_done = __init_static_variables();
bool XpathNumber::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathNumber", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathNumber::XpathNumber(ThreadContext* ctx) throw()  : IObject(ctx), IXpathStatement(ctx), number(nullptr)
{
}
void XpathNumber::__construct_impl(ThreadContext* ctx) throw() 
{
}
 XpathNumber::~XpathNumber() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathNumber::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathNumber", L"~XpathNumber");
	__e_obj1.add(this->number, this);
	number = nullptr;
	if(!prepare){
		return;
	}
}
String* XpathNumber::getNumber(ThreadContext* ctx) throw() 
{
	return number;
}
void XpathNumber::setNumber(String* number, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->number), number, String);
}
String* XpathNumber::toString(ThreadContext* ctx) throw() 
{
	return number;
}
IVariableValue* XpathNumber::getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) throw() 
{
	return (new(ctx) NumberValue(Integer::parseInt(this->number, ctx), ctx));
}
void XpathNumber::__cleanUp(ThreadContext* ctx){
}
}}}

