#include "include/global.h"


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
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.analyse/SourceValidationError.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
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
#include "alinous.system/AlinousException.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.lock/LockObject.h"
#include "java.util/Random.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigInteger.h"
#include "alinous.numeric/RoundingMode.h"
#include "alinous.numeric/MathContext.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom/DomArray.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom/IVariableClassOperationCaller.h"
#include "alinous.runtime.dom/VariableOperationCaller.h"
#include "alinous.runtime.variant/IVariantData.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
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
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.dom/DocumentVariable.h"
#include "alinous.runtime.dom/NetworkAlinousVariableFactory.h"
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
#include "alinous.runtime.dom/DomVariableDebugXmlFactory.h"

namespace alinous {namespace runtime {namespace dom {





String* DomVariable::VAL_TYPE = ConstStr::getCNST_STR_1120();
String* DomVariable::PROPS = ConstStr::getCNST_STR_1121();
bool DomVariable::__init_done = __init_static_variables();
bool DomVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomVariable::DomVariable(ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(ctx)), VariantValue);
}
void DomVariable::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(ctx)), VariantValue);
}
 DomVariable::DomVariable(VariantValue* value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), value, VariantValue);
}
void DomVariable::__construct_impl(VariantValue* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, VariantValue);
}
 DomVariable::DomVariable(String* value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(String* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::DomVariable(char value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(char value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::DomVariable(short value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(short value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::DomVariable(wchar_t value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(wchar_t value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::DomVariable(int value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(int value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::DomVariable(long long value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(long long value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::DomVariable(Timestamp* value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(Timestamp* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::DomVariable(TimeOnlyTimestamp* value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(TimeOnlyTimestamp* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::DomVariable(BigDecimal* value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(BigDecimal* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::DomVariable(float value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(float value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::DomVariable(double value, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), IDatabaseRecord(ctx), properties(GCUtils<ArrayList<IDomVariable> >::ins(this, (new(ctx) ArrayList<IDomVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), meta(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
void DomVariable::__construct_impl(double value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) VariantValue(value, ctx)), VariantValue);
}
 DomVariable::~DomVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomVariable", L"~DomVariable");
	__e_obj1.add(this->properties, this);
	properties = nullptr;
	__e_obj1.add(this->meta, this);
	meta = nullptr;
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
}
void DomVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* attr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(attr, ctx);
	}
	if(this->value != nullptr)
	{
		this->value->outDebugXml(node, nullptr, ctx);
	}
	DomNode* props = (new(ctx) DomNode(PROPS, ctx));
	node->addChild(props, ctx);
	int maxLoop = this->properties->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomVariable* value = this->properties->get(i, ctx);
		String* key = this->meta->get(i, ctx);
		value->outDebugXml(props, key, ctx);
	}
}
int DomVariable::getColumnCount(ThreadContext* ctx) throw() 
{
	return this->properties->size(ctx);
}
int DomVariable::getValueType(ThreadContext* ctx) throw() 
{
	return this->value->getVtype(ctx);
}
int DomVariable::getIntValue(ThreadContext* ctx)
{
	return value->getInt(ctx);
}
String* DomVariable::getStringValue(ThreadContext* ctx)
{
	return value->getString(ctx);
}
IDomVariable* DomVariable::get(String* name, ThreadContext* ctx) throw() 
{
	int index = this->meta->indexOf(name, ctx);
	return this->properties->get(index, ctx);
}
VariantValue* DomVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void DomVariable::setValue(VariantValue* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, VariantValue);
}
String* DomVariable::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value->toString(ctx), ctx);
	buff->append(ConstStr::getCNST_STR_1116(), ctx);
	int cnt = 0;
	Iterator<IDomVariable>* it = this->properties->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IDomVariable* value = it->next(ctx);
		if(cnt != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		cnt ++ ;
		buff->append(value->toString(ctx), ctx);
	}
	buff->append(ConstStr::getCNST_STR_1117(), ctx);
	return buff->toString(ctx);
}
IDomVariable* DomVariable::get(int index, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void DomVariable::setProperty(String* key, IDomVariable* value, ThreadContext* ctx) throw() 
{
	int index = this->meta->indexOf(key, ctx);
	if(index >= 0)
	{
		this->properties->set(index, value, ctx);
	}
		else 
	{
		this->meta->add(key, ctx);
		this->properties->add(value, ctx);
	}
}
IDomVariable* DomVariable::getProperty(String* key, ThreadContext* ctx) throw() 
{
	return get(key, ctx);
}
Iterator<String>* DomVariable::getPropertiesIterator(ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->meta->iterator(ctx);
	return it;
}
void DomVariable::set(IDomVariable* val, int index, ThreadContext* ctx) throw() 
{
}
int DomVariable::getDomType(ThreadContext* ctx) throw() 
{
	return IDomVariable::TYPE_DOM;
}
IDomVariable* DomVariable::toDom(ThreadContext* ctx) throw() 
{
	return this;
}
int DomVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_DOM;
}
IAlinousVariable* DomVariable::copy(ThreadContext* ctx)
{
	DomVariable* dom = (new(ctx) DomVariable(ctx));
	dom->setValue(this->value, ctx);
	int maxLoop = this->properties->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = this->meta->get(i, ctx);
		IDomVariable* value = this->properties->get(i, ctx);
		dom->setProperty(key, static_cast<IDomVariable*>(value->copy(ctx)), ctx);
	}
	return dom;
}
IDomVariable* DomVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	return this;
}
IAlinousVariable* DomVariable::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DomVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DomVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DomVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DomVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DomVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DomVariable::bitReverse(ThreadContext* ctx)
{
	return this->value->bitReverse(ctx);
}
IAlinousVariable* DomVariable::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DomVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
bool DomVariable::isNull(ThreadContext* ctx) throw() 
{
	return this->value->isNull(ctx);
}
bool DomVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
IAlinousVariable* DomVariable::shiftLeft(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
int DomVariable::compareTo(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
bool DomVariable::isTrue(ThreadContext* ctx)
{
	return this->value->isTrue(ctx);
}
IAlinousVariable* DomVariable::bitOr(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IDomVariable* DomVariable::getByDescriptor(DomVariableDescriptor* desc, ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* DomVariable::toVariantValue(ThreadContext* ctx)
{
	return this->value;
}
IAlinousVariable* DomVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->add((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->minus((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->div((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
int DomVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo((new(ctx) VariantValue(variable->getIntValue(ctx), ctx)), ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
BoolVariable* DomVariable::toBoolVariable(ThreadContext* ctx)
{
	return this->value->toBoolVariable(ctx);
}
ByteVariable* DomVariable::toByteVariable(ThreadContext* ctx)
{
	return this->value->toByteVariable(ctx);
}
CharVariable* DomVariable::toCharVariable(ThreadContext* ctx)
{
	return this->value->toCharVariable(ctx);
}
ShortVariable* DomVariable::toShortVariable(ThreadContext* ctx)
{
	return this->value->toShortVariable(ctx);
}
IntegerVariable* DomVariable::toIntVariable(ThreadContext* ctx)
{
	return this->value->toIntVariable(ctx);
}
LongVariable* DomVariable::toLongVariable(ThreadContext* ctx)
{
	return this->value->toLongVariable(ctx);
}
StringVariable* DomVariable::toStringVariable(ThreadContext* ctx)
{
	return this->value->toStringVariable(ctx);
}
BigDecimalVariable* DomVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	return this->value->toBigDecimalVariable(ctx);
}
long long DomVariable::getLongValue(ThreadContext* ctx)
{
	return this->value->getLong(ctx);
}
FloatVariable* DomVariable::toFloatVariable(ThreadContext* ctx)
{
	return this->value->toFloatVariable(ctx);
}
DoubleVariable* DomVariable::toDoubleVariable(ThreadContext* ctx)
{
	return this->value->toDoubleVariable(ctx);
}
TimeVariable* DomVariable::toTimeVariable(ThreadContext* ctx)
{
	return this->value->toTimeVariable(ctx);
}
TimestampVariable* DomVariable::toTimestampVariable(ThreadContext* ctx)
{
	return this->value->toTimestampVariable(ctx);
}
IAlinousVariable* DomVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DomVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DomVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DomVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
int DomVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DomVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
IAlinousVariable* DomVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	return this->value->substitute(variable, ctx);
}
VariantValue* DomVariable::getColumnValue(int colOrder, ThreadContext* ctx) throw() 
{
	return nullptr;
}
int DomVariable::getNumValues(ThreadContext* ctx) throw() 
{
	return this->properties->size(ctx);
}
long long DomVariable::getInsertedCommitId(ThreadContext* ctx) throw() 
{
	return -1;
}
long long DomVariable::getLastUpdateCommitId(ThreadContext* ctx) throw() 
{
	return -1;
}
long long DomVariable::getDeletedCommitId(ThreadContext* ctx) throw() 
{
	return -1;
}
ArrayList<VariantValue>* DomVariable::getValues(ThreadContext* ctx) throw() 
{
	ArrayList<VariantValue>* list = (new(ctx) ArrayList<VariantValue>(ctx));
	Iterator<IDomVariable>* it = this->properties->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IDomVariable* val = it->next(ctx);
		{
			try
			{
				list->add(val->toVariantValue(ctx), ctx);
			}
			catch(VariableException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
	return list;
}
void DomVariable::setValue(int index, VariantValue* value, ThreadContext* ctx) throw() 
{
	this->setValue(index, value, ctx);
}
int DomVariable::getKind(ThreadContext* ctx) throw() 
{
	return IDatabaseRecord::DOM_VARIABLE;
}
void DomVariable::addValue(VariantValue* vv, ThreadContext* ctx) throw() 
{
	throw (new(ctx) RuntimeException(ConstStr::getCNST_STR_1118(), ctx));
}
long long DomVariable::getOid(ThreadContext* ctx) throw() 
{
	return -1;
}
void DomVariable::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeValue::TYPE_DOM_VARIABLE_RECORD, ctx);
	this->value->appendToEntry(builder, ctx);
	int maxLoop = this->properties->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = this->meta->get(i, ctx);
		IDomVariable* value = this->properties->get(i, ctx);
		VariantValue* vv = value->toVariantValue(ctx);
		builder->putString(key, ctx);
		vv->appendToEntry(builder, ctx);
	}
}
int DomVariable::diskSize(ThreadContext* ctx)
{
	int total = 4;
	total += this->value->bufferSize(ctx);
	int maxLoop = this->properties->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = this->meta->get(i, ctx);
		IDomVariable* value = this->properties->get(i, ctx);
		VariantValue* vv = value->toVariantValue(ctx);
		total += 4 + key->length(ctx) * 2;
		total += vv->bufferSize(ctx);
	}
	return total;
}
IValueFetcher* DomVariable::getFetcher(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool DomVariable::equals(IObject* other, ThreadContext* ctx) throw() 
{
	return this == other;
}
long long DomVariable::getMaxCommitId(ThreadContext* ctx) throw() 
{
	return 0;
}
void DomVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	char nullbl = buff->getByte(ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	IAlinousVariable* val = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
	if(val == nullptr || !((dynamic_cast<VariantValue*>(val) != 0)))
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1119(), ctx));
	}
	__GC_MV(this, &(this->value), static_cast<VariantValue*>(val), VariantValue);
}
void DomVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__DomVariable, ctx);
	char nullbl = ((char)(isNull(ctx) ? 0 : 1));
	buff->putByte(nullbl, ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	this->value->writeData(buff, ctx);
}
int DomVariable::getNumColumn(ThreadContext* ctx) throw() 
{
	return this->properties->size(ctx);
}
void DomVariable::setLastUpdateCommitId(long long commitId, ThreadContext* ctx) throw() 
{
}
void DomVariable::setInsertedCommitId(long long insertedCommitId, ThreadContext* ctx) throw() 
{
}
DomVariable* DomVariable::importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(DomVariable::VAL_TYPE, ctx))
	{
		return nullptr;
	}
	DomVariable* retValue = (new(ctx) DomVariable(ctx));
	int maxLoop = node->getNumChildern(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DomNode* n = node->getChildNodeAt(i, ctx);
		String* nodeName = n->getName(ctx);
		if(nodeName->equals(PROPS, ctx))
		{
			importProps(n, retValue, ctx);
		}
				else 
		{
			if(nodeName->equals(VariantValue::TAG_NAME, ctx))
			{
				__GC_MV(retValue, &(retValue->value), VariantValue::importFromDebugXml(n, ctx), VariantValue);
			}
		}
	}
	return retValue;
}
DomVariable* DomVariable::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	VariantValue* value = VariantValue::valueFromFetcher(fetcher, ctx);
	DomVariable* dom = (new(ctx) DomVariable(value, ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = fetcher->fetchString(ctx);
		VariantValue* vv = VariantValue::valueFromFetcher(fetcher, ctx);
		DomVariable* prop = (new(ctx) DomVariable(vv, ctx));
		dom->setProperty(key, prop, ctx);
	}
	return dom;
}
void DomVariable::importProps(DomNode* node, DomVariable* parentDom, ThreadContext* ctx) throw() 
{
	int maxLoop = node->getNumChildern(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DomNode* n = node->getChildNodeAt(i, ctx);
		IVariableValue* nameattr = n->getAttributeValue(IAlinousVariable::ATTR_NAME, ctx);
		if(nameattr == nullptr)
		{
			continue;
		}
		String* key = nameattr->toString(ctx);
		IDomVariable* val = DomVariableDebugXmlFactory::getDom(n, ctx);
		parentDom->setProperty(key, val, ctx);
	}
}
int DomVariable::ValueCompare::operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}

