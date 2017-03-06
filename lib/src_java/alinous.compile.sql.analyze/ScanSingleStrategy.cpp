#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidationError.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/TypedVariableDeclareSource.h"
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
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
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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
#include "alinous.runtime.variant/IVariantData.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileAccessWrapper.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.buffer/FifoList.h"
#include "java.util/BitSet.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/BTreeException.h"
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
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
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
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "java.lang/Integer.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
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
#include "alinous.db.table/IOidPublisher.h"
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
#include "alinous.remote.db.command.data/SchemaData.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
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
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"
#include "alinous.runtime.function/IAlinousNativeFunction.h"
#include "alinous.runtime.function/AlinousNativeFunctionRegistory.h"
#include "alinous.system.functions/NativeFunctionManager.h"
#include "alinous.system.functions/AlinousFunctionManager.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
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
#include "alinous.system/AlinousCoreLogger.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.remote.region.client.transaction/AbstractRemoteClientTransaction.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/ExpressionStreamBuffer.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/ClassDeclareHolder.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.db.table.scan/IndexListScannerParam.h"
#include "alinous.db.table.scan/IndexRangeScannerParam.h"
#include "alinous.compile.sql.analyze/IndexScanStrategyPlan.h"
#include "alinous.compile.sql.analyze/IndexScanStrategy.h"
#include "alinous.compile.sql.analyze/InnerNecessaryCondition.h"
#include "alinous.compile.sql.analyze/BooleanFilterConditionUtil.h"
#include "alinous.compile.sql.expression.blexp/SQLEqualityExpression.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze/IndexConditionDetector.h"
#include "alinous.compile.sql.analyze/IndexSelectionUtils.h"
#include "alinous.compile.sql.analyze/IScanStrategy.h"
#include "alinous.compile.sql.analyze.scan/VoidScanner.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndexScanner.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.table.scan/TableIndexScanner.h"
#include "alinous.db.table.scan/IndexEqScanner.h"
#include "alinous.db.table.scan/IndexListScanner.h"
#include "alinous.db.table.scan/IndexRangeScanner.h"
#include "alinous.db.table.scan/SingleTableIndexScanner.h"
#include "alinous.db.table.scan/TableFullScanner.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.analyze/ScanSingleStrategy.h"
#include "alinous.compile.sql.analyze/JoinConditionDetector.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool ScanSingleStrategy::__init_done = __init_static_variables();
bool ScanSingleStrategy::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanSingleStrategy", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanSingleStrategy::ScanSingleStrategy(ScanTableMetadata* table, ScanTableIdentifier* tableId, AlinousDatabase* database, ThreadContext* ctx) throw()  : IObject(ctx), filterConditions(GCUtils<ArrayList<InnerNecessaryCondition> >::ins(this, (new(ctx) ArrayList<InnerNecessaryCondition>(ctx)), ctx, __FILEW__, __LINE__, L"")), table(nullptr), database(nullptr), tableId(nullptr), joinRequest(nullptr)
{
	__GC_MV(this, &(this->table), table, ScanTableMetadata);
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
	__GC_MV(this, &(this->database), database, AlinousDatabase);
}
void ScanSingleStrategy::__construct_impl(ScanTableMetadata* table, ScanTableIdentifier* tableId, AlinousDatabase* database, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, ScanTableMetadata);
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
	__GC_MV(this, &(this->database), database, AlinousDatabase);
}
 ScanSingleStrategy::~ScanSingleStrategy() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanSingleStrategy::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanSingleStrategy", L"~ScanSingleStrategy");
	__e_obj1.add(this->filterConditions, this);
	filterConditions = nullptr;
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->database, this);
	database = nullptr;
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->joinRequest, this);
	joinRequest = nullptr;
	if(!prepare){
		return;
	}
}
ITableTargetScanner* ScanSingleStrategy::getScanner(ScriptMachine* machine, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	if(this->filterConditions->isEmpty(ctx))
	{
		{
			try
			{
				return getNoWhereConditionScanner(machine, trx, joinRequest, debug, ctx);
			}
			catch(IOException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
		}
	}
	ITableTargetScanner* scanner = necessaryCollectionScanner(machine, trx, joinRequest, debug, ctx);
	return scanner;
}
void ScanSingleStrategy::optimize(ThreadContext* ctx) throw() 
{
	int maxLoop = this->filterConditions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		InnerNecessaryCondition* cnd = this->filterConditions->get(i, ctx);
		cnd->optimizeIndexStrategy(database, this->joinRequest, ctx);
	}
}
void ScanSingleStrategy::analyzeFilterCondition(SQLWhere* where, ThreadContext* ctx) throw() 
{
	ArrayList<InnerNecessaryCondition>* result = nullptr;
	if(where != nullptr && where->getCondition(ctx) != nullptr)
	{
		ISQLExpression* whereExp = where->getCondition(ctx);
		result = BooleanFilterConditionUtil::fetchCondition(whereExp, this->table->getFirstTableId(ctx), ctx);
		if(result != nullptr)
		{
			this->filterConditions->addAll(result, ctx);
		}
	}
}
void ScanSingleStrategy::analyzeIndex(SQLWhere* where, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx)
{
	int maxloop = this->filterConditions->size(ctx);
	for(int i = 0; i != maxloop; ++i)
	{
		InnerNecessaryCondition* cond = this->filterConditions->get(i, ctx);
		cond->analyze(tableMetadata, debug, ctx);
	}
}
ITableTargetScanner* ScanSingleStrategy::getNoWhereConditionScanner(ScriptMachine* machine, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	ArrayList<ScanTableIndexMetadata>* indexes = this->table->getAbailableIndexes(tableId, joinRequest, ctx);
	if(indexes != nullptr && !indexes->isEmpty(ctx))
	{
		ScanTableIndexMetadata* indexMeta = indexes->get(0, ctx);
		return getIndexScanner(trx, indexMeta, ctx);
	}
	if(joinRequest == nullptr)
	{
		return getFullScanScanner(trx, ctx);
	}
	{
		try
		{
			return getCachedFullScanScanner(trx, joinRequest, debug, ctx);
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) DatabaseException(e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(e, ctx));
		}
	}
}
SingleTableIndexScanner* ScanSingleStrategy::getIndexScanner(DbTransaction* trx, ScanTableIndexMetadata* indexMeta, ThreadContext* ctx)
{
	ScanTableMetadata* metadata = this->table;
	IDatabaseTable* tableStore = this->database->getTable(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
	TrxStorageManager* trxStorageManager = trx->getTrxStorageManager(ctx);
	IScannableIndex* index = tableStore->getAbailableIndex(indexMeta->getColumnsStr(ctx), ctx);
	TrxRecordCacheIndex* insertCacheindex = nullptr;
	TrxRecordCacheIndex* updateCacheindex = nullptr;
	{
		try
		{
			TrxRecordsCache* inserCache = trxStorageManager->getInsertCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			TrxRecordsCache* updateCache = trxStorageManager->getUpdateCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			if(inserCache != nullptr)
			{
				insertCacheindex = inserCache->getCachedIndex(indexMeta->getColumnIds(ctx), ctx);
			}
			if(updateCache != nullptr)
			{
				updateCacheindex = updateCache->getCachedIndex(indexMeta->getColumnIds(ctx), ctx);
			}
		}
		catch(AlinousDbException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1052(), e, ctx));
		}
	}
	SingleTableIndexScanner* scanner = (new(ctx) SingleTableIndexScanner(ctx))->init(this->tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, IndexScannerLockRequirement::INSTANT_SHARE, ctx);
	return scanner;
}
ITableTargetScanner* ScanSingleStrategy::getFullScanScanner(DbTransaction* trx, ThreadContext* ctx)
{
	ScanTableMetadata* metadata = this->table;
	IDatabaseTable* tableStore = this->database->getTable(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
	IScannableIndex* index = tableStore->getPrimaryIndex(ctx);
	TrxStorageManager* trxStorageManager = trx->getTrxStorageManager(ctx);
	TrxRecordCacheIndex* insertCacheindex = nullptr;
	TrxRecordCacheIndex* updateCacheindex = nullptr;
	{
		try
		{
			ArrayList<ScanTableColumnIdentifier>* colIdList = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
			ArrayList<TableColumnMetadata>* list = index->getColumns(ctx);
			int maxLoop = list->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				TableColumnMetadata* metaCol = list->get(i, ctx);
				ScanTableColumnIdentifier* colId = (new(ctx) ScanTableColumnIdentifier(this->tableId, metaCol->name, ctx));
				colIdList->add(colId, ctx);
			}
			TrxRecordsCache* inserCache = trxStorageManager->getInsertCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			TrxRecordsCache* updateCache = trxStorageManager->getUpdateCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			if(inserCache != nullptr)
			{
				insertCacheindex = inserCache->getCachedIndex(colIdList, ctx);
			}
			if(updateCache != nullptr)
			{
				updateCacheindex = updateCache->getCachedIndex(colIdList, ctx);
			}
		}
		catch(AlinousDbException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1052(), e, ctx));
		}
	}
	SingleTableIndexScanner* scanner = (new(ctx) SingleTableIndexScanner(ctx))->init(this->tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, IndexScannerLockRequirement::INSTANT_SHARE, ctx);
	return scanner;
}
ITableTargetScanner* ScanSingleStrategy::getCachedFullScanScanner(DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	ITableTargetScanner* scanner = getFullScanScanner(trx, ctx);
	return toCachedScanner(trx, joinRequest, scanner, debug, ctx);
}
ScannedResultIndexScanner* ScanSingleStrategy::toCachedScanner(DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, ITableTargetScanner* scanner, bool debug, ThreadContext* ctx)
{
	ScanResult* result = trx->newResult(this->table, ctx);
	result->addIndex(joinRequest, ctx);
	{
		try
		{
			scanner->startScan(nullptr, ctx);
			while(scanner->hasNext(debug, ctx))
			{
				ScanResultRecord* record = scanner->next(debug, ctx);
				result->addRecord(record, trx, ctx);
			}
			scanner->endScan(ctx);
		}
		catch(Throwable* e)
		{
			scanner->dispose(trx->getLogger(ctx), ctx);
			throw e;
		}
	}
	scanner->dispose(trx->getLogger(ctx), ctx);
	ScannedResultIndexScanner* resultScanner = (new(ctx) ScannedResultIndexScanner(result, joinRequest, ctx));
	return resultScanner;
}
ITableTargetScanner* ScanSingleStrategy::necessaryCollectionScanner(ScriptMachine* machine, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	int maxLoop = this->filterConditions->size(ctx);
	ArrayList<ITableTargetScanner>* list = (new(ctx) ArrayList<ITableTargetScanner>(ctx));
	for(int i = 0; i != maxLoop; ++i)
	{
		InnerNecessaryCondition* ncd = this->filterConditions->get(i, ctx);
		IndexScanStrategyPlan* plan = ncd->getStrategy(ctx)->getBestPlan(joinRequest, ctx);
		ITableTargetScanner* nscan = 0;
		{
			try
			{
				nscan = initOnTheFlyScanner(machine, plan, trx, joinRequest, ncd, debug, ctx);
				if(nscan == nullptr)
				{
					throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1053(), ctx));
				}
				list->add(nscan, ctx);
			}
			catch(IOException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1054(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1054(), e, ctx));
			}
			catch(AlinousDbException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1054(), e, ctx));
			}
		}
	}
	if(maxLoop == 1)
	{
		return list->get(0, ctx);
	}
	return nullptr;
}
ITableTargetScanner* ScanSingleStrategy::initOnTheFlyScanner(ScriptMachine* machine, IndexScanStrategyPlan* plan, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, InnerNecessaryCondition* necessaryCnd, bool debug, ThreadContext* ctx)
{
	if(joinRequest != nullptr)
	{
		return initOnTheFlyScanner4Join(machine, plan, trx, joinRequest, necessaryCnd, ctx);
	}
	ScanTableMetadata* metadata = this->table;
	IDatabaseTable* tableStore = this->database->getTable(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
	IScannableIndex* index = plan->getIndex(tableStore, ctx);
	TrxStorageManager* trxStorageManager = trx->getTrxStorageManager(ctx);
	TrxRecordCacheIndex* insertCacheindex = nullptr;
	TrxRecordCacheIndex* updateCacheindex = nullptr;
	ArrayList<ScanTableColumnIdentifier>* colIdList = nullptr;
	{
		try
		{
			colIdList = plan->getColumns(ctx);
			TrxRecordsCache* inserCache = trxStorageManager->getInsertCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			TrxRecordsCache* updateCache = trxStorageManager->getUpdateCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			if(inserCache != nullptr)
			{
				insertCacheindex = inserCache->getCachedIndex(colIdList, ctx);
			}
			if(updateCache != nullptr)
			{
				updateCacheindex = updateCache->getCachedIndex(colIdList, ctx);
			}
		}
		catch(AlinousDbException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1052(), e, ctx));
		}
	}
	int matchMode = plan->getScanMode(ctx);
	switch(matchMode) {
	case IndexScanStrategyPlan::SCAN_ALWAYS_FALSE:
		return (new(ctx) VoidScanner(ctx));
	case IndexScanStrategyPlan::SCAN_EQ:
		{
			ScanResultIndexKey* eqKey = plan->getEqIndexKey(machine, index->getColumns(ctx), debug, ctx);
			int effectiveKeyLength = plan->getEqKeyLength(ctx);
			IndexEqScanner* intnlScanner = (new(ctx) IndexEqScanner(ctx))->init(this->tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, IndexScannerLockRequirement::INSTANT_SHARE, eqKey, effectiveKeyLength, necessaryCnd, machine, ctx);
			return intnlScanner;
		}
	case IndexScanStrategyPlan::SCAN_RANGE:
		{
			IndexRangeScannerParam* param = plan->getRamgeIndexKeyParam(machine, index->getColumns(ctx), debug, ctx);
			int effectiveKeyLength = 1;
			IndexRangeScanner* rangeScanner = (new(ctx) IndexRangeScanner(ctx))->init(this->tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, IndexScannerLockRequirement::INSTANT_SHARE, param, effectiveKeyLength, necessaryCnd, machine, ctx);
			return rangeScanner;
		}
	case IndexScanStrategyPlan::SCAN_LIST:
		{
			IndexListScannerParam* param = plan->getListIndexKey(machine, index->getColumns(ctx), debug, ctx);
			int effectiveKeyLength = 1;
			IndexListScanner* listScanner = (new(ctx) IndexListScanner(ctx))->init(this->tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, IndexScannerLockRequirement::INSTANT_SHARE, param, effectiveKeyLength, necessaryCnd, machine, ctx);
			return listScanner;
		}
	default:
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1055(), ctx));
		break;
	}
}
ITableTargetScanner* ScanSingleStrategy::initOnTheFlyScanner4Join(ScriptMachine* machine, IndexScanStrategyPlan* plan, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, InnerNecessaryCondition* necessaryCnd, ThreadContext* ctx)
{
	ScanTableMetadata* metadata = this->table;
	IDatabaseTable* tableStore = this->database->getTable(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
	IScannableIndex* index = tableStore->getAbailableIndexByScanColId(joinRequest, ctx);
	if(index == nullptr)
	{
		TableIndexScanner* indexScanner = (new(ctx) TableIndexScanner(ctx))->init(this->tableId, trx, index, tableStore, IndexScannerLockRequirement::INSTANT_SHARE, ctx);
		return indexScanner;
	}
	TableFullScanner* scanner = (new(ctx) TableFullScanner(ctx))->init(this->tableId, trx, tableStore, IndexScannerLockRequirement::INSTANT_SHARE, ctx);
	return scanner;
}
}}}}

