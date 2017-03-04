#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.buffer/FifoList.h"
#include "java.util/BitSet.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.lock/LockObject.h"
#include "java.util/Random.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigInteger.h"
#include "alinous.numeric/RoundingMode.h"
#include "alinous.numeric/MathContext.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.analyse/SourceValidationError.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/TypedVariableDeclareSource.h"
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.variant/IVariantData.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileAccessWrapper.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree/AbstractBTreeLeafContainer.h"
#include "alinous.btree/BTreeLeafContainer.h"
#include "alinous.btree/BTreeMaxLeafContainer.h"
#include "alinous.btree/BTreeValues.h"
#include "alinous.btree/KeyValue.h"
#include "alinous.btree/BTreeLeafNode.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IntKey.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.table/LocalOidCounter.h"
#include "alinous.db.table/LocalOidPublisher.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system.utils/FileUtils.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.btree/LongKey.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.remote.db.command.data/StorageNodeData.h"
#include "alinous.remote.db.command.data/TableClusterData.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.lock.unique/ColumnsUniqueCollections.h"
#include "alinous.lock.unique/TableUniqueCollections.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db.trx/CreateIndexMetadata.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.remote.db.command.data/SchemaData.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.lock.unique/UniqueLockClientFactory.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.remote.monitor.client/MonitorConnectionInfo.h"
#include "alinous.remote.monitor.client/RemoteCommitIdPublisher.h"
#include "alinous.remote.region.command.data/ClientTableData.h"
#include "alinous.remote.region.command.data/ClientSchemaData.h"
#include "alinous.remote.region.command.data/ClientStructureMetadata.h"
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.remote.region.client/RegionConnectionInfo.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.remote.region.command.data/ClientNetworkRecord.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.region.client/DatabaseTableClient.h"
#include "alinous.remote.region.client/RemoteTableScheme.h"
#include "alinous.remote.region.client/RemoteRegionRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.db/MonitorAccess.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.system.config.remote/RemoteNodeReference.h"
#include "alinous.system.config.remote/Region.h"
#include "alinous.remote.monitor/NodeInfo.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.monitor.command.data/RegionInfoData.h"
#include "alinous.system.config.remote/Regions.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.remote.monitor/RegionNodeInfoManager.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.remote.region/NodeReference.h"
#include "alinous.remote.region/NodeCluster.h"
#include "alinous.remote.region/NodeTableReference.h"
#include "alinous.remote.region/NodeTableClaster.h"
#include "alinous.remote.region/NodeRegionSchema.h"
#include "alinous.remote.region/RegionShardPart.h"
#include "alinous.remote.region/RegionShardTable.h"
#include "alinous.remote.region/NodeReferenceManager.h"
#include "java.lang/Long.h"
#include "alinous.remote.region/RegionInsertExecutor.h"
#include "alinous.remote.region/RegionInsertExecutorPool.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.runtime.dbif/DataSourceManager.h"
#include "alinous.runtime.engine.debugger.server/ServerBreakPoint.h"
#include "alinous.runtime.engine.debugger.server/FileBreakpointContainer.h"
#include "alinous.runtime.engine.debugger/DebugStackFrame.h"
#include "alinous.runtime.engine.debugger/DebugThread.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEvent.h"
#include "alinous.runtime.engine.debugger.server/IDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/IServerCommand.h"
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEventNotifier.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.web.htmlxml.inner/IHtmlStringPart.h"
#include "alinous.web.parse.htmlxml/Token.h"
#include "alinous.web.htmlxml/AbstractXHtmlElement.h"
#include "alinous.web.htmlxml/AbstractXHtmlAttributeValue.h"
#include "alinous.web.htmlxml/XHtmlAttribute.h"
#include "alinous.web.htmlxml/XMLTagBase.h"
#include "alinous.web.htmlxml.module/AbstractSerializedHtmlPart.h"
#include "alinous.web.htmlxml.module/SerializeContext.h"
#include "alinous.web.htmlxml/HtmlDocType.h"
#include "alinous.web.htmlxml/HtmlTopObject.h"
#include "alinous.web.htmlxml.module/AlinousWebHtmlXmlModule.h"
#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.server.webmodule/AbstractWebModule.h"
#include "alinous.server.webmodule/WebModuleList.h"
#include "alinous.server.webmodule/WebModuleHashList.h"
#include "alinous.server.webmodule/WebModuleManager.h"
#include "alinous.system.config.remote/Table.h"
#include "alinous.system.config.remote/Tables.h"
#include "alinous.system.config.remote/Node.h"
#include "alinous.system.config.remote/Nodes.h"
#include "alinous.system.config/DataSourceInfo.h"
#include "alinous.system.config/MailInfo.h"
#include "alinous.system.config/AlinousConfig.h"
#include "alinous.runtime.function/IAlinousNativeFunction.h"
#include "alinous.runtime.function/AlinousNativeFunctionRegistory.h"
#include "alinous.system.functions/NativeFunctionManager.h"
#include "alinous.system.functions/AlinousFunctionManager.h"
#include "alinous.system/AlinousCoreLogger.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/ExpressionStreamBuffer.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/ClassDeclareHolder.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.buffer/HashArrayListIterator.h"
#include "alinous.buffer/HashArrayList.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"

