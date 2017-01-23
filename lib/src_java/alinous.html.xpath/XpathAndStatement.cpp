#include "includes.h"


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
			buffer->append(ConstStr::getCNST_STR_1763(), ctx);
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
}}}

