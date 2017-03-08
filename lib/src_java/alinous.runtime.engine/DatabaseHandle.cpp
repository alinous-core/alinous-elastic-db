#include "include/global.h"


#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.runtime.engine/DatabaseHandle.h"

namespace alinous {namespace runtime {namespace engine {





bool DatabaseHandle::__init_done = __init_static_variables();
bool DatabaseHandle::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseHandle", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseHandle::DatabaseHandle(IDatabaseDriver* dbdriver, IDatabaseConnection* con, ThreadContext* ctx) throw()  : IObject(ctx), dbdriver(nullptr), con(nullptr)
{
	__GC_MV(this, &(this->dbdriver), dbdriver, IDatabaseDriver);
	__GC_MV(this, &(this->con), con, IDatabaseConnection);
}
void DatabaseHandle::__construct_impl(IDatabaseDriver* dbdriver, IDatabaseConnection* con, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->dbdriver), dbdriver, IDatabaseDriver);
	__GC_MV(this, &(this->con), con, IDatabaseConnection);
}
 DatabaseHandle::~DatabaseHandle() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseHandle::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DatabaseHandle", L"~DatabaseHandle");
	__e_obj1.add(this->dbdriver, this);
	dbdriver = nullptr;
	__e_obj1.add(this->con, this);
	con = nullptr;
	if(!prepare){
		return;
	}
}
IDatabaseDriver* DatabaseHandle::getDbdriver(ThreadContext* ctx) throw() 
{
	return dbdriver;
}
void DatabaseHandle::setDbdriver(IDatabaseDriver* dbdriver, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->dbdriver), dbdriver, IDatabaseDriver);
}
IDatabaseConnection* DatabaseHandle::getCon(ThreadContext* ctx) throw() 
{
	return con;
}
void DatabaseHandle::setCon(IDatabaseConnection* con, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->con), con, IDatabaseConnection);
}
void DatabaseHandle::__cleanUp(ThreadContext* ctx){
}
}}}

