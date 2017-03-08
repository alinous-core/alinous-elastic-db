#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.trx.scan/ScanException.h"

namespace alinous {namespace db {namespace trx {namespace scan {





constexpr const long long ScanException::serialVersionUID;
bool ScanException::__init_done = __init_static_variables();
bool ScanException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanException::ScanException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), DatabaseException(msg, ctx)
{
}
void ScanException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 ScanException::ScanException(String* msg, Throwable* cause, ThreadContext* ctx) throw()  : IObject(ctx), DatabaseException(msg, cause, ctx)
{
}
void ScanException::__construct_impl(String* msg, Throwable* cause, ThreadContext* ctx) throw() 
{
}
 ScanException::ScanException(Throwable* cause, ThreadContext* ctx) throw()  : IObject(ctx), DatabaseException(cause, ctx)
{
}
void ScanException::__construct_impl(Throwable* cause, ThreadContext* ctx) throw() 
{
}
 ScanException::~ScanException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DatabaseException::__releaseRegerences(true, ctx);
}
void ScanException::__cleanUp(ThreadContext* ctx){
}
}}}}

