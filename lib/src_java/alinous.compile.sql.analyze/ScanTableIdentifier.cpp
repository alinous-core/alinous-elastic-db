#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/IExpression.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile.sql.analyze/IndexScanStrategyPlan.h"
#include "alinous.compile.sql.analyze/IndexScanStrategy.h"
#include "alinous.compile.sql.analyze/InnerNecessaryCondition.h"
#include "alinous.compile.sql.analyze/BooleanFilterConditionUtil.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.compile.sql.analyze/IndexConditionDetector.h"
#include "alinous.compile.sql.analyze/IndexSelectionUtils.h"
#include "alinous.compile.sql.analyze/IScanStrategy.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.table.scan/SingleTableIndexScanner.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.analyze/ScanSingleStrategy.h"
#include "alinous.compile.sql.analyze/JoinConditionDetector.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool ScanTableIdentifier::__init_done = __init_static_variables();
bool ScanTableIdentifier::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanTableIdentifier", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanTableIdentifier::ScanTableIdentifier(TableAndSchema* table, String* asName, int numColmuns, ThreadContext* ctx) throw()  : IObject(ctx), table(nullptr), asName(nullptr), numColmuns(0)
{
	__GC_MV(this, &(this->table), table, TableAndSchema);
	__GC_MV(this, &(this->asName), asName, String);
}
void ScanTableIdentifier::__construct_impl(TableAndSchema* table, String* asName, int numColmuns, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, TableAndSchema);
	__GC_MV(this, &(this->asName), asName, String);
}
 ScanTableIdentifier::~ScanTableIdentifier() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanTableIdentifier::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanTableIdentifier", L"~ScanTableIdentifier");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	if(!prepare){
		return;
	}
}
ScanTableIdentifier* ScanTableIdentifier::copy(ThreadContext* ctx) throw() 
{
	ScanTableIdentifier* newObj = (new(ctx) ScanTableIdentifier(table, asName, numColmuns, ctx));
	return newObj;
}
bool ScanTableIdentifier::equals(String* asName, ThreadContext* ctx) throw() 
{
	return this->asName != nullptr && this->asName->equals(asName, ctx);
}
bool ScanTableIdentifier::equals(ScanTableIdentifier* other, ThreadContext* ctx) throw() 
{
	return (this->asName != nullptr && other->asName != nullptr && this->asName->equals(other->asName, ctx)) || (this->table != nullptr && other->table != nullptr && this->table->equals(other->table, ctx));
}
int ScanTableIdentifier::getArchiveSize(ThreadContext* ctx) throw() 
{
	int total = 1;
	if(this->table != nullptr)
	{
		total += this->table->getArchiveSize(ctx);
	}
	total += 1;
	if(this->asName != nullptr)
	{
		total += 4 + this->asName->length(ctx) * 2;
	}
	total += 4;
	return total;
}
void ScanTableIdentifier::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	if(this->table != nullptr)
	{
		builder->putByte(((char)1), ctx);
		this->table->appendToEntry(builder, ctx);
	}
		else 
	{
		builder->putByte(((char)0), ctx);
	}
	if(this->asName != nullptr)
	{
		builder->putByte(((char)1), ctx);
		builder->putString(this->asName, ctx);
	}
		else 
	{
		builder->putByte(((char)0), ctx);
	}
	builder->putInt(this->numColmuns, ctx);
}
String* ScanTableIdentifier::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	bool hasTable = this->table != nullptr;
	if(hasTable)
	{
		buff->append(table->toString(ctx), ctx);
	}
	if(this->asName != nullptr)
	{
		if(hasTable)
		{
			buff->append(ConstStr::getCNST_STR_887(), ctx)->append(asName, ctx)->append(ConstStr::getCNST_STR_889(), ctx);
		}
				else 
		{
			buff->append(asName, ctx);
		}
	}
	return buff->toString(ctx);
}
TableAndSchema* ScanTableIdentifier::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void ScanTableIdentifier::setTable(TableAndSchema* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, TableAndSchema);
}
String* ScanTableIdentifier::getAsName(ThreadContext* ctx) throw() 
{
	return asName;
}
void ScanTableIdentifier::setAsName(String* asName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), asName, String);
}
int ScanTableIdentifier::getNumColmuns(ThreadContext* ctx) throw() 
{
	return numColmuns;
}
ScanTableIdentifier* ScanTableIdentifier::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	TableAndSchema* table = nullptr;
	String* asName = nullptr;
	int numColumns = 0;
	char flag = fetcher->fetchByte(ctx);
	if(flag != (char)0)
	{
		table = TableAndSchema::valueFromFetcher(fetcher, ctx);
	}
	flag = fetcher->fetchByte(ctx);
	if(flag != (char)0)
	{
		asName = fetcher->fetchString(ctx);
	}
	numColumns = fetcher->fetchInt(ctx);
	return (new(ctx) ScanTableIdentifier(table, asName, numColumns, ctx));
}
void ScanTableIdentifier::__cleanUp(ThreadContext* ctx){
}
}}}}

