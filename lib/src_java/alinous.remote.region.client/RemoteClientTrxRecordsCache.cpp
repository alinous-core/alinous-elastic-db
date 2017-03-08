#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.btree/LongKey.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.remote.region.client/RemoteClientTrxRecordsCache.h"

namespace alinous {namespace remote {namespace region {namespace client {





bool RemoteClientTrxRecordsCache::__init_done = __init_static_variables();
bool RemoteClientTrxRecordsCache::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteClientTrxRecordsCache", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteClientTrxRecordsCache::RemoteClientTrxRecordsCache(ThreadContext* ctx) throw()  : IObject(ctx), TrxRecordsCache(ctx)
{
}
void RemoteClientTrxRecordsCache::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteClientTrxRecordsCache::~RemoteClientTrxRecordsCache() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteClientTrxRecordsCache::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	TrxRecordsCache::__releaseRegerences(true, ctx);
}
bool RemoteClientTrxRecordsCache::commitUpdateRecord(AlinousDatabase* db, IDatabaseTable* table, long long newCommitId, ThreadContext* ctx)
{
	return TrxRecordsCache::commitUpdateRecord(db, table, newCommitId, ctx);
}
bool RemoteClientTrxRecordsCache::commitInsertRecord(DbTransaction* trx, AlinousDatabase* db, IDatabaseTable* table, long long newCommitId, ThreadContext* ctx)
{
	ArrayList<IDatabaseRecord>* list = (new(ctx) ArrayList<IDatabaseRecord>(ctx));
	BTreeScanner* scanner = (new(ctx) BTreeScanner(this->storage, ctx));
	scanner->startScan(false, ctx);
	while(scanner->hasNext(ctx))
	{
		IBTreeNode* lnode = scanner->next(ctx);
		ArrayList<IBTreeValue>* values = lnode->getValues(ctx);
		CachedRecord* record = static_cast<CachedRecord*>(values->get(0, ctx));
		list->add(record, ctx);
	}
	scanner->endScan(ctx);
	if(list->isEmpty(ctx))
	{
		return false;
	}
	table->insertData(this->trx, list, newCommitId, nullptr, this->trx->getLogger(ctx), ctx);
	return true;
}
void RemoteClientTrxRecordsCache::__cleanUp(ThreadContext* ctx){
}
}}}}

