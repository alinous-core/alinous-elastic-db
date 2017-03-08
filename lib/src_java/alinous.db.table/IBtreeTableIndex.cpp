#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/IBtreeTableIndex.h"

namespace alinous {namespace db {namespace table {




bool IBtreeTableIndex::__init_done = __init_static_variables();
bool IBtreeTableIndex::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IBtreeTableIndex", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IBtreeTableIndex::IBtreeTableIndex(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IBtreeTableIndex::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IBtreeTableIndex::~IBtreeTableIndex() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IBtreeTableIndex::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IBtreeTableIndex::__cleanUp(ThreadContext* ctx){
}
}}}

