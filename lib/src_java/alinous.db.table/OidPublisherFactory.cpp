#include "include/global.h"


#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.table/OidPublisherFactory.h"

namespace alinous {namespace db {namespace table {





bool OidPublisherFactory::__init_done = __init_static_variables();
bool OidPublisherFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"OidPublisherFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 OidPublisherFactory::OidPublisherFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void OidPublisherFactory::__construct_impl(ThreadContext* ctx) throw() 
{
}
 OidPublisherFactory::~OidPublisherFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void OidPublisherFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IOidPublisher* OidPublisherFactory::create(FileStorage* storage, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void OidPublisherFactory::__cleanUp(ThreadContext* ctx){
}
}}}

