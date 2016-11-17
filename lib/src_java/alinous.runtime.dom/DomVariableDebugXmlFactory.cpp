#include "includes.h"


namespace alinous {namespace runtime {namespace dom {





bool DomVariableDebugXmlFactory::__init_done = __init_static_variables();
bool DomVariableDebugXmlFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomVariableDebugXmlFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomVariableDebugXmlFactory::~DomVariableDebugXmlFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomVariableDebugXmlFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IDomVariable* DomVariableDebugXmlFactory::getDom(DomNode* node, ThreadContext* ctx) throw() 
{
	String* tag = node->getName(ctx);
	if(tag->equals(DomVariable::VAL_TYPE, ctx))
	{
		return DomVariable::importFromDebugXml(node, ctx);
	}
		else 
	{
		if(tag->equals(DomArray::VAL_TYPE, ctx))
		{
			return DomArray::importFromDebugXml(node, ctx);
		}
	}
	return nullptr;
}
}}}

