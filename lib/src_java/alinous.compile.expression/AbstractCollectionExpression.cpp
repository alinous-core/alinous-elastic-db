#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"

namespace alinous {namespace compile {namespace expression {





bool AbstractCollectionExpression::__init_done = __init_static_variables();
bool AbstractCollectionExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractCollectionExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractCollectionExpression::AbstractCollectionExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), first(nullptr), expressions(GCUtils<ArrayList<SubExpression> >::ins(this, (new(ctx) ArrayList<SubExpression>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AbstractCollectionExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractCollectionExpression::~AbstractCollectionExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractCollectionExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractCollectionExpression", L"~AbstractCollectionExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->expressions, this);
	expressions = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
void AbstractCollectionExpression::setFirst(IExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, IExpression);
}
ArrayList<SubExpression>* AbstractCollectionExpression::getExpressions(ThreadContext* ctx) throw() 
{
	return expressions;
}
void AbstractCollectionExpression::addSubExpression(SubExpression* exp, ThreadContext* ctx) throw() 
{
	this->expressions->add(exp, ctx);
}
bool AbstractCollectionExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && !this->first->isConstant(ctx))
	{
		return false;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->expressions->get(i, ctx)->isConstant(ctx))
		{
			return false;
		}
	}
	return true;
}
bool AbstractCollectionExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->first != nullptr && !this->first->visit(visitor, this, ctx))
	{
		return false;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->expressions->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool AbstractCollectionExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr)
	{
		return first->analyse(context, leftValue, ctx);
	}
	return true;
}
ExpressionSourceId* AbstractCollectionExpression::getSourceId(ThreadContext* ctx) throw() 
{
	AlinousType* type = this->first->getSourceId(ctx)->getType(ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SubExpression* subexp = this->expressions->get(i, ctx);
		AlinousType* subType = subexp->getSourceId(ctx)->getType(ctx);
		if(subType->getType(ctx) > type->getType(ctx))
		{
			type = subType;
		}
	}
	return (new(ctx) ExpressionSourceId(nullptr, this, type, ctx));
}
void AbstractCollectionExpression::__readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1027(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<IExpression*>(el), IExpression);
	}
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SubExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1028(), ctx));
		}
		this->expressions->add(static_cast<SubExpression*>(el), ctx);
	}
}
void AbstractCollectionExpression::__writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = (this->first == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->writeData(buff, ctx);
	}
	int maxLoop = this->expressions->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		SubExpression* exp = this->expressions->get(i, ctx);
		exp->writeData(buff, ctx);
	}
}
int AbstractCollectionExpression::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->first == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->first->fileSize(ctx);
	}
	int maxLoop = this->expressions->size(ctx);
	total += 4;
	for(int i = 0; i < maxLoop; ++i)
	{
		SubExpression* exp = this->expressions->get(i, ctx);
		total += exp->fileSize(ctx);
	}
	return total;
}
void AbstractCollectionExpression::__toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	bool isnull = (this->first == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->toFileEntry(builder, ctx);
	}
	int maxLoop = this->expressions->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		SubExpression* exp = this->expressions->get(i, ctx);
		exp->toFileEntry(builder, ctx);
	}
}
void AbstractCollectionExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1027(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<IExpression*>(el), IExpression);
	}
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<SubExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1028(), ctx));
		}
		this->expressions->add(static_cast<SubExpression*>(el), ctx);
	}
}
void AbstractCollectionExpression::includes(AlinousElementNetworkFactory* arg0, IExpressionFactory* arg1, ThreadContext* ctx) throw() 
{
}
void AbstractCollectionExpression::__cleanUp(ThreadContext* ctx){
}
}}}

