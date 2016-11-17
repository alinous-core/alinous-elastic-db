#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {





constexpr const int AlinousDebugEvent::STARTED;
constexpr const int AlinousDebugEvent::BEFORE_SENTENCE;
constexpr const int AlinousDebugEvent::BEFORE_EXPRESSION;
bool AlinousDebugEvent::__init_done = __init_static_variables();
bool AlinousDebugEvent::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDebugEvent", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDebugEvent::AlinousDebugEvent(int eventType, int line, String* filePath, String* debugFilePath, DebugThread* thread, ThreadContext* ctx) throw()  : IObject(ctx), eventType(0), line(0), filePath(nullptr), debugFilePath(nullptr), thread(nullptr)
{
	this->eventType = eventType;
	this->line = line;
	__GC_MV(this, &(this->filePath), forceUnixPath(filePath, ctx), String);
	__GC_MV(this, &(this->debugFilePath), debugFilePath, String);
	__GC_MV(this, &(this->thread), thread, DebugThread);
}
void AlinousDebugEvent::__construct_impl(int eventType, int line, String* filePath, String* debugFilePath, DebugThread* thread, ThreadContext* ctx) throw() 
{
	this->eventType = eventType;
	this->line = line;
	__GC_MV(this, &(this->filePath), forceUnixPath(filePath, ctx), String);
	__GC_MV(this, &(this->debugFilePath), debugFilePath, String);
	__GC_MV(this, &(this->thread), thread, DebugThread);
}
 AlinousDebugEvent::~AlinousDebugEvent() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDebugEvent::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDebugEvent", L"~AlinousDebugEvent");
	__e_obj1.add(this->filePath, this);
	filePath = nullptr;
	__e_obj1.add(this->debugFilePath, this);
	debugFilePath = nullptr;
	__e_obj1.add(this->thread, this);
	thread = nullptr;
	if(!prepare){
		return;
	}
}
int AlinousDebugEvent::getEventType(ThreadContext* ctx) throw() 
{
	return eventType;
}
String* AlinousDebugEvent::getFilePath(ThreadContext* ctx) throw() 
{
	return filePath;
}
int AlinousDebugEvent::getLine(ThreadContext* ctx) throw() 
{
	return line;
}
DebugThread* AlinousDebugEvent::getThread(ThreadContext* ctx) throw() 
{
	return thread;
}
String* AlinousDebugEvent::getDebugFilePath(ThreadContext* ctx) throw() 
{
	return debugFilePath;
}
String* AlinousDebugEvent::forceUnixPath(String* path, ThreadContext* ctx) throw() 
{
	if(path == nullptr)
	{
		return nullptr;
	}
	return path->replace(L'\\', L'/', ctx);
}
}}}}

