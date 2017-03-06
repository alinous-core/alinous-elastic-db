#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
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
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
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
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"

namespace alinous {namespace compile {namespace sql {





bool TableAndSchema::__init_done = __init_static_variables();
bool TableAndSchema::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableAndSchema", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableAndSchema::TableAndSchema(String* schema, String* table, ThreadContext* ctx) throw()  : IObject(ctx), table(nullptr), schema(nullptr), toStr(nullptr)
{
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->table), table, String);
}
void TableAndSchema::__construct_impl(String* schema, String* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->table), table, String);
}
 TableAndSchema::~TableAndSchema() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableAndSchema::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableAndSchema", L"~TableAndSchema");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->schema, this);
	schema = nullptr;
	__e_obj1.add(this->toStr, this);
	toStr = nullptr;
	if(!prepare){
		return;
	}
}
String* TableAndSchema::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void TableAndSchema::setTable(String* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, String);
}
String* TableAndSchema::getSchema(ThreadContext* ctx) throw() 
{
	return schema;
}
void TableAndSchema::setSchema(String* schema, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schema), schema, String);
}
TableAndSchema* TableAndSchema::copy(ThreadContext* ctx) throw() 
{
	TableAndSchema* newObj = (new(ctx) TableAndSchema(this->schema, this->table, ctx));
	return newObj;
}
int TableAndSchema::getArchiveSize(ThreadContext* ctx) throw() 
{
	int total = 4;
	if(this->table != nullptr)
	{
		total += this->table->length(ctx) * 2;
	}
	total += 4;
	if(this->schema != nullptr)
	{
		total += this->schema->length(ctx) * 2;
	}
	return total;
}
void TableAndSchema::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putString(this->table, ctx);
	builder->putString(this->schema, ctx);
}
bool TableAndSchema::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	TableAndSchema* other = dynamic_cast<TableAndSchema*>(obj);
	return this->schema->equals(other->schema, ctx) && this->table->equals(other->table, ctx);
}
String* TableAndSchema::toString(ThreadContext* ctx) throw() 
{
	if(this->toStr == nullptr)
	{
		StringBuffer* buff = (new(ctx) StringBuffer(ctx));
		buff->append(this->schema, ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(this->table, ctx);
		__GC_MV(this, &(this->toStr), buff->toString(ctx), String);
	}
	return this->toStr;
}
TableAndSchema* TableAndSchema::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	String* table = fetcher->fetchString(ctx);
	String* schema = fetcher->fetchString(ctx);
	return (new(ctx) TableAndSchema(schema, table, ctx));
}
void TableAndSchema::__cleanUp(ThreadContext* ctx){
}
}}}

