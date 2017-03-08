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





constexpr const int Pattern::CASE_INSENSITIVE;
constexpr const int Pattern::DOTALL;
constexpr const int Pattern::MULTILINE;
constexpr const int Pattern::DISABLE_UNICODE_GROUPS;
bool Pattern::__init_done = __init_static_variables();
bool Pattern::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Pattern", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Pattern::Pattern(String* pattern, int flags, RE2* re2, ThreadContext* ctx) throw()  : IObject(ctx), _pattern(nullptr), _flags(0), _re2(nullptr)
{
	if(pattern == nullptr)
	{
		throw (new(ctx) NullPointerException(ConstStr::getCNST_STR_309(), ctx));
	}
	if(re2 == nullptr)
	{
		throw (new(ctx) NullPointerException(ConstStr::getCNST_STR_316(), ctx));
	}
	__GC_MV(this, &(this->_pattern), pattern, String);
	this->_flags = flags;
	__GC_MV(this, &(this->_re2), re2, RE2);
}
void Pattern::__construct_impl(String* pattern, int flags, RE2* re2, ThreadContext* ctx) throw() 
{
	if(pattern == nullptr)
	{
		throw (new(ctx) NullPointerException(ConstStr::getCNST_STR_309(), ctx));
	}
	if(re2 == nullptr)
	{
		throw (new(ctx) NullPointerException(ConstStr::getCNST_STR_316(), ctx));
	}
	__GC_MV(this, &(this->_pattern), pattern, String);
	this->_flags = flags;
	__GC_MV(this, &(this->_re2), re2, RE2);
}
 Pattern::~Pattern() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Pattern::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Pattern", L"~Pattern");
	__e_obj1.add(this->_pattern, this);
	_pattern = nullptr;
	__e_obj1.add(this->_re2, this);
	_re2 = nullptr;
	if(!prepare){
		return;
	}
}
void Pattern::reset(ThreadContext* ctx) throw() 
{
	_re2->reset(ctx);
}
int Pattern::flags(ThreadContext* ctx) throw() 
{
	return _flags;
}
String* Pattern::pattern(ThreadContext* ctx) throw() 
{
	return _pattern;
}
RE2* Pattern::re2(ThreadContext* ctx) throw() 
{
	return _re2;
}
bool Pattern::matches(String* input, ThreadContext* ctx) throw() 
{
	return this->matcher(input, ctx)->matches(ctx);
}
Matcher* Pattern::matcher(CharSequence* input, ThreadContext* ctx) throw() 
{
	return (new(ctx) Matcher(this, input, ctx));
}
IArrayObject<String>* Pattern::split(String* input, ThreadContext* ctx) throw() 
{
	return split(input, 0, ctx);
}
IArrayObject<String>* Pattern::split(String* input, int limit, ThreadContext* ctx) throw() 
{
	return split((new(ctx) Matcher(this, input, ctx)), limit, ctx);
}
String* Pattern::toString(ThreadContext* ctx) throw() 
{
	return _pattern;
}
int Pattern::groupCount(ThreadContext* ctx) throw() 
{
	return _re2->numberOfCapturingGroups(ctx);
}
IObject* Pattern::readReplace(ThreadContext* ctx)
{
	return Pattern::compile(_pattern, _flags, ctx);
}
IArrayObject<String>* Pattern::split(Matcher* m, int limit, ThreadContext* ctx) throw() 
{
	int matchCount = 0;
	int arraySize = 0;
	int last = 0;
	while(m->find(ctx))
	{
		matchCount ++ ;
		if(limit != 0 || last < m->start(ctx))
		{
			arraySize = matchCount;
		}
		last = m->end(ctx);
	}
	if(last < m->inputLength(ctx) || limit != 0)
	{
		matchCount ++ ;
		arraySize = matchCount;
	}
	int trunc = 0;
	if(limit > 0 && arraySize > limit)
	{
		arraySize = limit;
		trunc = 1;
	}
	IArrayObject<String>* array = ArrayAllocator<String>::allocate(ctx, arraySize);
	int i = 0;
	last = 0;
	m->reset(ctx);
	while(m->find(ctx) && i < arraySize - trunc)
	{
		array->set(m->substring(last, m->start(ctx), ctx),i++, ctx);
		last = m->end(ctx);
	}
	if(i < arraySize)
	{
		array->set(m->substring(last, m->inputLength(ctx), ctx),i, ctx);
	}
	return array;
}
Pattern* Pattern::compile(String* regex, ThreadContext* ctx)
{
	return compile(regex, regex, 0, ctx);
}
Pattern* Pattern::compile(String* regex, int flags, ThreadContext* ctx)
{
	String* flregex = regex;
	if((flags & CASE_INSENSITIVE) != 0)
	{
		flregex = ConstStr::getCNST_STR_317()->clone(ctx)->append(flregex, ctx);
	}
	if((flags & DOTALL) != 0)
	{
		flregex = ConstStr::getCNST_STR_318()->clone(ctx)->append(flregex, ctx);
	}
	if((flags & MULTILINE) != 0)
	{
		flregex = ConstStr::getCNST_STR_319()->clone(ctx)->append(flregex, ctx);
	}
	if((flags & ~(MULTILINE | DOTALL | CASE_INSENSITIVE | DISABLE_UNICODE_GROUPS)) != 0)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_320()->clone(ctx)->append(ConstStr::getCNST_STR_321(), ctx), ctx));
	}
	return compile(flregex, regex, flags, ctx);
}
bool Pattern::matches(String* regex, CharSequence* input, ThreadContext* ctx)
{
	return compile(regex, ctx)->matcher(input, ctx)->matches(ctx);
}
String* Pattern::quote(String* s, ThreadContext* ctx) throw() 
{
	return RE2::quoteMeta(s, ctx);
}
Pattern* Pattern::compile(String* flregex, String* regex, int flags, ThreadContext* ctx)
{
	int re2Flags = RE2::PERL;
	if((flags & DISABLE_UNICODE_GROUPS) != 0)
	{
		re2Flags = re2Flags & (~RE2::UNICODE_GROUPS);
	}
	return (new(ctx) Pattern(regex, flags, RE2::compileImpl(flregex, re2Flags, false, ctx), ctx));
}
void Pattern::__cleanUp(ThreadContext* ctx){
}
}}}

