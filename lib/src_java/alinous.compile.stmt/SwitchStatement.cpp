#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool SwitchStatement::__init_done = __init_static_variables();
bool SwitchStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SwitchStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SwitchStatement::~SwitchStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SwitchStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SwitchStatement", L"~SwitchStatement");
	__e_obj1.add(this->label, this);
	label = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->caseParts, this);
	caseParts = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
IStatement::StatementType SwitchStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::SWITCH_STATEMENT;
}
void SwitchStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool SwitchStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->label != nullptr && !this->label->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->exp != nullptr && !this->exp->visit(visitor, this, ctx))
	{
		return false;
	}
	int maxLoop = this->caseParts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SwitchCasePart* part = this->caseParts->get(i, ctx);
		if(part != nullptr && !part->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool SwitchStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->label != nullptr)
	{
		this->label->analyse(context, leftValue, ctx);
	}
	if(this->exp != nullptr)
	{
		this->exp->analyse(context, leftValue, ctx);
	}
	int maxLoop = this->caseParts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SwitchCasePart* part = this->caseParts->get(i, ctx);
		part->analyse(context, leftValue, ctx);
	}
	return true;
}
ArrayList<SwitchCasePart>* SwitchStatement::getCaseParts(ThreadContext* ctx) throw() 
{
	return caseParts;
}
void SwitchStatement::addCasePart(SwitchCasePart* part, ThreadContext* ctx) throw() 
{
	this->caseParts->add(part, ctx);
}
IExpression* SwitchStatement::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void SwitchStatement::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
LabeledStatement* SwitchStatement::getLabel(ThreadContext* ctx) throw() 
{
	return label;
}
void SwitchStatement::setLabel(LabeledStatement* label, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->label), label, LabeledStatement);
}
}}}

