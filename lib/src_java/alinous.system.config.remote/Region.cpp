#include "includes.h"


namespace alinous {namespace system {namespace config {namespace remote {





bool Region::__init_done = __init_static_variables();
bool Region::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Region", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Region::~Region() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Region::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Region", L"~Region");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->url, this);
	url = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	if(!prepare){
		return;
	}
}
String* Region::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void Region::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
String* Region::getUrl(ThreadContext* ctx) throw() 
{
	return url;
}
void Region::setUrl(String* url, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->url), url, String);
}
Tables* Region::getTables(ThreadContext* ctx) throw() 
{
	return tables;
}
void Region::setTables(Tables* tables, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tables), tables, Tables);
}
Region* Region::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx) throw() 
{
	Region* reg = (new(ctx) Region(ctx));
	return reg;
}
}}}}

