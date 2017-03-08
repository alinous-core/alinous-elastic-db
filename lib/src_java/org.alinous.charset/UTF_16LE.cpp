#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"
#include "org.alinous.charset/UTF_16.h"
#include "org.alinous.charset/UTF_16LE.h"

namespace org {namespace alinous {namespace charset {





bool UTF_16LE::__init_done = __init_static_variables();
bool UTF_16LE::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UTF_16LE", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UTF_16LE::UTF_16LE(ThreadContext* ctx) throw()  : IObject(ctx), UTF_16(ctx)
{
}
void UTF_16LE::__construct_impl(ThreadContext* ctx) throw() 
{
}
 UTF_16LE::~UTF_16LE() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UTF_16LE::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	UTF_16::__releaseRegerences(true, ctx);
}
int UTF_16LE::getDefaultEndian(ThreadContext* ctx) throw() 
{
	return LITTLE;
}
int UTF_16LE::getDetectedEndian(int b1, int b2, ThreadContext* ctx) throw() 
{
	return (b1 == 0xFF && b2 == 0xFE) ? getDefaultEndian(ctx) : NOT_DETECTED;
}
void UTF_16LE::__cleanUp(ThreadContext* ctx){
}
}}}

