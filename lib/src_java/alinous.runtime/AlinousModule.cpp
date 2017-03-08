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
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.declare/IDeclare.h"
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
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.stmt/StatementBlock.h"
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
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
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
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
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
#include "alinous.compile.analyse/AlinousType.h"
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
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.server.debug/DebugConfigLoader.h"
#include "alinous.system.utils/FileUtils.h"
#include "alinous.runtime/AlinousModule.h"

namespace alinous {namespace runtime {





bool AlinousModule::__init_done = __init_static_variables();
bool AlinousModule::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModule", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModule::AlinousModule(String* path, File* file, AlinousSrc* moduleSource, AlinousCore* core, ThreadContext* ctx) : IObject(ctx), IAlinousElement(ctx), packageName(nullptr), path(nullptr), debugPath(nullptr), file(nullptr), compiledTime(0), moduleSource(nullptr), setupper(nullptr), core(nullptr), parent(nullptr), includedModules(GCUtils<ArrayList<AlinousModule> >::ins(this, (new(ctx) ArrayList<AlinousModule>(ctx)), ctx, __FILEW__, __LINE__, L"")), functionMap(GCUtils<HashMap<String,AlinousFunction> >::ins(this, (new(ctx) HashMap<String,AlinousFunction>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->debugPath), file->getAbsolutePath(ctx), String);
	__GC_MV(this, &(this->debugPath), FileUtils::formatAfterAbsolutePath(this->debugPath, ctx), String);
	DebugConfigLoader* loader = (new(ctx) DebugConfigLoader(core->getConfig(ctx), ctx));
	__GC_MV(this, &(this->debugPath), loader->getDebugFilePath(this->debugPath, ctx), String);
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->file), file, File);
	this->compiledTime = System::currentTimeMillis(ctx);
	__GC_MV(this, &(this->moduleSource), moduleSource, AlinousSrc);
	__GC_MV(this, &(this->setupper), (new(ctx) AlinousModule::SetUpper(this->path, this->debugPath, ctx)), AlinousModule::SetUpper);
	__GC_MV(this, &(this->core), core, AlinousCore);
}
void AlinousModule::__construct_impl(String* path, File* file, AlinousSrc* moduleSource, AlinousCore* core, ThreadContext* ctx)
{
	__GC_MV(this, &(this->debugPath), file->getAbsolutePath(ctx), String);
	__GC_MV(this, &(this->debugPath), FileUtils::formatAfterAbsolutePath(this->debugPath, ctx), String);
	DebugConfigLoader* loader = (new(ctx) DebugConfigLoader(core->getConfig(ctx), ctx));
	__GC_MV(this, &(this->debugPath), loader->getDebugFilePath(this->debugPath, ctx), String);
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->file), file, File);
	this->compiledTime = System::currentTimeMillis(ctx);
	__GC_MV(this, &(this->moduleSource), moduleSource, AlinousSrc);
	__GC_MV(this, &(this->setupper), (new(ctx) AlinousModule::SetUpper(this->path, this->debugPath, ctx)), AlinousModule::SetUpper);
	__GC_MV(this, &(this->core), core, AlinousCore);
}
 AlinousModule::AlinousModule(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), packageName(nullptr), path(nullptr), debugPath(nullptr), file(nullptr), compiledTime(0), moduleSource(nullptr), setupper(nullptr), core(nullptr), parent(nullptr), includedModules(GCUtils<ArrayList<AlinousModule> >::ins(this, (new(ctx) ArrayList<AlinousModule>(ctx)), ctx, __FILEW__, __LINE__, L"")), functionMap(GCUtils<HashMap<String,AlinousFunction> >::ins(this, (new(ctx) HashMap<String,AlinousFunction>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AlinousModule::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousModule::~AlinousModule() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModule::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousModule", L"~AlinousModule");
	__e_obj1.add(this->packageName, this);
	packageName = nullptr;
	__e_obj1.add(this->path, this);
	path = nullptr;
	__e_obj1.add(this->debugPath, this);
	debugPath = nullptr;
	__e_obj1.add(this->file, this);
	file = nullptr;
	__e_obj1.add(this->moduleSource, this);
	moduleSource = nullptr;
	__e_obj1.add(this->setupper, this);
	setupper = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->parent, this);
	parent = nullptr;
	__e_obj1.add(this->includedModules, this);
	includedModules = nullptr;
	__e_obj1.add(this->functionMap, this);
	functionMap = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
IAlinousVariable* AlinousModule::execute(ScriptMachine* machine, bool degug, ThreadContext* ctx)
{
	return executeAsScript(machine, degug, ctx);
}
IAlinousVariable* AlinousModule::execute(bool degug, ThreadContext* ctx)
{
	ScriptMachine* machine = (new(ctx) ScriptMachine(this, this->core, ctx));
	return executeAsScript(machine, degug, ctx);
}
AlinousType* AlinousModule::getFunctionReturnType(String* prefix, String* name, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(prefix != nullptr)
	{
		buff->append(prefix, ctx)->append(ConstStr::getCNST_STR_950(), ctx);
	}
	buff->append(name, ctx);
	AlinousFunction* func = this->functionMap->get(buff->toString(ctx), ctx);
	if(func != nullptr)
	{
		AlinousType* type = func->getAnalysedReturnType(ctx);
		return type;
	}
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		AlinousType* type = mod->getFunctionReturnType(prefix, name, ctx);
		if(type != nullptr)
		{
			return type;
		}
	}
	return nullptr;
}
bool AlinousModule::isfunctionPrefix(String* name, ThreadContext* ctx) throw() 
{
	String* prefix = name->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx);
	Iterator<String>* it = functionMap->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* funcName = it->next(ctx);
		if(funcName->startsWith(prefix, ctx))
		{
			return true;
		}
	}
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		if(mod->isfunctionPrefix(name, ctx))
		{
			return true;
		}
	}
	return false;
}
AlinousFunction* AlinousModule::findFunction(String* name, ThreadContext* ctx) throw() 
{
	AlinousFunction* func = this->functionMap->get(name, ctx);
	if(func != nullptr)
	{
		return func;
	}
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		func = mod->findFunction(name, ctx);
	}
	return nullptr;
}
void AlinousModule::init(AlinousModuleRepository* moduleRepository, ArrayList<String>* once, bool isInclude, bool debug, ThreadContext* ctx)
{
	ArrayList<IncludePreprocessor>* inclist = moduleSource->getIncludes(ctx);
	int maxLoop = inclist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IncludePreprocessor* inc = inclist->get(i, ctx);
		if(inc->getPath(ctx) == nullptr)
		{
			throw (new(ctx) AlinousNullPointerException(ctx));
		}
		AlinousModule* modinc = static_cast<AlinousModule*>(moduleRepository->getModule(inc->getPath(ctx), once, true, debug, ctx));
		if(modinc == nullptr || alreadyIncluded(static_cast<AlinousModule*>(modinc), ctx))
		{
			continue;
		}
		inc->setModule(modinc, ctx);
		(static_cast<AlinousModule*>(modinc))->setParent(this, ctx);
		this->includedModules->add(modinc, ctx);
	}
	ArrayList<AlinousFunction>* funclist = this->moduleSource->getFunctionDeclares(ctx);
	maxLoop = funclist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousFunction* func = funclist->get(i, ctx);
		this->functionMap->put(func->getFunctionName(ctx), func, ctx);
	}
	this->moduleSource->setFilePath(this->setupper->getPath(ctx), ctx);
	this->moduleSource->setDebugFilePath(this->setupper->getDebugPath(ctx), ctx);
	this->moduleSource->visit(this->setupper, nullptr, ctx);
	__GC_MV(this, &(this->packageName), (new(ctx) AlinousModulePackage(this->path, ctx)), AlinousModulePackage);
	if(isInclude)
	{
		return;
	}
	SrcAnalyseContext* context = (new(ctx) SrcAnalyseContext(this, this->core->getFunctionManager(ctx), this->core->sqlFunctionManager, ctx));
	analyseClassDeclare(context, ctx);
	context->newStack(ctx);
	analyzeClassDependency(context, ctx);
	analyzeVirtualMethods(context, ctx);
	this->moduleSource->analyse(context, false, ctx);
	context->endStack(ctx);
	ScriptRunner* runner = this->core->getRunner(ctx);
	ScriptMachine* machine = (new(ctx) ScriptMachine(this, this->core, ctx));
	AlinousModule::ClassCollector* visitor = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(visitor, nullptr, ctx);
	Iterator<AlinousClass>* it = visitor->list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		AlinousClass* clazz = it->next(ctx);
		runner->initStatic(clazz, machine, debug, ctx);
	}
	machine->dispose(ctx);
}
AlinousModulePackage* AlinousModule::getPackageName(ThreadContext* ctx) throw() 
{
	return this->packageName;
}
bool AlinousModule::isDirty(ThreadContext* ctx) throw() 
{
	return this->file->lastModified(ctx) > this->compiledTime;
}
File* AlinousModule::getFile(ThreadContext* ctx) throw() 
{
	return file;
}
String* AlinousModule::getPath(ThreadContext* ctx) throw() 
{
	return path;
}
AlinousSrc* AlinousModule::getModuleSource(ThreadContext* ctx) throw() 
{
	return moduleSource;
}
AlinousModule* AlinousModule::getParent(ThreadContext* ctx) throw() 
{
	return parent;
}
void AlinousModule::setParent(AlinousModule* parent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->parent), parent, AlinousModule);
}
void AlinousModule::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		String* str = buff->getString(ctx);
		__GC_MV(this, &(this->packageName), (new(ctx) AlinousModulePackage(str, ctx)), AlinousModulePackage);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousSrc*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1104(), ctx));
		}
		__GC_MV(this, &(this->moduleSource), static_cast<AlinousSrc*>(el), AlinousSrc);
	}
}
void AlinousModule::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__AlinousModule, ctx);
	bool isnull = (this->packageName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		String* str = this->packageName->toString(ctx);
		buff->putString(str, ctx);
	}
	isnull = (this->moduleSource == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->moduleSource->writeData(buff, ctx);
	}
}
bool AlinousModule::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->moduleSource != nullptr)
	{
		this->moduleSource->analyse(context, false, ctx);
	}
	return true;
}
IAlinousVariable* AlinousModule::executeAsScript(ScriptMachine* machine, bool degug, ThreadContext* ctx)
{
	ScriptRunner* runner = this->core->getRunner(ctx);
	runner->run(this, machine, degug, ctx);
	return machine->getReturnedValue(ctx);
}
void AlinousModule::analyzeVirtualMethods(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->analyzeVirtualMethods(context, ctx);
	}
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->analyseVirtualMethods(context, ctx);
	}
}
void AlinousModule::analyzeClassDependency(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->analyzeClassDependency(context, ctx);
	}
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->analyseDependency(context, ctx);
	}
}
void AlinousModule::analyseClassDeclare(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->setPackageName(this->packageName, ctx);
		context->addClassDeclare(clazz, ctx);
	}
	ArrayList<String>* once = (new(ctx) ArrayList<String>(ctx));
	once->add(this->path, ctx);
	maxLoop = includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->exportClasses(context, once, ctx);
	}
}
void AlinousModule::exportClasses(SrcAnalyseContext* context, ArrayList<String>* once, ThreadContext* ctx) throw() 
{
	if(once->contains(path, ctx))
	{
		return;
	}
	once->add(this->path, ctx);
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->setPackageName(this->packageName, ctx);
		context->addClassDeclare(clazz, ctx);
	}
	maxLoop = includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->exportClasses(context, once, ctx);
	}
}
bool AlinousModule::alreadyIncluded(AlinousModule* modinc, ThreadContext* ctx) throw() 
{
	AlinousModule* parendMod = this->parent;
	while(parendMod != nullptr)
	{
		if(parendMod == modinc)
		{
			return true;
		}
		parendMod = parendMod->getParent(ctx);
	}
	return false;
}
void AlinousModule::__cleanUp(ThreadContext* ctx){
}
}}

