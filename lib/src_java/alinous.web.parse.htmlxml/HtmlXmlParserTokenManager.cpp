#include "include/global.h"


#include "alinous.web.parse.htmlxml/TokenMgrError.h"
#include "alinous.web.parse.htmlxml/Token.h"
#include "alinous.web.parse.htmlxml/ParseException.h"
#include "alinous.compile/Token.h"
#include "alinous.web.parse.htmlxml/JavaCharStream.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParserConstants.h"
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
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
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
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/DbTransaction.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
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
#include "alinous.remote.region/RegionInsertExecutorPool.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.compile/ParseException.h"
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
#include "alinous.web.htmlxml/AbstractXHtmlElement.h"
#include "alinous.web.htmlxml/AbstractXHtmlAttributeValue.h"
#include "alinous.web.htmlxml/XHtmlAttribute.h"
#include "alinous.web.htmlxml/XMLTagBase.h"
#include "alinous.web.htmlxml.module/AbstractSerializedHtmlPart.h"
#include "alinous.web.htmlxml.module/SerializeContext.h"
#include "alinous.web.htmlxml/HtmlDocType.h"
#include "alinous.web.htmlxml/HtmlTopObject.h"
#include "alinous.web.htmlxml/BodyText.h"
#include "alinous.web.htmlxml/XHtmlComment.h"
#include "alinous.web.htmlxml.module/DynamicExecutableAttributeValue.h"
#include "alinous.web.htmlxml/XHtmlDqString.h"
#include "alinous.web.htmlxml/XHtmlSQString.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParser.h"
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
#include "alinous.system/AlinousException.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParserTokenManager.h"
#include "alinous.compile/JavaCharStream.h"

