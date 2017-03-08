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





bool UTF16Input::__init_done = __init_static_variables();
bool UTF16Input::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UTF16Input", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UTF16Input::UTF16Input(CharSequence* str, int start, int end, ThreadContext* ctx) throw()  : IObject(ctx), MachineInput(ctx), str(nullptr), start(0), end(0)
{
	__GC_MV(this, &(this->str), str, CharSequence);
	this->start = start;
	this->end = end;
}
void UTF16Input::__construct_impl(CharSequence* str, int start, int end, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->str), str, CharSequence);
	this->start = start;
	this->end = end;
}
 UTF16Input::~UTF16Input() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UTF16Input::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UTF16Input", L"~UTF16Input");
	__e_obj1.add(this->str, this);
	str = nullptr;
	if(!prepare){
		return;
	}
	MachineInput::__releaseRegerences(true, ctx);
}
int UTF16Input::step(int pos, ThreadContext* ctx) throw() 
{
	pos += start;
	if(pos < end)
	{
		int rune = Character::codePointAt(str, pos, ctx);
		int nextPos = pos + Character::charCount(rune, ctx);
		int width = nextPos - pos;
		return rune << 3 | width;
	}
		else 
	{
		return _EOF;
	}
}
bool UTF16Input::canCheckPrefix(ThreadContext* ctx) throw() 
{
	return true;
}
int UTF16Input::index(RE2* re2, int pos, ThreadContext* ctx) throw() 
{
	pos += start;
	int i = indexOf(str, re2->prefix, pos, ctx);
	return i < 0 ? i : i - pos;
}
int UTF16Input::context(int pos, ThreadContext* ctx) throw() 
{
	pos += start;
	int r1 = pos > start && pos <= end ? Character::codePointBefore(str, pos, ctx) : -1;
	int r2 = pos < end ? Character::codePointAt(str, pos, ctx) : -1;
	return Utils::emptyOpContext(r1, r2, ctx);
}
int UTF16Input::endPos(ThreadContext* ctx) throw() 
{
	return end;
}
int UTF16Input::indexOf(CharSequence* hayStack, String* needle, int pos, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<String*>(hayStack) != 0))
	{
		return (static_cast<String*>(hayStack))->indexOf(needle, pos, ctx);
	}
	if((dynamic_cast<StringBuilder*>(hayStack) != 0))
	{
		return (static_cast<StringBuilder*>(hayStack))->indexOf(needle, pos, ctx);
	}
	return indexOfFallback(hayStack, needle, pos, ctx);
}
int UTF16Input::indexOfFallback(CharSequence* hayStack, String* needle, int fromIndex, ThreadContext* ctx) throw() 
{
	if(fromIndex >= hayStack->length(ctx))
	{
		return needle->isEmpty(ctx) ? 0 : -1;
	}
	if(fromIndex < 0)
	{
		fromIndex = 0;
	}
	if(needle->isEmpty(ctx))
	{
		return fromIndex;
	}
	wchar_t first = needle->charAt(0, ctx);
	int max = hayStack->length(ctx) - needle->length(ctx);
	for(int i = fromIndex; i <= max; i ++ )
	{
		if(hayStack->charAt(i, ctx) != first)
		{
			while(++i <= max && hayStack->charAt(i, ctx) != first)
			{
			}
		}
		if(i <= max)
		{
			int j = i + 1;
			int end = j + needle->length(ctx) - 1;
			for(int k = 1; j < end && hayStack->charAt(j, ctx) == needle->charAt(k, ctx); j ++ , k ++ )
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
void UTF16Input::__cleanUp(ThreadContext* ctx){
}
}}}

