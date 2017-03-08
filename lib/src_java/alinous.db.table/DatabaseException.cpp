#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"

namespace alinous {namespace db {namespace table {





constexpr const long long DatabaseException::serialVersionUID;
bool DatabaseException::__init_done = __init_static_variables();
bool DatabaseException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseException::DatabaseException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), Throwable(msg, ctx)
{
}
void DatabaseException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 DatabaseException::DatabaseException(String* msg, Throwable* cause, ThreadContext* ctx) throw()  : IObject(ctx), Throwable(msg, cause, ctx)
{
}
void DatabaseException::__construct_impl(String* msg, Throwable* cause, ThreadContext* ctx) throw() 
{
}
 DatabaseException::DatabaseException(Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), Throwable(e, ctx)
{
}
void DatabaseException::__construct_impl(Throwable* e, ThreadContext* ctx) throw() 
{
}
 DatabaseException::~DatabaseException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	Throwable::__releaseRegerences(true, ctx);
}
void DatabaseException::__cleanUp(ThreadContext* ctx){
}
}}}

