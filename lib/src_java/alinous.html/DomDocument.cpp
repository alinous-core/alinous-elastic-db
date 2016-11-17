#include "includes.h"


namespace alinous {namespace html {





bool DomDocument::__init_done = __init_static_variables();
bool DomDocument::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomDocument", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomDocument::DomDocument(String* name, ThreadContext* ctx) throw()  : IObject(ctx), DomNode(name, ctx)
{
}
void DomDocument::__construct_impl(String* name, ThreadContext* ctx) throw() 
{
}
 DomDocument::~DomDocument() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomDocument::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DomNode::__releaseRegerences(true, ctx);
}
String* DomDocument::getPathString(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_4();
}
String* DomDocument::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	Iterator<IDomObject>* childrenIt = this->children->iterator(ctx);
	while(childrenIt->hasNext(ctx))
	{
		buff->append(childrenIt->next(ctx)->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
int DomDocument::getType(ThreadContext* ctx) throw() 
{
	return IDomObject::TYPE_DOM_DOCUMENT;
}
}}

