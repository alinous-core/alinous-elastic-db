#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace expstream {





constexpr const int FunctionCallExpression::SOURCE_FUNTION;
constexpr const int FunctionCallExpression::NATIVE_FUNTION;
constexpr const int FunctionCallExpression::JAVA_FUNTION;
constexpr const int FunctionCallExpression::CLASS_METHOD;
constexpr const int FunctionCallExpression::CLASS_STATIC_METHOD;
bool FunctionCallExpression::__init_done = __init_static_variables();
bool FunctionCallExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FunctionCallExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FunctionCallExpression::FunctionCallExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), body(nullptr), arguments(nullptr), functionType(0), analysedType(nullptr), sourceFunction(nullptr), nativeFunction(nullptr), memberMethod(nullptr), javaFuncPrefix(nullptr)
{
}
void FunctionCallExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 FunctionCallExpression::~FunctionCallExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FunctionCallExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FunctionCallExpression", L"~FunctionCallExpression");
	__e_obj1.add(this->body, this);
	body = nullptr;
	__e_obj1.add(this->arguments, this);
	arguments = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	__e_obj1.add(this->sourceFunction, this);
	sourceFunction = nullptr;
	__e_obj1.add(this->nativeFunction, this);
	nativeFunction = nullptr;
	__e_obj1.add(this->memberMethod, this);
	memberMethod = nullptr;
	__e_obj1.add(this->javaFuncPrefix, this);
	javaFuncPrefix = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool FunctionCallExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->arguments != nullptr && !this->arguments->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool FunctionCallExpression::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
