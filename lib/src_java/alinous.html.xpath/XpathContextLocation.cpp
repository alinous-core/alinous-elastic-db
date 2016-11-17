#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool XpathContextLocation::__init_done = __init_static_variables();
bool XpathContextLocation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathContextLocation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathContextLocation::~XpathContextLocation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathContextLocation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathContextLocation", L"~XpathContextLocation");
	__e_obj1.add(this->ctrls, this);
	ctrls = nullptr;
	if(!prepare){
		return;
	}
}
void XpathContextLocation::addCtrl(XpathContextLocationCtrl* ctrl, ThreadContext* ctx) throw() 
{
	this->ctrls->add(ctrl, ctx);
}
void XpathContextLocation::setupLocation(MatchCursor* cursor, ThreadContext* ctx)
{
	XpathContext::ScanPolicy policy = cursor->getScanPolicy(ctx);
	Iterator<XpathContextLocationCtrl>* it = this->ctrls->iterator(ctx);
	while(it->hasNext(ctx))
	{
		XpathContextLocationCtrl* ctrl = it->next(ctx);
		XpathContextLocationCtrl::CtrlType type = ctrl->getType(ctx);
		switch(type) {
		case XpathContextLocationCtrl::CtrlType::all:
			policy = XpathContext::ScanPolicy::scan_all_inherited_children;
			break ;
		case XpathContextLocationCtrl::CtrlType::children:
			policy = XpathContext::ScanPolicy::scan_children;
			break ;
		case XpathContextLocationCtrl::CtrlType::current:
			policy = XpathContext::ScanPolicy::scan_this_only;
			break ;
		case XpathContextLocationCtrl::CtrlType::parent:
			cursor->gotoParent(ctx);
			break ;
		default:
			break ;
		}
	}
	cursor->caluculateScanPolicy(policy, ctx);
}
String* XpathContextLocation::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	Iterator<XpathContextLocationCtrl>* it = this->ctrls->iterator(ctx);
	while(it->hasNext(ctx))
	{
		buff->append(it->next(ctx)->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
}}}

