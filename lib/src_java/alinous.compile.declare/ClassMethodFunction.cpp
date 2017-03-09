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
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
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
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
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
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/VirtualTable.h"
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
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/CatchBlock.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/FinallyBlock.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/ThrowStatement.h"
#include "alinous.compile.stmt/TryBlock.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.declare/ClassMethodFunction.h"

namespace alinous {namespace compile {namespace declare {





bool ClassMethodFunction::__init_done = __init_static_variables();
bool ClassMethodFunction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClassMethodFunction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClassMethodFunction::ClassMethodFunction(ThreadContext* ctx) throw()  : IObject(ctx), AbstractClassMember(ctx), func(nullptr), constructorMethod(0), virtualMethod(0), vtable(nullptr), superConstructor(nullptr)
{
}
void ClassMethodFunction::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ClassMethodFunction::~ClassMethodFunction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClassMethodFunction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassMethodFunction", L"~ClassMethodFunction");
	__e_obj1.add(this->func, this);
	func = nullptr;
	__e_obj1.add(this->vtable, this);
	vtable = nullptr;
	__e_obj1.add(this->superConstructor, this);
	superConstructor = nullptr;
	if(!prepare){
		return;
	}
	AbstractClassMember::__releaseRegerences(true, ctx);
}
bool ClassMethodFunction::sameSig(ClassMethodFunction* other, ThreadContext* ctx) throw() 
{
	return this->func->sameSig(other->func, ctx);
}
bool ClassMethodFunction::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->modifier != nullptr && !this->modifier->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->func != nullptr && !this->func->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
int ClassMethodFunction::getMemberType(ThreadContext* ctx) throw() 
{
	if(isStatic(ctx))
	{
		return IClassMember::STATIC_CLASS_METHOD;
	}
	return IClassMember::CLASS_METHOD;
}
int ClassMethodFunction::getArgumentsSize(ThreadContext* ctx) throw() 
{
	FunctionArgumentsListDefine* argdef = this->func->getArguments(ctx);
	return argdef->getList(ctx)->size(ctx);
}
ArrayList<FunctionArgumentDefine>* ClassMethodFunction::getArgumentsDefine(ThreadContext* ctx) throw() 
{
	FunctionArgumentsListDefine* argdef = this->func->getArguments(ctx);
	return argdef->getList(ctx);
}
AlinousFunction* ClassMethodFunction::getFunc(ThreadContext* ctx) throw() 
{
	return func;
}
void ClassMethodFunction::setFunc(AlinousFunction* func, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->func), func, AlinousFunction);
}
bool ClassMethodFunction::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->constructorMethod)
	{
		bool result = analyseConstructorMethod(context, ctx);
		if(!result)
		{
			return false;
		}
	}
	this->func->analyse(context, false, ctx);
	return true;
}
ClassMethodFunction* ClassMethodFunction::getConstructorCall(ThreadContext* ctx) throw() 
{
	return this->superConstructor;
}
String* ClassMethodFunction::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->modifier->toString(ctx), ctx)->append(ConstStr::getCNST_STR_380(), ctx);
	if(this->func != nullptr)
	{
		buff->append(this->func->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
AlinousClass* ClassMethodFunction::getAlinousClass(ThreadContext* ctx) throw() 
{
	return static_cast<AlinousClass*>(this->parent);
}
bool ClassMethodFunction::isConstructorMethod(ThreadContext* ctx) throw() 
{
	return constructorMethod;
}
void ClassMethodFunction::setConstructorMethod(bool constructorMethod, ThreadContext* ctx) throw() 
{
	this->constructorMethod = constructorMethod;
}
ClassMethodFunction* ClassMethodFunction::getSuperConstructor(ThreadContext* ctx) throw() 
{
	return superConstructor;
}
bool ClassMethodFunction::isVirtualMethod(ThreadContext* ctx) throw() 
{
	return virtualMethod;
}
void ClassMethodFunction::setVirtualMethod(bool virtualMethod, ThreadContext* ctx) throw() 
{
	this->virtualMethod = virtualMethod;
}
ClassMethodFunction* ClassMethodFunction::resolveVirtual(AlinousClass* clazz, ThreadContext* ctx) throw() 
{
	if(!this->virtualMethod)
	{
		return this;
	}
	return this->vtable->getMethod(clazz, ctx);
}
VirtualTable* ClassMethodFunction::getVtable(ThreadContext* ctx) throw() 
{
	return vtable;
}
void ClassMethodFunction::setVtable(VirtualTable* vtable, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vtable), vtable, VirtualTable);
}
void ClassMethodFunction::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousFunction*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1094(), ctx));
		}
		__GC_MV(this, &(this->func), static_cast<AlinousFunction*>(el), AlinousFunction);
	}
	this->constructorMethod = buff->getBoolean(ctx);
	this->virtualMethod = buff->getBoolean(ctx);
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<VirtualTable*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1095(), ctx));
		}
		__GC_MV(this, &(this->vtable), static_cast<VirtualTable*>(el), VirtualTable);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ClassMethodFunction*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1088(), ctx));
		}
		__GC_MV(this, &(this->superConstructor), static_cast<ClassMethodFunction*>(el), ClassMethodFunction);
	}
}
void ClassMethodFunction::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__ClassMethodFunction, ctx);
	bool isnull = (this->func == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->func->writeData(buff, ctx);
	}
	buff->putBoolean(this->constructorMethod, ctx);
	buff->putBoolean(this->virtualMethod, ctx);
	isnull = (this->vtable == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vtable->writeData(buff, ctx);
	}
	isnull = (this->superConstructor == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->superConstructor->writeData(buff, ctx);
	}
}
bool ClassMethodFunction::analyseConstructorMethod(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->superConstructor), nullptr, ClassMethodFunction);
	FunctionCallExpression* exp = this->func->callSuperConstructor(ctx);
	if(exp != nullptr)
	{
		return true;
	}
	AlinousClass* clazz = getAlinousClass(ctx);
	while(clazz->getExtendsClasses(ctx) != nullptr)
	{
		AlinousClass* superClazz = clazz->getExtendsClasses(ctx)->getAnalysedClazz(ctx);
		FunctionArguments* blankArg = (new(ctx) FunctionArguments(ctx));
		__GC_MV(this, &(this->superConstructor), superClazz->getConstructorFunction(blankArg, ctx), ClassMethodFunction);
		if(this->superConstructor != nullptr)
		{
			return true;
		}
		clazz = superClazz;
	}
	return true;
}
void ClassMethodFunction::__cleanUp(ThreadContext* ctx){
}
}}}

