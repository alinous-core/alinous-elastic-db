#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace parts {





bool AbstractExpressionPart::__init_done = __init_static_variables();
bool AbstractExpressionPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractExpressionPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractExpressionPart::~AbstractExpressionPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractExpressionPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ISQLExpressionPart::__releaseRegerences(true, ctx);
}
int AbstractExpressionPart::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpressionPart::getLine(ctx);
}
int AbstractExpressionPart::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpressionPart::getStartPosition(ctx);
}
int AbstractExpressionPart::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpressionPart::getEndLine(ctx);
}
int AbstractExpressionPart::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpressionPart::getEndPosition(ctx);
}
AbstractSrcElement* AbstractExpressionPart::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpressionPart::getParent(ctx);
}
void AbstractExpressionPart::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpressionPart::setParent(parent, ctx);
}
bool AbstractExpressionPart::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
}}}}

