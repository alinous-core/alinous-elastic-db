#include "includes.h"


namespace alinous {namespace html {namespace xpath {



constexpr EnumBase __XpathContextLocationCtrl__CtrlType::__DEFAULT_NULL;
constexpr EnumBase __XpathContextLocationCtrl__CtrlType::current;
constexpr EnumBase __XpathContextLocationCtrl__CtrlType::parent;
constexpr EnumBase __XpathContextLocationCtrl__CtrlType::children;
constexpr EnumBase __XpathContextLocationCtrl__CtrlType::all;


bool XpathContextLocationCtrl::__init_done = __init_static_variables();
bool XpathContextLocationCtrl::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathContextLocationCtrl", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathContextLocationCtrl::XpathContextLocationCtrl(XpathContextLocationCtrl::CtrlType type, ThreadContext* ctx) throw()  : IObject(ctx)
{
	this->type = type;
}
void XpathContextLocationCtrl::__construct_impl(XpathContextLocationCtrl::CtrlType type, ThreadContext* ctx) throw() 
{
	this->type = type;
}
 XpathContextLocationCtrl::~XpathContextLocationCtrl() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathContextLocationCtrl::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathContextLocationCtrl", L"~XpathContextLocationCtrl");
	if(!prepare){
		return;
	}
}
XpathContextLocationCtrl::CtrlType XpathContextLocationCtrl::getType(ThreadContext* ctx) throw() 
{
	return type;
}
String* XpathContextLocationCtrl::toString(ThreadContext* ctx) throw() 
{
	switch(this->type) {
	case XpathContextLocationCtrl::CtrlType::all:
		return ConstStr::getCNST_STR_1785();
	case XpathContextLocationCtrl::CtrlType::current:
		return ConstStr::getCNST_STR_950();
	case XpathContextLocationCtrl::CtrlType::parent:
		return ConstStr::getCNST_STR_1244();
	case XpathContextLocationCtrl::CtrlType::children:
		return ConstStr::getCNST_STR_1007();
	default:
		break ;
	}
	return nullptr;
}
}}}

