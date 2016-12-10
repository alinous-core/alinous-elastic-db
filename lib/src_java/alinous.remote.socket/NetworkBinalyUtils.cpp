#include "includes.h"


namespace alinous {namespace remote {namespace socket {





bool NetworkBinalyUtils::__init_done = __init_static_variables();
bool NetworkBinalyUtils::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NetworkBinalyUtils", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NetworkBinalyUtils::~NetworkBinalyUtils() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NetworkBinalyUtils::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
int NetworkBinalyUtils::readInt(InputStream* stream, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* intbytes = ArrayAllocatorPrimitive<char>::allocatep(ctx, 4);
	stream->read(intbytes, ctx);
	ByteBuffer* buff = ByteBuffer::wrap(intbytes, ctx);
	return buff->getInt(ctx);
}
}}}

