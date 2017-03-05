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




constexpr const long long AlinousPlusParserConstants::EOF;
constexpr const long long AlinousPlusParserConstants::NOTASCII;
constexpr const long long AlinousPlusParserConstants::ASCILETTER;
constexpr const long long AlinousPlusParserConstants::NUMBERLETTER;
constexpr const long long AlinousPlusParserConstants::CHARACTOR;
constexpr const long long AlinousPlusParserConstants::INTEGER_LITERAL;
constexpr const long long AlinousPlusParserConstants::DECIMAL_LITERAL;
constexpr const long long AlinousPlusParserConstants::HEX_LITERAL;
constexpr const long long AlinousPlusParserConstants::OCTAL_LITERAL;
constexpr const long long AlinousPlusParserConstants::FLOATING_POINT_LITERAL;
constexpr const long long AlinousPlusParserConstants::DECIMAL_FLOATING_POINT_LITERAL;
constexpr const long long AlinousPlusParserConstants::DECIMAL_EXPONENT;
constexpr const long long AlinousPlusParserConstants::HEXADECIMAL_FLOATING_POINT_LITERAL;
constexpr const long long AlinousPlusParserConstants::HEXADECIMAL_EXPONENT;
constexpr const long long AlinousPlusParserConstants::STRING_LITERAL;
constexpr const long long AlinousPlusParserConstants::CHARACTER_LITERAL;
constexpr const long long AlinousPlusParserConstants::SQL_STRING_LITERAL;
constexpr const long long AlinousPlusParserConstants::SEMI_COLON;
constexpr const long long AlinousPlusParserConstants::EQUALS;
constexpr const long long AlinousPlusParserConstants::ASTERISK;
constexpr const long long AlinousPlusParserConstants::PLUSPLUS;
constexpr const long long AlinousPlusParserConstants::PLUS;
constexpr const long long AlinousPlusParserConstants::MINUSMINUS;
constexpr const long long AlinousPlusParserConstants::MINUS;
constexpr const long long AlinousPlusParserConstants::DIV;
constexpr const long long AlinousPlusParserConstants::MODULO;
constexpr const long long AlinousPlusParserConstants::LOGICAL_AND;
constexpr const long long AlinousPlusParserConstants::LOGICAL_OR;
constexpr const long long AlinousPlusParserConstants::BIT_AND;
constexpr const long long AlinousPlusParserConstants::BIT_OR;
constexpr const long long AlinousPlusParserConstants::L_PARENTHESIS;
constexpr const long long AlinousPlusParserConstants::R_PARENTHESIS;
constexpr const long long AlinousPlusParserConstants::L_BRACKET;
constexpr const long long AlinousPlusParserConstants::R_BRACKET;
constexpr const long long AlinousPlusParserConstants::DOLLAR;
constexpr const long long AlinousPlusParserConstants::DOT;
constexpr const long long AlinousPlusParserConstants::COMMA;
constexpr const long long AlinousPlusParserConstants::AT_AT_MARK;
constexpr const long long AlinousPlusParserConstants::AT_MARK;
constexpr const long long AlinousPlusParserConstants::L_BRACE;
constexpr const long long AlinousPlusParserConstants::R_BRACE;
constexpr const long long AlinousPlusParserConstants::CMP_EQUALS;
constexpr const long long AlinousPlusParserConstants::CMP_NOTEQUALS;
constexpr const long long AlinousPlusParserConstants::GT;
constexpr const long long AlinousPlusParserConstants::GEQ;
constexpr const long long AlinousPlusParserConstants::LT;
constexpr const long long AlinousPlusParserConstants::LEQ;
constexpr const long long AlinousPlusParserConstants::NOT;
constexpr const long long AlinousPlusParserConstants::COLON;
constexpr const long long AlinousPlusParserConstants::RSIGNEDSHIFT;
constexpr const long long AlinousPlusParserConstants::RUNSIGNEDSHIFT;
constexpr const long long AlinousPlusParserConstants::IMPORT;
constexpr const long long AlinousPlusParserConstants::PACKAGE;
constexpr const long long AlinousPlusParserConstants::CLASS;
constexpr const long long AlinousPlusParserConstants::CLASS_INTERFACE;
constexpr const long long AlinousPlusParserConstants::ABSTRACT;
constexpr const long long AlinousPlusParserConstants::BREAK;
constexpr const long long AlinousPlusParserConstants::BYTE;
constexpr const long long AlinousPlusParserConstants::CASE;
constexpr const long long AlinousPlusParserConstants::CATCH;
constexpr const long long AlinousPlusParserConstants::_CONST;
constexpr const long long AlinousPlusParserConstants::CONTINUE;
constexpr const long long AlinousPlusParserConstants::DO;
constexpr const long long AlinousPlusParserConstants::ELSE;
constexpr const long long AlinousPlusParserConstants::ENUM;
constexpr const long long AlinousPlusParserConstants::EXTENDS;
constexpr const long long AlinousPlusParserConstants::FINAL;
constexpr const long long AlinousPlusParserConstants::FINALLY;
constexpr const long long AlinousPlusParserConstants::FOR;
constexpr const long long AlinousPlusParserConstants::GOTO;
constexpr const long long AlinousPlusParserConstants::IF;
constexpr const long long AlinousPlusParserConstants::IMPLEMENTS;
constexpr const long long AlinousPlusParserConstants::INSTANCEOF;
constexpr const long long AlinousPlusParserConstants::NATIVE;
constexpr const long long AlinousPlusParserConstants::NEW;
constexpr const long long AlinousPlusParserConstants::PRIVATE;
constexpr const long long AlinousPlusParserConstants::PROTECTED;
constexpr const long long AlinousPlusParserConstants::PUBLIC;
constexpr const long long AlinousPlusParserConstants::RETURN;
constexpr const long long AlinousPlusParserConstants::STATIC;
constexpr const long long AlinousPlusParserConstants::SUPER;
constexpr const long long AlinousPlusParserConstants::SWITCH;
constexpr const long long AlinousPlusParserConstants::SYNCHRONIZED;
constexpr const long long AlinousPlusParserConstants::THIS;
constexpr const long long AlinousPlusParserConstants::THROW;
constexpr const long long AlinousPlusParserConstants::THROWS;
constexpr const long long AlinousPlusParserConstants::TRY;
constexpr const long long AlinousPlusParserConstants::VOID;
constexpr const long long AlinousPlusParserConstants::WHILE;
constexpr const long long AlinousPlusParserConstants::INCLUDE;
constexpr const long long AlinousPlusParserConstants::DOWNLOAD;
constexpr const long long AlinousPlusParserConstants::REDIRECT;
constexpr const long long AlinousPlusParserConstants::REFERER_FROM;
constexpr const long long AlinousPlusParserConstants::VALIDATOR;
constexpr const long long AlinousPlusParserConstants::PARALLEL;
constexpr const long long AlinousPlusParserConstants::LOCAL;
constexpr const long long AlinousPlusParserConstants::TRUE;
constexpr const long long AlinousPlusParserConstants::FALSE;
constexpr const long long AlinousPlusParserConstants::SELECT;
constexpr const long long AlinousPlusParserConstants::INSERT;
constexpr const long long AlinousPlusParserConstants::UPDATE;
constexpr const long long AlinousPlusParserConstants::DELETE;
constexpr const long long AlinousPlusParserConstants::INTO;
constexpr const long long AlinousPlusParserConstants::FROM;
constexpr const long long AlinousPlusParserConstants::WHERE;
constexpr const long long AlinousPlusParserConstants::OR;
constexpr const long long AlinousPlusParserConstants::SQLAND;
constexpr const long long AlinousPlusParserConstants::LIKE;
constexpr const long long AlinousPlusParserConstants::ESCAPE;
constexpr const long long AlinousPlusParserConstants::LEFT;
constexpr const long long AlinousPlusParserConstants::RIGHT;
constexpr const long long AlinousPlusParserConstants::NATURAL;
constexpr const long long AlinousPlusParserConstants::INNER;
constexpr const long long AlinousPlusParserConstants::OUTER;
constexpr const long long AlinousPlusParserConstants::FULL;
constexpr const long long AlinousPlusParserConstants::JOIN;
constexpr const long long AlinousPlusParserConstants::CROSS;
constexpr const long long AlinousPlusParserConstants::SET;
constexpr const long long AlinousPlusParserConstants::VALUES;
constexpr const long long AlinousPlusParserConstants::GROUP;
constexpr const long long AlinousPlusParserConstants::BY;
constexpr const long long AlinousPlusParserConstants::HAVING;
constexpr const long long AlinousPlusParserConstants::ORDER;
constexpr const long long AlinousPlusParserConstants::ASC;
constexpr const long long AlinousPlusParserConstants::DESC;
constexpr const long long AlinousPlusParserConstants::LIMIT;
constexpr const long long AlinousPlusParserConstants::OFFSET;
constexpr const long long AlinousPlusParserConstants::ON;
constexpr const long long AlinousPlusParserConstants::SQL_NOT;
constexpr const long long AlinousPlusParserConstants::AS;
constexpr const long long AlinousPlusParserConstants::DISTINCT;
constexpr const long long AlinousPlusParserConstants::SHARE;
constexpr const long long AlinousPlusParserConstants::NOWAIT;
constexpr const long long AlinousPlusParserConstants::OF;
constexpr const long long AlinousPlusParserConstants::IN;
constexpr const long long AlinousPlusParserConstants::BETWEEN;
constexpr const long long AlinousPlusParserConstants::IS;
constexpr const long long AlinousPlusParserConstants::BEGIN;
constexpr const long long AlinousPlusParserConstants::PREPARE;
constexpr const long long AlinousPlusParserConstants::TRANSACTION;
constexpr const long long AlinousPlusParserConstants::ISOLATION;
constexpr const long long AlinousPlusParserConstants::LEVEL;
constexpr const long long AlinousPlusParserConstants::COMMIT;
constexpr const long long AlinousPlusParserConstants::PREPARED;
constexpr const long long AlinousPlusParserConstants::END;
constexpr const long long AlinousPlusParserConstants::ROLLBACK;
constexpr const long long AlinousPlusParserConstants::CREATE;
constexpr const long long AlinousPlusParserConstants::DROP;
constexpr const long long AlinousPlusParserConstants::ALTER;
constexpr const long long AlinousPlusParserConstants::TABLE;
constexpr const long long AlinousPlusParserConstants::SQL_DEFAULT;
constexpr const long long AlinousPlusParserConstants::ADD;
constexpr const long long AlinousPlusParserConstants::RENAME;
constexpr const long long AlinousPlusParserConstants::COLUMN;
constexpr const long long AlinousPlusParserConstants::TO;
constexpr const long long AlinousPlusParserConstants::PRIMARY;
constexpr const long long AlinousPlusParserConstants::KEY;
constexpr const long long AlinousPlusParserConstants::UNIQUE;
constexpr const long long AlinousPlusParserConstants::CHECK;
constexpr const long long AlinousPlusParserConstants::RETURNS;
constexpr const long long AlinousPlusParserConstants::SETOF;
constexpr const long long AlinousPlusParserConstants::LANGUAGE;
constexpr const long long AlinousPlusParserConstants::REPLACE;
constexpr const long long AlinousPlusParserConstants::INDEX;
constexpr const long long AlinousPlusParserConstants::USING;
constexpr const long long AlinousPlusParserConstants::EACH;
constexpr const long long AlinousPlusParserConstants::ROW;
constexpr const long long AlinousPlusParserConstants::STATEMENT;
constexpr const long long AlinousPlusParserConstants::EXECUTE;
constexpr const long long AlinousPlusParserConstants::PROCEDURE;
constexpr const long long AlinousPlusParserConstants::EXISTS;
constexpr const long long AlinousPlusParserConstants::TRIGGER;
constexpr const long long AlinousPlusParserConstants::BEFORE;
constexpr const long long AlinousPlusParserConstants::AFTER;
constexpr const long long AlinousPlusParserConstants::FOREIGN;
constexpr const long long AlinousPlusParserConstants::REFERENCES;
constexpr const long long AlinousPlusParserConstants::ADJUST_WHERE;
constexpr const long long AlinousPlusParserConstants::ADJUST_SET;
constexpr const long long AlinousPlusParserConstants::BOOL;
constexpr const long long AlinousPlusParserConstants::_NULL;
constexpr const long long AlinousPlusParserConstants::FUNCTION;
constexpr const long long AlinousPlusParserConstants::USE;
constexpr const long long AlinousPlusParserConstants::REGION;
constexpr const long long AlinousPlusParserConstants::PARTITION;
constexpr const long long AlinousPlusParserConstants::SUB;
constexpr const long long AlinousPlusParserConstants::SERIALIZABLE;
constexpr const long long AlinousPlusParserConstants::READ;
constexpr const long long AlinousPlusParserConstants::COMMITTED;
constexpr const long long AlinousPlusParserConstants::IDENTIFIER;
constexpr const long long AlinousPlusParserConstants::DEFAULT;
constexpr const long long AlinousPlusParserConstants::COMM;
constexpr const long long AlinousPlusParserConstants::L_COMM;
const StaticArrayObject<UnicodeStringWrapper> AlinousPlusParserConstants::__tokenImage = {ConstStr::getCNST_STR_1332(), ConstStr::getCNST_STR_1333(), ConstStr::getCNST_STR_1334(), ConstStr::getCNST_STR_1335(), ConstStr::getCNST_STR_1336(), ConstStr::getCNST_STR_1337(), ConstStr::getCNST_STR_1338(), ConstStr::getCNST_STR_1339(), ConstStr::getCNST_STR_1340(), ConstStr::getCNST_STR_1341(), ConstStr::getCNST_STR_1342(), ConstStr::getCNST_STR_1343(), ConstStr::getCNST_STR_1344(), ConstStr::getCNST_STR_1345(), ConstStr::getCNST_STR_1346(), ConstStr::getCNST_STR_1347(), ConstStr::getCNST_STR_1348(), ConstStr::getCNST_STR_1349(), ConstStr::getCNST_STR_1350(), ConstStr::getCNST_STR_1351(), ConstStr::getCNST_STR_1352(), ConstStr::getCNST_STR_1353(), ConstStr::getCNST_STR_1354(), ConstStr::getCNST_STR_1355(), ConstStr::getCNST_STR_1356(), ConstStr::getCNST_STR_1357(), ConstStr::getCNST_STR_1358(), ConstStr::getCNST_STR_1359(), ConstStr::getCNST_STR_1360(), ConstStr::getCNST_STR_1361(), ConstStr::getCNST_STR_1362(), ConstStr::getCNST_STR_1363(), ConstStr::getCNST_STR_1364(), ConstStr::getCNST_STR_1365(), ConstStr::getCNST_STR_1366(), ConstStr::getCNST_STR_1367(), ConstStr::getCNST_STR_1368(), ConstStr::getCNST_STR_1369(), ConstStr::getCNST_STR_1370(), ConstStr::getCNST_STR_1371(), ConstStr::getCNST_STR_1372(), ConstStr::getCNST_STR_1373(), ConstStr::getCNST_STR_1374(), ConstStr::getCNST_STR_1375(), ConstStr::getCNST_STR_1376(), ConstStr::getCNST_STR_1377(), ConstStr::getCNST_STR_1378(), ConstStr::getCNST_STR_1379(), ConstStr::getCNST_STR_1380(), ConstStr::getCNST_STR_1381(), ConstStr::getCNST_STR_1382(), ConstStr::getCNST_STR_1383(), ConstStr::getCNST_STR_1384(), ConstStr::getCNST_STR_1385(), ConstStr::getCNST_STR_1386(), ConstStr::getCNST_STR_1387(), ConstStr::getCNST_STR_1388(), ConstStr::getCNST_STR_1389(), ConstStr::getCNST_STR_1390(), ConstStr::getCNST_STR_1391(), ConstStr::getCNST_STR_1392(), ConstStr::getCNST_STR_1393(), ConstStr::getCNST_STR_1394(), ConstStr::getCNST_STR_1395(), ConstStr::getCNST_STR_1396(), ConstStr::getCNST_STR_1397(), ConstStr::getCNST_STR_1398(), ConstStr::getCNST_STR_1399(), ConstStr::getCNST_STR_1400(), ConstStr::getCNST_STR_1401(), ConstStr::getCNST_STR_1402(), ConstStr::getCNST_STR_1403(), ConstStr::getCNST_STR_1404(), ConstStr::getCNST_STR_1405(), ConstStr::getCNST_STR_1406(), ConstStr::getCNST_STR_1407(), ConstStr::getCNST_STR_1408(), ConstStr::getCNST_STR_1409(), ConstStr::getCNST_STR_1410(), ConstStr::getCNST_STR_1411(), ConstStr::getCNST_STR_1412(), ConstStr::getCNST_STR_1413(), ConstStr::getCNST_STR_1414(), ConstStr::getCNST_STR_1415(), ConstStr::getCNST_STR_1416(), ConstStr::getCNST_STR_1417(), ConstStr::getCNST_STR_1418(), ConstStr::getCNST_STR_1419(), ConstStr::getCNST_STR_1420(), ConstStr::getCNST_STR_1421(), ConstStr::getCNST_STR_1422(), ConstStr::getCNST_STR_1423(), ConstStr::getCNST_STR_1424(), ConstStr::getCNST_STR_1425(), ConstStr::getCNST_STR_1426(), ConstStr::getCNST_STR_1427(), ConstStr::getCNST_STR_1428(), ConstStr::getCNST_STR_1429(), ConstStr::getCNST_STR_1430(), ConstStr::getCNST_STR_1431(), ConstStr::getCNST_STR_1432(), ConstStr::getCNST_STR_1433(), ConstStr::getCNST_STR_1434(), ConstStr::getCNST_STR_1435(), ConstStr::getCNST_STR_1436(), ConstStr::getCNST_STR_1437(), ConstStr::getCNST_STR_1438(), ConstStr::getCNST_STR_1439(), ConstStr::getCNST_STR_1440(), ConstStr::getCNST_STR_1441(), ConstStr::getCNST_STR_1442(), ConstStr::getCNST_STR_1443(), ConstStr::getCNST_STR_1444(), ConstStr::getCNST_STR_1445(), ConstStr::getCNST_STR_1446(), ConstStr::getCNST_STR_1447(), ConstStr::getCNST_STR_1448(), ConstStr::getCNST_STR_1449(), ConstStr::getCNST_STR_1450(), ConstStr::getCNST_STR_1451(), ConstStr::getCNST_STR_1452(), ConstStr::getCNST_STR_1453(), ConstStr::getCNST_STR_1454(), ConstStr::getCNST_STR_1455(), ConstStr::getCNST_STR_1456(), ConstStr::getCNST_STR_1457(), ConstStr::getCNST_STR_1458(), ConstStr::getCNST_STR_1459(), ConstStr::getCNST_STR_1460(), ConstStr::getCNST_STR_1461(), ConstStr::getCNST_STR_1462(), ConstStr::getCNST_STR_1463(), ConstStr::getCNST_STR_1464(), ConstStr::getCNST_STR_1465(), ConstStr::getCNST_STR_1466(), ConstStr::getCNST_STR_1467(), ConstStr::getCNST_STR_1468(), ConstStr::getCNST_STR_1469(), ConstStr::getCNST_STR_1470(), ConstStr::getCNST_STR_1471(), ConstStr::getCNST_STR_1472(), ConstStr::getCNST_STR_1473(), ConstStr::getCNST_STR_1474(), ConstStr::getCNST_STR_1475(), ConstStr::getCNST_STR_1476(), ConstStr::getCNST_STR_1477(), ConstStr::getCNST_STR_1478(), ConstStr::getCNST_STR_1479(), ConstStr::getCNST_STR_1480(), ConstStr::getCNST_STR_1481(), ConstStr::getCNST_STR_1482(), ConstStr::getCNST_STR_1483(), ConstStr::getCNST_STR_1484(), ConstStr::getCNST_STR_1485(), ConstStr::getCNST_STR_1486(), ConstStr::getCNST_STR_1487(), ConstStr::getCNST_STR_1488(), ConstStr::getCNST_STR_1489(), ConstStr::getCNST_STR_1490(), ConstStr::getCNST_STR_1491(), ConstStr::getCNST_STR_1492(), ConstStr::getCNST_STR_1493(), ConstStr::getCNST_STR_1494(), ConstStr::getCNST_STR_1495(), ConstStr::getCNST_STR_1496(), ConstStr::getCNST_STR_1497(), ConstStr::getCNST_STR_1498(), ConstStr::getCNST_STR_1499(), ConstStr::getCNST_STR_1500(), ConstStr::getCNST_STR_1501(), ConstStr::getCNST_STR_1502(), ConstStr::getCNST_STR_1503(), ConstStr::getCNST_STR_1504(), ConstStr::getCNST_STR_1505(), ConstStr::getCNST_STR_1506(), ConstStr::getCNST_STR_1507(), ConstStr::getCNST_STR_1508(), ConstStr::getCNST_STR_1509(), ConstStr::getCNST_STR_1510(), ConstStr::getCNST_STR_1511(), ConstStr::getCNST_STR_1512(), ConstStr::getCNST_STR_1513(), ConstStr::getCNST_STR_1514(), ConstStr::getCNST_STR_1515(), ConstStr::getCNST_STR_1516(), ConstStr::getCNST_STR_1517(), ConstStr::getCNST_STR_1518(), ConstStr::getCNST_STR_1519(), ConstStr::getCNST_STR_1520(), ConstStr::getCNST_STR_1521(), ConstStr::getCNST_STR_1522(), ConstStr::getCNST_STR_1523(), ConstStr::getCNST_STR_1524(), ConstStr::getCNST_STR_1525(), ConstStr::getCNST_STR_1526(), ConstStr::getCNST_STR_1335(), ConstStr::getCNST_STR_1527(), ConstStr::getCNST_STR_1528(), ConstStr::getCNST_STR_1529(), ConstStr::getCNST_STR_1530(), ConstStr::getCNST_STR_1531(), ConstStr::getCNST_STR_1532(), ConstStr::getCNST_STR_1533(), ConstStr::getCNST_STR_1534(), ConstStr::getCNST_STR_1535(), ConstStr::getCNST_STR_1536(), ConstStr::getCNST_STR_1537(), ConstStr::getCNST_STR_1538(), ConstStr::getCNST_STR_1539(), ConstStr::getCNST_STR_1540(), ConstStr::getCNST_STR_1541(), ConstStr::getCNST_STR_1542(), ConstStr::getCNST_STR_1543(), ConstStr::getCNST_STR_1544()};
IArrayObject<String>* AlinousPlusParserConstants::tokenImage = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__tokenImage);
bool AlinousPlusParserConstants::__init_done = __init_static_variables();
bool AlinousPlusParserConstants::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousPlusParserConstants", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousPlusParserConstants::~AlinousPlusParserConstants() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousPlusParserConstants::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}

