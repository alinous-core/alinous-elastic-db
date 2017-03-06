#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.trx.scan/ScanException.h"
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
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.btree/IntKey.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.lock.unique/ColumnsUniqueCollections.h"
#include "alinous.lock.unique/TableUniqueCollections.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
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
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.remote.db.command.data/StorageNodeData.h"
#include "alinous.remote.db.command.data/TableClusterData.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.db.command.data/SchemaData.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.btree/LongKey.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db.trx/CreateIndexMetadata.h"
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
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db.trx.scan/PadddingRecord.h"
#include "alinous.btree/KeyValueFactory.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
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
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.trx.scan/GroupedScanResultRecord.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.db.trx.scan/JoinedRecords.h"
#include "alinous.db.trx.scan/ScannedOids.h"
#include "alinous.db.trx.scan/ScanResultScanner.h"

namespace alinous {namespace db {namespace trx {namespace scan {





bool ScanResultRecord::__init_done = __init_static_variables();
bool ScanResultRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanResultRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanResultRecord::ScanResultRecord(ScanTableIdentifier* tableId, int kind, long long oid, DbTransaction* trx, IDatabaseRecord* record, int lockingMode, ThreadContext* ctx) : IObject(ctx), IBTreeValue(ctx), records(GCUtils<ArrayList<IDatabaseRecord> >::ins(this, (new(ctx) ArrayList<IDatabaseRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), tables(GCUtils<ArrayList<ScanTableIdentifier> >::ins(this, (new(ctx) ArrayList<ScanTableIdentifier>(ctx)), ctx, __FILEW__, __LINE__, L"")), lockingModeList(GCUtils<ArrayList<Integer> >::ins(this, (new(ctx) ArrayList<Integer>(ctx)), ctx, __FILEW__, __LINE__, L"")), soid(0)
{
	this->records->add(record, ctx);
	this->tables->add(tableId, ctx);
	this->lockingModeList->add((new(ctx) Integer(lockingMode, ctx)), ctx);
	this->soid = trx->newSoid(ctx);
}
void ScanResultRecord::__construct_impl(ScanTableIdentifier* tableId, int kind, long long oid, DbTransaction* trx, IDatabaseRecord* record, int lockingMode, ThreadContext* ctx)
{
	this->records->add(record, ctx);
	this->tables->add(tableId, ctx);
	this->lockingModeList->add((new(ctx) Integer(lockingMode, ctx)), ctx);
	this->soid = trx->newSoid(ctx);
}
 ScanResultRecord::ScanResultRecord(ScanTableIdentifier* tableId, long long oid, DbTransaction* trx, ScanTableMetadata* metadata, DomVariable* domVariable, ThreadContext* ctx) : IObject(ctx), IBTreeValue(ctx), records(GCUtils<ArrayList<IDatabaseRecord> >::ins(this, (new(ctx) ArrayList<IDatabaseRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), tables(GCUtils<ArrayList<ScanTableIdentifier> >::ins(this, (new(ctx) ArrayList<ScanTableIdentifier>(ctx)), ctx, __FILEW__, __LINE__, L"")), lockingModeList(GCUtils<ArrayList<Integer> >::ins(this, (new(ctx) ArrayList<Integer>(ctx)), ctx, __FILEW__, __LINE__, L"")), soid(0)
{
	this->records->add(domVariable, ctx);
	this->tables->add(tableId, ctx);
	this->lockingModeList->add((new(ctx) Integer(IndexScannerLockRequirement::NO_LOCK, ctx)), ctx);
}
void ScanResultRecord::__construct_impl(ScanTableIdentifier* tableId, long long oid, DbTransaction* trx, ScanTableMetadata* metadata, DomVariable* domVariable, ThreadContext* ctx)
{
	this->records->add(domVariable, ctx);
	this->tables->add(tableId, ctx);
	this->lockingModeList->add((new(ctx) Integer(IndexScannerLockRequirement::NO_LOCK, ctx)), ctx);
}
 ScanResultRecord::~ScanResultRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanResultRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanResultRecord", L"~ScanResultRecord");
	__e_obj1.add(this->records, this);
	records = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	__e_obj1.add(this->lockingModeList, this);
	lockingModeList = nullptr;
	if(!prepare){
		return;
	}
}
ScanResultRecord* ScanResultRecord::copy(DbTransaction* trx, ThreadContext* ctx)
{
	ScanResultRecord* newrecord = (new(ctx) ScanResultRecord(ctx));
	newrecord->soid = this->soid;
	ArrayList<IDatabaseRecord>* records = this->records;
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = records->get(i, ctx);
		newrecord->records->add(rec, ctx);
	}
	ArrayList<ScanTableIdentifier>* tables = this->tables;
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = tables->get(i, ctx);
		newrecord->tables->add(tableId, ctx);
	}
	ArrayList<Integer>* lockingModeList = this->lockingModeList;
	for(int i = 0; i != maxLoop; ++i)
	{
		Integer* mode = lockingModeList->get(i, ctx);
		newrecord->lockingModeList->add(mode, ctx);
	}
	return newrecord;
}
void ScanResultRecord::unlock(DbTransaction* trx, ThreadContext* ctx)
{
	ArrayList<IDatabaseRecord>* records = this->records;
	ArrayList<ScanTableIdentifier>* tables = this->tables;
	AlinousDatabase* db = trx->getDatabase(ctx);
	TrxLockContext* locker = trx->lockContext;
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* record = records->get(i, ctx);
		if(record->getKind(ctx) != IDatabaseRecord::NORMAL_RECORD)
		{
			continue;
		}
		ScanTableIdentifier* tableId = tables->get(i, ctx);
		TableAndSchema* ts = tableId->getTable(ctx);
		IDatabaseTable* tableStore = db->getTable(ts->getSchema(ctx), ts->getTable(ctx), ctx);
		int lockingMode = this->lockingModeList->get(i, ctx)->intValue(ctx);
		switch(lockingMode) {
		case IndexScannerLockRequirement::EXPLICIT_SHARE:
			locker->shareUnlockRow(tableStore, record->getOid(ctx), ctx);
			break ;
		case IndexScannerLockRequirement::EXPLICIT_UPDATE:
			locker->updateUnlockRow(tableStore, record->getOid(ctx), ctx);
			break ;
		default:
			break ;
		}
	}
}
VariantValue* ScanResultRecord::getValueOfTable(ScanTableIdentifier* tableId, int columnOrder, ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableIdentifier>* tables = this->tables;
	int maxLoop = tables->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* t = tables->get(i, ctx);
		if(tableId->equals(t, ctx))
		{
			IDatabaseRecord* rec = this->records->get(i, ctx);
			return rec->getColumnValue(columnOrder, ctx);
		}
	}
	return nullptr;
}
VariantValue* ScanResultRecord::get(int index, ThreadContext* ctx) throw() 
{
	int maxLoop = tables->size(ctx);
	int offset = 0;
	int tableOffset = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* t = records->get(i, ctx);
		int off = offset + t->getNumValues(ctx);
		if(off > index)
		{
			break ;
		}
		offset = off;
		tableOffset ++ ;
	}
	return this->records->get(tableOffset, ctx)->getColumnValue(index - offset, ctx);
}
int ScanResultRecord::numColumns(ThreadContext* ctx) throw() 
{
	int maxLoop = tables->size(ctx);
	int cols = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* t = records->get(i, ctx);
		cols += t->getNumValues(ctx);
	}
	return cols;
}
void ScanResultRecord::setValue(int index, VariantValue* vv, ThreadContext* ctx) throw() 
{
	int maxLoop = tables->size(ctx);
	int offset = 0;
	int tableOffset = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* t = records->get(i, ctx);
		int off = offset + t->getNumValues(ctx);
		if(off > index)
		{
			break ;
		}
		offset = off;
		tableOffset ++ ;
	}
	this->records->get(tableOffset, ctx)->setValue(index - offset, vv, ctx);
}
void ScanResultRecord::addNullRecord(int colSize, ThreadContext* ctx) throw() 
{
	this->records->add((new(ctx) PadddingRecord(colSize, ctx)), ctx);
}
long long ScanResultRecord::getLastUpdateCommitId(ThreadContext* ctx) throw() 
{
	return this->records->get(0, ctx)->getLastUpdateCommitId(ctx);
}
long long ScanResultRecord::getInsertedCommitId(ThreadContext* ctx) throw() 
{
	return this->records->get(0, ctx)->getInsertedCommitId(ctx);
}
long long ScanResultRecord::getDeletedCommitId(ThreadContext* ctx) throw() 
{
	return this->records->get(0, ctx)->getDeletedCommitId(ctx);
}
long long ScanResultRecord::getOid(ThreadContext* ctx) throw() 
{
	return this->records->get(0, ctx)->getOid(ctx);
}
void ScanResultRecord::releaseLocks(TrxLockContext* lockContext, ThreadContext* ctx) throw() 
{
}
ScanTableIdentifier* ScanResultRecord::getTableId(ThreadContext* ctx) throw() 
{
	return this->tables->get(0, ctx);
}
int ScanResultRecord::diskSize(ThreadContext* ctx)
{
	int total = 4 + 8 + 4;
	int maxLoop = this->records->size(ctx);
	ArrayList<IDatabaseRecord>* records = this->records;
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = records->get(i, ctx);
		total += rec->diskSize(ctx);
	}
	ArrayList<ScanTableIdentifier>* tables = this->tables;
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = tables->get(i, ctx);
		total += tableId->getArchiveSize(ctx);
	}
	total += maxLoop * 4;
	return total;
}
void ScanResultRecord::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeValue::TYPE_SCAN_RESULT_RECORD, ctx);
	builder->putLong(this->soid, ctx);
	int maxLoop = this->records->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = this->records->get(i, ctx);
		rec->appendToEntry(builder, ctx);
	}
	ArrayList<ScanTableIdentifier>* tables = this->tables;
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = tables->get(i, ctx);
		tableId->appendToEntry(builder, ctx);
	}
	ArrayList<Integer>* lockingModeList = this->lockingModeList;
	for(int i = 0; i != maxLoop; ++i)
	{
		Integer* mode = lockingModeList->get(i, ctx);
		builder->putInt(mode->intValue(ctx), ctx);
	}
}
IValueFetcher* ScanResultRecord::getFetcher(ThreadContext* ctx) throw() 
{
	return nullptr;
}
ScanResultRecord* ScanResultRecord::join(ScanResultRecord* rightRecord, DbTransaction* trx, ThreadContext* ctx)
{
	ScanResultRecord* newRecord = copy(trx, ctx);
	ArrayList<IDatabaseRecord>* reclist = rightRecord->records;
	ArrayList<ScanTableIdentifier>* tableslist = rightRecord->tables;
	ArrayList<Integer>* lockingModeList = rightRecord->lockingModeList;
	ArrayList<IDatabaseRecord>* nrecords = newRecord->records;
	ArrayList<ScanTableIdentifier>* ntables = newRecord->tables;
	ArrayList<Integer>* nlockingModeList = newRecord->lockingModeList;
	int maxLoop = reclist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* record = reclist->get(i, ctx);
		ScanTableIdentifier* tableId = tableslist->get(i, ctx);
		Integer* lockingMode = lockingModeList->get(i, ctx);
		nrecords->add(record, ctx);
		ntables->add(tableId, ctx);
		nlockingModeList->add(lockingMode, ctx);
	}
	return newRecord;
}
long long ScanResultRecord::getSoid(ThreadContext* ctx) throw() 
{
	return soid;
}
void ScanResultRecord::setSoid(long long soid, ThreadContext* ctx) throw() 
{
	this->soid = soid;
}
ArrayList<IDatabaseRecord>* ScanResultRecord::getRecords(ThreadContext* ctx) throw() 
{
	return records;
}
String* ScanResultRecord::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	ArrayList<IDatabaseRecord>* records = this->records;
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = records->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(rec->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
bool ScanResultRecord::equals(IObject* other, ThreadContext* ctx) throw() 
{
	return this == other;
}
ScanResultRecord* ScanResultRecord::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	ScanResultRecord* record = (new(ctx) ScanResultRecord(ctx));
	record->soid = fetcher->fetchLong(ctx);
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IBTreeValue* rec = KeyValueFactory::valueFromFetcher(fetcher, ctx);
		record->records->add(static_cast<IDatabaseRecord*>(rec), ctx);
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = ScanTableIdentifier::valueFromFetcher(fetcher, ctx);
		record->tables->add(tableId, ctx);
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		int lockingMode = fetcher->fetchInt(ctx);
		record->lockingModeList->add((new(ctx) Integer(lockingMode, ctx)), ctx);
	}
	return record;
}
}}}}

