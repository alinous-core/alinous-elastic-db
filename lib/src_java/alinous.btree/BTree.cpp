#include "include/global.h"


#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.lock/LockObject.h"
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
#include "alinous.btree/BTreeException.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.buffer/FifoList.h"
#include "java.util/BitSet.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileAccessWrapper.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree/AbstractBTreeLeafContainer.h"
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
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.btree/IBTree.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.btree/BTreeMachine.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.btree/LongValue.h"
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
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.btree/IntValue.h"
#include "alinous.btree/StringValue.h"
#include "alinous.btree/TimestampValue.h"
#include "alinous.btree/DoubleValue.h"
#include "alinous.btree/StringKey.h"
#include "alinous.btree/DoubleKey.h"
#include "alinous.btree/TimestampKey.h"
#include "alinous.btree/KeyValueFactory.h"
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
#include "alinous.btree/BTreeLeafContainer.h"

namespace alinous {namespace btree {





bool BTree::__init_done = __init_static_variables();
bool BTree::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTree", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTree::~BTree() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTree::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTree", L"~BTree");
	__e_obj1.add(this->gate, this);
	gate = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->loader, this);
	loader = nullptr;
	__e_obj1.add(this->fetcher, this);
	fetcher = nullptr;
	if(!prepare){
		return;
	}
}
BTree* BTree::init(File* file, BTreeGlobalCache* cacheEngine, DiskCacheManager* diskCache, ThreadContext* ctx)
{
	__GC_MV(this, &(this->storage), (new(ctx) FileStorage(diskCache, file, ConstStr::getCNST_STR_1666(), ctx)), FileStorage);
	__GC_MV(this, &(this->loader), (new(ctx) BTreeNodeLoader(this->storage, cacheEngine, ctx)), BTreeNodeLoader);
	this->root = 0;
	__GC_MV(this, &(this->fetcher), (new(ctx) FileStorageEntryFetcher(ctx)), FileStorageEntryFetcher);
	return this;
}
ArrayList<IBTreeValue>* BTree::getValues(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		return nullptr;
	}
	IBTreeNode* node = findByKey(key, ctx);
	if(node == nullptr)
	{
		return nullptr;
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	node->endUse(ctx);
	return values;
}
bool BTree::putUniqueKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		putRooNode(ctx);
	}
	IBTreeNode* node = findByKey(key, ctx);
	if(node != nullptr)
	{
		return false;
	}
	node = internalPutKey(key, ctx);
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	if(values->contains(value, ctx))
	{
		values->remove(value, ctx);
	}
	values->add(value, ctx);
	this->loader->saveBTreeNode(node, ctx);
	node->endUse(ctx);
	return true;
}
void BTree::appendKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		putRooNode(ctx);
	}
	IBTreeNode* node = findByKey(key, ctx);
	if(node == nullptr)
	{
		node = internalPutKey(key, ctx);
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	values->add(value, ctx);
	this->loader->saveBTreeNode(node, ctx);
	node->endUse(ctx);
}
void BTree::putKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		putRooNode(ctx);
	}
	IBTreeNode* node = findByKey(key, ctx);
	if(node == nullptr)
	{
		node = internalPutKey(key, ctx);
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	if(values->contains(value, ctx))
	{
		values->remove(value, ctx);
	}
	values->add(value, ctx);
	this->loader->saveBTreeNode(node, ctx);
	node->endUse(ctx);
}
IBTreeNode* BTree::findByKey(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		return nullptr;
	}
	IBTreeNode* node = this->getRootNode(ctx);
	IBTreeNode* lastNode = nullptr;
	while(!node->isHasLeaf(ctx))
	{
		lastNode = node;
		node = node->getNodeAtInsertPosition(key, ctx);
		node->use(ctx);
		lastNode->endUse(ctx);
	}
	lastNode = node;
	IBTreeNode* leaf = node->getNodeAtInsertPosition(key, ctx);
	lastNode->endUse(ctx);
	if(leaf == nullptr)
	{
		return nullptr;
	}
	leaf->use(ctx);
	if(leaf->getKey(ctx)->equals(key, ctx))
	{
		return leaf;
	}
	leaf->endUse(ctx);
	return nullptr;
}
void BTree::putKey(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		putRooNode(ctx);
	}
	BTreeLeafNode* newNode = this->loader->newLeafNode(key, ctx);
	IBTreeNode* rootObj = getRootNode(ctx);
	BTreeMachine* machine = (new(ctx) BTreeMachine(rootObj, this, ctx));
	machine->insertLeaf(newNode, ctx);
	newNode->endUse(ctx);
	rootObj->endUse(ctx);
	machine->destroy(ctx);
}
void BTree::removeKey(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		return;
	}
	IBTreeNode* rootObj = nullptr;
	{
		try
		{
			rootObj = getRootNode(ctx);
			BTreeMachine* machine = (new(ctx) BTreeMachine(rootObj, this, ctx));
			machine->removeKey(key, ctx);
		}
		catch(Throwable* e)
		{
			if(rootObj != nullptr)
			{
				rootObj->endUse(ctx);
			}
			throw e;
		}
	}
	if(rootObj != nullptr)
	{
		rootObj->endUse(ctx);
	}
}
void BTree::saveNode(IBTreeNode* node, ThreadContext* ctx)
{
	this->loader->saveBTreeNode(node, ctx);
}
IBTreeNode* BTree::getRootNode(ThreadContext* ctx)
{
	IBTreeNode* node = this->loader->loadBTreeNode(this->root, ctx);
	return node;
}
void BTree::initTreeStorage(int nodeCapacity, int keyType, int valueType, long long capacity, long long BLOCK_SIZE, ThreadContext* ctx)
{
	if(capacity < (long long)256)
	{
		capacity = 256;
	}
	this->nodeCapacity = nodeCapacity;
	this->keyType = keyType;
	this->valueType = valueType;
	this->storage->createStorage(capacity, BLOCK_SIZE, ctx);
	{
		try
		{
			this->storage->open(ctx);
			updateMasterSection(ctx);
		}
		catch(Throwable* e)
		{
			this->storage->close(ctx);
			throw e;
		}
	}
	this->storage->close(ctx);
}
void BTree::open(ThreadContext* ctx)
{
	if(!this->storage->isCreated(ctx))
	{
		throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1667(), ctx));
	}
	this->storage->open(ctx);
	this->loader->open(ctx);
	loadStorageinfo(ctx);
	__GC_MV(this, &(this->gate), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
}
void BTree::printNode(StringBuffer* buff, ThreadContext* ctx)
{
	IBTreeNode* rootNode = getRootNode(ctx);
	rootNode->printNode(buff, 0, ctx);
	rootNode->endUse(ctx);
}
bool BTree::isOpened(ThreadContext* ctx) throw() 
{
	return this->storage->isOpened(ctx);
}
void BTree::close(ThreadContext* ctx)
{
	{
		try
		{
			updateMasterSection(ctx);
			this->loader->close(ctx);
			this->storage->close(ctx);
		}
		catch(Throwable* e)
		{
			this->gate->close(ctx);
			throw e;
		}
	}
	this->gate->close(ctx);
}
void BTree::assertCache(ThreadContext* ctx)
{
	this->loader->assertCache(ctx);
}
void BTree::updateMasterSection(ThreadContext* ctx)
{
	FileStorageEntryBuilder* builder = (new(ctx) FileStorageEntryBuilder(ctx));
	builder->putInt(this->nodeCapacity, ctx);
	builder->putLong(this->root, ctx);
	builder->putInt(this->keyType, ctx);
	builder->putInt(this->valueType, ctx);
	FileStorageEntryWriter* writer = this->storage->getWriter(ctx);
	FileStorageEntry* entry = builder->toEntry((long long)FileStorage::DATA_BEGIN, ctx);
	writer->write(entry, ctx);
}
bool BTree::isEmpty(ThreadContext* ctx) throw() 
{
	return this->root == (long long)0;
}
long long BTree::getRoot(ThreadContext* ctx) throw() 
{
	return root;
}
void BTree::setRoot(long long root, ThreadContext* ctx) throw() 
{
	this->root = root;
}
BTreeNodeLoader* BTree::getLoader(ThreadContext* ctx) throw() 
{
	return loader;
}
int BTree::getNodeCapacity(ThreadContext* ctx) throw() 
{
	return nodeCapacity;
}
BTreeLeafNode* BTree::internalPutKey(IBTreeKey* key, ThreadContext* ctx)
{
	BTreeLeafNode* newNode = this->loader->newLeafNode(key, ctx);
	IBTreeNode* rootObj = getRootNode(ctx);
	BTreeMachine* machine = (new(ctx) BTreeMachine(rootObj, this, ctx));
	machine->insertLeaf(newNode, ctx);
	rootObj->endUse(ctx);
	machine->destroy(ctx);
	return newNode;
}
void BTree::putRooNode(ThreadContext* ctx)
{
	IBTreeNode* node = this->loader->newBTreeMaxLeafContainer(this->nodeCapacity, ctx);
	this->root = node->getFilePointer(ctx);
	node->endUse(ctx);
}
void BTree::loadStorageinfo(ThreadContext* ctx)
{
	FileStorageEntryReader* reader = this->storage->getReader(ctx);
	FileStorageEntry* entry = reader->read((long long)FileStorage::DATA_BEGIN, ctx);
	this->fetcher->load(entry, ctx);
	this->nodeCapacity = this->fetcher->fetchInt(ctx);
	this->root = this->fetcher->fetchLong(ctx);
	this->keyType = this->fetcher->fetchInt(ctx);
	this->valueType = this->fetcher->fetchInt(ctx);
	this->fetcher->close(ctx);
}
}}

