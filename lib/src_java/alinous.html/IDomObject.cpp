#include "includes.h"


namespace alinous {namespace html {




constexpr const int IDomObject::TYPE_ATTRIBUTE;
constexpr const int IDomObject::TYPE_DOM_NODE;
constexpr const int IDomObject::TYPE_DOC_TYPE;
constexpr const int IDomObject::TYPE_DOM_COMMENT;
constexpr const int IDomObject::TYPE_DOM_DOCUMENT;
constexpr const int IDomObject::TYPE_DOM_TEXT;
bool IDomObject::__init_done = __init_static_variables();
bool IDomObject::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDomObject", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDomObject::~IDomObject() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDomObject::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}

