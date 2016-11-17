#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {





bool DebugStackFrame::__init_done = __init_static_variables();
bool DebugStackFrame::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DebugStackFrame", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DebugStackFrame::DebugStackFrame(MainStackFrame* frame, bool peek, long long stackId, ThreadContext* ctx) throw()  : IObject(ctx), line(0), fileName(nullptr), peek(0), stackId(0), frame(nullptr)
{
	__GC_MV(this, &(this->frame), frame, MainStackFrame);
	AbstractSrcElement* src = frame->sourceElement;
	this->line = src->getLine(ctx);
	__GC_MV(this, &(this->fileName), src->getFilePath(ctx), String);
	this->peek = peek;
	this->stackId = stackId;
}
void DebugStackFrame::__construct_impl(MainStackFrame* frame, bool peek, long long stackId, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->frame), frame, MainStackFrame);
	AbstractSrcElement* src = frame->sourceElement;
	this->line = src->getLine(ctx);
	__GC_MV(this, &(this->fileName), src->getFilePath(ctx), String);
	this->peek = peek;
	this->stackId = stackId;
}
 DebugStackFrame::~DebugStackFrame() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DebugStackFrame::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DebugStackFrame", L"~DebugStackFrame");
	__e_obj1.add(this->fileName, this);
	fileName = nullptr;
	__e_obj1.add(this->frame, this);
	frame = nullptr;
	if(!prepare){
		return;
	}
}
String* DebugStackFrame::getFileName(ThreadContext* ctx) throw() 
{
	return fileName;
}
void DebugStackFrame::setFileName(String* fileName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->fileName), fileName, String);
}
int DebugStackFrame::getLine(ThreadContext* ctx) throw() 
{
	return line;
}
void DebugStackFrame::setLine(int line, ThreadContext* ctx) throw() 
{
	this->line = line;
}
bool DebugStackFrame::isPeek(ThreadContext* ctx) throw() 
{
	return peek;
}
void DebugStackFrame::setPeek(bool peek, ThreadContext* ctx) throw() 
{
	this->peek = peek;
}
long long DebugStackFrame::getStackId(ThreadContext* ctx) throw() 
{
	return stackId;
}
void DebugStackFrame::setStackId(long long stackId, ThreadContext* ctx) throw() 
{
	this->stackId = stackId;
}
MainStackFrame* DebugStackFrame::getFrame(ThreadContext* ctx) throw() 
{
	return frame;
}
}}}}

