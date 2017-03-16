#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.lock/LockObject.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.system/AlinousCore.h"
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
#include "alinous.remote.region.client/RegionClientConnectionFactory.h"
#include "alinous.remote.region.client/RemoteTableScheme.h"
#include "alinous.remote.region.client/RemoteRegionRef.h"

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
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3596(), ctx));
			}
			cmd = static_cast<GetSchemaFromRegionCommand*>(retcmd);
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3597(), e, ctx));
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
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3596(), ctx));
			}
			syncSchemes(ctx);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3598(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3598(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3598(), e, ctx));
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
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3599(), ctx));
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
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3578(), ctx));
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
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3579(), e, ctx));
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

