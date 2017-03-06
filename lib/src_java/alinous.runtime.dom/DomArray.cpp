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
#include "alinous.system/AlinousNotSupportedException.h"
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
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
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





String* DomArray::VAL_TYPE = ConstStr::getCNST_STR_1113();
bool DomArray::__init_done = __init_static_variables();
bool DomArray::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomArray", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomArray::DomArray(ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), array(nullptr), num(0), cap(0)
{
	this->num = 0;
	this->cap = 32;
	GCUtils<ArrayList<IDomVariable> >::mv(this, &(this->array), (new(ctx) ArrayList<IDomVariable>(cap, ctx)), ctx);
}
void DomArray::__construct_impl(ThreadContext* ctx) throw() 
{
	this->num = 0;
	this->cap = 32;
	GCUtils<ArrayList<IDomVariable> >::mv(this, &(this->array), (new(ctx) ArrayList<IDomVariable>(cap, ctx)), ctx);
}
 DomArray::~DomArray() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomArray::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomArray", L"~DomArray");
	__e_obj1.add(this->array, this);
	array = nullptr;
	if(!prepare){
		return;
	}
}
void DomArray::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	int maxLoop = this->array->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomVariable* dm = this->array->get(i, ctx);
		dm->outDebugXml(node, nullptr, ctx);
	}
}
int DomArray::getIntValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
String* DomArray::getStringValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
int DomArray::size(ThreadContext* ctx) throw() 
{
	return this->num;
}
void DomArray::put(IDomVariable* val, ThreadContext* ctx) throw() 
{
	array->add(val, ctx);
}
void DomArray::set(IDomVariable* val, int index, ThreadContext* ctx) throw() 
{
	if(array->size(ctx) >= index)
	{
		int maxLoop = index + 1;
		for(int i = this->array->size(ctx); i != maxLoop; ++i)
		{
			this->array->add((new(ctx) DomVariable(ctx)), ctx);
		}
	}
	if(array->size(ctx) < index)
	{
		for(int i = array->size(ctx); i <= index; ++i)
		{
			this->array->add((new(ctx) DomVariable(ctx)), ctx);
		}
	}
	this->array->set(index, val, ctx);
}
IDomVariable* DomArray::get(int index, ThreadContext* ctx) throw() 
{
	if(index >= this->array->size(ctx))
	{
		return nullptr;
	}
	return this->array->get(index, ctx);
}
int DomArray::getDomType(ThreadContext* ctx) throw() 
{
	return IDomVariable::TYPE_ARRAY;
}
IDomVariable* DomArray::toDom(ThreadContext* ctx) throw() 
{
	return this;
}
int DomArray::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_DOM;
}
IAlinousVariable* DomArray::copy(ThreadContext* ctx)
{
	DomArray* array = (new(ctx) DomArray(ctx));
	int maxLoop = this->array->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomVariable* dm = this->array->get(i, ctx);
		array->put(static_cast<IDomVariable*>(dm->copy(ctx)), ctx);
	}
	return nullptr;
}
IDomVariable* DomArray::toDomVariable(ThreadContext* ctx) throw() 
{
	return this;
}
IAlinousVariable* DomArray::add(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitReverse(ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
bool DomArray::isNull(ThreadContext* ctx) throw() 
{
	return this->array->isEmpty(ctx);
}
bool DomArray::isArray(ThreadContext* ctx) throw() 
{
	return true;
}
IAlinousVariable* DomArray::shiftLeft(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
bool DomArray::isTrue(ThreadContext* ctx)
{
	return !this->array->isEmpty(ctx);
}
IAlinousVariable* DomArray::bitOr(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IDomVariable* DomArray::getByDescriptor(DomVariableDescriptor* desc, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
void DomArray::setProperty(String* key, IDomVariable* value, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IDomVariableContainer* DomArray::getProperty(String* key, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
VariantValue* DomArray::toVariantValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
int DomArray::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
BoolVariable* DomArray::toBoolVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
ByteVariable* DomArray::toByteVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
CharVariable* DomArray::toCharVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
ShortVariable* DomArray::toShortVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IntegerVariable* DomArray::toIntVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
LongVariable* DomArray::toLongVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
StringVariable* DomArray::toStringVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
long long DomArray::getLongValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
BigDecimalVariable* DomArray::toBigDecimalVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
FloatVariable* DomArray::toFloatVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
DoubleVariable* DomArray::toDoubleVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
TimeVariable* DomArray::toTimeVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
TimestampVariable* DomArray::toTimestampVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::add(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::add(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::minus(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::div(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::div(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
int DomArray::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
int DomArray::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	DomArray* arrayDom = static_cast<DomArray*>(variable->toDomVariable(ctx));
	GCUtils<ArrayList<IDomVariable> >::mv(this, &(this->array), arrayDom->array, ctx);
	return this;
}
void DomArray::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->cap = buff->getInt(ctx);
	this->num = buff->getInt(ctx);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousVariable* val = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
		if(val->getVariableClass(ctx) != IAlinousVariable::CLASS_DOM)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1112(), ctx));
		}
		this->array->add(static_cast<IDomVariable*>(val), ctx);
	}
}
void DomArray::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__DomArray, ctx);
	buff->putInt(this->cap, ctx);
	buff->putInt(this->num, ctx);
	int maxLoop = this->array->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomVariable* dom = this->array->get(i, ctx);
		dom->writeData(buff, ctx);
	}
}
DomArray* DomArray::importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(DomVariable::VAL_TYPE, ctx))
	{
		return nullptr;
	}
	DomArray* array = (new(ctx) DomArray(ctx));
	int maxLoop = node->getNumChildern(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DomNode* n = node->getChildNodeAt(i, ctx);
		IDomVariable* val = DomVariableDebugXmlFactory::getDom(n, ctx);
		array->put(val, ctx);
	}
	return array;
}
int DomArray::ValueCompare::operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}

