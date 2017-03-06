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
#include "alinous.db.table/DatabaseException.h"
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
#include "alinous.runtime.dom/DomArray.h"
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
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.btree.scan/BTreeScanner.h"
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
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db.trx/CreateIndexMetadata.h"
#include "alinous.remote.db.command.data/SchemaData.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.remote.region.client.transaction/AbstractRemoteClientTransaction.h"
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
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx/DbTransactionManager.h"
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
#include "alinous.system.config.remote/RegionRef.h"
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
#include "java.lang/Integer.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
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
#include "alinous.remote.region.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.command.data/ClientTableData.h"
#include "alinous.remote.region.command.data/ClientSchemaData.h"
#include "alinous.remote.region.command.data/ClientStructureMetadata.h"
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
#include "alinous.remote.region/RegionTpcExecutorPool.h"
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
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.db.trx/ReadCommittedTransaction.h"
#include "alinous.db.trx/RepeatableReadTransaction.h"
#include "alinous.db.trx/SerializableTransaction.h"
#include "alinous.db.trx/DbTransactionFactory.h"

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
 DbTransaction::DbTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw()  : IObject(ctx), lockContext(nullptr), commitId(0), trxManager(nullptr), trxSchema(nullptr), trxStorageManager(nullptr), database(nullptr), logger(nullptr), subTransaction(nullptr), uniqueExclusiveLock(nullptr), resultSerial(0), trxDir(nullptr), vctx(nullptr), soidSerial(0), core(nullptr)
{
	__GC_MV(this, &(this->trxManager), mgr, DbTransactionManager);
	__GC_MV(this, &(this->trxSchema), (new(ctx) TrxSchemeManager(database, core->getLogger(ctx), ctx)), TrxSchemeManager);
	__GC_MV(this, &(this->trxStorageManager), (new(ctx) TrxStorageManager(tmpDir, this, ctx)), TrxStorageManager);
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->logger), core->getLogger(ctx), ISystemLog);
	this->commitId = commitId;
	__GC_MV(this, &(this->lockContext), database->newLockContext(ctx), TrxLockContext);
	__GC_MV(this, &(this->uniqueExclusiveLock), database->newUniqueExclusiveLockClient(ctx), UniqueExclusiveLockClient);
	this->resultSerial = 1;
	__GC_MV(this, &(this->trxDir), tmpDir, String);
	this->soidSerial = 1;
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
}
void DbTransaction::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->trxManager), mgr, DbTransactionManager);
	__GC_MV(this, &(this->trxSchema), (new(ctx) TrxSchemeManager(database, core->getLogger(ctx), ctx)), TrxSchemeManager);
	__GC_MV(this, &(this->trxStorageManager), (new(ctx) TrxStorageManager(tmpDir, this, ctx)), TrxStorageManager);
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->logger), core->getLogger(ctx), ISystemLog);
	this->commitId = commitId;
	__GC_MV(this, &(this->lockContext), database->newLockContext(ctx), TrxLockContext);
	__GC_MV(this, &(this->uniqueExclusiveLock), database->newUniqueExclusiveLockClient(ctx), UniqueExclusiveLockClient);
	this->resultSerial = 1;
	__GC_MV(this, &(this->trxDir), tmpDir, String);
	this->soidSerial = 1;
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
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
	__e_obj1.add(this->uniqueExclusiveLock, this);
	uniqueExclusiveLock = nullptr;
	__e_obj1.add(this->trxDir, this);
	trxDir = nullptr;
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	if(!prepare){
		return;
	}
}
bool DbTransaction::isRemote(ThreadContext* ctx) throw() 
{
	return false;
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
	IDatabaseTable* tableStore = this->database->getTable(tableName, ConstStr::getCNST_STR_955(), ctx);
	{
		try
		{
			this->lockContext->shareLockTable(tableStore, ctx);
		}
		catch(DatabaseLockException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1710()->clone(ctx)->append(tableName->toString(ctx), ctx), e, ctx));
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
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1711(), e, ctx));
		}
		catch(BTreeException* e)
		{
			e->printStackTrace(ctx);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1711(), e, ctx));
		}
	}
}
void DbTransaction::createTable(TableSchema* schema, ThreadContext* ctx)
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
		this->trxSchema->executeCommit(this->core, this->database->getBtreeCache(ctx), ctx);
		this->trxSchema->reset(ctx);
	}
	commitUpdateInsert(newCommitId, ctx);
}
void DbTransaction::close(ThreadContext* ctx)
{
	if(this->subTransaction != nullptr)
	{
		this->subTransaction->close(ctx);
	}
	this->uniqueExclusiveLock->reset(ctx);
	this->trxSchema->reset(ctx);
	this->trxStorageManager->reset(ctx);
	this->lockContext->reset(ctx);
	this->trxManager->returnTransaction(this, ctx);
}
void DbTransaction::dispose(ThreadContext* ctx) throw() 
{
	this->uniqueExclusiveLock->dispose(ctx);
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
DbVersionContext* DbTransaction::getVersionContext(ThreadContext* ctx) throw() 
{
	return this->vctx;
}
UniqueExclusiveLockClient* DbTransaction::getUniqueExclusiveLock(ThreadContext* ctx) throw() 
{
	return uniqueExclusiveLock;
}
void DbTransaction::commitUpdateInsert(long long newCommitId, ThreadContext* ctx)
{
	if(this->trxStorageManager->isHasOperation(ctx))
	{
		{
			try
			{
				this->trxStorageManager->commitLocal(newCommitId, ctx);
			}
			catch(IOException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1712(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1712(), e, ctx));
			}
			catch(VariableException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1712(), e, ctx));
			}
			catch(BTreeException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1712(), e, ctx));
			}
		}
		this->trxStorageManager->reset(ctx);
	}
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

