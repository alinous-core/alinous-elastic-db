#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool BreakStatement::__init_done = __init_static_variables();
bool BreakStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BreakStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BreakStatement::~BreakStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BreakStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BreakStatement", L"~BreakStatement");
	__e_obj1.add(this->label, this);
	label = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
IStatement::StatementType BreakStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::BREAK_STATEMENT;
}
void BreakStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool BreakStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool BreakStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
String* BreakStatement::getLabel(ThreadContext* ctx) throw() 
{
	return label;
}
void BreakStatement::setLabel(String* label, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->label), label, String);
}
}}}

