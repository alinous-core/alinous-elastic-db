#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidationError.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
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
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.runtime.variant/IVariantData.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
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
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql/ISqlStatement.h"
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
#include "alinous.system.utils/FileUtils.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.remote.db.command.data/SchemaData.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.remote.db.command.data/SchemasStructureInfoData.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.system.config/AlinousInitException.h"
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
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.runtime/ModuleNotFoundException.h"
#include "alinous.runtime/CompileErrorException.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
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
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
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
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
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
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.compile.analyse/ClassDeclareHolder.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.server.debug/DebugConfigLoader.h"
#include "alinous.runtime/AlinousModule.h"

namespace alinous {namespace runtime {





bool AlinousModule::__init_done = __init_static_variables();
bool AlinousModule::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModule", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModule::AlinousModule(String* path, File* file, AlinousSrc* moduleSource, AlinousCore* core, ThreadContext* ctx) : IObject(ctx), IAlinousElement(ctx), packageName(nullptr), path(nullptr), debugPath(nullptr), file(nullptr), compiledTime(0), moduleSource(nullptr), setupper(nullptr), core(nullptr), parent(nullptr), includedModules(GCUtils<ArrayList<AlinousModule> >::ins(this, (new(ctx) ArrayList<AlinousModule>(ctx)), ctx, __FILEW__, __LINE__, L"")), functionMap(GCUtils<HashMap<String,AlinousFunction> >::ins(this, (new(ctx) HashMap<String,AlinousFunction>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->debugPath), file->getAbsolutePath(ctx), String);
	__GC_MV(this, &(this->debugPath), FileUtils::formatAfterAbsolutePath(this->debugPath, ctx), String);
	DebugConfigLoader* loader = (new(ctx) DebugConfigLoader(core->getConfig(ctx), ctx));
	__GC_MV(this, &(this->debugPath), loader->getDebugFilePath(this->debugPath, ctx), String);
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->file), file, File);
	this->compiledTime = System::currentTimeMillis(ctx);
	__GC_MV(this, &(this->moduleSource), moduleSource, AlinousSrc);
	__GC_MV(this, &(this->setupper), (new(ctx) AlinousModule::SetUpper(this->path, this->debugPath, ctx)), AlinousModule::SetUpper);
	__GC_MV(this, &(this->core), core, AlinousCore);
}
void AlinousModule::__construct_impl(String* path, File* file, AlinousSrc* moduleSource, AlinousCore* core, ThreadContext* ctx)
{
	__GC_MV(this, &(this->debugPath), file->getAbsolutePath(ctx), String);
	__GC_MV(this, &(this->debugPath), FileUtils::formatAfterAbsolutePath(this->debugPath, ctx), String);
	DebugConfigLoader* loader = (new(ctx) DebugConfigLoader(core->getConfig(ctx), ctx));
	__GC_MV(this, &(this->debugPath), loader->getDebugFilePath(this->debugPath, ctx), String);
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->file), file, File);
	this->compiledTime = System::currentTimeMillis(ctx);
	__GC_MV(this, &(this->moduleSource), moduleSource, AlinousSrc);
	__GC_MV(this, &(this->setupper), (new(ctx) AlinousModule::SetUpper(this->path, this->debugPath, ctx)), AlinousModule::SetUpper);
	__GC_MV(this, &(this->core), core, AlinousCore);
}
 AlinousModule::~AlinousModule() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModule::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousModule", L"~AlinousModule");
	__e_obj1.add(this->packageName, this);
	packageName = nullptr;
	__e_obj1.add(this->path, this);
	path = nullptr;
	__e_obj1.add(this->debugPath, this);
	debugPath = nullptr;
	__e_obj1.add(this->file, this);
	file = nullptr;
	__e_obj1.add(this->moduleSource, this);
	moduleSource = nullptr;
	__e_obj1.add(this->setupper, this);
	setupper = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->parent, this);
	parent = nullptr;
	__e_obj1.add(this->includedModules, this);
	includedModules = nullptr;
	__e_obj1.add(this->functionMap, this);
	functionMap = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
