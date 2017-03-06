#include "include/global.h"


#include "alinous.btree/BTreeException.h"
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
#include "alinous.db.table/DatabaseException.h"
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
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.remote.region.client.command.data/ClientTableData.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.region/NodeRegionServer.h"
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
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/ITableRegion.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command/GetSchemaFromRegionCommand.h"
#include "alinous.remote.region.client.command.ddl/RegionCreateSchemaCommand.h"
#include "alinous.remote.region.client.command.ddl/RegionCreateTableCommand.h"
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





bool RemoteRegionRef::__init_done = __init_static_variables();
bool RemoteRegionRef::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteRegionRef", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteRegionRef::RemoteRegionRef(RegionRef* ref, ICommidIdPublisher* commitIdPublisher, ThreadContext* ctx) throw()  : IObject(ctx), ITableRegion(ctx), regionAccessPool(nullptr), url(nullptr), name(nullptr), info(nullptr), schemeLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), schemes(GCUtils<Map<String,RemoteTableScheme> >::ins(this, (new(ctx) HashMap<String,RemoteTableScheme>(ctx)), ctx, __FILEW__, __LINE__, L"")), schemeVersion(0)
{
	__GC_MV(this, &(this->url), ref->getUrl(ctx), String);
	__GC_MV(this, &(this->name), ref->getName(ctx), String);
}
void RemoteRegionRef::__construct_impl(RegionRef* ref, ICommidIdPublisher* commitIdPublisher, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->url), ref->getUrl(ctx), String);
	__GC_MV(this, &(this->name), ref->getName(ctx), String);
}
 RemoteRegionRef::~RemoteRegionRef() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteRegionRef::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteRegionRef", L"~RemoteRegionRef");
	__e_obj1.add(this->regionAccessPool, this);
	regionAccessPool = nullptr;
	__e_obj1.add(this->url, this);
	url = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->info, this);
	info = nullptr;
	__e_obj1.add(this->schemeLock, this);
	schemeLock = nullptr;
	__e_obj1.add(this->schemes, this);
	schemes = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteRegionRef::init(ThreadContext* ctx)
{
	initRegionServerAcess(ctx);
}
void RemoteRegionRef::dispose(ThreadContext* ctx) throw() 
{
	if(this->regionAccessPool != nullptr)
	{
		this->regionAccessPool->dispose(ctx);
	}
}
void RemoteRegionRef::syncSchemes(ThreadContext* ctx)
{
	GetSchemaFromRegionCommand* cmd = (new(ctx) GetSchemaFromRegionCommand(ctx));
	cmd->setSchemeVersion(this->schemeVersion, ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->regionAccessPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->regionAccessPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractNodeRegionCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractNodeRegionCommand::TYPE_GET_SCHEMA_FROM_REGION)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3598(), ctx));
			}
			cmd = static_cast<GetSchemaFromRegionCommand*>(retcmd);
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3599(), e, ctx));
		}
	}
	{
		SynchronizedBlockObj __synchronized_2(this->schemeLock, ctx);
		ClientStructureMetadata* data = cmd->getData(ctx);
		this->schemeVersion = cmd->getSchemeVersion(ctx);
		synschemeData(data, ctx);
	}
}
int RemoteRegionRef::getRegionType(ThreadContext* ctx) throw() 
{
	return ITableRegion::REMOTE_REGION;
}
String* RemoteRegionRef::getRegionName(ThreadContext* ctx) throw() 
{
	return this->name;
}
ITableSchema* RemoteRegionRef::getSchema(String* name, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->schemeLock, ctx);
		return this->schemes->get(name, ctx);
	}
}
void RemoteRegionRef::createSchema(String* schemaName, ThreadContext* ctx)
{
	ITableSchema* schema = getSchema(schemaName, ctx);
	if(schema != nullptr)
	{
		return;
	}
	RegionCreateSchemaCommand* cmd = (new(ctx) RegionCreateSchemaCommand(ctx));
	cmd->setSchemaName(schemaName, ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->regionAccessPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->regionAccessPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractNodeRegionCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractNodeRegionCommand::TYPE_CREATE_SCHEMA)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3598(), ctx));
			}
			syncSchemes(ctx);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3600(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3600(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3600(), e, ctx));
		}
	}
}
void RemoteRegionRef::createTable(String* schemaName, TableMetadata* tblMeta, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	RegionCreateTableCommand* cmd = (new(ctx) RegionCreateTableCommand(ctx));
	cmd->setMetadata(tblMeta, ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->regionAccessPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->regionAccessPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractNodeRegionCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractNodeRegionCommand::TYPE_CREATE_TABLE)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3601(), ctx));
			}
			syncSchemes(ctx);
		}
		catch(...){throw;}
	}
}
long long RemoteRegionRef::getSchemeVersion(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->schemeLock, ctx);
		return this->schemeVersion;
	}
}
void RemoteRegionRef::setSchemeVersion(long long schemeVersion, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->schemeLock, ctx);
		this->schemeVersion = schemeVersion;
	}
}
void RemoteRegionRef::initRegionServerAcess(ThreadContext* ctx)
{
	IArrayObject<String>* segs = this->url->split(ConstStr::getCNST_STR_381(), ctx);
	if(segs->length != 2)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3581(), ctx));
	}
	String* host = segs->get(0);
	int port = 0;
	{
		try
		{
			port = Integer::parseInt(segs->get(1), ctx);
		}
		catch(NumberFormatException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3582(), e, ctx));
		}
	}
	__GC_MV(this, &(this->info), (new(ctx) RegionConnectionInfo(host, port, ctx)), RegionConnectionInfo);
	RegionClientConnectionFactory* factory = (new(ctx) RegionClientConnectionFactory(info, ctx));
	__GC_MV(this, &(this->regionAccessPool), (new(ctx) SocketConnectionPool(factory, ctx)), SocketConnectionPool);
}
void RemoteRegionRef::synschemeData(ClientStructureMetadata* data, ThreadContext* ctx) throw() 
{
	Map<String,ClientSchemaData>* map = data->getMap(ctx);
	Iterator<String>* it = map->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* schemaName = it->next(ctx);
		ClientSchemaData* scdata = map->get(schemaName, ctx);
		RemoteTableScheme* schema = findOrCreateSchema(schemaName, ctx);
		schema->updateInfo(scdata, this->regionAccessPool, ctx);
	}
}
RemoteTableScheme* RemoteRegionRef::findOrCreateSchema(String* schemaName, ThreadContext* ctx) throw() 
{
	RemoteTableScheme* schema = this->schemes->get(schemaName, ctx);
	if(schema == nullptr)
	{
		schema = (new(ctx) RemoteTableScheme(schemaName, ctx));
		this->schemes->put(schemaName, schema, ctx);
	}
	return schema;
}
void RemoteRegionRef::__cleanUp(ThreadContext* ctx){
}
}}}}

