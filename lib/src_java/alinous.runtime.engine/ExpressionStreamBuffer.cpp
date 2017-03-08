#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ExpressionStreamBuffer.h"

namespace alinous {namespace runtime {namespace engine {





bool ExpressionStreamBuffer::__init_done = __init_static_variables();
bool ExpressionStreamBuffer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ExpressionStreamBuffer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ExpressionStreamBuffer::ExpressionStreamBuffer(ThreadContext* ctx) throw()  : IObject(ctx), streamLastValue(nullptr)
{
}
void ExpressionStreamBuffer::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ExpressionStreamBuffer::~ExpressionStreamBuffer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ExpressionStreamBuffer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ExpressionStreamBuffer", L"~ExpressionStreamBuffer");
	__e_obj1.add(this->streamLastValue, this);
	streamLastValue = nullptr;
	if(!prepare){
		return;
	}
}
IAlinousVariable* ExpressionStreamBuffer::getStreamLastValue(ThreadContext* ctx) throw() 
{
	return streamLastValue;
}
void ExpressionStreamBuffer::setStreamLastValue(IAlinousVariable* streamLastValue, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->streamLastValue), streamLastValue, IAlinousVariable);
}
void ExpressionStreamBuffer::__cleanUp(ThreadContext* ctx){
}
}}}

