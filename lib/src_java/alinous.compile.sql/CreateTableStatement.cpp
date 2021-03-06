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
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
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
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
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
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
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
#include "alinous.compile.sql/CreateTableStatement.h"

namespace alinous {namespace compile {namespace sql {





bool CreateTableStatement::__init_done = __init_static_variables();
bool CreateTableStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CreateTableStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CreateTableStatement::CreateTableStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLStatement(ctx), table(nullptr), columns(GCUtils<ArrayList<DdlColumnDescriptor> >::ins(this, (new(ctx) ArrayList<DdlColumnDescriptor>(ctx)), ctx, __FILEW__, __LINE__, L"")), uniques(GCUtils<ArrayList<Unique> >::ins(this, (new(ctx) ArrayList<Unique>(ctx)), ctx, __FILEW__, __LINE__, L"")), checks(GCUtils<ArrayList<CheckDefinition> >::ins(this, (new(ctx) ArrayList<CheckDefinition>(ctx)), ctx, __FILEW__, __LINE__, L"")), primaryKeys(nullptr), region(nullptr), partitionKeys(GCUtils<List<ShardKeys> >::ins(this, (new(ctx) ArrayList<ShardKeys>(ctx)), ctx, __FILEW__, __LINE__, L"")), metadata(nullptr)
{
}
void CreateTableStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CreateTableStatement::~CreateTableStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CreateTableStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CreateTableStatement", L"~CreateTableStatement");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->uniques, this);
	uniques = nullptr;
	__e_obj1.add(this->checks, this);
	checks = nullptr;
	__e_obj1.add(this->primaryKeys, this);
	primaryKeys = nullptr;
	__e_obj1.add(this->region, this);
	region = nullptr;
	__e_obj1.add(this->partitionKeys, this);
	partitionKeys = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLStatement::__releaseRegerences(true, ctx);
}
TableSchema* CreateTableStatement::createMetadata(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	TableJoinTarget* tbl = static_cast<TableJoinTarget*>(this->table);
	ArrayList<String>* segments = tbl->getName(ctx)->getSegments(ctx);
	String* schemeName = nullptr;
	String* tblName = nullptr;
	if(segments->size(ctx) == 1)
	{
		schemeName = ConstStr::getCNST_STR_1086();
		tblName = segments->get(0, ctx);
	}
		else 
	{
		if(segments->size(ctx) == 2)
		{
			schemeName = segments->get(0, ctx);
			tblName = segments->get(1, ctx);
		}
	}
	TableSchema* schema = (new(ctx) TableSchema(schemeName, nullptr, ctx));
	TableMetadata* tblMetadata = (new(ctx) TableMetadata(tblName, ctx));
	schema->addTableMetadata(tblMetadata, ctx);
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DdlColumnDescriptor* colDesc = this->columns->get(i, ctx);
		TableColumnMetadata* colMeta = colDesc->toMetadata(machine, debug, ctx);
		tblMetadata->addColumn(colMeta, ctx);
	}
	ArrayList<String>* prims = this->primaryKeys->getColumns(ctx);
	maxLoop = prims->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* prim = prims->get(i, ctx);
		tblMetadata->addPrimaryKey(prim, ctx);
	}
	tblMetadata->setChecks(this->checks, ctx);
	schema->setRegionName(this->region, ctx);
	if(this->partitionKeys->isEmpty(ctx))
	{
		ArrayList<String>* scolumns = this->primaryKeys->getColumns(ctx);
		ShardKeys* mainKey = (new(ctx) ShardKeys(ctx));
		maxLoop = scolumns->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			String* key = scolumns->get(i, ctx);
			mainKey->addKey(key, ctx);
		}
		this->partitionKeys->add(mainKey, ctx);
	}
	TablePartitionKeyCollection* partitionKeys = (new(ctx) TablePartitionKeyCollection(ctx));
	TablePartitionRangeCollection* partitionValueRanges = (new(ctx) TablePartitionRangeCollection(ctx));
	maxLoop = this->partitionKeys->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ShardKeys* skey = this->partitionKeys->get(i, ctx);
		ArrayList<String>* cols = skey->getColumns(ctx);
		TablePartitionKey* key = toPartitionKeys(tblMetadata, cols, ctx);
		partitionKeys->addPartitionKey(key, ctx);
		TablePartitionRange* range = makeDefaultRange(tblMetadata, key, ctx);
		partitionValueRanges->addRange(range, ctx);
	}
	tblMetadata->setPartitionKeys(partitionKeys, ctx);
	tblMetadata->setPartitionValueRanges(partitionValueRanges, ctx);
	return schema;
}
void CreateTableStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<TableJoinTarget*>(this->table) != 0)))
	{
		validator->addError(ConstStr::getCNST_STR_1109(), this, ctx);
	}
		else 
	{
		TableJoinTarget* tbl = static_cast<TableJoinTarget*>(this->table);
		ArrayList<String>* segments = tbl->getName(ctx)->getSegments(ctx);
		if(segments->size(ctx) > 2)
		{
			validator->addError(ConstStr::getCNST_STR_1109(), this, ctx);
		}
	}
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DdlColumnDescriptor* colDesc = this->columns->get(i, ctx);
		colDesc->validate(validator, ctx);
	}
	if(this->primaryKeys == nullptr)
	{
		validator->addError(ConstStr::getCNST_STR_1110(), this, ctx);
	}
}
TableMetadata* CreateTableStatement::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
bool CreateTableStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->table != nullptr && !this->table->visit(visitor, this, ctx))
	{
		return false;
	}
	int max = this->columns->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		if(!this->columns->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	max = this->uniques->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		if(!this->uniques->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	max = this->checks->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		if(!this->checks->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	if(this->primaryKeys != nullptr && !this->primaryKeys->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool CreateTableStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->table != nullptr)
	{
		this->table->analyse(context, leftValue, ctx);
	}
	int max = this->columns->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		this->columns->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	max = this->uniques->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		this->uniques->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	max = this->checks->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		this->checks->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	if(this->primaryKeys != nullptr)
	{
		this->primaryKeys->analyse(context, leftValue, ctx);
	}
	return true;
}
void CreateTableStatement::addColumn(DdlColumnDescriptor* col, ThreadContext* ctx) throw() 
{
	this->columns->add(col, ctx);
}
void CreateTableStatement::addUnique(Unique* unique, ThreadContext* ctx) throw() 
{
	this->uniques->add(unique, ctx);
}
void CreateTableStatement::addCheckDef(CheckDefinition* def, ThreadContext* ctx) throw() 
{
	this->checks->add(def, ctx);
}
IJoinTarget* CreateTableStatement::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void CreateTableStatement::setTable(IJoinTarget* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, IJoinTarget);
}
PrimaryKeys* CreateTableStatement::getPrimaryKeys(ThreadContext* ctx) throw() 
{
	return primaryKeys;
}
void CreateTableStatement::setPrimaryKeys(PrimaryKeys* primaryKeys, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->primaryKeys), primaryKeys, PrimaryKeys);
}
ArrayList<DdlColumnDescriptor>* CreateTableStatement::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
ArrayList<Unique>* CreateTableStatement::getUniques(ThreadContext* ctx) throw() 
{
	return uniques;
}
ArrayList<CheckDefinition>* CreateTableStatement::getChecks(ThreadContext* ctx) throw() 
{
	return checks;
}
String* CreateTableStatement::getRegion(ThreadContext* ctx) throw() 
{
	return region;
}
void CreateTableStatement::setRegion(String* region, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->region), region, String);
}
IStatement::StatementType CreateTableStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::CREATE_TABLE;
}
void CreateTableStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) throw() 
{
}
void CreateTableStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IJoinTarget*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
		}
		__GC_MV(this, &(this->table), static_cast<IJoinTarget*>(el), IJoinTarget);
	}
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<DdlColumnDescriptor*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1112(), ctx));
		}
		this->columns->add(static_cast<DdlColumnDescriptor*>(el), ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<Unique*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1113(), ctx));
		}
		this->uniques->add(static_cast<Unique*>(el), ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<CheckDefinition*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
		}
		this->checks->add(static_cast<CheckDefinition*>(el), ctx);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<PrimaryKeys*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1115(), ctx));
		}
		__GC_MV(this, &(this->primaryKeys), static_cast<PrimaryKeys*>(el), PrimaryKeys);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->region), buff->getString(ctx), String);
	}
	maxLoop = this->partitionKeys->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ShardKeys*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1116(), ctx));
		}
		ShardKeys* keys = static_cast<ShardKeys*>(el);
		this->partitionKeys->add(keys, ctx);
	}
}
void CreateTableStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__CreateTableStatement, ctx);
	bool isnull = (this->table == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->table->writeData(buff, ctx);
	}
	int maxLoop = this->columns->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		DdlColumnDescriptor* exp = this->columns->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	maxLoop = this->uniques->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		Unique* exp = this->uniques->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	maxLoop = this->checks->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		CheckDefinition* exp = this->checks->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	isnull = (this->primaryKeys == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->primaryKeys->writeData(buff, ctx);
	}
	isnull = (this->region == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->region, ctx);
	}
	maxLoop = this->partitionKeys->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		ShardKeys* keys = this->partitionKeys->get(i, ctx);
		keys->writeData(buff, ctx);
	}
}
void CreateTableStatement::addPartitionKey(ShardKeys* key, ThreadContext* ctx) throw() 
{
	this->partitionKeys->add(key, ctx);
}
TablePartitionKey* CreateTableStatement::toPartitionKeys(TableMetadata* meta, ArrayList<String>* cols, ThreadContext* ctx)
{
	TablePartitionKey* key = (new(ctx) TablePartitionKey(ctx));
	int maxLoop = cols->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* col = cols->get(i, ctx);
		TableColumnMetadata* colmeta = meta->getColumnByName(col, ctx);
		if(colmeta == nullptr)
		{
			throw (new(ctx) DatabaseException(col->clone(ctx)->append(ConstStr::getCNST_STR_1108(), ctx), ctx));
		}
		key->addKeyColumn(colmeta, ctx);
	}
	return key;
}
TablePartitionRange* CreateTableStatement::makeDefaultRange(TableMetadata* meta, TablePartitionKey* key, ThreadContext* ctx) throw() 
{
	TablePartitionRange* range = (new(ctx) TablePartitionRange(key, ctx));
	ArrayList<TableColumnMetadata>* keys = key->getKeys(ctx);
	int maxLoop = keys->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = keys->get(i, ctx);
		int coltype = col->getType(ctx);
		int type = ddlColumnType2VariantType(coltype, ctx);
		VariantValue* max = VariantValue::createMaxValue(type, ctx);
		VariantValue* min = VariantValue::createMinValue(type, ctx);
		range->addMaxKeyValue(max, ctx);
		range->addMinKeyValue(min, ctx);
	}
	return range;
}
int CreateTableStatement::ddlColumnType2VariantType(int coltype, ThreadContext* ctx) throw() 
{
	int type = 0;
	switch(coltype) {
	case ColumnTypeDescriptor::INT:
		type = VariantValue::TYPE_INT;
		break ;
	case ColumnTypeDescriptor::DOUBLE:
		type = VariantValue::TYPE_DOUBLE;
		break ;
	case ColumnTypeDescriptor::DATE:
	case ColumnTypeDescriptor::TIMESTAMP:
		type = VariantValue::TYPE_TIMESTAMP;
		break ;
	case ColumnTypeDescriptor::TIME:
		type = VariantValue::TYPE_TIME;
		break ;
	case ColumnTypeDescriptor::BIG_DECIMAL:
		type = VariantValue::TYPE_BIG_DECIMAL;
		break ;
	case ColumnTypeDescriptor::VARCHAR:
	case ColumnTypeDescriptor::TEXT:
	case ColumnTypeDescriptor::BLOB:
	default:
		type = VariantValue::TYPE_STRING;
		break ;
	}
	return type;
}
void CreateTableStatement::__cleanUp(ThreadContext* ctx){
}
}}}

