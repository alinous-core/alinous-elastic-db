#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"
#include "org.alinous.charset/UTF_16.h"
#include "org.alinous.charset/UTF_16BE.h"
#include "org.alinous.charset/CP_1254.h"
#include "org.alinous.charset/ISO_8859_7.h"
#include "org.alinous.charset/ISO_8859_5.h"
#include "org.alinous.charset/US_ASCII.h"
#include "org.alinous.charset/CP_1250.h"
#include "org.alinous.charset/CP_1251.h"
#include "org.alinous.charset/CP_1252.h"
#include "org.alinous.charset/CP_1253.h"
#include "org.alinous.charset/CP_1257.h"
#include "org.alinous.charset/IBM866.h"
#include "org.alinous.charset/ISO_8859_1.h"
#include "org.alinous.charset/ISO_8859_2.h"
#include "org.alinous.charset/ISO_8859_4.h"
#include "org.alinous.charset/ISO_8859_9.h"
#include "org.alinous.charset/ISO_8859_13.h"
#include "org.alinous.charset/ISO_8859_15.h"
#include "org.alinous.charset/KOI8_R.h"
#include "org.alinous.charset/UTF_16LE.h"
#include "org.alinous.charset/UTF_8.h"
#include "org.alinous.charset/CharsetManager.h"

namespace org {namespace alinous {namespace charset {




bool CharsetConverter::__init_done = __init_static_variables();
bool CharsetConverter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CharsetConverter", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CharsetConverter::CharsetConverter(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void CharsetConverter::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CharsetConverter::~CharsetConverter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CharsetConverter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void CharsetConverter::__cleanUp(ThreadContext* ctx){
}
}}}