IAlinousVariable* AlinousModule::execute(ScriptMachine* machine, bool degug, ThreadContext* ctx)
{
	return executeAsScript(machine, degug, ctx);
}
IAlinousVariable* AlinousModule::execute(bool degug, ThreadContext* ctx)
{
	ScriptMachine* machine = (new(ctx) ScriptMachine(this, this->core, ctx));
	return executeAsScript(machine, degug, ctx);
}
AlinousType* AlinousModule::getFunctionReturnType(String* prefix, String* name, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(prefix != nullptr)
	{
		buff->append(prefix, ctx)->append(ConstStr::getCNST_STR_950(), ctx);
	}
	buff->append(name, ctx);
	AlinousFunction* func = this->functionMap->get(buff->toString(ctx), ctx);
	if(func != nullptr)
	{
		AlinousType* type = func->getAnalysedReturnType(ctx);
		return type;
	}
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		AlinousType* type = mod->getFunctionReturnType(prefix, name, ctx);
		if(type != nullptr)
		{
			return type;
		}
	}
	return nullptr;
}
bool AlinousModule::isfunctionPrefix(String* name, ThreadContext* ctx) throw() 
{
	String* prefix = name->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx);
	Iterator<String>* it = functionMap->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* funcName = it->next(ctx);
		if(funcName->startsWith(prefix, ctx))
		{
			return true;
		}
	}
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		if(mod->isfunctionPrefix(name, ctx))
		{
			return true;
		}
	}
	return false;
}
AlinousFunction* AlinousModule::findFunction(String* name, ThreadContext* ctx) throw() 
{
	AlinousFunction* func = this->functionMap->get(name, ctx);
	if(func != nullptr)
	{
		return func;
	}
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		func = mod->findFunction(name, ctx);
	}
	return nullptr;
}
void AlinousModule::init(AlinousModuleRepository* moduleRepository, ArrayList<String>* once, bool isInclude, bool debug, ThreadContext* ctx)
{
	ArrayList<IncludePreprocessor>* inclist = moduleSource->getIncludes(ctx);
	int maxLoop = inclist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IncludePreprocessor* inc = inclist->get(i, ctx);
		if(inc->getPath(ctx) == nullptr)
		{
			throw (new(ctx) AlinousNullPointerException(ctx));
		}
		AlinousModule* modinc = static_cast<AlinousModule*>(moduleRepository->getModule(inc->getPath(ctx), once, true, debug, ctx));
		if(modinc == nullptr || alreadyIncluded(static_cast<AlinousModule*>(modinc), ctx))
		{
			continue;
		}
		inc->setModule(modinc, ctx);
		(static_cast<AlinousModule*>(modinc))->setParent(this, ctx);
		this->includedModules->add(modinc, ctx);
	}
	ArrayList<AlinousFunction>* funclist = this->moduleSource->getFunctionDeclares(ctx);
	maxLoop = funclist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousFunction* func = funclist->get(i, ctx);
		this->functionMap->put(func->getFunctionName(ctx), func, ctx);
	}
	this->moduleSource->setFilePath(this->setupper->getPath(ctx), ctx);
	this->moduleSource->setDebugFilePath(this->setupper->getDebugPath(ctx), ctx);
	this->moduleSource->visit(this->setupper, nullptr, ctx);
	__GC_MV(this, &(this->packageName), (new(ctx) AlinousModulePackage(this->path, ctx)), AlinousModulePackage);
	if(isInclude)
	{
		return;
	}
	SrcAnalyseContext* context = (new(ctx) SrcAnalyseContext(this, this->core->getFunctionManager(ctx), this->core->sqlFunctionManager, ctx));
	analyseClassDeclare(context, ctx);
	context->newStack(ctx);
	analyzeClassDependency(context, ctx);
	analyzeVirtualMethods(context, ctx);
	this->moduleSource->analyse(context, false, ctx);
	context->endStack(ctx);
	ScriptRunner* runner = this->core->getRunner(ctx);
	ScriptMachine* machine = (new(ctx) ScriptMachine(this, this->core, ctx));
	AlinousModule::ClassCollector* visitor = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(visitor, nullptr, ctx);
	Iterator<AlinousClass>* it = visitor->list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		AlinousClass* clazz = it->next(ctx);
		runner->initStatic(clazz, machine, debug, ctx);
	}
	machine->dispose(ctx);
}
AlinousModulePackage* AlinousModule::getPackageName(ThreadContext* ctx) throw() 
{
	return this->packageName;
}
bool AlinousModule::isDirty(ThreadContext* ctx) throw() 
{
	return this->file->lastModified(ctx) > this->compiledTime;
}
File* AlinousModule::getFile(ThreadContext* ctx) throw() 
{
	return file;
}
String* AlinousModule::getPath(ThreadContext* ctx) throw() 
{
	return path;
}
AlinousSrc* AlinousModule::getModuleSource(ThreadContext* ctx) throw() 
{
	return moduleSource;
}
AlinousModule* AlinousModule::getParent(ThreadContext* ctx) throw() 
{
	return parent;
}
void AlinousModule::setParent(AlinousModule* parent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->parent), parent, AlinousModule);
}
void AlinousModule::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		String* str = buff->getString(ctx);
		__GC_MV(this, &(this->packageName), (new(ctx) AlinousModulePackage(str, ctx)), AlinousModulePackage);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousSrc*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1104(), ctx));
		}
		__GC_MV(this, &(this->moduleSource), static_cast<AlinousSrc*>(el), AlinousSrc);
	}
}
void AlinousModule::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__AlinousModule, ctx);
	bool isnull = (this->packageName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		String* str = this->packageName->toString(ctx);
		buff->putString(str, ctx);
	}
	isnull = (this->moduleSource == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->moduleSource->writeData(buff, ctx);
	}
}
bool AlinousModule::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->moduleSource != nullptr)
	{
		this->moduleSource->analyse(context, false, ctx);
	}
	return true;
}
IAlinousVariable* AlinousModule::executeAsScript(ScriptMachine* machine, bool degug, ThreadContext* ctx)
{
	ScriptRunner* runner = this->core->getRunner(ctx);
	runner->run(this, machine, degug, ctx);
	return machine->getReturnedValue(ctx);
}
void AlinousModule::analyzeVirtualMethods(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->analyzeVirtualMethods(context, ctx);
	}
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->analyseVirtualMethods(context, ctx);
	}
}
void AlinousModule::analyzeClassDependency(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = this->includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->analyzeClassDependency(context, ctx);
	}
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->analyseDependency(context, ctx);
	}
}
void AlinousModule::analyseClassDeclare(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->setPackageName(this->packageName, ctx);
		context->addClassDeclare(clazz, ctx);
	}
	ArrayList<String>* once = (new(ctx) ArrayList<String>(ctx));
	once->add(this->path, ctx);
	maxLoop = includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->exportClasses(context, once, ctx);
	}
}
void AlinousModule::exportClasses(SrcAnalyseContext* context, ArrayList<String>* once, ThreadContext* ctx) throw() 
{
	if(once->contains(path, ctx))
	{
		return;
	}
	once->add(this->path, ctx);
	AlinousModule::ClassCollector* collector = (new(ctx) AlinousModule::ClassCollector(ctx));
	this->moduleSource->visit(collector, nullptr, ctx);
	ArrayList<AlinousClass>* list = collector->getClasses(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousClass* clazz = list->get(i, ctx);
		clazz->setPackageName(this->packageName, ctx);
		context->addClassDeclare(clazz, ctx);
	}
	maxLoop = includedModules->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AlinousModule* mod = this->includedModules->get(i, ctx);
		mod->exportClasses(context, once, ctx);
	}
}
bool AlinousModule::alreadyIncluded(AlinousModule* modinc, ThreadContext* ctx) throw() 
{
	AlinousModule* parendMod = this->parent;
	while(parendMod != nullptr)
	{
		if(parendMod == modinc)
		{
			return true;
		}
		parendMod = parendMod->getParent(ctx);
	}
	return false;
}
}}

