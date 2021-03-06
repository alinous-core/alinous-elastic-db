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





bool XpathIdentifier::__init_done = __init_static_variables();
bool XpathIdentifier::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathIdentifier", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathIdentifier::XpathIdentifier(String* id, ThreadContext* ctx) throw()  : IObject(ctx), IXpathStatement(ctx), id(nullptr)
{
	__GC_MV(this, &(this->id), id, String);
}
void XpathIdentifier::__construct_impl(String* id, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), id, String);
}
 XpathIdentifier::~XpathIdentifier() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathIdentifier::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathIdentifier", L"~XpathIdentifier");
	__e_obj1.add(this->id, this);
	id = nullptr;
	if(!prepare){
		return;
	}
}
String* XpathIdentifier::getId(ThreadContext* ctx) throw() 
{
	return id;
}
void XpathIdentifier::setId(String* id, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), id, String);
}
String* XpathIdentifier::toString(ThreadContext* ctx) throw() 
{
	return this->id;
}
IVariableValue* XpathIdentifier::getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) throw() 
{
	return (new(ctx) StringValue(this->id, ctx));
}
void XpathIdentifier::__cleanUp(ThreadContext* ctx){
}
}}}

