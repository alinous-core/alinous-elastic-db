#include "include/global.h"


#include "alinous.web.parse.htmlxml/TokenMgrError.h"
#include "alinous.web.parse.htmlxml/Token.h"
#include "alinous.web.parse.htmlxml/ParseException.h"
#include "alinous.compile/Token.h"
#include "alinous.web.parse.htmlxml/JavaCharStream.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParserConstants.h"
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
#include "alinous.compile/ParseException.h"
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
#include "alinous.web.htmlxml/AbstractXHtmlElement.h"
#include "alinous.web.htmlxml/AbstractXHtmlAttributeValue.h"
#include "alinous.web.htmlxml/XHtmlAttribute.h"
#include "alinous.web.htmlxml/XMLTagBase.h"
#include "alinous.web.htmlxml.module/AbstractSerializedHtmlPart.h"
#include "alinous.web.htmlxml.module/SerializeContext.h"
#include "alinous.web.htmlxml/HtmlDocType.h"
#include "alinous.web.htmlxml/HtmlTopObject.h"
#include "alinous.web.htmlxml/BodyText.h"
#include "alinous.web.htmlxml/XHtmlComment.h"
#include "alinous.web.htmlxml.module/DynamicExecutableAttributeValue.h"
#include "alinous.web.htmlxml/XHtmlDqString.h"
#include "alinous.web.htmlxml/XHtmlSQString.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParser.h"
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
#include "alinous.system/AlinousException.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParserTokenManager.h"
#include "alinous.compile/JavaCharStream.h"

