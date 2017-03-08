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
#include "alinous.compile.declare/IDeclare.h"
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
#include "alinous.compile.expression.blexp/InstanceOfExpression.h"
#include "alinous.compile.expression.blexp/NotExpression.h"
#include "alinous.compile.expression.blexp/RelationalExpression.h"
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
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
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
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/VirtualTable.h"
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
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.analyse.tools/MatchingMethodCandidate.h"
#include "alinous.compile.analyse.tools/ClassMethodArgumentMatcher.h"
#include "alinous.compile.declare/AlinousClass.h"

namespace alinous {namespace compile {namespace declare {





bool AlinousClass::__init_done = __init_static_variables();
bool AlinousClass::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousClass", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousClass::AlinousClass(ThreadContext* ctx) throw()  : IObject(ctx), IDeclare(ctx), packageName(nullptr), name(nullptr), extendsClasses(nullptr), implementsClass(nullptr), interfaceClass(0), constructors(GCUtils<ArrayList<ClassMethodFunction> >::ins(this, (new(ctx) ArrayList<ClassMethodFunction>(ctx)), ctx, __FILEW__, __LINE__, L"")), members(GCUtils<ArrayList<ClassMemberVariable> >::ins(this, (new(ctx) ArrayList<ClassMemberVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), methods(GCUtils<ArrayList<ClassMethodFunction> >::ins(this, (new(ctx) ArrayList<ClassMethodFunction>(ctx)), ctx, __FILEW__, __LINE__, L"")), staticMembers(GCUtils<ArrayList<ClassMemberVariable> >::ins(this, (new(ctx) ArrayList<ClassMemberVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), staticMethods(GCUtils<ArrayList<ClassMethodFunction> >::ins(this, (new(ctx) ArrayList<ClassMethodFunction>(ctx)), ctx, __FILEW__, __LINE__, L"")), delivedClasses(GCUtils<ArrayList<AlinousClass> >::ins(this, (new(ctx) ArrayList<AlinousClass>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AlinousClass::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousClass::~AlinousClass() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousClass::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousClass", L"~AlinousClass");
	__e_obj1.add(this->packageName, this);
	packageName = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->extendsClasses, this);
	extendsClasses = nullptr;
	__e_obj1.add(this->implementsClass, this);
	implementsClass = nullptr;
	__e_obj1.add(this->constructors, this);
	constructors = nullptr;
	__e_obj1.add(this->members, this);
	members = nullptr;
	__e_obj1.add(this->methods, this);
	methods = nullptr;
	__e_obj1.add(this->staticMembers, this);
	staticMembers = nullptr;
	__e_obj1.add(this->staticMethods, this);
	staticMethods = nullptr;
	__e_obj1.add(this->delivedClasses, this);
	delivedClasses = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
void AlinousClass::initStatic(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	int maxLoop = this->staticMembers->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMemberVariable* val = this->staticMembers->get(i, ctx);
		val->initStatic(machine, debug, ctx);
	}
}
bool AlinousClass::hasBaseClass(AlinousClass* other, ThreadContext* ctx) throw() 
{
	if(equals(other, ctx))
	{
		return true;
	}
	AlinousClass* clazz = this->extendsClasses->getAnalysedClazz(ctx);
	return clazz->hasBaseClass(other, ctx);
}
bool AlinousClass::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<AlinousClass*>(obj) != 0)))
	{
		return false;
	}
	AlinousClass* other = dynamic_cast<AlinousClass*>(obj);
	return this->packageName->equals(other->packageName, ctx) && this->name->equals(other->name, ctx);
}
ClassMemberVariable* AlinousClass::getStaticMemberVariable(String* name, ThreadContext* ctx) throw() 
{
	int maxLoop = this->staticMembers->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMemberVariable* val = this->staticMembers->get(i, ctx);
		if(val->getName(ctx)->equals(name, ctx))
		{
			return val;
		}
	}
	return nullptr;
}
ClassMethodFunction* AlinousClass::getMemberMethod(String* functionName, FunctionArguments* arguments, ThreadContext* ctx) throw() 
{
	ArrayList<ClassMethodFunction>* candidates = (new(ctx) ArrayList<ClassMethodFunction>(ctx));
	int maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMethodFunction* m = this->methods->get(i, ctx);
		if(m->getFunc(ctx)->getName(ctx)->equals(functionName, ctx))
		{
			candidates->add(m, ctx);
		}
	}
	ClassMethodArgumentMatcher* matcher = (new(ctx) ClassMethodArgumentMatcher(arguments, candidates, ctx));
	MatchingMethodCandidate* constructorDeclare = matcher->match(ctx);
	if(constructorDeclare != nullptr)
	{
		return constructorDeclare->getMethod(ctx);
	}
	if(this->getExtendsClasses(ctx) != nullptr)
	{
		AlinousClass* superClazz = this->getExtendsClasses(ctx)->getAnalysedClazz(ctx);
		return superClazz->getMemberMethod(functionName, arguments, ctx);
	}
	return nullptr;
}
ClassMethodFunction* AlinousClass::getStaticMemberMethod(String* functionName, FunctionArguments* arguments, ThreadContext* ctx) throw() 
{
	ArrayList<ClassMethodFunction>* candidates = (new(ctx) ArrayList<ClassMethodFunction>(ctx));
	int maxLoop = this->staticMethods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMethodFunction* m = this->staticMethods->get(i, ctx);
		if(m->getFunc(ctx)->getName(ctx)->equals(functionName, ctx))
		{
			candidates->add(m, ctx);
		}
	}
	ClassMethodArgumentMatcher* matcher = (new(ctx) ClassMethodArgumentMatcher(arguments, candidates, ctx));
	MatchingMethodCandidate* constructorDeclare = matcher->match(ctx);
	if(constructorDeclare != nullptr)
	{
		return constructorDeclare->getMethod(ctx);
	}
	return nullptr;
}
ClassMethodFunction* AlinousClass::getConstructorFunction(FunctionArguments* arguments, ThreadContext* ctx) throw() 
{
	ClassMethodArgumentMatcher* matcher = (new(ctx) ClassMethodArgumentMatcher(arguments, this->constructors, ctx));
	MatchingMethodCandidate* constructorDeclare = matcher->match(ctx);
	if(constructorDeclare != nullptr)
	{
		return constructorDeclare->getMethod(ctx);
	}
	return nullptr;
}
void AlinousClass::invokeStaticMemberMethod(ClassMethodFunction* method, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	{
		try
		{
			AlinousFunction* func = method->getFunc(ctx);
			machine->newStackFrame(func, ctx);
			MainStackFrame* frame = machine->getFrame(ctx);
			StatementBlock* blk = func->getBlock(ctx);
			frame->subFrame(blk, ctx);
			ArrayList<IAlinousVariable>* args = (new(ctx) ArrayList<IAlinousVariable>(ctx));
			FunctionArgumentsListDefine* argsListDef = func->getArguments(ctx);
			ArrayList<FunctionArgumentDefine>* definelist = argsListDef->getList(ctx);
			ArrayList<IExpression>* actualArgs = arguments->arguments;
			int maxLoop = definelist->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IExpression* value = actualArgs->get(i, ctx);
				IAlinousVariable* variable = machine->resolveExpression(value, debug, ctx);
				args->add(variable, ctx);
			}
			for(int i = 0; i != maxLoop; ++i)
			{
				FunctionArgumentDefine* def = definelist->get(i, ctx);
				IAlinousVariable* variable = args->get(i, ctx);
				def->putArgument(machine, frame, variable, debug, ctx);
			}
			StatementList* stmtList = func->getBlock(ctx)->getList(ctx);
			if(stmtList != nullptr)
			{
				ScriptRunner::executeStatementList(stmtList, machine, debug, ctx);
			}
		}
		catch(Throwable* e)
		{
			machine->popStackFrame(ctx);
			throw e;
		}
	}
	machine->popStackFrame(ctx);
}
void AlinousClass::invokeMemberMethod(AlinousClassVariable* obj, ClassMethodFunction* method, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	{
		try
		{
			AlinousFunction* func = method->getFunc(ctx);
			machine->newStackFrame(func, ctx);
			MainStackFrame* frame = machine->getFrame(ctx);
			machine->setThisPtr(obj, ctx);
			frame->subFrame(func->getBlock(ctx), ctx);
			ArrayList<IAlinousVariable>* args = (new(ctx) ArrayList<IAlinousVariable>(ctx));
			ArrayList<FunctionArgumentDefine>* definelist = func->getArguments(ctx)->getList(ctx);
			ArrayList<IExpression>* actualArgs = arguments->arguments;
			int maxLoop = definelist->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IExpression* value = actualArgs->get(i, ctx);
				IAlinousVariable* variable = machine->resolveExpression(value, debug, ctx);
				args->add(variable, ctx);
			}
			for(int i = 0; i != maxLoop; ++i)
			{
				FunctionArgumentDefine* def = definelist->get(i, ctx);
				IAlinousVariable* variable = args->get(i, ctx);
				def->putArgument(machine, frame, variable, debug, ctx);
			}
			StatementList* stmtList = func->getBlock(ctx)->getList(ctx);
			if(stmtList != nullptr)
			{
				ScriptRunner::executeStatementList(stmtList, machine, debug, ctx);
			}
		}
		catch(Throwable* e)
		{
			machine->popStackFrame(ctx);
			throw e;
		}
	}
	machine->popStackFrame(ctx);
}
void AlinousClass::invokeConstructorMethod(AlinousClassVariable* obj, ClassMethodFunction* method, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	{
		try
		{
			AlinousFunction* func = method->getFunc(ctx);
			machine->newStackFrame(func, ctx);
			MainStackFrame* frame = machine->getFrame(ctx);
			machine->setThisPtr(obj, ctx);
			frame->subFrame(func->getBlock(ctx), ctx);
			initMembers(obj, machine, debug, ctx);
			ArrayList<IAlinousVariable>* args = (new(ctx) ArrayList<IAlinousVariable>(ctx));
			ArrayList<FunctionArgumentDefine>* definelist = func->getArguments(ctx)->getList(ctx);
			ArrayList<IExpression>* actualArgs = arguments->arguments;
			int maxLoop = definelist->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IExpression* value = actualArgs->get(i, ctx);
				IAlinousVariable* variable = machine->resolveExpression(value, debug, ctx);
				args->add(variable, ctx);
			}
			for(int i = 0; i != maxLoop; ++i)
			{
				FunctionArgumentDefine* def = definelist->get(i, ctx);
				IAlinousVariable* variable = args->get(i, ctx);
				def->putArgument(machine, frame, variable, debug, ctx);
			}
			if(method->getSuperConstructor(ctx) != nullptr)
			{
				ClassMethodFunction* superConst = method->getSuperConstructor(ctx);
				AlinousClass* superClazz = superConst->getAlinousClass(ctx);
				superClazz->invokeConstructorMethod(obj, superConst, arguments, machine, debug, ctx);
			}
			StatementList* stmtList = func->getBlock(ctx)->getList(ctx);
			if(stmtList != nullptr)
			{
				ScriptRunner::executeStatementList(stmtList, machine, debug, ctx);
			}
		}
		catch(Throwable* e)
		{
			machine->popStackFrame(ctx);
			throw e;
		}
	}
	machine->popStackFrame(ctx);
}
bool AlinousClass::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->extendsClasses != nullptr && !this->extendsClasses->visit(visitor, this, ctx))
	{
		return false;
	}
	int maxLoop = this->implementsClass == nullptr ? 0 : this->implementsClass->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->implementsClass->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->constructors->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->constructors->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->members->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->members->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->methods->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->staticMembers->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->staticMembers->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->staticMethods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->staticMethods->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
