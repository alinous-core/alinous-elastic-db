#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
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
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.db.trx.scan/PadddingRecord.h"
#include "alinous.btree/BTreeValues.h"
#include "alinous.btree/IntValue.h"
#include "alinous.btree/LongValue.h"
#include "alinous.btree/StringValue.h"
#include "alinous.btree/TimestampValue.h"
#include "alinous.btree/DoubleValue.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IntKey.h"
#include "alinous.btree/LongKey.h"
#include "alinous.btree/StringKey.h"
#include "alinous.btree/DoubleKey.h"
#include "alinous.btree/TimestampKey.h"
#include "alinous.btree/KeyValueFactory.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/DbTransaction.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"

namespace alinous {namespace db {namespace trx {namespace scan {





bool ScanResultRecord::__init_done = __init_static_variables();
bool ScanResultRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanResultRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanResultRecord::ScanResultRecord(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), records(GCUtils<ArrayList<IDatabaseRecord> >::ins(this, (new(ctx) ArrayList<IDatabaseRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), tables(GCUtils<ArrayList<ScanTableIdentifier> >::ins(this, (new(ctx) ArrayList<ScanTableIdentifier>(ctx)), ctx, __FILEW__, __LINE__, L"")), lockingModeList(GCUtils<ArrayList<Integer> >::ins(this, (new(ctx) ArrayList<Integer>(ctx)), ctx, __FILEW__, __LINE__, L"")), soid(0)
{
}
void ScanResultRecord::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ScanResultRecord::ScanResultRecord(ScanTableIdentifier* tableId, int kind, long long oid, DbTransaction* trx, IDatabaseRecord* record, int lockingMode, ThreadContext* ctx) : IObject(ctx), IBTreeValue(ctx), records(GCUtils<ArrayList<IDatabaseRecord> >::ins(this, (new(ctx) ArrayList<IDatabaseRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), tables(GCUtils<ArrayList<ScanTableIdentifier> >::ins(this, (new(ctx) ArrayList<ScanTableIdentifier>(ctx)), ctx, __FILEW__, __LINE__, L"")), lockingModeList(GCUtils<ArrayList<Integer> >::ins(this, (new(ctx) ArrayList<Integer>(ctx)), ctx, __FILEW__, __LINE__, L"")), soid(0)
{
	this->records->add(record, ctx);
	this->tables->add(tableId, ctx);
	this->lockingModeList->add((new(ctx) Integer(lockingMode, ctx)), ctx);
	this->soid = trx->newSoid(ctx);
}
void ScanResultRecord::__construct_impl(ScanTableIdentifier* tableId, int kind, long long oid, DbTransaction* trx, IDatabaseRecord* record, int lockingMode, ThreadContext* ctx)
{
	this->records->add(record, ctx);
	this->tables->add(tableId, ctx);
	this->lockingModeList->add((new(ctx) Integer(lockingMode, ctx)), ctx);
	this->soid = trx->newSoid(ctx);
}
 ScanResultRecord::ScanResultRecord(ScanTableIdentifier* tableId, long long oid, DbTransaction* trx, ScanTableMetadata* metadata, DomVariable* domVariable, ThreadContext* ctx) : IObject(ctx), IBTreeValue(ctx), records(GCUtils<ArrayList<IDatabaseRecord> >::ins(this, (new(ctx) ArrayList<IDatabaseRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), tables(GCUtils<ArrayList<ScanTableIdentifier> >::ins(this, (new(ctx) ArrayList<ScanTableIdentifier>(ctx)), ctx, __FILEW__, __LINE__, L"")), lockingModeList(GCUtils<ArrayList<Integer> >::ins(this, (new(ctx) ArrayList<Integer>(ctx)), ctx, __FILEW__, __LINE__, L"")), soid(0)
{
	this->records->add(domVariable, ctx);
	this->tables->add(tableId, ctx);
	this->lockingModeList->add((new(ctx) Integer(IndexScannerLockRequirement::NO_LOCK, ctx)), ctx);
}
void ScanResultRecord::__construct_impl(ScanTableIdentifier* tableId, long long oid, DbTransaction* trx, ScanTableMetadata* metadata, DomVariable* domVariable, ThreadContext* ctx)
{
	this->records->add(domVariable, ctx);
	this->tables->add(tableId, ctx);
	this->lockingModeList->add((new(ctx) Integer(IndexScannerLockRequirement::NO_LOCK, ctx)), ctx);
}
 ScanResultRecord::~ScanResultRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanResultRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanResultRecord", L"~ScanResultRecord");
	__e_obj1.add(this->records, this);
	records = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	__e_obj1.add(this->lockingModeList, this);
	lockingModeList = nullptr;
	if(!prepare){
		return;
	}
}
ScanResultRecord* ScanResultRecord::copy(DbTransaction* trx, ThreadContext* ctx)
{
	ScanResultRecord* newrecord = (new(ctx) ScanResultRecord(ctx));
	newrecord->soid = this->soid;
	ArrayList<IDatabaseRecord>* records = this->records;
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = records->get(i, ctx);
		newrecord->records->add(rec, ctx);
	}
	ArrayList<ScanTableIdentifier>* tables = this->tables;
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = tables->get(i, ctx);
		newrecord->tables->add(tableId, ctx);
	}
	ArrayList<Integer>* lockingModeList = this->lockingModeList;
	for(int i = 0; i != maxLoop; ++i)
	{
		Integer* mode = lockingModeList->get(i, ctx);
		newrecord->lockingModeList->add(mode, ctx);
	}
	return newrecord;
}
void ScanResultRecord::unlock(DbTransaction* trx, ThreadContext* ctx)
{
	ArrayList<IDatabaseRecord>* records = this->records;
	ArrayList<ScanTableIdentifier>* tables = this->tables;
	AlinousDatabase* db = trx->getDatabase(ctx);
	TrxLockContext* locker = trx->lockContext;
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* record = records->get(i, ctx);
		if(record->getKind(ctx) != IDatabaseRecord::NORMAL_RECORD)
		{
			continue;
		}
		ScanTableIdentifier* tableId = tables->get(i, ctx);
		TableAndSchema* ts = tableId->getTable(ctx);
		IDatabaseTable* tableStore = db->getTable(ts->getSchema(ctx), ts->getTable(ctx), ctx);
		int lockingMode = this->lockingModeList->get(i, ctx)->intValue(ctx);
		switch(lockingMode) {
		case IndexScannerLockRequirement::EXPLICIT_SHARE:
			locker->shareUnlockRow(tableStore, record->getOid(ctx), ctx);
			break ;
		case IndexScannerLockRequirement::EXPLICIT_UPDATE:
			locker->updateUnlockRow(tableStore, record->getOid(ctx), ctx);
			break ;
		default:
			break ;
		}
	}
}
VariantValue* ScanResultRecord::getValueOfTable(ScanTableIdentifier* tableId, int columnOrder, ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableIdentifier>* tables = this->tables;
	int maxLoop = tables->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* t = tables->get(i, ctx);
		if(tableId->equals(t, ctx))
		{
			IDatabaseRecord* rec = this->records->get(i, ctx);
			return rec->getColumnValue(columnOrder, ctx);
		}
	}
	return nullptr;
}
VariantValue* ScanResultRecord::get(int index, ThreadContext* ctx) throw() 
{
	int maxLoop = tables->size(ctx);
	int offset = 0;
	int tableOffset = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* t = records->get(i, ctx);
		int off = offset + t->getNumValues(ctx);
		if(off > index)
		{
			break ;
		}
		offset = off;
		tableOffset ++ ;
	}
	return this->records->get(tableOffset, ctx)->getColumnValue(index - offset, ctx);
}
int ScanResultRecord::numColumns(ThreadContext* ctx) throw() 
{
	int maxLoop = tables->size(ctx);
	int cols = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* t = records->get(i, ctx);
		cols += t->getNumValues(ctx);
	}
	return cols;
}
void ScanResultRecord::setValue(int index, VariantValue* vv, ThreadContext* ctx) throw() 
{
	int maxLoop = tables->size(ctx);
	int offset = 0;
	int tableOffset = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* t = records->get(i, ctx);
		int off = offset + t->getNumValues(ctx);
		if(off > index)
		{
			break ;
		}
		offset = off;
		tableOffset ++ ;
	}
	this->records->get(tableOffset, ctx)->setValue(index - offset, vv, ctx);
}
void ScanResultRecord::addNullRecord(int colSize, ThreadContext* ctx) throw() 
{
	this->records->add((new(ctx) PadddingRecord(colSize, ctx)), ctx);
}
long long ScanResultRecord::getLastUpdateCommitId(ThreadContext* ctx) throw() 
{
	return this->records->get(0, ctx)->getLastUpdateCommitId(ctx);
}
long long ScanResultRecord::getInsertedCommitId(ThreadContext* ctx) throw() 
{
	return this->records->get(0, ctx)->getInsertedCommitId(ctx);
}
long long ScanResultRecord::getDeletedCommitId(ThreadContext* ctx) throw() 
{
	return this->records->get(0, ctx)->getDeletedCommitId(ctx);
}
long long ScanResultRecord::getOid(ThreadContext* ctx) throw() 
{
	return this->records->get(0, ctx)->getOid(ctx);
}
void ScanResultRecord::releaseLocks(TrxLockContext* lockContext, ThreadContext* ctx) throw() 
{
}
ScanTableIdentifier* ScanResultRecord::getTableId(ThreadContext* ctx) throw() 
{
	return this->tables->get(0, ctx);
}
int ScanResultRecord::diskSize(ThreadContext* ctx)
{
	int total = 4 + 8 + 4;
	int maxLoop = this->records->size(ctx);
	ArrayList<IDatabaseRecord>* records = this->records;
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = records->get(i, ctx);
		total += rec->diskSize(ctx);
	}
	ArrayList<ScanTableIdentifier>* tables = this->tables;
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = tables->get(i, ctx);
		total += tableId->getArchiveSize(ctx);
	}
	total += maxLoop * 4;
	return total;
}
void ScanResultRecord::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeValue::TYPE_SCAN_RESULT_RECORD, ctx);
	builder->putLong(this->soid, ctx);
	int maxLoop = this->records->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = this->records->get(i, ctx);
		rec->appendToEntry(builder, ctx);
	}
	ArrayList<ScanTableIdentifier>* tables = this->tables;
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = tables->get(i, ctx);
		tableId->appendToEntry(builder, ctx);
	}
	ArrayList<Integer>* lockingModeList = this->lockingModeList;
	for(int i = 0; i != maxLoop; ++i)
	{
		Integer* mode = lockingModeList->get(i, ctx);
		builder->putInt(mode->intValue(ctx), ctx);
	}
}
IValueFetcher* ScanResultRecord::getFetcher(ThreadContext* ctx) throw() 
{
	return nullptr;
}
ScanResultRecord* ScanResultRecord::join(ScanResultRecord* rightRecord, DbTransaction* trx, ThreadContext* ctx)
{
	ScanResultRecord* newRecord = copy(trx, ctx);
	ArrayList<IDatabaseRecord>* reclist = rightRecord->records;
	ArrayList<ScanTableIdentifier>* tableslist = rightRecord->tables;
	ArrayList<Integer>* lockingModeList = rightRecord->lockingModeList;
	ArrayList<IDatabaseRecord>* nrecords = newRecord->records;
	ArrayList<ScanTableIdentifier>* ntables = newRecord->tables;
	ArrayList<Integer>* nlockingModeList = newRecord->lockingModeList;
	int maxLoop = reclist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* record = reclist->get(i, ctx);
		ScanTableIdentifier* tableId = tableslist->get(i, ctx);
		Integer* lockingMode = lockingModeList->get(i, ctx);
		nrecords->add(record, ctx);
		ntables->add(tableId, ctx);
		nlockingModeList->add(lockingMode, ctx);
	}
	return newRecord;
}
long long ScanResultRecord::getSoid(ThreadContext* ctx) throw() 
{
	return soid;
}
void ScanResultRecord::setSoid(long long soid, ThreadContext* ctx) throw() 
{
	this->soid = soid;
}
ArrayList<IDatabaseRecord>* ScanResultRecord::getRecords(ThreadContext* ctx) throw() 
{
	return records;
}
String* ScanResultRecord::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	ArrayList<IDatabaseRecord>* records = this->records;
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = records->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(rec->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
bool ScanResultRecord::equals(IObject* other, ThreadContext* ctx) throw() 
{
	return this == other;
}
ScanResultRecord* ScanResultRecord::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	ScanResultRecord* record = (new(ctx) ScanResultRecord(ctx));
	record->soid = fetcher->fetchLong(ctx);
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IBTreeValue* rec = KeyValueFactory::valueFromFetcher(fetcher, ctx);
		record->records->add(static_cast<IDatabaseRecord*>(rec), ctx);
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = ScanTableIdentifier::valueFromFetcher(fetcher, ctx);
		record->tables->add(tableId, ctx);
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		int lockingMode = fetcher->fetchInt(ctx);
		record->lockingModeList->add((new(ctx) Integer(lockingMode, ctx)), ctx);
	}
	return record;
}
void ScanResultRecord::__cleanUp(ThreadContext* ctx){
}
}}}}