FunctionArguments* FunctionCallExpression::getArguments(ThreadContext* ctx) throw() 
{
	return arguments;
}
void FunctionCallExpression::setArguments(FunctionArguments* arguments, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->arguments), arguments, FunctionArguments);
}
bool FunctionCallExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->analysedType), nullptr, AlinousType);
	if(this->arguments != nullptr)
	{
		this->arguments->analyse(context, true, ctx);
	}
	ExpressionStreamResult* result = context->getExpressionStreamResult(ctx);
	String* prefix = result->getFunctionPrefix(ctx);
	analyseSourceAndJavaFunction(prefix, context, ctx);
	if(this->analysedType != nullptr)
	{
		return true;
	}
	if(result->isStaticMember(ctx))
	{
		this->functionType = CLASS_STATIC_METHOD;
		AlinousType* thisType = result->getType(ctx);
		AlinousClass* clazz = thisType->getClazz(ctx);
		__GC_MV(this, &(this->memberMethod), clazz->getStaticMemberMethod(this->body, this->arguments, ctx), ClassMethodFunction);
		if(this->memberMethod == nullptr)
		{
			context->getSourceValidator(ctx)->addError(this->body->clone(ctx)->append(ConstStr::getCNST_STR_1019(), ctx), this, ctx);
			return false;
		}
		__GC_MV(this, &(this->analysedType), this->memberMethod->getFunc(ctx)->getReturnType(ctx)->getAnalysedType(ctx), AlinousType);
		return true;
	}
	this->functionType = CLASS_METHOD;
	AlinousType* thisType = result->getType(ctx);
	AlinousClass* clazz = thisType->getClazz(ctx);
	__GC_MV(this, &(this->memberMethod), clazz->getMemberMethod(this->body, this->arguments, ctx), ClassMethodFunction);
	if(this->memberMethod == nullptr)
	{
		context->getSourceValidator(ctx)->addError(this->body->clone(ctx)->append(ConstStr::getCNST_STR_1019(), ctx), this, ctx);
		return false;
	}
	__GC_MV(this, &(this->analysedType), this->memberMethod->getFunc(ctx)->getReturnType(ctx)->getAnalysedType(ctx), AlinousType);
	return true;
}
IAlinousVariable* FunctionCallExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	AlinousFunctionManager* functionManager = nullptr;
	switch(this->functionType) {
	case JAVA_FUNTION:
		functionManager = machine->getCore(ctx)->getFunctionManager(ctx);
		functionManager->invokeFunction(javaFuncPrefix, this->body, arguments, machine, debug, ctx);
		return machine->getReturnedValue(ctx);
	case NATIVE_FUNTION:
		functionManager = machine->getCore(ctx)->getFunctionManager(ctx);
		functionManager->invokeNativeFunction(this->nativeFunction, arguments, machine, debug, ctx);
		return machine->getReturnedValue(ctx);
	case SOURCE_FUNTION:
		return executeSourceFunction(this->sourceFunction, machine, debug, ctx);
	case CLASS_METHOD:
		return executeMemberMethod(machine, debug, ctx);
	case CLASS_STATIC_METHOD:
		return executeStaticMethod(machine, debug, ctx);
	default:
		break ;
	}
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
ExpressionSourceId* FunctionCallExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->analysedType, ctx));
}
int FunctionCallExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::functionCallExpression;
}
void FunctionCallExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->body), buff->getString(ctx), String);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<FunctionArguments*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_998(), ctx));
		}
		__GC_MV(this, &(this->arguments), static_cast<FunctionArguments*>(el), FunctionArguments);
	}
}
void FunctionCallExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__FunctionCallExpression, ctx);
	bool isnull = (this->body == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->body, ctx);
	}
	isnull = (this->arguments == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->arguments->writeData(buff, ctx);
	}
}
int FunctionCallExpression::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->body == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->body->length(ctx) * 2 + 4;
	}
	isnull = (this->arguments == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->arguments->fileSize(ctx);
	}
	return total;
}
void FunctionCallExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__FunctionCallExpression, ctx);
	bool isnull = (this->body == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->body, ctx);
	}
	isnull = (this->arguments == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->arguments->toFileEntry(builder, ctx);
	}
}
void FunctionCallExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->body), fetcher->fetchString(ctx), String);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<FunctionArguments*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_998(), ctx));
		}
		__GC_MV(this, &(this->arguments), static_cast<FunctionArguments*>(el), FunctionArguments);
	}
}
bool FunctionCallExpression::analyseSourceAndJavaFunction(String* prefix, SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	if(prefix != nullptr && context->isJavaFunction(prefix, this->body, ctx))
	{
		this->functionType = JAVA_FUNTION;
		__GC_MV(this, &(this->analysedType), context->getFunctionReturnType(prefix, this->body, ctx), AlinousType);
		return true;
	}
	if(prefix != nullptr && context->isNativeFunction(prefix, this->body, ctx))
	{
		this->functionType = NATIVE_FUNTION;
		__GC_MV(this, &(this->analysedType), context->getFunctionReturnType(prefix, this->body, ctx), AlinousType);
		__GC_MV(this, &(this->nativeFunction), context->getNativeFuncion(prefix, this->body, ctx), IAlinousNativeFunction);
		return true;
	}
	if(context->isSourceFunction(prefix, this->body, ctx))
	{
		this->functionType = SOURCE_FUNTION;
		__GC_MV(this, &(this->analysedType), context->getFunctionReturnType(prefix, this->body, ctx), AlinousType);
		__GC_MV(this, &(this->sourceFunction), context->getSourceFunction(prefix, this->body, ctx), AlinousFunction);
		return true;
	}
	return true;
}
IAlinousVariable* FunctionCallExpression::executeMemberMethod(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	AlinousClass* clazz = this->memberMethod->getAlinousClass(ctx);
	AlinousClassVariable* variable = static_cast<AlinousClassVariable*>(machine->getStreamLastValue(ctx));
	ClassMethodFunction* method = this->memberMethod;
	if(variable != nullptr)
	{
		method = method->resolveVirtual(variable->getClassDeclare(ctx), ctx);
	}
	clazz->invokeMemberMethod(variable, method, arguments, machine, debug, ctx);
	IAlinousVariable* returnedValue = machine->getReturnedValue(ctx);
	machine->setReturnedValue(nullptr, ctx);
	return returnedValue;
}
IAlinousVariable* FunctionCallExpression::executeStaticMethod(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	AlinousClass* clazz = this->memberMethod->getAlinousClass(ctx);
	clazz->invokeStaticMemberMethod(this->memberMethod, arguments, machine, debug, ctx);
	IAlinousVariable* returnedValue = machine->getReturnedValue(ctx);
	machine->setReturnedValue(nullptr, ctx);
	return returnedValue;
}
IAlinousVariable* FunctionCallExpression::executeSourceFunction(AlinousFunction* func, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ArrayList<FunctionArgumentDefine>* definelist = func->getArguments(ctx)->getList(ctx);
	ArrayList<IExpression>* actualArgs = this->arguments->arguments;
	if(definelist->size(ctx) != actualArgs->size(ctx))
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1020(), ctx));
	}
	ArrayList<IAlinousVariable>* args = (new(ctx) ArrayList<IAlinousVariable>(ctx));
	{
		try
		{
			int maxLoop = definelist->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IExpression* value = actualArgs->get(i, ctx);
				IAlinousVariable* variable = machine->resolveExpression(value, debug, ctx);
				args->add(variable, ctx);
			}
			machine->newStackFrame(func, ctx);
			MainStackFrame* frame = machine->getFrame(ctx);
			frame->subFrame(func->getBlock(ctx), ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				FunctionArgumentDefine* def = definelist->get(i, ctx);
				IAlinousVariable* variable = args->get(i, ctx);
				def->putArgument(machine, frame, variable, debug, ctx);
			}
			StatementList* stmtList = func->getBlock(ctx)->getList(ctx);
			ScriptRunner::executeStatementList(stmtList, machine, debug, ctx);
		}
		catch(Throwable* e)
		{
			machine->popStackFrame(ctx);
			throw e;
		}
	}
	machine->popStackFrame(ctx);
	IAlinousVariable* returnedValue = machine->getReturnedValue(ctx);
	machine->setReturnedValue(nullptr, ctx);
	return returnedValue;
}
}}}}