void AlinousClass::analyseVirtualMethods(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMethodFunction* method = this->methods->get(i, ctx);
		analyzeMethodVirtual(context, method, ctx);
	}
}
ClassMethodFunction* AlinousClass::getOverrodeMethod(ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	int maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMethodFunction* m = this->methods->get(i, ctx);
		if(method->sameSig(m, ctx))
		{
			return m;
		}
	}
	return nullptr;
}
void AlinousClass::analyseDependency(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	if(this->extendsClasses != nullptr)
	{
		this->extendsClasses->analyse(context, false, ctx);
		AlinousClass* baseClass = this->extendsClasses->getAnalysedClazz(ctx);
		if(baseClass == nullptr)
		{
			AlinousName* className = this->extendsClasses->getClassName(ctx);
			context->addError(className->toString(ctx)->clone(ctx)->append(ConstStr::getCNST_STR_972(), ctx), this, ctx);
			return;
		}
		baseClass->delivedClasses->add(this, ctx);
	}
	if(this->implementsClass != nullptr)
	{
		Iterator<ClassImplements>* it = this->implementsClass->iterator(ctx);
		while(it->hasNext(ctx))
		{
			ClassImplements* impl = it->next(ctx);
			impl->analyse(context, false, ctx);
			AlinousClass* baseClass = impl->getAnalysedClazz(ctx);
			if(baseClass == nullptr)
			{
				AlinousName* className = impl->getClassName(ctx);
				context->addError(className->toString(ctx)->clone(ctx)->append(ConstStr::getCNST_STR_972(), ctx), this, ctx);
				return;
			}
			baseClass->delivedClasses->add(this, ctx);
		}
	}
}
bool AlinousClass::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->name != nullptr)
	{
		this->name->analyse(context, leftValue, ctx);
	}
	if(this->extendsClasses != nullptr)
	{
		this->extendsClasses->analyse(context, leftValue, ctx);
	}
	int maxLoop = this->implementsClass == nullptr ? 0 : this->implementsClass->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->implementsClass->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->members->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->members->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->constructors->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->constructors->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->methods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->methods->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->staticMembers->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->staticMembers->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->staticMethods->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->staticMethods->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
