#include "include/global.h"


#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.util/Random.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigInteger.h"
#include "alinous.numeric/BitLevel.h"
#include "alinous.numeric/Multiplication.h"
#include "alinous.numeric/Conversion.h"
#include "alinous.numeric/RoundingMode.h"
#include "alinous.numeric/Logical.h"
#include "alinous.numeric/MathContext.h"
#include "alinous.numeric/Division.h"
#include "alinous.lock/LockObject.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.numeric/Elementary.h"
#include "alinous.numeric/Primality.h"

namespace alinous {namespace numeric {





int RoundingMode::UP = 0;
int RoundingMode::DOWN = 0;
int RoundingMode::CEILING = 0;
int RoundingMode::FLOOR = 0;
int RoundingMode::HALF_UP = 0;
int RoundingMode::HALF_DOWN = 0;
int RoundingMode::HALF_EVEN = 0;
int RoundingMode::UNNECESSARY = 0;
bool RoundingMode::__init_done = __init_static_variables();
bool RoundingMode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RoundingMode", L"__init_static_variables");
		RoundingMode::UP = BigDecimal::ROUND_UP;
		RoundingMode::DOWN = BigDecimal::ROUND_DOWN;
		RoundingMode::CEILING = BigDecimal::ROUND_CEILING;
		RoundingMode::FLOOR = BigDecimal::ROUND_FLOOR;
		RoundingMode::HALF_UP = BigDecimal::ROUND_HALF_UP;
		RoundingMode::HALF_DOWN = BigDecimal::ROUND_HALF_DOWN;
		RoundingMode::HALF_EVEN = BigDecimal::ROUND_HALF_EVEN;
		RoundingMode::UNNECESSARY = BigDecimal::ROUND_UNNECESSARY;
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RoundingMode::RoundingMode(int rm, ThreadContext* ctx) throw()  : IObject(ctx), bigDecimalRM(0)
{
	this->bigDecimalRM = rm;
}
void RoundingMode::__construct_impl(int rm, ThreadContext* ctx) throw() 
{
	this->bigDecimalRM = rm;
}
 RoundingMode::~RoundingMode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RoundingMode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RoundingMode", L"~RoundingMode");
	if(!prepare){
		return;
	}
}
int RoundingMode::getBigDecimalRM(ThreadContext* ctx) throw() 
{
	return bigDecimalRM;
}
RoundingMode* RoundingMode::valueOf(int mode, ThreadContext* ctx) throw() 
{
	switch(mode) {
	case BigDecimal::ROUND_CEILING:
		return (new(ctx) RoundingMode(CEILING, ctx));
	case BigDecimal::ROUND_DOWN:
		return (new(ctx) RoundingMode(DOWN, ctx));
	case BigDecimal::ROUND_FLOOR:
		return (new(ctx) RoundingMode(FLOOR, ctx));
	case BigDecimal::ROUND_HALF_DOWN:
		return (new(ctx) RoundingMode(HALF_DOWN, ctx));
	case BigDecimal::ROUND_HALF_EVEN:
		return (new(ctx) RoundingMode(HALF_EVEN, ctx));
	case BigDecimal::ROUND_HALF_UP:
		return (new(ctx) RoundingMode(HALF_UP, ctx));
	case BigDecimal::ROUND_UNNECESSARY:
		return (new(ctx) RoundingMode(UNNECESSARY, ctx));
	case BigDecimal::ROUND_UP:
		return (new(ctx) RoundingMode(UP, ctx));
	default:
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_19(), ctx));
		break;
	}
}
}}

