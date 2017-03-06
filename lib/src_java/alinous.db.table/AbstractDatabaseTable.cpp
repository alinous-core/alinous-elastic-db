#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileAccessWrapper.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
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
#include "alinous.btree/BTreeException.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.buffer/FifoList.h"
#include "java.util/BitSet.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
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
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.buffer/HashArrayListIterator.h"
#include "alinous.buffer/HashArrayList.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/IntKey.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.btree/IBTree.h"
#include "alinous.compile.sql/ISqlStatement.h"
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
#include "alinous.db.table/IOidPublisher.h"
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
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db.trx/CreateIndexMetadata.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableIndexValue.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table/IndexInsertJob.h"
#include "alinous.db.table/OidIndexJob.h"
#include "alinous.db.table.cache/DbRecordHashArray.h"
#include "alinous.db.table.cache/DbREcordHashListIterator.h"
#include "alinous.db.table.cache/DbRecordHashMainList.h"
#include "alinous.db.table.cache/DbRecordCache.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table.lockmonitor.db/RowLockManager.h"
#include "alinous.db.table.lockmonitor.db/RowLockManagerList.h"
#include "alinous.db.table.lockmonitor.db/RowLockDb.h"
#include "alinous.db.table.lockmonitor.db/TableLockMamager.h"
#include "alinous.db.table.lockmonitor.db/TableLockManagerList.h"
#include "alinous.db.table.lockmonitor.db/TableLockHashDb.h"
#include "alinous.db.table.lockmonitor/DBThreadMonitor.h"
#include "alinous.db.table/DatabaseTable.h"
#include "alinous.remote.db.command.data/SchemaData.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx/DbTransactionManager.h"
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
#include "alinous.db/ITableRegion.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.table/DatatableConstants.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.table/LocalOidCounter.h"
#include "alinous.db.table/LocalOidPublisher.h"
#include "alinous.db.trx/TrxLockManager.h"
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
#include "alinous.btree/BTree.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/OidPublisherFactory.h"

