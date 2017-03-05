#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
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
#include "alinous.lock/LockObject.h"
#include "java.util/Random.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigInteger.h"
#include "alinous.numeric/RoundingMode.h"
#include "alinous.numeric/MathContext.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
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
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
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
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
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
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/IDatabaseRecord.h"
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
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
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
#include "alinous.remote.region/RegionInsertExecutorPool.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.compile/ParseException.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/JavaCharStream.h"
#include "alinous.compile/TokenMgrError.h"
#include "alinous.compile/AlinousPlusParserConstants.h"
#include "alinous.compile/AlinousPlusParserTokenManager.h"
#include "alinous.compile/AlinousPlusParser.h"
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
#include "alinous.db/TableSchema.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/DbTransaction.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
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
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/ClassDeclareHolder.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.compile/DebugProbeSection.h"
#include "alinous.compile/DebugProbe.h"

namespace alinous {namespace compile {





constexpr const bool JavaCharStream::staticFlag;
bool JavaCharStream::__init_done = __init_static_variables();
bool JavaCharStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JavaCharStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JavaCharStream::JavaCharStream(java::io::Reader* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__GC_MV(this, &(inputStream), dstream, java::io::Reader);
	line = startline;
	column = startcolumn - 1;
	available = bufsize = buffersize;
	__GC_MV(this, &(buffer), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, buffersize), IArrayObjectPrimitive<wchar_t>);
	__GC_MV(this, &(bufline), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(bufcolumn), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(nextCharBuf), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 4096), IArrayObjectPrimitive<wchar_t>);
}
void JavaCharStream::__construct_impl(java::io::Reader* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(inputStream), dstream, java::io::Reader);
	line = startline;
	column = startcolumn - 1;
	available = bufsize = buffersize;
	__GC_MV(this, &(buffer), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, buffersize), IArrayObjectPrimitive<wchar_t>);
	__GC_MV(this, &(bufline), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(bufcolumn), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(nextCharBuf), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 4096), IArrayObjectPrimitive<wchar_t>);
}
 JavaCharStream::JavaCharStream(java::io::Reader* dstream, int startline, int startcolumn, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::Reader* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() 
{
	__construct_impl(dstream, startline, startcolumn, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::Reader* dstream, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, 1, 1, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::Reader* dstream, ThreadContext* ctx) throw() 
{
	__construct_impl(dstream, 1, 1, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, int buffersize, ThreadContext* ctx) : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(encoding == nullptr ? (new(ctx) java::io::InputStreamReader(dstream, ctx)) : (new(ctx) java::io::InputStreamReader(dstream, encoding, ctx)), startline, startcolumn, buffersize, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, int buffersize, ThreadContext* ctx)
{
	__construct_impl(encoding == nullptr ? (new(ctx) java::io::InputStreamReader(dstream, ctx)) : (new(ctx) java::io::InputStreamReader(dstream, encoding, ctx)), startline, startcolumn, buffersize, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl((new(ctx) java::io::InputStreamReader(dstream, ctx)), startline, startcolumn, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() 
{
	__construct_impl((new(ctx) java::io::InputStreamReader(dstream, ctx)), startline, startcolumn, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, ThreadContext* ctx) : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, encoding, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, ThreadContext* ctx)
{
	__construct_impl(dstream, encoding, startline, startcolumn, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, int startline, int startcolumn, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() 
{
	__construct_impl(dstream, startline, startcolumn, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, String* encoding, ThreadContext* ctx) : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, encoding, 1, 1, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, String* encoding, ThreadContext* ctx)
{
	__construct_impl(dstream, encoding, 1, 1, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, 1, 1, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, ThreadContext* ctx) throw() 
{
	__construct_impl(dstream, 1, 1, 4096, ctx);
}
 JavaCharStream::~JavaCharStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JavaCharStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JavaCharStream", L"~JavaCharStream");
	__e_obj1.add(this->bufline, this);
	bufline = nullptr;
	__e_obj1.add(this->bufcolumn, this);
	bufcolumn = nullptr;
	__e_obj1.add(this->inputStream, this);
	inputStream = nullptr;
	__e_obj1.add(this->nextCharBuf, this);
	nextCharBuf = nullptr;
	__e_obj1.add(this->buffer, this);
	buffer = nullptr;
	if(!prepare){
		return;
	}
}
void JavaCharStream::setTabSize(int i, ThreadContext* ctx) throw() 
{
	tabSize = i;
}
int JavaCharStream::getTabSize(ThreadContext* ctx) throw() 
{
	return tabSize;
}
wchar_t JavaCharStream::BeginToken(ThreadContext* ctx)
{
	if(inBuf > 0)
	{
		--inBuf;
		if(++bufpos == bufsize)
		{
			bufpos = 0;
		}
		tokenBegin = bufpos;
		return buffer->get(bufpos);
	}
	tokenBegin = 0;
	bufpos = -1;
	return readChar(ctx);
}
wchar_t JavaCharStream::readChar(ThreadContext* ctx)
{
	if(inBuf > 0)
	{
		--inBuf;
		if(++bufpos == bufsize)
		{
			bufpos = 0;
		}
		return buffer->get(bufpos);
	}
	wchar_t c = 0;
	if(++bufpos == available)
	{
		AdjustBuffSize(ctx);
	}
	buffer->set(c = ReadByte(ctx),bufpos, ctx);
	if((buffer->get(bufpos)) == L'\\')
	{
		if(trackLineColumn)
		{
			UpdateLineColumn(c, ctx);
		}
		int backSlashCnt = 1;
		for(; ; )
		{
			if(++bufpos == available)
			{
				AdjustBuffSize(ctx);
			}
			{
				try
				{
					buffer->set(c = ReadByte(ctx),bufpos, ctx);
					if((buffer->get(bufpos)) != L'\\')
					{
						if(trackLineColumn)
						{
							UpdateLineColumn(c, ctx);
						}
						if((c == L'u') && ((backSlashCnt & 1) == 1))
						{
							if(--bufpos < 0)
							{
								bufpos = bufsize - 1;
							}
							break ;
						}
						backup(backSlashCnt, ctx);
						return L'\\';
					}
				}
				catch(java::io::IOException* e)
				{
					if(backSlashCnt > 1)
					{
						backup(backSlashCnt - 1, ctx);
					}
					return L'\\';
				}
			}
			if(trackLineColumn)
			{
				UpdateLineColumn(c, ctx);
			}
			backSlashCnt ++ ;
		}
		{
			try
			{
				c = ReadByte(ctx);
				while((c) == L'u')
				++column;
				buffer->set(c = ((wchar_t)(hexval(c, ctx) << 12 | hexval(ReadByte(ctx), ctx) << 8 | hexval(ReadByte(ctx), ctx) << 4 | hexval(ReadByte(ctx), ctx))),bufpos, ctx);
				column += 4;
			}
			catch(java::io::IOException* e)
			{
				throw (new(ctx) Error(ConstStr::getCNST_STR_1330()->clone(ctx)->append(line, ctx)->append(ConstStr::getCNST_STR_1331(), ctx)->append(column, ctx)->append(ConstStr::getCNST_STR_950(), ctx), ctx));
			}
		}
		if(backSlashCnt == 1)
		{
			return c;
		}
				else 
		{
			backup(backSlashCnt - 1, ctx);
			return L'\\';
		}
	}
		else 
	{
		UpdateLineColumn(c, ctx);
		return c;
	}
}
int JavaCharStream::getColumn(ThreadContext* ctx) throw() 
{
	return bufcolumn->get(bufpos);
}
int JavaCharStream::getLine(ThreadContext* ctx) throw() 
{
	return bufline->get(bufpos);
}
int JavaCharStream::getEndColumn(ThreadContext* ctx) throw() 
{
	return bufcolumn->get(bufpos);
}
int JavaCharStream::getEndLine(ThreadContext* ctx) throw() 
{
	return bufline->get(bufpos);
}
int JavaCharStream::getBeginColumn(ThreadContext* ctx) throw() 
{
	return bufcolumn->get(tokenBegin);
}
int JavaCharStream::getBeginLine(ThreadContext* ctx) throw() 
{
	return bufline->get(tokenBegin);
}
void JavaCharStream::backup(int amount, ThreadContext* ctx) throw() 
{
	inBuf += amount;
	bufpos -= amount;
	if((bufpos) < 0)
	{
		bufpos += bufsize;
	}
}
void JavaCharStream::ReInit(java::io::Reader* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(inputStream), dstream, java::io::Reader);
	line = startline;
	column = startcolumn - 1;
	if(buffer == (IArrayObjectPrimitive<wchar_t>*)nullptr || buffersize != buffer->length)
	{
		available = bufsize = buffersize;
		__GC_MV(this, &(buffer), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, buffersize), IArrayObjectPrimitive<wchar_t>);
		__GC_MV(this, &(bufline), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
		__GC_MV(this, &(bufcolumn), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
		__GC_MV(this, &(nextCharBuf), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 4096), IArrayObjectPrimitive<wchar_t>);
	}
	prevCharIsLF = prevCharIsCR = false;
	tokenBegin = inBuf = maxNextCharInd = 0;
	nextCharInd = bufpos = -1;
}
void JavaCharStream::ReInit(java::io::Reader* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() 
{
	ReInit(dstream, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::ReInit(java::io::Reader* dstream, ThreadContext* ctx) throw() 
{
	ReInit(dstream, 1, 1, 4096, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, int buffersize, ThreadContext* ctx)
{
	ReInit(encoding == nullptr ? (new(ctx) java::io::InputStreamReader(dstream, ctx)) : (new(ctx) java::io::InputStreamReader(dstream, encoding, ctx)), startline, startcolumn, buffersize, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() 
{
	ReInit((new(ctx) java::io::InputStreamReader(dstream, ctx)), startline, startcolumn, buffersize, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, ThreadContext* ctx)
{
	ReInit(dstream, encoding, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() 
{
	ReInit(dstream, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, String* encoding, ThreadContext* ctx)
{
	ReInit(dstream, encoding, 1, 1, 4096, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, ThreadContext* ctx) throw() 
{
	ReInit(dstream, 1, 1, 4096, ctx);
}
String* JavaCharStream::GetImage(ThreadContext* ctx) throw() 
{
	if(bufpos >= tokenBegin)
	{
		return (new(ctx) String(buffer, tokenBegin, bufpos - tokenBegin + 1, ctx));
	}
		else 
	{
		return (new(ctx) String(buffer, tokenBegin, bufsize - tokenBegin, ctx))->clone(ctx)->append((new(ctx) String(buffer, 0, bufpos + 1, ctx)), ctx);
	}
}
IArrayObjectPrimitive<wchar_t>* JavaCharStream::GetSuffix(int len, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<wchar_t>* ret = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, len);
	if((bufpos + 1) >= len)
	{
		System::arraycopy(buffer, bufpos - len + 1, ret, 0, len, ctx);
	}
		else 
	{
		System::arraycopy(buffer, bufsize - (len - bufpos - 1), ret, 0, len - bufpos - 1, ctx);
		System::arraycopy(buffer, 0, ret, len - bufpos - 1, bufpos + 1, ctx);
	}
	return ret;
}
void JavaCharStream::Done(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(nextCharBuf), nullptr, IArrayObjectPrimitive<wchar_t>);
	__GC_MV(this, &(buffer), nullptr, IArrayObjectPrimitive<wchar_t>);
	__GC_MV(this, &(bufline), nullptr, IArrayObjectPrimitive<int>);
	__GC_MV(this, &(bufcolumn), nullptr, IArrayObjectPrimitive<int>);
}
void JavaCharStream::adjustBeginLineColumn(int newLine, int newCol, ThreadContext* ctx) throw() 
{
	int start = tokenBegin;
	int len = 0;
	if(bufpos >= tokenBegin)
	{
		len = bufpos - tokenBegin + inBuf + 1;
	}
		else 
	{
		len = bufsize - tokenBegin + bufpos + 1 + inBuf;
	}
	int i = 0;int j = 0;int k = 0;
	int nextColDiff = 0;int columnDiff = 0;
	if(i < len){
		j = start % bufsize;
	}
	if(i < len){
		k = ++start % bufsize;
	}
	while(i < len && bufline->get(j) == bufline->get(k))
	{
		bufline->set(newLine,j, ctx);
		nextColDiff = columnDiff + bufcolumn->get(k) - bufcolumn->get(j);
		bufcolumn->set(newCol + columnDiff,j, ctx);
		columnDiff = nextColDiff;
		i ++ ;
	}
	if(i < len)
	{
		bufline->set(newLine++,j, ctx);
		bufcolumn->set(newCol + columnDiff,j, ctx);
		while(i++ < len)
		{
			j = start % bufsize;
			if(bufline->get(j) != bufline->get(++start % bufsize))
			{
				bufline->set(newLine++,j, ctx);
			}
						else 
			{
				bufline->set(newLine,j, ctx);
			}
		}
	}
	line = bufline->get(j);
	column = bufcolumn->get(j);
}
void JavaCharStream::ExpandBuff(bool wrapAround, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<wchar_t>* newbuffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, bufsize + 2048);
	IArrayObjectPrimitive<int>* newbufline = ArrayAllocatorPrimitive<int>::allocatep(ctx, bufsize + 2048);
	IArrayObjectPrimitive<int>* newbufcolumn = ArrayAllocatorPrimitive<int>::allocatep(ctx, bufsize + 2048);
	{
		try
		{
			if(wrapAround)
			{
				System::arraycopy(buffer, tokenBegin, newbuffer, 0, bufsize - tokenBegin, ctx);
				System::arraycopy(buffer, 0, newbuffer, bufsize - tokenBegin, bufpos, ctx);
				__GC_MV(this, &(buffer), newbuffer, IArrayObjectPrimitive<wchar_t>);
				System::arraycopy(bufline, tokenBegin, newbufline, 0, bufsize - tokenBegin, ctx);
				System::arraycopy(bufline, 0, newbufline, bufsize - tokenBegin, bufpos, ctx);
				__GC_MV(this, &(bufline), newbufline, IArrayObjectPrimitive<int>);
				System::arraycopy(bufcolumn, tokenBegin, newbufcolumn, 0, bufsize - tokenBegin, ctx);
				System::arraycopy(bufcolumn, 0, newbufcolumn, bufsize - tokenBegin, bufpos, ctx);
				__GC_MV(this, &(bufcolumn), newbufcolumn, IArrayObjectPrimitive<int>);
				bufpos += (bufsize - tokenBegin);
			}
						else 
			{
				System::arraycopy(buffer, tokenBegin, newbuffer, 0, bufsize - tokenBegin, ctx);
				__GC_MV(this, &(buffer), newbuffer, IArrayObjectPrimitive<wchar_t>);
				System::arraycopy(bufline, tokenBegin, newbufline, 0, bufsize - tokenBegin, ctx);
				__GC_MV(this, &(bufline), newbufline, IArrayObjectPrimitive<int>);
				System::arraycopy(bufcolumn, tokenBegin, newbufcolumn, 0, bufsize - tokenBegin, ctx);
				__GC_MV(this, &(bufcolumn), newbufcolumn, IArrayObjectPrimitive<int>);
				bufpos -= tokenBegin;
			}
		}
		catch(Throwable* t)
		{
			throw (new(ctx) Error(t->getMessage(ctx), ctx));
		}
	}
	available = (bufsize += 2048);
	tokenBegin = 0;
}
void JavaCharStream::FillBuff(ThreadContext* ctx)
{
	int i = 0;
	if(maxNextCharInd == 4096)
	{
		maxNextCharInd = nextCharInd = 0;
	}
	{
		try
		{
			i = inputStream->read(nextCharBuf, maxNextCharInd, 4096 - maxNextCharInd, ctx);
			if((i) == -1)
			{
				inputStream->close(ctx);
				throw (new(ctx) java::io::IOException(ctx));
			}
						else 
			{
				maxNextCharInd += i;
			}
			return;
		}
		catch(java::io::IOException* e)
		{
			if(bufpos != 0)
			{
				--bufpos;
				backup(0, ctx);
			}
						else 
			{
				bufline->set(line,bufpos, ctx);
				bufcolumn->set(column,bufpos, ctx);
			}
			throw e;
		}
	}
}
wchar_t JavaCharStream::ReadByte(ThreadContext* ctx)
{
	if(++nextCharInd >= maxNextCharInd)
	{
		FillBuff(ctx);
	}
	return nextCharBuf->get(nextCharInd);
}
void JavaCharStream::AdjustBuffSize(ThreadContext* ctx) throw() 
{
	if(available == bufsize)
	{
		if(tokenBegin > 2048)
		{
			bufpos = 0;
			available = tokenBegin;
		}
				else 
		{
			ExpandBuff(false, ctx);
		}
	}
		else 
	{
		if(available > tokenBegin)
		{
			available = bufsize;
		}
				else 
		{
			if((tokenBegin - available) < 2048)
			{
				ExpandBuff(true, ctx);
			}
						else 
			{
				available = tokenBegin;
			}
		}
	}
}
void JavaCharStream::UpdateLineColumn(wchar_t c, ThreadContext* ctx) throw() 
{
	column ++ ;
	if(prevCharIsLF)
	{
		prevCharIsLF = false;
		line += (column = 1);
	}
		else 
	{
		if(prevCharIsCR)
		{
			prevCharIsCR = false;
			if(c == L'\n')
			{
				prevCharIsLF = true;
			}
						else 
			{
				line += (column = 1);
			}
		}
	}
	switch(c) {
	case L'\r':
		prevCharIsCR = true;
		break ;
	case L'\n':
		prevCharIsLF = true;
		break ;
	case L'\t':
		column -- ;
		column += (tabSize - (column % tabSize));
		break ;
	default:
		break ;
	}
	bufline->set(line,bufpos, ctx);
	bufcolumn->set(column,bufpos, ctx);
}
bool JavaCharStream::getTrackLineColumn(ThreadContext* ctx) throw() 
{
	return trackLineColumn;
}
void JavaCharStream::setTrackLineColumn(bool tlc, ThreadContext* ctx) throw() 
{
	trackLineColumn = tlc;
}
int JavaCharStream::hexval(wchar_t c, ThreadContext* ctx)
{
	switch(c) {
	case L'0':
		return 0;
	case L'1':
		return 1;
	case L'2':
		return 2;
	case L'3':
		return 3;
	case L'4':
		return 4;
	case L'5':
		return 5;
	case L'6':
		return 6;
	case L'7':
		return 7;
	case L'8':
		return 8;
	case L'9':
		return 9;
	case L'a':
	case L'A':
		return 10;
	case L'b':
	case L'B':
		return 11;
	case L'c':
	case L'C':
		return 12;
	case L'd':
	case L'D':
		return 13;
	case L'e':
	case L'E':
		return 14;
	case L'f':
	case L'F':
		return 15;
	}
	throw (new(ctx) java::io::IOException(ctx));
}
}}

