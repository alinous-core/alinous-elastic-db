#include "includes.h"


namespace alinous {namespace db {namespace trx {





bool DbTransaction::__init_done = __init_static_variables();
bool DbTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbTransaction::DbTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, ISystemLog* logger, long long commitId, ThreadContext* ctx) throw()  : IObject(ctx), lockContext(nullptr), lockMode(0), commitId(0), trxManager(nullptr), trxSchema(nullptr), trxStorageManager(nullptr), database(nullptr), logger(nullptr), subTransaction(nullptr), resultSerial(0), trxDir(nullptr), soidSerial(0)
{
	__GC_MV(this, &(this->trxManager), mgr, DbTransactionManager);
	__GC_MV(this, &(this->trxSchema), (new(ctx) TrxSchemeManager(database, logger, ctx)), TrxSchemeManager);
	__GC_MV(this, &(this->trxStorageManager), (new(ctx) TrxStorageManager(tmpDir, this, ctx)), TrxStorageManager);
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->logger), logger, ISystemLog);
	this->commitId = commitId;
	__GC_MV(this, &(this->lockContext), database->newLockContext(ctx), TrxLockContext);
	this->lockMode = IndexScannerLockRequirement::INSTANT_SHARE;
	this->resultSerial = 1;
	__GC_MV(this, &(this->trxDir), tmpDir, String);
	this->soidSerial = 1;
}
void DbTransaction::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, ISystemLog* logger, long long commitId, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->trxManager), mgr, DbTransactionManager);
	__GC_MV(this, &(this->trxSchema), (new(ctx) TrxSchemeManager(database, logger, ctx)), TrxSchemeManager);
	__GC_MV(this, &(this->trxStorageManager), (new(ctx) TrxStorageManager(tmpDir, this, ctx)), TrxStorageManager);
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->logger), logger, ISystemLog);
	this->commitId = commitId;
	__GC_MV(this, &(this->lockContext), database->newLockContext(ctx), TrxLockContext);
	this->lockMode = IndexScannerLockRequirement::INSTANT_SHARE;
	this->resultSerial = 1;
	__GC_MV(this, &(this->trxDir), tmpDir, String);
	this->soidSerial = 1;
}
 DbTransaction::~DbTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbTransaction", L"~DbTransaction");
	__e_obj1.add(this->lockContext, this);
	lockContext = nullptr;
	__e_obj1.add(this->trxManager, this);
	trxManager = nullptr;
	__e_obj1.add(this->trxSchema, this);
	trxSchema = nullptr;
	__e_obj1.add(this->trxStorageManager, this);
	trxStorageManager = nullptr;
	__e_obj1.add(this->database, this);
	database = nullptr;
	__e_obj1.add(this->logger, this);
	logger = nullptr;
	__e_obj1.add(this->subTransaction, this);
	subTransaction = nullptr;
	__e_obj1.add(this->trxDir, this);
	trxDir = nullptr;
	if(!prepare){
		return;
	}
}
long long DbTransaction::newSoid(ThreadContext* ctx) throw() 
{
	return this->soidSerial++;
}
ScanResult* DbTransaction::newResult(ScanTableMetadata* metadata, ThreadContext* ctx)
{
	ScanResult* result = (new(ctx) ScanResult(metadata, this->trxDir, this->resultSerial++, this->lockContext, ctx));
	return result;
}
void DbTransaction::select(SelectStatement* selectStmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->subTransaction != nullptr)
	{
		this->subTransaction->select(selectStmt, machine, debug, ctx);
		return;
	}
	SQLGroupBy* groupby = selectStmt->getGroupBy(ctx);
	if(groupby == nullptr)
	{
		noGroupBySelect(selectStmt, machine, debug, ctx);
		return;
	}
	ScanResult* groupedResult = newResult(selectStmt->getScanTableMetadata(ctx), ctx);
	ArrayList<ScanTableColumnIdentifier>* groupByCols = selectStmt->groupByDesc->getGroupByIndexColumns(ctx);
	ScanResultIndex* groupIndex = groupedResult->addIndex(groupByCols, ctx);
	ITableTargetScanner* scanner = selectStmt->getScanner(this, machine, nullptr, debug, ctx);
	scanner->startScan(nullptr, ctx);
	while(scanner->hasNext(debug, ctx))
	{
		ScanResultRecord* srecord = scanner->next(debug, ctx);
		groupedResult->addGroupByRecord(srecord, this, ctx);
	}
	IBTree* btree = groupIndex->getBtree(ctx);
	BTreeScanner* grpScanner = nullptr;
	{
		try
		{
			grpScanner = (new(ctx) BTreeScanner(btree, ctx));
			grpScanner->startScan(false, ctx);
			while(grpScanner->hasNext(ctx))
			{
				grpScanner->next(ctx);
			}
			scanner->endScan(ctx);
		}
		catch(Throwable* e)
		{
			if(grpScanner != nullptr)
			{
				groupIndex->dispose(this->logger, ctx);
			}
			throw (new(ctx) AlinousException(e, ctx));
		}
	}
	groupIndex->dispose(this->logger, ctx);
}
void DbTransaction::update(UpdateStatement* update, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->subTransaction != nullptr)
	{
		this->subTransaction->update(update, machine, debug, ctx);
		return;
	}
	AlinousName* tableName = update->getTableName(ctx);
	IDatabaseTable* tableStore = this->database->getTable(tableName, ConstStr::getCNST_STR_951(), ctx);
	{
		try
		{
			this->lockContext->shareLockTable(tableStore, ctx);
		}
		catch(DatabaseLockException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1617()->clone(ctx)->append(tableName->toString(ctx), ctx), e, ctx));
		}
	}
	{
		try
		{
			IJoinTarget* scanTarget = update->getTable(ctx);
			ITableTargetScanner* scanner = scanTarget->getScanner(this, machine, nullptr, debug, ctx);
			scanner->startScan(nullptr, ctx);
			while(scanner->hasNext(debug, ctx))
			{
				ScanResultRecord* record = scanner->next(debug, ctx);
				doUpdate(record, update, machine, debug, ctx);
			}
		}
		catch(Throwable* e)
		{
			this->lockContext->shareUnlockTable(tableStore, ctx);
			throw e;
		}
	}
	this->lockContext->shareUnlockTable(tableStore, ctx);
}
void DbTransaction::insert(InsertStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->subTransaction != nullptr)
	{
		this->subTransaction->insert(stmt, machine, debug, ctx);
		return;
	}
	TrxRecordsCache* cache = stmt->getCache(machine, trxStorageManager, ctx);
	ArrayList<IDomVariable>* values = stmt->getInsertRercords(machine, debug, ctx);
	ArrayList<CulumnOrder>* columns = stmt->getColumnOrder(machine, debug, ctx);
	cache->insertRecord(values, columns, ctx);
}
void DbTransaction::createIndex(CreateIndexStatement* stmt, ScriptMachine* machine, ThreadContext* ctx)
{
	if(this->subTransaction != nullptr)
	{
		this->subTransaction->createIndex(stmt, machine, ctx);
		return;
	}
	String* indexName = stmt->getIndexName(ctx);
	TableAndSchema* tas = stmt->getTableAndSchema(ctx);
	ArrayList<String>* columns = stmt->getColumns(ctx);
	CreateIndexMetadata* createMeta = (new(ctx) CreateIndexMetadata(indexName, tas, columns, ctx));
	this->trxSchema->addIndex(createMeta, ctx);
	TableMetadata* metadata = this->trxSchema->getTableMetadata(tas->getSchema(ctx), tas->getTable(ctx), ctx);
	if(metadata == nullptr)
	{
		IDatabaseTable* tableStore = this->database->getTable(tas->getSchema(ctx), tas->getTable(ctx), ctx);
		metadata = tableStore->getMetadata(ctx);
	}
	{
		try
		{
			this->trxStorageManager->addIndex(createMeta, metadata, this->database, ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1618(), e, ctx));
		}
		catch(BTreeException* e)
		{
			e->printStackTrace(ctx);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1618(), e, ctx));
		}
	}
}
void DbTransaction::createTable(TableSchema* schema, ThreadContext* ctx) throw() 
{
	if(this->subTransaction != nullptr)
	{
		this->subTransaction->createTable(schema, ctx);
		return;
	}
	this->trxSchema->addNewMetadata(schema, ctx);
}
TableMetadata* DbTransaction::getMetadata(String* schemaName, String* tableName, ThreadContext* ctx) throw() 
{
	TableMetadata* metadata = this->trxSchema->getTableMetadata(schemaName, tableName, ctx);
	if(metadata != nullptr)
	{
		return metadata;
	}
	TableSchemaCollection* sc = this->database->getSchema(schemaName, ctx);
	return sc->getDableMetadata(tableName, ctx);
}
void DbTransaction::commit(ThreadContext* ctx)
{
	if(this->subTransaction != nullptr)
	{
		this->subTransaction->commit(ctx);
	}
	long long newCommitId = this->database->newCommitId(ctx);
	if(this->trxSchema->isHasOperation(ctx))
	{
		this->trxSchema->executeCommit(ctx);
		this->trxSchema->reset(ctx);
	}
	if(this->trxStorageManager->isHasOperation(ctx))
	{
		{
			try
			{
				this->trxStorageManager->commit(newCommitId, ctx);
			}
			catch(IOException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1619(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1619(), e, ctx));
			}
			catch(VariableException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1619(), e, ctx));
			}
			catch(BTreeException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1619(), e, ctx));
			}
		}
		this->trxStorageManager->reset(ctx);
	}
}
void DbTransaction::close(ThreadContext* ctx)
{
	if(this->subTransaction != nullptr)
	{
		this->subTransaction->close(ctx);
	}
	this->trxSchema->reset(ctx);
	this->trxStorageManager->reset(ctx);
	this->lockContext->reset(ctx);
	this->trxManager->returnTransaction(this, ctx);
}
void DbTransaction::dispose(ThreadContext* ctx) throw() 
{
	this->trxSchema->dispose(ctx);
	this->trxStorageManager->dispose(ctx);
}
DbTransactionManager* DbTransaction::getTrxManager(ThreadContext* ctx) throw() 
{
	return trxManager;
}
TrxSchemeManager* DbTransaction::getTrxSchema(ThreadContext* ctx) throw() 
{
	return trxSchema;
}
TrxStorageManager* DbTransaction::getTrxStorageManager(ThreadContext* ctx) throw() 
{
	return trxStorageManager;
}
ISystemLog* DbTransaction::getLogger(ThreadContext* ctx) throw() 
{
	return logger;
}
AlinousDatabase* DbTransaction::getDatabase(ThreadContext* ctx) throw() 
{
	return database;
}
ThreadPool* DbTransaction::getThreadPool(ThreadContext* ctx) throw() 
{
	return this->database->workerThreadsPool;
}
bool DbTransaction::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this == obj;
}
void DbTransaction::noGroupBySelect(SelectStatement* selectStmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ITableTargetScanner* scanner = selectStmt->getScanner(this, machine, nullptr, debug, ctx);
	DomArray* selectResult = (new(ctx) DomArray(ctx));
	machine->getFrame(ctx)->putVariable(machine, selectStmt->intoDesc, selectResult, debug, ctx);
	SelectResultDescription* desc = selectStmt->resultDesc;
	scanner->startScan(nullptr, ctx);
	while(scanner->hasNext(debug, ctx))
	{
		ScanResultRecord* srecord = scanner->next(debug, ctx);
		DomVariable* domVariable = desc->fetchDom(srecord, machine, debug, ctx);
		selectResult->put(domVariable, ctx);
	}
}
void DbTransaction::doUpdate(ScanResultRecord* record, UpdateStatement* update, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	SQLWhere* where = update->getWhere(ctx);
	if(where != nullptr && where->getCondition(ctx) != nullptr)
	{
		ISQLExpression* exp = where->getCondition(ctx);
		VariantValue* value = exp->resolveSQLExpression(record, machine, debug, ctx);
		if(!value->isTrue(ctx))
		{
			return;
		}
	}
	ArrayList<UpdateSet>* sets = update->getSets(ctx);
	int maxLoop = sets->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		UpdateSet* set = sets->get(i, ctx);
		int colOrder = set->getColumnOrder(ctx);
		ISQLExpression* exp = set->getValue(ctx);
		VariantValue* value = exp->resolveSQLExpression(record, machine, debug, ctx);
		record->setValue(colOrder, value, ctx);
	}
	ScanTableMetadata* tableScheme = update->getTable(ctx)->getScanTableMetadata(ctx);
	TrxRecordsCache* cache = this->trxStorageManager->getUpdateCacheWithCreate(tableScheme->getSchemaName(ctx), tableScheme->getTableName(ctx), ctx);
	CachedRecord* rec = cache->getRecordByOid(record->getOid(ctx), ctx);
	if(rec != nullptr)
	{
		int numCols = record->numColumns(ctx);
		for(int i = 0; i != numCols; ++i)
		{
			rec->set(i, record->get(i, ctx), ctx);
		}
	}
		else 
	{
		cache->insertUpdateRecord(record, ctx);
	}
	this->trxStorageManager->setHasOperation(true, ctx);
}
}}}

