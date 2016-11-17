#include "includes.h"


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
}}}

