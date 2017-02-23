#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool ForUpdatePart::__init_done = __init_static_variables();
bool ForUpdatePart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ForUpdatePart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ForUpdatePart::~ForUpdatePart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ForUpdatePart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ForUpdatePart", L"~ForUpdatePart");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	__e_obj1.add(this->ope, this);
	ope = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void ForUpdatePart::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool ForUpdatePart::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
bool ForUpdatePart::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr)
	{
		this->left->analyse(context, true, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyse(context, false, ctx);
	}
	return true;
}
IStatement::StatementType ForUpdatePart::getType(ThreadContext* ctx) throw() 
{
	return StatementType::FOR_UPDATE_STATEMENT_PART;
}
IExpression* ForUpdatePart::getLeft(ThreadContext* ctx) throw() 
{
	return left;
}
void ForUpdatePart::setLeft(IExpression* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), left, IExpression);
}
IExpression* ForUpdatePart::getRight(ThreadContext* ctx) throw() 
{
	return right;
}
void ForUpdatePart::setRight(IExpression* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), right, IExpression);
}
String* ForUpdatePart::getOpe(ThreadContext* ctx) throw() 
{
	return ope;
}
void ForUpdatePart::setOpe(String* ope, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->ope), ope, String);
}
void ForUpdatePart::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->right), static_cast<IExpression*>(el), IExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->ope), buff->getString(ctx), String);
	}
}
void ForUpdatePart::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__ForUpdatePart, ctx);
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
	isnull = (this->ope == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->ope, ctx);
	}
}
}}}

