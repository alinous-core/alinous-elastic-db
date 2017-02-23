#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool ExpressionStatement::__init_done = __init_static_variables();
bool ExpressionStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ExpressionStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ExpressionStatement::~ExpressionStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ExpressionStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ExpressionStatement", L"~ExpressionStatement");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
bool ExpressionStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->exp != nullptr && !this->exp->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool ExpressionStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		this->exp->analyse(context, leftValue, ctx);
	}
	return true;
}
IExpression* ExpressionStatement::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void ExpressionStatement::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
IStatement::StatementType ExpressionStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::EXPRESSION;
}
void ExpressionStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void ExpressionStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
}
void ExpressionStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__ExpressionStatement, ctx);
	bool isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
}
}}}