namespace alinous {namespace web {namespace parse {namespace htmlxml {





IArrayObjectPrimitive<long long>* HtmlXmlParser::jj_la1_0 = nullptr;
bool HtmlXmlParser::__init_done = __init_static_variables();
bool HtmlXmlParser::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HtmlXmlParser", L"__init_static_variables");
		__GC_MV(nullptr, &(jj_la1_0), nullptr, IArrayObjectPrimitive<long long>);
		{
			jj_la1_init_0(ctx);
		}
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HtmlXmlParser::HtmlXmlParser(java::io::InputStream* stream, ThreadContext* ctx) : IObject(ctx), HtmlXmlParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 16), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 6), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) HtmlXmlParser::LookaheadSuccess(ctx)), HtmlXmlParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	__construct_impl(stream, nullptr, ctx);
}
void HtmlXmlParser::__construct_impl(java::io::InputStream* stream, ThreadContext* ctx)
{
	__construct_impl(stream, nullptr, ctx);
}
 HtmlXmlParser::HtmlXmlParser(java::io::InputStream* stream, String* encoding, ThreadContext* ctx) : IObject(ctx), HtmlXmlParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 16), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 6), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) HtmlXmlParser::LookaheadSuccess(ctx)), HtmlXmlParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	{
		try
		{
			__GC_MV(this, &(jj_input_stream), (new(ctx) JavaCharStream(stream, encoding, 1, 1, ctx)), JavaCharStream);
		}
		catch(java::io::UnsupportedEncodingException* e)
		{
			throw (new(ctx) RuntimeException(e, ctx));
		}
	}
	__GC_MV(this, &(token_source), (new(ctx) HtmlXmlParserTokenManager(jj_input_stream, ctx)), HtmlXmlParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)16; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) HtmlXmlParser::JJCalls(ctx)),i, ctx);
}
void HtmlXmlParser::__construct_impl(java::io::InputStream* stream, String* encoding, ThreadContext* ctx)
{
	{
		try
		{
			__GC_MV(this, &(jj_input_stream), (new(ctx) JavaCharStream(stream, encoding, 1, 1, ctx)), JavaCharStream);
		}
		catch(java::io::UnsupportedEncodingException* e)
		{
			throw (new(ctx) RuntimeException(e, ctx));
		}
	}
	__GC_MV(this, &(token_source), (new(ctx) HtmlXmlParserTokenManager(jj_input_stream, ctx)), HtmlXmlParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)16; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) HtmlXmlParser::JJCalls(ctx)),i, ctx);
}
 HtmlXmlParser::HtmlXmlParser(java::io::Reader* stream, ThreadContext* ctx) : IObject(ctx), HtmlXmlParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 16), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 6), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) HtmlXmlParser::LookaheadSuccess(ctx)), HtmlXmlParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	__GC_MV(this, &(jj_input_stream), (new(ctx) JavaCharStream(stream, 1, 1, ctx)), JavaCharStream);
	__GC_MV(this, &(token_source), (new(ctx) HtmlXmlParserTokenManager(jj_input_stream, ctx)), HtmlXmlParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)16; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) HtmlXmlParser::JJCalls(ctx)),i, ctx);
}
void HtmlXmlParser::__construct_impl(java::io::Reader* stream, ThreadContext* ctx)
{
	__GC_MV(this, &(jj_input_stream), (new(ctx) JavaCharStream(stream, 1, 1, ctx)), JavaCharStream);
	__GC_MV(this, &(token_source), (new(ctx) HtmlXmlParserTokenManager(jj_input_stream, ctx)), HtmlXmlParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)16; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) HtmlXmlParser::JJCalls(ctx)),i, ctx);
}
 HtmlXmlParser::HtmlXmlParser(HtmlXmlParserTokenManager* tm, ThreadContext* ctx) : IObject(ctx), HtmlXmlParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 16), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 6), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) HtmlXmlParser::LookaheadSuccess(ctx)), HtmlXmlParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	__GC_MV(this, &(token_source), tm, HtmlXmlParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)16; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) HtmlXmlParser::JJCalls(ctx)),i, ctx);
}
void HtmlXmlParser::__construct_impl(HtmlXmlParserTokenManager* tm, ThreadContext* ctx)
{
	__GC_MV(this, &(token_source), tm, HtmlXmlParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)16; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) HtmlXmlParser::JJCalls(ctx)),i, ctx);
}
 HtmlXmlParser::~HtmlXmlParser()
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HtmlXmlParser::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HtmlXmlParser", L"~HtmlXmlParser");
	__e_obj1.add(this->token_source, this);
	token_source = nullptr;
	__e_obj1.add(this->token, this);
	token = nullptr;
	__e_obj1.add(this->jj_nt, this);
	jj_nt = nullptr;
	__e_obj1.add(this->jj_input_stream, this);
	jj_input_stream = nullptr;
	__e_obj1.add(this->jj_scanpos, this);
	jj_scanpos = nullptr;
	__e_obj1.add(this->jj_lastpos, this);
	jj_lastpos = nullptr;
	__e_obj1.add(this->jj_la1, this);
	jj_la1 = nullptr;
	__e_obj1.add(this->jj_2_rtns, this);
	jj_2_rtns = nullptr;
	__e_obj1.add(this->jj_ls, this);
	jj_ls = nullptr;
	__e_obj1.add(this->jj_expentries, this);
	jj_expentries = nullptr;
	__e_obj1.add(this->jj_expentry, this);
	jj_expentry = nullptr;
	__e_obj1.add(this->jj_lasttokens, this);
	jj_lasttokens = nullptr;
	if(!prepare){
		return;
	}
}
HtmlTopObject* HtmlXmlParser::parse(ThreadContext* ctx)
{
	HtmlTopObject* top = (new(ctx) HtmlTopObject(ctx));
	AbstractXHtmlElement* element = nullptr;
	HtmlDocType* _docType = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case DOCTYPE:
		{
			_docType = docType(ctx);
			top->setDocType(_docType, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,0, ctx);
		;
		break;
	}
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case br:
		case link:
		case meta:
		case col:
		case param:
		case base:
		case area:
		case hr:
		case input:
		case GT:
		case LT:
		case GT_SLASH:
		case EQUALS:
		case XML_HEADER_END:
		case COMMENT:
		case WHITE_SPACE:
		case STRING_LITERAL:
		case SQ_STRING_LITERAL:
		case IDENTIFIER:
		case HTML_BODY_STRING:
		case 30:
		case 31:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,1, ctx);
			goto label_1_out_break;
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case br:
		case link:
		case meta:
		case col:
		case param:
		case base:
		case area:
		case hr:
		case input:
		case GT:
		case GT_SLASH:
		case EQUALS:
		case XML_HEADER_END:
		case WHITE_SPACE:
		case STRING_LITERAL:
		case SQ_STRING_LITERAL:
		case IDENTIFIER:
		case HTML_BODY_STRING:
		case 30:
		case 31:
			{
				element = bodyText(ctx);
				break ;
			}
		case LT:
			{
				element = tagObject(ctx);
				break ;
			}
		case COMMENT:
			{
				element = comment(ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,2, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		top->addElement(element, ctx);
	}
	label_1_out_break: ;
	{
		{
			return top;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
HtmlDocType* HtmlXmlParser::docType(ThreadContext* ctx)
{
	HtmlDocType* docType = (new(ctx) HtmlDocType(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	Token* lit = nullptr;
	XHtmlDqString* value = nullptr;
	XHtmlAttribute* attr = nullptr;
	t = jj_consume_token(DOCTYPE, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case WHITE_SPACE:
		case STRING_LITERAL:
		case IDENTIFIER:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,3, ctx);
			goto label_2_out_break;
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case WHITE_SPACE:
			{
				skipWhiteSpace2(ctx);
				break ;
			}
		case IDENTIFIER:
			{
				attr = attribute(ctx);
				docType->addElement(attr, ctx);
				break ;
			}
		case STRING_LITERAL:
			{
				lit = jj_consume_token(STRING_LITERAL, ctx);
				value = (new(ctx) XHtmlDqString(ctx));
				value->position(lit, lit, ctx);
				value->setValue(lit->image, ctx);
				docType->addElement(value, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,4, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	label_2_out_break: ;
	t2 = jj_consume_token(GT, ctx);
	docType->position(t, t2, ctx);
	{
		{
			return docType;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XHtmlComment* HtmlXmlParser::comment(ThreadContext* ctx)
{
	XHtmlComment* com = (new(ctx) XHtmlComment(ctx));
	Token* t = nullptr;
	t = jj_consume_token(COMMENT, ctx);
	com->position(t, t, ctx);
	com->setComment(t->image, ctx);
	{
		{
			return com;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XMLTagBase* HtmlXmlParser::tagObject(ThreadContext* ctx)
{
	XMLTagBase* tag = nullptr;
	if(jj_2_1((long long)3, ctx))
	{
		tag = htmlSingleTagObject(ctx);
	}
		else 
	{
		if(jj_2_2((long long)2147483647, ctx))
		{
			tag = singleTagObject(ctx);
		}
				else 
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case LT:
				{
					tag = normalTagObject(ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,5, ctx);
				jj_consume_token((long long)-1, ctx);
				throw (new(ctx) ParseException(ctx));
				break;
			}
		}
	}
	{
		{
			return tag;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XMLTagBase* HtmlXmlParser::normalTagObject(ThreadContext* ctx)
{
	XMLTagBase* tag = (new(ctx) XMLTagBase(ctx));
	Token* start = nullptr;
	Token* t = nullptr;
	Token* end = nullptr;
	XHtmlAttribute* attr = nullptr;
	AbstractXHtmlElement* element = nullptr;
	start = jj_consume_token(LT, ctx);
	skipWhiteSpace(ctx);
	t = jj_consume_token(IDENTIFIER, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case WHITE_SPACE:
		case IDENTIFIER:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,6, ctx);
			goto label_3_out_break;
		}
		skipWhiteSpace(ctx);
		attr = attribute(ctx);
		skipWhiteSpace(ctx);
		tag->addAttribute(attr, ctx);
	}
	label_3_out_break: ;
	jj_consume_token(GT, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case br:
		case link:
		case meta:
		case col:
		case param:
		case base:
		case area:
		case hr:
		case input:
		case GT:
		case LT:
		case GT_SLASH:
		case EQUALS:
		case XML_HEADER_END:
		case COMMENT:
		case WHITE_SPACE:
		case STRING_LITERAL:
		case SQ_STRING_LITERAL:
		case IDENTIFIER:
		case HTML_BODY_STRING:
		case 30:
		case 31:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,7, ctx);
			goto label_4_out_break;
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case br:
		case link:
		case meta:
		case col:
		case param:
		case base:
		case area:
		case hr:
		case input:
		case GT:
		case GT_SLASH:
		case EQUALS:
		case XML_HEADER_END:
		case WHITE_SPACE:
		case STRING_LITERAL:
		case SQ_STRING_LITERAL:
		case IDENTIFIER:
		case HTML_BODY_STRING:
		case 30:
		case 31:
			{
				element = bodyText(ctx);
				break ;
			}
		case LT:
			{
				element = tagObject(ctx);
				break ;
			}
		case COMMENT:
			{
				element = comment(ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,8, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		tag->addInnerElement(element, ctx);
	}
	label_4_out_break: ;
	jj_consume_token(LT_SLASH, ctx);
	skipWhiteSpace(ctx);
	t = jj_consume_token(IDENTIFIER, ctx);
	skipWhiteSpace(ctx);
	end = jj_consume_token(GT, ctx);
	tag->setTagName(t->image, ctx);
	tag->position(start, end, ctx);
	{
		{
			return tag;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
void HtmlXmlParser::singleTagObjectLookAhead(ThreadContext* ctx)
{
	jj_consume_token(LT, ctx);
	skipWhiteSpace(ctx);
	jj_consume_token(IDENTIFIER, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case WHITE_SPACE:
		case IDENTIFIER:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,9, ctx);
			goto label_5_out_break;
		}
		skipWhiteSpace(ctx);
		attribute(ctx);
		skipWhiteSpace(ctx);
	}
	label_5_out_break: ;
	jj_consume_token(GT_SLASH, ctx);
}
XMLTagBase* HtmlXmlParser::singleTagObject(ThreadContext* ctx)
{
	XMLTagBase* tag = (new(ctx) XMLTagBase(ctx));
	Token* start = nullptr;
	Token* t = nullptr;
	Token* end = nullptr;
	XHtmlAttribute* attr = nullptr;
	start = jj_consume_token(LT, ctx);
	skipWhiteSpace(ctx);
	t = jj_consume_token(IDENTIFIER, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case WHITE_SPACE:
		case IDENTIFIER:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,10, ctx);
			goto label_6_out_break;
		}
		skipWhiteSpace(ctx);
		attr = attribute(ctx);
		skipWhiteSpace(ctx);
		tag->addAttribute(attr, ctx);
	}
	label_6_out_break: ;
	end = jj_consume_token(GT_SLASH, ctx);
	tag->setTagName(t->image, ctx);
	tag->position(start, end, ctx);
	{
		{
			return tag;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XMLTagBase* HtmlXmlParser::htmlSingleTagObject(ThreadContext* ctx)
{
	XMLTagBase* tag = (new(ctx) XMLTagBase(ctx));
	Token* start = nullptr;
	Token* t = nullptr;
	Token* end = nullptr;
	XHtmlAttribute* attr = nullptr;
	start = jj_consume_token(LT, ctx);
	skipWhiteSpace(ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case br:
		{
			t = jj_consume_token(br, ctx);
			break ;
		}
	case link:
		{
			t = jj_consume_token(link, ctx);
			break ;
		}
	case meta:
		{
			t = jj_consume_token(meta, ctx);
			break ;
		}
	case col:
		{
			t = jj_consume_token(col, ctx);
			break ;
		}
	case param:
		{
			t = jj_consume_token(param, ctx);
			break ;
		}
	case base:
		{
			t = jj_consume_token(base, ctx);
			break ;
		}
	case area:
		{
			t = jj_consume_token(area, ctx);
			break ;
		}
	case hr:
		{
			t = jj_consume_token(hr, ctx);
			break ;
		}
	case input:
		{
			t = jj_consume_token(input, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,11, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	while(true)
	{
		if(jj_2_3((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_7_out_break;
		}
		skipWhiteSpace(ctx);
		attr = attribute(ctx);
		tag->addAttribute(attr, ctx);
	}
	label_7_out_break: ;
	skipWhiteSpace(ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case GT:
		{
			end = jj_consume_token(GT, ctx);
			break ;
		}
	case GT_SLASH:
		{
			end = jj_consume_token(GT_SLASH, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,12, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	tag->setTagName(t->image, ctx);
	tag->position(start, end, ctx);
	{
		{
			return tag;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XHtmlAttribute* HtmlXmlParser::attribute(ThreadContext* ctx)
{
	XHtmlAttribute* attr = (new(ctx) XHtmlAttribute(ctx));
	Token* t = nullptr;
	Token* lit = nullptr;
	AbstractXHtmlAttributeValue* value = nullptr;
	t = jj_consume_token(IDENTIFIER, ctx);
	skipWhiteSpace(ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case EQUALS:
		{
			jj_consume_token(EQUALS, ctx);
			skipWhiteSpace(ctx);
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case STRING_LITERAL:
				{
					lit = jj_consume_token(STRING_LITERAL, ctx);
					value = (new(ctx) XHtmlDqString(ctx));
					value->position(lit, lit, ctx);
					value->setValue(lit->image, ctx);
					attr->setValue(value, ctx);
					break ;
				}
			case SQ_STRING_LITERAL:
				{
					lit = jj_consume_token(SQ_STRING_LITERAL, ctx);
					value = (new(ctx) XHtmlSQString(ctx));
					value->position(lit, lit, ctx);
					value->setValue(lit->image, ctx);
					attr->setValue(value, ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,13, ctx);
				jj_consume_token((long long)-1, ctx);
				throw (new(ctx) ParseException(ctx));
				break;
			}
			break ;
		}
	default:
		jj_la1->set(jj_gen,14, ctx);
		;
		break;
	}
	attr->setName(t->image, ctx);
	if(lit != nullptr)
	{
		attr->position(t, lit, ctx);
	}
		else 
	{
		attr->position(t, t, ctx);
	}
	{
		{
			return attr;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
void HtmlXmlParser::skipWhiteSpace(ThreadContext* ctx)
{
	while(true)
	{
		if(jj_2_4((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_8_out_break;
		}
		jj_consume_token(WHITE_SPACE, ctx);
	}
	label_8_out_break: ;
}
void HtmlXmlParser::skipWhiteSpace2(ThreadContext* ctx)
{
	while(true)
	{
		jj_consume_token(WHITE_SPACE, ctx);
		if(jj_2_5((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_9_out_break;
		}
	}
	label_9_out_break: ;
}
BodyText* HtmlXmlParser::bodyText(ThreadContext* ctx)
{
	BodyText* text = (new(ctx) BodyText(ctx));
	Token* t = nullptr;
	Token* firstToken = nullptr;
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case HTML_BODY_STRING:
			{
				t = jj_consume_token(HTML_BODY_STRING, ctx);
				break ;
			}
		case WHITE_SPACE:
			{
				t = jj_consume_token(WHITE_SPACE, ctx);
				break ;
			}
		case STRING_LITERAL:
			{
				t = jj_consume_token(STRING_LITERAL, ctx);
				break ;
			}
		case SQ_STRING_LITERAL:
			{
				t = jj_consume_token(SQ_STRING_LITERAL, ctx);
				break ;
			}
		case IDENTIFIER:
			{
				t = jj_consume_token(IDENTIFIER, ctx);
				break ;
			}
		case 30:
			{
				t = jj_consume_token((long long)30, ctx);
				break ;
			}
		case 31:
			{
				t = jj_consume_token((long long)31, ctx);
				break ;
			}
		case GT:
			{
				t = jj_consume_token(GT, ctx);
				break ;
			}
		case GT_SLASH:
			{
				t = jj_consume_token(GT_SLASH, ctx);
				break ;
			}
		case XML_HEADER_END:
			{
				t = jj_consume_token(XML_HEADER_END, ctx);
				break ;
			}
		case EQUALS:
			{
				t = jj_consume_token(EQUALS, ctx);
				break ;
			}
		case br:
			{
				t = jj_consume_token(br, ctx);
				break ;
			}
		case link:
			{
				t = jj_consume_token(link, ctx);
				break ;
			}
		case meta:
			{
				t = jj_consume_token(meta, ctx);
				break ;
			}
		case col:
			{
				t = jj_consume_token(col, ctx);
				break ;
			}
		case param:
			{
				t = jj_consume_token(param, ctx);
				break ;
			}
		case base:
			{
				t = jj_consume_token(base, ctx);
				break ;
			}
		case area:
			{
				t = jj_consume_token(area, ctx);
				break ;
			}
		case hr:
			{
				t = jj_consume_token(hr, ctx);
				break ;
			}
		case input:
			{
				t = jj_consume_token(input, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,15, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		if(firstToken == nullptr)
		{
			firstToken = t;
		}
		text->addString(t, ctx);
		if(jj_2_6((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_10_out_break;
		}
	}
	label_10_out_break: ;
	text->position(firstToken, t, ctx);
	text->finishAdd(ctx);
	{
		{
			return text;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
void HtmlXmlParser::ReInit(java::io::InputStream* stream, ThreadContext* ctx)
{
	ReInit(stream, nullptr, ctx);
}
void HtmlXmlParser::ReInit(java::io::InputStream* stream, String* encoding, ThreadContext* ctx)
{
	{
		try
		{
			jj_input_stream->ReInit(stream, encoding, 1, 1, ctx);
		}
		catch(java::io::UnsupportedEncodingException* e)
		{
			throw (new(ctx) RuntimeException(e, ctx));
		}
	}
	token_source->ReInit(jj_input_stream, ctx);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)16; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) HtmlXmlParser::JJCalls(ctx)),i, ctx);
}
void HtmlXmlParser::ReInit(java::io::Reader* stream, ThreadContext* ctx)
{
	jj_input_stream->ReInit(stream, 1, 1, ctx);
	token_source->ReInit(jj_input_stream, ctx);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)16; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) HtmlXmlParser::JJCalls(ctx)),i, ctx);
}
void HtmlXmlParser::ReInit(HtmlXmlParserTokenManager* tm, ThreadContext* ctx)
{
	__GC_MV(this, &(token_source), tm, HtmlXmlParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)16; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) HtmlXmlParser::JJCalls(ctx)),i, ctx);
}
Token* HtmlXmlParser::getNextToken(ThreadContext* ctx)
{
	if(token->next != nullptr)
	{
		__GC_MV(this, &(token), token->next, Token);
	}
		else 
	{
		__GC_MV(this, &(token), __GC_MV(token, &(token->next), token_source->getNextToken(ctx), Token), Token);
	}
	jj_ntk = -1;
	jj_gen ++ ;
	return token;
}
Token* HtmlXmlParser::getToken(long long index, ThreadContext* ctx)
{
	Token* t = token;
	for(long long i = 0; i < index; i ++ )
	{
		if(t->next != nullptr)
		{
			t = t->next;
		}
				else 
		{
			t = __GC_MV(t, &(t->next), token_source->getNextToken(ctx), Token);
		}
	}
	return t;
}
ParseException* HtmlXmlParser::generateParseException(ThreadContext* ctx)
{
	jj_expentries->clear(ctx);
	IArrayObjectPrimitive<bool>* la1tokens = ArrayAllocatorPrimitive<bool>::allocatep(ctx, 32);
	if(jj_kind >= (long long)0)
	{
		la1tokens->set(true,jj_kind, ctx);
		jj_kind = -1;
	}
	for(long long i = 0; i < (long long)16; i ++ )
	{
		if(jj_la1->get(i) == jj_gen)
		{
			for(long long j = 0; j < (long long)32; j ++ )
			{
				if((jj_la1_0->get(i) & (1 << j)) != (long long)0)
				{
					la1tokens->set(true,j, ctx);
				}
			}
		}
	}
	for(long long i = 0; i < (long long)32; i ++ )
	{
		if(la1tokens->get(i))
		{
			__GC_MV(this, &(jj_expentry), ArrayAllocatorPrimitive<long long>::allocatep(ctx, 1), IArrayObjectPrimitive<long long>);
			jj_expentry->set(i,0, ctx);
			jj_expentries->add(jj_expentry, ctx);
		}
	}
	jj_endpos = 0;
	jj_rescan_token(ctx);
	jj_add_error_token((long long)0, (long long)0, ctx);
	IArrayObject<IArrayObjectPrimitive<long long>>* exptokseq = ArrayAllocatorPrimitive<long long>::allocatep(ctx, jj_expentries->size(ctx), 0);
	for(long long i = 0; i < (long long)jj_expentries->size(ctx); i ++ )
	{
		exptokseq->set(jj_expentries->get((int)i, ctx),i, ctx);
	}
	return (new(ctx) ParseException(token, exptokseq, tokenImage, ctx));
}
void HtmlXmlParser::enable_tracing(ThreadContext* ctx)
{
}
void HtmlXmlParser::disable_tracing(ThreadContext* ctx)
{
}
bool HtmlXmlParser::jj_2_1(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)0, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_1(ctx);
		}
		catch(HtmlXmlParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool HtmlXmlParser::jj_2_2(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)1, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_2(ctx);
		}
		catch(HtmlXmlParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool HtmlXmlParser::jj_2_3(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)2, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_3(ctx);
		}
		catch(HtmlXmlParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool HtmlXmlParser::jj_2_4(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)3, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_4(ctx);
		}
		catch(HtmlXmlParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool HtmlXmlParser::jj_2_5(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)4, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_5(ctx);
		}
		catch(HtmlXmlParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool HtmlXmlParser::jj_2_6(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)5, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_6(ctx);
		}
		catch(HtmlXmlParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool HtmlXmlParser::jj_3R_18(ThreadContext* ctx)
{
	if(jj_scan_token(SQ_STRING_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool HtmlXmlParser::jj_3R_15(ThreadContext* ctx)
{
	if(jj_3R_13(ctx))
	{
		return true;
	}
	if(jj_3R_14(ctx))
	{
		return true;
	}
	if(jj_3R_13(ctx))
	{
		return true;
	}
	return false;
}
bool HtmlXmlParser::jj_3R_14(ThreadContext* ctx)
{
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	if(jj_3R_13(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_16(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool HtmlXmlParser::jj_3_5(ThreadContext* ctx)
{
	if(jj_scan_token(WHITE_SPACE, ctx))
	{
		return true;
	}
	return false;
}
bool HtmlXmlParser::jj_3_2(ThreadContext* ctx)
{
	if(jj_3R_12(ctx))
	{
		return true;
	}
	return false;
}
bool HtmlXmlParser::jj_3R_17(ThreadContext* ctx)
{
	if(jj_scan_token(STRING_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool HtmlXmlParser::jj_3_3(ThreadContext* ctx)
{
	if(jj_3R_13(ctx))
	{
		return true;
	}
	if(jj_3R_14(ctx))
	{
		return true;
	}
	return false;
}
bool HtmlXmlParser::jj_3_4(ThreadContext* ctx)
{
	if(jj_scan_token(WHITE_SPACE, ctx))
	{
		return true;
	}
	return false;
}
bool HtmlXmlParser::jj_3R_13(ThreadContext* ctx)
{
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_4(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool HtmlXmlParser::jj_3R_12(ThreadContext* ctx)
{
	if(jj_scan_token(LT, ctx))
	{
		return true;
	}
	if(jj_3R_13(ctx))
	{
		return true;
	}
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_15(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	if(jj_scan_token(GT_SLASH, ctx))
	{
		return true;
	}
	return false;
}
bool HtmlXmlParser::jj_3R_11(ThreadContext* ctx)
{
	if(jj_scan_token(LT, ctx))
	{
		return true;
	}
	if(jj_3R_13(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)1, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)3, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)4, ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_scan_token((long long)5, ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_scan_token((long long)6, ctx))
					{
						__GC_MV(this, &(jj_scanpos), xsp, Token);
						if(jj_scan_token((long long)7, ctx))
						{
							__GC_MV(this, &(jj_scanpos), xsp, Token);
							if(jj_scan_token((long long)8, ctx))
							{
								__GC_MV(this, &(jj_scanpos), xsp, Token);
								if(jj_scan_token((long long)9, ctx))
								{
									__GC_MV(this, &(jj_scanpos), xsp, Token);
									if(jj_scan_token((long long)10, ctx))
									{
										return true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_3(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	if(jj_3R_13(ctx))
	{
		return true;
	}
	xsp = jj_scanpos;
	if(jj_scan_token((long long)11, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)14, ctx))
		{
			return true;
		}
	}
	return false;
}
bool HtmlXmlParser::jj_3R_16(ThreadContext* ctx)
{
	if(jj_scan_token(EQUALS, ctx))
	{
		return true;
	}
	if(jj_3R_13(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_17(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_18(ctx))
		{
			return true;
		}
	}
	return false;
}
bool HtmlXmlParser::jj_3_1(ThreadContext* ctx)
{
	if(jj_3R_11(ctx))
	{
		return true;
	}
	return false;
}
bool HtmlXmlParser::jj_3_6(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)29, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)24, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)25, ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_scan_token((long long)26, ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_scan_token((long long)28, ctx))
					{
						__GC_MV(this, &(jj_scanpos), xsp, Token);
						if(jj_scan_token((long long)30, ctx))
						{
							__GC_MV(this, &(jj_scanpos), xsp, Token);
							if(jj_scan_token((long long)31, ctx))
							{
								__GC_MV(this, &(jj_scanpos), xsp, Token);
								if(jj_scan_token((long long)11, ctx))
								{
									__GC_MV(this, &(jj_scanpos), xsp, Token);
									if(jj_scan_token((long long)14, ctx))
									{
										__GC_MV(this, &(jj_scanpos), xsp, Token);
										if(jj_scan_token((long long)19, ctx))
										{
											__GC_MV(this, &(jj_scanpos), xsp, Token);
											if(jj_scan_token((long long)15, ctx))
											{
												__GC_MV(this, &(jj_scanpos), xsp, Token);
												if(jj_scan_token((long long)1, ctx))
												{
													__GC_MV(this, &(jj_scanpos), xsp, Token);
													if(jj_scan_token((long long)3, ctx))
													{
														__GC_MV(this, &(jj_scanpos), xsp, Token);
														if(jj_scan_token((long long)4, ctx))
														{
															__GC_MV(this, &(jj_scanpos), xsp, Token);
															if(jj_scan_token((long long)5, ctx))
															{
																__GC_MV(this, &(jj_scanpos), xsp, Token);
																if(jj_scan_token((long long)6, ctx))
																{
																	__GC_MV(this, &(jj_scanpos), xsp, Token);
																	if(jj_scan_token((long long)7, ctx))
																	{
																		__GC_MV(this, &(jj_scanpos), xsp, Token);
																		if(jj_scan_token((long long)8, ctx))
																		{
																			__GC_MV(this, &(jj_scanpos), xsp, Token);
																			if(jj_scan_token((long long)9, ctx))
																			{
																				__GC_MV(this, &(jj_scanpos), xsp, Token);
																				if(jj_scan_token((long long)10, ctx))
																				{
																					return true;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}
Token* HtmlXmlParser::jj_consume_token(long long kind, ThreadContext* ctx)
{
	Token* oldToken = 0;
	oldToken = token;
	if((oldToken)->next != nullptr)
	{
		__GC_MV(this, &(token), token->next, Token);
	}
		else 
	{
		__GC_MV(this, &(token), __GC_MV(token, &(token->next), token_source->getNextToken(ctx), Token), Token);
	}
	jj_ntk = -1;
	if(token->kind == (int)kind)
	{
		jj_gen ++ ;
		if(++jj_gc > (long long)100)
		{
			jj_gc = 0;
			for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
			{
				HtmlXmlParser::JJCalls* c = jj_2_rtns->get(i);
				while(c != nullptr)
				{
					if(c->gen < jj_gen)
					{
						__GC_MV(c, &(c->first), nullptr, Token);
					}
					c = c->next;
				}
			}
		}
		return token;
	}
	__GC_MV(this, &(token), oldToken, Token);
	jj_kind = kind;
	throw generateParseException(ctx);
}
bool HtmlXmlParser::jj_scan_token(long long kind, ThreadContext* ctx)
{
	if(jj_scanpos == jj_lastpos)
	{
		jj_la -- ;
		if(jj_scanpos->next == nullptr)
		{
			__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), __GC_MV(jj_scanpos, &(jj_scanpos->next), token_source->getNextToken(ctx), Token), Token), Token);
		}
				else 
		{
			__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), jj_scanpos->next, Token), Token);
		}
	}
		else 
	{
		__GC_MV(this, &(jj_scanpos), jj_scanpos->next, Token);
	}
	if(jj_rescan)
	{
		long long i = 0;
		Token* tok = token;
		while(tok != nullptr && tok != jj_scanpos)
		{
			i ++ ;
			tok = tok->next;
		}
		if(tok != nullptr)
		{
			jj_add_error_token(kind, i, ctx);
		}
	}
	if(jj_scanpos->kind != (int)kind)
	{
		return true;
	}
	if(jj_la == (long long)0 && jj_scanpos == jj_lastpos)
	{
		throw jj_ls;
	}
	return false;
}
long long HtmlXmlParser::jj_ntk_f(ThreadContext* ctx)
{
	__GC_MV(this, &(jj_nt), token->next, Token);
	if((jj_nt) == nullptr)
	{
		return (jj_ntk = (__GC_MV(token, &(token->next), token_source->getNextToken(ctx), Token))->kind);
	}
		else 
	{
		return (jj_ntk = jj_nt->kind);
	}
}
void HtmlXmlParser::jj_add_error_token(long long kind, long long pos, ThreadContext* ctx)
{
	if(pos >= (long long)100)
	{
		return;
	}
	if(pos == jj_endpos + 1)
	{
		jj_lasttokens->set(kind,jj_endpos++, ctx);
	}
		else 
	{
		if(jj_endpos != (long long)0)
		{
			__GC_MV(this, &(jj_expentry), ArrayAllocatorPrimitive<long long>::allocatep(ctx, jj_endpos), IArrayObjectPrimitive<long long>);
			for(long long i = 0; i < jj_endpos; i ++ )
			{
				jj_expentry->set(jj_lasttokens->get(i),i, ctx);
			}
			for(java::util::Iterator<IArrayObjectPrimitive<long long>>* it = jj_expentries->iterator(ctx); it->hasNext(ctx); )
			{
				jj_entries_loop_continue:
				IArrayObjectPrimitive<long long>* oldentry = ((IArrayObjectPrimitive<long long>*)(it->next(ctx)));
				if(oldentry->length == jj_expentry->length)
				{
					for(long long i = 0; i < (long long)jj_expentry->length; i ++ )
					{
						if(oldentry->get(i) != jj_expentry->get(i))
						{
							if(!it->hasNext(ctx)){
								goto jj_entries_loop_out_break;
							}
							goto jj_entries_loop_continue;
						}
					}
					jj_expentries->add(jj_expentry, ctx);
					goto jj_entries_loop_out_break;
				}
			}
			jj_entries_loop_out_break: ;
			if(pos != (long long)0)
			{
				jj_endpos = pos;
				jj_lasttokens->set(kind,(jj_endpos) - 1, ctx);
			}
		}
	}
}
void HtmlXmlParser::jj_rescan_token(ThreadContext* ctx)
{
	jj_rescan = true;
	for(long long i = 0; i < (long long)6; i ++ )
	{
		{
			try
			{
				HtmlXmlParser::JJCalls* p = jj_2_rtns->get(i);
				do
				{
					if(p->gen > jj_gen)
					{
						jj_la = p->arg;
						__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), p->first, Token), Token);
						switch(i) {
						case 0:
							jj_3_1(ctx);
							break ;
						case 1:
							jj_3_2(ctx);
							break ;
						case 2:
							jj_3_3(ctx);
							break ;
						case 3:
							jj_3_4(ctx);
							break ;
						case 4:
							jj_3_5(ctx);
							break ;
						case 5:
							jj_3_6(ctx);
							break ;
						}
					}
					p = p->next;
				}
				while(p != nullptr);
			}
			catch(HtmlXmlParser::LookaheadSuccess* ls)
			{
			}
		}
	}
	jj_rescan = false;
}
void HtmlXmlParser::jj_save(long long index, long long xla, ThreadContext* ctx)
{
	HtmlXmlParser::JJCalls* p = jj_2_rtns->get(index);
	while(p->gen > jj_gen)
	{
		if(p->next == nullptr)
		{
			p = __GC_MV(p, &(p->next), (new(ctx) HtmlXmlParser::JJCalls(ctx)), HtmlXmlParser::JJCalls);
			break ;
		}
		p = p->next;
	}
	p->gen = jj_gen + xla - jj_la;
	__GC_MV(p, &(p->first), token, Token);
	p->arg = xla;
}
void HtmlXmlParser::jj_la1_init_0(ThreadContext* ctx)
{
	__GC_MV(nullptr, &(jj_la1_0), ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({0x100000, 0xf748dffa, 0xf748dffa, 0x13000000, 0x13000000, 0x1000, 0x11000000, 0xf748dffa, 0xf748dffa, 0x11000000, 0x11000000, 0x7fa, 0x4800, 0x6000000, 0x8000, 0xf708cffa}, ctx)), IArrayObjectPrimitive<long long>);
}
}}}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {





bool HtmlXmlParser::LookaheadSuccess::__init_done = __init_static_variables();
bool HtmlXmlParser::LookaheadSuccess::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HtmlXmlParser::LookaheadSuccess", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HtmlXmlParser::LookaheadSuccess::~LookaheadSuccess() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HtmlXmlParser::LookaheadSuccess::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	java::lang::Error::__releaseRegerences(true, ctx);
}
}}}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {





bool HtmlXmlParser::JJCalls::__init_done = __init_static_variables();
bool HtmlXmlParser::JJCalls::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HtmlXmlParser::JJCalls", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HtmlXmlParser::JJCalls::~JJCalls() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HtmlXmlParser::JJCalls::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JJCalls", L"~JJCalls");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->next, this);
	next = nullptr;
	if(!prepare){
		return;
	}
}
}}}}

