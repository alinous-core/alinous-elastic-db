#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression.blexp/BooleanSubExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanCollectionExpression.h"
#include "alinous.compile.expression.blexp/AndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalAndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalOrExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanExpression.h"
#include "alinous.compile.expression.blexp/EqualityExpression.h"
#include "alinous.compile.expression.blexp/ExclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InclusiveOrExpression.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.compile.expression.blexp/InstanceOfExpression.h"
#include "alinous.compile.expression.blexp/NotExpression.h"
#include "alinous.compile.expression.blexp/RelationalExpression.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql.select.join/AbstractJoinTarget.h"
#include "alinous.compile.sql.select.join/TableJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.runtime.function/IAlinousNativeFunction.h"
#include "alinous.system.functions/AlinousFunctionManager.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql.expression/SQLSubExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLCollectionExpression.h"
#include "alinous.compile.sql.expression/SQLAdditiveExpression.h"
#include "alinous.compile.sql.expression/SQLLiteral.h"
#include "alinous.compile.sql.expression/SQLMultiplicativeExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.sql.expression/SQLSubqueryExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBooleanLiteral.h"
#include "alinous.compile.sql.expression.blexp/SQLEqualityExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLInExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLIsNullExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLLikeExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLNotExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLOrExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLRelationalExpression.h"
#include "alinous.compile.sql.parts/SQLExpressionListAll.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/ConditionalExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.select.join/AbstractSQLJoin.h"
#include "alinous.compile.sql.select.join/InnerJoin.h"
#include "alinous.compile.sql.select.join/CrossJoin.h"
#include "alinous.compile.sql.select.join/DomVariableJoinTarget.h"
#include "alinous.compile.sql.select.join/JoinSubQueryTarget.h"
#include "alinous.compile.sql.select.join/LeftJoin.h"
#include "alinous.compile.sql.select.join/NaturalJoin.h"
#include "alinous.compile.sql.select.join/RightJoin.h"
#include "alinous.compile.sql.select.join/TableList.h"
#include "alinous.compile.sql.select.join/WrappedJoinTarget.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/CatchBlock.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/FinallyBlock.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/ThrowStatement.h"
#include "alinous.compile.stmt/TryBlock.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"

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
			context->addError(this->body->clone(ctx)->append(ConstStr::getCNST_STR_1045(), ctx), this, ctx);
			return false;
		}
		AlinousFunction* alinousFunction = this->memberMethod->getFunc(ctx);
		ReturnValueDefinition* returndef = alinousFunction->getReturnType(ctx);
		__GC_MV(this, &(this->analysedType), returndef->getAnalysedType(ctx), AlinousType);
		return true;
	}
	this->functionType = CLASS_METHOD;
	AlinousType* thisType = result->getType(ctx);
	AlinousClass* clazz = thisType->getClazz(ctx);
	__GC_MV(this, &(this->memberMethod), clazz->getMemberMethod(this->body, this->arguments, ctx), ClassMethodFunction);
	if(this->memberMethod == nullptr)
	{
		context->addError(this->body->clone(ctx)->append(ConstStr::getCNST_STR_1045(), ctx), this, ctx);
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
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1034(), ctx));
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
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1034(), ctx));
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
	FunctionArgumentsListDefine* argslist = func->getArguments(ctx);
	ArrayList<FunctionArgumentDefine>* definelist = argslist->getList(ctx);
	ArrayList<IExpression>* actualArgs = this->arguments->arguments;
	if(definelist->size(ctx) != actualArgs->size(ctx))
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1046(), ctx));
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
			StatementBlock* blk = func->getBlock(ctx);
			StatementList* stmtList = blk->getList(ctx);
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
void FunctionCallExpression::__cleanUp(ThreadContext* ctx){
}
}}}}

