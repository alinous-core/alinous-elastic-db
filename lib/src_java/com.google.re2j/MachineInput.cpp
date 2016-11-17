#include "includes.h"


namespace com {namespace google {namespace re2j {





constexpr const int MachineInput::_EOF;
bool MachineInput::__init_done = __init_static_variables();
bool MachineInput::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MachineInput", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MachineInput::~MachineInput() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MachineInput::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
MachineInput* MachineInput::fromUTF8(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() 
{
	return (new(ctx) UTF8Input(b, ctx));
}
MachineInput* MachineInput::fromUTF8(IArrayObjectPrimitive<char>* b, int start, int end, ThreadContext* ctx) throw() 
{
	return (new(ctx) UTF8Input(b, start, end, ctx));
}
MachineInput* MachineInput::fromUTF16(CharSequence* s, ThreadContext* ctx) throw() 
{
	return (new(ctx) UTF16Input(s, 0, s->length(ctx), ctx));
}
MachineInput* MachineInput::fromUTF16(CharSequence* s, int start, int end, ThreadContext* ctx) throw() 
{
	return (new(ctx) UTF16Input(s, start, end, ctx));
}
}}}

