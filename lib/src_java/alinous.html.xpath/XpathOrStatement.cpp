#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool XpathOrStatement::__init_done = __init_static_variables();
bool XpathOrStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathOrStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathOrStatement::~XpathOrStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathOrStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractContainerStatement::__releaseRegerences(true, ctx);
}
String* XpathOrStatement::toString(ThreadContext* ctx) throw() 
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
			buffer->append(ConstStr::getCNST_STR_1696(), ctx);
		}
		buffer->append(stmt, ctx);
	}
	return buffer->toString(ctx);
}
bool XpathOrStatement::getBooleanValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx)
{
	Iterator<IXpathBooleanCondition>* it = this->statements->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IXpathBooleanCondition* stmt = it->next(ctx);
		if(stmt->getBooleanValue(document, currentNode, ctx))
		{
			return true;
		}
	}
	return false;
}
}}}

