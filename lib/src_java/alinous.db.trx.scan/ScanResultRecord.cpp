#include "includes.h"


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
	ThreadLocker* locker = trx->lockContext;
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
void ScanResultRecord::releaseLocks(ThreadLocker* lockContext, ThreadContext* ctx) throw() 
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
}}}}

