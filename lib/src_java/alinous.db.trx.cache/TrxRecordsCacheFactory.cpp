#include "includes.h"


namespace alinous {namespace db {namespace trx {namespace cache {





bool TrxRecordsCacheFactory::__init_done = __init_static_variables();
bool TrxRecordsCacheFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxRecordsCacheFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxRecordsCacheFactory::~TrxRecordsCacheFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxRecordsCacheFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
TrxRecordsCache* TrxRecordsCacheFactory::createCache(String* tmpDir, String* schema, String* tableName, TableMetadata* metadata, DbTransaction* trx, bool insert, ThreadContext* ctx)
{
	if(!trx->isRemote(ctx))
	{
		TrxRecordsCache* cache = (new(ctx) TrxRecordsCache(ctx))->init(tmpDir, schema, tableName, metadata, trx, true, ctx);
		return cache;
	}
	TrxRecordsCache* cache = (new(ctx) RemoteClientTrxRecordsCache(ctx))->init(tmpDir, schema, tableName, metadata, trx, true, ctx);
	return cache;
}
}}}}

