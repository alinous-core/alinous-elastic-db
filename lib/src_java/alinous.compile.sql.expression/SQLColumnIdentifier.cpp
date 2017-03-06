#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.lock/LockObject.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql.expression/SQLLiteral.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.expression/SQLSubExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLCollectionExpression.h"
#include "alinous.compile.sql.expression/SQLMultiplicativeExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.sql.expression/SQLSubqueryExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/TrxLockContext.h"
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
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.sql.expression/SQLAdditiveExpression.h"

namespace alinous {namespace compile {namespace sql {namespace expression {





bool SQLColumnIdentifier::__init_done = __init_static_variables();
bool SQLColumnIdentifier::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLColumnIdentifier", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLColumnIdentifier::SQLColumnIdentifier(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLExpression(ctx), distinct(0), id(nullptr), asName(nullptr), resolvedName(nullptr), analysedColumn(nullptr), columnOrder(-1)
{
}
void SQLColumnIdentifier::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLColumnIdentifier::SQLColumnIdentifier(AlinousName* name, ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLExpression(ctx), distinct(0), id(nullptr), asName(nullptr), resolvedName(nullptr), analysedColumn(nullptr), columnOrder(-1)
{
	__GC_MV(this, &(this->id), name, AlinousName);
}
void SQLColumnIdentifier::__construct_impl(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), name, AlinousName);
}
 SQLColumnIdentifier::~SQLColumnIdentifier() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLColumnIdentifier::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLColumnIdentifier", L"~SQLColumnIdentifier");
	__e_obj1.add(this->id, this);
	id = nullptr;
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	__e_obj1.add(this->resolvedName, this);
	resolvedName = nullptr;
	__e_obj1.add(this->analysedColumn, this);
	analysedColumn = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLExpression::__releaseRegerences(true, ctx);
}
bool SQLColumnIdentifier::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->id != nullptr && !this->id->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLColumnIdentifier::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLColumnIdentifier::isDistinct(ThreadContext* ctx) throw() 
{
	return distinct;
}
void SQLColumnIdentifier::setDistinct(bool distinct, ThreadContext* ctx) throw() 
{
	this->distinct = distinct;
}
AlinousName* SQLColumnIdentifier::getId(ThreadContext* ctx) throw() 
{
	return id;
}
void SQLColumnIdentifier::setId(AlinousName* id, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), id, AlinousName);
}
String* SQLColumnIdentifier::getAsName(ThreadContext* ctx) throw() 
{
	return asName;
}
void SQLColumnIdentifier::setAsName(String* asName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), asName, String);
}
IAlinousVariable* SQLColumnIdentifier::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->resolvedName == nullptr)
	{
		__GC_MV(this, &(this->resolvedName), (new(ctx) VariantValue(this->id->toString(ctx), ctx)), VariantValue);
	}
	return this->resolvedName;
}
bool SQLColumnIdentifier::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
ExpressionSourceId* SQLColumnIdentifier::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(this->id->toString(ctx), this, nullptr, ctx));
}
bool SQLColumnIdentifier::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	ArrayList<String>* segments = this->id->getSegments(ctx);
	__GC_MV(this, &(this->analysedColumn), nullptr, ScanTableColumnIdentifier);
	if(analyzeAsName(context, segments, ctx))
	{
		return true;
	}
	int size = this->id->getSegments(ctx)->size(ctx);
	String* schema = nullptr;
	String* table = nullptr;
	String* column = nullptr;
	switch(size) {
	case 1:
		schema = ConstStr::getCNST_STR_955();
		column = segments->get(0, ctx);
		table = SQLAnalyseContext::findTable(context, schema, column, ctx);
		if(table == nullptr)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1044()->clone(ctx)->append(this->id->toString(ctx), ctx), ctx));
		}
		break ;
	case 2:
		schema = ConstStr::getCNST_STR_955();
		table = segments->get(0, ctx);
		column = segments->get(1, ctx);
		break ;
	case 3:
		schema = segments->get(0, ctx);
		table = segments->get(1, ctx);
		column = segments->get(2, ctx);
		break ;
	default:
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1044()->clone(ctx)->append(this->id->toString(ctx), ctx), ctx));
		break;
	}
	AlinousDatabase* database = context->getDatabase(ctx);
	IDatabaseTable* dataStore = database->getTable(schema, table, ctx);
	if(dataStore == nullptr)
	{
		throw (new(ctx) DatabaseException(schema->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1045(), ctx), ctx));
	}
	TableAndSchema* tableSc = (new(ctx) TableAndSchema(schema, table, ctx));
	ScanTableIdentifier* tableId = (new(ctx) ScanTableIdentifier(tableSc, this->asName, dataStore->getColumnCount(ctx), ctx));
	__GC_MV(this, &(this->analysedColumn), (new(ctx) ScanTableColumnIdentifier(tableId, column, ctx)), ScanTableColumnIdentifier);
	analyseColumnOrder(tableSc, context, ctx);
	return true;
}
bool SQLColumnIdentifier::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return this->analysedColumn->getTable(ctx)->equals(table, ctx);
}
ArrayList<ScanTableColumnIdentifier>* SQLColumnIdentifier::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	list->add(this->analysedColumn, ctx);
	return list;
}
bool SQLColumnIdentifier::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLColumnIdentifier::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLColumnIdentifier::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLColumnIdentifier::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return true;
}
ScanTableColumnIdentifier* SQLColumnIdentifier::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return this->analysedColumn;
}
VariantValue* SQLColumnIdentifier::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->columnOrder >= 0)
	{
		ScanTableIdentifier* tableId = analysedColumn->getTable(ctx);
		return record->getValueOfTable(tableId, this->columnOrder, ctx);
	}
		else 
	{
	}
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
bool SQLColumnIdentifier::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLColumnIdentifier::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
bool SQLColumnIdentifier::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
int SQLColumnIdentifier::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLColumnIdentifier;
}
void SQLColumnIdentifier::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->distinct = buff->getBoolean(ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->id), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), buff->getString(ctx), String);
	}
}
void SQLColumnIdentifier::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLColumnIdentifier, ctx);
	buff->putBoolean(this->distinct, ctx);
	bool isnull = (this->id == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->id->writeData(buff, ctx);
	}
	isnull = (this->asName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->asName, ctx);
	}
}
int SQLColumnIdentifier::fileSize(ThreadContext* ctx) throw() 
{
	int total = 4;
	total += 1;
	bool isnull = (this->id == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->id->fileSize(ctx);
	}
	isnull = (this->asName == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->asName->length(ctx) * 2 + 4;
	}
	return total;
}
void SQLColumnIdentifier::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IExpressionFactory::__SQLColumnIdentifier, ctx);
	builder->putBoolean(this->distinct, ctx);
	bool isnull = (this->id == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->id->toFileEntry(builder, ctx);
	}
	isnull = (this->asName == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->asName, ctx);
	}
}
void SQLColumnIdentifier::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	this->distinct = fetcher->fetchBoolean(ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		AlinousName* exp = AlinousName::fromFileEntry(fetcher, ctx);
		if(exp != nullptr)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->id), exp, AlinousName);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), fetcher->fetchString(ctx), String);
	}
}
void SQLColumnIdentifier::analyseColumnOrder(TableAndSchema* tableSc, SQLAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = context->getTables(ctx)->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableMetadata* tableMetadata = context->getTables(ctx)->get(i, ctx);
		String* s = tableMetadata->getSchemaName(ctx);
		String* t = tableMetadata->getTableName(ctx);
		if(s->equals(tableSc->getSchema(ctx), ctx) && t->equals(tableSc->getTable(ctx), ctx))
		{
			this->columnOrder = tableMetadata->getColumnOrder(this->analysedColumn, ctx);
		}
	}
}
bool SQLColumnIdentifier::analyzeAsName(SQLAnalyseContext* context, ArrayList<String>* segments, ThreadContext* ctx) throw() 
{
	int size = segments->size(ctx);
	if(size != 2)
	{
		return false;
	}
	String* asname = segments->get(0, ctx);
	String* columnName = segments->get(1, ctx);
	ScanTableMetadata* meta = context->findTableByAsName(asname, ctx);
	if(meta == nullptr)
	{
		return false;
	}
	ScanTableIdentifier* tableId = (new(ctx) ScanTableIdentifier(nullptr, asname, meta->getColumns(ctx)->size(ctx), ctx));
	__GC_MV(this, &(this->analysedColumn), (new(ctx) ScanTableColumnIdentifier(tableId, columnName, ctx)), ScanTableColumnIdentifier);
	return true;
}
void SQLColumnIdentifier::__cleanUp(ThreadContext* ctx){
}
}}}}

