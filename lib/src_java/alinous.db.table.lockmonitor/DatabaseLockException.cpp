#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"

namespace alinous {namespace db {namespace table {namespace lockmonitor {





constexpr const long long DatabaseLockException::serialVersionUID;
bool DatabaseLockException::__init_done = __init_static_variables();
bool DatabaseLockException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseLockException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseLockException::DatabaseLockException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), DatabaseException(msg, ctx)
{
}
void DatabaseLockException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 DatabaseLockException::DatabaseLockException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), DatabaseException(msg, e, ctx)
{
}
void DatabaseLockException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 DatabaseLockException::~DatabaseLockException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseLockException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DatabaseException::__releaseRegerences(true, ctx);
}
void DatabaseLockException::__cleanUp(ThreadContext* ctx){
}
}}}}

