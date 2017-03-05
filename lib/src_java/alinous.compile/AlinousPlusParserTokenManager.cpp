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
#include "alinous.btree.scan/BTreeScanner.h"
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
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.remote.db.command.data/SchemaData.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
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
#include "alinous.db.trx/DbVersionContext.h"
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
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/ConditionalExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
#include "alinous.compile.expression.blexp/BooleanSubExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanCollectionExpression.h"
#include "alinous.compile.expression.blexp/AndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalAndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalOrExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanExpression.h"
#include "alinous.compile.expression.blexp/EqualityExpression.h"
#include "alinous.compile.expression.blexp/ExclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InstanceOfExpression.h"
#include "alinous.compile.expression.blexp/NotExpression.h"
#include "alinous.compile.expression.blexp/RelationalExpression.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.btree/LongKey.h"
#include "alinous.db.table/IOidPublisher.h"
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
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.sql.parts/SQLExpressionListAll.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.compile.sql.expression/SQLSubExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLCollectionExpression.h"
#include "alinous.compile.sql.expression/SQLAdditiveExpression.h"
#include "alinous.compile.sql.expression/SQLLiteral.h"
#include "alinous.compile.sql.expression/SQLMultiplicativeExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.sql.expression/SQLSubqueryExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBooleanLiteral.h"
#include "alinous.compile.sql.expression.blexp/SQLEqualityExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLInExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLIsNullExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLLikeExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLNotExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLOrExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLRelationalExpression.h"
#include "alinous.compile.sql.select.join/AbstractJoinTarget.h"
#include "alinous.compile.sql.select.join/DomVariableJoinTarget.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.select.join/AbstractSQLJoin.h"
#include "alinous.compile.sql.select.join/InnerJoin.h"
#include "alinous.compile.sql.select.join/JoinSubQueryTarget.h"
#include "alinous.compile.sql.select.join/LeftJoin.h"
#include "alinous.compile.sql.select.join/NaturalJoin.h"
#include "alinous.compile.sql.select.join/RightJoin.h"
#include "alinous.compile.sql.select.join/CrossJoin.h"
#include "alinous.compile.sql.select.join/TableList.h"
#include "alinous.compile.sql.select.join/WrappedJoinTarget.h"
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
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table.scan/IndexListScannerParam.h"
#include "alinous.db.table.scan/IndexRangeScannerParam.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndexScanner.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.table.scan/TableIndexScanner.h"
#include "alinous.db.table.scan/SingleTableIndexScanner.h"
#include "alinous.compile.sql.analyze/IndexScanStrategyPlan.h"
#include "alinous.compile.sql.analyze/IndexScanStrategy.h"
#include "alinous.compile.sql.analyze/InnerNecessaryCondition.h"
#include "alinous.compile.sql.analyze/ScanSingleStrategy.h"
#include "alinous.compile.sql.select.join/TableJoinTarget.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/DbTransaction.h"
#include "java.lang/Integer.h"
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





