#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool DefaultStatement::__init_done = __init_static_variables();
bool DefaultStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DefaultStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DefaultStatement::~DefaultStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DefaultStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	CaseStatement::__releaseRegerences(true, ctx);
}
IStatement::StatementType DefaultStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::DEFAULT_STATEMENT;
}
void DefaultStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool DefaultStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
}}}

