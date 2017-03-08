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
#include "com.google.re2j/CharGroup.h"
#include "com.google.re2j/CharClass.h"
#include "com.google.re2j/Parser.h"
#include "com.google.re2j/Unicode.h"
#include "com.google.re2j/Utils.h"
#include "com.google.re2j/Compiler.h"
#include "com.google.re2j/UnicodeTable2.h"
#include "com.google.re2j/UnicodeTables.h"
#include "com.google.re2j/Pattern.h"
#include "com.google.re2j/Matcher.h"

namespace com {namespace google {namespace re2j {





const StaticArrayObjectPrimitive<int> Utils::__EMPTY_INTS = {};
IArrayObjectPrimitive<int>* Utils::EMPTY_INTS = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__EMPTY_INTS);
String* Utils::METACHARACTERS = ConstStr::getCNST_STR_122();
constexpr const int Utils::EMPTY_BEGIN_LINE;
constexpr const int Utils::EMPTY_END_LINE;
constexpr const int Utils::EMPTY_BEGIN_TEXT;
constexpr const int Utils::EMPTY_END_TEXT;
constexpr const int Utils::EMPTY_WORD_BOUNDARY;
constexpr const int Utils::EMPTY_NO_WORD_BOUNDARY;
constexpr const int Utils::EMPTY_ALL;
bool Utils::__init_done = __init_static_variables();
bool Utils::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Utils", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Utils::Utils(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void Utils::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Utils::~Utils() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Utils::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
bool Utils::isalnum(int c, ThreadContext* ctx) throw() 
{
	return (L'0' <= (wchar_t)c && c <= (int)L'9') || (L'A' <= (wchar_t)c && c <= (int)L'Z') || (L'a' <= (wchar_t)c && c <= (int)L'z');
}
int Utils::unhex(int c, ThreadContext* ctx) throw() 
{
	if(L'0' <= (wchar_t)c && c <= (int)L'9')
	{
		return c - L'0';
	}
	if(L'a' <= (wchar_t)c && c <= (int)L'f')
	{
		return c - L'a' + 10;
	}
	if(L'A' <= (wchar_t)c && c <= (int)L'F')
	{
		return c - L'A' + 10;
	}
	return -1;
}
void Utils::escapeRune(StringBuilder* out, int rune, ThreadContext* ctx) throw() 
{
	if(Unicode::isPrint(rune, ctx))
	{
		if(METACHARACTERS->indexOf((int)((wchar_t)rune), ctx) >= 0)
		{
			out->append(L'\\', ctx);
		}
		out->appendCodePoint(rune, ctx);
		return;
	}
	switch(rune) {
	case L'"':
		out->append(ConstStr::getCNST_STR_123(), ctx);
		break ;
	case L'\\':
		out->append(ConstStr::getCNST_STR_124(), ctx);
		break ;
	case L'\t':
		out->append(ConstStr::getCNST_STR_125(), ctx);
		break ;
	case L'\n':
		out->append(ConstStr::getCNST_STR_126(), ctx);
		break ;
	case L'\r':
		out->append(ConstStr::getCNST_STR_127(), ctx);
		break ;
	case L'\b':
		out->append(ConstStr::getCNST_STR_86(), ctx);
		break ;
	case L'\f':
		out->append(ConstStr::getCNST_STR_128(), ctx);
		break ;
	default:
		{
			String* s = Integer::toHexString(rune, ctx);
			if(rune < 0x100)
			{
				out->append(ConstStr::getCNST_STR_129(), ctx);
				if(s->length(ctx) == 1)
				{
					out->append(L'0', ctx);
				}
				out->append(s, ctx);
			}
						else 
			{
				out->append(ConstStr::getCNST_STR_130(), ctx)->append(s, ctx)->append(L'}', ctx);
			}
			break ;
		}
		break;
	}
}
IArrayObjectPrimitive<int>* Utils::stringToRunes(String* str, ThreadContext* ctx) throw() 
{
	int charlen = str->length(ctx);
	int runelen = str->codePointCount(0, charlen, ctx);
	IArrayObjectPrimitive<int>* runes = ArrayAllocatorPrimitive<int>::allocatep(ctx, runelen);
	int r = 0;int c = 0;
	while(c < charlen)
	{
		int rune = str->codePointAt(c, ctx);
		runes->set(rune,r++, ctx);
		c += Character::charCount(rune, ctx);
	}
	return runes;
}
String* Utils::runeToString(int r, ThreadContext* ctx) throw() 
{
	wchar_t c = ((wchar_t)r);
	return r == (int)c ? String::valueOf(c, ctx) : (new(ctx) String(Character::toChars((int)c, ctx), ctx));
}
IArrayObjectPrimitive<int>* Utils::subarray(IArrayObjectPrimitive<int>* array, int start, int end, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* r = ArrayAllocatorPrimitive<int>::allocatep(ctx, end - start);
	for(int i = start; i < end; ++i)
	{
		r->set(array->get(i),i - start, ctx);
	}
	return r;
}
IArrayObjectPrimitive<char>* Utils::subarray(IArrayObjectPrimitive<char>* array, int start, int end, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<char>* r = ArrayAllocatorPrimitive<char>::allocatep(ctx, end - start);
	for(int i = start; i < end; ++i)
	{
		r->set(array->get(i),i - start, ctx);
	}
	return r;
}
int Utils::indexOf(IArrayObjectPrimitive<char>* source, IArrayObjectPrimitive<char>* target, int fromIndex, ThreadContext* ctx) throw() 
{
	if(fromIndex >= source->length)
	{
		return target->length == 0 ? source->length : -1;
	}
	if(fromIndex < 0)
	{
		fromIndex = 0;
	}
	if(target->length == 0)
	{
		return fromIndex;
	}
	char first = target->get(0);
	for(int i = fromIndex,  max = source->length - target->length; i <= max; i ++ )
	{
		if(source->get(i) != first)
		{
			while(++i <= max && source->get(i) != first)
			{
			}
		}
		if(i <= max)
		{
			int j = i + 1;
			int end = j + target->length - 1;
			for(int k = 1; j < end && source->get(j) == target->get(k); j ++ , k ++ )
			{
			}
			if(j == end)
			{
				return i;
			}
		}
	}
	return -1;
}
bool Utils::isWordRune(int r, ThreadContext* ctx) throw() 
{
	return ((L'A' <= (wchar_t)r && r <= (int)L'Z') || (L'a' <= (wchar_t)r && r <= (int)L'z') || (L'0' <= (wchar_t)r && r <= (int)L'9') || r == (int)L'_');
}
int Utils::emptyOpContext(int r1, int r2, ThreadContext* ctx) throw() 
{
	int op = 0;
	if(r1 < 0)
	{
		op = op | (EMPTY_BEGIN_TEXT | EMPTY_BEGIN_LINE);
	}
	if(r1 == (int)L'\n')
	{
		op = op | (EMPTY_BEGIN_LINE);
	}
	if(r2 < 0)
	{
		op = op | (EMPTY_END_TEXT | EMPTY_END_LINE);
	}
	if(r2 == (int)L'\n')
	{
		op = op | (EMPTY_END_LINE);
	}
	if(isWordRune(r1, ctx) != isWordRune(r2, ctx))
	{
		op = op | (EMPTY_WORD_BOUNDARY);
	}
		else 
	{
		op = op | (EMPTY_NO_WORD_BOUNDARY);
	}
	return op;
}
void Utils::__cleanUp(ThreadContext* ctx){
}
}}}

