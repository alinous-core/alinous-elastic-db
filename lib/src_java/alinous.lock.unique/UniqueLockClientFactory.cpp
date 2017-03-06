#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.lock.unique/UniqueExclusiveException.h"
#include "alinous.lock.unique/ColumnsUniqueCollections.h"
#include "alinous.lock.unique/TableUniqueCollections.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.lock.unique/UniqueLockClientFactory.h"

namespace alinous {namespace lock {namespace unique {





bool UniqueLockClientFactory::__init_done = __init_static_variables();
bool UniqueLockClientFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueLockClientFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueLockClientFactory::UniqueLockClientFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void UniqueLockClientFactory::__construct_impl(ThreadContext* ctx) throw() 
{
}
 UniqueLockClientFactory::~UniqueLockClientFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueLockClientFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
UniqueExclusiveLockClient* UniqueLockClientFactory::createClient(UniqueExclusiveLockManager* mgr, ThreadContext* ctx) throw() 
{
	return (new(ctx) UniqueExclusiveLockClient(mgr, ctx));
}
void UniqueLockClientFactory::__cleanUp(ThreadContext* ctx){
}
}}}

