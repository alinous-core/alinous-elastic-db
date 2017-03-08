#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"
#include "org.alinous.charset/CP_1250.h"
#include "org.alinous.charset/CP_1251.h"
#include "org.alinous.charset/CP_1252.h"
#include "org.alinous.charset/CP_1253.h"
#include "org.alinous.charset/CP_1254.h"
#include "org.alinous.charset/CP_1257.h"
#include "org.alinous.charset/IBM866.h"
#include "org.alinous.charset/ISO_8859_1.h"
#include "org.alinous.charset/ISO_8859_2.h"
#include "org.alinous.charset/ISO_8859_4.h"
#include "org.alinous.charset/ISO_8859_5.h"
#include "org.alinous.charset/ISO_8859_7.h"
#include "org.alinous.charset/ISO_8859_9.h"
#include "org.alinous.charset/ISO_8859_13.h"
#include "org.alinous.charset/ISO_8859_15.h"
#include "org.alinous.charset/KOI8_R.h"
#include "org.alinous.charset/US_ASCII.h"
#include "org.alinous.charset/UTF_16.h"
#include "org.alinous.charset/UTF_16BE.h"
#include "org.alinous.charset/UTF_16LE.h"
#include "org.alinous.charset/UTF_8.h"
#include "org.alinous.charset/CharsetManager.h"

