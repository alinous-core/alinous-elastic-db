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





bool Simplify::__init_done = __init_static_variables();
bool Simplify::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Simplify", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Simplify::~Simplify() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Simplify::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
Regexp* Simplify::simplify(Regexp* re, ThreadContext* ctx) throw() 
{
	if(re == nullptr)
	{
		return nullptr;
	}
	switch(re->op) {
	case Regexp::Op::CAPTURE:
	case Regexp::Op::CONCAT:
	case Regexp::Op::ALTERNATE:
		{
			Regexp* nre = re;
			for(int i = 0; i < re->subs->length; ++i)
			{
				Regexp* sub = re->subs->get(i);
				Regexp* nsub = simplify(sub, ctx);
				if(nre == re && nsub != sub)
				{
					nre = (new(ctx) Regexp(re, ctx));
					__GC_MV(nre, &(nre->runes), nullptr, IArrayObjectPrimitive<int>);
					__GC_MV(nre, &(nre->subs), Parser::subarray(re->subs, 0, re->subs->length, ctx), IArrayObject<Regexp>);
				}
				if(nre != re)
				{
					nre->subs->set(nsub,i, ctx);
				}
			}
			return nre;
		}
	case Regexp::Op::STAR:
	case Regexp::Op::PLUS:
	case Regexp::Op::QUEST:
		{
			Regexp* sub = simplify(re->subs->get(0), ctx);
			return simplify1(re->op, re->flags, sub, re, ctx);
		}
	case Regexp::Op::REPEAT:
		{
			if(re->min == 0 && re->max == 0)
			{
				return (new(ctx) Regexp(Regexp::Op::EMPTY_MATCH, ctx));
			}
			Regexp* sub = simplify(re->subs->get(0), ctx);
			if(re->max == -1)
			{
				if(re->min == 0)
				{
					return simplify1(Regexp::Op::STAR, re->flags, sub, nullptr, ctx);
				}
				if(re->min == 1)
				{
					return simplify1(Regexp::Op::PLUS, re->flags, sub, nullptr, ctx);
				}
				Regexp* nre = (new(ctx) Regexp(Regexp::Op::CONCAT, ctx));
				ArrayList<Regexp>* subs = (new(ctx) ArrayList<Regexp>(ctx));
				for(int i = 0; i < re->min - 1; i ++ )
				{
					subs->add(sub, ctx);
				}
				subs->add(simplify1(Regexp::Op::PLUS, re->flags, sub, nullptr, ctx), ctx);
				__GC_MV(nre, &(nre->subs), subs->toArray(ArrayAllocator<Regexp>::allocate(ctx, subs->size(ctx)), ctx), IArrayObject<Regexp>);
				return nre;
			}
			if(re->min == 1 && re->max == 1)
			{
				return sub;
			}
			ArrayList<Regexp>* prefixSubs = nullptr;
			if(re->min > 0)
			{
				prefixSubs = (new(ctx) ArrayList<Regexp>(ctx));
				for(int i = 0; i < re->min; i ++ )
				{
					prefixSubs->add(sub, ctx);
				}
			}
			if(re->max > re->min)
			{
				Regexp* suffix = simplify1(Regexp::Op::QUEST, re->flags, sub, nullptr, ctx);
				for(int i = re->min + 1; i < re->max; i ++ )
				{
					Regexp* nre2 = (new(ctx) Regexp(Regexp::Op::CONCAT, ctx));
					__GC_MV(nre2, &(nre2->subs), ((IArrayObject<Regexp>*)new(ctx) ArrayObject<Regexp>({sub, suffix}, ctx)), IArrayObject<Regexp>);
					suffix = simplify1(Regexp::Op::QUEST, re->flags, nre2, nullptr, ctx);
				}
				if(prefixSubs == nullptr)
				{
					return suffix;
				}
				prefixSubs->add(suffix, ctx);
			}
			if(prefixSubs != nullptr)
			{
				Regexp* prefix = (new(ctx) Regexp(Regexp::Op::CONCAT, ctx));
				__GC_MV(prefix, &(prefix->subs), prefixSubs->toArray(ArrayAllocator<Regexp>::allocate(ctx, prefixSubs->size(ctx)), ctx), IArrayObject<Regexp>);
				return prefix;
			}
			return (new(ctx) Regexp(Regexp::Op::NO_MATCH, ctx));
		}
	default:
		break ;
	}
	return re;
}
Regexp* Simplify::simplify1(Regexp::Op op, int flags, Regexp* sub, Regexp* re, ThreadContext* ctx) throw() 
{
	if(sub->op == Regexp::Op::EMPTY_MATCH)
	{
		return sub;
	}
	if(op == sub->op && (flags & RE2::NON_GREEDY) == (sub->flags & RE2::NON_GREEDY))
	{
		return sub;
	}
	if(re != nullptr && re->op == op && (re->flags & RE2::NON_GREEDY) == (flags & RE2::NON_GREEDY) && sub == re->subs->get(0))
	{
		return re;
	}
	re = (new(ctx) Regexp(op, ctx));
	re->flags = flags;
	__GC_MV(re, &(re->subs), ((IArrayObject<Regexp>*)new(ctx) ArrayObject<Regexp>({sub}, ctx)), IArrayObject<Regexp>);
	return re;
}
}}}

