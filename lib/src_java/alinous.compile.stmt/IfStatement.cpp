#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool IfStatement::__init_done = __init_static_variables();
bool IfStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IfStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IfStatement::~IfStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IfStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IfStatement", L"~IfStatement");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->exec, this);
	exec = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void IfStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool IfStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
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
bool IfStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
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
IStatement::StatementType IfStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::IF_STATEMENT;
}
IExpression* IfStatement::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void IfStatement::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
IStatement* IfStatement::getExec(ThreadContext* ctx) throw() 
{
	return exec;
}
void IfStatement::setExec(IStatement* exec, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exec), exec, IStatement);
}
void IfStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
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
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1096(), ctx));
		}
		__GC_MV(this, &(this->exec), static_cast<IStatement*>(el), IStatement);
	}
}
void IfStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__IfStatement, ctx);
	bool isnull = (this->exp == nullptr);
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

