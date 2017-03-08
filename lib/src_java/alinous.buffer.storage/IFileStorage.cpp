#include "include/global.h"


#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"

namespace alinous {namespace buffer {namespace storage {




constexpr const int IFileStorage::SIZE_LONG;
constexpr const int IFileStorage::SIZE_INT;
constexpr const int IFileStorage::SIZE_SHORT;
constexpr const int IFileStorage::SIZE_BYTE;
bool IFileStorage::__init_done = __init_static_variables();
bool IFileStorage::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IFileStorage", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IFileStorage::IFileStorage(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IFileStorage::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IFileStorage::~IFileStorage() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IFileStorage::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IFileStorage::__cleanUp(ThreadContext* ctx){
}
}}}

