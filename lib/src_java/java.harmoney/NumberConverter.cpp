#include "include/global.h"


#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Integer.h"
#include "java.harmoney/FloatingPointParser.h"
#include "java.lang/Double.h"
#include "java.harmoney/NumberConverter.h"
#include "com.google.re2j/Inst.h"
#include "com.google.re2j/Prog.h"
#include "com.google.re2j/MachineInput.h"
#include "com.google.re2j/Machine.h"
#include "com.google.re2j/RE2.h"
#include "com.google.re2j/Pattern.h"
#include "com.google.re2j/Matcher.h"
#include "java.harmoney/HexStringParser.h"

namespace java {namespace harmoney {





double NumberConverter::invLogOfTenBaseTwo = 0;
IArrayObjectPrimitive<long long>* NumberConverter::TEN_TO_THE = nullptr;
bool NumberConverter::__init_done = __init_static_variables();
bool NumberConverter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NumberConverter", L"__init_static_variables");
		NumberConverter::invLogOfTenBaseTwo = Math::log((double)2.0, ctx) / Math::log((double)10.0, ctx);
		__GC_MV(nullptr, &(TEN_TO_THE), (new ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 20), ctx)), IArrayObjectPrimitive<long long>);
		{
			TEN_TO_THE->set(1L,0, ctx);
			for(int i = 1; i < TEN_TO_THE->length; ++i)
			{
				long long previous = TEN_TO_THE->get(i - 1);
				TEN_TO_THE->set((previous << 1) + (previous << 3),i, ctx);
			}
		}
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NumberConverter::~NumberConverter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NumberConverter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NumberConverter", L"~NumberConverter");
	__e_obj1.add(this->uArray, this);
	uArray = nullptr;
	if(!prepare){
		return;
	}
}
String* NumberConverter::convertD(double inputNumber, ThreadContext* ctx) throw() 
{
	int p = 1023 + 52;
	long long signMask = ((long long)0x8000000000000000L);
	long long eMask = ((long long)0x7FF0000000000000L);
	long long fMask = ((long long)0x000FFFFFFFFFFFFFL);
	long long inputNumberBits = Double::doubleToLongBits(inputNumber, ctx);
	String* signString = (inputNumberBits & signMask) == (long long)0 ? ConstStr::getCNST_STR_4() : ConstStr::getCNST_STR_98();
	int e = ((int)((inputNumberBits & eMask) >> 52));
	long long f = inputNumberBits & fMask;
	bool mantissaIsZero = f == (long long)0;
	int pow = 0;int numBits = 52;
	if(e == 2047)
	{
		return mantissaIsZero ? signString->clone(ctx)->append(ConstStr::getCNST_STR_358(), ctx) : ConstStr::getCNST_STR_359();
	}
	if(e == 0)
	{
		if(mantissaIsZero)
		{
			return signString->clone(ctx)->append(ConstStr::getCNST_STR_10(), ctx);
		}
		if(f == (long long)1)
		{
			return signString->clone(ctx)->append(ConstStr::getCNST_STR_360(), ctx);
		}
		pow = 1 - p;
		long long ff = f;
		while((ff & 0x0010000000000000L) == (long long)0)
		{
			ff = ff << 1;
			numBits -- ;
		}
	}
		else 
	{
		f = f | 0x0010000000000000L;
		pow = e - p;
	}
	if((-59 < pow && pow < 6) || (pow == -59 && !mantissaIsZero))
	{
		longDigitGenerator(f, pow, e == 0, mantissaIsZero, numBits, ctx);
	}
		else 
	{
		bigIntDigitGeneratorInstImpl(f, pow, e == 0, mantissaIsZero, numBits, ctx);
	}
	if(inputNumber >= (double)1e7 || inputNumber <= (double)-1e7 || (inputNumber > (double)-1e-3 && inputNumber < (double)1e-3))
	{
		return signString->clone(ctx)->append(freeFormatExponential(ctx), ctx);
	}
	return signString->clone(ctx)->append(freeFormat(ctx), ctx);
}
String* NumberConverter::freeFormatExponential(ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<wchar_t>* formattedDecimal = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 25);
	formattedDecimal->set(((wchar_t)(L'0' + uArray->get(getCount++))),0, ctx);
	formattedDecimal->set(L'.',1, ctx);
	int charPos = 2;
	int k = firstK;
	int expt = k;
	while(true)
	{
		k -- ;
		if(getCount >= setCount)
		{
			break ;
		}
		formattedDecimal->set(((wchar_t)(L'0' + uArray->get(getCount++))),charPos++, ctx);
	}
	if(k == expt - 1)
	{
		formattedDecimal->set(L'0',charPos++, ctx);
	}
	formattedDecimal->set(L'E',charPos++, ctx);
	return (new(ctx) String(formattedDecimal, 0, charPos, ctx))->clone(ctx)->append(Integer::toString(expt, ctx), ctx);
}
String* NumberConverter::freeFormat(ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<wchar_t>* formattedDecimal = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 25);
	int charPos = 0;
	int k = firstK;
	if(k < 0)
	{
		formattedDecimal->set(L'0',0, ctx);
		formattedDecimal->set(L'.',1, ctx);
		charPos += 2;
		for(int i = k + 1; i < 0; i ++ )
		formattedDecimal->set(L'0',charPos++, ctx);
	}
	int U = uArray->get(getCount++);
	do
	{
		if(U != -1)
		{
			formattedDecimal->set(((wchar_t)(L'0' + U)),charPos++, ctx);
		}
				else 
		{
			if(k >= -1)
			{
				formattedDecimal->set(L'0',charPos++, ctx);
			}
		}
		if(k == 0)
		{
			formattedDecimal->set(L'.',charPos++, ctx);
		}
		k -- ;
		U = getCount < setCount ? uArray->get(getCount++) : -1;
	}
	while(U != -1 || k >= -1);
	return (new(ctx) String(formattedDecimal, 0, charPos, ctx));
}
void NumberConverter::bigIntDigitGeneratorInstImpl(long long f, int e, bool isDenormalized, bool mantissaIsZero, int p, ThreadContext* ctx) throw() 
{
}
void NumberConverter::longDigitGenerator(long long f, int e, bool isDenormalized, bool mantissaIsZero, int p, ThreadContext* ctx) throw() 
{
	long long R = 0;long long S = 0;long long M = 0;
	if(e >= 0)
	{
		M = 1l << e;
		if(!mantissaIsZero)
		{
			R = f << (e + 1);
			S = 2;
		}
				else 
		{
			R = f << (e + 2);
			S = 4;
		}
	}
		else 
	{
		M = 1;
		if(isDenormalized || !mantissaIsZero)
		{
			R = f << 1;
			S = 1l << (1 - e);
		}
				else 
		{
			R = f << 2;
			S = 1l << (2 - e);
		}
	}
	int k = ((int)Math::ceil((double)(e + p - 1) * invLogOfTenBaseTwo - 1e-10, ctx));
	if(k > 0)
	{
		S = S * TEN_TO_THE->get(k);
	}
		else 
	{
		if(k < 0)
		{
			long long scale = TEN_TO_THE->get(-k);
			R = R * scale;
			M = M == (long long)1 ? scale : M * scale;
		}
	}
	if(R + M > S)
	{
		firstK = k;
	}
		else 
	{
		firstK = k - 1;
		R = R * 10;
		M = M * 10;
	}
	getCount = setCount = 0;
	bool low = 0;bool high = 0;
	int U = 0;
	IArrayObjectPrimitive<long long>* Si = ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({S, S << 1, S << 2, S << 3}, ctx));
	while(true)
	{
		U = 0;
		long long remainder = 0;
		for(int i = 3; i >= 0; i -- )
		{
			remainder = R - Si->get(i);
			if(remainder >= (long long)0)
			{
				R = remainder;
				U += 1 << i;
			}
		}
		low = R < M;
		high = R + M > S;
		if(low || high)
		{
			break ;
		}
		R = R * 10;
		M = M * 10;
		uArray->set(U,setCount++, ctx);
	}
	if(low && !high)
	{
		uArray->set(U,setCount++, ctx);
	}
		else 
	{
		if(high && !low)
		{
			uArray->set(U + 1,setCount++, ctx);
		}
				else 
		{
			if((R << 1) < S)
			{
				uArray->set(U,setCount++, ctx);
			}
						else 
			{
				uArray->set(U + 1,setCount++, ctx);
			}
		}
	}
}
String* NumberConverter::convert(double input, ThreadContext* ctx) throw() 
{
	return getConverter(ctx)->convertD(input, ctx);
}
NumberConverter* NumberConverter::getConverter(ThreadContext* ctx) throw() 
{
	return (new(ctx) NumberConverter(ctx));
}
}}