const StaticArrayObjectPrimitive<uint64_t> AlinousPlusParserTokenManager::__jjbitVec0 = {0xfffffffffffffffeL, 0xffffffffffffffffL, 0xffffffffffffffffL, 0xffffffffffffffffL};
IArrayObjectPrimitive<uint64_t>* AlinousPlusParserTokenManager::jjbitVec0 = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjbitVec0);
const StaticArrayObjectPrimitive<uint64_t> AlinousPlusParserTokenManager::__jjbitVec2 = {0x0L, 0x0L, 0xffffffffffffffffL, 0xffffffffffffffffL};
IArrayObjectPrimitive<uint64_t>* AlinousPlusParserTokenManager::jjbitVec2 = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjbitVec2);
const StaticArrayObjectPrimitive<uint64_t> AlinousPlusParserTokenManager::__jjnextStates = {21, 22, 8, 25, 26, 29, 30, 36, 38, 46, 47, 49, 10, 11, 13, 57, 59, 2, 60, 67, 4, 5, 8, 10, 11, 15, 13, 21, 22, 8, 31, 32, 8, 46, 47, 49, 46, 47, 51, 49, 46, 47, 55, 49, 61, 62, 68, 69, 70, 6, 7, 12, 14, 16, 23, 24, 27, 28, 33, 34, 39, 40, 42, 44, 48, 50, 52, 54, 63, 64, 65, 66, 71, 72};
IArrayObjectPrimitive<uint64_t>* AlinousPlusParserTokenManager::jjnextStates = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjnextStates);
const StaticArrayObject<UnicodeStringWrapper> AlinousPlusParserTokenManager::__jjstrLiteralImages = {ConstStr::getCNST_STR_4(), (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, ConstStr::getCNST_STR_1550(), ConstStr::getCNST_STR_1551(), ConstStr::getCNST_STR_1552(), ConstStr::getCNST_STR_1553(), ConstStr::getCNST_STR_1554(), ConstStr::getCNST_STR_1555(), ConstStr::getCNST_STR_1556(), ConstStr::getCNST_STR_1557(), ConstStr::getCNST_STR_1558(), ConstStr::getCNST_STR_1559(), ConstStr::getCNST_STR_1560(), ConstStr::getCNST_STR_1561(), ConstStr::getCNST_STR_1562(), ConstStr::getCNST_STR_1563(), ConstStr::getCNST_STR_1564(), ConstStr::getCNST_STR_1565(), ConstStr::getCNST_STR_1566(), ConstStr::getCNST_STR_1567(), ConstStr::getCNST_STR_1568(), ConstStr::getCNST_STR_1569(), ConstStr::getCNST_STR_1570(), ConstStr::getCNST_STR_1571(), ConstStr::getCNST_STR_1572(), ConstStr::getCNST_STR_1573(), ConstStr::getCNST_STR_1574(), ConstStr::getCNST_STR_1575(), ConstStr::getCNST_STR_1576(), ConstStr::getCNST_STR_1577(), ConstStr::getCNST_STR_1578(), ConstStr::getCNST_STR_1579(), ConstStr::getCNST_STR_1580(), ConstStr::getCNST_STR_1581(), ConstStr::getCNST_STR_1582(), ConstStr::getCNST_STR_1583(), ConstStr::getCNST_STR_1584(), ConstStr::getCNST_STR_1585(), ConstStr::getCNST_STR_1586(), ConstStr::getCNST_STR_1587(), ConstStr::getCNST_STR_1588(), ConstStr::getCNST_STR_1589(), ConstStr::getCNST_STR_1590(), ConstStr::getCNST_STR_1591(), ConstStr::getCNST_STR_1592(), ConstStr::getCNST_STR_1593(), ConstStr::getCNST_STR_1594(), ConstStr::getCNST_STR_1595(), ConstStr::getCNST_STR_1596(), ConstStr::getCNST_STR_1597(), ConstStr::getCNST_STR_1598(), ConstStr::getCNST_STR_1599(), ConstStr::getCNST_STR_1600(), ConstStr::getCNST_STR_1601(), ConstStr::getCNST_STR_1602(), ConstStr::getCNST_STR_1603(), ConstStr::getCNST_STR_1604(), ConstStr::getCNST_STR_1605(), ConstStr::getCNST_STR_1606(), ConstStr::getCNST_STR_1607(), ConstStr::getCNST_STR_1608(), ConstStr::getCNST_STR_1609(), ConstStr::getCNST_STR_1610(), ConstStr::getCNST_STR_1611(), ConstStr::getCNST_STR_1612(), ConstStr::getCNST_STR_1613(), ConstStr::getCNST_STR_1614(), ConstStr::getCNST_STR_1615(), ConstStr::getCNST_STR_1616(), ConstStr::getCNST_STR_1617(), ConstStr::getCNST_STR_1618(), ConstStr::getCNST_STR_1619(), ConstStr::getCNST_STR_1620(), ConstStr::getCNST_STR_1621(), ConstStr::getCNST_STR_1622(), ConstStr::getCNST_STR_1623(), ConstStr::getCNST_STR_1624(), ConstStr::getCNST_STR_1625(), ConstStr::getCNST_STR_1626(), ConstStr::getCNST_STR_1627(), ConstStr::getCNST_STR_1628(), ConstStr::getCNST_STR_1629(), ConstStr::getCNST_STR_1630(), (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, ConstStr::getCNST_STR_1631(), ConstStr::getCNST_STR_1632(), ConstStr::getCNST_STR_1633(), ConstStr::getCNST_STR_1634(), ConstStr::getCNST_STR_1635(), ConstStr::getCNST_STR_1636(), ConstStr::getCNST_STR_1637(), ConstStr::getCNST_STR_1638(), ConstStr::getCNST_STR_1639(), ConstStr::getCNST_STR_1640(), ConstStr::getCNST_STR_1641(), ConstStr::getCNST_STR_1642(), ConstStr::getCNST_STR_1643(), ConstStr::getCNST_STR_1644(), ConstStr::getCNST_STR_1645()};
IArrayObject<String>* AlinousPlusParserTokenManager::jjstrLiteralImages = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__jjstrLiteralImages);
const StaticArrayObject<UnicodeStringWrapper> AlinousPlusParserTokenManager::__lexStateNames = {ConstStr::getCNST_STR_1646(), ConstStr::getCNST_STR_1647(), ConstStr::getCNST_STR_1648()};
IArrayObject<String>* AlinousPlusParserTokenManager::lexStateNames = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__lexStateNames);
const StaticArrayObjectPrimitive<long long> AlinousPlusParserTokenManager::__jjnewLexState = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 2, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
IArrayObjectPrimitive<long long>* AlinousPlusParserTokenManager::jjnewLexState = (IArrayObjectPrimitive<long long>*)const_cast<StaticArrayObjectPrimitive<long long>*>(&__jjnewLexState);
const StaticArrayObjectPrimitive<uint64_t> AlinousPlusParserTokenManager::__jjtoToken = {0xfffffffffffc2201L, 0xffffffffffffffffL, 0xffffffffffffffffL, 0x3fff81L};
IArrayObjectPrimitive<uint64_t>* AlinousPlusParserTokenManager::jjtoToken = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjtoToken);
const StaticArrayObjectPrimitive<uint64_t> AlinousPlusParserTokenManager::__jjtoSkip = {0x1eL, 0x0L, 0x0L, 0x28L};
IArrayObjectPrimitive<uint64_t>* AlinousPlusParserTokenManager::jjtoSkip = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjtoSkip);
const StaticArrayObjectPrimitive<uint64_t> AlinousPlusParserTokenManager::__jjtoSpecial = {0x0L, 0x0L, 0x0L, 0x28L};
IArrayObjectPrimitive<uint64_t>* AlinousPlusParserTokenManager::jjtoSpecial = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjtoSpecial);
const StaticArrayObjectPrimitive<uint64_t> AlinousPlusParserTokenManager::__jjtoMore = {0x0L, 0x0L, 0x0L, 0x56L};
IArrayObjectPrimitive<uint64_t>* AlinousPlusParserTokenManager::jjtoMore = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjtoMore);
bool AlinousPlusParserTokenManager::__init_done = __init_static_variables();
bool AlinousPlusParserTokenManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousPlusParserTokenManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousPlusParserTokenManager::AlinousPlusParserTokenManager(JavaCharStream* stream, ThreadContext* ctx) : IObject(ctx), AlinousPlusParserConstants(ctx), debugStream(__GC_INS(this, System::out, java::io::PrintStream)), curLexState(0), defaultLexState(0), jjnewStateCnt(0), jjround(0), jjmatchedPos(0), jjmatchedKind(0), input_stream(nullptr), curChar(0), jjrounds(__GC_INS(this, ((IArrayObjectPrimitive<uint64_t>*)new(ctx) ArrayObjectPrimitive<uint64_t>(ArrayAllocatorPrimitive<uint64_t>::allocatep(ctx, 73), ctx)), IArrayObjectPrimitive<uint64_t>)), jjstateSet(__GC_INS(this, ((IArrayObjectPrimitive<uint64_t>*)new(ctx) ArrayObjectPrimitive<uint64_t>(ArrayAllocatorPrimitive<uint64_t>::allocatep(ctx, 2 * 73), ctx)), IArrayObjectPrimitive<uint64_t>)), jjimage(__GC_INS(this, (new(ctx) StringBuilder(ctx)), StringBuilder)), image(__GC_INS(this, jjimage, StringBuilder)), jjimageLen(0), lengthOfMatch(0)
{
	if(JavaCharStream::staticFlag)
	{
		throw (new(ctx) Error(ConstStr::getCNST_STR_1547(), ctx));
	}
	__GC_MV(this, &(input_stream), stream, JavaCharStream);
}
void AlinousPlusParserTokenManager::__construct_impl(JavaCharStream* stream, ThreadContext* ctx)
{
	if(JavaCharStream::staticFlag)
	{
		throw (new(ctx) Error(ConstStr::getCNST_STR_1547(), ctx));
	}
	__GC_MV(this, &(input_stream), stream, JavaCharStream);
}
 AlinousPlusParserTokenManager::AlinousPlusParserTokenManager(JavaCharStream* stream, long long lexState, ThreadContext* ctx) : IObject(ctx), AlinousPlusParserConstants(ctx), debugStream(__GC_INS(this, System::out, java::io::PrintStream)), curLexState(0), defaultLexState(0), jjnewStateCnt(0), jjround(0), jjmatchedPos(0), jjmatchedKind(0), input_stream(nullptr), curChar(0), jjrounds(__GC_INS(this, ((IArrayObjectPrimitive<uint64_t>*)new(ctx) ArrayObjectPrimitive<uint64_t>(ArrayAllocatorPrimitive<uint64_t>::allocatep(ctx, 73), ctx)), IArrayObjectPrimitive<uint64_t>)), jjstateSet(__GC_INS(this, ((IArrayObjectPrimitive<uint64_t>*)new(ctx) ArrayObjectPrimitive<uint64_t>(ArrayAllocatorPrimitive<uint64_t>::allocatep(ctx, 2 * 73), ctx)), IArrayObjectPrimitive<uint64_t>)), jjimage(__GC_INS(this, (new(ctx) StringBuilder(ctx)), StringBuilder)), image(__GC_INS(this, jjimage, StringBuilder)), jjimageLen(0), lengthOfMatch(0)
{
	ReInit(stream, ctx);
	SwitchTo(lexState, ctx);
}
void AlinousPlusParserTokenManager::__construct_impl(JavaCharStream* stream, long long lexState, ThreadContext* ctx)
{
	ReInit(stream, ctx);
	SwitchTo(lexState, ctx);
}
 AlinousPlusParserTokenManager::~AlinousPlusParserTokenManager()
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousPlusParserTokenManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousPlusParserTokenManager", L"~AlinousPlusParserTokenManager");
	__e_obj1.add(this->debugStream, this);
	debugStream = nullptr;
	__e_obj1.add(this->input_stream, this);
	input_stream = nullptr;
	__e_obj1.add(this->jjrounds, this);
	jjrounds = nullptr;
	__e_obj1.add(this->jjstateSet, this);
	jjstateSet = nullptr;
	__e_obj1.add(this->jjimage, this);
	jjimage = nullptr;
	__e_obj1.add(this->image, this);
	image = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousPlusParserTokenManager::setDebugStream(java::io::PrintStream* ds, ThreadContext* ctx)
{
	__GC_MV(this, &(debugStream), ds, java::io::PrintStream);
}
Token* AlinousPlusParserTokenManager::getNextToken(ThreadContext* ctx)
{
	Token* specialToken = nullptr;
	Token* matchedToken = 0;
	long long curPos = 0;
	for(; ; )
	{
		EOFLoop_continue:
		{
			try
			{
				curChar = input_stream->BeginToken(ctx);
			}
			catch(java::io::IOException* e)
			{
				jjmatchedKind = 0;
				jjmatchedPos = -1;
				matchedToken = jjFillToken(ctx);
				__GC_MV(matchedToken, &(matchedToken->specialToken), specialToken, Token);
				return matchedToken;
			}
		}
		__GC_MV(this, &(image), jjimage, StringBuilder);
		image->setLength(0, ctx);
		jjimageLen = 0;
		for(; ; )
		{
			switch(curLexState) {
			case 0:
				jjmatchedKind = 0x7fffffff;
				jjmatchedPos = 0;
				curPos = jjMoveStringLiteralDfa0_0(ctx);
				break ;
			case 1:
				jjmatchedKind = 0x7fffffff;
				jjmatchedPos = 0;
				curPos = jjMoveStringLiteralDfa0_1(ctx);
				if(jjmatchedPos == (long long)0 && jjmatchedKind > (long long)198)
				{
					jjmatchedKind = 198;
				}
				break ;
			case 2:
				jjmatchedKind = 0x7fffffff;
				jjmatchedPos = 0;
				curPos = jjMoveStringLiteralDfa0_2(ctx);
				if(jjmatchedPos == (long long)0 && jjmatchedKind > (long long)196)
				{
					jjmatchedKind = 196;
				}
				break ;
			}
			if(jjmatchedKind != (long long)0x7fffffff)
			{
				if(jjmatchedPos + 1 < curPos)
				{
					input_stream->backup((int)curPos - jjmatchedPos - 1, ctx);
				}
				if((jjtoToken->get(jjmatchedKind >> 6) & (1L << (jjmatchedKind & 077))) != (uint64_t)0L)
				{
					matchedToken = jjFillToken(ctx);
					__GC_MV(matchedToken, &(matchedToken->specialToken), specialToken, Token);
					if(jjnewLexState->get(jjmatchedKind) != (long long)-1)
					{
						curLexState = jjnewLexState->get(jjmatchedKind);
					}
					return matchedToken;
				}
								else 
				{
					if((jjtoSkip->get(jjmatchedKind >> 6) & (1L << (jjmatchedKind & 077))) != (uint64_t)0L)
					{
						if((jjtoSpecial->get(jjmatchedKind >> 6) & (1L << (jjmatchedKind & 077))) != (uint64_t)0L)
						{
							matchedToken = jjFillToken(ctx);
							if(specialToken == nullptr)
							{
								specialToken = matchedToken;
							}
														else 
							{
								__GC_MV(matchedToken, &(matchedToken->specialToken), specialToken, Token);
								specialToken = (__GC_MV(specialToken, &(specialToken->next), matchedToken, Token));
							}
							SkipLexicalActions(matchedToken, ctx);
						}
												else 
						{
							SkipLexicalActions(nullptr, ctx);
						}
						if(jjnewLexState->get(jjmatchedKind) != (long long)-1)
						{
							curLexState = jjnewLexState->get(jjmatchedKind);
						}
						goto EOFLoop_continue;
					}
				}
				jjimageLen += jjmatchedPos + 1;
				if(jjnewLexState->get(jjmatchedKind) != (long long)-1)
				{
					curLexState = jjnewLexState->get(jjmatchedKind);
				}
				curPos = 0;
				jjmatchedKind = 0x7fffffff;
				{
					try
					{
						curChar = input_stream->readChar(ctx);
						continue;
					}
					catch(java::io::IOException* e1)
					{
					}
				}
			}
			long long error_line = input_stream->getEndLine(ctx);
			long long error_column = input_stream->getEndColumn(ctx);
			String* error_after = nullptr;
			bool EOFSeen = false;
			{
				try
				{
					input_stream->readChar(ctx);
					input_stream->backup(1, ctx);
				}
				catch(java::io::IOException* e1)
				{
					EOFSeen = true;
					error_after = curPos <= (long long)1 ? ConstStr::getCNST_STR_4() : input_stream->GetImage(ctx);
					if(curChar == L'\n' || curChar == L'\r')
					{
						error_line ++ ;
						error_column = 0;
					}
										else 
					{
						error_column ++ ;
					}
				}
			}
			if(!EOFSeen)
			{
				input_stream->backup(1, ctx);
				error_after = curPos <= (long long)1 ? ConstStr::getCNST_STR_4() : input_stream->GetImage(ctx);
			}
			throw (new(ctx) TokenMgrError(EOFSeen, curLexState, error_line, error_column, error_after, curChar, TokenMgrError::LEXICAL_ERROR, ctx));
		}
	}
}
void AlinousPlusParserTokenManager::ReInit(JavaCharStream* stream, ThreadContext* ctx)
{
	jjmatchedPos = jjnewStateCnt = 0;
	curLexState = defaultLexState;
	__GC_MV(this, &(input_stream), stream, JavaCharStream);
	ReInitRounds(ctx);
}
void AlinousPlusParserTokenManager::ReInit(JavaCharStream* stream, long long lexState, ThreadContext* ctx)
{
	ReInit(stream, ctx);
	SwitchTo(lexState, ctx);
}
void AlinousPlusParserTokenManager::SwitchTo(long long lexState, ThreadContext* ctx)
{
	if(lexState >= (long long)3 || lexState < (long long)0)
	{
		throw (new(ctx) TokenMgrError(ConstStr::getCNST_STR_1548()->clone(ctx)->append(lexState, ctx)->append(ConstStr::getCNST_STR_1549(), ctx), TokenMgrError::INVALID_LEXICAL_STATE, ctx));
	}
		else 
	{
		curLexState = lexState;
	}
}
Token* AlinousPlusParserTokenManager::jjFillToken(ThreadContext* ctx)
{
	Token* t = 0;
	String* curTokenImage = 0;
	long long beginLine = 0;
	long long endLine = 0;
	long long beginColumn = 0;
	long long endColumn = 0;
	String* im = jjstrLiteralImages->get(jjmatchedKind);
	curTokenImage = (im == nullptr) ? input_stream->GetImage(ctx) : im;
	beginLine = input_stream->getBeginLine(ctx);
	beginColumn = input_stream->getBeginColumn(ctx);
	endLine = input_stream->getEndLine(ctx);
	endColumn = input_stream->getEndColumn(ctx);
	t = Token::newToken((int)jjmatchedKind, curTokenImage, ctx);
	t->beginLine = beginLine;
	t->endLine = endLine;
	t->beginColumn = beginColumn;
	t->endColumn = endColumn;
	return t;
}
void AlinousPlusParserTokenManager::SkipLexicalActions(Token* matchedToken, ThreadContext* ctx)
{
	switch(jjmatchedKind) {
	default:
		break ;
	}
}
long long AlinousPlusParserTokenManager::jjStopAtPos(long long pos, long long kind, ThreadContext* ctx)
{
	jjmatchedKind = kind;
	jjmatchedPos = pos;
	return pos + 1;
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa0_2(ThreadContext* ctx)
{
	switch(curChar) {
	case 10:
		return jjStopAtPos((long long)0, (long long)195, ctx);
	default:
		return 1;
		break;
	}
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa0_0(ThreadContext* ctx)
{
	switch(curChar) {
	case 9:
		jjmatchedKind = 2;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 10:
		jjmatchedKind = 3;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 13:
		jjmatchedKind = 4;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 32:
		jjmatchedKind = 1;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 33:
		jjmatchedKind = 51;
		return jjMoveStringLiteralDfa1_0((long long)0x400000000000L, (long long)0x0L, (long long)0x0L, (long long)0x0L, ctx);
	case 36:
		jjmatchedKind = 38;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 37:
		jjmatchedKind = 29;
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x0L, (long long)0x0L, (long long)0x2000L, ctx);
	case 38:
		jjmatchedKind = 32;
		return jjMoveStringLiteralDfa1_0((long long)0x40000000L, (long long)0x0L, (long long)0x0L, (long long)0x40000L, ctx);
	case 40:
		jjmatchedKind = 34;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 41:
		jjmatchedKind = 35;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 42:
		jjmatchedKind = 23;
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x0L, (long long)0x0L, (long long)0x800L, ctx);
	case 43:
		jjmatchedKind = 25;
		return jjMoveStringLiteralDfa1_0((long long)0x1000000L, (long long)0x0L, (long long)0x0L, (long long)0x4000L, ctx);
	case 44:
		jjmatchedKind = 40;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 45:
		jjmatchedKind = 27;
		return jjMoveStringLiteralDfa1_0((long long)0x4000000L, (long long)0x0L, (long long)0x0L, (long long)0x8000L, ctx);
	case 46:
		jjmatchedKind = 39;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 47:
		jjmatchedKind = 28;
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x0L, (long long)0x0L, (long long)0x1006L, ctx);
	case 58:
		jjmatchedKind = 52;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 59:
		jjmatchedKind = 21;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 60:
		jjmatchedKind = 49;
		return jjMoveStringLiteralDfa1_0((long long)0x4000000000000L, (long long)0x1000000000000L, (long long)0x0L, (long long)0x210200L, ctx);
	case 61:
		jjmatchedKind = 22;
		return jjMoveStringLiteralDfa1_0((long long)0x200000000000L, (long long)0x0L, (long long)0x0L, (long long)0x0L, ctx);
	case 62:
		jjmatchedKind = 47;
		return jjMoveStringLiteralDfa1_0((long long)0x61000000000000L, (long long)0x0L, (long long)0x0L, (long long)0x20000L, ctx);
	case 63:
		jjmatchedKind = 199;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 64:
		jjmatchedKind = 42;
		return jjMoveStringLiteralDfa1_0((long long)0x20000000000L, (long long)0x0L, (long long)0x0L, (long long)0x0L, ctx);
	case 65:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x8000400000000000L, (long long)0x32000009000020L, (long long)0x0L, ctx);
	case 66:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x1000000000000000L, (long long)0x41000000002800L, (long long)0x0L, ctx);
	case 67:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x100000000000000L, (long long)0x8000000420440000L, (long long)0x0L, ctx);
	case 68:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x20000000000L, (long long)0x4800041L, (long long)0x0L, ctx);
	case 69:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x0L, (long long)0x520000100000L, (long long)0x0L, ctx);
	case 70:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x40080000000000L, (long long)0x104000000000000L, (long long)0x0L, ctx);
	case 71:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x800000000000000L, (long long)0x0L, (long long)0x0L, ctx);
	case 72:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x2000000000000000L, (long long)0x0L, (long long)0x0L, ctx);
	case 73:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x10048000000000L, (long long)0x8000011400L, (long long)0x0L, ctx);
	case 74:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x80000000000000L, (long long)0x0L, (long long)0x0L, ctx);
	case 75:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x0L, (long long)0x100000000L, (long long)0x0L, ctx);
	case 76:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x2800000000000L, (long long)0x2000020002L, (long long)0x0L, ctx);
	case 78:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x8000000000000L, (long long)0x80000000000110L, (long long)0x0L, ctx);
	case 79:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x4020200000000000L, (long long)0x20cL, (long long)0x0L, ctx);
	case 80:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x0L, (long long)0x800200080084000L, (long long)0x0L, ctx);
	case 82:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x4000000000000L, (long long)0x4408044810200000L, (long long)0x0L, ctx);
	case 83:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x200004000000000L, (long long)0x3000081000000080L, (long long)0x0L, ctx);
	case 84:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x0L, (long long)0x800042008000L, (long long)0x0L, ctx);
	case 85:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x10000000000L, (long long)0x200010200000000L, (long long)0x0L, ctx);
	case 86:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x400000000000000L, (long long)0x0L, (long long)0x0L, ctx);
	case 87:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x100000000000L, (long long)0x0L, (long long)0x0L, ctx);
	case 91:
		jjmatchedKind = 36;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 93:
		jjmatchedKind = 37;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 94:
		jjmatchedKind = 200;
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x0L, (long long)0x0L, (long long)0x80000L, ctx);
	case 97:
		return jjMoveStringLiteralDfa1_0((long long)0x800000000000000L, (long long)0x8000400000000000L, (long long)0x32000009000020L, (long long)0x0L, ctx);
	case 98:
		return jjMoveStringLiteralDfa1_0((long long)0x3000000000000000L, (long long)0x1000000000000000L, (long long)0x41000000002800L, (long long)0x0L, ctx);
	case 99:
		return jjMoveStringLiteralDfa1_0((long long)0xc200000000000000L, (long long)0x100000000000003L, (long long)0x8000000420440000L, (long long)0x0L, ctx);
	case 100:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x20040000004L, (long long)0x4800041L, (long long)0x0L, ctx);
	case 101:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x38L, (long long)0x520000100000L, (long long)0x0L, ctx);
	case 102:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x400820000001c0L, (long long)0x104000000000000L, (long long)0x0L, ctx);
	case 103:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x800000000000200L, (long long)0x0L, (long long)0x0L, ctx);
	case 104:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x2000000000000000L, (long long)0x0L, (long long)0x0L, ctx);
	case 105:
		return jjMoveStringLiteralDfa1_0((long long)0x480000000000000L, (long long)0x10048020001c00L, (long long)0x8000011400L, (long long)0x0L, ctx);
	case 106:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x80000000000000L, (long long)0x0L, (long long)0x0L, ctx);
	case 107:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x0L, (long long)0x100000000L, (long long)0x0L, ctx);
	case 108:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x2800800000000L, (long long)0x2000020002L, (long long)0x0L, ctx);
	case 110:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x8000000006000L, (long long)0x80000000000110L, (long long)0x0L, ctx);
	case 111:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x4020200000000000L, (long long)0x20cL, (long long)0x0L, ctx);
	case 112:
		return jjMoveStringLiteralDfa1_0((long long)0x100000000000000L, (long long)0x400038000L, (long long)0x800200080084000L, (long long)0x0L, ctx);
	case 114:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x4000180040000L, (long long)0x4408044810200000L, (long long)0x0L, ctx);
	case 115:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x200004000780000L, (long long)0x3000081000000080L, (long long)0x0L, ctx);
	case 116:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x1007800000L, (long long)0x800042008000L, (long long)0x0L, ctx);
	case 117:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x10000000000L, (long long)0x200010200000000L, (long long)0x0L, ctx);
	case 118:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x400000208000000L, (long long)0x0L, (long long)0x0L, ctx);
	case 119:
		return jjMoveStringLiteralDfa1_0((long long)0x0L, (long long)0x100010000000L, (long long)0x0L, (long long)0x0L, ctx);
	case 123:
		jjmatchedKind = 43;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 124:
		jjmatchedKind = 33;
		return jjMoveStringLiteralDfa1_0((long long)0x80000000L, (long long)0x0L, (long long)0x0L, (long long)0x100000L, ctx);
	case 125:
		jjmatchedKind = 44;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 126:
		jjmatchedKind = 202;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	default:
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
		break;
	}
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa1_0(long long active0, long long active1, long long active2, long long active3, ThreadContext* ctx)
{
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)0, ctx);
		}
	}
	switch(curChar) {
	case 38:
		if((active0 & 0x40000000L) != (long long)0L)
		{
			jjmatchedKind = 30;
			jjmatchedPos = 1;
		}
		break ;
	case 42:
		if((active3 & 0x2L) != (long long)0L)
		{
			jjmatchedKind = 193;
			jjmatchedPos = 1;
		}
		break ;
	case 43:
		if((active0 & 0x1000000L) != (long long)0L)
		{
			jjmatchedKind = 24;
			jjmatchedPos = 1;
		}
		break ;
	case 45:
		if((active0 & 0x4000000L) != (long long)0L)
		{
			jjmatchedKind = 26;
			jjmatchedPos = 1;
		}
		break ;
	case 47:
		if((active3 & 0x4L) != (long long)0L)
		{
			jjmatchedKind = 194;
			jjmatchedPos = 1;
		}
		break ;
	case 60:
		if((active3 & 0x200L) != (long long)0L)
		{
			jjmatchedKind = 201;
			jjmatchedPos = 1;
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0L, active3, (long long)0x10000L, ctx);
	case 61:
		if((active0 & 0x200000000000L) != (long long)0L)
		{
			jjmatchedKind = 45;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active0 & 0x400000000000L) != (long long)0L)
			{
				jjmatchedKind = 46;
				jjmatchedPos = 1;
			}
						else 
			{
				if((active0 & 0x1000000000000L) != (long long)0L)
				{
					jjmatchedKind = 48;
					jjmatchedPos = 1;
				}
								else 
				{
					if((active0 & 0x4000000000000L) != (long long)0L)
					{
						jjmatchedKind = 50;
						jjmatchedPos = 1;
					}
										else 
					{
						if((active3 & 0x800L) != (long long)0L)
						{
							jjmatchedKind = 203;
							jjmatchedPos = 1;
						}
												else 
						{
							if((active3 & 0x1000L) != (long long)0L)
							{
								jjmatchedKind = 204;
								jjmatchedPos = 1;
							}
														else 
							{
								if((active3 & 0x2000L) != (long long)0L)
								{
									jjmatchedKind = 205;
									jjmatchedPos = 1;
								}
																else 
								{
									if((active3 & 0x4000L) != (long long)0L)
									{
										jjmatchedKind = 206;
										jjmatchedPos = 1;
									}
																		else 
									{
										if((active3 & 0x8000L) != (long long)0L)
										{
											jjmatchedKind = 207;
											jjmatchedPos = 1;
										}
																				else 
										{
											if((active3 & 0x40000L) != (long long)0L)
											{
												jjmatchedKind = 210;
												jjmatchedPos = 1;
											}
																						else 
											{
												if((active3 & 0x80000L) != (long long)0L)
												{
													jjmatchedKind = 211;
													jjmatchedPos = 1;
												}
																								else 
												{
													if((active3 & 0x100000L) != (long long)0L)
													{
														jjmatchedKind = 212;
														jjmatchedPos = 1;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		break ;
	case 62:
		if((active0 & 0x20000000000000L) != (long long)0L)
		{
			jjmatchedKind = 53;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active3 & 0x200000L) != (long long)0L)
			{
				jjmatchedKind = 213;
				jjmatchedPos = 1;
			}
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x40000000000000L, active1, (long long)0L, active2, (long long)0L, active3, (long long)0x20000L, ctx);
	case 64:
		if((active0 & 0x20000000000L) != (long long)0L)
		{
			jjmatchedKind = 41;
			jjmatchedPos = 1;
		}
		break ;
	case 65:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x2408000000000000L, active2, (long long)0x800022002000000L, active3, (long long)0L, ctx);
	case 68:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x30000008000000L, active3, (long long)0L, ctx);
	case 69:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x203024000000000L, active2, (long long)0x6409005914022801L, active3, (long long)0L, ctx);
	case 70:
		if((active2 & 0x200L) != (long long)0L)
		{
			jjmatchedKind = 137;
			jjmatchedPos = 1;
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2000000000004L, active3, (long long)0L, ctx);
	case 72:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x100000000000L, active2, (long long)0x400000080L, active3, (long long)0L, ctx);
	case 73:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x4800000000000L, active2, (long long)0x42L, active3, (long long)0L, ctx);
	case 76:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x1000000L, active3, (long long)0L, ctx);
	case 78:
		if((active2 & 0x8L) != (long long)0L)
		{
			jjmatchedKind = 131;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active2 & 0x400L) != (long long)0L)
			{
				jjmatchedKind = 138;
				jjmatchedPos = 1;
			}
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x10448000000000L, active2, (long long)0x8200100000L, active3, (long long)0L, ctx);
	case 79:
		if((active2 & 0x40000000L) != (long long)0L)
		{
			jjmatchedKind = 158;
			jjmatchedPos = 1;
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x80000000000000L, active2, (long long)0x8044040020240110L, active3, (long long)0L, ctx);
	case 80:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x10000000000L, active2, (long long)0L, active3, (long long)0L, ctx);
	case 82:
		if((active1 & 0x200000000000L) != (long long)0L)
		{
			jjmatchedKind = 109;
			jjmatchedPos = 1;
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x4900080000000000L, active2, (long long)0xa00080c8c000L, active3, (long long)0L, ctx);
	case 83:
		if((active2 & 0x20L) != (long long)0L)
		{
			jjmatchedKind = 133;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active2 & 0x1000L) != (long long)0L)
			{
				jjmatchedKind = 140;
				jjmatchedPos = 1;
			}
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x8000000000000000L, active2, (long long)0x200010000010000L, active3, (long long)0L, ctx);
	case 84:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x80000000000L, active3, (long long)0L, ctx);
	case 85:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x60000000000000L, active2, (long long)0x1180000000000000L, active3, (long long)0L, ctx);
	case 88:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x500000000000L, active3, (long long)0L, ctx);
	case 89:
		if((active1 & 0x1000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 124;
			jjmatchedPos = 1;
		}
		break ;
	case 97:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0xc100000000000000L, active1, (long long)0x2408002600002000L, active2, (long long)0x800022002000000L, active3, (long long)0L, ctx);
	case 98:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x800000000000000L, active1, (long long)0L, active2, (long long)0L, active3, (long long)0L, ctx);
	case 100:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x30000008000000L, active3, (long long)0L, ctx);
	case 101:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x203024180044000L, active2, (long long)0x6409005914022801L, active3, (long long)0L, ctx);
	case 102:
		if((active1 & 0x400L) != (long long)0L)
		{
			jjmatchedKind = 74;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active2 & 0x200L) != (long long)0L)
			{
				jjmatchedKind = 137;
				jjmatchedPos = 1;
			}
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2000000000004L, active3, (long long)0L, ctx);
	case 104:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x100013800000L, active2, (long long)0x400000080L, active3, (long long)0L, ctx);
	case 105:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x48000000000c0L, active2, (long long)0x42L, active3, (long long)0L, ctx);
	case 108:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x200000000000000L, active1, (long long)0x8L, active2, (long long)0x1000000L, active3, (long long)0L, ctx);
	case 109:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x80000000000000L, active1, (long long)0x800L, active2, (long long)0L, active3, (long long)0L, ctx);
	case 110:
		if((active2 & 0x8L) != (long long)0L)
		{
			jjmatchedKind = 131;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active2 & 0x400L) != (long long)0L)
			{
				jjmatchedKind = 138;
				jjmatchedPos = 1;
			}
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x400000000000000L, active1, (long long)0x10448020001010L, active2, (long long)0x8200100000L, active3, (long long)0L, ctx);
	case 111:
		if((active1 & 0x4L) != (long long)0L)
		{
			jjmatchedKind = 66;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active2 & 0x40000000L) != (long long)0L)
			{
				jjmatchedKind = 158;
				jjmatchedPos = 1;
			}
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x80000848000303L, active2, (long long)0x8044040020240110L, active3, (long long)0L, ctx);
	case 112:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x10000000000L, active2, (long long)0L, active3, (long long)0L, ctx);
	case 114:
		if((active1 & 0x200000000000L) != (long long)0L)
		{
			jjmatchedKind = 109;
			jjmatchedPos = 1;
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x1000000000000000L, active1, (long long)0x4900081004018000L, active2, (long long)0xa00080c8c000L, active3, (long long)0L, ctx);
	case 115:
		if((active2 & 0x20L) != (long long)0L)
		{
			jjmatchedKind = 133;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active2 & 0x1000L) != (long long)0L)
			{
				jjmatchedKind = 140;
				jjmatchedPos = 1;
			}
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x8000000000000000L, active2, (long long)0x200010000010000L, active3, (long long)0L, ctx);
	case 116:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x80000L, active2, (long long)0x80000000000L, active3, (long long)0L, ctx);
	case 117:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x60000000120000L, active2, (long long)0x1180000000000000L, active3, (long long)0L, ctx);
	case 119:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x200000L, active2, (long long)0L, active3, (long long)0L, ctx);
	case 120:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0L, active1, (long long)0x20L, active2, (long long)0x500000000000L, active3, (long long)0L, ctx);
	case 121:
		if((active1 & 0x1000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 124;
			jjmatchedPos = 1;
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x2000000000000000L, active1, (long long)0x400000L, active2, (long long)0L, active3, (long long)0L, ctx);
	case 124:
		if((active0 & 0x80000000L) != (long long)0L)
		{
			jjmatchedKind = 31;
			jjmatchedPos = 1;
		}
		break ;
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)1, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa2_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, long long old3, long long active3, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	active1 = active1 & (old1);
	active2 = active2 & (old2);
	active3 = active3 & (old3);
	if(((active0) | (active1) | (active2) | (active3)) == (bool)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)1, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)1, ctx);
		}
	}
	switch(curChar) {
	case 61:
		if((active3 & 0x10000L) != (long long)0L)
		{
			jjmatchedKind = 208;
			jjmatchedPos = 2;
		}
				else 
		{
			if((active3 & 0x20000L) != (long long)0L)
			{
				jjmatchedKind = 209;
				jjmatchedPos = 2;
			}
		}
		break ;
	case 62:
		if((active0 & 0x40000000000000L) != (long long)0L)
		{
			jjmatchedKind = 54;
			jjmatchedPos = 2;
		}
		break ;
	case 65:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x4000080000008080L, active3, (long long)0L, ctx);
	case 66:
		if((active2 & 0x1000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 188;
			jjmatchedPos = 2;
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2000000L, active3, (long long)0L, ctx);
	case 67:
		if((active1 & 0x8000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 127;
			jjmatchedPos = 2;
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x20000000000L, active3, (long long)0L, ctx);
	case 68:
		if((active1 & 0x400000000000L) != (long long)0L)
		{
			jjmatchedKind = 110;
			jjmatchedPos = 2;
		}
				else 
		{
			if((active2 & 0x100000L) != (long long)0L)
			{
				jjmatchedKind = 148;
				jjmatchedPos = 2;
			}
						else 
			{
				if((active2 & 0x8000000L) != (long long)0L)
				{
					jjmatchedKind = 155;
					jjmatchedPos = 2;
				}
			}
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x4000010000000000L, active2, (long long)0x8000000000L, active3, (long long)0L, ctx);
	case 69:
		if((active2 & 0x200000000000000L) != (long long)0L)
		{
			jjmatchedKind = 185;
			jjmatchedPos = 2;
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x100000000000L, active2, (long long)0x100400484000L, active3, (long long)0L, ctx);
	case 70:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x2000000000000L, active2, (long long)0x9000004000004L, active3, (long long)0L, ctx);
	case 71:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x4000000000000L, active2, (long long)0x400000000002000L, active3, (long long)0L, ctx);
	case 73:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x80000000000000L, active2, (long long)0xc10280000000L, active3, (long long)0L, ctx);
	case 74:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x30000000000000L, active3, (long long)0L, ctx);
	case 75:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x800000000000L, active2, (long long)0L, active3, (long long)0L, ctx);
	case 76:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x440024000000000L, active2, (long long)0x80000020200000L, active3, (long long)0L, ctx);
	case 77:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000000000040002L, active3, (long long)0L, ctx);
	case 78:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x10000000000000L, active2, (long long)0x100002010000000L, active3, (long long)0L, ctx);
	case 79:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x900080000000000L, active2, (long long)0x40200000810000L, active3, (long long)0L, ctx);
	case 80:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x4000000000L, active3, (long long)0L, ctx);
	case 82:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2804000000000000L, active3, (long long)0L, ctx);
	case 83:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x1008000000000L, active2, (long long)0x41L, active3, (long long)0L, ctx);
	case 84:
		if((active1 & 0x200000000000000L) != (long long)0L)
		{
			jjmatchedKind = 121;
			jjmatchedPos = 2;
		}
				else 
		{
			if((active2 & 0x10L) != (long long)0L)
			{
				jjmatchedKind = 132;
				jjmatchedPos = 2;
			}
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x28040000000000L, active2, (long long)0x2001801000800L, active3, (long long)0L, ctx);
	case 86:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x2000000000000000L, active2, (long long)0x20000L, active3, (long long)0L, ctx);
	case 87:
		if((active2 & 0x40000000000L) != (long long)0L)
		{
			jjmatchedKind = 170;
			jjmatchedPos = 2;
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x100L, active3, (long long)0L, ctx);
	case 89:
		if((active2 & 0x100000000L) != (long long)0L)
		{
			jjmatchedKind = 160;
			jjmatchedPos = 2;
		}
		break ;
	case 97:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x200000000000000L, active1, (long long)0x80000L, active2, (long long)0x4000080000008080L, active3, (long long)0L, ctx);
	case 98:
		if((active2 & 0x1000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 188;
			jjmatchedPos = 2;
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x20000L, active2, (long long)0x2000000L, active3, (long long)0L, ctx);
	case 99:
		if((active1 & 0x8000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 127;
			jjmatchedPos = 2;
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x100000000000000L, active1, (long long)0x820000000L, active2, (long long)0x20000000000L, active3, (long long)0L, ctx);
	case 100:
		if((active1 & 0x400000000000L) != (long long)0L)
		{
			jjmatchedKind = 110;
			jjmatchedPos = 2;
		}
				else 
		{
			if((active2 & 0x100000L) != (long long)0L)
			{
				jjmatchedKind = 148;
				jjmatchedPos = 2;
			}
						else 
			{
				if((active2 & 0x8000000L) != (long long)0L)
				{
					jjmatchedKind = 155;
					jjmatchedPos = 2;
				}
			}
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x4000010080000000L, active2, (long long)0x8000000000L, active3, (long long)0L, ctx);
	case 101:
		if((active2 & 0x200000000000000L) != (long long)0L)
		{
			jjmatchedKind = 185;
			jjmatchedPos = 2;
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x1000000000000000L, active1, (long long)0x100000000000L, active2, (long long)0x100400484000L, active3, (long long)0L, ctx);
	case 102:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x2000100000000L, active2, (long long)0x9000004000004L, active3, (long long)0L, ctx);
	case 103:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x4000000000000L, active2, (long long)0x400000000002000L, active3, (long long)0L, ctx);
	case 105:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x80000018a08000L, active2, (long long)0xc10280000000L, active3, (long long)0L, ctx);
	case 106:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x30000000000000L, active3, (long long)0L, ctx);
	case 107:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x800000000000L, active2, (long long)0L, active3, (long long)0L, ctx);
	case 108:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x440026200000000L, active2, (long long)0x80000020200000L, active3, (long long)0L, ctx);
	case 109:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000000000040002L, active3, (long long)0L, ctx);
	case 110:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x100000004000c3L, active2, (long long)0x100002010000000L, active3, (long long)0L, ctx);
	case 111:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x900080000010000L, active2, (long long)0x40200000810000L, active3, (long long)0L, ctx);
	case 112:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x80000000000000L, active1, (long long)0x100800L, active2, (long long)0x4000000000L, active3, (long long)0L, ctx);
	case 114:
		if((active1 & 0x100L) != (long long)0L)
		{
			jjmatchedKind = 72;
			jjmatchedPos = 2;
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x403000000L, active2, (long long)0x2804000000000000L, active3, (long long)0L, ctx);
	case 115:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x4800000000000000L, active1, (long long)0x1008000001008L, active2, (long long)0x41L, active3, (long long)0L, ctx);
	case 116:
		if((active1 & 0x200000000000000L) != (long long)0L)
		{
			jjmatchedKind = 121;
			jjmatchedPos = 2;
		}
				else 
		{
			if((active2 & 0x10L) != (long long)0L)
			{
				jjmatchedKind = 132;
				jjmatchedPos = 2;
			}
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0xa400000000000000L, active1, (long long)0x28040000042220L, active2, (long long)0x2001801000800L, active3, (long long)0L, ctx);
	case 117:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x1000000010L, active2, (long long)0L, active3, (long long)0L, ctx);
	case 118:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x2000000000000000L, active2, (long long)0x20000L, active3, (long long)0L, ctx);
	case 119:
		if((active1 & 0x4000L) != (long long)0L)
		{
			jjmatchedKind = 78;
			jjmatchedPos = 2;
		}
				else 
		{
			if((active2 & 0x40000000000L) != (long long)0L)
			{
				jjmatchedKind = 170;
				jjmatchedPos = 2;
			}
		}
		return jjMoveStringLiteralDfa3_0(active0, (long long)0L, active1, (long long)0x40000000L, active2, (long long)0x100L, active3, (long long)0L, ctx);
	case 121:
		if((active1 & 0x4000000L) != (long long)0L)
		{
			jjmatchedKind = 90;
			jjmatchedPos = 2;
		}
				else 
		{
			if((active2 & 0x100000000L) != (long long)0L)
			{
				jjmatchedKind = 160;
				jjmatchedPos = 2;
			}
		}
		break ;
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)2, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa3_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, long long old3, long long active3, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	active1 = active1 & (old1);
	active2 = active2 & (old2);
	active3 = active3 & (old3);
	if(((active0) | (active1) | (active2) | (active3)) == (bool)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)2, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)2, ctx);
		}
	}
	switch(curChar) {
	case 65:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x10000000000L, active2, (long long)0x14400100L, ctx);
	case 67:
		if((active2 & 0x1L) != (long long)0L)
		{
			jjmatchedKind = 128;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x1000000000000L, active2, (long long)0x100300400000000L, ctx);
	case 68:
		if((active2 & 0x4000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 190;
			jjmatchedPos = 3;
		}
		break ;
	case 69:
		if((active1 & 0x800000000000L) != (long long)0L)
		{
			jjmatchedKind = 111;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x403002c000000000L, active2, (long long)0xe008001020000L, ctx);
	case 71:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x802000000000L, ctx);
	case 72:
		if((active2 & 0x20000000000L) != (long long)0L)
		{
			jjmatchedKind = 169;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x4000000000000L, active2, (long long)0L, ctx);
	case 73:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x2000000000000000L, active2, (long long)0x2400000000002002L, ctx);
	case 76:
		if((active1 & 0x40000000000000L) != (long long)0L)
		{
			jjmatchedKind = 118;
			jjmatchedPos = 3;
		}
				else 
		{
			if((active2 & 0x40000000000000L) != (long long)0L)
			{
				jjmatchedKind = 182;
				jjmatchedPos = 3;
			}
						else 
			{
				if((active2 & 0x80000000000000L) != (long long)0L)
				{
					jjmatchedKind = 183;
					jjmatchedPos = 3;
				}
			}
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x4002210000L, ctx);
	case 77:
		if((active1 & 0x80000000000L) != (long long)0L)
		{
			jjmatchedKind = 107;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000000080040000L, ctx);
	case 78:
		if((active1 & 0x80000000000000L) != (long long)0L)
		{
			jjmatchedKind = 119;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x10000008000L, ctx);
	case 79:
		if((active1 & 0x40000000000L) != (long long)0L)
		{
			jjmatchedKind = 106;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x1001000000000L, ctx);
	case 80:
		if((active2 & 0x800000L) != (long long)0L)
		{
			jjmatchedKind = 151;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x84000L, ctx);
	case 81:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x200000000L, ctx);
	case 82:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x100000000000L, active2, (long long)0x80L, ctx);
	case 83:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x100000000000000L, active2, (long long)0x400000000004L, ctx);
	case 84:
		if((active1 & 0x2000000000000L) != (long long)0L)
		{
			jjmatchedKind = 113;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x800080000000040L, ctx);
	case 85:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0xc08000000000000L, active2, (long long)0x30000820000000L, ctx);
	case 87:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x800L, ctx);
	case 97:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x1000000000000000L, active1, (long long)0x10c000000c0L, active2, (long long)0x14400100L, ctx);
	case 99:
		if((active2 & 0x1L) != (long long)0L)
		{
			jjmatchedKind = 128;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x8000000000000000L, active1, (long long)0x1000000400000L, active2, (long long)0x100300400000000L, ctx);
	case 100:
		if((active1 & 0x8000000L) != (long long)0L)
		{
			jjmatchedKind = 91;
			jjmatchedPos = 3;
		}
				else 
		{
			if((active2 & 0x4000000000000000L) != (long long)0L)
			{
				jjmatchedKind = 190;
				jjmatchedPos = 3;
			}
		}
		break ;
	case 101:
		if((active0 & 0x2000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 61;
			jjmatchedPos = 3;
		}
				else 
		{
			if((active0 & 0x4000000000000000L) != (long long)0L)
			{
				jjmatchedKind = 62;
				jjmatchedPos = 3;
			}
						else 
			{
				if((active1 & 0x8L) != (long long)0L)
				{
					jjmatchedKind = 67;
					jjmatchedPos = 3;
				}
								else 
				{
					if((active1 & 0x1000000000L) != (long long)0L)
					{
						jjmatchedKind = 100;
						jjmatchedPos = 3;
					}
										else 
					{
						if((active1 & 0x800000000000L) != (long long)0L)
						{
							jjmatchedKind = 111;
							jjmatchedPos = 3;
						}
					}
				}
			}
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x400000000000000L, active1, (long long)0x403002c100100020L, active2, (long long)0xe008001020000L, ctx);
	case 103:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x802000000000L, ctx);
	case 104:
		if((active2 & 0x20000000000L) != (long long)0L)
		{
			jjmatchedKind = 169;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x4000000000000L, active2, (long long)0L, ctx);
	case 105:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x2000000280002000L, active2, (long long)0x2400000000002002L, ctx);
	case 107:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x100000000000000L, active1, (long long)0L, active2, (long long)0L, ctx);
	case 108:
		if((active1 & 0x40000000000000L) != (long long)0L)
		{
			jjmatchedKind = 118;
			jjmatchedPos = 3;
		}
				else 
		{
			if((active2 & 0x40000000000000L) != (long long)0L)
			{
				jjmatchedKind = 182;
				jjmatchedPos = 3;
			}
						else 
			{
				if((active2 & 0x80000000000000L) != (long long)0L)
				{
					jjmatchedKind = 183;
					jjmatchedPos = 3;
				}
			}
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x30020800L, active2, (long long)0x4002210000L, ctx);
	case 109:
		if((active1 & 0x10L) != (long long)0L)
		{
			jjmatchedKind = 68;
			jjmatchedPos = 3;
		}
				else 
		{
			if((active1 & 0x80000000000L) != (long long)0L)
			{
				jjmatchedKind = 107;
				jjmatchedPos = 3;
			}
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000000080040000L, ctx);
	case 110:
		if((active1 & 0x80000000000000L) != (long long)0L)
		{
			jjmatchedKind = 119;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x40000000L, active2, (long long)0x10000008000L, ctx);
	case 111:
		if((active1 & 0x200L) != (long long)0L)
		{
			jjmatchedKind = 73;
			jjmatchedPos = 3;
		}
				else 
		{
			if((active1 & 0x40000000000L) != (long long)0L)
			{
				jjmatchedKind = 106;
				jjmatchedPos = 3;
			}
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x80000000000000L, active1, (long long)0x3000000L, active2, (long long)0x1001000000000L, ctx);
	case 112:
		if((active2 & 0x800000L) != (long long)0L)
		{
			jjmatchedKind = 151;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x84000L, ctx);
	case 113:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x200000000L, ctx);
	case 114:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x100000000000L, active2, (long long)0x80L, ctx);
	case 115:
		if((active1 & 0x800000L) != (long long)0L)
		{
			jjmatchedKind = 87;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x200000000000000L, active1, (long long)0x100002000000001L, active2, (long long)0x400000000004L, ctx);
	case 116:
		if((active1 & 0x2000000000000L) != (long long)0L)
		{
			jjmatchedKind = 113;
			jjmatchedPos = 3;
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x800000000000000L, active1, (long long)0x291002L, active2, (long long)0x800080000000040L, ctx);
	case 117:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0xc08000000040000L, active2, (long long)0x30000820000000L, ctx);
	case 118:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0x8000L, active2, (long long)0L, ctx);
	case 119:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x800L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)3, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa4_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	active1 = active1 & (old1);
	active2 = active2 & (old2);
	if(((active0) | (active1) | (active2)) == (bool)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)3, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)3, ctx);
		}
	}
	switch(curChar) {
	case 65:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x1000000000000L, active2, (long long)0x2000004080094000L, ctx);
	case 66:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x200000L, ctx);
	case 67:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x4000000000L, active2, (long long)0L, ctx);
	case 69:
		if((active1 & 0x100000000000L) != (long long)0L)
		{
			jjmatchedKind = 108;
			jjmatchedPos = 4;
		}
				else 
		{
			if((active2 & 0x80L) != (long long)0L)
			{
				jjmatchedKind = 135;
				jjmatchedPos = 4;
			}
						else 
			{
				if((active2 & 0x2000000L) != (long long)0L)
				{
					jjmatchedKind = 153;
					jjmatchedPos = 4;
				}
			}
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x400000000000000L, active2, (long long)0x280000000804L, ctx);
	case 70:
		if((active2 & 0x1000000000L) != (long long)0L)
		{
			jjmatchedKind = 164;
			jjmatchedPos = 4;
		}
		break ;
	case 71:
		if((active2 & 0x10000000000L) != (long long)0L)
		{
			jjmatchedKind = 168;
			jjmatchedPos = 4;
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x800000000000L, ctx);
	case 73:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8804000000040140L, ctx);
	case 75:
		if((active2 & 0x400000000L) != (long long)0L)
		{
			jjmatchedKind = 162;
			jjmatchedPos = 4;
		}
		break ;
	case 76:
		if((active2 & 0x20000L) != (long long)0L)
		{
			jjmatchedKind = 145;
			jjmatchedPos = 4;
		}
		break ;
	case 77:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x30000000L, ctx);
	case 78:
		if((active2 & 0x2000L) != (long long)0L)
		{
			jjmatchedKind = 141;
			jjmatchedPos = 4;
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x2000000000000000L, active2, (long long)0L, ctx);
	case 79:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x400000000000000L, ctx);
	case 80:
		if((active1 & 0x800000000000000L) != (long long)0L)
		{
			jjmatchedKind = 123;
			jjmatchedPos = 4;
		}
		break ;
	case 82:
		if((active1 & 0x10000000000000L) != (long long)0L)
		{
			jjmatchedKind = 116;
			jjmatchedPos = 4;
		}
				else 
		{
			if((active1 & 0x20000000000000L) != (long long)0L)
			{
				jjmatchedKind = 117;
				jjmatchedPos = 4;
			}
						else 
			{
				if((active1 & 0x4000000000000000L) != (long long)0L)
				{
					jjmatchedKind = 126;
					jjmatchedPos = 4;
				}
								else 
				{
					if((active2 & 0x1000000L) != (long long)0L)
					{
						jjmatchedKind = 152;
						jjmatchedPos = 4;
					}
										else 
					{
						if((active2 & 0x2000000000000L) != (long long)0L)
						{
							jjmatchedKind = 177;
							jjmatchedPos = 4;
						}
					}
				}
			}
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x8008000000000L, active2, (long long)0x9000800000000L, ctx);
	case 83:
		if((active1 & 0x100000000000000L) != (long long)0L)
		{
			jjmatchedKind = 120;
			jjmatchedPos = 4;
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x30000000008000L, ctx);
	case 84:
		if((active1 & 0x4000000000000L) != (long long)0L)
		{
			jjmatchedKind = 114;
			jjmatchedPos = 4;
		}
				else 
		{
			if((active2 & 0x2L) != (long long)0L)
			{
				jjmatchedKind = 129;
				jjmatchedPos = 4;
			}
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x30000000000L, active2, (long long)0x100400000400000L, ctx);
	case 85:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x102204000000L, ctx);
	case 88:
		if((active2 & 0x8000000000L) != (long long)0L)
		{
			jjmatchedKind = 167;
			jjmatchedPos = 4;
		}
		break ;
	case 97:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0x100000000000000L, active1, (long long)0x1000000009000L, active2, (long long)0x2000004080094000L, ctx);
	case 98:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x200000L, ctx);
	case 99:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x4000200000L, active2, (long long)0L, ctx);
	case 100:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x200000000L, active2, (long long)0L, ctx);
	case 101:
		if((active1 & 0x10000000L) != (long long)0L)
		{
			jjmatchedKind = 92;
			jjmatchedPos = 4;
		}
				else 
		{
			if((active1 & 0x2000000000L) != (long long)0L)
			{
				jjmatchedKind = 101;
				jjmatchedPos = 4;
			}
						else 
			{
				if((active1 & 0x100000000000L) != (long long)0L)
				{
					jjmatchedKind = 108;
					jjmatchedPos = 4;
				}
								else 
				{
					if((active2 & 0x80L) != (long long)0L)
					{
						jjmatchedKind = 135;
						jjmatchedPos = 4;
					}
										else 
					{
						if((active2 & 0x2000000L) != (long long)0L)
						{
							jjmatchedKind = 153;
							jjmatchedPos = 4;
						}
					}
				}
			}
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x400000000010800L, active2, (long long)0x280000000804L, ctx);
	case 102:
		if((active2 & 0x1000000000L) != (long long)0L)
		{
			jjmatchedKind = 164;
			jjmatchedPos = 4;
		}
		break ;
	case 103:
		if((active2 & 0x10000000000L) != (long long)0L)
		{
			jjmatchedKind = 168;
			jjmatchedPos = 4;
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x800000000000L, ctx);
	case 104:
		if((active0 & 0x8000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 63;
			jjmatchedPos = 4;
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x400000L, active2, (long long)0L, ctx);
	case 105:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0xa0002L, active2, (long long)0x8804000000040140L, ctx);
	case 107:
		if((active0 & 0x1000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 60;
			jjmatchedPos = 4;
		}
				else 
		{
			if((active2 & 0x400000000L) != (long long)0L)
			{
				jjmatchedKind = 162;
				jjmatchedPos = 4;
			}
		}
		break ;
	case 108:
		if((active1 & 0x40L) != (long long)0L)
		{
			jjmatchedKind = 70;
			jjmatchedPos = 4;
		}
				else 
		{
			if((active1 & 0x800000000L) != (long long)0L)
			{
				jjmatchedKind = 99;
				jjmatchedPos = 4;
			}
						else 
			{
				if((active2 & 0x20000L) != (long long)0L)
				{
					jjmatchedKind = 145;
					jjmatchedPos = 4;
				}
			}
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x440000080L, active2, (long long)0L, ctx);
	case 109:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x30000000L, ctx);
	case 110:
		if((active2 & 0x2000L) != (long long)0L)
		{
			jjmatchedKind = 141;
			jjmatchedPos = 4;
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x2000000000000020L, active2, (long long)0L, ctx);
	case 111:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x400000000000000L, ctx);
	case 112:
		if((active1 & 0x800000000000000L) != (long long)0L)
		{
			jjmatchedKind = 123;
			jjmatchedPos = 4;
		}
		break ;
	case 114:
		if((active1 & 0x100000L) != (long long)0L)
		{
			jjmatchedKind = 84;
			jjmatchedPos = 4;
		}
				else 
		{
			if((active1 & 0x10000000000000L) != (long long)0L)
			{
				jjmatchedKind = 116;
				jjmatchedPos = 4;
			}
						else 
			{
				if((active1 & 0x20000000000000L) != (long long)0L)
				{
					jjmatchedKind = 117;
					jjmatchedPos = 4;
				}
								else 
				{
					if((active1 & 0x4000000000000000L) != (long long)0L)
					{
						jjmatchedKind = 126;
						jjmatchedPos = 4;
					}
										else 
					{
						if((active2 & 0x1000000L) != (long long)0L)
						{
							jjmatchedKind = 152;
							jjmatchedPos = 4;
						}
												else 
						{
							if((active2 & 0x2000000000000L) != (long long)0L)
							{
								jjmatchedKind = 177;
								jjmatchedPos = 4;
							}
						}
					}
				}
			}
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0xc80000000000000L, active1, (long long)0x8008180040000L, active2, (long long)0x9000800000000L, ctx);
	case 115:
		if((active0 & 0x200000000000000L) != (long long)0L)
		{
			jjmatchedKind = 57;
			jjmatchedPos = 4;
		}
				else 
		{
			if((active1 & 0x100000000000000L) != (long long)0L)
			{
				jjmatchedKind = 120;
				jjmatchedPos = 4;
			}
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x30000000008000L, ctx);
	case 116:
		if((active1 & 0x1L) != (long long)0L)
		{
			jjmatchedKind = 64;
			jjmatchedPos = 4;
		}
				else 
		{
			if((active1 & 0x4000000000000L) != (long long)0L)
			{
				jjmatchedKind = 114;
				jjmatchedPos = 4;
			}
						else 
			{
				if((active2 & 0x2L) != (long long)0L)
				{
					jjmatchedKind = 129;
					jjmatchedPos = 4;
				}
			}
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x30000000000L, active2, (long long)0x100400000400000L, ctx);
	case 117:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x20000000L, active2, (long long)0x102204000000L, ctx);
	case 118:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x2000L, active2, (long long)0L, ctx);
	case 119:
		if((active1 & 0x1000000L) != (long long)0L)
		{
			jjmatchedKind = 88;
			jjmatchedPos = 4;
		}
		return jjMoveStringLiteralDfa5_0(active0, (long long)0L, active1, (long long)0x2000000L, active2, (long long)0L, ctx);
	case 120:
		if((active2 & 0x8000000000L) != (long long)0L)
		{
			jjmatchedKind = 167;
			jjmatchedPos = 4;
		}
		break ;
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)4, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa5_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	active1 = active1 & (old1);
	active2 = active2 & (old2);
	if(((active0) | (active1) | (active2)) == (bool)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)4, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)4, ctx);
		}
	}
	switch(curChar) {
	case 65:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x8000000000000L, active2, (long long)0x2000208000L, ctx);
	case 67:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x4000000000L, ctx);
	case 68:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x200000000000L, ctx);
	case 69:
		if((active1 & 0x10000000000L) != (long long)0L)
		{
			jjmatchedKind = 104;
			jjmatchedPos = 5;
		}
				else 
		{
			if((active1 & 0x20000000000L) != (long long)0L)
			{
				jjmatchedKind = 105;
				jjmatchedPos = 5;
			}
						else 
			{
				if((active2 & 0x400000L) != (long long)0L)
				{
					jjmatchedKind = 150;
					jjmatchedPos = 5;
				}
								else 
				{
					if((active2 & 0x10000000L) != (long long)0L)
					{
						jjmatchedKind = 156;
						jjmatchedPos = 5;
					}
										else 
					{
						if((active2 & 0x200000000L) != (long long)0L)
						{
							jjmatchedKind = 161;
							jjmatchedPos = 5;
						}
												else 
						{
							if((active2 & 0x1000000000000L) != (long long)0L)
							{
								jjmatchedKind = 176;
								jjmatchedPos = 5;
							}
						}
					}
				}
			}
		}
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8800000000800L, ctx);
	case 71:
		if((active1 & 0x2000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 125;
			jjmatchedPos = 5;
		}
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x4000000000000L, ctx);
	case 73:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x100000000000000L, ctx);
	case 76:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2000000004000000L, ctx);
	case 77:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x80000000000L, ctx);
	case 78:
		if((active2 & 0x20000000L) != (long long)0L)
		{
			jjmatchedKind = 157;
			jjmatchedPos = 5;
		}
				else 
		{
			if((active2 & 0x400000000000000L) != (long long)0L)
			{
				jjmatchedKind = 186;
				jjmatchedPos = 5;
			}
		}
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x800000040L, ctx);
	case 80:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x1000000000000L, active2, (long long)0L, ctx);
	case 82:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x80084000L, ctx);
	case 83:
		if((active1 & 0x400000000000000L) != (long long)0L)
		{
			jjmatchedKind = 122;
			jjmatchedPos = 5;
		}
				else 
		{
			if((active2 & 0x400000000000L) != (long long)0L)
			{
				jjmatchedKind = 174;
				jjmatchedPos = 5;
			}
		}
		break ;
	case 84:
		if((active1 & 0x4000000000L) != (long long)0L)
		{
			jjmatchedKind = 102;
			jjmatchedPos = 5;
		}
				else 
		{
			if((active1 & 0x8000000000L) != (long long)0L)
			{
				jjmatchedKind = 103;
				jjmatchedPos = 5;
			}
						else 
			{
				if((active2 & 0x4L) != (long long)0L)
				{
					jjmatchedKind = 130;
					jjmatchedPos = 5;
				}
								else 
				{
					if((active2 & 0x100L) != (long long)0L)
					{
						jjmatchedKind = 136;
						jjmatchedPos = 5;
					}
										else 
					{
						if((active2 & 0x40000L) != (long long)0L)
						{
							jjmatchedKind = 146;
							jjmatchedPos = 5;
						}
					}
				}
			}
		}
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8830100000010000L, ctx);
	case 95:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x100000000L, active2, (long long)0L, ctx);
	case 97:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0x800000000000000L, active1, (long long)0x8000200000000L, active2, (long long)0x2000208000L, ctx);
	case 99:
		if((active1 & 0x20000L) != (long long)0L)
		{
			jjmatchedKind = 81;
			jjmatchedPos = 5;
		}
				else 
		{
			if((active1 & 0x80000L) != (long long)0L)
			{
				jjmatchedKind = 83;
				jjmatchedPos = 5;
			}
		}
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x10000L, active2, (long long)0x4000000000L, ctx);
	case 100:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x20000020L, active2, (long long)0x200000000000L, ctx);
	case 101:
		if((active1 & 0x2000L) != (long long)0L)
		{
			jjmatchedKind = 77;
			jjmatchedPos = 5;
		}
				else 
		{
			if((active1 & 0x10000000000L) != (long long)0L)
			{
				jjmatchedKind = 104;
				jjmatchedPos = 5;
			}
						else 
			{
				if((active1 & 0x20000000000L) != (long long)0L)
				{
					jjmatchedKind = 105;
					jjmatchedPos = 5;
				}
								else 
				{
					if((active2 & 0x400000L) != (long long)0L)
					{
						jjmatchedKind = 150;
						jjmatchedPos = 5;
					}
										else 
					{
						if((active2 & 0x10000000L) != (long long)0L)
						{
							jjmatchedKind = 156;
							jjmatchedPos = 5;
						}
												else 
						{
							if((active2 & 0x200000000L) != (long long)0L)
							{
								jjmatchedKind = 161;
								jjmatchedPos = 5;
							}
														else 
							{
								if((active2 & 0x1000000000000L) != (long long)0L)
								{
									jjmatchedKind = 176;
									jjmatchedPos = 5;
								}
							}
						}
					}
				}
			}
		}
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x80000000L, active2, (long long)0x8800000000800L, ctx);
	case 102:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0x400000000000000L, active1, (long long)0L, active2, (long long)0L, ctx);
	case 103:
		if((active1 & 0x2000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 125;
			jjmatchedPos = 5;
		}
		return jjMoveStringLiteralDfa6_0(active0, (long long)0x100000000000000L, active1, (long long)0L, active2, (long long)0x4000000000000L, ctx);
	case 104:
		if((active1 & 0x200000L) != (long long)0L)
		{
			jjmatchedKind = 85;
			jjmatchedPos = 5;
		}
		break ;
	case 105:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x100000000000000L, ctx);
	case 108:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x400000080L, active2, (long long)0x2000000004000000L, ctx);
	case 109:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x800L, active2, (long long)0x80000000000L, ctx);
	case 110:
		if((active1 & 0x40000L) != (long long)0L)
		{
			jjmatchedKind = 82;
			jjmatchedPos = 5;
		}
				else 
		{
			if((active2 & 0x20000000L) != (long long)0L)
			{
				jjmatchedKind = 157;
				jjmatchedPos = 5;
			}
						else 
			{
				if((active2 & 0x400000000000000L) != (long long)0L)
				{
					jjmatchedKind = 186;
					jjmatchedPos = 5;
				}
			}
		}
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x1002L, active2, (long long)0x800000040L, ctx);
	case 111:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x40000000L, active2, (long long)0L, ctx);
	case 112:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x1000000000000L, active2, (long long)0L, ctx);
	case 114:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x400000L, active2, (long long)0x80084000L, ctx);
	case 115:
		if((active1 & 0x2000000L) != (long long)0L)
		{
			jjmatchedKind = 89;
			jjmatchedPos = 5;
		}
				else 
		{
			if((active1 & 0x400000000000000L) != (long long)0L)
			{
				jjmatchedKind = 122;
				jjmatchedPos = 5;
			}
						else 
			{
				if((active2 & 0x400000000000L) != (long long)0L)
				{
					jjmatchedKind = 174;
					jjmatchedPos = 5;
				}
			}
		}
		break ;
	case 116:
		if((active0 & 0x80000000000000L) != (long long)0L)
		{
			jjmatchedKind = 55;
			jjmatchedPos = 5;
		}
				else 
		{
			if((active1 & 0x4000000000L) != (long long)0L)
			{
				jjmatchedKind = 102;
				jjmatchedPos = 5;
			}
						else 
			{
				if((active1 & 0x8000000000L) != (long long)0L)
				{
					jjmatchedKind = 103;
					jjmatchedPos = 5;
				}
								else 
				{
					if((active2 & 0x4L) != (long long)0L)
					{
						jjmatchedKind = 130;
						jjmatchedPos = 5;
					}
										else 
					{
						if((active2 & 0x100L) != (long long)0L)
						{
							jjmatchedKind = 136;
							jjmatchedPos = 5;
						}
												else 
						{
							if((active2 & 0x40000L) != (long long)0L)
							{
								jjmatchedKind = 146;
								jjmatchedPos = 5;
							}
						}
					}
				}
			}
		}
		return jjMoveStringLiteralDfa6_0(active0, (long long)0L, active1, (long long)0x8000L, active2, (long long)0x8830100000010000L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)5, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa6_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	active1 = active1 & (old1);
	active2 = active2 & (old2);
	if(((active0) | (active1) | (active2)) == (bool)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)5, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)5, ctx);
		}
	}
	switch(curChar) {
	case 67:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x208040L, ctx);
	case 69:
		if((active2 & 0x4000L) != (long long)0L)
		{
			jjmatchedKind = 142;
			jjmatchedPos = 6;
		}
				else 
		{
			if((active2 & 0x4000000000L) != (long long)0L)
			{
				jjmatchedKind = 166;
				jjmatchedPos = 6;
			}
						else 
			{
				if((active2 & 0x100000000000L) != (long long)0L)
				{
					jjmatchedKind = 172;
					jjmatchedPos = 6;
				}
			}
		}
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0x1000000000000L, active2, (long long)0x80000080000L, ctx);
	case 71:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2000000000L, ctx);
	case 73:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2800000000010000L, ctx);
	case 76:
		if((active1 & 0x8000000000000L) != (long long)0L)
		{
			jjmatchedKind = 115;
			jjmatchedPos = 6;
		}
		break ;
	case 78:
		if((active2 & 0x800L) != (long long)0L)
		{
			jjmatchedKind = 139;
			jjmatchedPos = 6;
		}
				else 
		{
			if((active2 & 0x4000000000000L) != (long long)0L)
			{
				jjmatchedKind = 178;
				jjmatchedPos = 6;
			}
		}
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000000000000L, ctx);
	case 79:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x100000000000000L, ctx);
	case 82:
		if((active2 & 0x800000000000L) != (long long)0L)
		{
			jjmatchedKind = 175;
			jjmatchedPos = 6;
		}
		break ;
	case 83:
		if((active2 & 0x800000000L) != (long long)0L)
		{
			jjmatchedKind = 163;
			jjmatchedPos = 6;
		}
		break ;
	case 84:
		if((active2 & 0x4000000L) != (long long)0L)
		{
			jjmatchedKind = 154;
			jjmatchedPos = 6;
		}
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000000000000000L, ctx);
	case 85:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x200000000000L, ctx);
	case 89:
		if((active2 & 0x80000000L) != (long long)0L)
		{
			jjmatchedKind = 159;
			jjmatchedPos = 6;
		}
		break ;
	case 95:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x30000000000000L, ctx);
	case 97:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0x400000000000000L, active1, (long long)0x40000000L, active2, (long long)0L, ctx);
	case 99:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0x800000000000000L, active1, (long long)0x80001000L, active2, (long long)0x208040L, ctx);
	case 101:
		if((active0 & 0x100000000000000L) != (long long)0L)
		{
			jjmatchedKind = 56;
			jjmatchedPos = 6;
		}
				else 
		{
			if((active1 & 0x8000L) != (long long)0L)
			{
				jjmatchedKind = 79;
				jjmatchedPos = 6;
			}
						else 
			{
				if((active1 & 0x20000000L) != (long long)0L)
				{
					jjmatchedKind = 93;
					jjmatchedPos = 6;
				}
								else 
				{
					if((active2 & 0x4000L) != (long long)0L)
					{
						jjmatchedKind = 142;
						jjmatchedPos = 6;
					}
										else 
					{
						if((active2 & 0x4000000000L) != (long long)0L)
						{
							jjmatchedKind = 166;
							jjmatchedPos = 6;
						}
												else 
						{
							if((active2 & 0x100000000000L) != (long long)0L)
							{
								jjmatchedKind = 172;
								jjmatchedPos = 6;
							}
						}
					}
				}
			}
		}
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0x1000400000800L, active2, (long long)0x80000080000L, ctx);
	case 102:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0x100000000L, active2, (long long)0L, ctx);
	case 103:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2000000000L, ctx);
	case 105:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2800000000010000L, ctx);
	case 108:
		if((active1 & 0x8000000000000L) != (long long)0L)
		{
			jjmatchedKind = 115;
			jjmatchedPos = 6;
		}
		break ;
	case 110:
		if((active2 & 0x800L) != (long long)0L)
		{
			jjmatchedKind = 139;
			jjmatchedPos = 6;
		}
				else 
		{
			if((active2 & 0x4000000000000L) != (long long)0L)
			{
				jjmatchedKind = 178;
				jjmatchedPos = 6;
			}
		}
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000000000000L, ctx);
	case 111:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0x400000L, active2, (long long)0x100000000000000L, ctx);
	case 114:
		if((active2 & 0x800000000000L) != (long long)0L)
		{
			jjmatchedKind = 175;
			jjmatchedPos = 6;
		}
		break ;
	case 115:
		if((active1 & 0x20L) != (long long)0L)
		{
			jjmatchedKind = 69;
			jjmatchedPos = 6;
		}
				else 
		{
			if((active2 & 0x800000000L) != (long long)0L)
			{
				jjmatchedKind = 163;
				jjmatchedPos = 6;
			}
		}
		break ;
	case 116:
		if((active2 & 0x4000000L) != (long long)0L)
		{
			jjmatchedKind = 154;
			jjmatchedPos = 6;
		}
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0x200010000L, active2, (long long)0x8000000000000000L, ctx);
	case 117:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0L, active1, (long long)0x2L, active2, (long long)0x200000000000L, ctx);
	case 121:
		if((active1 & 0x80L) != (long long)0L)
		{
			jjmatchedKind = 71;
			jjmatchedPos = 6;
		}
				else 
		{
			if((active2 & 0x80000000L) != (long long)0L)
			{
				jjmatchedKind = 159;
				jjmatchedPos = 6;
			}
		}
		break ;
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)6, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa7_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	active1 = active1 & (old1);
	active2 = active2 & (old2);
	if(((active0) | (active1) | (active2)) == (bool)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)6, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)6, ctx);
		}
	}
	switch(curChar) {
	case 62:
		if((active1 & 0x1000000000000L) != (long long)0L)
		{
			jjmatchedKind = 112;
			jjmatchedPos = 7;
		}
		break ;
	case 67:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000000000000L, ctx);
	case 68:
		if((active2 & 0x80000L) != (long long)0L)
		{
			jjmatchedKind = 147;
			jjmatchedPos = 7;
		}
		break ;
	case 69:
		if((active2 & 0x2000000000L) != (long long)0L)
		{
			jjmatchedKind = 165;
			jjmatchedPos = 7;
		}
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000000000000000L, ctx);
	case 75:
		if((active2 & 0x200000L) != (long long)0L)
		{
			jjmatchedKind = 149;
			jjmatchedPos = 7;
		}
		break ;
	case 78:
		if((active2 & 0x100000000000000L) != (long long)0L)
		{
			jjmatchedKind = 184;
			jjmatchedPos = 7;
		}
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x80000000000L, ctx);
	case 79:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x800000000010000L, ctx);
	case 82:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x200000000000L, ctx);
	case 83:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x20000000000000L, ctx);
	case 84:
		if((active2 & 0x40L) != (long long)0L)
		{
			jjmatchedKind = 134;
			jjmatchedPos = 7;
		}
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000L, ctx);
	case 87:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x10000000000000L, ctx);
	case 90:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2000000000000000L, ctx);
	case 99:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0x400000000000000L, active1, (long long)0L, active2, (long long)0x8000000000000L, ctx);
	case 100:
		if((active1 & 0x40000000L) != (long long)0L)
		{
			jjmatchedKind = 94;
			jjmatchedPos = 7;
		}
				else 
		{
			if((active2 & 0x80000L) != (long long)0L)
			{
				jjmatchedKind = 147;
				jjmatchedPos = 7;
			}
		}
		break ;
	case 101:
		if((active1 & 0x2L) != (long long)0L)
		{
			jjmatchedKind = 65;
			jjmatchedPos = 7;
		}
				else 
		{
			if((active2 & 0x2000000000L) != (long long)0L)
			{
				jjmatchedKind = 165;
				jjmatchedPos = 7;
			}
		}
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0x11000L, active2, (long long)0x8000000000000000L, ctx);
	case 107:
		if((active2 & 0x200000L) != (long long)0L)
		{
			jjmatchedKind = 149;
			jjmatchedPos = 7;
		}
		break ;
	case 108:
		if((active1 & 0x400000000L) != (long long)0L)
		{
			jjmatchedKind = 98;
			jjmatchedPos = 7;
		}
		break ;
	case 110:
		if((active2 & 0x100000000000000L) != (long long)0L)
		{
			jjmatchedKind = 184;
			jjmatchedPos = 7;
		}
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0x400800L, active2, (long long)0x80000000000L, ctx);
	case 111:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0x200000000L, active2, (long long)0x800000000010000L, ctx);
	case 114:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0x100000000L, active2, (long long)0x200000000000L, ctx);
	case 115:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x20000000000000L, ctx);
	case 116:
		if((active0 & 0x800000000000000L) != (long long)0L)
		{
			jjmatchedKind = 59;
			jjmatchedPos = 7;
		}
				else 
		{
			if((active1 & 0x80000000L) != (long long)0L)
			{
				jjmatchedKind = 95;
				jjmatchedPos = 7;
			}
						else 
			{
				if((active2 & 0x40L) != (long long)0L)
				{
					jjmatchedKind = 134;
					jjmatchedPos = 7;
				}
			}
		}
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000L, ctx);
	case 119:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x10000000000000L, ctx);
	case 122:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2000000000000000L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)7, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa8_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	active1 = active1 & (old1);
	active2 = active2 & (old2);
	if(((active0) | (active1) | (active2)) == (bool)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)7, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)7, ctx);
		}
	}
	switch(curChar) {
	case 65:
		return jjMoveStringLiteralDfa9_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2000000000000000L, ctx);
	case 68:
		if((active2 & 0x8000000000000000L) != (long long)0L)
		{
			jjmatchedKind = 191;
			jjmatchedPos = 8;
		}
		break ;
	case 69:
		if((active2 & 0x200000000000L) != (long long)0L)
		{
			jjmatchedKind = 173;
			jjmatchedPos = 8;
		}
		return jjMoveStringLiteralDfa9_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x28000000000000L, ctx);
	case 72:
		return jjMoveStringLiteralDfa9_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x10000000000000L, ctx);
	case 73:
		return jjMoveStringLiteralDfa9_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x8000L, ctx);
	case 78:
		if((active2 & 0x10000L) != (long long)0L)
		{
			jjmatchedKind = 144;
			jjmatchedPos = 8;
		}
				else 
		{
			if((active2 & 0x800000000000000L) != (long long)0L)
			{
				jjmatchedKind = 187;
				jjmatchedPos = 8;
			}
		}
		break ;
	case 84:
		if((active2 & 0x80000000000L) != (long long)0L)
		{
			jjmatchedKind = 171;
			jjmatchedPos = 8;
		}
		break ;
	case 97:
		return jjMoveStringLiteralDfa9_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x2000000000000000L, ctx);
	case 100:
		if((active1 & 0x10000L) != (long long)0L)
		{
			jjmatchedKind = 80;
			jjmatchedPos = 8;
		}
				else 
		{
			if((active2 & 0x8000000000000000L) != (long long)0L)
			{
				jjmatchedKind = 191;
				jjmatchedPos = 8;
			}
		}
		break ;
	case 101:
		if((active0 & 0x400000000000000L) != (long long)0L)
		{
			jjmatchedKind = 58;
			jjmatchedPos = 8;
		}
				else 
		{
			if((active2 & 0x200000000000L) != (long long)0L)
			{
				jjmatchedKind = 173;
				jjmatchedPos = 8;
			}
		}
		return jjMoveStringLiteralDfa9_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x28000000000000L, ctx);
	case 104:
		return jjMoveStringLiteralDfa9_0(active0, (long long)0L, active1, (long long)0L, active2, (long long)0x10000000000000L, ctx);
	case 105:
		return jjMoveStringLiteralDfa9_0(active0, (long long)0L, active1, (long long)0x400000L, active2, (long long)0x8000L, ctx);
	case 110:
		if((active2 & 0x10000L) != (long long)0L)
		{
			jjmatchedKind = 144;
			jjmatchedPos = 8;
		}
				else 
		{
			if((active2 & 0x800000000000000L) != (long long)0L)
			{
				jjmatchedKind = 187;
				jjmatchedPos = 8;
			}
		}
		break ;
	case 111:
		return jjMoveStringLiteralDfa9_0(active0, (long long)0L, active1, (long long)0x100001000L, active2, (long long)0L, ctx);
	case 114:
		if((active1 & 0x200000000L) != (long long)0L)
		{
			jjmatchedKind = 97;
			jjmatchedPos = 8;
		}
		break ;
	case 116:
		if((active2 & 0x80000000000L) != (long long)0L)
		{
			jjmatchedKind = 171;
			jjmatchedPos = 8;
		}
		return jjMoveStringLiteralDfa9_0(active0, (long long)0L, active1, (long long)0x800L, active2, (long long)0L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)8, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa9_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	active1 = active1 & (old1);
	active2 = active2 & (old2);
	if(((active0) | (active1) | (active2)) == (bool)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)8, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)8, ctx);
		}
	}
	switch(curChar) {
	case 66:
		return jjMoveStringLiteralDfa10_0(active1, (long long)0L, active2, (long long)0x2000000000000000L, ctx);
	case 69:
		return jjMoveStringLiteralDfa10_0(active1, (long long)0L, active2, (long long)0x10000000000000L, ctx);
	case 79:
		return jjMoveStringLiteralDfa10_0(active1, (long long)0L, active2, (long long)0x8000L, ctx);
	case 83:
		if((active2 & 0x8000000000000L) != (long long)0L)
		{
			jjmatchedKind = 179;
			jjmatchedPos = 9;
		}
		break ;
	case 84:
		if((active2 & 0x20000000000000L) != (long long)0L)
		{
			jjmatchedKind = 181;
			jjmatchedPos = 9;
		}
		break ;
	case 98:
		return jjMoveStringLiteralDfa10_0(active1, (long long)0L, active2, (long long)0x2000000000000000L, ctx);
	case 101:
		return jjMoveStringLiteralDfa10_0(active1, (long long)0L, active2, (long long)0x10000000000000L, ctx);
	case 102:
		if((active1 & 0x1000L) != (long long)0L)
		{
			jjmatchedKind = 76;
			jjmatchedPos = 9;
		}
		break ;
	case 109:
		if((active1 & 0x100000000L) != (long long)0L)
		{
			jjmatchedKind = 96;
			jjmatchedPos = 9;
		}
		break ;
	case 111:
		return jjMoveStringLiteralDfa10_0(active1, (long long)0L, active2, (long long)0x8000L, ctx);
	case 115:
		if((active1 & 0x800L) != (long long)0L)
		{
			jjmatchedKind = 75;
			jjmatchedPos = 9;
		}
				else 
		{
			if((active2 & 0x8000000000000L) != (long long)0L)
			{
				jjmatchedKind = 179;
				jjmatchedPos = 9;
			}
		}
		break ;
	case 116:
		if((active2 & 0x20000000000000L) != (long long)0L)
		{
			jjmatchedKind = 181;
			jjmatchedPos = 9;
		}
		break ;
	case 122:
		return jjMoveStringLiteralDfa10_0(active1, (long long)0x400000L, active2, (long long)0L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)9, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa10_0(long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx)
{
	active1 = active1 & (old1);
	active2 = active2 & (old2);
	if(((active1) | (active2)) == (bool)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)9, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)9, ctx);
		}
	}
	switch(curChar) {
	case 76:
		return jjMoveStringLiteralDfa11_0(active1, (long long)0L, active2, (long long)0x2000000000000000L, ctx);
	case 78:
		if((active2 & 0x8000L) != (long long)0L)
		{
			jjmatchedKind = 143;
			jjmatchedPos = 10;
		}
		break ;
	case 82:
		return jjMoveStringLiteralDfa11_0(active1, (long long)0L, active2, (long long)0x10000000000000L, ctx);
	case 101:
		return jjMoveStringLiteralDfa11_0(active1, (long long)0x400000L, active2, (long long)0L, ctx);
	case 108:
		return jjMoveStringLiteralDfa11_0(active1, (long long)0L, active2, (long long)0x2000000000000000L, ctx);
	case 110:
		if((active2 & 0x8000L) != (long long)0L)
		{
			jjmatchedKind = 143;
			jjmatchedPos = 10;
		}
		break ;
	case 114:
		return jjMoveStringLiteralDfa11_0(active1, (long long)0L, active2, (long long)0x10000000000000L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)10, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa11_0(long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx)
{
	active1 = active1 & (old1);
	active2 = active2 & (old2);
	if(((active1) | (active2)) == (bool)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)10, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)10, ctx);
		}
	}
	switch(curChar) {
	case 69:
		if((active2 & 0x10000000000000L) != (long long)0L)
		{
			jjmatchedKind = 180;
			jjmatchedPos = 11;
		}
				else 
		{
			if((active2 & 0x2000000000000000L) != (long long)0L)
			{
				jjmatchedKind = 189;
				jjmatchedPos = 11;
			}
		}
		break ;
	case 100:
		if((active1 & 0x400000L) != (long long)0L)
		{
			jjmatchedKind = 86;
			jjmatchedPos = 11;
		}
		break ;
	case 101:
		if((active2 & 0x10000000000000L) != (long long)0L)
		{
			jjmatchedKind = 180;
			jjmatchedPos = 11;
		}
				else 
		{
			if((active2 & 0x2000000000000000L) != (long long)0L)
			{
				jjmatchedKind = 189;
				jjmatchedPos = 11;
			}
		}
		break ;
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)11, ctx);
}
long long AlinousPlusParserTokenManager::jjMoveNfa_0(long long startState, long long curPos, ThreadContext* ctx)
{
	long long strKind = jjmatchedKind;
	long long strPos = jjmatchedPos;
	long long seenUpto = 0;
	seenUpto = curPos + 1;
	input_stream->backup((int)seenUpto, ctx);
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			throw (new(ctx) Error(ConstStr::getCNST_STR_1545(), ctx));
		}
	}
	curPos = 0;
	long long startsAt = 0;
	jjnewStateCnt = 73;
	long long i = 1;
	jjstateSet->set(startState,0, ctx);
	long long kind = 0x7fffffff;
	for(; ; )
	{
		if(++jjround == (long long)0x7fffffff)
		{
			ReInitRounds(ctx);
		}
		if(curChar < (wchar_t)64)
		{
			long long l = 1L << curChar;
			do
			{
				switch(jjstateSet->get(--i)) {
				case 0:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)0, (long long)6, ctx);
					}
										else 
					{
						if(curChar == (wchar_t)39)
						{
							jjCheckNAddStates((long long)7, (long long)11, ctx);
						}
												else 
						{
							if(curChar == (wchar_t)34)
							{
								jjCheckNAddStates((long long)12, (long long)14, ctx);
							}
														else 
							{
								if(curChar == (wchar_t)46)
								{
									jjCheckNAdd((long long)4, ctx);
								}
							}
						}
					}
					if((0x3fe000000000000L & l) != 0L)
					{
						if(kind > (long long)9)
						{
							kind = 9;
						}
						{
							jjCheckNAddTwoStates((long long)1, (long long)2, ctx);
						}
					}
										else 
					{
						if(curChar == (wchar_t)48)
						{
							if(kind > (long long)9)
							{
								kind = 9;
							}
							{
								jjCheckNAddStates((long long)15, (long long)19, ctx);
							}
						}
					}
					break ;
				case 1:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)9)
					{
						kind = 9;
					}
					{
						jjCheckNAddTwoStates((long long)1, (long long)2, ctx);
					}
					break ;
				case 3:
					if(curChar == (wchar_t)46)
					{
						jjCheckNAdd((long long)4, ctx);
					}
					break ;
				case 4:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)13)
					{
						kind = 13;
					}
					{
						jjCheckNAddStates((long long)20, (long long)22, ctx);
					}
					break ;
				case 6:
					if((0x280000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)7, ctx);
					}
					break ;
				case 7:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)13)
					{
						kind = 13;
					}
					{
						jjCheckNAddTwoStates((long long)7, (long long)8, ctx);
					}
					break ;
				case 9:
					if(curChar == (wchar_t)34)
					{
						jjCheckNAddStates((long long)12, (long long)14, ctx);
					}
					break ;
				case 10:
					if((0xfffffffbffffdbffL & l) != 0L)
					{
						jjCheckNAddStates((long long)12, (long long)14, ctx);
					}
					break ;
				case 12:
					if((0x8400000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)12, (long long)14, ctx);
					}
					break ;
				case 13:
					if(curChar == (wchar_t)34 && kind > (long long)18)
					{
						kind = 18;
					}
					break ;
				case 14:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)23, (long long)26, ctx);
					}
					break ;
				case 15:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)12, (long long)14, ctx);
					}
					break ;
				case 16:
					if((0xf000000000000L & l) != 0L)
					{
						jjstateSet->set(17,jjnewStateCnt++, ctx);
					}
					break ;
				case 17:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)15, ctx);
					}
					break ;
				case 19:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)192)
					{
						kind = 192;
					}
					jjstateSet->set(19,jjnewStateCnt++, ctx);
					break ;
				case 20:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)0, (long long)6, ctx);
					}
					break ;
				case 21:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)27, (long long)29, ctx);
					}
					break ;
				case 23:
					if((0x280000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)24, ctx);
					}
					break ;
				case 24:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddTwoStates((long long)24, (long long)8, ctx);
					}
					break ;
				case 25:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddTwoStates((long long)25, (long long)26, ctx);
					}
					break ;
				case 27:
					if((0x280000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)28, ctx);
					}
					break ;
				case 28:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)13)
					{
						kind = 13;
					}
					{
						jjCheckNAddTwoStates((long long)28, (long long)8, ctx);
					}
					break ;
				case 29:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddTwoStates((long long)29, (long long)30, ctx);
					}
					break ;
				case 30:
					if(curChar != (wchar_t)46)
					{
						break ;
					}
					if(kind > (long long)13)
					{
						kind = 13;
					}
					{
						jjCheckNAddStates((long long)30, (long long)32, ctx);
					}
					break ;
				case 31:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)13)
					{
						kind = 13;
					}
					{
						jjCheckNAddStates((long long)30, (long long)32, ctx);
					}
					break ;
				case 33:
					if((0x280000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)34, ctx);
					}
					break ;
				case 34:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)13)
					{
						kind = 13;
					}
					{
						jjCheckNAddTwoStates((long long)34, (long long)8, ctx);
					}
					break ;
				case 35:
					if(curChar == (wchar_t)39)
					{
						jjCheckNAddStates((long long)7, (long long)11, ctx);
					}
					break ;
				case 36:
					if((0xffffff7fffffdbffL & l) != 0L)
					{
						jjCheckNAdd((long long)37, ctx);
					}
					break ;
				case 37:
					if(curChar == (wchar_t)39 && kind > (long long)19)
					{
						kind = 19;
					}
					break ;
				case 39:
					if((0x8400000000L & l) != 0L)
					{
						jjCheckNAdd((long long)37, ctx);
					}
					break ;
				case 40:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAddTwoStates((long long)41, (long long)37, ctx);
					}
					break ;
				case 41:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)37, ctx);
					}
					break ;
				case 42:
					if((0xf000000000000L & l) != 0L)
					{
						jjstateSet->set(43,jjnewStateCnt++, ctx);
					}
					break ;
				case 43:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)41, ctx);
					}
					break ;
				case 45:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddTwoStates((long long)45, (long long)37, ctx);
					}
					break ;
				case 46:
					if((0xffffff7fffffdbffL & l) != 0L)
					{
						jjCheckNAddStates((long long)33, (long long)35, ctx);
					}
					break ;
				case 48:
					if((0x8400000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)33, (long long)35, ctx);
					}
					break ;
				case 49:
					if(curChar == (wchar_t)39 && kind > (long long)20)
					{
						kind = 20;
					}
					break ;
				case 50:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)36, (long long)39, ctx);
					}
					break ;
				case 51:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)33, (long long)35, ctx);
					}
					break ;
				case 52:
					if((0xf000000000000L & l) != 0L)
					{
						jjstateSet->set(53,jjnewStateCnt++, ctx);
					}
					break ;
				case 53:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)51, ctx);
					}
					break ;
				case 55:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)40, (long long)43, ctx);
					}
					break ;
				case 56:
					if(curChar != (wchar_t)48)
					{
						break ;
					}
					if(kind > (long long)9)
					{
						kind = 9;
					}
					{
						jjCheckNAddStates((long long)15, (long long)19, ctx);
					}
					break ;
				case 58:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)9)
					{
						kind = 9;
					}
					{
						jjCheckNAddTwoStates((long long)58, (long long)2, ctx);
					}
					break ;
				case 59:
					if((0xff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)9)
					{
						kind = 9;
					}
					{
						jjCheckNAddTwoStates((long long)59, (long long)2, ctx);
					}
					break ;
				case 61:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjAddStates((long long)44, (long long)45, ctx);
					}
					break ;
				case 62:
					if(curChar == (wchar_t)46)
					{
						jjCheckNAdd((long long)63, ctx);
					}
					break ;
				case 63:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddTwoStates((long long)63, (long long)64, ctx);
					}
					break ;
				case 65:
					if((0x280000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)66, ctx);
					}
					break ;
				case 66:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)13)
					{
						kind = 13;
					}
					{
						jjCheckNAddTwoStates((long long)66, (long long)8, ctx);
					}
					break ;
				case 68:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)46, (long long)48, ctx);
					}
					break ;
				case 69:
					if(curChar == (wchar_t)46)
					{
						jjCheckNAdd((long long)70, ctx);
					}
					break ;
				case 71:
					if((0x280000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)72, ctx);
					}
					break ;
				case 72:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)13)
					{
						kind = 13;
					}
					{
						jjCheckNAddTwoStates((long long)72, (long long)8, ctx);
					}
					break ;
				default:
					break ;
				}
			}
			while(i != startsAt);
		}
				else 
		{
			if(curChar < (wchar_t)128)
			{
				long long l = 1L << (curChar & 077);
				do
				{
					switch(jjstateSet->get(--i)) {
					case 0:
					case 19:
						if((0x7fffffe87fffffeL & l) == 0L)
						{
							break ;
						}
						if(kind > (long long)192)
						{
							kind = 192;
						}
						{
							jjCheckNAdd((long long)19, ctx);
						}
						break ;
					case 2:
						if((0x100000001000L & l) != 0L && kind > (long long)9)
						{
							kind = 9;
						}
						break ;
					case 5:
						if((0x2000000020L & l) != 0L)
						{
							jjAddStates((long long)49, (long long)50, ctx);
						}
						break ;
					case 8:
						if((0x5000000050L & l) != 0L && kind > (long long)13)
						{
							kind = 13;
						}
						break ;
					case 10:
						if((0xffffffffefffffffL & l) != 0L)
						{
							jjCheckNAddStates((long long)12, (long long)14, ctx);
						}
						break ;
					case 11:
						if(curChar == (wchar_t)92)
						{
							jjAddStates((long long)51, (long long)53, ctx);
						}
						break ;
					case 12:
						if((0x14404410000000L & l) != 0L)
						{
							jjCheckNAddStates((long long)12, (long long)14, ctx);
						}
						break ;
					case 22:
						if((0x2000000020L & l) != 0L)
						{
							jjAddStates((long long)54, (long long)55, ctx);
						}
						break ;
					case 26:
						if((0x2000000020L & l) != 0L)
						{
							jjAddStates((long long)56, (long long)57, ctx);
						}
						break ;
					case 32:
						if((0x2000000020L & l) != 0L)
						{
							jjAddStates((long long)58, (long long)59, ctx);
						}
						break ;
					case 36:
						if((0xffffffffefffffffL & l) != 0L)
						{
							jjCheckNAdd((long long)37, ctx);
						}
						break ;
					case 38:
						if(curChar == (wchar_t)92)
						{
							jjAddStates((long long)60, (long long)63, ctx);
						}
						break ;
					case 39:
						if((0x14404410000000L & l) != 0L)
						{
							jjCheckNAdd((long long)37, ctx);
						}
						break ;
					case 44:
						if(curChar == (wchar_t)117)
						{
							jjCheckNAdd((long long)45, ctx);
						}
						break ;
					case 45:
						if((0x7e0000007eL & l) != 0L)
						{
							jjCheckNAddTwoStates((long long)45, (long long)37, ctx);
						}
						break ;
					case 46:
						if((0xffffffffefffffffL & l) != 0L)
						{
							jjCheckNAddStates((long long)33, (long long)35, ctx);
						}
						break ;
					case 47:
						if(curChar == (wchar_t)92)
						{
							jjAddStates((long long)64, (long long)67, ctx);
						}
						break ;
					case 48:
						if((0x14404410000000L & l) != 0L)
						{
							jjCheckNAddStates((long long)33, (long long)35, ctx);
						}
						break ;
					case 54:
						if(curChar == (wchar_t)117)
						{
							jjCheckNAdd((long long)55, ctx);
						}
						break ;
					case 55:
						if((0x7e0000007eL & l) != 0L)
						{
							jjCheckNAddStates((long long)40, (long long)43, ctx);
						}
						break ;
					case 57:
						if((0x100000001000000L & l) != 0L)
						{
							jjCheckNAdd((long long)58, ctx);
						}
						break ;
					case 58:
						if((0x7e0000007eL & l) == 0L)
						{
							break ;
						}
						if(kind > (long long)9)
						{
							kind = 9;
						}
						{
							jjCheckNAddTwoStates((long long)58, (long long)2, ctx);
						}
						break ;
					case 60:
						if((0x100000001000000L & l) != 0L)
						{
							jjCheckNAddTwoStates((long long)61, (long long)62, ctx);
						}
						break ;
					case 61:
						if((0x7e0000007eL & l) != 0L)
						{
							jjCheckNAddTwoStates((long long)61, (long long)62, ctx);
						}
						break ;
					case 63:
						if((0x7e0000007eL & l) != 0L)
						{
							jjAddStates((long long)68, (long long)69, ctx);
						}
						break ;
					case 64:
						if((0x1000000010000L & l) != 0L)
						{
							jjAddStates((long long)70, (long long)71, ctx);
						}
						break ;
					case 67:
						if((0x100000001000000L & l) != 0L)
						{
							jjCheckNAdd((long long)68, ctx);
						}
						break ;
					case 68:
						if((0x7e0000007eL & l) != 0L)
						{
							jjCheckNAddStates((long long)46, (long long)48, ctx);
						}
						break ;
					case 70:
						if((0x1000000010000L & l) != 0L)
						{
							jjAddStates((long long)72, (long long)73, ctx);
						}
						break ;
					default:
						break ;
					}
				}
				while(i != startsAt);
			}
						else 
			{
				long long hiByte = (curChar >> 8);
				long long i1 = hiByte >> 6;
				long long l1 = 1L << (hiByte & 077);
				long long i2 = (curChar & 0xff) >> 6;
				long long l2 = 1L << (curChar & 077);
				do
				{
					switch(jjstateSet->get(--i)) {
					case 10:
						if(jjCanMove_0(hiByte, i1, i2, l1, l2, ctx))
						{
							jjAddStates((long long)12, (long long)14, ctx);
						}
						break ;
					case 36:
						if(jjCanMove_0(hiByte, i1, i2, l1, l2, ctx))
						{
							jjstateSet->set(37,jjnewStateCnt++, ctx);
						}
						break ;
					case 46:
						if(jjCanMove_0(hiByte, i1, i2, l1, l2, ctx))
						{
							jjAddStates((long long)33, (long long)35, ctx);
						}
						break ;
					default:
						if(i1 == (long long)0 || l1 == (long long)0 || i2 == (long long)0 || l2 == (long long)0)
						{
							break ;
						}
												else 
						{
							break ;
						}
						break;
					}
				}
				while(i != startsAt);
			}
		}
		if(kind != (long long)0x7fffffff)
		{
			jjmatchedKind = kind;
			jjmatchedPos = curPos;
			kind = 0x7fffffff;
		}
		++curPos;
		i = jjnewStateCnt;
		startsAt = 73 - (jjnewStateCnt = startsAt);
		if((i) == (startsAt))
		{
			break ;
		}
		{
			try
			{
				curChar = input_stream->readChar(ctx);
			}
			catch(java::io::IOException* e)
			{
				break ;
			}
		}
	}
	if(jjmatchedPos > strPos)
	{
		return curPos;
	}
	long long toRet = Math::max(curPos, seenUpto, ctx);
	if(curPos < toRet)
	{
		for(i = toRet - Math::min(curPos, seenUpto, ctx); i-- > (long long)0; )
		{
			try
			{
				curChar = input_stream->readChar(ctx);
			}
			catch(java::io::IOException* e)
			{
				throw (new(ctx) Error(ConstStr::getCNST_STR_1546(), ctx));
			}
		}
	}
	if(jjmatchedPos < strPos)
	{
		jjmatchedKind = strKind;
		jjmatchedPos = strPos;
	}
		else 
	{
		if(jjmatchedPos == strPos && jjmatchedKind > strKind)
		{
			jjmatchedKind = strKind;
		}
	}
	return toRet;
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa0_1(ThreadContext* ctx)
{
	switch(curChar) {
	case 42:
		return jjMoveStringLiteralDfa1_1((long long)0x20L, ctx);
	default:
		return 1;
		break;
	}
}
long long AlinousPlusParserTokenManager::jjMoveStringLiteralDfa1_1(long long active3, ThreadContext* ctx)
{
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return 1;
		}
	}
	switch(curChar) {
	case 47:
		if((active3 & 0x20L) != (long long)0L)
		{
			return jjStopAtPos((long long)1, (long long)197, ctx);
		}
		break ;
	default:
		return 2;
		break;
	}
	return 2;
}
void AlinousPlusParserTokenManager::jjCheckNAdd(long long state, ThreadContext* ctx)
{
	if(jjrounds->get(state) != (uint64_t)jjround)
	{
		jjstateSet->set(state,jjnewStateCnt++, ctx);
		jjrounds->set(jjround,state, ctx);
	}
}
void AlinousPlusParserTokenManager::jjAddStates(long long start, long long end, ThreadContext* ctx)
{
	do
	{
		jjstateSet->set(jjnextStates->get(start),jjnewStateCnt++, ctx);
	}
	while(start++ != end);
}
void AlinousPlusParserTokenManager::jjCheckNAddTwoStates(long long state1, long long state2, ThreadContext* ctx)
{
	jjCheckNAdd(state1, ctx);
	jjCheckNAdd(state2, ctx);
}
void AlinousPlusParserTokenManager::jjCheckNAddStates(long long start, long long end, ThreadContext* ctx)
{
	do
	{
		jjCheckNAdd((long long)jjnextStates->get(start), ctx);
	}
	while(start++ != end);
}
void AlinousPlusParserTokenManager::ReInitRounds(ThreadContext* ctx)
{
	long long i = 0;
	jjround = 0x80000001;
	for(i = 73; i-- > (long long)0; )
	jjrounds->set(0x80000000,i, ctx);
}
bool AlinousPlusParserTokenManager::jjCanMove_0(long long hiByte, long long i1, long long i2, long long l1, long long l2, ThreadContext* ctx)
{
	switch(hiByte) {
	case 0:
		return ((jjbitVec2->get(i2) & l2) != (uint64_t)0L);
	default:
		if((jjbitVec0->get(i1) & l1) != (uint64_t)0L)
		{
			return true;
		}
		return false;
		break;
	}
}
}}

