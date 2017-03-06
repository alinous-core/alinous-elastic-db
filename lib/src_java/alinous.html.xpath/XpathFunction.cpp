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
#include "alinous.html.xpath.function/First.h"
#include "alinous.html.xpath.function/Last.h"
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





bool XpathFunction::__init_done = __init_static_variables();
bool XpathFunction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathFunction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathFunction::XpathFunction(ThreadContext* ctx) throw()  : IObject(ctx), IXpathStatement(ctx), name(nullptr), arguments(GCUtils<ArrayList<XpathFunctionArgument> >::ins(this, (new(ctx) ArrayList<XpathFunctionArgument>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void XpathFunction::__construct_impl(ThreadContext* ctx) throw() 
{
}
 XpathFunction::~XpathFunction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathFunction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathFunction", L"~XpathFunction");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->arguments, this);
	arguments = nullptr;
	if(!prepare){
		return;
	}
}
void XpathFunction::addArgument(XpathFunctionArgument* arg, ThreadContext* ctx) throw() 
{
	this->arguments->add(arg, ctx);
}
String* XpathFunction::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void XpathFunction::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
String* XpathFunction::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->name, ctx);
	buff->append(ConstStr::getCNST_STR_991(), ctx);
	Iterator<XpathFunctionArgument>* it = this->arguments->iterator(ctx);
	while(it->hasNext(ctx))
	{
		XpathFunctionArgument* arg = it->next(ctx);
		buff->append(arg->toString(ctx), ctx);
	}
	buff->append(ConstStr::getCNST_STR_889(), ctx);
	return buff->toString(ctx);
}
IVariableValue* XpathFunction::getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) throw() 
{
	IXpathFunction* func = nullptr;
	if(this->name->equals(ConstStr::getCNST_STR_1787(), ctx))
	{
		func = (new(ctx) First(ctx));
	}
		else 
	{
		if(this->name->equals(ConstStr::getCNST_STR_1784(), ctx))
		{
			func = (new(ctx) Last(ctx));
		}
	}
	if(func != nullptr)
	{
		return func->getValue(document, currentNode, this->arguments, ctx);
	}
	return nullptr;
}
void XpathFunction::__cleanUp(ThreadContext* ctx){
}
}}}

