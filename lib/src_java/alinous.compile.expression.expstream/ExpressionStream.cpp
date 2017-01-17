#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace expstream {





bool ExpressionStream::__init_done = __init_static_variables();
bool ExpressionStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ExpressionStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ExpressionStream::ExpressionStream(ThreadContext* ctx) throw()  : IObject(ctx), IExpression(ctx), segments(GCUtils<ArrayList<IExpression> >::ins(this, (new(ctx) ArrayList<IExpression>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void ExpressionStream::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ExpressionStream::~ExpressionStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ExpressionStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ExpressionStream", L"~ExpressionStream");
	__e_obj1.add(this->segments, this);
	segments = nullptr;
	if(!prepare){
		return;
	}
	IExpression::__releaseRegerences(true, ctx);
}
AlinousName* ExpressionStream::toAlinousName(ThreadContext* ctx) throw() 
{
	AlinousName* name = (new(ctx) AlinousName(ctx));
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* ex = this->segments->get(i, ctx);
		if((dynamic_cast<ExpStreamSegment*>(ex) != 0))
		{
			ExpStreamSegment* seg = static_cast<ExpStreamSegment*>(ex);
			String* segid = seg->getName(ctx);
			name->addSegment(segid, ctx);
		}
				else 
		{
			return nullptr;
		}
	}
	return name;
}
FunctionArguments* ExpressionStream::getSQLFunctionArguments(ThreadContext* ctx) throw() 
{
	FunctionCallExpression* funcExp = nullptr;
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* ex = this->segments->get(i, ctx);
		if((dynamic_cast<FunctionCallExpression*>(ex) != 0))
		{
			funcExp = static_cast<FunctionCallExpression*>(ex);
			break ;
		}
	}
	return funcExp->getArguments(ctx);
}
String* ExpressionStream::getSQLFunctionName(ThreadContext* ctx) throw() 
{
	FunctionCallExpression* funcExp = nullptr;
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* ex = this->segments->get(i, ctx);
		if((dynamic_cast<FunctionCallExpression*>(ex) != 0))
		{
			funcExp = static_cast<FunctionCallExpression*>(ex);
			break ;
		}
	}
	return funcExp->body;
}
bool ExpressionStream::hasFunction(ThreadContext* ctx) throw() 
{
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* ex = this->segments->get(i, ctx);
		if((dynamic_cast<FunctionCallExpression*>(ex) != 0))
		{
			return true;
		}
	}
	return false;
}
bool ExpressionStream::isProgramOnlyOnAnalyze(ThreadContext* ctx) throw() 
{
	int funcIndex = -1;
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* ex = this->segments->get(i, ctx);
		if((dynamic_cast<FunctionCallExpression*>(ex) != 0))
		{
			if(funcIndex >= 0)
			{
				return true;
			}
			funcIndex = i;
		}
				else 
		{
			if((dynamic_cast<ExpStreamSegment*>(ex) != 0))
			{
				ExpStreamSegment* seg = static_cast<ExpStreamSegment*>(ex);
				if(seg->getArrayIndexes(ctx) != nullptr && !seg->getArrayIndexes(ctx)->isEmpty(ctx))
				{
					return true;
				}
				if(seg->getPrefix(ctx) != nullptr)
				{
					return true;
				}
			}
		}
	}
	if(funcIndex < 0)
	{
		return false;
	}
	return funcIndex != 0;
}
IAlinousVariable* ExpressionStream::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	machine->newExpressionStream(ctx);
	machine->setStreamLastValue(nullptr, ctx);
	IAlinousVariable* val = nullptr;
	{
		try
		{
			int maxLoop = this->segments->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IExpression* exp = this->segments->get(i, ctx);
				val = exp->resolveExpression(machine, debug, ctx);
				if(val == nullptr)
				{
					if(isDom(i, ctx))
					{
						return (new(ctx) DomVariable(ctx));
					}
					throw (new(ctx) ScriptNullPointerException(this, ctx));
				}
				machine->setStreamLastValue(val, ctx);
			}
		}
		catch(Throwable* e)
		{
			machine->endExpressionStream(ctx);
			throw e;
		}
	}
	machine->endExpressionStream(ctx);
	return val;
}
bool ExpressionStream::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* exp = this->segments->get(i, ctx);
		if(!exp->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool ExpressionStream::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
void ExpressionStream::addSegment(IExpression* segment, ThreadContext* ctx) throw() 
{
	this->segments->add(segment, ctx);
}
ArrayList<IExpression>* ExpressionStream::getSegments(ThreadContext* ctx) throw() 
{
	return segments;
}
bool ExpressionStream::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	context->newExpressionStream(ctx);
	ExpressionStreamResult* result = context->getExpressionStreamResult(ctx);
	{
		try
		{
			int maxLoop = this->segments->size(ctx);
			result->setMaxCount(maxLoop, ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IExpression* exp = this->segments->get(i, ctx);
				result->setCount(i, ctx);
				exp->analyse(context, leftValue, ctx);
			}
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			context->endExpressionStream(ctx);
			throw e;
		}
	}
	context->endExpressionStream(ctx);
	return true;
}
ExpressionSourceId* ExpressionStream::getSourceId(ThreadContext* ctx) throw() 
{
	int peekindex = this->segments->size(ctx) - 1;
	AlinousType* type = this->segments->get(peekindex, ctx)->getSourceId(ctx)->getType(ctx);
	return (new(ctx) ExpressionSourceId(nullptr, this, type, ctx));
}
int ExpressionStream::getLine(ThreadContext* ctx) throw() 
{
	return IExpression::getLine(ctx);
}
int ExpressionStream::getStartPosition(ThreadContext* ctx) throw() 
{
	return IExpression::getStartPosition(ctx);
}
int ExpressionStream::getEndLine(ThreadContext* ctx) throw() 
{
	return IExpression::getEndLine(ctx);
}
int ExpressionStream::getEndPosition(ThreadContext* ctx) throw() 
{
	return IExpression::getEndPosition(ctx);
}
AbstractSrcElement* ExpressionStream::getParent(ThreadContext* ctx) throw() 
{
	return IExpression::getParent(ctx);
}
void ExpressionStream::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IExpression::setParent(parent, ctx);
}
bool ExpressionStream::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int ExpressionStream::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::expressionStream;
}
void ExpressionStream::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		this->segments->add(static_cast<IExpression*>(el), ctx);
	}
}
void ExpressionStream::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ExpressionStream, ctx);
	int maxLoop = this->segments->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* exp = this->segments->get(i, ctx);
		exp->writeData(buff, ctx);
	}
}
int ExpressionStream::fileSize(ThreadContext* ctx)
{
	int total = 4;
	int maxLoop = this->segments->size(ctx);
	total += 4;
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* exp = this->segments->get(i, ctx);
		total += exp->fileSize(ctx);
	}
	return total;
}
void ExpressionStream::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__ExpressionStream, ctx);
	int maxLoop = this->segments->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* exp = this->segments->get(i, ctx);
		exp->toFileEntry(builder, ctx);
	}
}
void ExpressionStream::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		this->segments->add(static_cast<IExpression*>(el), ctx);
	}
}
bool ExpressionStream::isDom(int currentPosition, ThreadContext* ctx) throw() 
{
	int pos = currentPosition;
	IExpression* exp = this->segments->get(pos, ctx);
	int type = exp->getExpressionType(ctx);
	if(type == IExpression::expStreamSegment)
	{
		ExpStreamSegment* seg = static_cast<ExpStreamSegment*>(exp);
		if(seg->domPath != nullptr)
		{
			return true;
		}
	}
	return false;
}
}}}}

