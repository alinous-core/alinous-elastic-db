#include "includes.h"


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
		if(this->ope->equals(ConstStr::getCNST_STR_1030(), ctx))
		{
			return l == r;
		}
				else 
		{
			if(this->ope->equals(ConstStr::getCNST_STR_1697(), ctx))
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
					if(this->ope->equals(ConstStr::getCNST_STR_988(), ctx))
					{
						return l >= r;
					}
										else 
					{
						if(this->ope->equals(ConstStr::getCNST_STR_986(), ctx))
						{
							return l < r;
						}
												else 
						{
							if(this->ope->equals(ConstStr::getCNST_STR_987(), ctx))
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
		if(this->ope->equals(ConstStr::getCNST_STR_1030(), ctx))
		{
			return l->equals(r, ctx);
		}
				else 
		{
			if(this->ope->equals(ConstStr::getCNST_STR_1697(), ctx))
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
					if(this->ope->equals(ConstStr::getCNST_STR_988(), ctx))
					{
						return l->compareTo(r, ctx) >= 0;
					}
										else 
					{
						if(this->ope->equals(ConstStr::getCNST_STR_986(), ctx))
						{
							return l->compareTo(r, ctx) < 0;
						}
												else 
						{
							if(this->ope->equals(ConstStr::getCNST_STR_987(), ctx))
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
		throw (new(ctx) MatchingException(ConstStr::getCNST_STR_1698(), ctx));
	}
	Xpath* xpath = (static_cast<XpathReference*>(this->lparam))->getXpath(ctx);
	Matcher* matcher = (new(ctx) Matcher(ctx));
	MatchCandidatesCollection* result = matcher->match(document, currentNode, xpath, ctx);
	return !result->getCandidatesList(ctx)->isEmpty(ctx);
}
}}}

