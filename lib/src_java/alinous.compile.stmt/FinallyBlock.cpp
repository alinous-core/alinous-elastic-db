#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool FinallyBlock::__init_done = __init_static_variables();
bool FinallyBlock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FinallyBlock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FinallyBlock::~FinallyBlock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FinallyBlock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void FinallyBlock::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool FinallyBlock::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool FinallyBlock::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
IStatement::StatementType FinallyBlock::getType(ThreadContext* ctx) throw() 
{
	return StatementType::FINALLY_STATEMENT;
}
}}}

