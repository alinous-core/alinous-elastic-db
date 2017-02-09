#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





bool FileBreakpointContainer::__init_done = __init_static_variables();
bool FileBreakpointContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileBreakpointContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileBreakpointContainer::~FileBreakpointContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileBreakpointContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileBreakpointContainer", L"~FileBreakpointContainer");
	__e_obj1.add(this->breakpoints, this);
	breakpoints = nullptr;
	if(!prepare){
		return;
	}
}
void FileBreakpointContainer::addBreakpoint(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw() 
{
	this->breakpoints->add(breakpoint, ctx);
}
void FileBreakpointContainer::removeBreakpoint(int line, ThreadContext* ctx) throw() 
{
	Iterator<ServerBreakPoint>* it = this->breakpoints->iterator(ctx);
	while(it->hasNext(ctx))
	{
		ServerBreakPoint* breakPoint = it->next(ctx);
		if(breakPoint->getLine(ctx) == line)
		{
			it->remove(ctx);
		}
	}
}
Iterator<ServerBreakPoint>* FileBreakpointContainer::iterator(ThreadContext* ctx) throw() 
{
	return this->breakpoints->iterator(ctx);
}
void FileBreakpointContainer::clear(ThreadContext* ctx) throw() 
{
	this->breakpoints->clear(ctx);
}
String* FileBreakpointContainer::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	Iterator<ServerBreakPoint>* it = this->breakpoints->iterator(ctx);
	while(it->hasNext(ctx))
	{
		ServerBreakPoint* p = it->next(ctx);
		buff->append(p->getFilePath(ctx), ctx);
		buff->append(ConstStr::getCNST_STR_381(), ctx);
		buff->append(p->getLine(ctx), ctx);
		buff->append(ConstStr::getCNST_STR_1212(), ctx);
	}
	return buff->toString(ctx);
}
}}}}}