namespace alinous {namespace db {namespace table {





bool AbstractDatabaseTable::__init_done = __init_static_variables();
bool AbstractDatabaseTable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractDatabaseTable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractDatabaseTable::AbstractDatabaseTable(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseTable(ctx), tableId(nullptr), metadata(nullptr), indexes(GCUtils<ArrayList<IScannableIndex> >::ins(this, (new(ctx) ArrayList<IScannableIndex>(ctx)), ctx, __FILEW__, __LINE__, L"")), primaryIndex(nullptr), name(nullptr), baseDir(nullptr), oidIndexPath(nullptr), dataStoragePath(nullptr), oidIndex(nullptr), dataStorage(nullptr), storageLock(nullptr), schmeUpdated(nullptr), updateHistoryCache(nullptr), fullName(nullptr)
{
	__GC_MV(this, &(this->tableId), (new(ctx) Integer(DatabaseTableIdPublisher::getId(name, ctx), ctx)), Integer);
	__GC_MV(this, &(this->metadata), (new(ctx) TableMetadata(schema, name, ctx)), TableMetadata);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	__GC_MV(this, &(this->oidIndex), nullptr, BTree);
	getDataStorageName(ctx);
	getOidIndexName(ctx);
	__GC_MV(this, &(this->storageLock), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
	__GC_MV(this, &(this->schmeUpdated), (new(ctx) Timestamp(System::currentTimeMillis(ctx), ctx)), Timestamp);
	__GC_MV(this, &(this->updateHistoryCache), nullptr, DatatableUpdateCache);
	__GC_MV(this, &(this->fullName), schema->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(name, ctx), String);
}
void AbstractDatabaseTable::__construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableId), (new(ctx) Integer(DatabaseTableIdPublisher::getId(name, ctx), ctx)), Integer);
	__GC_MV(this, &(this->metadata), (new(ctx) TableMetadata(schema, name, ctx)), TableMetadata);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	__GC_MV(this, &(this->oidIndex), nullptr, BTree);
	getDataStorageName(ctx);
	getOidIndexName(ctx);
	__GC_MV(this, &(this->storageLock), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
	__GC_MV(this, &(this->schmeUpdated), (new(ctx) Timestamp(System::currentTimeMillis(ctx), ctx)), Timestamp);
	__GC_MV(this, &(this->updateHistoryCache), nullptr, DatatableUpdateCache);
	__GC_MV(this, &(this->fullName), schema->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(name, ctx), String);
}
 AbstractDatabaseTable::~AbstractDatabaseTable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractDatabaseTable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractDatabaseTable", L"~AbstractDatabaseTable");
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	__e_obj1.add(this->indexes, this);
	indexes = nullptr;
	__e_obj1.add(this->primaryIndex, this);
	primaryIndex = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->baseDir, this);
	baseDir = nullptr;
	__e_obj1.add(this->oidIndexPath, this);
	oidIndexPath = nullptr;
	__e_obj1.add(this->dataStoragePath, this);
	dataStoragePath = nullptr;
	__e_obj1.add(this->oidIndex, this);
	oidIndex = nullptr;
	__e_obj1.add(this->dataStorage, this);
	dataStorage = nullptr;
	__e_obj1.add(this->storageLock, this);
	storageLock = nullptr;
	__e_obj1.add(this->schmeUpdated, this);
	schmeUpdated = nullptr;
	__e_obj1.add(this->updateHistoryCache, this);
	updateHistoryCache = nullptr;
	__e_obj1.add(this->fullName, this);
	fullName = nullptr;
	if(!prepare){
		return;
	}
}
void AbstractDatabaseTable::open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	getDataStorageName(ctx);
	getOidIndexName(ctx);
	__GC_MV(this, &(this->dataStorage), (new(ctx) FileStorage(core->diskCache, (new(ctx) File(dataStoragePath, ctx)), ConstStr::getCNST_STR_1666(), ctx)), FileStorage);
	{
		try
		{
			__GC_MV(this, &(this->oidIndex), (new(ctx) BTree(ctx))->init((new(ctx) File(this->oidIndexPath, ctx)), cache, core->diskCache, ctx), BTree);
		}
		catch(Throwable* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1688(), e, ctx));
		}
	}
	__GC_MV(this, &(this->updateHistoryCache), (new(ctx) DatatableUpdateCache(this, ctx)), DatatableUpdateCache);
	open(true, core, cache, ctx);
}
void AbstractDatabaseTable::open(bool loadscheme, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	{
		try
		{
			this->dataStorage->open(ctx);
			this->oidIndex->open(ctx);
			this->updateHistoryCache->open(core, cache, ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) DatabaseException(e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseException(e, ctx));
		}
	}
	if(loadscheme)
	{
		{
			try
			{
				loadScheme(ctx);
			}
			catch(IOException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
			catch(AlinousDbException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
			catch(VariableException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
		}
	}
	{
		try
		{
			this->primaryIndex->open(core, cache, ctx);
			int maxLoop = this->indexes->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IScannableIndex* index = this->indexes->get(i, ctx);
				index->open(core, cache, ctx);
			}
		}
		catch(IOException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1697(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1697(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1697(), e, ctx));
		}
	}
}
void AbstractDatabaseTable::close(ThreadContext* ctx) throw() 
{
	{
		try
		{
			syncScheme(ctx);
		}
		catch(VariableException* e1)
		{
			e1->printStackTrace(ctx);
		}
		catch(IOException* e1)
		{
			e1->printStackTrace(ctx);
		}
		catch(InterruptedException* e1)
		{
			e1->printStackTrace(ctx);
		}
		catch(AlinousException* e)
		{
			e->printStackTrace(ctx);
		}
	}
	if(this->dataStorage != nullptr && this->dataStorage->isOpened(ctx))
	{
		this->dataStorage->close(ctx);
	}
	if(this->oidIndex != nullptr && this->oidIndex->isOpened(ctx))
	{
		{
			try
			{
				this->oidIndex->close(ctx);
			}
			catch(IOException* e)
			{
				e->printStackTrace(ctx);
			}
			catch(InterruptedException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
	{
		try
		{
			this->primaryIndex->close(ctx);
			int maxLoop = this->indexes->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IScannableIndex* index = this->indexes->get(i, ctx);
				index->close(ctx);
			}
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
		}
		catch(InterruptedException* e)
		{
			e->printStackTrace(ctx);
		}
	}
	this->updateHistoryCache->close(ctx);
	this->storageLock->dispose(ctx);
}
TableMetadata* AbstractDatabaseTable::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
ArrayList<IScannableIndex>* AbstractDatabaseTable::getIndexes(ThreadContext* ctx) throw() 
{
	return indexes;
}
String* AbstractDatabaseTable::getName(ThreadContext* ctx) throw() 
{
	return name;
}
String* AbstractDatabaseTable::getSchemaName(ThreadContext* ctx) throw() 
{
	return this->metadata->getSchema(ctx);
}
String* AbstractDatabaseTable::getBaseDir(ThreadContext* ctx) throw() 
{
	return baseDir;
}
bool AbstractDatabaseTable::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return (dynamic_cast<DatabaseTable*>(obj))->tableId->intValue(ctx) == this->tableId->intValue(ctx);
}
Timestamp* AbstractDatabaseTable::getSchmeUpdated(ThreadContext* ctx) throw() 
{
	return schmeUpdated;
}
DatatableUpdateCache* AbstractDatabaseTable::getUpdateHistoryCache(ThreadContext* ctx) throw() 
{
	return updateHistoryCache;
}
TableIndex* AbstractDatabaseTable::getPrimaryIndex(ThreadContext* ctx) throw() 
{
	return primaryIndex;
}
int AbstractDatabaseTable::getColumnCount(ThreadContext* ctx) throw() 
{
	return this->metadata->getColumnCount(ctx);
}
FileStorage* AbstractDatabaseTable::getDataStorage(ThreadContext* ctx) throw() 
{
	return dataStorage;
}
BTree* AbstractDatabaseTable::getOidIndex(ThreadContext* ctx) throw() 
{
	return oidIndex;
}
Integer* AbstractDatabaseTable::getTableId(ThreadContext* ctx) throw() 
{
	return tableId;
}
void AbstractDatabaseTable::setTableId(Integer* tableId, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableId), tableId, Integer);
}
String* AbstractDatabaseTable::getFullName(ThreadContext* ctx) throw() 
{
	return fullName;
}
void AbstractDatabaseTable::syncScheme(ThreadContext* ctx)
{
	FileStorageEntryWriter* writer = this->dataStorage->getWriter(ctx);
	int cap = this->metadata->fileSize(ctx);
	cap += indexSchemeSize(ctx);
	cap += 8;
	FileStorageEntryBuilder* builder = (new(ctx) FileStorageEntryBuilder(cap, ctx));
	this->metadata->toFileEntry(builder, ctx);
	syncIndexScheme(builder, ctx);
	builder->putLong(this->schmeUpdated->getTime(ctx), ctx);
	FileStorageEntry* entry = builder->toEntry((long long)FileStorage::DATA_BEGIN, ctx);
	writer->write(entry, ctx);
	writer->end(ctx);
}
String* AbstractDatabaseTable::getDataStorageName(ThreadContext* ctx) throw() 
{
	if(this->dataStoragePath == nullptr)
	{
		StringBuilder* buff = (new(ctx) StringBuilder(ctx));
		buff->append(this->baseDir, ctx);
		if(!this->baseDir->endsWith(ConstStr::getCNST_STR_1007(), ctx))
		{
			buff->append(ConstStr::getCNST_STR_1007(), ctx);
		}
		buff->append(this->name, ctx)->append(ConstStr::getCNST_STR_1698(), ctx);
		__GC_MV(this, &(this->dataStoragePath), buff->toString(ctx), String);
	}
	return this->dataStoragePath;
}
int AbstractDatabaseTable::indexSchemeSize(ThreadContext* ctx)
{
	int total = this->primaryIndex->archiveSize(ctx);
	total += 4;
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		total += index->archiveSize(ctx);
	}
	return total;
}
void AbstractDatabaseTable::syncIndexScheme(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	this->primaryIndex->appendToEntry(builder, ctx);
	int maxLoop = this->indexes->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		index->appendToEntry(builder, ctx);
	}
}
void AbstractDatabaseTable::loadScheme(ThreadContext* ctx)
{
	FileStorageEntryReader* reader = 0;
	{
		try
		{
			reader = this->dataStorage->getReader(ctx);
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1699(), e, ctx));
		}
	}
	FileStorageEntry* entry = reader->readFirstEntry(ctx);
	FileStorageEntryFetcher* fetcher = (new(ctx) FileStorageEntryFetcher(entry, ctx));
	__GC_MV(this, &(this->metadata), TableMetadata::loadFromFetcher(fetcher, ctx), TableMetadata);
	loadIndexes(fetcher, ctx);
	long long mills = fetcher->fetchLong(ctx);
	__GC_MV(this, &(this->schmeUpdated), (new(ctx) Timestamp(mills, ctx)), Timestamp);
	fetcher->close(ctx);
}
String* AbstractDatabaseTable::getOidIndexName(ThreadContext* ctx) throw() 
{
	if(this->oidIndexPath == nullptr)
	{
		StringBuilder* buff = (new(ctx) StringBuilder(ctx));
		buff->append(this->baseDir, ctx);
		if(!this->baseDir->endsWith(ConstStr::getCNST_STR_1007(), ctx))
		{
			buff->append(ConstStr::getCNST_STR_1007(), ctx);
		}
		buff->append(ConstStr::getCNST_STR_1689(), ctx)->append(this->name, ctx)->append(ConstStr::getCNST_STR_1700(), ctx);
		__GC_MV(this, &(this->oidIndexPath), buff->toString(ctx), String);
	}
	return this->oidIndexPath;
}
void AbstractDatabaseTable::loadIndexes(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->primaryIndex), TableIndex::valueFromFetcher(fetcher, this->baseDir, ctx), TableIndex);
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndex* index = TableIndex::valueFromFetcher(fetcher, this->baseDir, ctx);
		this->indexes->add(index, ctx);
	}
}
}}}

