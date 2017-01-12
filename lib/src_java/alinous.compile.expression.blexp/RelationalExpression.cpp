#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace blexp {





constexpr const int RelationalExpression::LT;
constexpr const int RelationalExpression::GT;
constexpr const int RelationalExpression::LT_EQ;
constexpr const int RelationalExpression::GT_EQ;
bool RelationalExpression::__init_done = __init_static_variables();
bool RelationalExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RelationalExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RelationalExpression::~RelationalExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RelationalExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RelationalExpression", L"~RelationalExpression");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	if(!prepare){
		return;
	}
	AbstractBooleanExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* RelationalExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* leftv = machine->resolveExpression(this->left, debug, ctx);
	IAlinousVariable* rightv = machine->resolveExpression(this->right, debug, ctx);
	int cmpresult = leftv->compareTo(rightv, ctx);
	;
	BoolVariable* bl = nullptr;
	switch(this->ope) {
	case LT:
		if(cmpresult < 0)
		{
			bl = (new(ctx) BoolVariable(true, ctx));
		}
				else 
		{
			bl = (new(ctx) BoolVariable(false, ctx));
		}
		break ;
	case GT:
		if(cmpresult > 0)
		{
			bl = (new(ctx) BoolVariable(true, ctx));
		}
				else 
		{
			bl = (new(ctx) BoolVariable(false, ctx));
		}
		break ;
	case LT_EQ:
		if(cmpresult <= 0)
		{
			bl = (new(ctx) BoolVariable(true, ctx));
		}
				else 
		{
			bl = (new(ctx) BoolVariable(false, ctx));
		}
		break ;
	case GT_EQ:
	default:
		if(cmpresult >= 0)
		{
			bl = (new(ctx) BoolVariable(true, ctx));
		}
				else 
		{
			bl = (new(ctx) BoolVariable(false, ctx));
		}
		break ;
	}
	return bl;
}
bool RelationalExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->left != nullptr && !this->left->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->right != nullptr && !this->right->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool RelationalExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->left != nullptr && !this->left->isConstant(ctx))
	{
		return false;
	}
	if(this->right != nullptr && !this->right->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool RelationalExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr)
	{
		this->left->analyse(context, leftValue, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyse(context, leftValue, ctx);
	}
	return true;
}
IExpression* RelationalExpression::getLeft(ThreadContext* ctx) throw() 
{
	return left;
}
void RelationalExpression::setLeft(IExpression* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), left, IExpression);
}
IExpression* RelationalExpression::getRight(ThreadContext* ctx) throw() 
{
	return right;
}
void RelationalExpression::setRight(IExpression* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), right, IExpression);
}
int RelationalExpression::getOpe(ThreadContext* ctx) throw() 
{
	return ope;
}
void RelationalExpression::setOpe(String* opeStr, ThreadContext* ctx) throw() 
{
	if(opeStr->equals(ConstStr::getCNST_STR_1010(), ctx))
	{
		this->ope = LT;
	}
		else 
	{
		if(opeStr->equals(ConstStr::getCNST_STR_82(), ctx))
		{
			this->ope = GT;
		}
				else 
		{
			if(opeStr->equals(ConstStr::getCNST_STR_1011(), ctx))
			{
				this->ope = LT_EQ;
			}
						else 
			{
				if(opeStr->equals(ConstStr::getCNST_STR_1012(), ctx))
				{
					this->ope = GT_EQ;
				}
			}
		}
	}
}
ExpressionSourceId* RelationalExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
int RelationalExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::relationalExpression;
}
void RelationalExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->left), static_cast<IExpression*>(el), IExpression);
	}
	this->ope = buff->getInt(ctx);
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->right), static_cast<IExpression*>(el), IExpression);
	}
}
void RelationalExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__RelationalExpression, ctx);
	bool isnull = (this->left == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->left->writeData(buff, ctx);
	}
	buff->putInt(this->ope, ctx);
	isnull = (this->right == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->right->writeData(buff, ctx);
	}
}
}}}}

