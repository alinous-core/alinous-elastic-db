#include "includes.h"


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
	buff->append(ConstStr::getCNST_STR_972(), ctx);
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
	if(this->name->equals(ConstStr::getCNST_STR_1696(), ctx))
	{
		func = (new(ctx) First(ctx));
	}
		else 
	{
		if(this->name->equals(ConstStr::getCNST_STR_1693(), ctx))
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
}}}

