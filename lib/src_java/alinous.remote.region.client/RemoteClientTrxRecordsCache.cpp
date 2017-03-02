#include "includes.h"


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
void RemoteClientTrxRecordsCache::commitInsertRecord(DbTransaction* trx, AlinousDatabase* db, IDatabaseTable* table, long long newCommitId, ThreadContext* ctx)
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
	table->insertData(this->trx, list, newCommitId, nullptr, this->trx->getLogger(ctx), ctx);
}
}}}}

