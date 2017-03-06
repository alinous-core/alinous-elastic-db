#include "include/global.h"


#include "alinous.lock/LockObject.h"
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
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
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
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.btree/BTree.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.remote.region.client.command.data/ClientTableData.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.remote.region.client/RegionConnectionInfo.h"
#include "alinous.remote.region.client/RegionConnection.h"
#include "alinous.remote.region.client/RegionClientConnectionFactory.h"
#include "alinous.remote.region.client/RemoteTableScheme.h"
#include "alinous.remote.region.client/RemoteRegionRef.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.btree/LongKey.h"
#include "alinous.btreememory/BTreeOnMemory.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.region.client/DatabaseTableClient.h"
#include "alinous.remote.region.client/RemoteClientTrxRecordsCache.h"

namespace alinous {namespace remote {namespace region {namespace client {





bool RemoteTableScheme::__init_done = __init_static_variables();
bool RemoteTableScheme::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableScheme", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableScheme::RemoteTableScheme(String* name, ThreadContext* ctx) throw()  : IObject(ctx), ITableSchema(ctx), name(nullptr), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), tables(GCUtils<Map<String,DatabaseTableClient> >::ins(this, (new(ctx) HashMap<String,DatabaseTableClient>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->name), name, String);
}
void RemoteTableScheme::__construct_impl(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
 RemoteTableScheme::~RemoteTableScheme() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableScheme::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteTableScheme", L"~RemoteTableScheme");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteTableScheme::updateInfo(ClientSchemaData* scdata, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		Map<String,ClientTableData>* map = scdata->getMap(ctx);
		doUpdateInfo(map, regionAccessPool, ctx);
	}
}
IDatabaseTable* RemoteTableScheme::getTableStore(String* tableName, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		return this->tables->get(tableName, ctx);
	}
}
String* RemoteTableScheme::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void RemoteTableScheme::doUpdateInfo(Map<String,ClientTableData>* map, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() 
{
	Iterator<String>* it = map->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		ClientTableData* tableData = map->get(tableName, ctx);
		DatabaseTableClient* table = getOrInitDatabaseTableClient(tableName, tableData, regionAccessPool, ctx);
		table->updateMetadata(tableData->getMetadata(ctx), ctx);
	}
	ArrayList<String>* delList = (new(ctx) ArrayList<String>(ctx));
	it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		DatabaseTableClient* table = this->tables->get(tableName, ctx);
		if(table == nullptr)
		{
			delList->add(tableName, ctx);
		}
	}
	int maxLoop = delList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* tableName = delList->get(i, ctx);
		this->tables->remove(tableName, ctx);
	}
}
DatabaseTableClient* RemoteTableScheme::getOrInitDatabaseTableClient(String* tableName, ClientTableData* tableData, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() 
{
	DatabaseTableClient* client = this->tables->get(tableName, ctx);
	if(client == nullptr)
	{
		client = (new(ctx) DatabaseTableClient(this->name, tableName, tableData->getMetadata(ctx), regionAccessPool, ctx));
		this->tables->put(tableName, client, ctx);
	}
	return client;
}
void RemoteTableScheme::__cleanUp(ThreadContext* ctx){
}
}}}}

