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





bool XpathAndStatement::__init_done = __init_static_variables();
bool XpathAndStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathAndStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathAndStatement::XpathAndStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractContainerStatement(ctx)
{
}
void XpathAndStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 XpathAndStatement::~XpathAndStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathAndStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractContainerStatement::__releaseRegerences(true, ctx);
}
String* XpathAndStatement::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buffer = (new(ctx) StringBuffer(ctx));
	bool first = true;
	Iterator<IXpathBooleanCondition>* it = this->statements->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IXpathBooleanCondition* stmt = it->next(ctx);
		if(first)
		{
			first = false;
		}
				else 
		{
			buffer->append(ConstStr::getCNST_STR_1810(), ctx);
		}
		buffer->append(stmt, ctx);
	}
	return buffer->toString(ctx);
}
bool XpathAndStatement::getBooleanValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx)
{
	Iterator<IXpathBooleanCondition>* it = this->statements->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IXpathBooleanCondition* stmt = it->next(ctx);
		if(!stmt->getBooleanValue(document, currentNode, ctx))
		{
			return false;
		}
	}
	return true;
}
void XpathAndStatement::__cleanUp(ThreadContext* ctx){
}
}}}

