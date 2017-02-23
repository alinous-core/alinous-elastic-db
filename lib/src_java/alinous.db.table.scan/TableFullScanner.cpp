#include "includes.h"


namespace alinous {namespace db {namespace table {namespace scan {





bool TableFullScanner::__init_done = __init_static_variables();
bool TableFullScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableFullScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableFullScanner::~TableFullScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableFullScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableFullScanner", L"~TableFullScanner");
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	__e_obj1.add(this->index, this);
	index = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->scanner, this);
	scanner = nullptr;
	__e_obj1.add(this->tableStore, this);
	tableStore = nullptr;
	__e_obj1.add(this->values, this);
	values = nullptr;
	__e_obj1.add(this->locker, this);
	locker = nullptr;
	__e_obj1.add(this->nextresult, this);
	nextresult = nullptr;
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	if(!prepare){
		return;
	}
}
TableFullScanner* TableFullScanner::init(ScanTableIdentifier* tableId, DbTransaction* trx, IDatabaseTable* tableStore, int lockMode, ThreadContext* ctx)
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->index), tableStore->getPrimaryIndex(ctx), IScannableIndex);
	__GC_MV(this, &(this->storage), this->index->getStorage(ctx), BTree);
	__GC_MV(this, &(this->scanner), (new(ctx) BTreeScanner(this->storage, ctx)), BTreeScanner);
	__GC_MV(this, &(this->tableStore), tableStore, IDatabaseTable);
	this->lockMode = lockMode;
	__GC_MV(this, &(this->locker), trx->lockContext, TrxLockContext);
	return this;
}
void TableFullScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	{
		try
		{
			this->scanner->startScan(false, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
	}
}
bool TableFullScanner::hasNext(bool debug, ThreadContext* ctx)
{
	{
		try
		{
			return loadNextRecord(ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
	}
}
void TableFullScanner::endScan(ThreadContext* ctx)
{
	{
		try
		{
			this->scanner->endScan(ctx);
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
	}
}
ScanResultRecord* TableFullScanner::next(bool debug, ThreadContext* ctx)
{
	ScanResultRecord* ret = this->nextresult;
	__GC_MV(this, &(this->nextresult), nullptr, ScanResultRecord);
	return ret;
}
void TableFullScanner::dispose(ISystemLog* core, ThreadContext* ctx)
{
	{
		try
		{
			this->scanner->endScan(ctx);
		}
		catch(InterruptedException* e)
		{
			e->printStackTrace(ctx);
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1707(), e, ctx));
		}
	}
}
bool TableFullScanner::loadNextRecord(ThreadContext* ctx)
{
	if(this->nextresult != nullptr)
	{
		return true;
	}
	while(true)
	{
		IDatabaseRecord* record = nextIndexValue(ctx);
		if(record == nullptr)
		{
			break ;
		}
		bool visible = this->trx->isVisible(record, this->tableStore, ctx);
		if(visible)
		{
			__GC_MV(this, &(this->nextresult), (new(ctx) ScanResultRecord(this->tableId, IDatabaseRecord::NORMAL_RECORD, record->getOid(ctx), trx, record, this->lockMode, ctx)), ScanResultRecord);
			return true;
		}
		switch(this->lockMode) {
		case IndexScannerLockRequirement::EXPLICIT_SHARE:
		case IndexScannerLockRequirement::INSTANT_SHARE:
			locker->shareUnlockRow(this->tableStore, record->getOid(ctx), ctx);
			break ;
		case IndexScannerLockRequirement::EXPLICIT_UPDATE:
		case IndexScannerLockRequirement::INSTANT_UPDATE:
			locker->updateUnlockRow(this->tableStore, record->getOid(ctx), ctx);
			break ;
		default:
			break ;
		}
	}
	return false;
}
IDatabaseRecord* TableFullScanner::nextIndexValue(ThreadContext* ctx)
{
	if(this->values == nullptr || this->values->size(ctx) == this->current)
	{
		GCUtils<ArrayList<IBTreeValue> >::mv(this, &(this->values), nullptr, ctx);
		this->current = 0;
		if(!this->scanner->hasNext(ctx))
		{
			return nullptr;
		}
		IBTreeNode* node = this->scanner->next(ctx);
		GCUtils<ArrayList<IBTreeValue> >::mv(this, &(this->values), node->getValues(ctx), ctx);
		this->current = 0;
	}
	TableIndexValue* value = static_cast<TableIndexValue*>(this->values->get(this->current++, ctx));
	long long position = value->getPosition(ctx);
	long long oid = value->getOid(ctx);
	switch(this->lockMode) {
	case IndexScannerLockRequirement::EXPLICIT_SHARE:
		locker->shareLockRow(this->tableStore, oid, ctx);
		break ;
	case IndexScannerLockRequirement::EXPLICIT_UPDATE:
		locker->updateLockRow(this->tableStore, oid, ctx);
		break ;
	case IndexScannerLockRequirement::INSTANT_SHARE:
		locker->shareLockRow(this->tableStore, oid, ctx);
		break ;
	case IndexScannerLockRequirement::INSTANT_UPDATE:
		locker->updateLockRow(this->tableStore, oid, ctx);
		break ;
	default:
		break ;
	}
	IDatabaseRecord* record = nullptr;
	{
		try
		{
			record = this->tableStore->loadRecord(position, ctx);
		}
		catch(Throwable* e)
		{
			switch(this->lockMode) {
			case IndexScannerLockRequirement::INSTANT_SHARE:
				locker->shareUnlockRow(this->tableStore, oid, ctx);
				break ;
			case IndexScannerLockRequirement::INSTANT_UPDATE:
				locker->updateUnlockRow(this->tableStore, oid, ctx);
				break ;
			}
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1706(), e, ctx));
		}
	}
	switch(this->lockMode) {
	case IndexScannerLockRequirement::INSTANT_SHARE:
		locker->shareUnlockRow(this->tableStore, oid, ctx);
		break ;
	case IndexScannerLockRequirement::INSTANT_UPDATE:
		locker->updateUnlockRow(this->tableStore, oid, ctx);
		break ;
	}
	return record;
}
}}}}

