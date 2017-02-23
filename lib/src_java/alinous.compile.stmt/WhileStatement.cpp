#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool WhileStatement::__init_done = __init_static_variables();
bool WhileStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"WhileStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 WhileStatement::~WhileStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void WhileStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"WhileStatement", L"~WhileStatement");
	__e_obj1.add(this->label, this);
	label = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->exec, this);
	exec = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void WhileStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool WhileStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
	if(this->exec != nullptr && !this->exec->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool WhileStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->label != nullptr)
	{
		this->label->analyse(context, leftValue, ctx);
	}
	if(this->exp != nullptr)
	{
		this->exp->analyse(context, leftValue, ctx);
	}
	if(this->exec != nullptr)
	{
		this->exec->analyse(context, leftValue, ctx);
	}
	return true;
}
IStatement::StatementType WhileStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::WHILE_STATEMENT;
}
LabeledStatement* WhileStatement::getLabel(ThreadContext* ctx) throw() 
{
	return label;
}
void WhileStatement::setLabel(LabeledStatement* label, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->label), label, LabeledStatement);
}
IExpression* WhileStatement::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void WhileStatement::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
IStatement* WhileStatement::getExec(ThreadContext* ctx) throw() 
{
	return exec;
}
void WhileStatement::setExec(IStatement* exec, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exec), exec, IStatement);
}
void WhileStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<LabeledStatement*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1098(), ctx));
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
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IStatement*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1099(), ctx));
		}
		__GC_MV(this, &(this->exec), static_cast<IStatement*>(el), IStatement);
	}
}
void WhileStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__WhileStatement, ctx);
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
	isnull = (this->exec == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exec->writeData(buff, ctx);
	}
}
}}}

