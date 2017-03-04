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
#include "alinous.system/AlinousException.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.runtime.dom/DomArray.h"
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
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db/AlinousDbException.h"
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
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.btree/IBTreeValue.h"
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
#include "alinous.btreememory/AbstractMemoryNode.h"
#include "alinous.btreememory/MBTreeLeafNode.h"
#include "alinous.btreememory/MemoryBTreeMachine.h"
#include "alinous.btreememory/BTreeOnMemory.h"
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
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndexScanner.h"
#include "alinous.db.trx.cache/TrxRecordCacheFullScanner.h"
#include "alinous.db.trx.cache/TrxRecordsCacheFactory.h"

namespace alinous {namespace db {namespace trx {namespace cache {





constexpr const long long TrxRecordsCache::BLOCK_SIZE;
bool TrxRecordsCache::__init_done = __init_static_variables();
bool TrxRecordsCache::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxRecordsCache", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxRecordsCache::~TrxRecordsCache() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxRecordsCache::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxRecordsCache", L"~TrxRecordsCache");
	__e_obj1.add(this->tmpDir, this);
	tmpDir = nullptr;
	__e_obj1.add(this->schema, this);
	schema = nullptr;
	__e_obj1.add(this->tableName, this);
	tableName = nullptr;
	__e_obj1.add(this->storagePath, this);
	storagePath = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	__e_obj1.add(this->indexList, this);
	indexList = nullptr;
	if(!prepare){
		return;
	}
}
TrxRecordsCache* TrxRecordsCache::init(String* tmpDir, String* schema, String* tableName, TableMetadata* metadata, DbTransaction* trx, bool insert, ThreadContext* ctx)
{
	this->insert = insert;
	__GC_MV(this, &(this->tmpDir), tmpDir, String);
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->tableName), tableName, String);
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	this->serial = 1;
	__GC_MV(this, &(this->storage), (new(ctx) BTreeOnMemory(4, ctx)), IBTree);
	ArrayList<TableIndexMetadata>* indexMetadatas = this->metadata->getIndexes(ctx);
	int maxLoop = indexMetadatas->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndexMetadata* imeta = indexMetadatas->get(i, ctx);
		String* indexName = imeta->getName(ctx);
		ArrayList<String>* idxCols = imeta->getColumns(ctx);
		{
			try
			{
				createIndex(indexName, idxCols, this->metadata, trx->getDatabase(ctx), ctx);
			}
			catch(VariableException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1722(), ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1722(), ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1722(), ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1722(), ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1722(), ctx));
			}
		}
	}
	return this;
}
void TrxRecordsCache::switchToDisk(AlinousDatabase* database, ThreadContext* ctx)
{
	setStorageFilePath(ctx);
	File* file = (new(ctx) File(this->storagePath, ctx));
	{
		try
		{
			if(file->exists(ctx))
			{
				file->_delete(ctx);
			}
			__GC_MV(this, &(this->storage), (new(ctx) BTree(ctx))->init(file, database->getBtreeCache(ctx), database->getCore(ctx)->diskCache, ctx), IBTree);
			long long capacity = 1024;
			int valueType = 8;
			int keyType = IBTreeKey::TYPE_LONG;
			int nodeCapacity = 8;
			this->storage->initTreeStorage(nodeCapacity, keyType, valueType, capacity, BLOCK_SIZE, ctx);
			this->storage->open(ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1723(), ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1723(), ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1723(), ctx));
		}
	}
}
void TrxRecordsCache::dispose(ThreadContext* ctx)
{
	int maxLoop = this->indexList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TrxRecordCacheIndex* cacheIndex = this->indexList->get(i, ctx);
		cacheIndex->dispose(ctx);
	}
	this->indexList->clear(ctx);
	{
		try
		{
			this->storage->close(ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1724(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1725(), e, ctx));
		}
	}
}
TrxRecordCacheIndex* TrxRecordsCache::getCachedIndex(ArrayList<ScanTableColumnIdentifier>* colIdList, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexList->size(ctx);
	TrxRecordCacheIndex* retIndex = nullptr;
	for(int i = 0; i != maxLoop; ++i)
	{
		TrxRecordCacheIndex* cachedindex = this->indexList->get(i, ctx);
		bool match = matchIndexByIdList(cachedindex->getColumns(ctx), colIdList, ctx);
		if(colIdList->size(ctx) == cachedindex->getColumns(ctx)->size(ctx) && match)
		{
			return cachedindex;
		}
				else 
		{
			if(match)
			{
				retIndex = cachedindex;
			}
		}
	}
	return retIndex;
}
void TrxRecordsCache::commitUpdateRecord(AlinousDatabase* db, IDatabaseTable* table, long long newCommitId, ThreadContext* ctx)
{
	table->lockStorage(ctx);
	int slotSize = table->getIndexes(ctx)->size(ctx) + 2;
	IArrayObject<SequentialBackgroundJob>* jobs = ArrayAllocator<SequentialBackgroundJob>::allocate(ctx, slotSize);
	for(int i = 0; i != slotSize; ++i)
	{
		jobs->set((new(ctx) SequentialBackgroundJob(ctx))->init(this->trx->getThreadPool(ctx), ctx),i, ctx);
	}
	BTreeScanner* scanner = nullptr;
	{
		try
		{
			scanner = (new(ctx) BTreeScanner(this->storage, ctx));
			scanner->startScan(false, ctx);
			while(scanner->hasNext(ctx))
			{
				IBTreeNode* lnode = scanner->next(ctx);
				ArrayList<IBTreeValue>* values = lnode->getValues(ctx);
				CachedRecord* record = static_cast<CachedRecord*>(values->get(0, ctx));
				table->updateData(record, newCommitId, jobs, this->trx->getLogger(ctx), ctx);
			}
		}
		catch(Throwable* e)
		{
			for(int i = 0; i != slotSize; ++i)
			{
				jobs->get(i)->joinAndEnd(ctx);
			}
			if(scanner != nullptr)
			{
				scanner->endScan(ctx);
			}
			table->unlockStorage(ctx);
			throw e;
		}
	}
	for(int i = 0; i != slotSize; ++i)
	{
		jobs->get(i)->joinAndEnd(ctx);
	}
	if(scanner != nullptr)
	{
		scanner->endScan(ctx);
	}
	table->unlockStorage(ctx);
}
void TrxRecordsCache::commitInsertRecord(DbTransaction* trx, AlinousDatabase* db, IDatabaseTable* table, long long newCommitId, ThreadContext* ctx)
{
	table->lockStorage(ctx);
	{
		try
		{
			checkInsertUnique(trx, table, ctx);
			int slotSize = table->getIndexes(ctx)->size(ctx) + 2;
			IArrayObject<SequentialBackgroundJob>* jobs = ArrayAllocator<SequentialBackgroundJob>::allocate(ctx, slotSize);
			for(int i = 0; i != slotSize; ++i)
			{
				jobs->set((new(ctx) SequentialBackgroundJob(ctx))->init(this->trx->getThreadPool(ctx), ctx),i, ctx);
			}
			IOidPublisher* oidPublisher = db->getOidPublisher(ctx);
			BTreeScanner* scanner = (new(ctx) BTreeScanner(this->storage, ctx));
			scanner->startScan(false, ctx);
			while(scanner->hasNext(ctx))
			{
				IBTreeNode* lnode = scanner->next(ctx);
				ArrayList<IBTreeValue>* values = lnode->getValues(ctx);
				CachedRecord* record = static_cast<CachedRecord*>(values->get(0, ctx));
				long long oid = oidPublisher->newOid(table->getFullName(ctx), ctx);
				record->setOid(oid, ctx);
				table->insertData(this->trx, record, newCommitId, jobs, this->trx->getLogger(ctx), ctx);
			}
			scanner->endScan(ctx);
			for(int i = 0; i != slotSize; ++i)
			{
				jobs->get(i)->joinAndEnd(ctx);
			}
		}
		catch(Throwable* e)
		{
			table->unlockStorage(ctx);
			throw e;
		}
	}
	table->unlockStorage(ctx);
}
CachedRecord* TrxRecordsCache::getRecordByOid(long long oid, ThreadContext* ctx)
{
	LongKey* key = (new(ctx) LongKey(oid, ctx));
	IBTreeNode* node = nullptr;
	{
		try
		{
			node = this->storage->findByKey(key, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1730(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1731(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1732(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1733(), e, ctx));
		}
	}
	if(node == nullptr)
	{
		return nullptr;
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	if(values->size(ctx) == 0)
	{
		return nullptr;
	}
	return static_cast<CachedRecord*>(values->get(0, ctx));
}
void TrxRecordsCache::insertUpdateRecord(ScanResultRecord* srecord, ThreadContext* ctx)
{
	int maxLoop = srecord->numColumns(ctx);
	int maxIndexes = this->indexList->size(ctx);
	CachedRecord* record = (new(ctx) CachedRecord(this->serial++, maxLoop, ctx));
	for(int i = 0; i != maxLoop; ++i)
	{
		record->set(i, srecord->get(i, ctx), ctx);
	}
	record->setInsertedCommitId(srecord->getInsertedCommitId(ctx), ctx);
	record->setLastUpdateCommitId(srecord->getLastUpdateCommitId(ctx), ctx);
	record->setDeletedCommitId(srecord->getDeletedCommitId(ctx), ctx);
	LongKey* key = (new(ctx) LongKey(srecord->getOid(ctx), ctx));
	{
		try
		{
			this->storage->putKeyValue(key, record, ctx);
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1734(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1735(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1736(), e, ctx));
		}
	}
	for(int i = 0; i != maxIndexes; ++i)
	{
		TrxRecordCacheIndex* cacheIndex = this->indexList->get(i, ctx);
		{
			try
			{
				cacheIndex->addIndexValue(record, record->getOid(ctx), ctx);
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1737(), e, ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1738(), e, ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1739(), e, ctx));
			}
		}
	}
}
void TrxRecordsCache::insertRecord(ArrayList<IDomVariable>* values, ArrayList<CulumnOrder>* columns, ThreadContext* ctx)
{
	int maxLoop = columns->size(ctx);
	int maxIndexes = this->indexList->size(ctx);
	int maxRecords = values->size(ctx);
	for(int index = 0; index != maxRecords; ++index)
	{
		IDomVariable* domValue = values->get(index, ctx);
		CachedRecord* record = (new(ctx) CachedRecord((this->serial++) * -1, maxLoop, ctx));
		for(int i = 0; i != maxLoop; ++i)
		{
			CulumnOrder* ord = columns->get(i, ctx);
			int columnOrder = this->metadata->getColumnOrder(ord->getColumnName(ctx), ctx);
			ord->setColumnOrder(columnOrder, ctx);
			if(domValue->getVariableClass(ctx) == IDomVariable::TYPE_ARRAY)
			{
				IDomVariable* dom = static_cast<IDomVariable*>((static_cast<DomArray*>(domValue))->get(i, ctx));
				record->setValue(columnOrder, dom->toVariantValue(ctx), ctx);
			}
						else 
			{
				throw (new(ctx) AlinousNotSupportedException(ctx));
			}
		}
		LongKey* key = (new(ctx) LongKey(record->getOid(ctx), ctx));
		{
			try
			{
				this->storage->putKeyValue(key, record, ctx);
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1734(), e, ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1735(), e, ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1736(), e, ctx));
			}
		}
		for(int i = 0; i != maxIndexes; ++i)
		{
			TrxRecordCacheIndex* cacheIndex = this->indexList->get(i, ctx);
			{
				try
				{
					cacheIndex->addIndexValue(record, record->getOid(ctx), ctx);
				}
				catch(InterruptedException* e)
				{
					throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1737(), e, ctx));
				}
				catch(IOException* e)
				{
					throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1738(), e, ctx));
				}
				catch(BTreeException* e)
				{
					throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1739(), e, ctx));
				}
			}
		}
	}
}
void TrxRecordsCache::createIndex(String* indexName, ArrayList<String>* columns, TableMetadata* tblMetadata, AlinousDatabase* database, ThreadContext* ctx)
{
	TableIndexMetadata* metadata = (new(ctx) TableIndexMetadata(indexName, columns, ctx));
	metadata->setupColumnMetadata(tblMetadata, ctx);
	TrxRecordCacheIndex* newIndex = (new(ctx) TrxRecordCacheIndex(indexName, this->tmpDir, metadata->getMetadata(ctx), ctx));
	newIndex->createIndex(ctx);
	this->indexList->add(newIndex, ctx);
	newIndex->open(database, ctx);
	buildFirstIndex(newIndex, ctx);
}
DbTransaction* TrxRecordsCache::getTrx(ThreadContext* ctx) throw() 
{
	return trx;
}
IBTreeNode* TrxRecordsCache::findByKey(LongKey* oidKey, ThreadContext* ctx)
{
	return this->storage->findByKey(oidKey, ctx);
}
void TrxRecordsCache::setStorageFilePath(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	String* postfix = ConstStr::getCNST_STR_1726();
	if(!this->insert)
	{
		postfix = ConstStr::getCNST_STR_1727();
	}
	buff->append(this->tmpDir, ctx)->append(this->schema, ctx)->append(ConstStr::getCNST_STR_1728(), ctx)->append(this->tableName, ctx)->append(postfix, ctx)->append(ConstStr::getCNST_STR_1729(), ctx);
	__GC_MV(this, &(this->storagePath), buff->toString(ctx), String);
}
bool TrxRecordsCache::matchIndexByIdList(ArrayList<TableColumnMetadata>* cachedIndexCols, ArrayList<ScanTableColumnIdentifier>* colIdList, ThreadContext* ctx) throw() 
{
	int maxLoop = colIdList->size(ctx);
	if(maxLoop > cachedIndexCols->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* indexColMeta = cachedIndexCols->get(i, ctx);
		ScanTableColumnIdentifier* colId = colIdList->get(i, ctx);
		if(!indexColMeta->name->equals(colId->getColumn(ctx), ctx))
		{
			return false;
		}
	}
	return true;
}
void TrxRecordsCache::checkInsertUnique(DbTransaction* trx, IDatabaseTable* table, ThreadContext* ctx)
{
	UniqueExclusiveLockClient* uniqueLock = trx->getUniqueExclusiveLock(ctx);
	TableMetadata* meta = table->getMetadata(ctx);
	TableMetadataUniqueCollection* uniques = meta->getUniques(ctx);
	BTreeScanner* scanner = (new(ctx) BTreeScanner(this->storage, ctx));
	scanner->startScan(false, ctx);
	while(scanner->hasNext(ctx))
	{
		IBTreeNode* lnode = scanner->next(ctx);
		ArrayList<IBTreeValue>* values = lnode->getValues(ctx);
		CachedRecord* record = static_cast<CachedRecord*>(values->get(0, ctx));
		ckeckUniques(uniqueLock, uniques, record, ctx);
	}
}
void TrxRecordsCache::ckeckUniques(UniqueExclusiveLockClient* uniqueLock, TableMetadataUniqueCollection* uniques, CachedRecord* record, ThreadContext* ctx)
{
	ArrayList<ScanUnique>* list = uniques->getUniqueList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanUnique* unique = list->get(i, ctx);
		uniqueLock->lockWithCheck(unique, record, true, ctx);
	}
}
void TrxRecordsCache::buildFirstIndex(TrxRecordCacheIndex* newIndex, ThreadContext* ctx)
{
	BTreeScanner* scanner = (new(ctx) BTreeScanner(this->storage, ctx));
	scanner->startScan(false, ctx);
	while(scanner->hasNext(ctx))
	{
		IBTreeNode* node = scanner->next(ctx);
		CachedRecord* record = getLastCommitedRecord(node, ctx);
		newIndex->addIndexValue(record, record->getOid(ctx), ctx);
	}
}
CachedRecord* TrxRecordsCache::getLastCommitedRecord(IBTreeNode* node, ThreadContext* ctx) throw() 
{
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	int idx = values->size(ctx) - 1;
	return static_cast<CachedRecord*>(values->get(idx, ctx));
}
}}}}

