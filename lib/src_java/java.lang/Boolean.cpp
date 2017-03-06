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





const Boolean Boolean:: __TRUE = (Boolean(true, nullptr));
const Boolean Boolean:: __FALSE = (Boolean(false, nullptr));
bool Boolean::__init_done = __init_static_variables();
bool Boolean::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Boolean", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Boolean::Boolean(String* string, ThreadContext* ctx) throw()  : IObject(ctx), value(0)
{
	__construct_impl(parseBoolean(string, ctx), ctx);
}
void Boolean::__construct_impl(String* string, ThreadContext* ctx) throw() 
{
	__construct_impl(parseBoolean(string, ctx), ctx);
}
 Boolean::Boolean(bool value, ThreadContext* ctx) throw()  : IObject(ctx), value(0)
{
	this->value = value;
}
void Boolean::__construct_impl(bool value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 Boolean::~Boolean() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Boolean::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Boolean", L"~Boolean");
	if(!prepare){
		return;
	}
}
bool Boolean::booleanValue(ThreadContext* ctx) throw() 
{
	return value;
}
bool Boolean::equals(IObject* o, ThreadContext* ctx) throw() 
{
	return (o == this) || (((dynamic_cast<Boolean*>(o) != 0)) && (value == (dynamic_cast<Boolean*>(o))->value));
}
int Boolean::compareTo(Boolean* that, ThreadContext* ctx) throw() 
{
	if(that == nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	if(this->value == that->value)
	{
		return 0;
	}
	return this->value ? 1 : -1;
}
int Boolean::hashCode(ThreadContext* ctx) throw() 
{
	return value ? 1231 : 1237;
}
String* Boolean::toString(ThreadContext* ctx) throw() 
{
	return String::valueOf(value, ctx);
}
bool Boolean::getBoolean(String* string, ThreadContext* ctx) throw() 
{
	if(string == nullptr || string->length(ctx) == 0)
	{
		return false;
	}
	return (parseBoolean(string, ctx));
}
bool Boolean::parseBoolean(String* s, ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_372()->equalsIgnoreCase(s, ctx);
}
String* Boolean::toString(bool value, ThreadContext* ctx) throw() 
{
	return String::valueOf(value, ctx);
}
Boolean* Boolean::valueOf(String* string, ThreadContext* ctx) throw() 
{
	return parseBoolean(string, ctx) ? Boolean::TRUE : Boolean::FALSE;
}
Boolean* Boolean::valueOf(bool b, ThreadContext* ctx) throw() 
{
	return b ? Boolean::TRUE : Boolean::FALSE;
}
void Boolean::__cleanUp(ThreadContext* ctx){
}
int Boolean::ValueCompare::operator() (Boolean* _this, Boolean* that, ThreadContext* ctx) const throw()
{
	return _this->compareTo(that, ctx);
}
}}

