#include "include/global.h"


#include "java.util/Date.h"
#include "java.util/Locale.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "java.util/Calendar.h"
#include "com.google.re2j/Inst.h"
#include "com.google.re2j/Prog.h"
#include "com.google.re2j/MachineInput.h"
#include "com.google.re2j/Machine.h"
#include "com.google.re2j/RE2.h"
#include "com.google.re2j/Matcher.h"
#include "com.google.re2j/Pattern.h"
#include "com.google.re2j/PatternSyntaxException.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "java.sql/Date.h"

namespace java {namespace sql {





String* Timestamp::TIME_FORMAT_REGEX = ConstStr::getCNST_STR_382();
String* Timestamp::PADDING = ConstStr::getCNST_STR_383();
bool Timestamp::__init_done = __init_static_variables();
bool Timestamp::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Timestamp", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Timestamp::Timestamp(long long theTime, ThreadContext* ctx) throw()  : IObject(ctx), InternalDate(theTime, ctx), nanos(0)
{
	setTimeImpl(theTime, ctx);
}
void Timestamp::__construct_impl(long long theTime, ThreadContext* ctx) throw() 
{
	setTimeImpl(theTime, ctx);
}
 Timestamp::~Timestamp() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Timestamp::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Timestamp", L"~Timestamp");
	if(!prepare){
		return;
	}
	InternalDate::__releaseRegerences(true, ctx);
}
bool Timestamp::after(Timestamp* theTimestamp, ThreadContext* ctx) throw() 
{
	long long thisTime = this->getTime(ctx);
	long long compareTime = theTimestamp->getTime(ctx);
	if(thisTime > compareTime)
	{
		return true;
	}
		else 
	{
		if(thisTime < compareTime)
		{
			return false;
		}
				else 
		{
			if(this->getNanos(ctx) > theTimestamp->getNanos(ctx))
			{
				return true;
			}
						else 
			{
				return false;
			}
		}
	}
}
bool Timestamp::before(Timestamp* theTimestamp, ThreadContext* ctx) throw() 
{
	long long thisTime = this->getTime(ctx);
	long long compareTime = theTimestamp->getTime(ctx);
	if(thisTime < compareTime)
	{
		return true;
	}
		else 
	{
		if(thisTime > compareTime)
		{
			return false;
		}
				else 
		{
			if(this->getNanos(ctx) < theTimestamp->getNanos(ctx))
			{
				return true;
			}
						else 
			{
				return false;
			}
		}
	}
}
int Timestamp::compareTo(InternalDate* theObject, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<Timestamp*>(theObject) != 0))
	{
		return this->compareTo(static_cast<Timestamp*>(theObject), ctx);
	}
	if(this->getTime(ctx) < theObject->getTime(ctx))
	{
		return -1;
	}
	if(this->getTime(ctx) > theObject->getTime(ctx))
	{
		return 1;
	}
	if(this->getNanos(ctx) % 1000000 > 0)
	{
		return 1;
	}
	return 0;
}
int Timestamp::compareTo(Timestamp* theTimestamp, ThreadContext* ctx) throw() 
{
	int result = InternalDate::compareTo(theTimestamp, ctx);
	if(result == 0)
	{
		int thisNano = this->getNanos(ctx);
		int thatNano = theTimestamp->getNanos(ctx);
		if(thisNano > thatNano)
		{
			return 1;
		}
				else 
		{
			if(thisNano == thatNano)
			{
				return 0;
			}
						else 
			{
				return -1;
			}
		}
	}
	return result;
}
bool Timestamp::equals(IObject* theObject, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<Timestamp*>(theObject) != 0))
	{
		return equals(dynamic_cast<Timestamp*>(theObject), ctx);
	}
	return false;
}
bool Timestamp::equals(Timestamp* theTimestamp, ThreadContext* ctx) throw() 
{
	if(theTimestamp == nullptr)
	{
		return false;
	}
	return (this->getTime(ctx) == theTimestamp->getTime(ctx)) && (this->getNanos(ctx) == theTimestamp->getNanos(ctx));
}
int Timestamp::getNanos(ThreadContext* ctx) throw() 
{
	return nanos;
}
long long Timestamp::getTime(ThreadContext* ctx) throw() 
{
	long long theTime = InternalDate::getTime(ctx);
	theTime = theTime + (nanos / 1000000);
	return theTime;
}
void Timestamp::setNanos(int n, ThreadContext* ctx)
{
	if((n < 0) || (n > 999999999))
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	nanos = n;
}
void Timestamp::setTime(long long theTime, ThreadContext* ctx) throw() 
{
	setTimeImpl(theTime, ctx);
}
String* Timestamp::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* sb = (new(ctx) StringBuilder(29, ctx));
	format((getYear(ctx) + 1900), 4, sb, ctx);
	sb->append(L'-', ctx);
	format((getMonth(ctx) + 1), 2, sb, ctx);
	sb->append(L'-', ctx);
	format(getDate(ctx), 2, sb, ctx);
	sb->append(L' ', ctx);
	format(getHours(ctx), 2, sb, ctx);
	sb->append(L':', ctx);
	format(getMinutes(ctx), 2, sb, ctx);
	sb->append(L':', ctx);
	format(getSeconds(ctx), 2, sb, ctx);
	sb->append(L'.', ctx);
	if(nanos == 0)
	{
		sb->append(L'0', ctx);
	}
		else 
	{
		format(nanos, 9, sb, ctx);
		while(sb->charAt(sb->length(ctx) - 1, ctx) == L'0')
		{
			sb->setLength(sb->length(ctx) - 1, ctx);
		}
	}
	return sb->toString(ctx);
}
void Timestamp::setTimeImpl(long long theTime, ThreadContext* ctx) throw() 
{
	int milliseconds = ((int)(theTime % 1000));
	theTime = theTime - milliseconds;
	if(milliseconds < 0)
	{
		theTime = theTime - 1000;
		milliseconds = 1000 + milliseconds;
	}
	InternalDate::setTime(theTime, ctx);
	nanos = milliseconds * 1000000;
}
void Timestamp::format(int date, int digits, StringBuilder* sb, ThreadContext* ctx) throw() 
{
	String* str = String::valueOf(date, ctx);
	if(digits - str->length(ctx) > 0)
	{
		sb->append(PADDING->substring(0, digits - str->length(ctx), ctx), ctx);
	}
	sb->append(str, ctx);
}
Timestamp* Timestamp::valueOf(String* s, ThreadContext* ctx)
{
	if(s == nullptr)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	s = s->trim(ctx);
	{
		try
		{
			if(!Pattern::matches(TIME_FORMAT_REGEX, s, ctx))
			{
				throw (new(ctx) IllegalArgumentException(ctx));
			}
		}
		catch(PatternSyntaxException* e)
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
	}
	IArrayObject<String>* segs = s->split(ConstStr::getCNST_STR_380(), ctx);
	IArrayObject<String>* dates = segs->get(0)->split(ConstStr::getCNST_STR_98(), ctx);
	int year = Integer::parseInt(dates->get(0), ctx);
	int month = Integer::parseInt(dates->get(1), ctx) - 1;
	int date = Integer::parseInt(dates->get(2), ctx) - 1;
	IArrayObject<String>* times = segs->get(1)->split(ConstStr::getCNST_STR_381(), ctx);
	int hour = Integer::parseInt(times->get(0), ctx);
	int minute = Integer::parseInt(times->get(1), ctx);
	int second = 0;
	int milli = 0;
	IArrayObject<String>* seconds = times->get(2)->split(ConstStr::getCNST_STR_361(), ctx);
	if(seconds->length == 1)
	{
		second = Integer::parseInt(seconds->get(0), ctx);
	}
		else 
	{
		second = Integer::parseInt(seconds->get(0), ctx);
		milli = Integer::parseInt(seconds->get(1), ctx);
	}
	Calendar* cal = Calendar::getInstance(ctx);
	cal->set(Calendar::YEAR, year, ctx);
	cal->set(Calendar::MONTH, month, ctx);
	cal->set(Calendar::DATE, date, ctx);
	cal->set(Calendar::HOUR, hour, ctx);
	cal->set(Calendar::MINUTE, minute, ctx);
	cal->set(Calendar::SECOND, second, ctx);
	cal->set(Calendar::MILLISECOND, milli, ctx);
	long long mls = cal->getTimeInMillis(ctx);
	Timestamp* tm = (new(ctx) Timestamp(mls, ctx));
	return tm;
}
int Timestamp::ValueCompare::operator() (InternalDate* _this, InternalDate* theObject, ThreadContext* ctx) const throw()
{
	return _this->compareTo(theObject, ctx);
}
}}

