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
void SwitchStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<LabeledStatement*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1093(), ctx));
		}
		__GC_MV(this, &(this->label), static_cast<LabeledStatement*>(el), LabeledStatement);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<IExpression*>(el), IExpression);
	}
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SwitchCasePart*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1009(), ctx));
		}
		this->caseParts->add(static_cast<SwitchCasePart*>(el), ctx);
	}
}
void SwitchStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SwitchStatement, ctx);
	bool isnull = (this->label == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->label->writeData(buff, ctx);
	}
	isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
	int maxLoop = this->caseParts->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		SwitchCasePart* exp = this->caseParts->get(i, ctx);
		exp->writeData(buff, ctx);
	}
}
}}}

