#include "includes.h"


namespace alinous {namespace db {





bool ConnectInfo::__init_done = __init_static_variables();
bool ConnectInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConnectInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConnectInfo::~ConnectInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConnectInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ConnectInfo", L"~ConnectInfo");
	__e_obj1.add(this->user, this);
	user = nullptr;
	__e_obj1.add(this->pass, this);
	pass = nullptr;
	if(!prepare){
		return;
	}
}
String* ConnectInfo::getUser(ThreadContext* ctx) throw() 
{
	return user;
}
void ConnectInfo::setUser(String* user, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->user), user, String);
}
String* ConnectInfo::getPass(ThreadContext* ctx) throw() 
{
	return pass;
}
void ConnectInfo::setPass(String* pass, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->pass), pass, String);
}
}}

