#include "includes.h"


namespace alinous {namespace runtime {namespace engine {





bool DebugMainFrameSrcElement::__init_done = __init_static_variables();
bool DebugMainFrameSrcElement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DebugMainFrameSrcElement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DebugMainFrameSrcElement::~DebugMainFrameSrcElement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DebugMainFrameSrcElement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DebugMainFrameSrcElement", L"~DebugMainFrameSrcElement");
	__e_obj1.add(this->filePath, this);
	filePath = nullptr;
	__e_obj1.add(this->debugFilePath, this);
	debugFilePath = nullptr;
	if(!prepare){
		return;
	}
	AbstractSrcElement::__releaseRegerences(true, ctx);
}
int DebugMainFrameSrcElement::getLine(ThreadContext* ctx) throw() 
{
	return this->line;
}
int DebugMainFrameSrcElement::getStartPosition(ThreadContext* ctx) throw() 
{
	return 0;
}
int DebugMainFrameSrcElement::getEndLine(ThreadContext* ctx) throw() 
{
	return 0;
}
int DebugMainFrameSrcElement::getEndPosition(ThreadContext* ctx) throw() 
{
	return 0;
}
AbstractSrcElement* DebugMainFrameSrcElement::getParent(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void DebugMainFrameSrcElement::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
}
String* DebugMainFrameSrcElement::getFilePath(ThreadContext* ctx) throw() 
{
	return this->filePath;
}
void DebugMainFrameSrcElement::setFilePath(String* path, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->filePath), path, String);
}
bool DebugMainFrameSrcElement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
String* DebugMainFrameSrcElement::getDebugFilePath(ThreadContext* ctx) throw() 
{
	return debugFilePath;
}
void DebugMainFrameSrcElement::setDebugFilePath(String* debugFilePath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->debugFilePath), debugFilePath, String);
}
}}}

