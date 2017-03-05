#include "include/global.h"


#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/Attribute.h"
#include "alinous.lock/LockObject.h"
#include "java.util/Random.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigInteger.h"
#include "alinous.numeric/RoundingMode.h"
#include "alinous.numeric/MathContext.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.remote.socket/ICommandData.h"
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
#include "alinous.runtime.dom/IVariableClassOperationCaller.h"
#include "alinous.runtime.dom/VariableOperationCaller.h"
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.runtime.variant/IVariantData.h"
#include "alinous.runtime.variant/StringData.h"
#include "alinous.runtime.variant/LongData.h"
#include "alinous.runtime.variant/IntData.h"
#include "alinous.runtime.variant/ShortData.h"
#include "alinous.runtime.variant/ByteData.h"
#include "alinous.runtime.variant/FloatData.h"
#include "alinous.runtime.variant/DoubleData.h"
#include "alinous.runtime.variant/BigDecimalData.h"
#include "alinous.runtime.variant/TimeData.h"
#include "alinous.runtime.variant/TimestampData.h"
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
#include "alinous.runtime.variant/CharData.h"
#include "alinous.runtime.variant/VariantDataFactory.h"

namespace alinous {namespace runtime {namespace variant {





constexpr const int VariantValue::TYPE_STRING;
constexpr const int VariantValue::TYPE_LONG;
constexpr const int VariantValue::TYPE_INT;
constexpr const int VariantValue::TYPE_SHORT;
constexpr const int VariantValue::TYPE_CHAR;
constexpr const int VariantValue::TYPE_BYTE;
constexpr const int VariantValue::TYPE_FLOAT;
constexpr const int VariantValue::TYPE_DOUBLE;
constexpr const int VariantValue::TYPE_BOOL;
constexpr const int VariantValue::TYPE_BIG_DECIMAL;
constexpr const int VariantValue::TYPE_TIME;
constexpr const int VariantValue::TYPE_TIMESTAMP;
constexpr const int VariantValue::TYPE_NULL;
String* VariantValue::TAG_NAME = nullptr;
String* VariantValue::ATTR_VTYPE = nullptr;
constexpr const int VariantValue::MAX_VALUE;
constexpr const int VariantValue::MIN_VALUE;
bool VariantValue::__init_done = __init_static_variables();
bool VariantValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariantValue", L"__init_static_variables");
		__GC_MV(nullptr, &(TAG_NAME), ConstStr::getCNST_STR_1236(), String);
		__GC_MV(nullptr, &(ATTR_VTYPE), ConstStr::getCNST_STR_1237(), String);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariantValue::VariantValue(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	this->vtype = VariantValue::TYPE_NULL;
	__GC_MV(this, &(this->data), nullptr, IVariantData);
	this->max = 0;
}
void VariantValue::__construct_impl(ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_NULL;
	__GC_MV(this, &(this->data), nullptr, IVariantData);
	this->max = 0;
}
 VariantValue::VariantValue(String* value, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	this->vtype = VariantValue::TYPE_STRING;
	__GC_MV(this, &(this->data), (new(ctx) StringData(value, ctx)), IVariantData);
	this->max = 0;
}
void VariantValue::__construct_impl(String* value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_STRING;
	__GC_MV(this, &(this->data), (new(ctx) StringData(value, ctx)), IVariantData);
	this->max = 0;
}
 VariantValue::VariantValue(long long lvalue, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	this->vtype = VariantValue::TYPE_LONG;
	__GC_MV(this, &(this->data), (new(ctx) LongData(lvalue, ctx)), IVariantData);
	this->max = 0;
}
void VariantValue::__construct_impl(long long lvalue, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_LONG;
	__GC_MV(this, &(this->data), (new(ctx) LongData(lvalue, ctx)), IVariantData);
	this->max = 0;
}
 VariantValue::VariantValue(int ivalue, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	this->vtype = VariantValue::TYPE_INT;
	__GC_MV(this, &(this->data), (new(ctx) IntData(ivalue, ctx)), IVariantData);
	this->max = 0;
}
void VariantValue::__construct_impl(int ivalue, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_INT;
	__GC_MV(this, &(this->data), (new(ctx) IntData(ivalue, ctx)), IVariantData);
	this->max = 0;
}
 VariantValue::VariantValue(short svalue, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	this->vtype = VariantValue::TYPE_SHORT;
	__GC_MV(this, &(this->data), (new(ctx) ShortData(svalue, ctx)), IVariantData);
	this->max = 0;
}
void VariantValue::__construct_impl(short svalue, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_SHORT;
	__GC_MV(this, &(this->data), (new(ctx) ShortData(svalue, ctx)), IVariantData);
	this->max = 0;
}
 VariantValue::VariantValue(wchar_t cvalue, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	this->vtype = VariantValue::TYPE_CHAR;
	__GC_MV(this, &(this->data), (new(ctx) CharData(cvalue, ctx)), IVariantData);
	this->max = 0;
}
void VariantValue::__construct_impl(wchar_t cvalue, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_CHAR;
	__GC_MV(this, &(this->data), (new(ctx) CharData(cvalue, ctx)), IVariantData);
	this->max = 0;
}
 VariantValue::VariantValue(char bvalue, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	this->vtype = VariantValue::TYPE_BYTE;
	__GC_MV(this, &(this->data), (new(ctx) ByteData(bvalue, ctx)), IVariantData);
	this->max = 0;
}
void VariantValue::__construct_impl(char bvalue, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_BYTE;
	__GC_MV(this, &(this->data), (new(ctx) ByteData(bvalue, ctx)), IVariantData);
	this->max = 0;
}
 VariantValue::VariantValue(float fvalue, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	this->vtype = VariantValue::TYPE_FLOAT;
	__GC_MV(this, &(this->data), (new(ctx) FloatData(fvalue, ctx)), IVariantData);
	this->max = 0;
}
void VariantValue::__construct_impl(float fvalue, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_FLOAT;
	__GC_MV(this, &(this->data), (new(ctx) FloatData(fvalue, ctx)), IVariantData);
	this->max = 0;
}
 VariantValue::VariantValue(double dvalue, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	this->vtype = VariantValue::TYPE_DOUBLE;
	__GC_MV(this, &(this->data), (new(ctx) DoubleData(dvalue, ctx)), IVariantData);
	this->max = 0;
}
void VariantValue::__construct_impl(double dvalue, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_DOUBLE;
	__GC_MV(this, &(this->data), (new(ctx) DoubleData(dvalue, ctx)), IVariantData);
	this->max = 0;
}
 VariantValue::VariantValue(BigDecimal* decvalue, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	setBigDecimal(decvalue, ctx);
	this->max = 0;
}
void VariantValue::__construct_impl(BigDecimal* decvalue, ThreadContext* ctx) throw() 
{
	setBigDecimal(decvalue, ctx);
	this->max = 0;
}
 VariantValue::VariantValue(TimeOnlyTimestamp* value, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	setTime(value, ctx);
	this->max = 0;
}
void VariantValue::__construct_impl(TimeOnlyTimestamp* value, ThreadContext* ctx) throw() 
{
	setTime(value, ctx);
	this->max = 0;
}
 VariantValue::VariantValue(Timestamp* value, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), vtype(0), data(nullptr), max(0)
{
	setTimestamp(value, ctx);
	this->max = 0;
}
void VariantValue::__construct_impl(Timestamp* value, ThreadContext* ctx) throw() 
{
	setTimestamp(value, ctx);
	this->max = 0;
}
 VariantValue::~VariantValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariantValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"VariantValue", L"~VariantValue");
	__e_obj1.add(this->data, this);
	data = nullptr;
	if(!prepare){
		return;
	}
}
void VariantValue::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(ATTR_VTYPE, Integer::toString(this->vtype, ctx), node, ctx));
	node->addAttribute(attr, ctx);
	if(this->data != nullptr)
	{
		this->data->outDebugXml(node, ctx);
	}
}
int VariantValue::getIntValue(ThreadContext* ctx)
{
	return data->getInt(ctx);
}
String* VariantValue::getStringValue(ThreadContext* ctx)
{
	return data->getString(ctx);
}
VariantValue* VariantValue::toVariantValue(ThreadContext* ctx)
{
	return this;
}
IAlinousVariable* VariantValue::copy(ThreadContext* ctx)
{
	VariantValue* newValue = (new(ctx) VariantValue(ctx));
	newValue->vtype = this->vtype;
	__GC_MV(newValue, &(newValue->data), this->data, IVariantData);
	newValue->max = this->max;
	return newValue;
}
String* VariantValue::toString(ThreadContext* ctx) throw() 
{
	if(this->max == (char)MAX_VALUE)
	{
		return ConstStr::getCNST_STR_1224();
	}
		else 
	{
		if(this->max == (char)MIN_VALUE)
		{
			return ConstStr::getCNST_STR_1225();
		}
	}
	if(this->data == nullptr)
	{
		return ConstStr::getCNST_STR_369();
	}
	{
		try
		{
			return data->getString(ctx);
		}
		catch(Throwable* e)
		{
			return nullptr;
		}
	}
}
void VariantValue::setString(String* value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_STRING;
	__GC_MV(this, &(this->data), (new(ctx) StringData(value, ctx)), IVariantData);
}
void VariantValue::setLong(long long value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_LONG;
	__GC_MV(this, &(this->data), (new(ctx) LongData(value, ctx)), IVariantData);
}
void VariantValue::setInt(int value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_INT;
	__GC_MV(this, &(this->data), (new(ctx) IntData(value, ctx)), IVariantData);
}
void VariantValue::setShort(short value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_SHORT;
	__GC_MV(this, &(this->data), (new(ctx) ShortData(value, ctx)), IVariantData);
}
void VariantValue::setChar(wchar_t value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_CHAR;
	__GC_MV(this, &(this->data), (new(ctx) CharData(value, ctx)), IVariantData);
}
void VariantValue::setByte(char value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_BYTE;
	__GC_MV(this, &(this->data), (new(ctx) ByteData(value, ctx)), IVariantData);
}
void VariantValue::setFloat(float value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_FLOAT;
	__GC_MV(this, &(this->data), (new(ctx) FloatData(value, ctx)), IVariantData);
}
void VariantValue::setDouble(double value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_DOUBLE;
	__GC_MV(this, &(this->data), (new(ctx) DoubleData(value, ctx)), IVariantData);
}
void VariantValue::setBigDecimal(BigDecimal* value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_BIG_DECIMAL;
	__GC_MV(this, &(this->data), (new(ctx) BigDecimalData(value, ctx)), IVariantData);
}
void VariantValue::setTime(TimeOnlyTimestamp* value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_TIME;
	__GC_MV(this, &(this->data), (new(ctx) TimeData(value, ctx)), IVariantData);
}
void VariantValue::setTimestamp(Timestamp* value, ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_TIMESTAMP;
	__GC_MV(this, &(this->data), (new(ctx) TimestampData(value, ctx)), IVariantData);
}
bool VariantValue::isMax(ThreadContext* ctx) throw() 
{
	return max == (char)VariantValue::MAX_VALUE;
}
bool VariantValue::isMinimum(ThreadContext* ctx) throw() 
{
	return max == (char)VariantValue::MIN_VALUE;
}
void VariantValue::setNull(ThreadContext* ctx) throw() 
{
	this->vtype = VariantValue::TYPE_NULL;
	__GC_MV(this, &(this->data), nullptr, IVariantData);
}
void VariantValue::setValue(VariantValue* variant, ThreadContext* ctx)
{
	this->vtype = variant->vtype;
	__GC_MV(this, &(this->data), variant->data, IVariantData);
}
int VariantValue::bufferSize(ThreadContext* ctx)
{
	int total = 4 + 1;
	if(this->data != nullptr && this->max == (char)0)
	{
		total += this->data->bufferSize(ctx);
	}
	return total;
}
void VariantValue::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(this->vtype, ctx);
	builder->putByte(this->max, ctx);
	if(this->data != nullptr && this->max == (char)0)
	{
		this->data->appendToEntry(builder, ctx);
	}
}
String* VariantValue::getString(ThreadContext* ctx) throw() 
{
	if(this->data == nullptr)
	{
		return ConstStr::getCNST_STR_369();
	}
	return this->data->getString(ctx);
}
long long VariantValue::getLong(ThreadContext* ctx) throw() 
{
	return this->data->getLong(ctx);
}
int VariantValue::getInt(ThreadContext* ctx) throw() 
{
	return this->data->getInt(ctx);
}
short VariantValue::getShort(ThreadContext* ctx) throw() 
{
	return this->data->getShort(ctx);
}
wchar_t VariantValue::getChar(ThreadContext* ctx) throw() 
{
	return this->data->getChar(ctx);
}
char VariantValue::getByte(ThreadContext* ctx) throw() 
{
	return this->data->getByte(ctx);
}
float VariantValue::getFloat(ThreadContext* ctx) throw() 
{
	return this->data->getFloat(ctx);
}
double VariantValue::getDouble(ThreadContext* ctx) throw() 
{
	return this->data->getDouble(ctx);
}
BigDecimal* VariantValue::getBigDecimal(ThreadContext* ctx) throw() 
{
	return this->data->getBigDecimal(ctx);
}
TimeOnlyTimestamp* VariantValue::getTime(ThreadContext* ctx) throw() 
{
	return this->data->getTime(ctx);
}
Timestamp* VariantValue::getTimestamp(ThreadContext* ctx) throw() 
{
	return this->data->getTimestamp(ctx);
}
int VariantValue::getVtype(ThreadContext* ctx) throw() 
{
	return vtype;
}
bool VariantValue::isNull(ThreadContext* ctx) throw() 
{
	return this->vtype == VariantValue::TYPE_NULL || this->data->isNull(ctx);
}
int VariantValue::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	if(isNull(ctx) || variant->isNull(ctx))
	{
		return nullCompare(variant, ctx);
	}
	if(this->max != (char)0 || variant->max != (char)0)
	{
		return compareMinMax(variant, ctx);
	}
	return this->data->compareTo(variant, ctx);
}
IAlinousVariable* VariantValue::add(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	String* thisStr = nullptr;
	String* another = nullptr;
	double dbl = 0;
	if(variant == nullptr || ((isNull(ctx) || variant->isNull(ctx)) && (getVtype(ctx) != VariantValue::TYPE_STRING && variant->getVtype(ctx) != VariantValue::TYPE_STRING)))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	if(variant->getVtype(ctx) == VariantValue::TYPE_STRING)
	{
		thisStr = this->data->getString(ctx);
		another = variant->data->getString(ctx);
		StringBuffer* buff = (new(ctx) StringBuffer(thisStr, ctx));
		buff->append(another, ctx);
		this->setString(buff->toString(ctx), ctx);
		return this;
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		{
		thisStr = getString(ctx);
		another = variant->getString(ctx);
		StringBuffer* buff = (new(ctx) StringBuffer(thisStr, ctx));
		buff->append(another, ctx);
		this->setString(buff->toString(ctx), ctx);
		}
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx) + variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx) + variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx) + variant->getShort(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx) + variant->getChar(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) + variant->getByte(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
		dbl = getFloat(ctx) + variant->getFloat(ctx);
		setFloat(((float)dbl), ctx);
		break ;
	case VariantValue::TYPE_DOUBLE:
		dbl = getDouble(ctx) + variant->getDouble(ctx);
		setDouble(dbl, ctx);
		break ;
	case VariantValue::TYPE_BIG_DECIMAL:
		{
			BigDecimal* dec = getBigDecimal(ctx);
			BigDecimal* operand = variant->getBigDecimal(ctx);
			dec = dec->add(operand, ctx);
			setBigDecimal(dec, ctx);
			break ;
		}
	case VariantValue::TYPE_TIME:
		{
			long long theTime = getLong(ctx) + variant->getLong(ctx);
			setTime((new(ctx) TimeOnlyTimestamp(theTime, ctx)), ctx);
			break ;
		}
	case VariantValue::TYPE_TIMESTAMP:
		{
			long long theTime = getLong(ctx) + variant->getLong(ctx);
			setTimestamp((new(ctx) Timestamp(theTime, ctx)), ctx);
			break ;
		}
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
IAlinousVariable* VariantValue::minus(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	double dbl = 0;
	if(variant == nullptr || isNull(ctx) || variant->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1226(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx) - variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx) - variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx) - variant->getShort(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx) - variant->getChar(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) - variant->getByte(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
		dbl = getFloat(ctx) - variant->getFloat(ctx);
		setFloat(((float)dbl), ctx);
		break ;
	case VariantValue::TYPE_DOUBLE:
		dbl = getDouble(ctx) - variant->getDouble(ctx);
		setDouble(dbl, ctx);
		break ;
	case VariantValue::TYPE_BIG_DECIMAL:
		{
			BigDecimal* dec = getBigDecimal(ctx);
			BigDecimal* operand = variant->getBigDecimal(ctx);
			dec = dec->subtract(operand, ctx);
			setBigDecimal(dec, ctx);
			break ;
		}
	case VariantValue::TYPE_TIME:
		{
			long long theTime = getLong(ctx) - variant->getLong(ctx);
			setTime((new(ctx) TimeOnlyTimestamp(theTime, ctx)), ctx);
			break ;
		}
	case VariantValue::TYPE_TIMESTAMP:
		{
			long long theTime = getLong(ctx) - variant->getLong(ctx);
			setTimestamp((new(ctx) Timestamp(theTime, ctx)), ctx);
			break ;
		}
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
IAlinousVariable* VariantValue::multiply(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	double dbl = 0;
	if(variant == nullptr || isNull(ctx) || variant->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1227(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx) * variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx) * variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx) * variant->getShort(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx) * variant->getChar(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) * variant->getByte(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
		dbl = getFloat(ctx) * variant->getFloat(ctx);
		setFloat(((float)dbl), ctx);
		break ;
	case VariantValue::TYPE_DOUBLE:
		dbl = getDouble(ctx) * variant->getDouble(ctx);
		setDouble(dbl, ctx);
		break ;
	case VariantValue::TYPE_BIG_DECIMAL:
		{
			BigDecimal* dec = getBigDecimal(ctx);
			BigDecimal* operand = variant->getBigDecimal(ctx);
			dec = dec->multiply(operand, ctx);
			setBigDecimal(dec, ctx);
			break ;
		}
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
IAlinousVariable* VariantValue::div(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	double dbl = 0;
	if(variant == nullptr || isNull(ctx) || variant->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1228(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx) / variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx) / variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx) / variant->getShort(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx) / variant->getChar(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) / variant->getByte(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
		dbl = getFloat(ctx) / variant->getFloat(ctx);
		setFloat(((float)dbl), ctx);
		break ;
	case VariantValue::TYPE_DOUBLE:
		dbl = getDouble(ctx) / variant->getDouble(ctx);
		setDouble(dbl, ctx);
		break ;
	case VariantValue::TYPE_BIG_DECIMAL:
		{
			BigDecimal* dec = getBigDecimal(ctx);
			BigDecimal* operand = variant->getBigDecimal(ctx);
			dec = dec->divide(operand, ctx);
			setBigDecimal(dec, ctx);
			break ;
		}
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
IAlinousVariable* VariantValue::shiftLeft(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	if(variant == nullptr || isNull(ctx) || variant->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1229(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx) << variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx) << variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx) << variant->getInt(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx) << variant->getInt(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) << variant->getInt(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
	case VariantValue::TYPE_DOUBLE:
	case VariantValue::TYPE_BIG_DECIMAL:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1230(), ctx));
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
IAlinousVariable* VariantValue::shiftRight(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	if(variant == nullptr || isNull(ctx) || variant->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1229(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx) >> variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx) >> variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx) >> variant->getInt(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx) >> variant->getInt(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) >> variant->getInt(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
	case VariantValue::TYPE_DOUBLE:
	case VariantValue::TYPE_BIG_DECIMAL:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1230(), ctx));
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
IAlinousVariable* VariantValue::shiftRightUnsigned(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	if(variant == nullptr || isNull(ctx) || variant->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1229(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = ((unsigned long long)getLong(ctx))>> variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = ((unsigned int)getInt(ctx))>> variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = ((unsigned short)getShort(ctx))>> variant->getInt(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = ((unsigned wchar_t)getChar(ctx))>> variant->getInt(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) >> variant->getInt(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
	case VariantValue::TYPE_DOUBLE:
	case VariantValue::TYPE_BIG_DECIMAL:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1230(), ctx));
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
IAlinousVariable* VariantValue::modulo(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	if(variant == nullptr || isNull(ctx) || variant->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1231(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx) % variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx) % variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx) % variant->getInt(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx) % variant->getInt(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) % variant->getInt(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
	case VariantValue::TYPE_DOUBLE:
	case VariantValue::TYPE_BIG_DECIMAL:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1232(), ctx));
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
bool VariantValue::isTrue(ThreadContext* ctx)
{
	int result = 0;
	double dresult = 0;
	if(isNull(ctx))
	{
		return false;
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		return true;
	case VariantValue::TYPE_LONG:
	case VariantValue::TYPE_INT:
	case VariantValue::TYPE_SHORT:
	case VariantValue::TYPE_CHAR:
	case VariantValue::TYPE_BYTE:
		result = getInt(ctx);
		if(result > 0)
		{
			return true;
		}
		break ;
	case VariantValue::TYPE_FLOAT:
	case VariantValue::TYPE_DOUBLE:
		dresult = getDouble(ctx);
		if(dresult > (double)0)
		{
			return true;
		}
		break ;
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return false;
}
IAlinousVariable* VariantValue::bitOr(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	if(variant == nullptr || isNull(ctx) || variant->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1233(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx) | variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx) | variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx) | variant->getInt(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx) | variant->getInt(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) | variant->getInt(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
	case VariantValue::TYPE_DOUBLE:
	case VariantValue::TYPE_BIG_DECIMAL:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1234(), ctx));
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
IAlinousVariable* VariantValue::bitAnd(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	if(variant == nullptr || isNull(ctx) || variant->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1233(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx) & variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx) & variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx) & variant->getInt(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx) & variant->getInt(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) & variant->getInt(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
	case VariantValue::TYPE_DOUBLE:
	case VariantValue::TYPE_BIG_DECIMAL:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1234(), ctx));
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
IAlinousVariable* VariantValue::bitExor(VariantValue* variant, ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	if(variant == nullptr || isNull(ctx) || variant->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1233(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx) ^ variant->getLong(ctx);
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx) ^ variant->getInt(ctx);
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx) ^ variant->getInt(ctx);
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx) ^ variant->getInt(ctx);
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx) ^ variant->getInt(ctx);
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
	case VariantValue::TYPE_DOUBLE:
	case VariantValue::TYPE_BIG_DECIMAL:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1234(), ctx));
	case VariantValue::TYPE_NULL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
