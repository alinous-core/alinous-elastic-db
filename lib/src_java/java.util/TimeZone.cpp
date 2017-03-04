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





constexpr const int TimeZone::SHORT;
constexpr const int TimeZone::LONG;
HashMap<String,TimeZone>* TimeZone::AvailableZones = nullptr;
TimeZone* TimeZone::Default = nullptr;
TimeZone* TimeZone::GMT = nullptr;
bool TimeZone::__init_done = __init_static_variables();
bool TimeZone::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimeZone", L"__init_static_variables");
		GCUtils<HashMap<String,TimeZone> >::global(GCUtils<HashMap<String,TimeZone> >::mv(nullptr, &(AvailableZones), nullptr, ctx), ctx, __FILEW__, __LINE__);
		__GC_MV(nullptr, &(Default), nullptr, TimeZone);
		__GC_MV(nullptr, &(GMT), (new(ctx) SimpleTimeZone(0, ConstStr::getCNST_STR_565(), ctx)), TimeZone);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimeZone::~TimeZone() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimeZone::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TimeZone", L"~TimeZone");
	__e_obj1.add(this->ID, this);
	ID = nullptr;
	if(!prepare){
		return;
	}
}
IObject* TimeZone::clone(ThreadContext* ctx) throw() 
{
	TimeZone* tm = (new(ctx) SimpleTimeZone(this->getRawOffset(ctx), this->ID, ctx));
	return tm;
}
String* TimeZone::getDisplayName(ThreadContext* ctx) throw() 
{
	return getDisplayName(false, LONG, Locale::getDefault(ctx), ctx);
}
String* TimeZone::getDisplayName(Locale* locale, ThreadContext* ctx) throw() 
{
	return getDisplayName(false, LONG, locale, ctx);
}
String* TimeZone::getDisplayName(bool daylightTime, int style, ThreadContext* ctx) throw() 
{
	return getDisplayName(daylightTime, style, Locale::getDefault(ctx), ctx);
}
String* TimeZone::getDisplayName(bool daylightTime, int style, Locale* locale, ThreadContext* ctx) throw() 
{
	return getID(ctx);
}
String* TimeZone::getID(ThreadContext* ctx) throw() 
{
	return ID;
}
int TimeZone::getDSTSavings(ThreadContext* ctx) throw() 
{
	if(useDaylightTime(ctx))
	{
		return 3600000;
	}
	return 0;
}
int TimeZone::getOffset(long long time, ThreadContext* ctx) throw() 
{
	if(inDaylightTime((new(ctx) Date(time, ctx)), ctx))
	{
		return getRawOffset(ctx) + getDSTSavings(ctx);
	}
	return getRawOffset(ctx);
}
bool TimeZone::hasSameRules(TimeZone* zone, ThreadContext* ctx) throw() 
{
	if(zone == nullptr)
	{
		return false;
	}
	return getRawOffset(ctx) == zone->getRawOffset(ctx);
}
void TimeZone::setID(String* name, ThreadContext* ctx) throw() 
{
	if(name == nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	__GC_MV(this, &(ID), name, String);
}
IArrayObject<String>* TimeZone::getAvailableIDs(ThreadContext* ctx) throw() 
{
	IArrayObject<TimeZone>* zones = TimeZones::getTimeZones(ctx);
	IArrayObject<String>* ret = ArrayAllocator<String>::allocate(ctx, zones->length);
	for(int i = 0; i < ret->length; i ++ )
	{
		ret->set(zones->get(i)->getID(ctx),i, ctx);
	}
	return ret;
}
IArrayObject<String>* TimeZone::getAvailableIDs(int offset, ThreadContext* ctx) throw() 
{
	ArrayList<String>* ans = (new(ctx) ArrayList<String>(ctx));
	IArrayObject<TimeZone>* zones = TimeZones::getTimeZones(ctx);
	for(int i = 0; i < zones->length; i ++ )
	{
		if(zones->get(i)->getRawOffset(ctx) == offset)
		{
			ans->add(zones->get(i)->getID(ctx), ctx);
		}
	}
	return ((IArrayObject<String>*)ans->toArray(ctx));
}
TimeZone* TimeZone::getDefault(ThreadContext* ctx) throw() 
{
	if(Default == nullptr)
	{
		setDefault(nullptr, ctx);
	}
	return dynamic_cast<TimeZone*>(Default->clone(ctx));
}
TimeZone* TimeZone::getTimeZone(String* name, ThreadContext* ctx) throw() 
{
	if(AvailableZones == nullptr)
	{
		initializeAvailable(ctx);
	}
	TimeZone* zone = AvailableZones->get(name, ctx);
	if(zone == nullptr)
	{
		if(name->startsWith(ConstStr::getCNST_STR_565(), ctx) && name->length(ctx) > 3)
		{
			wchar_t sign = name->charAt(3, ctx);
			if(sign == L'+' || sign == L'-')
			{
				IArrayObjectPrimitive<int>* position = ArrayAllocatorPrimitive<int>::allocatep(ctx, 1);
				String* formattedName = formatTimeZoneName(name, 4, ctx);
				int hour = parseNumber(formattedName, 4, position, ctx);
				if(hour < 0 || hour > 23)
				{
					return dynamic_cast<TimeZone*>(GMT->clone(ctx));
				}
				int index = position->get(0);
				if(index != -1)
				{
					int raw = hour * 3600000;
					if(index < formattedName->length(ctx) && formattedName->charAt(index, ctx) == L':')
					{
						int minute = parseNumber(formattedName, index + 1, position, ctx);
						if(position->get(0) == -1 || minute < 0 || minute > 59)
						{
							return dynamic_cast<TimeZone*>(GMT->clone(ctx));
						}
						raw += minute * 60000;
					}
										else 
					{
						if(hour >= 30 || index > 6)
						{
							raw = (hour / 100 * 3600000) + (hour % 100 * 60000);
						}
					}
					if(sign == L'-')
					{
						raw = -raw;
					}
					return (new(ctx) SimpleTimeZone(raw, formattedName, ctx));
				}
			}
		}
		zone = GMT;
	}
	return dynamic_cast<TimeZone*>(zone->clone(ctx));
}
void TimeZone::setDefault(TimeZone* timezone, ThreadContext* ctx) throw() 
{
	if(timezone != nullptr)
	{
		__GC_MV(nullptr, &(Default), timezone, TimeZone);
		return;
	}
}
void TimeZone::initializeAvailable(ThreadContext* ctx) throw() 
{
	IArrayObject<TimeZone>* zones = TimeZones::getTimeZones(ctx);
	GCUtils<HashMap<String,TimeZone> >::global(GCUtils<HashMap<String,TimeZone> >::mv(nullptr, &(AvailableZones), (new(ctx) HashMap<String,TimeZone>((zones->length + 1) * 4 / 3, ctx)), ctx), ctx, __FILEW__, __LINE__);
	AvailableZones->put(GMT->getID(ctx), GMT, ctx);
	for(int i = 0; i < zones->length; i ++ )
	{
		AvailableZones->put(zones->get(i)->getID(ctx), zones->get(i), ctx);
	}
}
String* TimeZone::formatTimeZoneName(String* name, int offset, ThreadContext* ctx) throw() 
{
	StringBuilder* buf = (new(ctx) StringBuilder(ctx));
	int index = offset;int length = name->length(ctx);
	buf->append(name->substring(0, offset, ctx), ctx);
	while(index < length)
	{
		if(Character::digit(name->charAt(index, ctx), 10, ctx) != -1)
		{
			buf->append(name->charAt(index, ctx), ctx);
			if((length - (index + 1)) == 2)
			{
				buf->append(L':', ctx);
			}
		}
				else 
		{
			if(name->charAt(index, ctx) == L':')
			{
				buf->append(L':', ctx);
			}
		}
		index ++ ;
	}
	if(buf->toString(ctx)->indexOf(ConstStr::getCNST_STR_381(), ctx) == -1)
	{
		buf->append(L':', ctx);
		buf->append(ConstStr::getCNST_STR_7(), ctx);
	}
	if(buf->toString(ctx)->indexOf(ConstStr::getCNST_STR_381(), ctx) == 5)
	{
		buf->insert(4, L'0', ctx);
	}
	return buf->toString(ctx);
}
int TimeZone::parseNumber(String* string, int offset, IArrayObjectPrimitive<int>* position, ThreadContext* ctx) throw() 
{
	int index = offset;int length = string->length(ctx);int digit = 0;int result = 0;
	if(index < length){
		digit = Character::digit(string->charAt(index, ctx), 10, ctx);
	}
	while(index < length && (digit) != -1)
	{
		index ++ ;
		result = result * 10 + digit;
	}
	position->set(index == offset ? -1 : index,0, ctx);
	return result;
}
}}