namespace alinous {namespace runtime {





bool AlinousModule::SetUpper::__init_done = __init_static_variables();
bool AlinousModule::SetUpper::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModule::SetUpper", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModule::SetUpper::SetUpper(String* path, String* debugPath, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElementVisitor(ctx), path(nullptr), debugPath(nullptr)
{
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->debugPath), debugPath, String);
}
void AlinousModule::SetUpper::__construct_impl(String* path, String* debugPath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->path), path, String);
	__GC_MV(this, &(this->debugPath), debugPath, String);
}
 AlinousModule::SetUpper::~SetUpper() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModule::SetUpper::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SetUpper", L"~SetUpper");
	__e_obj1.add(this->path, this);
	path = nullptr;
	__e_obj1.add(this->debugPath, this);
	debugPath = nullptr;
	if(!prepare){
		return;
	}
}
bool AlinousModule::SetUpper::visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	element->setParent(parent, ctx);
	element->setFilePath(this->path, ctx);
	element->setDebugFilePath(this->debugPath, ctx);
	return true;
}
String* AlinousModule::SetUpper::getPath(ThreadContext* ctx) throw() 
{
	return path;
}
String* AlinousModule::SetUpper::getDebugPath(ThreadContext* ctx) throw() 
{
	return debugPath;
}
}}

namespace alinous {namespace runtime {





bool AlinousModule::ClassCollector::__init_done = __init_static_variables();
bool AlinousModule::ClassCollector::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModule::ClassCollector", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModule::ClassCollector::~ClassCollector() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModule::ClassCollector::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassCollector", L"~ClassCollector");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
bool AlinousModule::ClassCollector::visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<AlinousClass*>(element) != 0))
	{
		this->list->add(static_cast<AlinousClass*>(element), ctx);
	}
	return true;
}
ArrayList<AlinousClass>* AlinousModule::ClassCollector::getClasses(ThreadContext* ctx) throw() 
{
	return this->list;
}
}}

