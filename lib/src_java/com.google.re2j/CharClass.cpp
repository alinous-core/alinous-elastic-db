#include "include/global.h"


#include "com.google.re2j/Regexp.h"
#include "com.google.re2j/Simplify.h"
#include "com.google.re2j/Inst.h"
#include "com.google.re2j/Prog.h"
#include "com.google.re2j/MachineInput.h"
#include "com.google.re2j/UTF8Input.h"
#include "com.google.re2j/UTF16Input.h"
#include "com.google.re2j/RE2.h"
#include "com.google.re2j/Machine.h"
#include "com.google.re2j/PatternSyntaxException.h"
#include "com.google.re2j/Utils.h"
#include "com.google.re2j/Unicode.h"
#include "com.google.re2j/CharGroup.h"
#include "com.google.re2j/CharClass.h"
#include "com.google.re2j/Parser.h"
#include "com.google.re2j/Compiler.h"
#include "com.google.re2j/UnicodeTable2.h"
#include "com.google.re2j/UnicodeTables.h"
#include "com.google.re2j/Pattern.h"
#include "com.google.re2j/Matcher.h"

namespace com {namespace google {namespace re2j {





bool CharClass::__init_done = __init_static_variables();
bool CharClass::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CharClass", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CharClass::CharClass(IArrayObjectPrimitive<int>* r, ThreadContext* ctx) throw()  : IObject(ctx), r(nullptr), len(0)
{
	__GC_MV(this, &(this->r), r, IArrayObjectPrimitive<int>);
	this->len = r->length;
}
void CharClass::__construct_impl(IArrayObjectPrimitive<int>* r, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->r), r, IArrayObjectPrimitive<int>);
	this->len = r->length;
}
 CharClass::CharClass(ThreadContext* ctx) throw()  : IObject(ctx), r(nullptr), len(0)
{
	__GC_MV(this, &(this->r), Utils::EMPTY_INTS, IArrayObjectPrimitive<int>);
	this->len = 0;
}
void CharClass::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->r), Utils::EMPTY_INTS, IArrayObjectPrimitive<int>);
	this->len = 0;
}
 CharClass::~CharClass() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CharClass::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CharClass", L"~CharClass");
	__e_obj1.add(this->r, this);
	r = nullptr;
	if(!prepare){
		return;
	}
}
String* CharClass::toString(ThreadContext* ctx) throw() 
{
	return charClassToString(r, len, ctx);
}
IArrayObjectPrimitive<int>* CharClass::toArray(ThreadContext* ctx) throw() 
{
	if(this->len == r->length)
	{
		return r;
	}
		else 
	{
		IArrayObjectPrimitive<int>* r2 = ArrayAllocatorPrimitive<int>::allocatep(ctx, len);
		System::arraycopy(r, 0, r2, 0, len, ctx);
		return r2;
	}
}
CharClass* CharClass::cleanClass(ThreadContext* ctx) throw() 
{
	if(len < 4)
	{
		return this;
	}
	qsortIntPair(r, 0, len - 2, ctx);
	int w = 2;
	for(int i = 2; i < len; i += 2)
	{
		int lo = r->get(i);
		int hi = r->get(i + 1);
		if(lo <= r->get(w - 1) + 1)
		{
			if(hi > r->get(w - 1))
			{
				r->set(hi,w - 1, ctx);
			}
			continue;
		}
		r->set(lo,w, ctx);
		r->set(hi,w + 1, ctx);
		w += 2;
	}
	len = w;
	return this;
}
CharClass* CharClass::appendLiteral(int x, int flags, ThreadContext* ctx) throw() 
{
	return ((flags & RE2::FOLD_CASE) != 0) ? appendFoldedRange(x, x, ctx) : appendRange(x, x, ctx);
}
CharClass* CharClass::appendRange(int lo, int hi, ThreadContext* ctx) throw() 
{
	if(len > 0)
	{
		for(int i = 2; i <= 4; i += 2)
		{
			if(len >= i)
			{
				int rlo = r->get(len - i);
				int rhi = r->get(len - i + 1);
				if(lo <= rhi + 1 && rlo <= hi + 1)
				{
					if(lo < rlo)
					{
						r->set(lo,len - i, ctx);
					}
					if(hi > rhi)
					{
						r->set(hi,len - i + 1, ctx);
					}
					return this;
				}
			}
		}
	}
	ensureCapacity(len + 2, ctx);
	r->set(lo,len++, ctx);
	r->set(hi,len++, ctx);
	return this;
}
CharClass* CharClass::appendFoldedRange(int lo, int hi, ThreadContext* ctx) throw() 
{
	if(lo <= Unicode::MIN_FOLD && hi >= Unicode::MAX_FOLD)
	{
		return appendRange(lo, hi, ctx);
	}
	if(hi < Unicode::MIN_FOLD || lo > Unicode::MAX_FOLD)
	{
		return appendRange(lo, hi, ctx);
	}
	if(lo < Unicode::MIN_FOLD)
	{
		appendRange(lo, Unicode::MIN_FOLD - 1, ctx);
		lo = Unicode::MIN_FOLD;
	}
	if(hi > Unicode::MAX_FOLD)
	{
		appendRange(Unicode::MAX_FOLD + 1, hi, ctx);
		hi = Unicode::MAX_FOLD;
	}
	for(int c = lo; c <= hi; c ++ )
	{
		appendRange(c, c, ctx);
		for(int f = Unicode::simpleFold(c, ctx); f != c; f = Unicode::simpleFold(f, ctx))
		{
			appendRange(f, f, ctx);
		}
	}
	return this;
}
CharClass* CharClass::appendClass(IArrayObjectPrimitive<int>* x, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < x->length; i += 2)
	{
		appendRange(x->get(i), x->get(i + 1), ctx);
	}
	return this;
}
CharClass* CharClass::appendFoldedClass(IArrayObjectPrimitive<int>* x, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < x->length; i += 2)
	{
		appendFoldedRange(x->get(i), x->get(i + 1), ctx);
	}
	return this;
}
CharClass* CharClass::appendNegatedClass(IArrayObjectPrimitive<int>* x, ThreadContext* ctx) throw() 
{
	int nextLo = 0;
	for(int i = 0; i < x->length; i += 2)
	{
		int lo = x->get(i);
		int hi = x->get(i + 1);
		if(nextLo <= lo - 1)
		{
			appendRange(nextLo, lo - 1, ctx);
		}
		nextLo = hi + 1;
	}
	if(nextLo <= Unicode::MAX_RUNE)
	{
		appendRange(nextLo, Unicode::MAX_RUNE, ctx);
	}
	return this;
}
CharClass* CharClass::appendTable(IArrayObject<IArrayObjectPrimitive<int>>* table, ThreadContext* ctx) throw() 
{
	{
		const int __max_for = table->length;
		for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
			IArrayObjectPrimitive<int>* triple = table->get(__i_loop);
			{
				int lo = triple->get(0);int hi = triple->get(1);int stride = triple->get(2);
				if(stride == 1)
				{
					appendRange(lo, hi, ctx);
					continue;
				}
				for(int c = lo; c <= hi; c += stride)
				{
					appendRange(c, c, ctx);
				}
			}
		}
	}
	return this;
}
CharClass* CharClass::appendNegatedTable(IArrayObject<IArrayObjectPrimitive<int>>* table, ThreadContext* ctx) throw() 
{
	int nextLo = 0;
	{
		const int __max_for = table->length;
		for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
			IArrayObjectPrimitive<int>* triple = table->get(__i_loop);
			{
				int lo = triple->get(0);int hi = triple->get(1);int stride = triple->get(2);
				if(stride == 1)
				{
					if(nextLo <= lo - 1)
					{
						appendRange(nextLo, lo - 1, ctx);
					}
					nextLo = hi + 1;
					continue;
				}
				for(int c = lo; c <= hi; c += stride)
				{
					if(nextLo <= c - 1)
					{
						appendRange(nextLo, c - 1, ctx);
					}
					nextLo = c + 1;
				}
			}
		}
	}
	if(nextLo <= Unicode::MAX_RUNE)
	{
		appendRange(nextLo, Unicode::MAX_RUNE, ctx);
	}
	return this;
}
CharClass* CharClass::appendTableWithSign(IArrayObject<IArrayObjectPrimitive<int>>* table, int sign, ThreadContext* ctx) throw() 
{
	return sign < 0 ? appendNegatedTable(table, ctx) : appendTable(table, ctx);
}
CharClass* CharClass::negateClass(ThreadContext* ctx) throw() 
{
	int nextLo = 0;
	int w = 0;
	for(int i = 0; i < len; i += 2)
	{
		int lo = r->get(i);int hi = r->get(i + 1);
		if(nextLo <= lo - 1)
		{
			r->set(nextLo,w, ctx);
			r->set(lo - 1,w + 1, ctx);
			w += 2;
		}
		nextLo = hi + 1;
	}
	len = w;
	if(nextLo <= Unicode::MAX_RUNE)
	{
		ensureCapacity(len + 2, ctx);
		r->set(nextLo,len++, ctx);
		r->set(Unicode::MAX_RUNE,len++, ctx);
	}
	return this;
}
CharClass* CharClass::appendClassWithSign(IArrayObjectPrimitive<int>* x, int sign, ThreadContext* ctx) throw() 
{
	return sign < 0 ? appendNegatedClass(x, ctx) : appendClass(x, ctx);
}
CharClass* CharClass::appendGroup(CharGroup* g, bool foldCase, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* cls = g->cls;
	if(foldCase)
	{
		cls = (new(ctx) CharClass(ctx))->appendFoldedClass(cls, ctx)->cleanClass(ctx)->toArray(ctx);
	}
	return appendClassWithSign(cls, g->sign, ctx);
}
void CharClass::ensureCapacity(int newLen, ThreadContext* ctx) throw() 
{
	if(r->length < newLen)
	{
		if(newLen < len * 2)
		{
			newLen = len * 2;
		}
		IArrayObjectPrimitive<int>* r2 = ArrayAllocatorPrimitive<int>::allocatep(ctx, newLen);
		System::arraycopy(r, 0, r2, 0, len, ctx);
		__GC_MV(this, &(r), r2, IArrayObjectPrimitive<int>);
	}
}
void CharClass::includes(Utils* arg0, RE2* arg1, Unicode* arg2, ThreadContext* ctx) throw() 
{
}
String* CharClass::charClassToString(IArrayObjectPrimitive<int>* r, int len, ThreadContext* ctx) throw() 
{
	StringBuilder* b = (new(ctx) StringBuilder(ctx));
	b->append(L'[', ctx);
	for(int i = 0; i < len; i += 2)
	{
		if(i > 0)
		{
			b->append(L' ', ctx);
		}
		int lo = r->get(i);int hi = r->get(i + 1);
		if(lo == hi)
		{
			b->append(ConstStr::getCNST_STR_322(), ctx);
			b->append(Integer::toHexString(lo, ctx), ctx);
		}
				else 
		{
			b->append(ConstStr::getCNST_STR_322(), ctx);
			b->append(Integer::toHexString(lo, ctx), ctx);
			b->append(ConstStr::getCNST_STR_323(), ctx);
			b->append(Integer::toHexString(hi, ctx), ctx);
		}
	}
	b->append(L']', ctx);
	return b->toString(ctx);
}
int CharClass::cmp(IArrayObjectPrimitive<int>* array, int i, int pivotFrom, int pivotTo, ThreadContext* ctx) throw() 
{
	int cmp = array->get(i) - pivotFrom;
	return cmp != 0 ? cmp : pivotTo - array->get(i + 1);
}
void CharClass::qsortIntPair(IArrayObjectPrimitive<int>* array, int left, int right, ThreadContext* ctx) throw() 
{
	int pivotIndex = ((left + right) / 2) & ~1;
	int pivotFrom = array->get(pivotIndex);int pivotTo = array->get(pivotIndex + 1);
	int i = left;int j = right;
	while(i <= j)
	{
		while(i < right && cmp(array, i, pivotFrom, pivotTo, ctx) < 0)
		{
			i += 2;
		}
		while(j > left && cmp(array, j, pivotFrom, pivotTo, ctx) > 0)
		{
			j -= 2;
		}
		if(i <= j)
		{
			if(i != j)
			{
				int temp = array->get(i);
				array->set(array->get(j),i, ctx);
				array->set(temp,j, ctx);
				temp = array->get(i + 1);
				array->set(array->get(j + 1),i + 1, ctx);
				array->set(temp,j + 1, ctx);
			}
			i += 2;
			j -= 2;
		}
	}
	if(left < j)
	{
		qsortIntPair(array, left, j, ctx);
	}
	if(i < right)
	{
		qsortIntPair(array, i, right, ctx);
	}
}
void CharClass::__cleanUp(ThreadContext* ctx){
}
}}}

