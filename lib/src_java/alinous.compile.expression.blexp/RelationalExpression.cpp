#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression.blexp/BooleanSubExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanCollectionExpression.h"
#include "alinous.compile.expression.blexp/ConditionalAndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalOrExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanExpression.h"
#include "alinous.compile.expression.blexp/EqualityExpression.h"
#include "alinous.compile.expression.blexp/ExclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InstanceOfExpression.h"
#include "alinous.compile.expression.blexp/RelationalExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.expression.blexp/AndExpression.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression.blexp/NotExpression.h"

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
 RelationalExpression::RelationalExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractBooleanExpression(ctx), left(nullptr), ope(0), right(nullptr)
{
}
void RelationalExpression::__construct_impl(ThreadContext* ctx) throw() 
{
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
void RelationalExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
int RelationalExpression::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->left == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->left->fileSize(ctx);
	}
	total += 4;
	isnull = (this->right == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->right->fileSize(ctx);
	}
	return total;
}
void RelationalExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__RelationalExpression, ctx);
	bool isnull = (this->left == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->left->toFileEntry(builder, ctx);
	}
	builder->putInt(this->ope, ctx);
	isnull = (this->right == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->right->toFileEntry(builder, ctx);
	}
}
void RelationalExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
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
	this->ope = fetcher->fetchInt(ctx);
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->right), static_cast<IExpression*>(el), IExpression);
	}
}
void RelationalExpression::__cleanUp(ThreadContext* ctx){
}
}}}}

