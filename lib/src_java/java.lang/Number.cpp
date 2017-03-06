#include "include/global.h"


#include "java.lang/Boolean.h"
#include "java.lang/Comparable.h"
#include "java.lang/Number.h"
#include "java.lang/Double.h"
#include "java.lang/Integer.h"
#include "java.lang/Byte.h"
#include "java.lang/Long.h"
#include "java.lang/Float.h"
#include "java.lang/Short.h"
#include "java.lang/BinarySearch.h"

namespace java {namespace lang {





bool Number::__init_done = __init_static_variables();
bool Number::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Number", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Number::Number(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void Number::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Number::~Number() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Number::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
char Number::byteValue(ThreadContext* ctx) throw() 
{
	return ((char)intValue(ctx));
}
short Number::shortValue(ThreadContext* ctx) throw() 
{
	return ((short)intValue(ctx));
}
void Number::__cleanUp(ThreadContext* ctx){
}
}}

