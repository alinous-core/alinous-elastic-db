#include "include/global.h"


#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "java.sql/Timestamp.h"
#include "java.sql/Date.h"

namespace java {namespace sql {





String* Date::PADDING = ConstStr::getCNST_STR_384();
bool Date::__init_done = __init_static_variables();
bool Date::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Date", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Date::Date(int theYear, int theMonth, int theDay, ThreadContext* ctx) throw()  : IObject(ctx), InternalDate(theYear, theMonth, theDay, ctx)
{
}
void Date::__construct_impl(int theYear, int theMonth, int theDay, ThreadContext* ctx) throw() 
{
}
 Date::Date(long long theDate, ThreadContext* ctx) throw()  : IObject(ctx), InternalDate(normalizeTime(theDate, ctx), ctx)
{
}
void Date::__construct_impl(long long theDate, ThreadContext* ctx) throw() 
{
}
 Date::~Date() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Date::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	InternalDate::__releaseRegerences(true, ctx);
}
void Date::setTime(long long theTime, ThreadContext* ctx) throw() 
{
	InternalDate::setTime(normalizeTime(theTime, ctx), ctx);
}
String* Date::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* sb = (new(ctx) StringBuilder(10, ctx));
	format((getYear(ctx) + 1900), 4, sb, ctx);
	sb->append(L'-', ctx);
	format((getMonth(ctx) + 1), 2, sb, ctx);
	sb->append(L'-', ctx);
	format(getDate(ctx), 2, sb, ctx);
	return sb->toString(ctx);
}
void Date::format(int date, int digits, StringBuilder* sb, ThreadContext* ctx) throw() 
{
	String* str = String::valueOf(date, ctx);
	if(digits - str->length(ctx) > 0)
	{
		sb->append(PADDING->substring(0, digits - str->length(ctx), ctx), ctx);
	}
	sb->append(str, ctx);
}
Date* Date::valueOf(String* dateString, ThreadContext* ctx) throw() 
{
	if(dateString == nullptr)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	int firstIndex = dateString->indexOf((int)L'-', ctx);
	int secondIndex = dateString->indexOf((int)L'-', firstIndex + 1, ctx);
	if(secondIndex == -1 || firstIndex == 0 || secondIndex + 1 == dateString->length(ctx))
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	int year = Integer::parseInt(dateString->substring(0, firstIndex, ctx), ctx);
	int month = Integer::parseInt(dateString->substring(firstIndex + 1, secondIndex, ctx), ctx);
	int day = Integer::parseInt(dateString->substring(secondIndex + 1, dateString->length(ctx), ctx), ctx);
	return (new(ctx) Date(year - 1900, month - 1, day, ctx));
}
long long Date::normalizeTime(long long theTime, ThreadContext* ctx) throw() 
{
	return theTime;
}
void Date::__cleanUp(ThreadContext* ctx){
}
}}

