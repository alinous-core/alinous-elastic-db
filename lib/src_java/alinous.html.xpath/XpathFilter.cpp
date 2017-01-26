#include "includes.h"


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
		if((dynamic_cast<XpathFunction*>(param) != 0) && (static_cast<XpathFunction*>(param))->getName(ctx)->equals(ConstStr::getCNST_STR_1759(), ctx))
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
	buffer->append(ConstStr::getCNST_STR_1000(), ctx);
	buffer->append(condition->toString(ctx), ctx);
	buffer->append(ConstStr::getCNST_STR_564(), ctx);
	return buffer->toString(ctx);
}
}}}

