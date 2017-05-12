#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/TableIndexValue.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.remote.db.server.scan/AbstractStorageScanSession.h"
#include "alinous.remote.db.server.scan/FullScanSession.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {





bool FullScanSession::__init_done = __init_static_variables();
bool FullScanSession::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FullScanSession", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FullScanSession::FullScanSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw()  : IObject(ctx), AbstractStorageScanSession(table, data, ctx), scanner(nullptr), lockMode(0), values(nullptr), current(0)
{
}
void FullScanSession::__construct_impl(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() 
{
}
 FullScanSession::~FullScanSession() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FullScanSession::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FullScanSession", L"~FullScanSession");
	__e_obj1.add(this->scanner, this);
	scanner = nullptr;
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
	AbstractStorageScanSession::__releaseRegerences(true, ctx);
}
void FullScanSession::init(ThreadContext* ctx)
{
	IScannableIndex* primaryIndex = this->table->getPrimaryIndex(ctx);
	BTree* storage = primaryIndex->getStorage(ctx);
	__GC_MV(this, &(this->scanner), (new(ctx) BTreeScanner(storage, ctx)), BTreeScanner);
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
	this->lockMode = this->data->getLockMode(ctx);
}
ScanWorkerResult* FullScanSession::scan(ThreadContext* ctx)
{
	ScanWorkerResult* result = (new(ctx) ScanWorkerResult(ctx));
	while(loadNextRecord(result, ctx))
	{
		;
	}
	return result;
}
bool FullScanSession::loadNextRecord(ScanWorkerResult* result, ThreadContext* ctx)
{
	IDatabaseRecord* rec = loadFromStorage(ctx);
	if(rec == nullptr)
	{
		result->setFinished(true, ctx);
		return false;
	}
	ClientNetworkRecord* record = (new(ctx) ClientNetworkRecord(rec, ctx));
	result->addRecord(record, ctx);
	return true;
}
IDatabaseRecord* FullScanSession::loadFromStorage(ThreadContext* ctx)
{
	if(this->values == nullptr || this->values->size(ctx) == this->current)
	{
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
		locker->shareLockRow(this->table, oid, ctx);
		break ;
	case IndexScannerLockRequirement::EXPLICIT_UPDATE:
		locker->updateLockRow(this->table, oid, ctx);
		break ;
	case IndexScannerLockRequirement::INSTANT_SHARE:
		locker->shareLockRow(this->table, oid, ctx);
		break ;
	case IndexScannerLockRequirement::INSTANT_UPDATE:
		locker->updateLockRow(this->table, oid, ctx);
		break ;
	default:
		break ;
	}
	IDatabaseRecord* record = nullptr;
	{
		try
		{
			record = this->table->loadRecord(position, ctx);
		}
		catch(Throwable* e)
		{
			switch(this->lockMode) {
			case IndexScannerLockRequirement::EXPLICIT_SHARE:
			case IndexScannerLockRequirement::INSTANT_SHARE:
				locker->shareUnlockRow(this->table, oid, ctx);
				break ;
			case IndexScannerLockRequirement::EXPLICIT_UPDATE:
			case IndexScannerLockRequirement::INSTANT_UPDATE:
				locker->updateUnlockRow(this->table, oid, ctx);
				break ;
			}
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1756(), e, ctx));
		}
	}
	switch(this->lockMode) {
	case IndexScannerLockRequirement::INSTANT_SHARE:
		locker->shareUnlockRow(this->table, oid, ctx);
		break ;
	case IndexScannerLockRequirement::INSTANT_UPDATE:
		locker->updateUnlockRow(this->table, oid, ctx);
		break ;
	}
	return record;
}
void FullScanSession::__cleanUp(ThreadContext* ctx){
}
}}}}}

