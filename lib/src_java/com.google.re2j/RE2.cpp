#include "include/global.h"


#include "java.util/Arrays.h"
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





constexpr const int RE2::FOLD_CASE;
constexpr const int RE2::LITERAL;
constexpr const int RE2::CLASS_NL;
constexpr const int RE2::DOT_NL;
constexpr const int RE2::ONE_LINE;
constexpr const int RE2::NON_GREEDY;
constexpr const int RE2::PERL_X;
constexpr const int RE2::UNICODE_GROUPS;
constexpr const int RE2::WAS_DOLLAR;
constexpr const int RE2::MATCH_NL;
constexpr const int RE2::PERL;
constexpr const int RE2::POSIX;
constexpr const int RE2::UNANCHORED;
constexpr const int RE2::ANCHOR_START;
constexpr const int RE2::ANCHOR_BOTH;
bool RE2::__init_done = __init_static_variables();
bool RE2::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RE2", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RE2::RE2(String* expr, ThreadContext* ctx) : IObject(ctx), expr(nullptr), prog(nullptr), cond(0), numSubexp(0), longest(0), prefix(nullptr), prefixUTF8(nullptr), prefixComplete(0), prefixRune(0), machine(GCUtils<List<Machine> >::ins(this, (new(ctx) ArrayList<Machine>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	RE2* re2 = RE2::compile(expr, ctx);
	__GC_MV(this, &(this->expr), re2->expr, String);
	__GC_MV(this, &(this->prog), re2->prog, Prog);
	this->cond = re2->cond;
	this->numSubexp = re2->numSubexp;
	this->longest = re2->longest;
	__GC_MV(this, &(this->prefix), re2->prefix, String);
	__GC_MV(this, &(this->prefixUTF8), re2->prefixUTF8, IArrayObjectPrimitive<char>);
	this->prefixComplete = re2->prefixComplete;
	this->prefixRune = re2->prefixRune;
}
void RE2::__construct_impl(String* expr, ThreadContext* ctx)
{
	RE2* re2 = RE2::compile(expr, ctx);
	__GC_MV(this, &(this->expr), re2->expr, String);
	__GC_MV(this, &(this->prog), re2->prog, Prog);
	this->cond = re2->cond;
	this->numSubexp = re2->numSubexp;
	this->longest = re2->longest;
	__GC_MV(this, &(this->prefix), re2->prefix, String);
	__GC_MV(this, &(this->prefixUTF8), re2->prefixUTF8, IArrayObjectPrimitive<char>);
	this->prefixComplete = re2->prefixComplete;
	this->prefixRune = re2->prefixRune;
}
 RE2::RE2(String* expr, Prog* prog, int numSubexp, bool longest, ThreadContext* ctx) throw()  : IObject(ctx), expr(nullptr), prog(nullptr), cond(0), numSubexp(0), longest(0), prefix(nullptr), prefixUTF8(nullptr), prefixComplete(0), prefixRune(0), machine(GCUtils<List<Machine> >::ins(this, (new(ctx) ArrayList<Machine>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->expr), expr, String);
	__GC_MV(this, &(this->prog), prog, Prog);
	this->numSubexp = numSubexp;
	this->cond = prog->startCond(ctx);
	this->longest = longest;
}
void RE2::__construct_impl(String* expr, Prog* prog, int numSubexp, bool longest, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->expr), expr, String);
	__GC_MV(this, &(this->prog), prog, Prog);
	this->numSubexp = numSubexp;
	this->cond = prog->startCond(ctx);
	this->longest = longest;
}
 RE2::~RE2() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RE2::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RE2", L"~RE2");
	__e_obj1.add(this->expr, this);
	expr = nullptr;
	__e_obj1.add(this->prog, this);
	prog = nullptr;
	__e_obj1.add(this->prefix, this);
	prefix = nullptr;
	__e_obj1.add(this->prefixUTF8, this);
	prefixUTF8 = nullptr;
	__e_obj1.add(this->machine, this);
	machine = nullptr;
	if(!prepare){
		return;
	}
}
String* RE2::toString(ThreadContext* ctx) throw() 
{
	return expr;
}
int RE2::numberOfCapturingGroups(ThreadContext* ctx) throw() 
{
	return numSubexp;
}
Machine* RE2::get(ThreadContext* ctx) throw() 
{
	int n = machine->size(ctx);
	if(n > 0)
	{
		return machine->remove(n - 1, ctx);
	}
	return (new(ctx) Machine(this, ctx));
}
void RE2::reset(ThreadContext* ctx) throw() 
{
	machine->clear(ctx);
}
void RE2::put(Machine* m, ThreadContext* ctx) throw() 
{
	machine->add(m, ctx);
}
bool RE2::match(CharSequence* s, ThreadContext* ctx) throw() 
{
	return doExecute(MachineInput::fromUTF16(s, ctx), 0, UNANCHORED, 0, ctx) != (IArrayObjectPrimitive<int>*)nullptr;
}
bool RE2::match(CharSequence* input, int start, int end, int anchor, IArrayObjectPrimitive<int>* group, int ngroup, ThreadContext* ctx) throw() 
{
	if(start > end)
	{
		return false;
	}
	IArrayObjectPrimitive<int>* groupMatch = doExecute(MachineInput::fromUTF16(input, 0, end, ctx), start, anchor, 2 * ngroup, ctx);
	if(groupMatch == (IArrayObjectPrimitive<int>*)nullptr)
	{
		return false;
	}
	if(group != (IArrayObjectPrimitive<int>*)nullptr)
	{
		System::arraycopy(groupMatch, 0, group, 0, groupMatch->length, ctx);
	}
	return true;
}
bool RE2::matchUTF8(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() 
{
	return doExecute(MachineInput::fromUTF8(b, ctx), 0, UNANCHORED, 0, ctx) != (IArrayObjectPrimitive<int>*)nullptr;
}
String* RE2::replaceAll(String* src, String* repl, ThreadContext* ctx) throw() 
{
	return replaceAllFunc(src, new RE2Anonimous0(repl, ctx), 2 * src->length(ctx) + 1, ctx);
}
String* RE2::replaceFirst(String* src, String* repl, ThreadContext* ctx) throw() 
{
	return replaceAllFunc(src, new RE2Anonimous1(repl, ctx), 1, ctx);
}
String* RE2::replaceAllFunc(String* src, RE2::ReplaceFunc* repl, int maxReplaces, ThreadContext* ctx) throw() 
{
	int lastMatchEnd = 0;
	int searchPos = 0;
	StringBuilder* buf = (new(ctx) StringBuilder(ctx));
	MachineInput* input = MachineInput::fromUTF16(src, ctx);
	int numReplaces = 0;
	while(searchPos <= src->length(ctx))
	{
		IArrayObjectPrimitive<int>* a = doExecute(input, searchPos, UNANCHORED, 2, ctx);
		if(a == (IArrayObjectPrimitive<int>*)nullptr || a->length == 0)
		{
			break ;
		}
		buf->append(src->substring(lastMatchEnd, a->get(0), ctx), ctx);
		if(a->get(1) > lastMatchEnd || a->get(0) == 0)
		{
			buf->append(repl->replace(src->substring(a->get(0), a->get(1), ctx), ctx), ctx);
			++numReplaces;
		}
		lastMatchEnd = a->get(1);
		int width = input->step(searchPos, ctx) & 0x7;
		if(searchPos + width > a->get(1))
		{
			searchPos += width;
		}
				else 
		{
			if(searchPos + 1 > a->get(1))
			{
				searchPos ++ ;
			}
						else 
			{
				searchPos = a->get(1);
			}
		}
		if(numReplaces >= maxReplaces)
		{
			break ;
		}
	}
	buf->append(src->substring(lastMatchEnd, ctx), ctx);
	return buf->toString(ctx);
}
IArrayObjectPrimitive<char>* RE2::findUTF8(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* a = doExecute(MachineInput::fromUTF8(b, ctx), 0, UNANCHORED, 2, ctx);
	if(a == (IArrayObjectPrimitive<int>*)nullptr)
	{
		return nullptr;
	}
	return Utils::subarray(b, a->get(0), a->get(1), ctx);
}
IArrayObjectPrimitive<int>* RE2::findUTF8Index(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* a = doExecute(MachineInput::fromUTF8(b, ctx), 0, UNANCHORED, 2, ctx);
	if(a == (IArrayObjectPrimitive<int>*)nullptr)
	{
		return nullptr;
	}
	return Utils::subarray(a, 0, 2, ctx);
}
String* RE2::find(String* s, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* a = doExecute(MachineInput::fromUTF16(s, ctx), 0, UNANCHORED, 2, ctx);
	if(a == (IArrayObjectPrimitive<int>*)nullptr)
	{
		return ConstStr::getCNST_STR_4();
	}
	return s->substring(a->get(0), a->get(1), ctx);
}
IArrayObjectPrimitive<int>* RE2::findIndex(String* s, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* a = doExecute(MachineInput::fromUTF16(s, ctx), 0, UNANCHORED, 2, ctx);
	if(a == (IArrayObjectPrimitive<int>*)nullptr)
	{
		return nullptr;
	}
	return a;
}
IArrayObject<IArrayObjectPrimitive<char>>* RE2::findUTF8Submatch(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* a = doExecute(MachineInput::fromUTF8(b, ctx), 0, UNANCHORED, prog->numCap, ctx);
	if(a == (IArrayObjectPrimitive<int>*)nullptr)
	{
		return nullptr;
	}
	IArrayObject<IArrayObjectPrimitive<char>>* ret = ArrayAllocatorPrimitive<char>::allocatep(ctx, 1 + numSubexp, 0);
	for(int i = 0; i < ret->length; i ++ )
	{
		if(2 * i < a->length && a->get(2 * i) >= 0)
		{
			ret->set(Utils::subarray(b, a->get(2 * i), a->get(2 * i + 1), ctx),i, ctx);
		}
	}
	return ret;
}
IArrayObjectPrimitive<int>* RE2::findUTF8SubmatchIndex(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() 
{
	return pad(doExecute(MachineInput::fromUTF8(b, ctx), 0, UNANCHORED, prog->numCap, ctx), ctx);
}
IArrayObject<String>* RE2::findSubmatch(String* s, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* a = doExecute(MachineInput::fromUTF16(s, ctx), 0, UNANCHORED, prog->numCap, ctx);
	if(a == (IArrayObjectPrimitive<int>*)nullptr)
	{
		return nullptr;
	}
	IArrayObject<String>* ret = ArrayAllocator<String>::allocate(ctx, 1 + numSubexp);
	for(int i = 0; i < ret->length; i ++ )
	{
		if(2 * i < a->length && a->get(2 * i) >= 0)
		{
			ret->set(s->substring(a->get(2 * i), a->get(2 * i + 1), ctx),i, ctx);
		}
	}
	return ret;
}
IArrayObjectPrimitive<int>* RE2::findSubmatchIndex(String* s, ThreadContext* ctx) throw() 
{
	return pad(doExecute(MachineInput::fromUTF16(s, ctx), 0, UNANCHORED, prog->numCap, ctx), ctx);
}
List<IArrayObjectPrimitive<char>>* RE2::findAllUTF8(IArrayObjectPrimitive<char>* b, int n, ThreadContext* ctx) throw() 
{
	List<IArrayObjectPrimitive<char>>* result = (new(ctx) ArrayList<IArrayObjectPrimitive<char>>(ctx));
	
	allMatches(MachineInput::fromUTF8(b, ctx), n, new RE2Anonimous2(result, b, ctx), ctx);
	if(result->isEmpty(ctx))
	{
		return nullptr;
	}
	return result;
}
List<IArrayObjectPrimitive<int>>* RE2::findAllUTF8Index(IArrayObjectPrimitive<char>* b, int n, ThreadContext* ctx) throw() 
{
	List<IArrayObjectPrimitive<int>>* result = (new(ctx) ArrayList<IArrayObjectPrimitive<int>>(ctx));
	
	allMatches(MachineInput::fromUTF8(b, ctx), n, new RE2Anonimous3(result, b, ctx), ctx);
	if(result->isEmpty(ctx))
	{
		return nullptr;
	}
	return result;
}
List<String>* RE2::findAll(String* s, int n, ThreadContext* ctx) throw() 
{
	List<String>* result = (new(ctx) ArrayList<String>(ctx));
	
	allMatches(MachineInput::fromUTF16(s, ctx), n, new RE2Anonimous4(result, s, ctx), ctx);
	if(result->isEmpty(ctx))
	{
		return nullptr;
	}
	return result;
}
List<IArrayObjectPrimitive<int>>* RE2::findAllIndex(String* s, int n, ThreadContext* ctx) throw() 
{
	List<IArrayObjectPrimitive<int>>* result = (new(ctx) ArrayList<IArrayObjectPrimitive<int>>(ctx));
	
	allMatches(MachineInput::fromUTF16(s, ctx), n, new RE2Anonimous5(result, ctx), ctx);
	if(result->isEmpty(ctx))
	{
		return nullptr;
	}
	return result;
}
List<IArrayObject<IArrayObjectPrimitive<char>>>* RE2::findAllUTF8Submatch(IArrayObjectPrimitive<char>* b, int n, ThreadContext* ctx) throw() 
{
	List<IArrayObject<IArrayObjectPrimitive<char>>>* result = (new(ctx) ArrayList<IArrayObject<IArrayObjectPrimitive<char>>>(ctx));
	
	allMatches(MachineInput::fromUTF8(b, ctx), n, new RE2Anonimous6(result, b, ctx), ctx);
	if(result->isEmpty(ctx))
	{
		return nullptr;
	}
	return result;
}
List<IArrayObjectPrimitive<int>>* RE2::findAllUTF8SubmatchIndex(IArrayObjectPrimitive<char>* b, int n, ThreadContext* ctx) throw() 
{
	List<IArrayObjectPrimitive<int>>* result = (new(ctx) ArrayList<IArrayObjectPrimitive<int>>(ctx));
	
	allMatches(MachineInput::fromUTF8(b, ctx), n, new RE2Anonimous7(result, ctx), ctx);
	if(result->isEmpty(ctx))
	{
		return nullptr;
	}
	return result;
}
List<IArrayObject<String>>* RE2::findAllSubmatch(String* s, int n, ThreadContext* ctx) throw() 
{
	List<IArrayObject<String>>* result = (new(ctx) ArrayList<IArrayObject<String>>(ctx));
	
	allMatches(MachineInput::fromUTF16(s, ctx), n, new RE2Anonimous8(result, s, ctx), ctx);
	if(result->isEmpty(ctx))
	{
		return nullptr;
	}
	return result;
}
List<IArrayObjectPrimitive<int>>* RE2::findAllSubmatchIndex(String* s, int n, ThreadContext* ctx) throw() 
{
	List<IArrayObjectPrimitive<int>>* result = (new(ctx) ArrayList<IArrayObjectPrimitive<int>>(ctx));
	
	allMatches(MachineInput::fromUTF16(s, ctx), n, new RE2Anonimous9(result, ctx), ctx);
	if(result->isEmpty(ctx))
	{
		return nullptr;
	}
	return result;
}
IArrayObjectPrimitive<int>* RE2::doExecute(MachineInput* in, int pos, int anchor, int ncap, ThreadContext* ctx) throw() 
{
	Machine* m = get(ctx);
	m->init(ncap, ctx);
	IArrayObjectPrimitive<int>* cap = m->match(in, pos, anchor, ctx) ? m->submatches(ctx) : nullptr;
	put(m, ctx);
	return cap;
}
IArrayObjectPrimitive<int>* RE2::pad(IArrayObjectPrimitive<int>* a, ThreadContext* ctx) throw() 
{
	if(a == (IArrayObjectPrimitive<int>*)nullptr)
	{
		return nullptr;
	}
	int n = (1 + numSubexp) * 2;
	if(a->length < n)
	{
		IArrayObjectPrimitive<int>* a2 = ArrayAllocatorPrimitive<int>::allocatep(ctx, n);
		System::arraycopy(a, 0, a2, 0, a->length, ctx);
		Arrays::fill(a2, a->length, n, -1, ctx);
		a = a2;
	}
	return a;
}
void RE2::allMatches(MachineInput* input, int n, RE2::DeliverFunc* deliver, ThreadContext* ctx) throw() 
{
	int end = input->endPos(ctx);
	if(n < 0)
	{
		n = end + 1;
	}
	for(int pos = 0,  i = 0, prevMatchEnd = -1; i < n && pos <= end; )
	{
		IArrayObjectPrimitive<int>* matches = doExecute(input, pos, UNANCHORED, prog->numCap, ctx);
		if(matches == (IArrayObjectPrimitive<int>*)nullptr || matches->length == 0)
		{
			break ;
		}
		bool accept = true;
		if(matches->get(1) == pos)
		{
			if(matches->get(0) == prevMatchEnd)
			{
				accept = false;
			}
			int r = input->step(pos, ctx);
			if(r < 0)
			{
				pos = end + 1;
			}
						else 
			{
				pos += r & 0x7;
			}
		}
				else 
		{
			pos = matches->get(1);
		}
		prevMatchEnd = matches->get(1);
		if(accept)
		{
			deliver->deliver(pad(matches, ctx), ctx);
			i ++ ;
		}
	}
}
RE2* RE2::compile(String* expr, ThreadContext* ctx)
{
	return compileImpl(expr, PERL, false, ctx);
}
RE2* RE2::compilePOSIX(String* expr, ThreadContext* ctx)
{
	return compileImpl(expr, POSIX, true, ctx);
}
RE2* RE2::compileImpl(String* expr, int mode, bool longest, ThreadContext* ctx)
{
	Regexp* re = Parser::parse(expr, mode, ctx);
	int maxCap = re->maxCap(ctx);
	re = Simplify::simplify(re, ctx);
	Prog* prog = Compiler::compileRegexp(re, ctx);
	RE2* re2 = (new(ctx) RE2(expr, prog, maxCap, longest, ctx));
	StringBuilder* prefixBuilder = (new(ctx) StringBuilder(ctx));
	re2->prefixComplete = prog->prefix(prefixBuilder, ctx);
	__GC_MV(re2, &(re2->prefix), prefixBuilder->toString(ctx), String);
	{
		try
		{
			__GC_MV(re2, &(re2->prefixUTF8), re2->prefix->getBytes(ConstStr::getCNST_STR_120(), ctx), IArrayObjectPrimitive<char>);
		}
		catch(UnsupportedEncodingException* e)
		{
			throw (new(ctx) IllegalStateException(ConstStr::getCNST_STR_121(), ctx));
		}
	}
	if(!re2->prefix->isEmpty(ctx))
	{
		re2->prefixRune = re2->prefix->codePointAt(0, ctx);
	}
	return re2;
}
bool RE2::match(String* pattern, CharSequence* s, ThreadContext* ctx)
{
	return compile(pattern, ctx)->match(s, ctx);
}
String* RE2::quoteMeta(String* s, ThreadContext* ctx) throw() 
{
	StringBuilder* b = (new(ctx) StringBuilder(2 * s->length(ctx), ctx));
	for(int i = 0,  len = s->length(ctx); i < len; i ++ )
	{
		wchar_t c = s->charAt(i, ctx);
		if(ConstStr::getCNST_STR_122()->indexOf((int)c, ctx) >= 0)
		{
			b->append(L'\\', ctx);
		}
		b->append(c, ctx);
	}
	return b->toString(ctx);
}
void RE2::__cleanUp(ThreadContext* ctx){
}
RE2Anonimous0::RE2Anonimous0(String* repl, ThreadContext* ctx)
: IObject(ctx), ReplaceFunc(ctx) ,repl(repl)
{
	__GC_INS(this, repl, String);
}
RE2Anonimous0::~RE2Anonimous0() throw() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	{
		ObjectEraser __e_obj(ctx, __FILEW__, __LINE__, L"RE2Anonimous0", L"~RE2Anonimous0()");
		__e_obj.add(this->repl, this);
	}
}
void RE2Anonimous0::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
}
void RE2Anonimous0::__init(ThreadContext* ctx) throw()
{
	repl = nullptr;
}
String* RE2Anonimous0::replace(String* orig, ThreadContext* ctx) throw()
{
	return repl;
}
RE2Anonimous1::RE2Anonimous1(String* repl, ThreadContext* ctx)
: IObject(ctx), ReplaceFunc(ctx) ,repl(repl)
{
	__GC_INS(this, repl, String);
}
RE2Anonimous1::~RE2Anonimous1() throw() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	{
		ObjectEraser __e_obj(ctx, __FILEW__, __LINE__, L"RE2Anonimous1", L"~RE2Anonimous1()");
		__e_obj.add(this->repl, this);
	}
}
void RE2Anonimous1::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
}
void RE2Anonimous1::__init(ThreadContext* ctx) throw()
{
	repl = nullptr;
}
String* RE2Anonimous1::replace(String* orig, ThreadContext* ctx) throw()
{
	return repl;
}
RE2Anonimous2::RE2Anonimous2(List<IArrayObjectPrimitive<char>>* result, IArrayObjectPrimitive<char>* b, ThreadContext* ctx)
: IObject(ctx), DeliverFunc(ctx) ,result(result),b(b)
{
	__GC_INS(this, result, List<IArrayObjectPrimitive<char>>);
	__GC_INS(this, b, IArrayObjectPrimitive<char>);
}
RE2Anonimous2::~RE2Anonimous2() throw() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	{
		ObjectEraser __e_obj(ctx, __FILEW__, __LINE__, L"RE2Anonimous2", L"~RE2Anonimous2()");
		__e_obj.add(this->result, this);
		__e_obj.add(this->b, this);
	}
}
void RE2Anonimous2::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
}
void RE2Anonimous2::__init(ThreadContext* ctx) throw()
{
	result = nullptr;
	b = nullptr;
}
void RE2Anonimous2::deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw()
{
	result->add(Utils::subarray(b, match->get(0), match->get(1), ctx), ctx);
}
RE2Anonimous3::RE2Anonimous3(List<IArrayObjectPrimitive<int>>* result, IArrayObjectPrimitive<char>* b, ThreadContext* ctx)
: IObject(ctx), DeliverFunc(ctx) ,result(result),b(b)
{
	__GC_INS(this, result, List<IArrayObjectPrimitive<int>>);
	__GC_INS(this, b, IArrayObjectPrimitive<char>);
}
RE2Anonimous3::~RE2Anonimous3() throw() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	{
		ObjectEraser __e_obj(ctx, __FILEW__, __LINE__, L"RE2Anonimous3", L"~RE2Anonimous3()");
		__e_obj.add(this->result, this);
		__e_obj.add(this->b, this);
	}
}
void RE2Anonimous3::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
}
void RE2Anonimous3::__init(ThreadContext* ctx) throw()
{
	result = nullptr;
	b = nullptr;
}
void RE2Anonimous3::deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw()
{
	result->add(Utils::subarray(match, 0, 2, ctx), ctx);
}
RE2Anonimous4::RE2Anonimous4(List<String>* result, String* s, ThreadContext* ctx)
: IObject(ctx), DeliverFunc(ctx) ,result(result),s(s)
{
	__GC_INS(this, result, List<String>);
	__GC_INS(this, s, String);
}
RE2Anonimous4::~RE2Anonimous4() throw() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	{
		ObjectEraser __e_obj(ctx, __FILEW__, __LINE__, L"RE2Anonimous4", L"~RE2Anonimous4()");
		__e_obj.add(this->result, this);
		__e_obj.add(this->s, this);
	}
}
void RE2Anonimous4::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
}
void RE2Anonimous4::__init(ThreadContext* ctx) throw()
{
	result = nullptr;
	s = nullptr;
}
void RE2Anonimous4::deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw()
{
	result->add(s->substring(match->get(0), match->get(1), ctx), ctx);
}
RE2Anonimous5::RE2Anonimous5(List<IArrayObjectPrimitive<int>>* result, ThreadContext* ctx)
: IObject(ctx), DeliverFunc(ctx) ,result(result)
{
	__GC_INS(this, result, List<IArrayObjectPrimitive<int>>);
}
RE2Anonimous5::~RE2Anonimous5() throw() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	{
		ObjectEraser __e_obj(ctx, __FILEW__, __LINE__, L"RE2Anonimous5", L"~RE2Anonimous5()");
		__e_obj.add(this->result, this);
	}
}
void RE2Anonimous5::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
}
void RE2Anonimous5::__init(ThreadContext* ctx) throw()
{
	result = nullptr;
}
void RE2Anonimous5::deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw()
{
	result->add(Utils::subarray(match, 0, 2, ctx), ctx);
}
RE2Anonimous6::RE2Anonimous6(List<IArrayObject<IArrayObjectPrimitive<char>>>* result, IArrayObjectPrimitive<char>* b, ThreadContext* ctx)
: IObject(ctx), DeliverFunc(ctx) ,result(result),b(b)
{
	__GC_INS(this, result, List<IArrayObject<IArrayObjectPrimitive<char>>>);
	__GC_INS(this, b, IArrayObjectPrimitive<char>);
}
RE2Anonimous6::~RE2Anonimous6() throw() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	{
		ObjectEraser __e_obj(ctx, __FILEW__, __LINE__, L"RE2Anonimous6", L"~RE2Anonimous6()");
		__e_obj.add(this->result, this);
		__e_obj.add(this->b, this);
	}
}
void RE2Anonimous6::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
}
void RE2Anonimous6::__init(ThreadContext* ctx) throw()
{
	result = nullptr;
	b = nullptr;
}
void RE2Anonimous6::deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw()
{
	IArrayObject<IArrayObjectPrimitive<char>>* slice = ArrayAllocatorPrimitive<char>::allocatep(ctx, match->length / 2, 0);
	for(int j = 0; j < slice->length; ++j)
	{
		if(match->get(2 * j) >= 0)
		{
			slice->set(Utils::subarray(b, match->get(2 * j), match->get(2 * j + 1), ctx),j, ctx);
		}
	}
	result->add(slice, ctx);
}
RE2Anonimous7::RE2Anonimous7(List<IArrayObjectPrimitive<int>>* result, ThreadContext* ctx)
: IObject(ctx), DeliverFunc(ctx) ,result(result)
{
	__GC_INS(this, result, List<IArrayObjectPrimitive<int>>);
}
RE2Anonimous7::~RE2Anonimous7() throw() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	{
		ObjectEraser __e_obj(ctx, __FILEW__, __LINE__, L"RE2Anonimous7", L"~RE2Anonimous7()");
		__e_obj.add(this->result, this);
	}
}
void RE2Anonimous7::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
}
void RE2Anonimous7::__init(ThreadContext* ctx) throw()
{
	result = nullptr;
}
void RE2Anonimous7::deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw()
{
	result->add(match, ctx);
}
RE2Anonimous8::RE2Anonimous8(List<IArrayObject<String>>* result, String* s, ThreadContext* ctx)
: IObject(ctx), DeliverFunc(ctx) ,result(result),s(s)
{
	__GC_INS(this, result, List<IArrayObject<String>>);
	__GC_INS(this, s, String);
}
RE2Anonimous8::~RE2Anonimous8() throw() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	{
		ObjectEraser __e_obj(ctx, __FILEW__, __LINE__, L"RE2Anonimous8", L"~RE2Anonimous8()");
		__e_obj.add(this->result, this);
		__e_obj.add(this->s, this);
	}
}
void RE2Anonimous8::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
}
void RE2Anonimous8::__init(ThreadContext* ctx) throw()
{
	result = nullptr;
	s = nullptr;
}
void RE2Anonimous8::deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw()
{
	IArrayObject<String>* slice = ArrayAllocator<String>::allocate(ctx, match->length / 2);
	for(int j = 0; j < slice->length; ++j)
	{
		if(match->get(2 * j) >= 0)
		{
			slice->set(s->substring(match->get(2 * j), match->get(2 * j + 1), ctx),j, ctx);
		}
	}
	result->add(slice, ctx);
}
RE2Anonimous9::RE2Anonimous9(List<IArrayObjectPrimitive<int>>* result, ThreadContext* ctx)
: IObject(ctx), DeliverFunc(ctx) ,result(result)
{
	__GC_INS(this, result, List<IArrayObjectPrimitive<int>>);
}
RE2Anonimous9::~RE2Anonimous9() throw() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	{
		ObjectEraser __e_obj(ctx, __FILEW__, __LINE__, L"RE2Anonimous9", L"~RE2Anonimous9()");
		__e_obj.add(this->result, this);
	}
}
void RE2Anonimous9::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
}
void RE2Anonimous9::__init(ThreadContext* ctx) throw()
{
	result = nullptr;
}
void RE2Anonimous9::deliver(IArrayObjectPrimitive<int>* match, ThreadContext* ctx) throw()
{
	result->add(match, ctx);
}
}}}

namespace com {namespace google {namespace re2j {




bool RE2::ReplaceFunc::__init_done = __init_static_variables();
bool RE2::ReplaceFunc::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RE2::ReplaceFunc", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RE2::ReplaceFunc::ReplaceFunc(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void RE2::ReplaceFunc::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RE2::ReplaceFunc::~ReplaceFunc() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RE2::ReplaceFunc::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void RE2::ReplaceFunc::__cleanUp(ThreadContext* ctx){
}
}}}

namespace com {namespace google {namespace re2j {




bool RE2::DeliverFunc::__init_done = __init_static_variables();
bool RE2::DeliverFunc::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RE2::DeliverFunc", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RE2::DeliverFunc::DeliverFunc(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void RE2::DeliverFunc::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RE2::DeliverFunc::~DeliverFunc() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RE2::DeliverFunc::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void RE2::DeliverFunc::__cleanUp(ThreadContext* ctx){
}
}}}