namespace alinous {namespace db {





const IntKey AlinousDatabase:: __SCHEMA = (IntKey(10, nullptr));
const IntKey AlinousDatabase:: __USERS = (IntKey(20, nullptr));
const IntKey AlinousDatabase:: __MAX_COMMIT_ID = (IntKey(30, nullptr));
const IntKey AlinousDatabase:: __MAX_OID_ID = (IntKey(40, nullptr));
bool AlinousDatabase::__init_done = __init_static_variables();
bool AlinousDatabase::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDatabase", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDatabase::AlinousDatabase(ThreadContext* ctx) throw()  : IObject(ctx), instanceConfigLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), trxManager(nullptr), trxLockManager(nullptr), commitIdPublisher(nullptr), workerThreadsPool(nullptr), core(nullptr), remote(false), dataDir(nullptr), dbconfig(nullptr), configFile(nullptr), oidPublisher(nullptr), trxWriterThread(nullptr), btreeCache(nullptr), regionManager(nullptr), uniqueExclusiveLockManager(nullptr)
{
	__GC_MV(this, &(this->trxWriterThread), nullptr, AlinousThread);
	__GC_MV(this, &(this->workerThreadsPool), nullptr, ThreadPool);
	__GC_MV(this, &(this->commitIdPublisher), (new(ctx) LocalCommitIdPublisher(this, ctx)), ICommidIdPublisher);
}
void AlinousDatabase::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->trxWriterThread), nullptr, AlinousThread);
	__GC_MV(this, &(this->workerThreadsPool), nullptr, ThreadPool);
	__GC_MV(this, &(this->commitIdPublisher), (new(ctx) LocalCommitIdPublisher(this, ctx)), ICommidIdPublisher);
}
 AlinousDatabase::~AlinousDatabase() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDatabase::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDatabase", L"~AlinousDatabase");
	__e_obj1.add(this->instanceConfigLock, this);
	instanceConfigLock = nullptr;
	__e_obj1.add(this->trxManager, this);
	trxManager = nullptr;
	__e_obj1.add(this->trxLockManager, this);
	trxLockManager = nullptr;
	__e_obj1.add(this->commitIdPublisher, this);
	commitIdPublisher = nullptr;
	__e_obj1.add(this->workerThreadsPool, this);
	workerThreadsPool = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->dataDir, this);
	dataDir = nullptr;
	__e_obj1.add(this->dbconfig, this);
	dbconfig = nullptr;
	__e_obj1.add(this->configFile, this);
	configFile = nullptr;
	__e_obj1.add(this->oidPublisher, this);
	oidPublisher = nullptr;
	__e_obj1.add(this->trxWriterThread, this);
	trxWriterThread = nullptr;
	__e_obj1.add(this->btreeCache, this);
	btreeCache = nullptr;
	__e_obj1.add(this->regionManager, this);
	regionManager = nullptr;
	__e_obj1.add(this->uniqueExclusiveLockManager, this);
	uniqueExclusiveLockManager = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousDatabase::construct(AlinousCore* core, String* dataDir, String* trxTmpDir, int maxConnection, ThreadContext* ctx)
{
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->dataDir), dataDir, String);
	__GC_MV(this, &(this->workerThreadsPool), (new(ctx) ThreadPool(16, ConstStr::getCNST_STR_1669(), ctx)), ThreadPool);
	__GC_MV(this, &(this->trxManager), (new(ctx) DbTransactionManager(this, trxTmpDir, maxConnection, core, this->workerThreadsPool, ctx)), DbTransactionManager);
	File* file = getConfigFile(ctx);
	{
		try
		{
			__GC_MV(this, &(this->btreeCache), (new(ctx) BTreeGlobalCache(ctx))->init(1024, ctx), BTreeGlobalCache);
			__GC_MV(this, &(this->dbconfig), (new(ctx) BTree(ctx))->init(file, this->btreeCache, core->diskCache, ctx), BTree);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1670(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1670(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1670(), e, ctx));
		}
	}
}
TrxLockContext* AlinousDatabase::newLockContext(ThreadContext* ctx) throw() 
{
	return this->trxLockManager->newLockContext(ctx);
}
void AlinousDatabase::initInstance(AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx)
{
	File* file = (new(ctx) File(this->dataDir, ctx));
	if(!file->exists(ctx))
	{
		file->mkdirs(ctx);
	}
	__GC_MV(this, &(this->commitIdPublisher), (new(ctx) LocalCommitIdPublisher(this, ctx)), ICommidIdPublisher);
	__GC_MV(this, &(this->oidPublisher), (new(ctx) LocalOidPublisher(ctx)), IOidPublisher);
	LocalTableRegion* localRegion = (new(ctx) LocalTableRegion(dataDir, this->core->getLogger(ctx), nullptr, core, this->btreeCache, static_cast<LocalCommitIdPublisher*>(this->commitIdPublisher), ctx));
	SchemaManager* schemas = localRegion->getSchemaManager(ctx);
	schemas->createSchema(ConstStr::getCNST_STR_955(), ctx);
	{
		try
		{
			int BLOCK_SIZE = 256;
			int nodeCapacity = 8;
			long long capacity = 1024;
			this->dbconfig->initTreeStorage(nodeCapacity, IBTreeKey::TYPE_INT, IBTreeKey::TYPE_INT, capacity, (long long)BLOCK_SIZE, ctx);
			this->dbconfig->open(ctx);
			this->dbconfig->putKeyValue(SCHEMA, schemas, ctx);
			LongValue* lvTrx = (new(ctx) LongValue(this->commitIdPublisher->getMaxCommitId(ctx), ctx));
			this->dbconfig->putKeyValue(MAX_COMMIT_ID, lvTrx, ctx);
			this->dbconfig->putKeyValue(MAX_OID_ID, static_cast<LocalOidPublisher*>(this->oidPublisher), ctx);
			this->dbconfig->close(ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1671(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1671(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1671(), e, ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1671(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1671(), e, ctx));
		}
	}
}
long long AlinousDatabase::getCommitId(ThreadContext* ctx)
{
	{
		try
		{
			return this->commitIdPublisher->getMaxCommitId(ctx);
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1672(), e, ctx));
		}
	}
}
long long AlinousDatabase::newCommitId(ThreadContext* ctx)
{
	{
		try
		{
			return this->commitIdPublisher->newCommitId(ctx);
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1673(), e, ctx));
		}
	}
}
UniqueExclusiveLockClient* AlinousDatabase::newUniqueExclusiveLockClient(ThreadContext* ctx) throw() 
{
	return UniqueLockClientFactory::createClient(this->uniqueExclusiveLockManager, ctx);
}
DbVersionContext* AlinousDatabase::newTransactionContext(ThreadContext* ctx)
{
	{
		try
		{
			return this->commitIdPublisher->newTransactionContext(ctx);
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1673(), e, ctx));
		}
	}
}
void AlinousDatabase::syncScheme(ThreadContext* ctx)
{
	LocalTableRegion* localRegion = this->regionManager->getLocalRegion(ctx);
	if(localRegion == nullptr)
	{
		return;
	}
	SchemaManager* schemas = localRegion->getSchemaManager(ctx);
	IBTreeNode* lvTrxIdNode = nullptr;
	{
		try
		{
			this->dbconfig->open(ctx);
			this->dbconfig->putKeyValue(SCHEMA, schemas, ctx);
			lvTrxIdNode = this->dbconfig->findByKey(MAX_COMMIT_ID, ctx);
			ArrayList<IBTreeValue>* trxvals = lvTrxIdNode->getValues(ctx);
			if(trxvals->size(ctx) > 0)
			{
				trxvals->clear(ctx);
				trxvals->add((new(ctx) LongValue(this->commitIdPublisher->getMaxCommitId(ctx), ctx)), ctx);
				lvTrxIdNode->save(ctx);
			}
						else 
			{
				LongValue* lvTrx = (new(ctx) LongValue(this->commitIdPublisher->getMaxCommitId(ctx), ctx));
				this->dbconfig->putKeyValue(MAX_COMMIT_ID, lvTrx, ctx);
			}
			lvTrxIdNode = this->dbconfig->findByKey(MAX_OID_ID, ctx);
			trxvals = lvTrxIdNode->getValues(ctx);
			trxvals->clear(ctx);
			trxvals->add(static_cast<LocalOidPublisher*>(this->oidPublisher), ctx);
			lvTrxIdNode->save(ctx);
			this->dbconfig->close(ctx);
		}
		catch(Throwable* e)
		{
			{
				try
				{
					if(lvTrxIdNode != nullptr)
					{
						lvTrxIdNode->endUse(ctx);
					}
				}
				catch(InterruptedException* e2)
				{
					e->printStackTrace(ctx);
					this->core->getLogger(ctx)->logError(e2, ctx);
				}
			}
			e->printStackTrace(ctx);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1674(), e, ctx));
		}
	}
	{
		try
		{
			lvTrxIdNode->endUse(ctx);
		}
		catch(InterruptedException* e)
		{
			e->printStackTrace(ctx);
			this->core->getLogger(ctx)->logError(e, ctx);
		}
	}
}
void AlinousDatabase::open(AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx)
{
	LaunchJoin* trxLaunchJoin = (new(ctx) LaunchJoin(1, ctx));
	__GC_MV(this, &(this->trxWriterThread), (new(ctx) AlinousThread(trxLaunchJoin, ctx)), AlinousThread);
	{
		try
		{
			trxLaunchJoin->parentJoin(ctx);
		}
		catch(InterruptedException* e)
		{
			this->workerThreadsPool->dispose(ctx);
			__GC_MV(this, &(this->workerThreadsPool), nullptr, ThreadPool);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1676(), e, ctx));
		}
	}
	MonitorRef* monitorRef = instanceConfig->getMonitorRef(ctx);
	if(monitorRef != nullptr)
	{
		__GC_MV(this, &(this->commitIdPublisher), (new(ctx) RemoteCommitIdPublisher(monitorRef, ctx))->init(ctx), ICommidIdPublisher);
		this->remote = true;
	}
		else 
	{
		__GC_MV(this, &(this->commitIdPublisher), (new(ctx) LocalCommitIdPublisher(this, ctx)), ICommidIdPublisher);
		this->remote = false;
	}
	__GC_MV(this, &(this->trxLockManager), (new(ctx) TrxLockManager(ctx)), TrxLockManager);
	__GC_MV(this, &(this->regionManager), (new(ctx) TableRegionManager(ctx)), TableRegionManager);
	__GC_MV(this, &(this->uniqueExclusiveLockManager), (new(ctx) UniqueExclusiveLockManager(ctx)), UniqueExclusiveLockManager);
	if(!isRemote(ctx))
	{
		openLocal(ctx);
	}
		else 
	{
		{
			try
			{
				openRegions(instanceConfig, ctx);
			}
			catch(UnknownHostException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1677(), e, ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1677(), e, ctx));
			}
		}
	}
}
TableSchemaCollection* AlinousDatabase::getSchema(String* name, ThreadContext* ctx) throw() 
{
	return this->regionManager->getSchema(name, ctx);
}
IDatabaseTable* AlinousDatabase::getTable(AlinousName* tableName, String* currentSchema, ThreadContext* ctx) throw() 
{
	ArrayList<String>* segs = tableName->getSegments(ctx);
	int size = segs->size(ctx);
	if(size == 1)
	{
		return getTable(currentSchema, segs->get(0, ctx), ctx);
	}
	return getTable(segs->get(0, ctx), segs->get(1, ctx), ctx);
}
IDatabaseTable* AlinousDatabase::getTable(String* schemaName, String* tableName, ThreadContext* ctx) throw() 
{
	TableSchemaCollection* sc = this->regionManager->getSchema(schemaName, ctx);
	return sc->getTableStore(tableName, ctx);
}
void AlinousDatabase::closeDatabase(ThreadContext* ctx) throw() 
{
	{
		try
		{
			{
				SynchronizedBlockObj __synchronized_3(instanceConfigLock, ctx);
				syncScheme(ctx);
			}
		}
		catch(AlinousDbException* e)
		{
			this->core->getLogger(ctx)->logError(e, ctx);
		}
	}
	if(this->trxManager != nullptr)
	{
		this->trxManager->dispose(ctx);
		__GC_MV(this, &(this->trxManager), nullptr, DbTransactionManager);
	}
	if(this->workerThreadsPool != nullptr)
	{
		this->workerThreadsPool->dispose(ctx);
		__GC_MV(this, &(this->workerThreadsPool), nullptr, ThreadPool);
	}
	if(this->trxWriterThread != nullptr)
	{
		this->trxWriterThread->shutdown(ctx);
		__GC_MV(this, &(this->trxWriterThread), nullptr, AlinousThread);
	}
	this->regionManager->dispose(ctx);
	this->commitIdPublisher->dispose(ctx);
}
AlinousDbConnection* AlinousDatabase::connect(ConnectInfo* info, ThreadContext* ctx) throw() 
{
	AlinousDbConnection* con = (new(ctx) AlinousDbConnection(this, info, ctx));
	return con;
}
void AlinousDatabase::disConnect(AlinousDbConnection* con, ThreadContext* ctx) throw() 
{
}
void AlinousDatabase::dropInstance(ThreadContext* ctx) throw() 
{
	File* file = (new(ctx) File(this->dataDir, ctx));
	if(file->exists(ctx))
	{
		FileUtils::removeAll(file, ctx);
	}
}
bool AlinousDatabase::exists(ThreadContext* ctx) throw() 
{
	File* file = getConfigFile(ctx);
	return file->exists(ctx);
}
AlinousCore* AlinousDatabase::getCore(ThreadContext* ctx) throw() 
{
	return core;
}
BTreeGlobalCache* AlinousDatabase::getBtreeCache(ThreadContext* ctx) throw() 
{
	return btreeCache;
}
TableRegionManager* AlinousDatabase::getRegionManager(ThreadContext* ctx) throw() 
{
	return regionManager;
}
bool AlinousDatabase::isRemote(ThreadContext* ctx) throw() 
{
	return remote;
}
void AlinousDatabase::syncSchemaVersion(DbVersionContext* vctx, ThreadContext* ctx)
{
	{
		try
		{
			this->regionManager->syncSchemaVersion(vctx, ctx);
		}
		catch(UnknownHostException* e)
		{
			(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1680(), e, ctx));
		}
		catch(IOException* e)
		{
			(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1680(), e, ctx));
		}
	}
}
IOidPublisher* AlinousDatabase::getOidPublisher(ThreadContext* ctx) throw() 
{
	return oidPublisher;
}
File* AlinousDatabase::getConfigFile(ThreadContext* ctx) throw() 
{
	if(this->configFile == nullptr)
	{
		String* pathname = this->dataDir->clone(ctx)->append(ConstStr::getCNST_STR_1675(), ctx);
		__GC_MV(this, &(this->configFile), (new(ctx) File(pathname, ctx)), File);
	}
	return this->configFile;
}
void AlinousDatabase::openLocal(ThreadContext* ctx)
{
	{
		try
		{
			this->dbconfig->open(ctx);
			ArrayList<IBTreeValue>* schemeValue = this->dbconfig->getValues(SCHEMA, ctx);
			if(schemeValue->size(ctx) > 0)
			{
				LocalTableRegion* localRegion = (new(ctx) LocalTableRegion(dataDir, this->core->getLogger(ctx), this->workerThreadsPool, core, this->btreeCache, static_cast<LocalCommitIdPublisher*>(this->commitIdPublisher), ctx));
				this->regionManager->addRegion(localRegion, ctx);
				SchemaManager* schemas = static_cast<SchemaManager*>(schemeValue->get(0, ctx));
				schemas->loadAfterFetch(this->dataDir, this->core->getLogger(ctx), this->workerThreadsPool, this->core, this->btreeCache, ctx);
				localRegion->setSchemaManager(schemas, ctx);
			}
			ArrayList<IBTreeValue>* lvTrxIds = this->dbconfig->getValues(MAX_COMMIT_ID, ctx);
			this->commitIdPublisher->setMaxCommitId((static_cast<LongValue*>(lvTrxIds->get(0, ctx)))->value, ctx);
			lvTrxIds = this->dbconfig->getValues(MAX_OID_ID, ctx);
			if(lvTrxIds == nullptr || lvTrxIds->size(ctx) == 0)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1678(), ctx));
			}
			__GC_MV(this, &(this->oidPublisher), static_cast<IOidPublisher*>(lvTrxIds->get(0, ctx)), IOidPublisher);
		}
		catch(Throwable* e)
		{
			{
				try
				{
					this->dbconfig->close(ctx);
				}
				catch(IOException* e2)
				{
					throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1679(), e2, ctx));
				}
				catch(InterruptedException* e2)
				{
					throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1679(), e2, ctx));
				}
			}
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1679(), e, ctx));
		}
	}
}
void AlinousDatabase::openRegions(AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx)
{
	RegionsRef* refs = instanceConfig->getRegionsRef(ctx);
	if(refs == nullptr)
	{
		LocalTableRegion* localRegion = (new(ctx) LocalTableRegion(dataDir, this->core->getLogger(ctx), this->workerThreadsPool, core, this->btreeCache, static_cast<LocalCommitIdPublisher*>(this->commitIdPublisher), ctx));
		this->regionManager->addRegion(localRegion, ctx);
		return;
	}
	List<RegionRef>* list = refs->getList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		RegionRef* ref = list->get(i, ctx);
		RemoteRegionRef* region = (new(ctx) RemoteRegionRef(ref, this->commitIdPublisher, ctx));
		region->init(ctx);
		this->regionManager->addRegion(region, ctx);
	}
	List<ITableRegion>* regions = this->regionManager->getRegions(ctx);
	maxLoop = regions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITableRegion* reg = regions->get(i, ctx);
		reg->syncSchemes(ctx);
	}
}
}}