AlinousName* AlinousClass::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void AlinousClass::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
ClassExtends* AlinousClass::getExtendsClasses(ThreadContext* ctx) throw() 
{
	return extendsClasses;
}
void AlinousClass::setExtendsClasses(ClassExtends* extendsClasses, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->extendsClasses), extendsClasses, ClassExtends);
}
void AlinousClass::addVariable(ClassMemberVariable* val, ThreadContext* ctx) throw() 
{
	this->members->add(val, ctx);
}
void AlinousClass::addMethod(ClassMethodFunction* val, ThreadContext* ctx) throw() 
{
	String* funcName = val->getFunc(ctx)->getFunctionName(ctx);
	if(funcName->equals(this->name->toString(ctx), ctx))
	{
		this->constructors->add(val, ctx);
		val->setConstructorMethod(true, ctx);
		return;
	}
	this->methods->add(val, ctx);
}
void AlinousClass::addStaticVariable(ClassMemberVariable* val, ThreadContext* ctx) throw() 
{
	this->staticMembers->add(val, ctx);
}
void AlinousClass::addStaticMethod(ClassMethodFunction* val, ThreadContext* ctx) throw() 
{
	this->staticMethods->add(val, ctx);
}
ClassMemberVariable* AlinousClass::getMember(String* name, ThreadContext* ctx) throw() 
{
	Iterator<ClassMemberVariable>* it = this->members->iterator(ctx);
	while(it->hasNext(ctx))
	{
		ClassMemberVariable* val = it->next(ctx);
		if(val->isSame(name, ctx))
		{
			return val;
		}
	}
	return nullptr;
}
ArrayList<ClassMemberVariable>* AlinousClass::getMembers(ThreadContext* ctx) throw() 
{
	return members;
}
ArrayList<ClassMethodFunction>* AlinousClass::getMethods(ThreadContext* ctx) throw() 
{
	return methods;
}
ArrayList<ClassMemberVariable>* AlinousClass::getStaticMembers(ThreadContext* ctx) throw() 
{
	return staticMembers;
}
ArrayList<ClassMethodFunction>* AlinousClass::getStaticMethods(ThreadContext* ctx) throw() 
{
	return staticMethods;
}
AlinousModulePackage* AlinousClass::getPackageName(ThreadContext* ctx) throw() 
{
	return packageName;
}
void AlinousClass::setPackageName(AlinousModulePackage* packageName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->packageName), packageName, AlinousModulePackage);
}
String* AlinousClass::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->packageName != nullptr)
	{
		buff->append(this->packageName->toString(ctx), ctx)->append(ConstStr::getCNST_STR_950(), ctx);
	}
	buff->append(this->name->toString(ctx), ctx);
	return buff->toString(ctx);
}
int AlinousClass::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int AlinousClass::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int AlinousClass::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int AlinousClass::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* AlinousClass::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void AlinousClass::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
bool AlinousClass::isInterfaceClass(ThreadContext* ctx) throw() 
{
	return interfaceClass;
}
void AlinousClass::setInterfaceClass(bool interfaceClass, ThreadContext* ctx) throw() 
{
	this->interfaceClass = interfaceClass;
}
ArrayList<ClassImplements>* AlinousClass::getImplementsClass(ThreadContext* ctx) throw() 
{
	return implementsClass;
}
void AlinousClass::setImplementsClass(ArrayList<ClassImplements>* implementsClass, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<ClassImplements> >::mv(this, &(this->implementsClass), implementsClass, ctx);
}
void AlinousClass::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousModulePackage*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_973(), ctx));
		}
		__GC_MV(this, &(this->packageName), static_cast<AlinousModulePackage*>(el), AlinousModulePackage);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->name), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ClassExtends*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_974(), ctx));
		}
		__GC_MV(this, &(this->extendsClasses), static_cast<ClassExtends*>(el), ClassExtends);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		int maxLoop = buff->getInt(ctx);
		for(int i = 0; i < maxLoop; ++i)
		{
			IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
			if(el == nullptr || !((dynamic_cast<ClassImplements*>(el) != 0)))
			{
				throw (new(ctx) VariableException(ConstStr::getCNST_STR_975(), ctx));
			}
			this->implementsClass->add(static_cast<ClassImplements*>(el), ctx);
		}
	}
	this->interfaceClass = buff->getBoolean(ctx);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ClassMethodFunction*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_971(), ctx));
		}
		this->constructors->add(static_cast<ClassMethodFunction*>(el), ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ClassMemberVariable*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_976(), ctx));
		}
		this->members->add(static_cast<ClassMemberVariable*>(el), ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ClassMethodFunction*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_971(), ctx));
		}
		this->methods->add(static_cast<ClassMethodFunction*>(el), ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ClassMemberVariable*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_976(), ctx));
		}
		this->staticMembers->add(static_cast<ClassMemberVariable*>(el), ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ClassMethodFunction*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_971(), ctx));
		}
		this->staticMethods->add(static_cast<ClassMethodFunction*>(el), ctx);
	}
}
void AlinousClass::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__AlinousClass, ctx);
	bool isnull = (this->packageName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->packageName->writeData(buff, ctx);
	}
	isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->name->writeData(buff, ctx);
	}
	isnull = (this->extendsClasses == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->extendsClasses->writeData(buff, ctx);
	}
	isnull = (this->implementsClass == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		int maxLoop = this->implementsClass->size(ctx);
		buff->putInt(maxLoop, ctx);
		for(int i = 0; i < maxLoop; ++i)
		{
			ClassImplements* exp = this->implementsClass->get(i, ctx);
			exp->writeData(buff, ctx);
		}
	}
	buff->putBoolean(this->interfaceClass, ctx);
	int maxLoop = this->constructors->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		ClassMethodFunction* exp = this->constructors->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	maxLoop = this->members->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		ClassMemberVariable* exp = this->members->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	maxLoop = this->methods->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		ClassMethodFunction* exp = this->methods->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	maxLoop = this->staticMembers->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		ClassMemberVariable* exp = this->staticMembers->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	maxLoop = this->staticMethods->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		ClassMethodFunction* exp = this->staticMethods->get(i, ctx);
		exp->writeData(buff, ctx);
	}
}
void AlinousClass::initMembers(AlinousClassVariable* obj, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ArrayList<ClassMemberVariable>* members = this->members;
	int maxLoop = members->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClassMemberVariable* variableDefine = members->get(i, ctx);
		variableDefine->initMember(obj, machine, debug, ctx);
	}
}
void AlinousClass::analyzeMethodVirtual(SrcAnalyseContext* context, ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	bool isVirtual = false;
	Iterator<AlinousClass>* it = this->delivedClasses->iterator(ctx);
	while(it->hasNext(ctx))
	{
		AlinousClass* dclazz = it->next(ctx);
		ClassMethodFunction* m = dclazz->getOverrodeMethod(method, ctx);
		if(m != nullptr)
		{
			method->setVirtualMethod(true, ctx);
			isVirtual = true;
		}
	}
	ClassExtends* extClazz = this->extendsClasses;
	while(extClazz != nullptr)
	{
		AlinousClass* cl = context->findClassDeclare(extClazz->getClassName(ctx), ctx);
		ClassMethodFunction* m = cl->getOverrodeMethod(method, ctx);
		if(m != nullptr)
		{
			method->setVirtualMethod(true, ctx);
			isVirtual = true;
		}
		extClazz = cl->getExtendsClasses(ctx);
	}
	ArrayList<ClassImplements>* implementsClass = this->implementsClass;
	while(implementsClass != nullptr && !implementsClass->isEmpty(ctx))
	{
		Iterator<ClassImplements>* implIt = implementsClass->iterator(ctx);
		while(implIt->hasNext(ctx))
		{
			ClassImplements* impls = implIt->next(ctx);
			isVirtual = findInterfaces(impls, context, method, ctx);
		}
	}
	if(isVirtual)
	{
		createVirtualTable(context, method, ctx);
	}
}
bool AlinousClass::findInterfaces(ClassImplements* impls, SrcAnalyseContext* context, ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	AlinousClass* clazz = impls->getAnalysedClazz(ctx);
	ClassExtends* extClazz = clazz->extendsClasses;
	while(extClazz != nullptr)
	{
		AlinousClass* cl = context->findClassDeclare(extClazz->getClassName(ctx), ctx);
		ClassMethodFunction* m = cl->getOverrodeMethod(method, ctx);
		if(m != nullptr)
		{
			method->setVirtualMethod(true, ctx);
			return true;
		}
		extClazz = cl->getExtendsClasses(ctx);
	}
	return false;
}
void AlinousClass::createVirtualTable(SrcAnalyseContext* context, ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	VirtualTable* vt = (new(ctx) VirtualTable(ctx));
	method->setVtable(vt, ctx);
	vt->addVirtualFunction(this, method, ctx);
	ClassMethodFunction* currentMethod = method;
	Iterator<AlinousClass>* it = this->delivedClasses->iterator(ctx);
	while(it->hasNext(ctx))
	{
		AlinousClass* dclazz = it->next(ctx);
		ClassMethodFunction* m = dclazz->getOverrodeMethod(method, ctx);
		if(m != nullptr)
		{
			currentMethod = m;
		}
		vt->addVirtualFunction(dclazz, currentMethod, ctx);
	}
}
void AlinousClass::__cleanUp(ThreadContext* ctx){
}
}}}