IAlinousVariable* VariantValue::bitReverse(ThreadContext* ctx)
{
	int result = 0;
	long long lresult = 0;
	if(isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	switch(this->getVtype(ctx)) {
	case VariantValue::TYPE_STRING:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1235(), ctx));
	case VariantValue::TYPE_LONG:
		lresult = getLong(ctx);
		lresult = ~lresult;
		setLong(lresult, ctx);
		break ;
	case VariantValue::TYPE_INT:
		result = getInt(ctx);
		result = ~result;
		setInt(result, ctx);
		break ;
	case VariantValue::TYPE_SHORT:
		result = getShort(ctx);
		result = ~result;
		setShort(((short)result), ctx);
		break ;
	case VariantValue::TYPE_CHAR:
		result = getChar(ctx);
		result = ~result;
		setChar(((wchar_t)result), ctx);
		break ;
	case VariantValue::TYPE_BYTE:
		result = getByte(ctx);
		result = ~result;
		setByte(((char)result), ctx);
		break ;
	case VariantValue::TYPE_FLOAT:
	case VariantValue::TYPE_DOUBLE:
	case VariantValue::TYPE_NULL:
	case VariantValue::TYPE_BIG_DECIMAL:
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return this;
}
int VariantValue::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_VARIANT;
}
IDomVariable* VariantValue::toDomVariable(ThreadContext* ctx) throw() 
{
	DomVariable* val = (new(ctx) DomVariable(ctx));
	val->setValue(this, ctx);
	return val;
}
IAlinousVariable* VariantValue::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	VariableOperationCaller::add(this, variable, ctx);
	return this;
}
IAlinousVariable* VariantValue::add(DomVariable* variable, ThreadContext* ctx)
{
	return add(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* VariantValue::add(ByteVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::add(CharVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::add(DoubleVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::add(FloatVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::add(IntegerVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::add(ShortVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::add(StringVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::minus(this, variable, ctx);
}
IAlinousVariable* VariantValue::minus(DomVariable* variable, ThreadContext* ctx)
{
	return minus(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* VariantValue::minus(ByteVariable* variable, ThreadContext* ctx)
{
	return minus((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(CharVariable* variable, ThreadContext* ctx)
{
	return minus((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	return minus((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(FloatVariable* variable, ThreadContext* ctx)
{
	return minus((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	return minus((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(ShortVariable* variable, ThreadContext* ctx)
{
	return minus((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* VariantValue::multiply(DomVariable* variable, ThreadContext* ctx)
{
	return multiply(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* VariantValue::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	return multiply((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::multiply(CharVariable* variable, ThreadContext* ctx)
{
	return multiply((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	return multiply((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	return multiply((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	return multiply((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	return multiply((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* VariantValue::div(DomVariable* variable, ThreadContext* ctx)
{
	return div(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* VariantValue::div(ByteVariable* variable, ThreadContext* ctx)
{
	return div((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::div(CharVariable* variable, ThreadContext* ctx)
{
	return div((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::div(DoubleVariable* variable, ThreadContext* ctx)
{
	return div((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::div(FloatVariable* variable, ThreadContext* ctx)
{
	return div((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::div(IntegerVariable* variable, ThreadContext* ctx)
{
	return div((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::div(ShortVariable* variable, ThreadContext* ctx)
{
	return div((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* VariantValue::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::multiply(this, variable, ctx);
}
IAlinousVariable* VariantValue::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::div(this, variable, ctx);
}
IAlinousVariable* VariantValue::add(LongVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(LongVariable* variable, ThreadContext* ctx)
{
	return minus((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::multiply(LongVariable* variable, ThreadContext* ctx)
{
	return multiply((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::div(LongVariable* variable, ThreadContext* ctx)
{
	return div((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
bool VariantValue::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
IAlinousVariable* VariantValue::shiftLeft(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftLeft(this, variable, ctx);
}
IAlinousVariable* VariantValue::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	return shiftLeft(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->isValue(ctx) ? 1 : 0, ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRight(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftLeft(this, variable, ctx);
}
IAlinousVariable* VariantValue::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	return shiftRight(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->isValue(ctx) ? 1 : 0, ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftRight(this, variable, ctx);
}
IAlinousVariable* VariantValue::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftRight(this, variable, ctx);
}
IAlinousVariable* VariantValue::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftRight(this, variable, ctx);
}
IAlinousVariable* VariantValue::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftRight(this, variable, ctx);
}
IAlinousVariable* VariantValue::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftRight(this, variable, ctx);
}
IAlinousVariable* VariantValue::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftRight(this, variable, ctx);
}
IAlinousVariable* VariantValue::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftRight(this, variable, ctx);
}
IAlinousVariable* VariantValue::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftRight(this, variable, ctx);
}
IAlinousVariable* VariantValue::modulo(IAlinousVariable* variable, ThreadContext* ctx)
{
	VariableOperationCaller::modulo(this, variable, ctx);
	return this;
}
IAlinousVariable* VariantValue::modulo(DomVariable* variable, ThreadContext* ctx)
{
	return minus(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* VariantValue::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	return modulo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::modulo(CharVariable* variable, ThreadContext* ctx)
{
	return modulo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	return modulo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	return modulo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	return modulo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::modulo(LongVariable* variable, ThreadContext* ctx)
{
	return modulo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	return modulo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::modulo(StringVariable* variable, ThreadContext* ctx)
{
	return modulo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::substitute(IAlinousVariable* variable, ThreadContext* ctx)
{
	VariableOperationCaller::substitute(this, variable, ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(VariantValue* variable, ThreadContext* ctx)
{
	this->vtype = variable->vtype;
	__GC_MV(this, &(this->data), variable->data, IVariantData);
	return this;
}
IAlinousVariable* VariantValue::substitute(DomVariable* variable, ThreadContext* ctx)
{
	VariantValue* val = variable->getValue(ctx);
	this->vtype = val->vtype;
	__GC_MV(this, &(this->data), val->data, IVariantData);
	return this;
}
IAlinousVariable* VariantValue::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	int bl = variable->isValue(ctx) ? 1 : 0;
	setInt(bl, ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	setByte(variable->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(CharVariable* variable, ThreadContext* ctx)
{
	setChar(variable->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	setDouble(variable->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	setFloat(variable->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	setInt(variable->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(LongVariable* variable, ThreadContext* ctx)
{
	setLong(variable->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	setShort(variable->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(StringVariable* variable, ThreadContext* ctx)
{
	setString(variable->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	setTimestamp(variable->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* VariantValue::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	setTime(variable->getValue(ctx), ctx);
	return this;
}
int VariantValue::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
int VariantValue::compareTo(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::compareTo(this, variable, ctx);
}
int VariantValue::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return compareTo(variable->getValue(ctx), ctx);
}
int VariantValue::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	int intv = variable->isValue(ctx) ? 1 : 0;
	return compareTo((new(ctx) VariantValue(intv, ctx)), ctx);
}
int VariantValue::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
int VariantValue::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
int VariantValue::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
int VariantValue::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
int VariantValue::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
int VariantValue::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
int VariantValue::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
int VariantValue::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
int VariantValue::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
int VariantValue::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return compareTo((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitOr(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::bitOr(this, variable, ctx);
}
IAlinousVariable* VariantValue::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	return bitOr(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* VariantValue::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	return bitOr((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	return bitOr((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	return bitOr((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	return bitOr((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	return bitOr((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	return bitOr((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	return bitOr((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	return bitOr((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitAnd(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::bitOr(this, variable, ctx);
}
IAlinousVariable* VariantValue::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	return bitAnd(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* VariantValue::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	return bitAnd((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	return bitAnd((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	return bitAnd((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	return bitAnd((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	return bitAnd((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	return bitAnd((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	return bitAnd((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	return bitAnd((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitExor(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::bitExor(this, variable, ctx);
}
IAlinousVariable* VariantValue::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	return bitExor(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* VariantValue::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	return bitExor((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	return bitExor((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	return bitExor((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	return bitExor((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	return bitExor((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	return bitExor((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	return bitExor((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	return bitExor((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return minus((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return multiply((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return div((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return shiftRight((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return modulo((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return bitOr((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return bitAnd((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return bitExor((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return substitute((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftRightUnsigned(this, variable, ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	return shiftRightUnsigned(variable->getValue(ctx), ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* VariantValue::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	return shiftRightUnsigned((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	return shiftRightUnsigned((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	return shiftRightUnsigned((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	return shiftRightUnsigned((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	return shiftRightUnsigned((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	return shiftRightUnsigned((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	return shiftRightUnsigned((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	return shiftRightUnsigned((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return shiftRightUnsigned((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
BoolVariable* VariantValue::toBoolVariable(ThreadContext* ctx)
{
	return (new(ctx) BoolVariable(isTrue(ctx), ctx));
}
ByteVariable* VariantValue::toByteVariable(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(getByte(ctx), ctx));
}
CharVariable* VariantValue::toCharVariable(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(getChar(ctx), ctx));
}
ShortVariable* VariantValue::toShortVariable(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(getShort(ctx), ctx));
}
IntegerVariable* VariantValue::toIntVariable(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(getInt(ctx), ctx));
}
LongVariable* VariantValue::toLongVariable(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(getLong(ctx), ctx));
}
StringVariable* VariantValue::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(getString(ctx), ctx));
}
BigDecimalVariable* VariantValue::toBigDecimalVariable(ThreadContext* ctx)
{
	return (new(ctx) BigDecimalVariable(getBigDecimal(ctx), ctx));
}
long long VariantValue::getLongValue(ThreadContext* ctx)
{
	return getLong(ctx);
}
FloatVariable* VariantValue::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(getFloat(ctx), ctx));
}
DoubleVariable* VariantValue::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(getDouble(ctx), ctx));
}
TimeVariable* VariantValue::toTimeVariable(ThreadContext* ctx)
{
	return (new(ctx) TimeVariable(getTime(ctx), ctx));
}
TimestampVariable* VariantValue::toTimestampVariable(ThreadContext* ctx)
{
	return (new(ctx) TimestampVariable(getTimestamp(ctx), ctx));
}
IAlinousVariable* VariantValue::add(TimeVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::add(TimestampVariable* variable, ThreadContext* ctx)
{
	return add((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(TimeVariable* variable, ThreadContext* ctx)
{
	return minus((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	return minus((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::div(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::div(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	return shiftLeft((new(ctx) VariantValue(variable->getValue(ctx), ctx)), ctx);
}
IAlinousVariable* VariantValue::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* VariantValue::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
void VariantValue::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->vtype = buff->getInt(ctx);
	this->max = buff->getByte(ctx);
	if(this->vtype != TYPE_NULL && this->max == (char)0)
	{
		__GC_MV(this, &(this->data), VariantDataFactory::fromNetworkData(buff, ctx), IVariantData);
	}
}
void VariantValue::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__VariantValue, ctx);
	buff->putInt(this->vtype, ctx);
	buff->putByte(this->max, ctx);
	if(this->vtype != TYPE_NULL && this->max == (char)0)
	{
		this->data->writeData(buff, ctx);
	}
}
int VariantValue::nullCompare(VariantValue* variant, ThreadContext* ctx) throw() 
{
	if(isNull(ctx) && variant->isNull(ctx))
	{
		return 0;
	}
		else 
	{
		if(isNull(ctx) && !variant->isNull(ctx))
		{
			return -1;
		}
	}
	return 1;
}
int VariantValue::compareMinMax(VariantValue* variable, ThreadContext* ctx) throw() 
{
	if(this->max == (char)0)
	{
		return variable->max;
	}
	if(variable->max == (char)0)
	{
		return this->max;
	}
	return this->max - variable->max;
}
VariantValue* VariantValue::createMaxValue(int type, ThreadContext* ctx) throw() 
{
	VariantValue* vv = (new(ctx) VariantValue(ctx));
	vv->vtype = type;
	vv->max = MAX_VALUE;
	return vv;
}
VariantValue* VariantValue::createMinValue(int type, ThreadContext* ctx) throw() 
{
	VariantValue* vv = (new(ctx) VariantValue(ctx));
	vv->vtype = type;
	vv->max = MIN_VALUE;
	return vv;
}
VariantValue* VariantValue::importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(VariantValue::TAG_NAME, ctx))
	{
		return nullptr;
	}
	IVariableValue* vType = node->getAttributeValue(VariantValue::ATTR_VTYPE, ctx);
	if(vType == nullptr)
	{
		return nullptr;
	}
	String* strType = vType->toString(ctx);
	int type = 0;
	{
		try
		{
			type = Integer::parseInt(strType, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	DomNode* datanode = node->getChildNodeAt(0, ctx);
	if(datanode == nullptr)
	{
		return nullptr;
	}
	VariantValue* vv = (new(ctx) VariantValue(ctx));
	vv->vtype = type;
	switch(type) {
	case TYPE_STRING:
		__GC_MV(vv, &(vv->data), StringData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_LONG:
		__GC_MV(vv, &(vv->data), LongData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_INT:
		__GC_MV(vv, &(vv->data), IntData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_SHORT:
		__GC_MV(vv, &(vv->data), ShortData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_CHAR:
		__GC_MV(vv, &(vv->data), CharData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_BYTE:
		__GC_MV(vv, &(vv->data), ByteData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_FLOAT:
		__GC_MV(vv, &(vv->data), FloatData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_DOUBLE:
		__GC_MV(vv, &(vv->data), DoubleData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_BOOL:
		__GC_MV(vv, &(vv->data), ByteData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_BIG_DECIMAL:
		__GC_MV(vv, &(vv->data), BigDecimalData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_TIME:
		__GC_MV(vv, &(vv->data), TimeData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_TIMESTAMP:
		__GC_MV(vv, &(vv->data), TimestampData::importFromXml(datanode, ctx), IVariantData);
		break ;
	case TYPE_NULL:
		break ;
	default:
		return nullptr;
		break;
	}
	return vv;
}
VariantValue* VariantValue::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	int vtype = fetcher->fetchInt(ctx);
	VariantValue* ret = nullptr;
	char max = fetcher->fetchByte(ctx);
	if(max != (char)0)
	{
		ret = (new(ctx) VariantValue(ctx));
		ret->vtype = vtype;
		ret->max = max;
		return ret;
	}
	switch(vtype) {
	case VariantValue::TYPE_STRING:
		ret = (new(ctx) VariantValue(fetcher->fetchString(ctx), ctx));
		break ;
	case VariantValue::TYPE_LONG:
		ret = (new(ctx) VariantValue(fetcher->fetchLong(ctx), ctx));
		break ;
	case VariantValue::TYPE_INT:
		ret = (new(ctx) VariantValue(fetcher->fetchInt(ctx), ctx));
		break ;
	case VariantValue::TYPE_SHORT:
		ret = (new(ctx) VariantValue(fetcher->fetchShort(ctx), ctx));
		break ;
	case VariantValue::TYPE_CHAR:
		ret = (new(ctx) VariantValue(fetcher->fetchChar(ctx), ctx));
		break ;
	case VariantValue::TYPE_BYTE:
		ret = (new(ctx) VariantValue(fetcher->fetchByte(ctx), ctx));
		break ;
	case VariantValue::TYPE_FLOAT:
		ret = (new(ctx) VariantValue(fetcher->fetchFloat(ctx), ctx));
		break ;
	case VariantValue::TYPE_DOUBLE:
		ret = (new(ctx) VariantValue(fetcher->fetchDouble(ctx), ctx));
		break ;
	case VariantValue::TYPE_BIG_DECIMAL:
		ret = (new(ctx) VariantValue(ctx));
		ret->setBigDecimal((new(ctx) BigDecimal(fetcher->fetchString(ctx), ctx)), ctx);
		break ;
	case VariantValue::TYPE_TIME:
		ret = (new(ctx) VariantValue((new(ctx) TimeOnlyTimestamp(fetcher->fetchLong(ctx), ctx)), ctx));
		break ;
	case VariantValue::TYPE_TIMESTAMP:
		ret = (new(ctx) VariantValue((new(ctx) Timestamp(fetcher->fetchLong(ctx), ctx)), ctx));
		break ;
	case VariantValue::TYPE_NULL:
		break ;
	default:
		throw (new(ctx) VariableException(ctx));
		break;
	}
	return ret;
}
int VariantValue::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}

