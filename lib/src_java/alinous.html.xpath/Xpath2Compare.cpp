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





bool Xpath2Compare::__init_done = __init_static_variables();
bool Xpath2Compare::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Xpath2Compare", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Xpath2Compare::Xpath2Compare(ThreadContext* ctx) throw()  : IObject(ctx), IXpathBooleanCondition(ctx), lparam(nullptr), rparam(nullptr), ope(nullptr)
{
}
void Xpath2Compare::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Xpath2Compare::~Xpath2Compare() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Xpath2Compare::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Xpath2Compare", L"~Xpath2Compare");
	__e_obj1.add(this->lparam, this);
	lparam = nullptr;
	__e_obj1.add(this->rparam, this);
	rparam = nullptr;
	__e_obj1.add(this->ope, this);
	ope = nullptr;
	if(!prepare){
		return;
	}
}
String* Xpath2Compare::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buffer = (new(ctx) StringBuffer(ctx));
	buffer->append(this->lparam->toString(ctx), ctx);
	if(this->rparam != nullptr)
	{
		buffer->append(this->ope, ctx);
		buffer->append(this->rparam->toString(ctx), ctx);
	}
	return buffer->toString(ctx);
}
IXpathElement* Xpath2Compare::getLparam(ThreadContext* ctx) throw() 
{
	return lparam;
}
void Xpath2Compare::setLparam(IXpathStatement* lparam, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->lparam), lparam, IXpathStatement);
}
IXpathElement* Xpath2Compare::getRparam(ThreadContext* ctx) throw() 
{
	return rparam;
}
void Xpath2Compare::setRparam(IXpathStatement* rparam, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->rparam), rparam, IXpathStatement);
}
String* Xpath2Compare::getOperator(ThreadContext* ctx) throw() 
{
	return ope;
}
void Xpath2Compare::setOperator(String* opeStr, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->ope), opeStr, String);
}
bool Xpath2Compare::getBooleanValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx)
{
	if(rparam == nullptr)
	{
		return checkExists(document, currentNode, ctx);
	}
	IVariableValue* leftValue = this->lparam->getValue(document, currentNode, ctx);
	IVariableValue* rightValue = this->rparam->getValue(document, currentNode, ctx);
	if(leftValue == nullptr || rightValue == nullptr)
	{
		return false;
	}
	if((dynamic_cast<NumberValue*>(leftValue) != 0) && (dynamic_cast<NumberValue*>(rightValue) != 0))
	{
		int l = (static_cast<NumberValue*>(leftValue))->getValue(ctx);
		int r = (static_cast<NumberValue*>(rightValue))->getValue(ctx);
		if(this->ope->equals(ConstStr::getCNST_STR_1079(), ctx))
		{
			return l == r;
		}
				else 
		{
			if(this->ope->equals(ConstStr::getCNST_STR_1785(), ctx))
			{
				return l != r;
			}
						else 
			{
				if(this->ope->equals(ConstStr::getCNST_STR_82(), ctx))
				{
					return l > r;
				}
								else 
				{
					if(this->ope->equals(ConstStr::getCNST_STR_1012(), ctx))
					{
						return l >= r;
					}
										else 
					{
						if(this->ope->equals(ConstStr::getCNST_STR_1010(), ctx))
						{
							return l < r;
						}
												else 
						{
							if(this->ope->equals(ConstStr::getCNST_STR_1011(), ctx))
							{
								return l <= r;
							}
						}
					}
				}
			}
		}
	}
		else 
	{
		String* l = leftValue->toString(ctx);
		String* r = rightValue->toString(ctx);
		if(this->ope->equals(ConstStr::getCNST_STR_1079(), ctx))
		{
			return l->equals(r, ctx);
		}
				else 
		{
			if(this->ope->equals(ConstStr::getCNST_STR_1785(), ctx))
			{
				return !l->equals(r, ctx);
			}
						else 
			{
				if(this->ope->equals(ConstStr::getCNST_STR_82(), ctx))
				{
					return l->compareTo(r, ctx) > 0;
				}
								else 
				{
					if(this->ope->equals(ConstStr::getCNST_STR_1012(), ctx))
					{
						return l->compareTo(r, ctx) >= 0;
					}
										else 
					{
						if(this->ope->equals(ConstStr::getCNST_STR_1010(), ctx))
						{
							return l->compareTo(r, ctx) < 0;
						}
												else 
						{
							if(this->ope->equals(ConstStr::getCNST_STR_1011(), ctx))
							{
								return l->compareTo(r, ctx) <= 0;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
bool Xpath2Compare::checkExists(DomDocument* document, DomNode* currentNode, ThreadContext* ctx)
{
	if(!((dynamic_cast<XpathReference*>(this->lparam) != 0)))
	{
		throw (new(ctx) MatchingException(ConstStr::getCNST_STR_1786(), ctx));
	}
	Xpath* xpath = (static_cast<XpathReference*>(this->lparam))->getXpath(ctx);
	Matcher* matcher = (new(ctx) Matcher(ctx));
	MatchCandidatesCollection* result = matcher->match(document, currentNode, xpath, ctx);
	return !result->getCandidatesList(ctx)->isEmpty(ctx);
}
void Xpath2Compare::__cleanUp(ThreadContext* ctx){
}
}}}

