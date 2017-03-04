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
#include "com.google.re2j/Compiler.h"
#include "com.google.re2j/UnicodeTable2.h"
#include "com.google.re2j/Utils.h"
#include "com.google.re2j/UnicodeTables.h"
#include "com.google.re2j/Pattern.h"
#include "com.google.re2j/Matcher.h"

namespace com {namespace google {namespace re2j {



constexpr EnumBase __Inst__Op::__DEFAULT_NULL;
constexpr EnumBase __Inst__Op::ALT;
constexpr EnumBase __Inst__Op::ALT_MATCH;
constexpr EnumBase __Inst__Op::CAPTURE;
constexpr EnumBase __Inst__Op::EMPTY_WIDTH;
constexpr EnumBase __Inst__Op::FAIL;
constexpr EnumBase __Inst__Op::MATCH;
constexpr EnumBase __Inst__Op::NOP;
constexpr EnumBase __Inst__Op::RUNE;
constexpr EnumBase __Inst__Op::RUNE1;
constexpr EnumBase __Inst__Op::RUNE_ANY;
constexpr EnumBase __Inst__Op::RUNE_ANY_NOT_NL;


bool Inst::__init_done = __init_static_variables();
bool Inst::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Inst", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Inst::Inst(Inst::Op op, ThreadContext* ctx) throw()  : IObject(ctx), out(0), arg(0), runes(nullptr)
{
	this->_op = op;
}
void Inst::__construct_impl(Inst::Op op, ThreadContext* ctx) throw() 
{
	this->_op = op;
}
 Inst::~Inst() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Inst::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Inst", L"~Inst");
	__e_obj1.add(this->runes, this);
	runes = nullptr;
	if(!prepare){
		return;
	}
}
String* Inst::toString(ThreadContext* ctx) throw() 
{
	switch(_op) {
	case Inst::Op::ALT:
		return ConstStr::getCNST_STR_294()->clone(ctx)->append(out, ctx)->append(ConstStr::getCNST_STR_73(), ctx)->append(arg, ctx);
	case Inst::Op::ALT_MATCH:
		return ConstStr::getCNST_STR_295()->clone(ctx)->append(out, ctx)->append(ConstStr::getCNST_STR_73(), ctx)->append(arg, ctx);
	case Inst::Op::CAPTURE:
		return ConstStr::getCNST_STR_296()->clone(ctx)->append(arg, ctx)->append(ConstStr::getCNST_STR_297(), ctx)->append(out, ctx);
	case Inst::Op::EMPTY_WIDTH:
		return ConstStr::getCNST_STR_298()->clone(ctx)->append(arg, ctx)->append(ConstStr::getCNST_STR_297(), ctx)->append(out, ctx);
	case Inst::Op::MATCH:
		return ConstStr::getCNST_STR_299();
	case Inst::Op::FAIL:
		return ConstStr::getCNST_STR_300();
	case Inst::Op::NOP:
		return ConstStr::getCNST_STR_301()->clone(ctx)->append(out, ctx);
	case Inst::Op::RUNE:
		if(runes == (IArrayObjectPrimitive<int>*)nullptr)
		{
			return ConstStr::getCNST_STR_302();
		}
		return ConstStr::getCNST_STR_303()->clone(ctx)->append(escapeRunes(runes, ctx), ctx)->append((((arg & RE2::FOLD_CASE) != 0) ? ConstStr::getCNST_STR_304() : ConstStr::getCNST_STR_4()), ctx)->append(ConstStr::getCNST_STR_297(), ctx)->append(out, ctx);
	case Inst::Op::RUNE1:
		return ConstStr::getCNST_STR_305()->clone(ctx)->append(escapeRunes(runes, ctx), ctx)->append(ConstStr::getCNST_STR_297(), ctx)->append(out, ctx);
	case Inst::Op::RUNE_ANY:
		return ConstStr::getCNST_STR_306()->clone(ctx)->append(out, ctx);
	case Inst::Op::RUNE_ANY_NOT_NL:
		return ConstStr::getCNST_STR_307()->clone(ctx)->append(out, ctx);
	default:
		throw (new(ctx) IllegalStateException(ConstStr::getCNST_STR_308(), ctx));
		break;
	}
}
Inst::Op Inst::op(ThreadContext* ctx) throw() 
{
	switch(_op) {
	case Inst::Op::RUNE1:
	case Inst::Op::RUNE_ANY:
	case Inst::Op::RUNE_ANY_NOT_NL:
		return Op::RUNE;
	default:
		return _op;
		break;
	}
}
bool Inst::matchRune(int r, ThreadContext* ctx) throw() 
{
	if(runes->length == 1)
	{
		int r0 = runes->get(0);
		if(r == r0)
		{
			return true;
		}
		if((arg & RE2::FOLD_CASE) != 0)
		{
			for(int r1 = Unicode::simpleFold(r0, ctx); r1 != r0; r1 = Unicode::simpleFold(r1, ctx))
			{
				if(r == r1)
				{
					return true;
				}
			}
		}
		return false;
	}
	for(int j = 0; j < runes->length && j <= 8; j += 2)
	{
		if(r < runes->get(j))
		{
			return false;
		}
		if(r <= runes->get(j + 1))
		{
			return true;
		}
	}
	for(int lo = 0,  hi = runes->length / 2; lo < hi; )
	{
		int m = lo + (hi - lo) / 2;
		int c = runes->get(2 * m);
		if(c <= r)
		{
			if(r <= runes->get(2 * m + 1))
			{
				return true;
			}
			lo = m + 1;
		}
				else 
		{
			hi = m;
		}
	}
	return false;
}
String* Inst::escapeRunes(IArrayObjectPrimitive<int>* runes, ThreadContext* ctx) throw() 
{
	StringBuilder* out = (new(ctx) StringBuilder(ctx));
	out->append(L'"', ctx);
	{
		const int __max_for = runes->length;
		for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
			int rune = runes->get(__i_loop);
			{
				Utils::escapeRune(out, rune, ctx);
			}
		}
	}
	out->append(L'"', ctx);
	return out->toString(ctx);
}
}}}

