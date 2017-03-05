#include "include/global.h"


#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
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
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
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
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableDomFactory.h"

namespace alinous {namespace runtime {namespace dom {namespace typed {





String* TimestampVariable::VAL_TYPE = ConstStr::getCNST_STR_1148();
bool TimestampVariable::__init_done = __init_static_variables();
bool TimestampVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimestampVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimestampVariable::TimestampVariable(Timestamp* timestamp, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), timestamp, Timestamp);
}
void TimestampVariable::__construct_impl(Timestamp* timestamp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), timestamp, Timestamp);
}
 TimestampVariable::~TimestampVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimestampVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TimestampVariable", L"~TimestampVariable");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void TimestampVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* nameattr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(nameattr, ctx);
	}
	if(this->value != nullptr)
	{
		Attribute* attr = (new(ctx) Attribute(AbstractTypedVariable::VALUE, this->value->toString(ctx), node, ctx));
		parentNode->addAttribute(attr, ctx);
	}
}
int TimestampVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int TimestampVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_TIMESTAMP;
}
Timestamp* TimestampVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void TimestampVariable::setValue(Timestamp* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, Timestamp);
}
VariantValue* TimestampVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx));
}
IAlinousVariable* TimestampVariable::copy(ThreadContext* ctx)
{
	VariantValue* value = (new(ctx) VariantValue(this->value, ctx));
	DomVariable* dom = (new(ctx) DomVariable(ctx));
	dom->setValue(value, ctx);
	return dom;
}
IDomVariable* TimestampVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	VariantValue* value = (new(ctx) VariantValue(this->value, ctx));
	DomVariable* dom = (new(ctx) DomVariable(ctx));
	dom->setValue(value, ctx);
	return dom;
}
bool TimestampVariable::isNull(ThreadContext* ctx) throw() 
{
	return this->value == nullptr;
}
bool TimestampVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
BoolVariable* TimestampVariable::toBoolVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
ByteVariable* TimestampVariable::toByteVariable(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(((char)this->value->getTime(ctx)), ctx));
}
CharVariable* TimestampVariable::toCharVariable(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(((wchar_t)this->value->getTime(ctx)), ctx));
}
ShortVariable* TimestampVariable::toShortVariable(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(((short)this->value->getTime(ctx)), ctx));
}
IntegerVariable* TimestampVariable::toIntVariable(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(((int)this->value->getTime(ctx)), ctx));
}
LongVariable* TimestampVariable::toLongVariable(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(this->value->getTime(ctx), ctx));
}
StringVariable* TimestampVariable::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(this->value->toString(ctx), ctx));
}
FloatVariable* TimestampVariable::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(this->value->getTime(ctx), ctx));
}
DoubleVariable* TimestampVariable::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value->getTime(ctx), ctx));
}
BigDecimalVariable* TimestampVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	return (new(ctx) BigDecimalVariable((new(ctx) BigDecimal(this->value->getTime(ctx), ctx)), ctx));
}
TimeVariable* TimestampVariable::toTimeVariable(ThreadContext* ctx)
{
	return (new(ctx) TimeVariable((new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx), ctx)), ctx));
}
TimestampVariable* TimestampVariable::toTimestampVariable(ThreadContext* ctx)
{
	return (new(ctx) TimestampVariable((new(ctx) Timestamp(this->value->getTime(ctx), ctx)), ctx));
}
int TimestampVariable::getIntValue(ThreadContext* ctx)
{
	return ((int)this->value->getTime(ctx));
}
long long TimestampVariable::getLongValue(ThreadContext* ctx)
{
	return this->value->getTime(ctx);
}
String* TimestampVariable::getStringValue(ThreadContext* ctx)
{
	return this->value->toString(ctx);
}
IAlinousVariable* TimestampVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) + variable->getLong(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) + variable->getValue(ctx)->getLong(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* TimestampVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) + variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) + variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) + variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) + variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) + variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) + variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) + variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) + variable->toTimestampVariable(ctx)->getValue(ctx)->getTime(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) + variable->getValue(ctx)->longValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) + variable->getValue(ctx)->getTime(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) + variable->getValue(ctx)->getTime(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) - variable->getLong(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) - variable->getValue(ctx)->getLong(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* TimestampVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) - variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) - variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) - variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) - variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) - variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) - variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) - variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) - variable->toTimestampVariable(ctx)->getValue(ctx)->getTime(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) - variable->getValue(ctx)->longValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) - variable->getValue(ctx)->getTime(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) - variable->getValue(ctx)->getTime(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) / variable->getLong(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) / variable->getValue(ctx)->getLong(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* TimestampVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) / variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) / variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) / variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) / variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) / variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) / variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) / variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) / variable->toTimestampVariable(ctx)->getValue(ctx)->getTime(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) / variable->getValue(ctx)->longValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) / variable->getValue(ctx)->getTime(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) / variable->getValue(ctx)->getTime(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) * variable->getLong(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) * variable->getValue(ctx)->getLong(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* TimestampVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) * variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) * variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) * variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) * variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) * variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) * variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) * variable->getValue(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)(this->value->getTime(ctx) * variable->toTimestampVariable(ctx)->getValue(ctx)->getTime(ctx))), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) * variable->getValue(ctx)->longValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) * variable->getValue(ctx)->getTime(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(this->value->getTime(ctx) * variable->getValue(ctx)->getTime(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(variable->getLong(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(variable->getValue(ctx)->getLong(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* TimestampVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)variable->getValue(ctx)), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(((long long)variable->getValue(ctx)), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(variable->getValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toTimestampVariable(ctx)->getValue(ctx), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(variable->getValue(ctx)->longValue(ctx), ctx)), Timestamp);
	return this;
}
IAlinousVariable* TimestampVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(variable->getValue(ctx)->getTime(ctx), ctx)), Timestamp);
	return nullptr;
}
IAlinousVariable* TimestampVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->getValue(ctx), Timestamp);
	return this;
}
int TimestampVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->getTimestamp(ctx), ctx);
}
int TimestampVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->getValue(ctx)->getTimestamp(ctx), ctx);
}
int TimestampVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
int TimestampVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
int TimestampVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
int TimestampVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
int TimestampVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
int TimestampVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
int TimestampVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
int TimestampVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
int TimestampVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
int TimestampVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
int TimestampVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
int TimestampVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimestampVariable(ctx)->getValue(ctx), ctx);
}
bool TimestampVariable::isTrue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1146(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::bitReverse(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1147(), ctx));
}
IAlinousVariable* TimestampVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
void TimestampVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	char nullbl = buff->getByte(ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	long long tm = buff->getLong(ctx);
	__GC_MV(this, &(this->value), (new(ctx) Timestamp(tm, ctx)), Timestamp);
}
void TimestampVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__TimestampVariable, ctx);
	char nullbl = ((char)(isNull(ctx) ? 0 : 1));
	buff->putByte(nullbl, ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	buff->putLong(this->value->getTime(ctx), ctx);
}
TimestampVariable* TimestampVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	IVariableValue* attrVal = node->getAttributeValue(VAL_TYPE, ctx);
	if(attrVal == nullptr)
	{
		return nullptr;
	}
	String* str = attrVal->toString(ctx);
	long long value = 0;
	{
		try
		{
			value = Long::parseLong(str, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return (new(ctx) TimestampVariable((new(ctx) Timestamp(value, ctx)), ctx));
}
int TimestampVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

