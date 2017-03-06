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
#include "alinous.web.htmlxml/AlinousAttrs.h"
#include "alinous.runtime.engine/HttpParamHandler.h"

namespace alinous {namespace runtime {namespace engine {





constexpr const int HttpParamHandler::STRING_VALUE;
constexpr const int HttpParamHandler::BYTE_VALUE;
constexpr const int HttpParamHandler::SHORT_VALUE;
constexpr const int HttpParamHandler::CHAR_VALUE;
constexpr const int HttpParamHandler::INT_VALUE;
constexpr const int HttpParamHandler::LONG_VALUE;
constexpr const int HttpParamHandler::FLOAT_VALUE;
constexpr const int HttpParamHandler::DOUBLE_VALUE;
bool HttpParamHandler::__init_done = __init_static_variables();
bool HttpParamHandler::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpParamHandler", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpParamHandler::~HttpParamHandler() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpParamHandler::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void HttpParamHandler::handleNormalParam(ScriptMachine* machine, HttpParameter* param, MainStackFrame* topFrame, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx)
{
	String* strValue = param->value;
	HttpParamHandler::ParamResult* typeResult = getStringType(strValue, params, ctx);
	String* name = param->getName(ctx);
	DomVariableDescriptor* desc = (new(ctx) DomVariableDescriptor(ctx));
	desc->addSegment((new(ctx) DomNameSegment(ConstStr::getCNST_STR_488(), ctx)), ctx);
	desc->addSegment((new(ctx) DomNameSegment(name, ctx)), ctx);
	switch(typeResult->type) {
	case HttpParamHandler::BYTE_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->byteValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::SHORT_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->shortValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::CHAR_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->charValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::INT_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->intValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::LONG_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->intValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::FLOAT_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->intValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::DOUBLE_VALUE:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(typeResult->intValue, ctx)), false, ctx);
		break ;
	case HttpParamHandler::STRING_VALUE:
	default:
		topFrame->putVariable(machine, desc, (new(ctx) DomVariable(strValue, ctx)), false, ctx);
		break ;
	}
}
void HttpParamHandler::handleArrayParam(ScriptMachine* machine, HttpArrayParameter* param, MainStackFrame* topFrame, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx)
{
	ArrayList<String>* strValues = param->values;
	int alnsType = -1;
	Iterator<String>* it = params->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* name = it->next(ctx);
		AbstractHttpParameter* p = params->get(name, ctx);
		if(name->equals(AlinousAttrs::ALINOUS_TYPE, ctx) && p->paramType == AbstractHttpParameter::TYPE_NORMAL_PARAM && (static_cast<HttpParameter*>(p))->value != nullptr)
		{
			String* typeValue = (static_cast<HttpParameter*>(p))->value;
			alnsType = handleAlinousTypeOnly(typeValue, ctx);
		}
	}
	String* name = param->getName(ctx);
	DomArray* domarray = (new(ctx) DomArray(ctx));
	DomVariableDescriptor* desc = (new(ctx) DomVariableDescriptor(ctx));
	desc->addSegment((new(ctx) DomNameSegment(ConstStr::getCNST_STR_488(), ctx)), ctx);
	desc->addSegment((new(ctx) DomNameSegment(name, ctx)), ctx);
	topFrame->putVariable(machine, desc, domarray, false, ctx);
	int maxLoop = 0;
	if(alnsType > 0)
	{
		maxLoop = strValues->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			String* valStr = strValues->get(i, ctx);
			IDomVariable* element = toVariable(alnsType, valStr, ctx);
			domarray->add(element, ctx);
		}
		return;
	}
	maxLoop = strValues->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* valStr = strValues->get(i, ctx);
		{
			try
			{
				int intValue = Integer::parseInt(valStr, ctx);
				IDomVariable* element = (new(ctx) DomVariable(intValue, ctx));
				domarray->put(element, ctx);
				continue;
			}
			catch(Throwable* e)
			{
			}
		}
		{
			try
			{
				double dblValue = Double::parseDouble(valStr, ctx);
				IDomVariable* element = (new(ctx) DomVariable(dblValue, ctx));
				domarray->put(element, ctx);
				continue;
			}
			catch(Throwable* e)
			{
			}
		}
		IDomVariable* element = (new(ctx) DomVariable(valStr, ctx));
		domarray->put(element, ctx);
	}
}
void HttpParamHandler::handleFileParam(ScriptMachine* machine, HttpUploadParameter* param, MainStackFrame* topFrame, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx) throw() 
{
}
HttpParamHandler::ParamResult* HttpParamHandler::getStringType(String* strValue, HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx) throw() 
{
	Iterator<String>* it = params->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* name = it->next(ctx);
		AbstractHttpParameter* p = params->get(name, ctx);
		if(name->equals(AlinousAttrs::ALINOUS_TYPE, ctx) && p->paramType == AbstractHttpParameter::TYPE_NORMAL_PARAM && (static_cast<HttpParameter*>(p))->value != nullptr)
		{
			String* typeValue = (static_cast<HttpParameter*>(p))->value;
			return handleAlinousType(strValue, typeValue, ctx);
		}
	}
	HttpParamHandler::ParamResult* result = (new(ctx) HttpParamHandler::ParamResult(ctx));
	result->type = HttpParamHandler::STRING_VALUE;
	__GC_MV(result, &(result->str), strValue, String);
	{
		try
		{
			int intValue = Integer::parseInt(strValue, ctx);
			result->type = HttpParamHandler::INT_VALUE;
			result->intValue = intValue;
			return result;
		}
		catch(Throwable* e)
		{
		}
	}
	{
		try
		{
			double value = Double::parseDouble(strValue, ctx);
			result->type = HttpParamHandler::DOUBLE_VALUE;
			result->doubleValue = value;
			return result;
		}
		catch(Throwable* e)
		{
		}
	}
	return result;
}
HttpParamHandler::ParamResult* HttpParamHandler::handleAlinousType(String* strValue, String* typeValue, ThreadContext* ctx) throw() 
{
	HttpParamHandler::ParamResult* result = (new(ctx) HttpParamHandler::ParamResult(ctx));
	result->type = HttpParamHandler::STRING_VALUE;
	__GC_MV(result, &(result->str), strValue, String);
	if(typeValue->equals(ConstStr::getCNST_STR_1174(), ctx))
	{
		return result;
	}
	if(typeValue->equals(ConstStr::getCNST_STR_958(), ctx))
	{
		char value = 0;
		{
			try
			{
				value = Byte::parseByte(strValue, ctx);
			}
			catch(Throwable* e)
			{
				return result;
			}
		}
		result->type = HttpParamHandler::BYTE_VALUE;
		result->byteValue = value;
		return result;
	}
		else 
	{
		if(typeValue->equals(ConstStr::getCNST_STR_959(), ctx))
		{
			short value = 0;
			{
				try
				{
					value = Short::parseShort(strValue, ctx);
				}
				catch(Throwable* e)
				{
					return result;
				}
			}
			result->type = HttpParamHandler::SHORT_VALUE;
			result->shortValue = value;
			return result;
		}
				else 
		{
			if(typeValue->equals(ConstStr::getCNST_STR_960(), ctx))
			{
				short value = 0;
				{
					try
					{
						value = Short::parseShort(strValue, ctx);
					}
					catch(Throwable* e)
					{
						return result;
					}
				}
				result->type = HttpParamHandler::CHAR_VALUE;
				result->charValue = ((wchar_t)value);
				return result;
			}
						else 
			{
				if(typeValue->equals(ConstStr::getCNST_STR_961(), ctx))
				{
					int value = 0;
					{
						try
						{
							value = Integer::parseInt(strValue, ctx);
						}
						catch(Throwable* e)
						{
							return result;
						}
					}
					result->type = HttpParamHandler::INT_VALUE;
					result->intValue = value;
					return result;
				}
								else 
				{
					if(typeValue->equals(ConstStr::getCNST_STR_962(), ctx))
					{
						long long value = 0;
						{
							try
							{
								value = Long::parseLong(strValue, ctx);
							}
							catch(Throwable* e)
							{
								return result;
							}
						}
						result->type = HttpParamHandler::LONG_VALUE;
						result->longValue = value;
						return result;
					}
										else 
					{
						if(typeValue->equals(ConstStr::getCNST_STR_964(), ctx))
						{
							float value = 0;
							{
								try
								{
									value = Float::parseFloat(strValue, ctx);
								}
								catch(Throwable* e)
								{
									return result;
								}
							}
							result->type = HttpParamHandler::FLOAT_VALUE;
							result->floatValue = value;
							return result;
						}
												else 
						{
							if(typeValue->equals(ConstStr::getCNST_STR_963(), ctx))
							{
								double value = 0;
								{
									try
									{
										value = Double::parseDouble(strValue, ctx);
									}
									catch(Throwable* e)
									{
										return result;
									}
								}
								result->type = HttpParamHandler::DOUBLE_VALUE;
								result->doubleValue = value;
								return result;
							}
						}
					}
				}
			}
		}
	}
	return result;
}
IDomVariable* HttpParamHandler::toVariable(int alnsType, String* valStr, ThreadContext* ctx) throw() 
{
	switch(alnsType) {
	case HttpParamHandler::BYTE_VALUE:
		{
			char value = 0;
			{
				try
				{
					value = Byte::parseByte(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::SHORT_VALUE:
		{
			short value = 0;
			{
				try
				{
					value = Short::parseShort(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::CHAR_VALUE:
		{
			wchar_t value = 0;
			{
				try
				{
					value = ((wchar_t)Short::parseShort(valStr, ctx));
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::INT_VALUE:
		{
			int value = 0;
			{
				try
				{
					value = Integer::parseInt(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::LONG_VALUE:
		{
			long long value = 0;
			{
				try
				{
					value = Long::parseLong(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::FLOAT_VALUE:
		{
			float value = 0;
			{
				try
				{
					value = Float::parseFloat(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::DOUBLE_VALUE:
		{
			double value = 0;
			{
				try
				{
					value = Double::parseDouble(valStr, ctx);
				}
				catch(Throwable* e)
				{
					return (new(ctx) DomVariable(valStr, ctx));
				}
			}
			return (new(ctx) DomVariable(value, ctx));
		}
	case HttpParamHandler::STRING_VALUE:
	default:
		break ;
	}
	return (new(ctx) DomVariable(valStr, ctx));
}
int HttpParamHandler::handleAlinousTypeOnly(String* typeValue, ThreadContext* ctx) throw() 
{
	if(typeValue->equals(ConstStr::getCNST_STR_1174(), ctx))
	{
		return HttpParamHandler::STRING_VALUE;
	}
	if(typeValue->equals(ConstStr::getCNST_STR_958(), ctx))
	{
		return HttpParamHandler::BYTE_VALUE;
	}
		else 
	{
		if(typeValue->equals(ConstStr::getCNST_STR_959(), ctx))
		{
			return HttpParamHandler::SHORT_VALUE;
		}
				else 
		{
			if(typeValue->equals(ConstStr::getCNST_STR_960(), ctx))
			{
				return HttpParamHandler::CHAR_VALUE;
			}
						else 
			{
				if(typeValue->equals(ConstStr::getCNST_STR_961(), ctx))
				{
					return HttpParamHandler::INT_VALUE;
				}
								else 
				{
					if(typeValue->equals(ConstStr::getCNST_STR_962(), ctx))
					{
						return HttpParamHandler::LONG_VALUE;
					}
										else 
					{
						if(typeValue->equals(ConstStr::getCNST_STR_964(), ctx))
						{
							return HttpParamHandler::FLOAT_VALUE;
						}
												else 
						{
							if(typeValue->equals(ConstStr::getCNST_STR_963(), ctx))
							{
								return HttpParamHandler::DOUBLE_VALUE;
							}
						}
					}
				}
			}
		}
	}
	return HttpParamHandler::STRING_VALUE;
}
}}}

namespace alinous {namespace runtime {namespace engine {





bool HttpParamHandler::ParamResult::__init_done = __init_static_variables();
bool HttpParamHandler::ParamResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpParamHandler::ParamResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpParamHandler::ParamResult::~ParamResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpParamHandler::ParamResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ParamResult", L"~ParamResult");
	__e_obj1.add(this->str, this);
	str = nullptr;
	if(!prepare){
		return;
	}
}
}}}

