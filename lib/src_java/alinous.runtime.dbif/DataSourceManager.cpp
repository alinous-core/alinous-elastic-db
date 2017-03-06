#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/Nodes.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.system.config/DataSourceInfo.h"
#include "alinous.system.config/MailInfo.h"
#include "alinous.system.config/AlinousConfig.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.dbif/AlinousDatabaseHandler.h"
#include "alinous.runtime.dbif/DataSourceManager.h"

namespace alinous {namespace runtime {namespace dbif {





bool DataSourceManager::__init_done = __init_static_variables();
bool DataSourceManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DataSourceManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DataSourceManager::DataSourceManager(AlinousCore* core, ThreadContext* ctx) : IObject(ctx), drivers(GCUtils<HashMap<String,IDatabaseDriver> >::ins(this, (new(ctx) HashMap<String,IDatabaseDriver>(ctx)), ctx, __FILEW__, __LINE__, L"")), core(nullptr)
{
	__GC_MV(this, &(this->core), core, AlinousCore);
}
void DataSourceManager::__construct_impl(AlinousCore* core, ThreadContext* ctx)
{
	__GC_MV(this, &(this->core), core, AlinousCore);
}
 DataSourceManager::~DataSourceManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DataSourceManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DataSourceManager", L"~DataSourceManager");
	__e_obj1.add(this->drivers, this);
	drivers = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	if(!prepare){
		return;
	}
}
void DataSourceManager::init(ThreadContext* ctx)
{
	AlinousConfig* config = this->core->getConfig(ctx);
	AlinousDbInfo* adbInfo = config->getAlinousDb(ctx);
	Iterator<String>* it = adbInfo->idSet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* id = it->next(ctx);
		AlinousDbInstanceInfo* instanceConfig = adbInfo->getInstance(id, ctx);
		IDatabaseDriver* driver = this->drivers->get(id, ctx);
		if(driver != nullptr)
		{
			this->core->getLogger(ctx)->logWarning(ConstStr::getCNST_STR_1107()->clone(ctx)->append(id, ctx)->append(ConstStr::getCNST_STR_1108(), ctx), ctx);
			continue;
		}
		driver = (new(ctx) AlinousDatabaseHandler(instanceConfig, ctx));
		{
			try
			{
				driver->initDriver(this->core, instanceConfig, ctx);
			}
			catch(AlinousDbException* e)
			{
				ISystemLog* log = this->core->getLogger(ctx);
				log->logError(e, ctx);
				continue;
			}
		}
		this->drivers->put(id, driver, ctx);
	}
}
IDatabaseDriver* DataSourceManager::get(String* id, ThreadContext* ctx) throw() 
{
	return this->drivers->get(id, ctx);
}
void DataSourceManager::dispose(ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->drivers->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* id = it->next(ctx);
		IDatabaseDriver* driver = this->drivers->get(id, ctx);
		driver->dispose(ctx);
	}
	this->drivers->clear(ctx);
}
void DataSourceManager::__cleanUp(ThreadContext* ctx){
}
}}}