namespace org {namespace alinous {namespace charset {





CharsetManager* CharsetManager::instance = nullptr;
bool CharsetManager::__init_done = __init_static_variables();
bool CharsetManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CharsetManager", L"__init_static_variables");
		__GC_MV(nullptr, &(instance), nullptr, CharsetManager);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CharsetManager::CharsetManager(ThreadContext* ctx) throw()  : IObject(ctx), charConverters(GCUtils<HashMap<String,CharsetConverter> >::ins(this, (new(ctx) HashMap<String,CharsetConverter>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void CharsetManager::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CharsetManager::~CharsetManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CharsetManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CharsetManager", L"~CharsetManager");
	__e_obj1.add(this->charConverters, this);
	charConverters = nullptr;
	if(!prepare){
		return;
	}
}
CharsetDecoder* CharsetManager::getDecoder(String* charset, ThreadContext* ctx) throw() 
{
	CharsetConverter* conv = getConverter(charset, ctx);
	CharsetDecoder* dec = conv->newDecoder(ctx);
	return dec;
}
CharsetEncoder* CharsetManager::getEncoder(String* charset, ThreadContext* ctx) throw() 
{
	CharsetConverter* conv = getConverter(charset, ctx);
	CharsetEncoder* enc = conv->newEncoder(ctx);
	return enc;
}
CharsetConverter* CharsetManager::getConverter(String* charset, ThreadContext* ctx) throw() 
{
	charset = charset->toUpperCase(ctx);
	String* altcharset = charset->replace(L'-', L'_', ctx);
	CharsetConverter* conv = this->charConverters->get(altcharset, ctx);
	if(conv != nullptr)
	{
		return conv;
	}
	conv = this->charConverters->get(charset, ctx);
	if(conv != nullptr)
	{
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_917(), ctx))
	{
		conv = (new(ctx) CP_1250(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_918(), ctx))
	{
		conv = (new(ctx) CP_1251(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_919(), ctx))
	{
		conv = (new(ctx) CP_1252(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_920(), ctx))
	{
		conv = (new(ctx) CP_1253(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_921(), ctx))
	{
		conv = (new(ctx) CP_1254(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_922(), ctx))
	{
		conv = (new(ctx) CP_1257(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_923(), ctx))
	{
		conv = (new(ctx) IBM866(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_924(), ctx))
	{
		conv = (new(ctx) ISO_8859_1(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_925(), ctx))
	{
		conv = (new(ctx) ISO_8859_2(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_926(), ctx))
	{
		conv = (new(ctx) ISO_8859_4(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_927(), ctx))
	{
		conv = (new(ctx) ISO_8859_5(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_928(), ctx))
	{
		conv = (new(ctx) ISO_8859_7(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_929(), ctx))
	{
		conv = (new(ctx) ISO_8859_9(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_930(), ctx))
	{
		conv = (new(ctx) ISO_8859_13(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_931(), ctx))
	{
		conv = (new(ctx) ISO_8859_15(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_932(), ctx))
	{
		conv = (new(ctx) KOI8_R(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_916(), ctx))
	{
		conv = (new(ctx) US_ASCII(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_933(), ctx))
	{
		conv = (new(ctx) UTF_16(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_934(), ctx))
	{
		conv = (new(ctx) UTF_16BE(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_935(), ctx))
	{
		conv = (new(ctx) UTF_16LE(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(altcharset->equals(ConstStr::getCNST_STR_936(), ctx))
	{
		conv = (new(ctx) UTF_8(ctx));
		charConverters->put(altcharset, conv, ctx);
		return conv;
	}
	if(CP_1250::contains(charset, ctx))
	{
		conv = (new(ctx) CP_1250(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(CP_1251::contains(charset, ctx))
	{
		conv = (new(ctx) CP_1251(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(CP_1252::contains(charset, ctx))
	{
		conv = (new(ctx) CP_1252(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(CP_1253::contains(charset, ctx))
	{
		conv = (new(ctx) CP_1253(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(CP_1254::contains(charset, ctx))
	{
		conv = (new(ctx) CP_1254(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(CP_1257::contains(charset, ctx))
	{
		conv = (new(ctx) CP_1257(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(IBM866::contains(charset, ctx))
	{
		conv = (new(ctx) IBM866(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(ISO_8859_1::contains(charset, ctx))
	{
		conv = (new(ctx) ISO_8859_1(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(ISO_8859_2::contains(charset, ctx))
	{
		conv = (new(ctx) ISO_8859_2(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(ISO_8859_4::contains(charset, ctx))
	{
		conv = (new(ctx) ISO_8859_4(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(ISO_8859_5::contains(charset, ctx))
	{
		conv = (new(ctx) ISO_8859_5(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(ISO_8859_7::contains(charset, ctx))
	{
		conv = (new(ctx) ISO_8859_7(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(ISO_8859_9::contains(charset, ctx))
	{
		conv = (new(ctx) ISO_8859_9(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(ISO_8859_13::contains(charset, ctx))
	{
		conv = (new(ctx) ISO_8859_13(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(ISO_8859_15::contains(charset, ctx))
	{
		conv = (new(ctx) ISO_8859_15(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(KOI8_R::contains(charset, ctx))
	{
		conv = (new(ctx) KOI8_R(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(US_ASCII::contains(charset, ctx))
	{
		conv = (new(ctx) US_ASCII(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(UTF_16::contains(charset, ctx))
	{
		conv = (new(ctx) UTF_16(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(UTF_16BE::contains(charset, ctx))
	{
		conv = (new(ctx) UTF_16BE(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(UTF_16LE::contains(charset, ctx))
	{
		conv = (new(ctx) UTF_16LE(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	if(UTF_8::contains(charset, ctx))
	{
		conv = (new(ctx) UTF_8(ctx));
		charConverters->put(charset, conv, ctx);
		return conv;
	}
	throw (new(ctx) UnsupportedCharsetException(charset, ctx));
}
CharsetManager* CharsetManager::getInstance(ThreadContext* ctx) throw() 
{
	if(CharsetManager::instance == nullptr)
	{
		__GC_MV(nullptr, &(CharsetManager::instance), (new(ctx) CharsetManager(ctx)), CharsetManager);
	}
	return CharsetManager::instance;
}
void CharsetManager::__cleanUp(ThreadContext* ctx){
	GCUtils<CharsetManager>::dec(nullptr, CharsetManager::instance, ctx, __FILEW__, __LINE__, L"CharsetManager");
}
}}}

