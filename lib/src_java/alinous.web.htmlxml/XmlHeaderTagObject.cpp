#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {





bool XmlHeaderTagObject::__init_done = __init_static_variables();
bool XmlHeaderTagObject::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XmlHeaderTagObject", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XmlHeaderTagObject::~XmlHeaderTagObject() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XmlHeaderTagObject::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}

