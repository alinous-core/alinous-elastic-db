#include "include/global.h"


#include "java.util/Locale.h"
#include "java.util/TimeZone.h"
#include "java.util/SimpleTimeZone.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.sql/Date.h"
#include "java.util/BitSet.h"
#include "java.util/TimeZones.h"
#include "java.util/Random.h"
#include "java.util/Arrays.h"

namespace java {namespace util {





Locale* Locale::defaultLocale = nullptr;
const Locale Locale:: __CANADA = (Locale(ConstStr::getCNST_STR_394(), ConstStr::getCNST_STR_414(), nullptr));
const Locale Locale:: __CANADA_FRENCH = (Locale(ConstStr::getCNST_STR_422(), ConstStr::getCNST_STR_414(), nullptr));
const Locale Locale:: __CHINA = (Locale(ConstStr::getCNST_STR_419(), ConstStr::getCNST_STR_420(), nullptr));
const Locale Locale:: __CHINESE = (Locale(ConstStr::getCNST_STR_419(), ConstStr::getCNST_STR_4(), nullptr));
const Locale Locale:: __ENGLISH = (Locale(ConstStr::getCNST_STR_394(), ConstStr::getCNST_STR_4(), nullptr));
const Locale Locale:: __FRANCE = (Locale(ConstStr::getCNST_STR_422(), ConstStr::getCNST_STR_523(), nullptr));
const Locale Locale:: __FRENCH = (Locale(ConstStr::getCNST_STR_422(), ConstStr::getCNST_STR_4(), nullptr));
const Locale Locale:: __GERMAN = (Locale(ConstStr::getCNST_STR_405(), ConstStr::getCNST_STR_4(), nullptr));
const Locale Locale:: __GERMANY = (Locale(ConstStr::getCNST_STR_405(), ConstStr::getCNST_STR_518(), nullptr));
const Locale Locale:: __ITALIAN = (Locale(ConstStr::getCNST_STR_396(), ConstStr::getCNST_STR_4(), nullptr));
const Locale Locale:: __ITALY = (Locale(ConstStr::getCNST_STR_396(), ConstStr::getCNST_STR_493(), nullptr));
const Locale Locale:: __JAPAN = (Locale(ConstStr::getCNST_STR_433(), ConstStr::getCNST_STR_440(), nullptr));
const Locale Locale:: __JAPANESE = (Locale(ConstStr::getCNST_STR_433(), ConstStr::getCNST_STR_4(), nullptr));
const Locale Locale:: __KOREA = (Locale(ConstStr::getCNST_STR_430(), ConstStr::getCNST_STR_431(), nullptr));
const Locale Locale:: __KOREAN = (Locale(ConstStr::getCNST_STR_430(), ConstStr::getCNST_STR_4(), nullptr));
const Locale Locale:: __PRC = (Locale(ConstStr::getCNST_STR_419(), ConstStr::getCNST_STR_420(), nullptr));
const Locale Locale:: __SIMPLIFIED_CHINESE = (Locale(ConstStr::getCNST_STR_419(), ConstStr::getCNST_STR_420(), nullptr));
const Locale Locale:: __TAIWAN = (Locale(ConstStr::getCNST_STR_419(), ConstStr::getCNST_STR_437(), nullptr));
const Locale Locale:: __TRADITIONAL_CHINESE = (Locale(ConstStr::getCNST_STR_419(), ConstStr::getCNST_STR_437(), nullptr));
const Locale Locale:: __UK = (Locale(ConstStr::getCNST_STR_394(), ConstStr::getCNST_STR_408(), nullptr));
const Locale Locale:: __US = (Locale(ConstStr::getCNST_STR_394(), ConstStr::getCNST_STR_418(), nullptr));
bool Locale::__init_done = __init_static_variables();
bool Locale::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Locale", L"__init_static_variables");
		__GC_MV(nullptr, &(defaultLocale), (new(ctx) Locale(ctx)), Locale);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Locale::Locale(ThreadContext* ctx) throw()  : IObject(ctx), countryCode(nullptr), languageCode(nullptr), variantCode(nullptr)
{
	__GC_MV(this, &(languageCode), ConstStr::getCNST_STR_394(), String);
	__GC_MV(this, &(countryCode), ConstStr::getCNST_STR_418(), String);
	__GC_MV(this, &(variantCode), ConstStr::getCNST_STR_4(), String);
}
void Locale::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(languageCode), ConstStr::getCNST_STR_394(), String);
	__GC_MV(this, &(countryCode), ConstStr::getCNST_STR_418(), String);
	__GC_MV(this, &(variantCode), ConstStr::getCNST_STR_4(), String);
}
 Locale::Locale(String* language, ThreadContext* ctx) throw()  : IObject(ctx), countryCode(nullptr), languageCode(nullptr), variantCode(nullptr)
{
	__construct_impl(language, ConstStr::getCNST_STR_4(), ConstStr::getCNST_STR_4(), ctx);
}
void Locale::__construct_impl(String* language, ThreadContext* ctx) throw() 
{
	__construct_impl(language, ConstStr::getCNST_STR_4(), ConstStr::getCNST_STR_4(), ctx);
}
 Locale::Locale(String* language, String* country, ThreadContext* ctx) throw()  : IObject(ctx), countryCode(nullptr), languageCode(nullptr), variantCode(nullptr)
{
	__construct_impl(language, country, ConstStr::getCNST_STR_4(), ctx);
}
void Locale::__construct_impl(String* language, String* country, ThreadContext* ctx) throw() 
{
	__construct_impl(language, country, ConstStr::getCNST_STR_4(), ctx);
}
 Locale::Locale(String* language, String* country, String* variant, ThreadContext* ctx) throw()  : IObject(ctx), countryCode(nullptr), languageCode(nullptr), variantCode(nullptr)
{
	__GC_MV(this, &(this->languageCode), language, String);
	__GC_MV(this, &(this->countryCode), country, String);
	__GC_MV(this, &(this->variantCode), variant, String);
}
void Locale::__construct_impl(String* language, String* country, String* variant, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->languageCode), language, String);
	__GC_MV(this, &(this->countryCode), country, String);
	__GC_MV(this, &(this->variantCode), variant, String);
}
 Locale::~Locale() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Locale::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Locale", L"~Locale");
	__e_obj1.add(this->countryCode, this);
	countryCode = nullptr;
	__e_obj1.add(this->languageCode, this);
	languageCode = nullptr;
	__e_obj1.add(this->variantCode, this);
	variantCode = nullptr;
	if(!prepare){
		return;
	}
}
bool Locale::equals(IObject* object, ThreadContext* ctx) throw() 
{
	if(object == this)
	{
		return true;
	}
	if((dynamic_cast<Locale*>(object) != 0))
	{
		Locale* o = dynamic_cast<Locale*>(object);
		return languageCode->equals(o->languageCode, ctx) && countryCode->equals(o->countryCode, ctx) && variantCode->equals(o->variantCode, ctx);
	}
	return false;
}
String* Locale::getCountry(ThreadContext* ctx) throw() 
{
	return countryCode;
}
String* Locale::getDisplayCountry(ThreadContext* ctx) throw() 
{
	return getDisplayCountry(getDefault(ctx), ctx);
}
String* Locale::getDisplayCountry(Locale* locale, ThreadContext* ctx) throw() 
{
	return locale->getCountry(ctx);
}
String* Locale::getDisplayLanguage(ThreadContext* ctx) throw() 
{
	return getDisplayLanguage(getDefault(ctx), ctx);
}
String* Locale::getDisplayLanguage(Locale* locale, ThreadContext* ctx) throw() 
{
	return locale->getLanguage(ctx);
}
String* Locale::getDisplayName(ThreadContext* ctx) throw() 
{
	return getDisplayName(getDefault(ctx), ctx);
}
String* Locale::getDisplayName(Locale* locale, ThreadContext* ctx) throw() 
{
	int count = 0;
	StringBuilder* buffer = (new(ctx) StringBuilder(ctx));
	if(languageCode->length(ctx) > 0)
	{
		buffer->append(getDisplayLanguage(locale, ctx), ctx);
		count ++ ;
	}
	if(countryCode->length(ctx) > 0)
	{
		if(count == 1)
		{
			buffer->append(ConstStr::getCNST_STR_887(), ctx);
		}
		buffer->append(getDisplayCountry(locale, ctx), ctx);
		count ++ ;
	}
	if(variantCode->length(ctx) > 0)
	{
		if(count == 1)
		{
			buffer->append(ConstStr::getCNST_STR_887(), ctx);
		}
				else 
		{
			if(count == 2)
			{
				buffer->append(ConstStr::getCNST_STR_888(), ctx);
			}
		}
		buffer->append(getDisplayVariant(locale, ctx), ctx);
		count ++ ;
	}
	if(count > 1)
	{
		buffer->append(ConstStr::getCNST_STR_889(), ctx);
	}
	return buffer->toString(ctx);
}
String* Locale::getDisplayVariant(ThreadContext* ctx) throw() 
{
	return getDisplayVariant(getDefault(ctx), ctx);
}
String* Locale::getDisplayVariant(Locale* locale, ThreadContext* ctx) throw() 
{
	return locale->getVariant(ctx);
}
String* Locale::getISO3Country(ThreadContext* ctx)
{
	return this->countryCode;
}
String* Locale::getISO3Language(ThreadContext* ctx)
{
	return languageCode;
}
String* Locale::getLanguage(ThreadContext* ctx) throw() 
{
	return languageCode;
}
String* Locale::getVariant(ThreadContext* ctx) throw() 
{
	return variantCode;
}
int Locale::hashCode(ThreadContext* ctx) throw() 
{
	return countryCode->hashCode(ctx) + languageCode->hashCode(ctx) + variantCode->hashCode(ctx);
}
String* Locale::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* result = (new(ctx) StringBuilder(ctx));
	result->append(languageCode, ctx);
	if(countryCode->length(ctx) > 0)
	{
		result->append(L'_', ctx);
		result->append(countryCode, ctx);
	}
	if(variantCode->length(ctx) > 0 && result->length(ctx) > 0)
	{
		if(0 == countryCode->length(ctx))
		{
			result->append(ConstStr::getCNST_STR_890(), ctx);
		}
				else 
		{
			result->append(L'_', ctx);
		}
		result->append(variantCode, ctx);
	}
	return result->toString(ctx);
}
IArrayObject<Locale>* Locale::getAvailableLocales(ThreadContext* ctx) throw() 
{
	return nullptr;
}
Locale* Locale::getDefault(ThreadContext* ctx) throw() 
{
	return defaultLocale;
}
IArrayObject<String>* Locale::getISOCountries(ThreadContext* ctx) throw() 
{
	return nullptr;
}
IArrayObject<String>* Locale::getISOLanguages(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void Locale::setDefault(Locale* locale, ThreadContext* ctx) throw() 
{
	if(locale != nullptr)
	{
		__GC_MV(nullptr, &(defaultLocale), locale, Locale);
	}
		else 
	{
		throw (new(ctx) NullPointerException(ctx));
	}
}
}}

