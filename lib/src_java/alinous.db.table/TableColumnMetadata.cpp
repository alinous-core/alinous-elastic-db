#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "java.sql/Timestamp.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.table/TableIndexValue.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table/IndexInsertJob.h"
#include "alinous.db.table/OidIndexJob.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table.lockmonitor/DBThreadMonitor.h"
#include "alinous.db.table/DatabaseTable.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.table/OidPublisherFactory.h"
#include "alinous.db.table/LocalOidCounter.h"
#include "alinous.db.table/LocalOidPublisher.h"
#include "alinous.db.table/DatatableConstants.h"

namespace alinous {namespace db {namespace table {





bool TableColumnMetadata::__init_done = __init_static_variables();
bool TableColumnMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableColumnMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableColumnMetadata::TableColumnMetadata(String* name, int type, int length, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), name(nullptr), notnull(0), unique(0), primaryKey(0), defaultValue(nullptr), columnOrder(0), type(0), length(0), check(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	this->type = type;
	this->length = length;
}
void TableColumnMetadata::__construct_impl(String* name, int type, int length, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	this->type = type;
	this->length = length;
}
 TableColumnMetadata::TableColumnMetadata(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), name(nullptr), notnull(0), unique(0), primaryKey(0), defaultValue(nullptr), columnOrder(0), type(0), length(0), check(nullptr)
{
}
void TableColumnMetadata::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TableColumnMetadata::~TableColumnMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableColumnMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableColumnMetadata", L"~TableColumnMetadata");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->defaultValue, this);
	defaultValue = nullptr;
	__e_obj1.add(this->check, this);
	check = nullptr;
	if(!prepare){
		return;
	}
}
int TableColumnMetadata::fileSize(ThreadContext* ctx)
{
	int total = 4 + 4;
	total += name->length(ctx) * 2 + 4;
	total += 1 * 3;
	total += 4;
	total += 1;
	if(this->defaultValue != nullptr)
	{
		total += defaultValue->length(ctx) * 2 + 4;
	}
	total += 1;
	if(this->check != nullptr)
	{
		total += check->getExp(ctx)->fileSize(ctx);
	}
	return total;
}
void TableColumnMetadata::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(this->type, ctx);
	builder->putInt(this->length, ctx);
	builder->putString(this->name, ctx);
	char bl = ((char)(this->notnull ? 1 : 0));
	builder->putByte(bl, ctx);
	bl = ((char)(this->unique ? 1 : 0));
	builder->putByte(bl, ctx);
	bl = ((char)(this->primaryKey ? 1 : 0));
	builder->putByte(bl, ctx);
	builder->putInt(this->columnOrder, ctx);
}
CheckDefinition* TableColumnMetadata::getCheck(ThreadContext* ctx) throw() 
{
	return check;
}
void TableColumnMetadata::setCheck(CheckDefinition* check, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->check), check, CheckDefinition);
}
bool TableColumnMetadata::isPrimaryKey(ThreadContext* ctx) throw() 
{
	return primaryKey;
}
void TableColumnMetadata::setPrimaryKey(bool primaryKey, ThreadContext* ctx) throw() 
{
	this->primaryKey = primaryKey;
}
void TableColumnMetadata::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->type = buff->getInt(ctx);
	this->length = buff->getInt(ctx);
	__GC_MV(this, &(this->name), buff->getString(ctx), String);
	this->notnull = buff->getBoolean(ctx);
	this->unique = buff->getBoolean(ctx);
	this->primaryKey = buff->getBoolean(ctx);
	this->columnOrder = buff->getInt(ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->defaultValue), buff->getString(ctx), String);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->check), (new(ctx) CheckDefinition(ctx)), CheckDefinition);
		this->check->readData(buff, ctx);
	}
}
void TableColumnMetadata::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(this->type, ctx);
	buff->putInt(this->length, ctx);
	buff->putString(this->name, ctx);
	buff->putBoolean(this->notnull, ctx);
	buff->putBoolean(this->unique, ctx);
	buff->putBoolean(this->primaryKey, ctx);
	buff->putInt(this->columnOrder, ctx);
	bool isnull = (this->defaultValue == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->defaultValue), buff->getString(ctx), String);
	}
	isnull = (this->check == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->check->writeData(buff, ctx);
	}
}
int TableColumnMetadata::getType(ThreadContext* ctx) throw() 
{
	return type;
}
bool TableColumnMetadata::isUnique(ThreadContext* ctx) throw() 
{
	return unique;
}
void TableColumnMetadata::setUnique(bool unique, ThreadContext* ctx) throw() 
{
	this->unique = unique;
}
TableColumnMetadata* TableColumnMetadata::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	int type = fetcher->fetchInt(ctx);
	int length = fetcher->fetchInt(ctx);
	String* name = fetcher->fetchString(ctx);
	TableColumnMetadata* col = (new(ctx) TableColumnMetadata(name, type, length, ctx));
	char bl = fetcher->fetchByte(ctx);
	col->notnull = (bl > (char)0 ? true : false);
	bl = fetcher->fetchByte(ctx);
	col->unique = (bl > (char)0 ? true : false);
	bl = fetcher->fetchByte(ctx);
	col->setPrimaryKey(bl > (char)0 ? true : false, ctx);
	col->columnOrder = fetcher->fetchInt(ctx);
	return col;
}
TableColumnMetadata* TableColumnMetadata::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TableColumnMetadata* meta = (new(ctx) TableColumnMetadata(ctx));
	meta->readData(buff, ctx);
	return meta;
}
void TableColumnMetadata::__cleanUp(ThreadContext* ctx){
}
}}}