namespace alinous {namespace web {namespace parse {namespace htmlxml {





const StaticArrayObjectPrimitive<uint64_t> HtmlXmlParserTokenManager::__jjbitVec0 = {0xfffffffffffffffeL, 0xffffffffffffffffL, 0xffffffffffffffffL, 0xffffffffffffffffL};
IArrayObjectPrimitive<uint64_t>* HtmlXmlParserTokenManager::jjbitVec0 = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjbitVec0);
const StaticArrayObjectPrimitive<uint64_t> HtmlXmlParserTokenManager::__jjbitVec2 = {0x0L, 0x0L, 0xffffffffffffffffL, 0xffffffffffffffffL};
IArrayObjectPrimitive<uint64_t>* HtmlXmlParserTokenManager::jjbitVec2 = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjbitVec2);
const StaticArrayObjectPrimitive<uint64_t> HtmlXmlParserTokenManager::__jjnextStates = {24, 22, 21, 11, 12, 14, 2, 3, 5, 2, 3, 7, 5, 11, 12, 16, 14, 11, 12, 20, 14, 4, 6, 8, 13, 15, 17, 19};
IArrayObjectPrimitive<uint64_t>* HtmlXmlParserTokenManager::jjnextStates = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjnextStates);
const StaticArrayObject<UnicodeStringWrapper> HtmlXmlParserTokenManager::__jjstrLiteralImages = {ConstStr::getCNST_STR_4(), (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, ConstStr::getCNST_STR_1574(), ConstStr::getCNST_STR_1576(), ConstStr::getCNST_STR_1864(), ConstStr::getCNST_STR_1865(), ConstStr::getCNST_STR_1549(), ConstStr::getCNST_STR_1866(), ConstStr::getCNST_STR_1867(), ConstStr::getCNST_STR_1868(), ConstStr::getCNST_STR_1869(), ConstStr::getCNST_STR_1870(), (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, ConstStr::getCNST_STR_1871(), ConstStr::getCNST_STR_1872()};
IArrayObject<String>* HtmlXmlParserTokenManager::jjstrLiteralImages = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__jjstrLiteralImages);
const StaticArrayObject<UnicodeStringWrapper> HtmlXmlParserTokenManager::__lexStateNames = {ConstStr::getCNST_STR_1644(), ConstStr::getCNST_STR_1645()};
IArrayObject<String>* HtmlXmlParserTokenManager::lexStateNames = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__lexStateNames);
const StaticArrayObjectPrimitive<long long> HtmlXmlParserTokenManager::__jjnewLexState = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1};
IArrayObjectPrimitive<long long>* HtmlXmlParserTokenManager::jjnewLexState = (IArrayObjectPrimitive<long long>*)const_cast<StaticArrayObjectPrimitive<long long>*>(&__jjnewLexState);
const StaticArrayObjectPrimitive<uint64_t> HtmlXmlParserTokenManager::__jjtoToken = {0xf75fffffL};
IArrayObjectPrimitive<uint64_t>* HtmlXmlParserTokenManager::jjtoToken = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjtoToken);
const StaticArrayObjectPrimitive<uint64_t> HtmlXmlParserTokenManager::__jjtoMore = {0xa00000L};
IArrayObjectPrimitive<uint64_t>* HtmlXmlParserTokenManager::jjtoMore = (IArrayObjectPrimitive<uint64_t>*)const_cast<StaticArrayObjectPrimitive<uint64_t>*>(&__jjtoMore);
bool HtmlXmlParserTokenManager::__init_done = __init_static_variables();
bool HtmlXmlParserTokenManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HtmlXmlParserTokenManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HtmlXmlParserTokenManager::HtmlXmlParserTokenManager(JavaCharStream* stream, ThreadContext* ctx) : IObject(ctx), HtmlXmlParserConstants(ctx), debugStream(__GC_INS(this, System::out, java::io::PrintStream)), curLexState(0), defaultLexState(0), jjnewStateCnt(0), jjround(0), jjmatchedPos(0), jjmatchedKind(0), input_stream(nullptr), curChar(0), jjrounds(__GC_INS(this, ((IArrayObjectPrimitive<uint64_t>*)new(ctx) ArrayObjectPrimitive<uint64_t>(ArrayAllocatorPrimitive<uint64_t>::allocatep(ctx, 25), ctx)), IArrayObjectPrimitive<uint64_t>)), jjstateSet(__GC_INS(this, ((IArrayObjectPrimitive<uint64_t>*)new(ctx) ArrayObjectPrimitive<uint64_t>(ArrayAllocatorPrimitive<uint64_t>::allocatep(ctx, 2 * 25), ctx)), IArrayObjectPrimitive<uint64_t>)), jjimage(__GC_INS(this, (new(ctx) StringBuilder(ctx)), StringBuilder)), image(__GC_INS(this, jjimage, StringBuilder)), jjimageLen(0), lengthOfMatch(0)
{
	if(JavaCharStream::staticFlag)
	{
		throw (new(ctx) Error(ConstStr::getCNST_STR_1545(), ctx));
	}
	__GC_MV(this, &(input_stream), stream, JavaCharStream);
}
void HtmlXmlParserTokenManager::__construct_impl(JavaCharStream* stream, ThreadContext* ctx)
{
	if(JavaCharStream::staticFlag)
	{
		throw (new(ctx) Error(ConstStr::getCNST_STR_1545(), ctx));
	}
	__GC_MV(this, &(input_stream), stream, JavaCharStream);
}
 HtmlXmlParserTokenManager::HtmlXmlParserTokenManager(JavaCharStream* stream, long long lexState, ThreadContext* ctx) : IObject(ctx), HtmlXmlParserConstants(ctx), debugStream(__GC_INS(this, System::out, java::io::PrintStream)), curLexState(0), defaultLexState(0), jjnewStateCnt(0), jjround(0), jjmatchedPos(0), jjmatchedKind(0), input_stream(nullptr), curChar(0), jjrounds(__GC_INS(this, ((IArrayObjectPrimitive<uint64_t>*)new(ctx) ArrayObjectPrimitive<uint64_t>(ArrayAllocatorPrimitive<uint64_t>::allocatep(ctx, 25), ctx)), IArrayObjectPrimitive<uint64_t>)), jjstateSet(__GC_INS(this, ((IArrayObjectPrimitive<uint64_t>*)new(ctx) ArrayObjectPrimitive<uint64_t>(ArrayAllocatorPrimitive<uint64_t>::allocatep(ctx, 2 * 25), ctx)), IArrayObjectPrimitive<uint64_t>)), jjimage(__GC_INS(this, (new(ctx) StringBuilder(ctx)), StringBuilder)), image(__GC_INS(this, jjimage, StringBuilder)), jjimageLen(0), lengthOfMatch(0)
{
	ReInit(stream, ctx);
	SwitchTo(lexState, ctx);
}
void HtmlXmlParserTokenManager::__construct_impl(JavaCharStream* stream, long long lexState, ThreadContext* ctx)
{
	ReInit(stream, ctx);
	SwitchTo(lexState, ctx);
}
 HtmlXmlParserTokenManager::~HtmlXmlParserTokenManager()
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HtmlXmlParserTokenManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HtmlXmlParserTokenManager", L"~HtmlXmlParserTokenManager");
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
void HtmlXmlParserTokenManager::setDebugStream(java::io::PrintStream* ds, ThreadContext* ctx)
{
	__GC_MV(this, &(debugStream), ds, java::io::PrintStream);
}
Token* HtmlXmlParserTokenManager::getNextToken(ThreadContext* ctx)
{
	Token* matchedToken = 0;
	long long curPos = 0;
	for(; ; )
	{
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
				if(jjmatchedPos == (long long)0 && jjmatchedKind > (long long)23)
				{
					jjmatchedKind = 23;
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
					TokenLexicalActions(matchedToken, ctx);
					if(jjnewLexState->get(jjmatchedKind) != (long long)-1)
					{
						curLexState = jjnewLexState->get(jjmatchedKind);
					}
					return matchedToken;
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
void HtmlXmlParserTokenManager::ReInit(JavaCharStream* stream, ThreadContext* ctx)
{
	jjmatchedPos = jjnewStateCnt = 0;
	curLexState = defaultLexState;
	__GC_MV(this, &(input_stream), stream, JavaCharStream);
	ReInitRounds(ctx);
}
void HtmlXmlParserTokenManager::ReInit(JavaCharStream* stream, long long lexState, ThreadContext* ctx)
{
	ReInit(stream, ctx);
	SwitchTo(lexState, ctx);
}
void HtmlXmlParserTokenManager::SwitchTo(long long lexState, ThreadContext* ctx)
{
	if(lexState >= (long long)2 || lexState < (long long)0)
	{
		throw (new(ctx) TokenMgrError(ConstStr::getCNST_STR_1546()->clone(ctx)->append(lexState, ctx)->append(ConstStr::getCNST_STR_1547(), ctx), TokenMgrError::INVALID_LEXICAL_STATE, ctx));
	}
		else 
	{
		curLexState = lexState;
	}
}
Token* HtmlXmlParserTokenManager::jjFillToken(ThreadContext* ctx)
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
void HtmlXmlParserTokenManager::TokenLexicalActions(Token* matchedToken, ThreadContext* ctx)
{
	switch(jjmatchedKind) {
	case 22:
		lengthOfMatch = jjmatchedPos + 1;
		image->append(input_stream->GetSuffix((int)jjimageLen + (lengthOfMatch), ctx), ctx);
		__GC_MV(matchedToken, &(matchedToken->image), image->substring(3, image->length(ctx) - 3, ctx), String);
		break ;
	case 25:
		lengthOfMatch = jjmatchedPos + 1;
		image->append(input_stream->GetSuffix((int)jjimageLen + (lengthOfMatch), ctx), ctx);
		__GC_MV(matchedToken, &(matchedToken->image), image->substring(1, image->length(ctx) - 1, ctx), String);
		break ;
	case 26:
		lengthOfMatch = jjmatchedPos + 1;
		image->append(input_stream->GetSuffix((int)jjimageLen + (lengthOfMatch), ctx), ctx);
		__GC_MV(matchedToken, &(matchedToken->image), image->substring(1, image->length(ctx) - 1, ctx), String);
		break ;
	default:
		break ;
	}
}
long long HtmlXmlParserTokenManager::jjStopAtPos(long long pos, long long kind, ThreadContext* ctx)
{
	jjmatchedKind = kind;
	jjmatchedPos = pos;
	return pos + 1;
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa0_0(ThreadContext* ctx)
{
	switch(curChar) {
	case 34:
		jjmatchedKind = 30;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 39:
		jjmatchedKind = 31;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 47:
		return jjMoveStringLiteralDfa1_0((long long)0x4000L, ctx);
	case 60:
		jjmatchedKind = 12;
		return jjMoveStringLiteralDfa1_0((long long)0x352000L, ctx);
	case 61:
		jjmatchedKind = 15;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 62:
		jjmatchedKind = 11;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 63:
		return jjMoveStringLiteralDfa1_0((long long)0x80000L, ctx);
	case 65:
		return jjMoveStringLiteralDfa1_0((long long)0x100L, ctx);
	case 66:
		return jjMoveStringLiteralDfa1_0((long long)0x82L, ctx);
	case 67:
		return jjMoveStringLiteralDfa1_0((long long)0x20L, ctx);
	case 72:
		return jjMoveStringLiteralDfa1_0((long long)0x200L, ctx);
	case 73:
		return jjMoveStringLiteralDfa1_0((long long)0x404L, ctx);
	case 76:
		return jjMoveStringLiteralDfa1_0((long long)0x8L, ctx);
	case 77:
		return jjMoveStringLiteralDfa1_0((long long)0x10L, ctx);
	case 80:
		return jjMoveStringLiteralDfa1_0((long long)0x40L, ctx);
	case 93:
		return jjMoveStringLiteralDfa1_0((long long)0x20000L, ctx);
	case 97:
		return jjMoveStringLiteralDfa1_0((long long)0x100L, ctx);
	case 98:
		return jjMoveStringLiteralDfa1_0((long long)0x82L, ctx);
	case 99:
		return jjMoveStringLiteralDfa1_0((long long)0x20L, ctx);
	case 104:
		return jjMoveStringLiteralDfa1_0((long long)0x200L, ctx);
	case 105:
		return jjMoveStringLiteralDfa1_0((long long)0x404L, ctx);
	case 108:
		return jjMoveStringLiteralDfa1_0((long long)0x8L, ctx);
	case 109:
		return jjMoveStringLiteralDfa1_0((long long)0x10L, ctx);
	case 112:
		return jjMoveStringLiteralDfa1_0((long long)0x40L, ctx);
	default:
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
		break;
	}
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa1_0(long long active0, ThreadContext* ctx)
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
	case 33:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x310000L, ctx);
	case 47:
		if((active0 & 0x2000L) != (long long)0L)
		{
			jjmatchedKind = 13;
			jjmatchedPos = 1;
		}
		break ;
	case 62:
		if((active0 & 0x4000L) != (long long)0L)
		{
			jjmatchedKind = 14;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active0 & 0x80000L) != (long long)0L)
			{
				jjmatchedKind = 19;
				jjmatchedPos = 1;
			}
		}
		break ;
	case 63:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x40000L, ctx);
	case 65:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0xc0L, ctx);
	case 69:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x10L, ctx);
	case 73:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x8L, ctx);
	case 77:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x4L, ctx);
	case 78:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x400L, ctx);
	case 79:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x20L, ctx);
	case 82:
		if((active0 & 0x2L) != (long long)0L)
		{
			jjmatchedKind = 1;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active0 & 0x200L) != (long long)0L)
			{
				jjmatchedKind = 9;
				jjmatchedPos = 1;
			}
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x100L, ctx);
	case 93:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x20000L, ctx);
	case 97:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0xc0L, ctx);
	case 101:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x10L, ctx);
	case 105:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x8L, ctx);
	case 109:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x4L, ctx);
	case 110:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x400L, ctx);
	case 111:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x20L, ctx);
	case 114:
		if((active0 & 0x2L) != (long long)0L)
		{
			jjmatchedKind = 1;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active0 & 0x200L) != (long long)0L)
			{
				jjmatchedKind = 9;
				jjmatchedPos = 1;
			}
		}
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x100L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)1, ctx);
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa2_0(long long old0, long long active0, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	if(((active0)) == (long long)0L)
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
	case 45:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x200000L, ctx);
	case 62:
		if((active0 & 0x20000L) != (long long)0L)
		{
			jjmatchedKind = 17;
			jjmatchedPos = 2;
		}
		break ;
	case 68:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x100000L, ctx);
	case 69:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x100L, ctx);
	case 71:
		if((active0 & 0x4L) != (long long)0L)
		{
			jjmatchedKind = 2;
			jjmatchedPos = 2;
		}
		break ;
	case 76:
		if((active0 & 0x20L) != (long long)0L)
		{
			jjmatchedKind = 5;
			jjmatchedPos = 2;
		}
		break ;
	case 78:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x8L, ctx);
	case 80:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x400L, ctx);
	case 82:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x40L, ctx);
	case 83:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x80L, ctx);
	case 84:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x10L, ctx);
	case 91:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x10000L, ctx);
	case 101:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x100L, ctx);
	case 103:
		if((active0 & 0x4L) != (long long)0L)
		{
			jjmatchedKind = 2;
			jjmatchedPos = 2;
		}
		break ;
	case 108:
		if((active0 & 0x20L) != (long long)0L)
		{
			jjmatchedKind = 5;
			jjmatchedPos = 2;
		}
		break ;
	case 110:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x8L, ctx);
	case 112:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x400L, ctx);
	case 114:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x40L, ctx);
	case 115:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x80L, ctx);
	case 116:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x10L, ctx);
	case 120:
		return jjMoveStringLiteralDfa3_0(active0, (long long)0x40000L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)2, ctx);
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa3_0(long long old0, long long active0, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	if(((active0)) == (long long)0L)
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
	case 45:
		if((active0 & 0x200000L) != (long long)0L)
		{
			jjmatchedKind = 21;
			jjmatchedPos = 3;
		}
		break ;
	case 65:
		if((active0 & 0x10L) != (long long)0L)
		{
			jjmatchedKind = 4;
			jjmatchedPos = 3;
		}
				else 
		{
			if((active0 & 0x100L) != (long long)0L)
			{
				jjmatchedKind = 8;
				jjmatchedPos = 3;
			}
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x40L, ctx);
	case 67:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x10000L, ctx);
	case 69:
		if((active0 & 0x80L) != (long long)0L)
		{
			jjmatchedKind = 7;
			jjmatchedPos = 3;
		}
		break ;
	case 75:
		if((active0 & 0x8L) != (long long)0L)
		{
			jjmatchedKind = 3;
			jjmatchedPos = 3;
		}
		break ;
	case 79:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x100000L, ctx);
	case 85:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x400L, ctx);
	case 97:
		if((active0 & 0x10L) != (long long)0L)
		{
			jjmatchedKind = 4;
			jjmatchedPos = 3;
		}
				else 
		{
			if((active0 & 0x100L) != (long long)0L)
			{
				jjmatchedKind = 8;
				jjmatchedPos = 3;
			}
		}
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x40L, ctx);
	case 101:
		if((active0 & 0x80L) != (long long)0L)
		{
			jjmatchedKind = 7;
			jjmatchedPos = 3;
		}
		break ;
	case 107:
		if((active0 & 0x8L) != (long long)0L)
		{
			jjmatchedKind = 3;
			jjmatchedPos = 3;
		}
		break ;
	case 109:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x40000L, ctx);
	case 117:
		return jjMoveStringLiteralDfa4_0(active0, (long long)0x400L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)3, ctx);
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa4_0(long long old0, long long active0, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	if(((active0)) == (long long)0L)
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
	case 67:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0x100000L, ctx);
	case 68:
		return jjMoveStringLiteralDfa5_0(active0, (long long)0x10000L, ctx);
	case 77:
		if((active0 & 0x40L) != (long long)0L)
		{
			jjmatchedKind = 6;
			jjmatchedPos = 4;
		}
		break ;
	case 84:
		if((active0 & 0x400L) != (long long)0L)
		{
			jjmatchedKind = 10;
			jjmatchedPos = 4;
		}
		break ;
	case 108:
		if((active0 & 0x40000L) != (long long)0L)
		{
			jjmatchedKind = 18;
			jjmatchedPos = 4;
		}
		break ;
	case 109:
		if((active0 & 0x40L) != (long long)0L)
		{
			jjmatchedKind = 6;
			jjmatchedPos = 4;
		}
		break ;
	case 116:
		if((active0 & 0x400L) != (long long)0L)
		{
			jjmatchedKind = 10;
			jjmatchedPos = 4;
		}
		break ;
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)4, ctx);
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa5_0(long long old0, long long active0, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	if(((active0)) == (long long)0L)
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
		return jjMoveStringLiteralDfa6_0(active0, (long long)0x10000L, ctx);
	case 84:
		return jjMoveStringLiteralDfa6_0(active0, (long long)0x100000L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)5, ctx);
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa6_0(long long old0, long long active0, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	if(((active0)) == (long long)0L)
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
	case 84:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0x10000L, ctx);
	case 89:
		return jjMoveStringLiteralDfa7_0(active0, (long long)0x100000L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)6, ctx);
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa7_0(long long old0, long long active0, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	if(((active0)) == (long long)0L)
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
	case 65:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0x10000L, ctx);
	case 80:
		return jjMoveStringLiteralDfa8_0(active0, (long long)0x100000L, ctx);
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)7, ctx);
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa8_0(long long old0, long long active0, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	if(((active0)) == (long long)0L)
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
	case 69:
		if((active0 & 0x100000L) != (long long)0L)
		{
			jjmatchedKind = 20;
			jjmatchedPos = 8;
		}
		break ;
	case 91:
		if((active0 & 0x10000L) != (long long)0L)
		{
			jjmatchedKind = 16;
			jjmatchedPos = 8;
		}
		break ;
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)8, ctx);
}
long long HtmlXmlParserTokenManager::jjMoveNfa_0(long long startState, long long curPos, ThreadContext* ctx)
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
			throw (new(ctx) Error(ConstStr::getCNST_STR_1543(), ctx));
		}
	}
	curPos = 0;
	long long startsAt = 0;
	jjnewStateCnt = 25;
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
					if((0xfffff7affffd9ffL & l) != 0L)
					{
						if(kind > (long long)28)
						{
							kind = 28;
						}
						{
							jjCheckNAddStates((long long)0, (long long)2, ctx);
						}
					}
										else 
					{
						if((0x100002600L & l) != 0L)
						{
							if(kind > (long long)24)
							{
								kind = 24;
							}
						}
												else 
						{
							if(curChar == (wchar_t)39)
							{
								jjCheckNAddStates((long long)3, (long long)5, ctx);
							}
														else 
							{
								if(curChar == (wchar_t)34)
								{
									jjCheckNAddStates((long long)6, (long long)8, ctx);
								}
																else 
								{
									if(curChar == (wchar_t)63)
									{
										if(kind > (long long)29)
										{
											kind = 29;
										}
										{
											jjCheckNAddTwoStates((long long)22, (long long)21, ctx);
										}
									}
								}
							}
						}
					}
					break ;
				case 1:
					if(curChar == (wchar_t)34)
					{
						jjCheckNAddStates((long long)6, (long long)8, ctx);
					}
					break ;
				case 2:
					if((0xfffffffbffffdbffL & l) != 0L)
					{
						jjCheckNAddStates((long long)6, (long long)8, ctx);
					}
					break ;
				case 4:
					if((0x8400000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)6, (long long)8, ctx);
					}
					break ;
				case 5:
					if(curChar == (wchar_t)34 && kind > (long long)25)
					{
						kind = 25;
					}
					break ;
				case 6:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)9, (long long)12, ctx);
					}
					break ;
				case 7:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)6, (long long)8, ctx);
					}
					break ;
				case 8:
					if((0xf000000000000L & l) != 0L)
					{
						jjstateSet->set(9,jjnewStateCnt++, ctx);
					}
					break ;
				case 9:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)7, ctx);
					}
					break ;
				case 10:
					if(curChar == (wchar_t)39)
					{
						jjCheckNAddStates((long long)3, (long long)5, ctx);
					}
					break ;
				case 11:
					if((0xffffff7fffffdbffL & l) != 0L)
					{
						jjCheckNAddStates((long long)3, (long long)5, ctx);
					}
					break ;
				case 13:
					if((0x8400000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)3, (long long)5, ctx);
					}
					break ;
				case 14:
					if(curChar == (wchar_t)39 && kind > (long long)26)
					{
						kind = 26;
					}
					break ;
				case 15:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)13, (long long)16, ctx);
					}
					break ;
				case 16:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)3, (long long)5, ctx);
					}
					break ;
				case 17:
					if((0xf000000000000L & l) != 0L)
					{
						jjstateSet->set(18,jjnewStateCnt++, ctx);
					}
					break ;
				case 18:
					if((0xff000000000000L & l) != 0L)
					{
						jjCheckNAdd((long long)16, ctx);
					}
					break ;
				case 20:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddStates((long long)17, (long long)20, ctx);
					}
					break ;
				case 21:
					if(curChar != (wchar_t)63)
					{
						break ;
					}
					if(kind > (long long)29)
					{
						kind = 29;
					}
					{
						jjCheckNAddTwoStates((long long)22, (long long)21, ctx);
					}
					break ;
				case 22:
					if((0xfffff7affffd9ffL & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)29)
					{
						kind = 29;
					}
					{
						jjCheckNAddTwoStates((long long)22, (long long)21, ctx);
					}
					break ;
				case 23:
					if((0xfffff7affffd9ffL & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)28)
					{
						kind = 28;
					}
					{
						jjCheckNAddStates((long long)0, (long long)2, ctx);
					}
					break ;
				case 24:
					if((0xfffff7affffd9ffL & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)28)
					{
						kind = 28;
					}
					{
						jjCheckNAdd((long long)24, ctx);
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
						if((0xd7ffffffefffffffL & l) != 0L)
						{
							if(kind > (long long)28)
							{
								kind = 28;
							}
							{
								jjCheckNAddStates((long long)0, (long long)2, ctx);
							}
						}
												else 
						{
							if((0x2800000010000000L & l) != 0L)
							{
								if(kind > (long long)29)
								{
									kind = 29;
								}
								{
									jjCheckNAddTwoStates((long long)22, (long long)21, ctx);
								}
							}
						}
						break ;
					case 2:
						if((0xffffffffefffffffL & l) != 0L)
						{
							jjCheckNAddStates((long long)6, (long long)8, ctx);
						}
						break ;
					case 3:
						if(curChar == (wchar_t)92)
						{
							jjAddStates((long long)21, (long long)23, ctx);
						}
						break ;
					case 4:
						if((0x14404410000000L & l) != 0L)
						{
							jjCheckNAddStates((long long)6, (long long)8, ctx);
						}
						break ;
					case 11:
						if((0xffffffffefffffffL & l) != 0L)
						{
							jjCheckNAddStates((long long)3, (long long)5, ctx);
						}
						break ;
					case 12:
						if(curChar == (wchar_t)92)
						{
							jjAddStates((long long)24, (long long)27, ctx);
						}
						break ;
					case 13:
						if((0x14404410000000L & l) != 0L)
						{
							jjCheckNAddStates((long long)3, (long long)5, ctx);
						}
						break ;
					case 19:
						if(curChar == (wchar_t)117)
						{
							jjCheckNAdd((long long)20, ctx);
						}
						break ;
					case 20:
						if((0x7e0000007eL & l) != 0L)
						{
							jjCheckNAddStates((long long)17, (long long)20, ctx);
						}
						break ;
					case 21:
						if((0x2800000010000000L & l) == 0L)
						{
							break ;
						}
						if(kind > (long long)29)
						{
							kind = 29;
						}
						{
							jjCheckNAddTwoStates((long long)22, (long long)21, ctx);
						}
						break ;
					case 22:
						if((0xd7ffffffefffffffL & l) == 0L)
						{
							break ;
						}
						if(kind > (long long)29)
						{
							kind = 29;
						}
						{
							jjCheckNAddTwoStates((long long)22, (long long)21, ctx);
						}
						break ;
					case 23:
						if((0xd7ffffffefffffffL & l) == 0L)
						{
							break ;
						}
						if(kind > (long long)28)
						{
							kind = 28;
						}
						{
							jjCheckNAddStates((long long)0, (long long)2, ctx);
						}
						break ;
					case 24:
						if((0xd7ffffffefffffffL & l) == 0L)
						{
							break ;
						}
						if(kind > (long long)28)
						{
							kind = 28;
						}
						{
							jjCheckNAdd((long long)24, ctx);
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
					case 0:
						if(!jjCanMove_0(hiByte, i1, i2, l1, l2, ctx))
						{
							break ;
						}
						if(kind > (long long)28)
						{
							kind = 28;
						}
						{
							jjCheckNAddStates((long long)0, (long long)2, ctx);
						}
						break ;
					case 2:
						if(jjCanMove_0(hiByte, i1, i2, l1, l2, ctx))
						{
							jjAddStates((long long)6, (long long)8, ctx);
						}
						break ;
					case 11:
						if(jjCanMove_0(hiByte, i1, i2, l1, l2, ctx))
						{
							jjAddStates((long long)3, (long long)5, ctx);
						}
						break ;
					case 22:
						if(!jjCanMove_0(hiByte, i1, i2, l1, l2, ctx))
						{
							break ;
						}
						if(kind > (long long)29)
						{
							kind = 29;
						}
						{
							jjCheckNAddTwoStates((long long)22, (long long)21, ctx);
						}
						break ;
					case 24:
						if(!jjCanMove_0(hiByte, i1, i2, l1, l2, ctx))
						{
							break ;
						}
						if(kind > (long long)28)
						{
							kind = 28;
						}
						{
							jjCheckNAdd((long long)24, ctx);
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
		startsAt = 25 - (jjnewStateCnt = startsAt);
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
				throw (new(ctx) Error(ConstStr::getCNST_STR_1544(), ctx));
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
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa0_1(ThreadContext* ctx)
{
	switch(curChar) {
	case 45:
		return jjMoveStringLiteralDfa1_1((long long)0x400000L, ctx);
	default:
		return 1;
		break;
	}
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa1_1(long long active0, ThreadContext* ctx)
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
	case 45:
		return jjMoveStringLiteralDfa2_1(active0, (long long)0x400000L, ctx);
	default:
		return 2;
		break;
	}
}
long long HtmlXmlParserTokenManager::jjMoveStringLiteralDfa2_1(long long old0, long long active0, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	if(((active0)) == (long long)0L)
	{
		return 2;
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return 2;
		}
	}
	switch(curChar) {
	case 62:
		if((active0 & 0x400000L) != (long long)0L)
		{
			return jjStopAtPos((long long)2, (long long)22, ctx);
		}
		break ;
	default:
		return 3;
		break;
	}
	return 3;
}
void HtmlXmlParserTokenManager::jjCheckNAdd(long long state, ThreadContext* ctx)
{
	if(jjrounds->get(state) != (uint64_t)jjround)
	{
		jjstateSet->set(state,jjnewStateCnt++, ctx);
		jjrounds->set(jjround,state, ctx);
	}
}
void HtmlXmlParserTokenManager::jjAddStates(long long start, long long end, ThreadContext* ctx)
{
	do
	{
		jjstateSet->set(jjnextStates->get(start),jjnewStateCnt++, ctx);
	}
	while(start++ != end);
}
void HtmlXmlParserTokenManager::jjCheckNAddTwoStates(long long state1, long long state2, ThreadContext* ctx)
{
	jjCheckNAdd(state1, ctx);
	jjCheckNAdd(state2, ctx);
}
void HtmlXmlParserTokenManager::jjCheckNAddStates(long long start, long long end, ThreadContext* ctx)
{
	do
	{
		jjCheckNAdd((long long)jjnextStates->get(start), ctx);
	}
	while(start++ != end);
}
void HtmlXmlParserTokenManager::ReInitRounds(ThreadContext* ctx)
{
	long long i = 0;
	jjround = 0x80000001;
	for(i = 25; i-- > (long long)0; )
	jjrounds->set(0x80000000,i, ctx);
}
bool HtmlXmlParserTokenManager::jjCanMove_0(long long hiByte, long long i1, long long i2, long long l1, long long l2, ThreadContext* ctx)
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
}}}}

