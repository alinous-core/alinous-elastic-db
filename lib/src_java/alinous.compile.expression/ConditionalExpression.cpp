#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/ConditionalExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.expression/IExpressionFactory.h"

namespace alinous {namespace compile {namespace expression {





bool ConditionalExpression::__init_done = __init_static_variables();
bool ConditionalExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConditionalExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConditionalExpression::ConditionalExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), first(nullptr), exp(nullptr), altexp(nullptr)
{
}
void ConditionalExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ConditionalExpression::~ConditionalExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConditionalExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ConditionalExpression", L"~ConditionalExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->altexp, this);
	altexp = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool ConditionalExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(first != nullptr && !first->visit(visitor, parent, ctx))
	{
		return false;
	}
	if(exp != nullptr && !exp->visit(visitor, parent, ctx))
	{
		return false;
	}
	if(altexp != nullptr && !altexp->visit(visitor, parent, ctx))
	{
		return false;
	}
	return true;
}
bool ConditionalExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(first != nullptr && !first->isConstant(ctx))
	{
		return false;
	}
	if(exp != nullptr && !exp->isConstant(ctx))
	{
		return false;
	}
	if(altexp != nullptr && !altexp->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool ConditionalExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(first != nullptr)
	{
		first->analyse(context, leftValue, ctx);
	}
	if(exp != nullptr)
	{
		exp->analyse(context, leftValue, ctx);
	}
	if(exp != nullptr)
	{
		exp->analyse(context, leftValue, ctx);
	}
	return true;
}
IExpression* ConditionalExpression::getFirst(ThreadContext* ctx) throw() 
{
	return first;
}
void ConditionalExpression::setFirst(IExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, IExpression);
}
IExpression* ConditionalExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void ConditionalExpression::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
IExpression* ConditionalExpression::getAltexp(ThreadContext* ctx) throw() 
{
	return altexp;
}
void ConditionalExpression::setAltexp(IExpression* altexp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->altexp), altexp, IExpression);
}
IAlinousVariable* ConditionalExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* condition = machine->resolveExpression(this->first, debug, ctx);
	if(condition->isTrue(ctx))
	{
		return machine->resolveExpression(this->exp, debug, ctx);
	}
	return machine->resolveExpression(this->altexp, debug, ctx);
}
ExpressionSourceId* ConditionalExpression::getSourceId(ThreadContext* ctx) throw() 
{
	AlinousType* type = this->exp->getSourceId(ctx)->getType(ctx);
	AlinousType* type2 = this->exp->getSourceId(ctx)->getType(ctx);
	if(type->getType(ctx) < type2->getType(ctx))
	{
		type = type2;
	}
	return (new(ctx) ExpressionSourceId(nullptr, this, type, ctx));
}
bool ConditionalExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int ConditionalExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::conditionalExpression;
}
void ConditionalExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<IExpression*>(el), IExpression);
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
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->altexp), static_cast<IExpression*>(el), IExpression);
	}
}
void ConditionalExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__ConditionalExpression, ctx);
	bool isnull = (this->first == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->writeData(buff, ctx);
	}
	isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
	isnull = (this->altexp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->altexp->writeData(buff, ctx);
	}
}
int ConditionalExpression::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->first == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->first->fileSize(ctx);
	}
	isnull = (this->exp == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->exp->fileSize(ctx);
	}
	isnull = (this->altexp == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->altexp->fileSize(ctx);
	}
	return total;
}
void ConditionalExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__ConditionalExpression, ctx);
	bool isnull = (this->first == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->toFileEntry(builder, ctx);
	}
	isnull = (this->exp == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->toFileEntry(builder, ctx);
	}
	isnull = (this->altexp == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->altexp->toFileEntry(builder, ctx);
	}
}
void ConditionalExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<IExpression*>(el), IExpression);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<IExpression*>(el), IExpression);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->altexp), static_cast<IExpression*>(el), IExpression);
	}
}
void ConditionalExpression::__cleanUp(ThreadContext* ctx){
}
}}}

