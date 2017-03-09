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





bool XpathNotStatement::__init_done = __init_static_variables();
bool XpathNotStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathNotStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathNotStatement::XpathNotStatement(ThreadContext* ctx) throw()  : IObject(ctx), IXpathBooleanCondition(ctx), notFlag(0), stmt(nullptr)
{
}
void XpathNotStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 XpathNotStatement::~XpathNotStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathNotStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathNotStatement", L"~XpathNotStatement");
	__e_obj1.add(this->stmt, this);
	stmt = nullptr;
	if(!prepare){
		return;
	}
}
bool XpathNotStatement::isNot(ThreadContext* ctx) throw() 
{
	return notFlag;
}
void XpathNotStatement::setNot(bool notFlag, ThreadContext* ctx) throw() 
{
	this->notFlag = notFlag;
}
IXpathBooleanCondition* XpathNotStatement::getStmt(ThreadContext* ctx) throw() 
{
	return stmt;
}
void XpathNotStatement::setStmt(IXpathBooleanCondition* stmt, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->stmt), stmt, IXpathBooleanCondition);
}
String* XpathNotStatement::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buffer = (new(ctx) StringBuffer(ctx));
	if(notFlag)
	{
		buffer->append(ConstStr::getCNST_STR_1808(), ctx);
	}
	buffer->append(ConstStr::getCNST_STR_1106(), ctx);
	buffer->append(stmt->toString(ctx), ctx);
	buffer->append(ConstStr::getCNST_STR_889(), ctx);
	return buffer->toString(ctx);
}
bool XpathNotStatement::getBooleanValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx)
{
	bool condition = this->stmt->getBooleanValue(document, currentNode, ctx);
	if(this->notFlag)
	{
		return !condition;
	}
	return condition;
}
void XpathNotStatement::__cleanUp(ThreadContext* ctx){
}
}}}

