#include "include/global.h"


#include "alinous.compile/DebugProbeSection.h"

namespace alinous {namespace compile {





bool DebugProbeSection::__init_done = __init_static_variables();
bool DebugProbeSection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DebugProbeSection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DebugProbeSection::DebugProbeSection(ThreadContext* ctx) throw()  : IObject(ctx), name(nullptr), _start(0), _end(0)
{
}
void DebugProbeSection::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DebugProbeSection::DebugProbeSection(String* name, ThreadContext* ctx) throw()  : IObject(ctx), name(nullptr), _start(0), _end(0)
{
	__GC_MV(this, &(this->name), name, String);
}
void DebugProbeSection::__construct_impl(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
 DebugProbeSection::~DebugProbeSection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DebugProbeSection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DebugProbeSection", L"~DebugProbeSection");
	__e_obj1.add(this->name, this);
	name = nullptr;
	if(!prepare){
		return;
	}
}
void DebugProbeSection::print(ThreadContext* ctx) throw() 
{
	System::out->println(this->name->clone(ctx)->append(ConstStr::getCNST_STR_948(), ctx)->append((this->_end - this->_start), ctx)->append(ConstStr::getCNST_STR_949(), ctx), ctx);
}
void DebugProbeSection::start(ThreadContext* ctx) throw() 
{
	this->_start = System::nanoTime(ctx);
}
void DebugProbeSection::end(ThreadContext* ctx) throw() 
{
	this->_end = System::nanoTime(ctx);
}
long long DebugProbeSection::getStart(ThreadContext* ctx) throw() 
{
	return _start;
}
long long DebugProbeSection::getEnd(ThreadContext* ctx) throw() 
{
	return _end;
}
void DebugProbeSection::__cleanUp(ThreadContext* ctx){
}
}}

