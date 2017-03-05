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





bool DocumentVariable::__init_done = __init_static_variables();
bool DocumentVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DocumentVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DocumentVariable::DocumentVariable(ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) DomVariable(ctx)), IDomVariable);
}
void DocumentVariable::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) DomVariable(ctx)), IDomVariable);
}
 DocumentVariable::DocumentVariable(bool array, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), value(nullptr)
{
	if(array)
	{
		__GC_MV(this, &(this->value), (new(ctx) DomArray(ctx)), IDomVariable);
	}
		else 
	{
		__GC_MV(this, &(this->value), (new(ctx) DomVariable(ctx)), IDomVariable);
	}
}
void DocumentVariable::__construct_impl(bool array, ThreadContext* ctx) throw() 
{
	if(array)
	{
		__GC_MV(this, &(this->value), (new(ctx) DomArray(ctx)), IDomVariable);
	}
		else 
	{
		__GC_MV(this, &(this->value), (new(ctx) DomVariable(ctx)), IDomVariable);
	}
}
 DocumentVariable::~DocumentVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DocumentVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DocumentVariable", L"~DocumentVariable");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
}
void DocumentVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	if(this->value != nullptr)
	{
		this->value->outDebugXml(parentNode, name, ctx);
	}
}
IDomVariable* DocumentVariable::getByDescriptor(DomVariableDescriptor* desc, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
void DocumentVariable::setProperty(String* key, IDomVariable* value, ThreadContext* ctx)
{
	this->value->setProperty(key, value, ctx);
}
IDomVariableContainer* DocumentVariable::getProperty(String* key, ThreadContext* ctx)
{
	return this->value->getProperty(key, ctx);
}
IDomVariableContainer* DocumentVariable::get(int index, ThreadContext* ctx) throw() 
{
	return this->value->get(index, ctx);
}
void DocumentVariable::set(IDomVariable* val, int index, ThreadContext* ctx) throw() 
{
	this->value->set(val, index, ctx);
}
int DocumentVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return this->value->getVariableClass(ctx);
}
IAlinousVariable* DocumentVariable::copy(ThreadContext* ctx)
{
	DocumentVariable* newObj = (new(ctx) DocumentVariable(ctx));
	IDomVariable* val = static_cast<IDomVariable*>(this->value->copy(ctx));
	__GC_MV(newObj, &(newObj->value), val, IDomVariable);
	return newObj;
}
IDomVariable* DocumentVariable::toDomVariable(ThreadContext* ctx)
{
	return this;
}
bool DocumentVariable::isNull(ThreadContext* ctx) throw() 
{
	return this->value->isNull(ctx);
}
bool DocumentVariable::isArray(ThreadContext* ctx) throw() 
{
	return this->value->isArray(ctx);
}
BoolVariable* DocumentVariable::toBoolVariable(ThreadContext* ctx)
{
	return this->value->toBoolVariable(ctx);
}
ByteVariable* DocumentVariable::toByteVariable(ThreadContext* ctx)
{
	return this->value->toByteVariable(ctx);
}
CharVariable* DocumentVariable::toCharVariable(ThreadContext* ctx)
{
	return this->value->toCharVariable(ctx);
}
ShortVariable* DocumentVariable::toShortVariable(ThreadContext* ctx)
{
	return this->value->toShortVariable(ctx);
}
IntegerVariable* DocumentVariable::toIntVariable(ThreadContext* ctx)
{
	return this->value->toIntVariable(ctx);
}
LongVariable* DocumentVariable::toLongVariable(ThreadContext* ctx)
{
	return this->value->toLongVariable(ctx);
}
StringVariable* DocumentVariable::toStringVariable(ThreadContext* ctx)
{
	return this->value->toStringVariable(ctx);
}
FloatVariable* DocumentVariable::toFloatVariable(ThreadContext* ctx)
{
	return this->value->toFloatVariable(ctx);
}
DoubleVariable* DocumentVariable::toDoubleVariable(ThreadContext* ctx)
{
	return this->value->toDoubleVariable(ctx);
}
BigDecimalVariable* DocumentVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	return this->value->toBigDecimalVariable(ctx);
}
TimeVariable* DocumentVariable::toTimeVariable(ThreadContext* ctx)
{
	return this->value->toTimeVariable(ctx);
}
TimestampVariable* DocumentVariable::toTimestampVariable(ThreadContext* ctx)
{
	return this->value->toTimestampVariable(ctx);
}
VariantValue* DocumentVariable::toVariantValue(ThreadContext* ctx)
{
	return this->value->toVariantValue(ctx);
}
int DocumentVariable::getIntValue(ThreadContext* ctx)
{
	return this->value->getIntValue(ctx);
}
long long DocumentVariable::getLongValue(ThreadContext* ctx)
{
	return this->value->getLongValue(ctx);
}
String* DocumentVariable::getStringValue(ThreadContext* ctx)
{
	return this->value->getStringValue(ctx);
}
IAlinousVariable* DocumentVariable::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitReverse(ThreadContext* ctx)
{
	return this->value->bitReverse(ctx);
}
IAlinousVariable* DocumentVariable::substitute(IAlinousVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable, IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
int DocumentVariable::compareTo(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
bool DocumentVariable::isTrue(ThreadContext* ctx)
{
	return this->value->isTrue(ctx);
}
int DocumentVariable::getDomType(ThreadContext* ctx) throw() 
{
	return this->value->getDomType(ctx);
}
IDomVariable* DocumentVariable::toDom(ThreadContext* ctx) throw() 
{
	return this->value->toDom(ctx);
}
void DocumentVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	char nullbl = buff->getByte(ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	IAlinousVariable* val = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
	if(val == nullptr || !((dynamic_cast<IDomVariable*>(val) != 0)))
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1123(), ctx));
	}
	__GC_MV(this, &(this->value), static_cast<IDomVariable*>(val), IDomVariable);
}
void DocumentVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__DocumentVariable, ctx);
	char nullbl = ((char)(isNull(ctx) ? 0 : 1));
	buff->putByte(nullbl, ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	this->value->writeData(buff, ctx);
}
int DocumentVariable::ValueCompare::operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}