namespace alinous {namespace runtime {





bool AlinousModule::SetUpper::__init_done = __init_static_variables();
bool AlinousModule::SetUpper::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModule::SetUpper", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModule::SetUpper::SetUpper(String* path, String* debugPath, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElementVisitor(ctx), path(nullptr), debugPath(nullptr)
{
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->debugPath), debugPath, String);
}
void AlinousModule::SetUpper::__construct_impl(String* path, String* debugPath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->debugPath), debugPath, String);
}
 AlinousModule::SetUpper::~SetUpper() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModule::SetUpper::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SetUpper", L"~SetUpper");
	__e_obj1.add(this->path, this);
	path = nullptr;
	__e_obj1.add(this->debugPath, this);
	debugPath = nullptr;
	if(!prepare){
		return;
	}
}
bool AlinousModule::SetUpper::visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	element->setParent(parent, ctx);
	element->setFilePath(this->path, ctx);
	element->setDebugFilePath(this->debugPath, ctx);
	return true;
}
String* AlinousModule::SetUpper::getPath(ThreadContext* ctx) throw() 
{
	return path;
}
String* AlinousModule::SetUpper::getDebugPath(ThreadContext* ctx) throw() 
{
	return debugPath;
}
void AlinousModule::SetUpper::__cleanUp(ThreadContext* ctx){
}
}}

namespace alinous {namespace runtime {





bool AlinousModule::ClassCollector::__init_done = __init_static_variables();
bool AlinousModule::ClassCollector::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModule::ClassCollector", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModule::ClassCollector::ClassCollector(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElementVisitor(ctx), list(GCUtils<ArrayList<AlinousClass> >::ins(this, (new(ctx) ArrayList<AlinousClass>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AlinousModule::ClassCollector::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousModule::ClassCollector::~ClassCollector() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModule::ClassCollector::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassCollector", L"~ClassCollector");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
bool AlinousModule::ClassCollector::visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<AlinousClass*>(element) != 0))
	{
		this->list->add(static_cast<AlinousClass*>(element), ctx);
	}
	return true;
}
ArrayList<AlinousClass>* AlinousModule::ClassCollector::getClasses(ThreadContext* ctx) throw() 
{
	return this->list;
}
void AlinousModule::ClassCollector::__cleanUp(ThreadContext* ctx){
}
}}

