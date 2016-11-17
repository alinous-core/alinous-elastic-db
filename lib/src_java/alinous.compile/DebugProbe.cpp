#include "includes.h"


namespace alinous {namespace compile {





DebugProbe* DebugProbe::inst = nullptr;
bool DebugProbe::__init_done = __init_static_variables();
bool DebugProbe::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DebugProbe", L"__init_static_variables");
		__GC_MV(nullptr, &(inst), nullptr, DebugProbe);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DebugProbe::~DebugProbe() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DebugProbe::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DebugProbe", L"~DebugProbe");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
DebugProbeSection* DebugProbe::start(String* name, ThreadContext* ctx) throw() 
{
	DebugProbeSection* section = (new(ctx) DebugProbeSection(name, ctx));
	this->list->add(section, ctx);
	section->start(ctx);
	return section;
}
void DebugProbe::print(ThreadContext* ctx) throw() 
{
	Iterator<DebugProbeSection>* it = this->list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		DebugProbeSection* sec = it->next(ctx);
		if(sec != nullptr)
		{
			sec->print(ctx);
		}
	}
}
DebugProbe* DebugProbe::getInstance(ThreadContext* ctx) throw() 
{
	if(inst == nullptr)
	{
		__GC_MV(nullptr, &(inst), (new(ctx) DebugProbe(ctx)), DebugProbe);
	}
	return inst;
}
}}

