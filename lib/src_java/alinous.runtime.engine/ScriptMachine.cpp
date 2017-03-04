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
#include "alinous.db.table/DatabaseException.h"
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
#include "alinous.compile.expression/DomNameSegment.h"
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
#include "alinous.runtime.engine/DebugMainFrameSrcElement.h"
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
#include "alinous.db/AlinousDbException.h"
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
#include "alinous.server.http.params/HttpArrayParameter.h"
#include "alinous.server.http.params/HttpParameter.h"
#include "alinous.server.http.params/HttpUploadParameter.h"
#include "alinous.runtime.engine/ExpressionStreamBuffer.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.runtime.engine/IStackFrame.h"
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
#include "alinous.runtime.engine/HttpParamHandler.h"

namespace alinous {namespace runtime {namespace engine {





bool ScriptMachine::__init_done = __init_static_variables();
bool ScriptMachine::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScriptMachine", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScriptMachine::ScriptMachine(AlinousModule* module, AlinousCore* core, ThreadContext* ctx) : IObject(ctx), core(nullptr), stackFrames(GCUtils<Stack<MainStackFrame> >::ins(this, (new(ctx) Stack<MainStackFrame>(ctx)), ctx, __FILEW__, __LINE__, L"")), module(nullptr), dbHandles(GCUtils<ArrayList<DatabaseHandle> >::ins(this, (new(ctx) ArrayList<DatabaseHandle>(ctx)), ctx, __FILEW__, __LINE__, L"")), currentDbHandle(nullptr), alinousStmtRunner(nullptr), sqlRunner(nullptr), stackIdSerial(0), returnedValue(nullptr), expStreamStack(GCUtils<Stack<ExpressionStreamBuffer> >::ins(this, (new(ctx) Stack<ExpressionStreamBuffer>(ctx)), ctx, __FILEW__, __LINE__, L"")), leftValue(0)
{
	__GC_MV(this, &(this->module), module, AlinousModule);
	MainStackFrame* topFrame = (new(ctx) MainStackFrame(module->getModuleSource(ctx), this->stackIdSerial++, ctx));
	this->stackFrames->push(topFrame, ctx);
	topFrame->subFrame(module->getModuleSource(ctx), ctx);
	__GC_MV(this, &(this->core), core, AlinousCore);
	String* defaultSrc = this->core->getConfig(ctx)->getSystem(ctx)->getDefaultDatastore(ctx);
	IDatabaseDriver* driver = this->core->getDatabaseManager(ctx)->get(defaultSrc, ctx);
	if(driver == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1170()->clone(ctx)->append(defaultSrc, ctx)->append(ConstStr::getCNST_STR_1171(), ctx), ctx));
	}
	IDatabaseConnection* con = driver->connect(ctx);
	__GC_MV(this, &(this->currentDbHandle), (new(ctx) DatabaseHandle(driver, con, ctx)), DatabaseHandle);
	this->dbHandles->add(this->currentDbHandle, ctx);
}
void ScriptMachine::__construct_impl(AlinousModule* module, AlinousCore* core, ThreadContext* ctx)
{
	__GC_MV(this, &(this->module), module, AlinousModule);
	MainStackFrame* topFrame = (new(ctx) MainStackFrame(module->getModuleSource(ctx), this->stackIdSerial++, ctx));
	this->stackFrames->push(topFrame, ctx);
	topFrame->subFrame(module->getModuleSource(ctx), ctx);
	__GC_MV(this, &(this->core), core, AlinousCore);
	String* defaultSrc = this->core->getConfig(ctx)->getSystem(ctx)->getDefaultDatastore(ctx);
	IDatabaseDriver* driver = this->core->getDatabaseManager(ctx)->get(defaultSrc, ctx);
	if(driver == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1170()->clone(ctx)->append(defaultSrc, ctx)->append(ConstStr::getCNST_STR_1171(), ctx), ctx));
	}
	IDatabaseConnection* con = driver->connect(ctx);
	__GC_MV(this, &(this->currentDbHandle), (new(ctx) DatabaseHandle(driver, con, ctx)), DatabaseHandle);
	this->dbHandles->add(this->currentDbHandle, ctx);
}
 ScriptMachine::~ScriptMachine() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScriptMachine::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScriptMachine", L"~ScriptMachine");
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->stackFrames, this);
	stackFrames = nullptr;
	__e_obj1.add(this->module, this);
	module = nullptr;
	__e_obj1.add(this->dbHandles, this);
	dbHandles = nullptr;
	__e_obj1.add(this->currentDbHandle, this);
	currentDbHandle = nullptr;
	__e_obj1.add(this->alinousStmtRunner, this);
	alinousStmtRunner = nullptr;
	__e_obj1.add(this->sqlRunner, this);
	sqlRunner = nullptr;
	__e_obj1.add(this->returnedValue, this);
	returnedValue = nullptr;
	__e_obj1.add(this->expStreamStack, this);
	expStreamStack = nullptr;
	if(!prepare){
		return;
	}
}
void ScriptMachine::importParams(HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx)
{
	MainStackFrame* topFrame = this->getFrame(ctx);
	DomVariable* inDom = (new(ctx) DomVariable(ctx));
	DomVariableDescriptor* desc = (new(ctx) DomVariableDescriptor(ctx));
	desc->addSegment((new(ctx) DomNameSegment(ConstStr::getCNST_STR_488(), ctx)), ctx);
	topFrame->putVariable(this, desc, inDom, false, ctx);
	Iterator<String>* it = params->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		AbstractHttpParameter* param = params->get(key, ctx);
		switch(param->paramType) {
		case AbstractHttpParameter::TYPE_NORMAL_PARAM:
			HttpParamHandler::handleNormalParam(this, static_cast<HttpParameter*>(param), topFrame, params, ctx);
			break ;
		case AbstractHttpParameter::TYPE_ARRAY_PARAM:
			HttpParamHandler::handleArrayParam(this, static_cast<HttpArrayParameter*>(param), topFrame, params, ctx);
			break ;
		case AbstractHttpParameter::TYPE_FILE_PARAM:
			HttpParamHandler::handleFileParam(this, static_cast<HttpUploadParameter*>(param), topFrame, params, ctx);
			break ;
		default:
			break ;
		}
	}
}
void ScriptMachine::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	int maxLoop = this->stackFrames->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		MainStackFrame* frame = this->stackFrames->get(i, ctx);
		frame->outDebugXml(parentNode, ctx);
	}
}
IAlinousVariable* ScriptMachine::resolveExpression(IExpression* exp, bool debug, ThreadContext* ctx)
{
	return exp->resolveExpression(this, debug, ctx);
}
AlinousFunction* ScriptMachine::findSourceFunction(String* name, ThreadContext* ctx) throw() 
{
	return this->module->findFunction(name, ctx);
}
void ScriptMachine::newStackFrame(AlinousFunction* func, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = (new(ctx) MainStackFrame(func, this->stackIdSerial++, ctx));
	this->stackFrames->push(frame, ctx);
}
void ScriptMachine::newStackFrame(StatementBlock* block, ThreadContext* ctx) throw() 
{
	IStackFrame* frame = peek(ctx);
	frame->subFrame(block, ctx);
}
void ScriptMachine::popStackFrame(ThreadContext* ctx) throw() 
{
	this->stackFrames->pop(ctx);
}
IStackFrame* ScriptMachine::peek(ThreadContext* ctx) throw() 
{
	return this->stackFrames->peek(ctx)->peek(ctx);
}
MainStackFrame* ScriptMachine::getFrame(ThreadContext* ctx) throw() 
{
	return this->stackFrames->peek(ctx);
}
MainStackFrame* ScriptMachine::getLastFrame(ThreadContext* ctx) throw() 
{
	return this->stackFrames->get(this->stackFrames->size(ctx) - 2, ctx);
}
Stack<MainStackFrame>* ScriptMachine::getStackFrames(ThreadContext* ctx) throw() 
{
	return stackFrames;
}
AlinousCore* ScriptMachine::getCore(ThreadContext* ctx) throw() 
{
	return core;
}
ArrayList<DatabaseHandle>* ScriptMachine::getDbHandles(ThreadContext* ctx) throw() 
{
	return dbHandles;
}
DatabaseHandle* ScriptMachine::getCurrentDbHandle(ThreadContext* ctx) throw() 
{
	return currentDbHandle;
}
void ScriptMachine::dispose(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->currentDbHandle), nullptr, DatabaseHandle);
	int maxdb = this->dbHandles->size(ctx);
	for(int i = 0; i != maxdb; ++i)
	{
		DatabaseHandle* handle = this->dbHandles->get(i, ctx);
		handle->getCon(ctx)->close(ctx);
	}
}
AlinousStatementRunner* ScriptMachine::getAlinousStmtRunner(ThreadContext* ctx) throw() 
{
	return alinousStmtRunner;
}
void ScriptMachine::setAlinousStmtRunner(AlinousStatementRunner* alinousStmtRunner, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->alinousStmtRunner), alinousStmtRunner, AlinousStatementRunner);
}
SQLStatementRunner* ScriptMachine::getSqlRunner(ThreadContext* ctx) throw() 
{
	return sqlRunner;
}
void ScriptMachine::setSqlRunner(SQLStatementRunner* sqlRunner, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->sqlRunner), sqlRunner, SQLStatementRunner);
}
void ScriptMachine::putVariable(DomVariableDescriptor* desc, IDomVariable* variable, bool debug, ThreadContext* ctx)
{
	MainStackFrame* frame = getFrame(ctx);
	frame->putVariable(this, desc, variable, debug, ctx);
}
IDomVariable* ScriptMachine::getByDescriptor(DomVariableDescriptor* domVariableDescriptor, bool debug, ThreadContext* ctx)
{
	MainStackFrame* frame = getFrame(ctx);
	return frame->getDomVariable(this, domVariableDescriptor, debug, ctx);
}
ITypedVariable* ScriptMachine::getTypedVariable(String* name, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = getFrame(ctx);
	ITypedVariable* tv = frame->getTypedVariable(name, ctx);
	return tv;
}
void ScriptMachine::putTypedVariable(String* name, ITypedVariable* variable, ThreadContext* ctx)
{
	MainStackFrame* frame = getFrame(ctx);
	frame->putTypedVariable(name, variable, ctx);
}
IAlinousVariable* ScriptMachine::getReturnedValue(ThreadContext* ctx) throw() 
{
	return returnedValue;
}
void ScriptMachine::setReturnedValue(IAlinousVariable* returnedValue, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->returnedValue), returnedValue, IAlinousVariable);
}
void ScriptMachine::newExpressionStream(ThreadContext* ctx) throw() 
{
	ExpressionStreamBuffer* buff = (new(ctx) ExpressionStreamBuffer(ctx));
	this->expStreamStack->push(buff, ctx);
}
void ScriptMachine::endExpressionStream(ThreadContext* ctx) throw() 
{
	this->expStreamStack->pop(ctx);
}
IAlinousVariable* ScriptMachine::getStreamLastValue(ThreadContext* ctx) throw() 
{
	ExpressionStreamBuffer* buff = this->expStreamStack->peek(ctx);
	return buff->getStreamLastValue(ctx);
}
void ScriptMachine::setStreamLastValue(IAlinousVariable* streamLastValue, ThreadContext* ctx) throw() 
{
	ExpressionStreamBuffer* buff = this->expStreamStack->peek(ctx);
	buff->setStreamLastValue(streamLastValue, ctx);
}
bool ScriptMachine::isLeftValue(ThreadContext* ctx) throw() 
{
	return leftValue;
}
void ScriptMachine::setLeftValue(bool leftValue, ThreadContext* ctx) throw() 
{
	this->leftValue = leftValue;
}
AlinousClassVariable* ScriptMachine::getThisPtr(ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = getFrame(ctx);
	return frame->getThisPtr(ctx);
}
void ScriptMachine::setThisPtr(AlinousClassVariable* thisPtr, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = getFrame(ctx);
	frame->setThisPtr(thisPtr, ctx);
}
}}}

