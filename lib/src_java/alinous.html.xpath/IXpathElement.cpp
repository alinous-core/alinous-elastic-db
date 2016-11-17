#include "includes.h"


namespace alinous {namespace html {namespace xpath {


constexpr EnumBase __IXpathElement__ScanPolicy::__DEFAULT_NULL;
constexpr EnumBase __IXpathElement__ScanPolicy::scan_all_inherited_children;
constexpr EnumBase __IXpathElement__ScanPolicy::scan_children;
constexpr EnumBase __IXpathElement__ScanPolicy::scan_this_only;
constexpr EnumBase __IXpathElement__ScanTarget::__DEFAULT_NULL;
constexpr EnumBase __IXpathElement__ScanTarget::node;
constexpr EnumBase __IXpathElement__ScanTarget::attribute;
constexpr EnumBase __IXpathElement__ScanTarget::value;


bool IXpathElement::__init_done = __init_static_variables();
bool IXpathElement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IXpathElement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IXpathElement::~IXpathElement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IXpathElement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}

