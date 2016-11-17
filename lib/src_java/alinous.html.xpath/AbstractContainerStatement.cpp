#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool AbstractContainerStatement::__init_done = __init_static_variables();
bool AbstractContainerStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractContainerStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractContainerStatement::~AbstractContainerStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractContainerStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractContainerStatement", L"~AbstractContainerStatement");
	__e_obj1.add(this->statements, this);
	statements = nullptr;
	if(!prepare){
		return;
	}
}
void AbstractContainerStatement::addStatement(IXpathBooleanCondition* stmt, ThreadContext* ctx) throw() 
{
	this->statements->add(stmt, ctx);
}
}}}

