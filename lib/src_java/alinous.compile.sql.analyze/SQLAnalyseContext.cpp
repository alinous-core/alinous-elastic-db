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
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
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
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
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





bool SQLAnalyseContext::__init_done = __init_static_variables();
bool SQLAnalyseContext::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLAnalyseContext", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLAnalyseContext::SQLAnalyseContext(AlinousDatabase* database, ScriptMachine* machine, ThreadContext* ctx) throw()  : IObject(ctx), database(nullptr), machine(nullptr), tables(GCUtils<ArrayList<ScanTableMetadata> >::ins(this, (new(ctx) ArrayList<ScanTableMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), asNameMap(GCUtils<HashMap<String,ScanTableMetadata> >::ins(this, (new(ctx) HashMap<String,ScanTableMetadata>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
}
void SQLAnalyseContext::__construct_impl(AlinousDatabase* database, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
}
 SQLAnalyseContext::~SQLAnalyseContext() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLAnalyseContext::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLAnalyseContext", L"~SQLAnalyseContext");
	__e_obj1.add(this->database, this);
	database = nullptr;
	__e_obj1.add(this->machine, this);
	machine = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	__e_obj1.add(this->asNameMap, this);
	asNameMap = nullptr;
	if(!prepare){
		return;
	}
}
void SQLAnalyseContext::addTable(ScanTableMetadata* table, String* asName, ThreadContext* ctx) throw() 
{
	this->tables->add(table, ctx);
	if(asName != nullptr)
	{
		this->asNameMap->put(asName, table, ctx);
	}
}
ArrayList<ScanTableMetadata>* SQLAnalyseContext::getTables(ThreadContext* ctx) throw() 
{
	return tables;
}
AlinousDatabase* SQLAnalyseContext::getDatabase(ThreadContext* ctx) throw() 
{
	return database;
}
ScanTableMetadata* SQLAnalyseContext::findTableByAsName(String* asname, ThreadContext* ctx) throw() 
{
	return this->asNameMap->get(asname, ctx);
}
ScriptMachine* SQLAnalyseContext::getMachine(ThreadContext* ctx) throw() 
{
	return machine;
}
ArrayList<ScanTableColumnIdentifier>* SQLAnalyseContext::joinList(ArrayList<ScanTableColumnIdentifier>* list, ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	if(exp == nullptr)
	{
		return list;
	}
	ArrayList<ScanTableColumnIdentifier>* sublist = exp->getColumns(ctx);
	if(sublist != nullptr)
	{
		list->addAll(sublist, ctx);
	}
	return list;
}
String* SQLAnalyseContext::findTable(SQLAnalyseContext* context, String* schema, String* column, ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableMetadata>* tables = context->getTables(ctx);
	AlinousDatabase* db = context->getDatabase(ctx);
	int maxLoop = tables->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableMetadata* tbl = tables->get(i, ctx);
		if(!tbl->getSchemaName(ctx)->equals(schema, ctx))
		{
			continue;
		}
		IDatabaseTable* tableStore = db->getTable(schema, tbl->getTableName(ctx), ctx);
		if(tableStore != nullptr)
		{
			return tbl->getTableName(ctx);
		}
	}
	return nullptr;
}
void SQLAnalyseContext::__cleanUp(ThreadContext* ctx){
}
}}}}

