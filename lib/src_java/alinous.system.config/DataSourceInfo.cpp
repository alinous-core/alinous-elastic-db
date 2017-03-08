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
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html/IReplacer.h"
#include "alinous.html/AlinousDomReplacer.h"
#include "alinous.html/DomConverter.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/Nodes.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.system.config/WebHandlerInfo.h"
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
#include "alinous.db.trx/DbTransaction.h"
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
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.system.config/ConfigPathUtils.h"

namespace alinous {namespace system {namespace config {





bool DataSourceInfo::__init_done = __init_static_variables();
bool DataSourceInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DataSourceInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DataSourceInfo::DataSourceInfo(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), connect(nullptr), user(nullptr), pass(nullptr), defaultAcid(IDatabaseDriver::READ_COMMITTED)
{
}
void DataSourceInfo::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DataSourceInfo::~DataSourceInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DataSourceInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DataSourceInfo", L"~DataSourceInfo");
	__e_obj1.add(this->connect, this);
	connect = nullptr;
	__e_obj1.add(this->user, this);
	user = nullptr;
	__e_obj1.add(this->pass, this);
	pass = nullptr;
	if(!prepare){
		return;
	}
}
String* DataSourceInfo::getConnect(ThreadContext* ctx) throw() 
{
	return connect;
}
void DataSourceInfo::setConnect(String* connect, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->connect), connect, String);
}
String* DataSourceInfo::getUser(ThreadContext* ctx) throw() 
{
	return user;
}
void DataSourceInfo::setUser(String* user, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->user), user, String);
}
String* DataSourceInfo::getPass(ThreadContext* ctx) throw() 
{
	return pass;
}
void DataSourceInfo::setPass(String* pass, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->pass), pass, String);
}
int DataSourceInfo::getDefaultAcid(ThreadContext* ctx) throw() 
{
	return defaultAcid;
}
void DataSourceInfo::setDefaultAcid(int defaultAcid, ThreadContext* ctx) throw() 
{
	this->defaultAcid = defaultAcid;
}
void DataSourceInfo::__cleanUp(ThreadContext* ctx){
}
}}}

