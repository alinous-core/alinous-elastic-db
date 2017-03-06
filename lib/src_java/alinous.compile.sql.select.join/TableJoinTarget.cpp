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
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
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
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.lock/LockObject.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze.scan/VoidScanner.h"
#include "alinous.compile.sql.select.join.scan/JoinedCollectionScanner.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"
#include "alinous.compile.sql.select.join.scan/CrossJoinScanner.h"
#include "alinous.compile.sql.select.join.scan/ReverseIndexScanner.h"
#include "alinous.compile.sql.select.join.scan/RightindexJoinScanner.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.select.join/AbstractSQLJoin.h"
#include "alinous.compile.sql.select.join/InnerJoin.h"
#include "alinous.compile.sql.select.join/CrossJoin.h"
#include "alinous.compile.sql.select.join/AbstractJoinTarget.h"
#include "alinous.compile.sql.select.join/DomVariableJoinTarget.h"
#include "alinous.compile.sql.select.join/JoinSubQueryTarget.h"
#include "alinous.compile.sql.select.join/LeftJoin.h"
#include "alinous.compile.sql.select.join/NaturalJoin.h"
#include "alinous.compile.sql.select.join/RightJoin.h"
#include "alinous.compile.sql.analyze/ScanSingleStrategy.h"
#include "alinous.compile.sql.select.join/TableJoinTarget.h"
#include "alinous.compile.sql.select.join/WrappedJoinTarget.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql.select.join/TableList.h"

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool TableJoinTarget::__init_done = __init_static_variables();
bool TableJoinTarget::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableJoinTarget", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableJoinTarget::TableJoinTarget(ThreadContext* ctx) throw()  : IObject(ctx), AbstractJoinTarget(ctx), name(nullptr), asName(nullptr), scanMeta(nullptr), tableId(nullptr), strategy(nullptr)
{
}
void TableJoinTarget::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TableJoinTarget::~TableJoinTarget() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableJoinTarget::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableJoinTarget", L"~TableJoinTarget");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	__e_obj1.add(this->scanMeta, this);
	scanMeta = nullptr;
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->strategy, this);
	strategy = nullptr;
	if(!prepare){
		return;
	}
	AbstractJoinTarget::__releaseRegerences(true, ctx);
}
bool TableJoinTarget::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool TableJoinTarget::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
AlinousName* TableJoinTarget::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void TableJoinTarget::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
String* TableJoinTarget::getAsName(ThreadContext* ctx) throw() 
{
	return asName;
}
void TableJoinTarget::setAsName(String* asName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), asName, String);
}
bool TableJoinTarget::analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	ArrayList<String>* segments = this->name->getSegments(ctx);
	int size = segments->size(ctx);
	String* schema = nullptr;
	String* table = nullptr;
	switch(size) {
	case 1:
		schema = ConstStr::getCNST_STR_955();
		table = segments->get(0, ctx);
		break ;
	case 2:
		schema = segments->get(0, ctx);
		table = segments->get(1, ctx);
		break ;
	default:
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1089()->clone(ctx)->append(this->name->toString(ctx), ctx), ctx));
		break;
	}
	AlinousDatabase* db = context->getDatabase(ctx);
	IDatabaseTable* tableStore = db->getTable(schema, table, ctx);
	if(tableStore == nullptr)
	{
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1089()->clone(ctx)->append(this->name->toString(ctx), ctx), ctx));
	}
	__GC_MV(this, &(this->scanMeta), (new(ctx) ScanTableMetadata(tableStore->getMetadata(ctx), this->asName, ctx)), ScanTableMetadata);
	__GC_MV(this, &(this->tableId), (new(ctx) ScanTableIdentifier((new(ctx) TableAndSchema(schema, table, ctx)), this->asName, this->scanMeta->getColumns(ctx)->size(ctx), ctx)), ScanTableIdentifier);
	context->addTable(scanMeta, this->asName, ctx);
	return true;
}
void TableJoinTarget::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
}
bool TableJoinTarget::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return this->scanMeta->hasTable(table, ctx);
}
void TableJoinTarget::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	__GC_MV(this, &(this->strategy), (new(ctx) ScanSingleStrategy(this->scanMeta, this->tableId, context->getDatabase(ctx), ctx)), ScanSingleStrategy);
	this->strategy->analyzeFilterCondition(where, ctx);
	this->strategy->analyzeIndex(where, this->scanMeta, debug, ctx);
	this->strategy->optimize(ctx);
}
ScanTableMetadata* TableJoinTarget::getScanTableMetadata(ThreadContext* ctx) throw() 
{
	return this->scanMeta;
}
bool TableJoinTarget::isOptimizerCacheable(ThreadContext* ctx) throw() 
{
	return true;
}
ITableTargetScanner* TableJoinTarget::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	ITableTargetScanner* scanner = this->strategy->getScanner(machine, trx, joinRequest, debug, ctx);
	return scanner;
}
SQLJoinCondition* TableJoinTarget::getCondition(ThreadContext* ctx)
{
	return nullptr;
}
IStatement::StatementType TableJoinTarget::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void TableJoinTarget::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void TableJoinTarget::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
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
		__GC_MV(this, &(this->asName), buff->getString(ctx), String);
	}
}
void TableJoinTarget::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__TableJoinTarget, ctx);
	bool isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->name->writeData(buff, ctx);
	}
	isnull = (this->asName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->asName, ctx);
	}
}
void TableJoinTarget::__cleanUp(ThreadContext* ctx){
}
}}}}}

