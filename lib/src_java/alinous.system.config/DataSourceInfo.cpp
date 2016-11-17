#include "includes.h"


namespace alinous {namespace system {namespace config {





bool DataSourceInfo::__init_done = __init_static_variables();
bool DataSourceInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DataSourceInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DataSourceInfo::~DataSourceInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DataSourceInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DataSourceInfo", L"~DataSourceInfo");
	__e_obj1.add(this->connect, this);
	connect = nullptr;
	__e_obj1.add(this->user, this);
	user = nullptr;
	__e_obj1.add(this->pass, this);
	pass = nullptr;
	if(!prepare){
		return;
	}
}
String* DataSourceInfo::getConnect(ThreadContext* ctx) throw() 
{
	return connect;
}
void DataSourceInfo::setConnect(String* connect, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->connect), connect, String);
}
String* DataSourceInfo::getUser(ThreadContext* ctx) throw() 
{
	return user;
}
void DataSourceInfo::setUser(String* user, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->user), user, String);
}
String* DataSourceInfo::getPass(ThreadContext* ctx) throw() 
{
	return pass;
}
void DataSourceInfo::setPass(String* pass, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->pass), pass, String);
}
int DataSourceInfo::getDefaultAcid(ThreadContext* ctx) throw() 
{
	return defaultAcid;
}
void DataSourceInfo::setDefaultAcid(int defaultAcid, ThreadContext* ctx) throw() 
{
	this->defaultAcid = defaultAcid;
}
}}}

