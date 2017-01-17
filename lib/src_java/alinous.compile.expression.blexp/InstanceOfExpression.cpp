#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace blexp {





bool InstanceOfExpression::__init_done = __init_static_variables();
bool InstanceOfExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InstanceOfExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InstanceOfExpression::~InstanceOfExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InstanceOfExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InstanceOfExpression", L"~InstanceOfExpression");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	if(!prepare){
		return;
	}
	AbstractBooleanExpression::__releaseRegerences(true, ctx);
}
bool InstanceOfExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
bool InstanceOfExpression::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool InstanceOfExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
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
IExpression* InstanceOfExpression::getLeft(ThreadContext* ctx) throw() 
{
	return left;
}
void InstanceOfExpression::setLeft(IExpression* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), left, IExpression);
}
AlinousName* InstanceOfExpression::getRight(ThreadContext* ctx) throw() 
{
	return right;
}
void InstanceOfExpression::setRight(AlinousName* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), right, AlinousName);
}
IAlinousVariable* InstanceOfExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
ExpressionSourceId* InstanceOfExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
int InstanceOfExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::instanceOfExpression;
}
void InstanceOfExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->right), static_cast<AlinousName*>(el), AlinousName);
	}
}
void InstanceOfExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__InstanceOfExpression, ctx);
	bool isnull = (this->left == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->left->writeData(buff, ctx);
	}
	isnull = (this->right == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->right->writeData(buff, ctx);
	}
}
int InstanceOfExpression::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->left == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->left->fileSize(ctx);
	}
	isnull = (this->right == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->right->fileSize(ctx);
	}
	return total;
}
void InstanceOfExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__InstanceOfExpression, ctx);
	bool isnull = (this->left == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->left->toFileEntry(builder, ctx);
		;
	}
	isnull = (this->right == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->right->toFileEntry(builder, ctx);
	}
}
void InstanceOfExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->left), static_cast<IExpression*>(el), IExpression);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		AlinousName* el = AlinousName::fromFileEntry(fetcher, ctx);
		if(el == nullptr)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->right), el, AlinousName);
	}
}
}}}}

