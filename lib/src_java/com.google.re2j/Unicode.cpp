#include "includes.h"


namespace com {namespace google {namespace re2j {





constexpr const int Unicode::MAX_RUNE;
constexpr const int Unicode::MAX_ASCII;
constexpr const int Unicode::MAX_LATIN1;
constexpr const int Unicode::MAX_CASE;
constexpr const int Unicode::REPLACEMENT_CHAR;
constexpr const int Unicode::MIN_FOLD;
constexpr const int Unicode::MAX_FOLD;
bool Unicode::__init_done = __init_static_variables();
bool Unicode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Unicode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Unicode::~Unicode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Unicode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
bool Unicode::isUpper(int r, ThreadContext* ctx) throw() 
{
	if(r <= MAX_LATIN1)
	{
		return Character::isUpperCase(((wchar_t)r), ctx);
	}
	return is(UnicodeTables::Upper, r, ctx);
}
bool Unicode::isLower(int r, ThreadContext* ctx) throw() 
{
	if(r <= MAX_LATIN1)
	{
		return Character::isLowerCase(((wchar_t)r), ctx);
	}
	return is(UnicodeTables::Lower, r, ctx);
}
bool Unicode::isTitle(int r, ThreadContext* ctx) throw() 
{
	if(r <= MAX_LATIN1)
	{
		return false;
	}
	return is(UnicodeTables::Title, r, ctx);
}
bool Unicode::isPrint(int r, ThreadContext* ctx) throw() 
{
	if(r <= MAX_LATIN1)
	{
		return (r >= 0x20 && r < 0x7F) || (r >= 0xA1 && r != 0xAD);
	}
	return is(UnicodeTables::L, r, ctx) || is(UnicodeTables::M, r, ctx) || is(UnicodeTables::N, r, ctx) || is(UnicodeTables::P, r, ctx) || is(UnicodeTables::S, r, ctx);
}
int Unicode::toUpper(int r, ThreadContext* ctx) throw() 
{
	if(r <= MAX_ASCII)
	{
		if(L'a' <= (wchar_t)r && r <= (int)L'z')
		{
			r -= L'a' - L'A';
		}
		return r;
	}
	return to(UnicodeTables::UpperCase, r, ctx);
}
int Unicode::toLower(int r, ThreadContext* ctx) throw() 
{
	if(r <= MAX_ASCII)
	{
		if(L'A' <= (wchar_t)r && r <= (int)L'Z')
		{
			r += L'a' - L'A';
		}
		return r;
	}
	return to(UnicodeTables::LowerCase, r, ctx);
}
int Unicode::simpleFold(int r, ThreadContext* ctx) throw() 
{
	int lo = 0;
	int hi = UnicodeTables::CASE_ORBIT->length;
	while(lo < hi)
	{
		int m = lo + (hi - lo) / 2;
		if(UnicodeTables::CASE_ORBIT->get(m)->get(0) < r)
		{
			lo = m + 1;
		}
				else 
		{
			hi = m;
		}
	}
	if(lo < UnicodeTables::CASE_ORBIT->length && UnicodeTables::CASE_ORBIT->get(lo)->get(0) == r)
	{
		return UnicodeTables::CASE_ORBIT->get(lo)->get(1);
	}
	int l = toLower(r, ctx);
	if(l != r)
	{
		return l;
	}
	return toUpper(r, ctx);
}
bool Unicode::is32(IArrayObject<IArrayObjectPrimitive<int>>* ranges, int r, ThreadContext* ctx) throw() 
{
	for(int lo = 0,  hi = ranges->length; lo < hi; )
	{
		int m = lo + (hi - lo) / 2;
		IArrayObjectPrimitive<int>* range = ranges->get(m);
		if(range->get(0) <= r && r <= range->get(1))
		{
			return ((r - range->get(0)) % range->get(2)) == 0;
		}
		if(r < range->get(0))
		{
			hi = m;
		}
				else 
		{
			lo = m + 1;
		}
	}
	return false;
}
bool Unicode::is(IArrayObject<IArrayObjectPrimitive<int>>* ranges, int r, ThreadContext* ctx) throw() 
{
	if(r <= MAX_LATIN1)
	{
		{
			const int __max_for = ranges->length;
			for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
				IArrayObjectPrimitive<int>* range = ranges->get(__i_loop);
				{
					if(r > range->get(1))
					{
						continue;
					}
					if(r < range->get(0))
					{
						return false;
					}
					return ((r - range->get(0)) % range->get(2)) == 0;
				}
			}
		}
		return false;
	}
	return ranges->length > 0 && r >= ranges->get(0)->get(0) && is32(ranges, r, ctx);
}
int Unicode::to(int kase, int r, IArrayObject<IArrayObjectPrimitive<int>>* caseRange, ThreadContext* ctx) throw() 
{
	if(kase < 0 || MAX_CASE <= kase)
	{
		return REPLACEMENT_CHAR;
	}
	for(int lo = 0,  hi = caseRange->length; lo < hi; )
	{
		int m = lo + (hi - lo) / 2;
		IArrayObjectPrimitive<int>* cr = caseRange->get(m);
		int crlo = cr->get(0);
		int crhi = cr->get(1);
		if(crlo <= r && r <= crhi)
		{
			int delta = cr->get(2 + kase);
			if(delta > MAX_RUNE)
			{
				return crlo + (((r - crlo) & ~1) | (kase & 1));
			}
			return r + delta;
		}
		if(r < crlo)
		{
			hi = m;
		}
				else 
		{
			lo = m + 1;
		}
	}
	return r;
}
int Unicode::to(int kase, int r, ThreadContext* ctx) throw() 
{
	return to(kase, r, UnicodeTables::CASE_RANGES, ctx);
}
}}}

