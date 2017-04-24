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



constexpr EnumBase __XpathFilter__FilterType::__DEFAULT_NULL;
constexpr EnumBase __XpathFilter__FilterType::logical;
constexpr EnumBase __XpathFilter__FilterType::index_number;


bool XpathFilter::__init_done = __init_static_variables();
bool XpathFilter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathFilter", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathFilter::XpathFilter(ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx), condition(nullptr)
{
}
void XpathFilter::__construct_impl(ThreadContext* ctx) throw() 
{
}
 XpathFilter::~XpathFilter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathFilter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathFilter", L"~XpathFilter");
	__e_obj1.add(this->condition, this);
	condition = nullptr;
	if(!prepare){
		return;
	}
}
IXpathBooleanCondition* XpathFilter::getCondition(ThreadContext* ctx) throw() 
{
	return condition;
}
void XpathFilter::setCondition(IXpathBooleanCondition* condition, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->condition), condition, IXpathBooleanCondition);
}
bool XpathFilter::isIndex(ThreadContext* ctx) throw() 
{
	if((dynamic_cast<Xpath2Compare*>(this->condition) != 0))
	{
		Xpath2Compare* compare = static_cast<Xpath2Compare*>(this->condition);
		if(compare->getRparam(ctx) != nullptr)
		{
			return false;
		}
		IXpathElement* param = compare->getLparam(ctx);
		if((dynamic_cast<XpathNumber*>(param) != 0))
		{
			return true;
		}
		if((dynamic_cast<XpathFunction*>(param) != 0) && (static_cast<XpathFunction*>(param))->getName(ctx)->equals(ConstStr::getCNST_STR_1805(), ctx))
		{
			return true;
		}
	}
	return false;
}
IXpathStatement* XpathFilter::getIndexStatement(ThreadContext* ctx) throw() 
{
	Xpath2Compare* compare = static_cast<Xpath2Compare*>(this->condition);
	return static_cast<IXpathStatement*>(compare->getLparam(ctx));
}
String* XpathFilter::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buffer = (new(ctx) StringBuffer(ctx));
	buffer->append(ConstStr::getCNST_STR_1036(), ctx);
	buffer->append(condition->toString(ctx), ctx);
	buffer->append(ConstStr::getCNST_STR_564(), ctx);
	return buffer->toString(ctx);
}
void XpathFilter::__cleanUp(ThreadContext* ctx){
}
}}}

