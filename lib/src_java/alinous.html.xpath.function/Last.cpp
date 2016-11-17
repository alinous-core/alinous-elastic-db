#include "includes.h"


namespace alinous {namespace html {namespace xpath {namespace function {





bool Last::__init_done = __init_static_variables();
bool Last::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Last", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Last::~Last() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Last::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IVariableValue* Last::getValue(DomDocument* document, DomNode* currentNode, ArrayList<XpathFunctionArgument>* arguments, ThreadContext* ctx) throw() 
{
	return (new(ctx) NumberValue(currentNode->getNumChildern(ctx), ctx));
}
}}}}

