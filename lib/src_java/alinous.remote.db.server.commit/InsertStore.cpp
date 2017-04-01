#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.btreememory/BTreeOnMemory.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.remote.db/MonitorAccess.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.remote.db.server.commit/TableFullNameKey.h"
#include "alinous.remote.db.server.commit/InsertStore.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {





bool InsertStore::__init_done = __init_static_variables();
bool InsertStore::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InsertStore", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InsertStore::InsertStore(String* filePath, ThreadContext* ctx) throw()  : IObject(ctx), store(nullptr), baseDir(nullptr)
{
	__GC_MV(this, &(this->baseDir), filePath, String);
}
void InsertStore::__construct_impl(String* filePath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->baseDir), filePath, String);
}
 InsertStore::~InsertStore() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InsertStore::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InsertStore", L"~InsertStore");
	__e_obj1.add(this->store, this);
	store = nullptr;
	__e_obj1.add(this->baseDir, this);
	baseDir = nullptr;
	if(!prepare){
		return;
	}
}
InsertStore* InsertStore::init(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->store), (new(ctx) BTreeOnMemory(8, ctx)), IBTree);
	return this;
}
void InsertStore::commitPrepared(long long newCommitId, DbVersionContext* vctx, RemoteTableStorageServer* server, ThreadContext* ctx)
{
	BTreeScanner* scanner = (new(ctx) BTreeScanner(this->store, ctx));
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			{
				try
				{
					scanner->endScan(ctx);
				}
				catch(InterruptedException* ignore)
				{
					ignore->printStackTrace(ctx);
				}
			}
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			scanner->startScan(false, ctx);
			while(scanner->hasNext(ctx))
			{
				IBTreeNode* node = scanner->next(ctx);
				TableFullNameKey* tablekey = static_cast<TableFullNameKey*>(node->getKey(ctx));
				ArrayList<IBTreeValue>* values = node->getValues(ctx);
				handleCommitTable(newCommitId, vctx, tablekey, values, server, ctx);
			}
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3595(), ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3595(), ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3595(), ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3595(), ctx));
		}
	}
}
void InsertStore::add(IDatabaseTable* table, List<ClientNetworkRecord>* records, ThreadContext* ctx)
{
	TableMetadata* meta = table->getMetadata(ctx);
	TableFullNameKey* key = (new(ctx) TableFullNameKey(meta->getSchema(ctx), meta->getTableName(ctx), ctx));
	IBTreeNode* node = this->store->findByKey(key, ctx);
	if(node == nullptr)
	{
		this->store->putKey(key, ctx);
		node = this->store->findByKey(key, ctx);
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = records->get(i, ctx);
		values->add(record, ctx);
	}
}
IBTree* InsertStore::getStore(ThreadContext* ctx) throw() 
{
	return store;
}
String* InsertStore::getBaseDir(ThreadContext* ctx) throw() 
{
	return baseDir;
}
void InsertStore::handleCommitTable(long long newCommitId, DbVersionContext* vctx, TableFullNameKey* fullName, ArrayList<IBTreeValue>* values, RemoteTableStorageServer* server, ThreadContext* ctx)
{
	String* schemaName = fullName->getSchema(ctx);
	String* tableName = fullName->getTable(ctx);
	TableSchema* schema = server->schemas->getSchema(schemaName, ctx);
	if(schema == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3589()->clone(ctx)->append(schemaName, ctx)->append(ConstStr::getCNST_STR_1125(), ctx), ctx));
	}
	IDatabaseTable* table = schema->getTableStore(tableName, ctx);
	if(table == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3589()->clone(ctx)->append(schemaName, ctx)->append(ConstStr::getCNST_STR_953(), ctx)->append(tableName, ctx)->append(ConstStr::getCNST_STR_1125(), ctx), ctx));
	}
	AlinousCore* core = server->getCore(ctx);
	ISystemLog* log = core->getLogger(ctx);
	int maxLoop = values->size(ctx);
	long long nextOid = allocOids(server, fullName, maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = static_cast<ClientNetworkRecord*>(values->get(i, ctx));
		record->setOid(nextOid, ctx);
		nextOid ++ ;
		table->tcpInsertCommit(record, server->getWorkerThreadsPool(ctx), log, ctx);
	}
}
long long InsertStore::allocOids(RemoteTableStorageServer* server, TableFullNameKey* fullName, int allocNum, ThreadContext* ctx)
{
	MonitorAccess* monitorAccess = server->getMonitorAccess(ctx);
	StringBuilder* buff = (new(ctx) StringBuilder(64, ctx));
	buff->append(fullName->getSchema(ctx), ctx)->append(ConstStr::getCNST_STR_953(), ctx)->append(fullName->getTable(ctx), ctx);
	long long nextOid = monitorAccess->allocOids(buff->toString(ctx), allocNum, ctx);
	return nextOid;
}
void InsertStore::__cleanUp(ThreadContext* ctx){
}
}}}}}

