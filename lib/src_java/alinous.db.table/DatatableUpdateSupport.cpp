#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTree.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Integer.h"
#include "alinous.btree/BTree.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table/OidIndexJob.h"
#include "alinous.db.table/IndexInsertJob.h"
#include "alinous.numeric/InternalDate.h"
#include "java.sql/Timestamp.h"
#include "alinous.db.table/DatatableConstants.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"

namespace alinous {namespace db {namespace table {





bool DatatableUpdateSupport::__init_done = __init_static_variables();
bool DatatableUpdateSupport::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatatableUpdateSupport", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatatableUpdateSupport::DatatableUpdateSupport(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw()  : IObject(ctx), DatatableDDLSupport(schema, name, baseDir, ctx)
{
}
void DatatableUpdateSupport::__construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() 
{
}
 DatatableUpdateSupport::~DatatableUpdateSupport() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatatableUpdateSupport::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DatatableDDLSupport::__releaseRegerences(true, ctx);
}
void DatatableUpdateSupport::updateData(IDatabaseRecord* data, long long commitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx)
{
	DatabaseRecord* lastdbrecord = getLastRecord(data->getOid(ctx), commitId, ctx);
	data->setLastUpdateCommitId(commitId, ctx);
	data->setInsertedCommitId(lastdbrecord->getInsertedCommitId(ctx), ctx);
	this->cacheEngine->updateData(this, lastdbrecord, commitId, jobs, log, ctx);
}
void DatatableUpdateSupport::insertData(DbTransaction* trx, IDatabaseRecord* data, long long commitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx)
{
	DatabaseRecord* dbrecord = (new(ctx) DatabaseRecord(data->getOid(ctx), data->getNumColumn(ctx), commitId, data, ctx));
	this->cacheEngine->insertData(this, dbrecord, commitId, jobs, log, ctx);
}
void DatatableUpdateSupport::insertData(DbTransaction* trx, List<IDatabaseRecord>* records, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* data = records->get(i, ctx);
		insertData(trx, data, newCommitId, jobs, logger, ctx);
	}
}
void DatatableUpdateSupport::tcpInsertCommit(IDatabaseRecord* dbrecord, ThreadPool* pool, ISystemLog* log, ThreadContext* ctx)
{
	int slotSize = getIndexes(ctx)->size(ctx) + 2;
	IArrayObject<SequentialBackgroundJob>* jobs = ArrayAllocator<SequentialBackgroundJob>::allocate(ctx, slotSize);
	for(int i = 0; i != slotSize; ++i)
	{
		jobs->set((new(ctx) SequentialBackgroundJob(ctx))->init(pool, ctx),i, ctx);
	}
	lockStorage(ctx);
	FileStorageEntryWriter* writer = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			writer->end(ctx);
			unlockStorage(ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			writer = this->dataStorage->getWriter(ctx);
			int cap = dbrecord->diskSize(ctx);
			FileStorageEntryBuilder* builder = (new(ctx) FileStorageEntryBuilder(cap, ctx));
			dbrecord->appendToEntry(builder, ctx);
			FileStorageEntry* entry = builder->toEntry(ctx);
			writer->write(entry, ctx);
			int slot = 0;
			jobs->get(slot++)->addJob((new(ctx) OidIndexJob(dbrecord->getOid(ctx), getOidIndex(ctx), entry->position, ctx)), ctx);
			jobs->get(slot++)->addJob((new(ctx) IndexInsertJob(getPrimaryIndex(ctx), dbrecord, ctx)), ctx);
			ArrayList<IScannableIndex>* indexes = getIndexes(ctx);
			int maxLoop = indexes->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IScannableIndex* tableIndex = indexes->get(i, ctx);
				jobs->get(slot++)->addJob((new(ctx) IndexInsertJob(tableIndex, dbrecord, ctx)), ctx);
			}
		}
		catch(...){throw;}
	}
}
void DatatableUpdateSupport::__cleanUp(ThreadContext* ctx){
}
}}}

