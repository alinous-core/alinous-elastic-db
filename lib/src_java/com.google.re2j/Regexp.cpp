#include "includes.h"


namespace com {namespace google {namespace re2j {



constexpr EnumBase __Regexp__Op::__DEFAULT_NULL;
constexpr EnumBase __Regexp__Op::NO_MATCH;
constexpr EnumBase __Regexp__Op::EMPTY_MATCH;
constexpr EnumBase __Regexp__Op::LITERAL;
constexpr EnumBase __Regexp__Op::CHAR_CLASS;
constexpr EnumBase __Regexp__Op::ANY_CHAR_NOT_NL;
constexpr EnumBase __Regexp__Op::ANY_CHAR;
constexpr EnumBase __Regexp__Op::BEGIN_LINE;
constexpr EnumBase __Regexp__Op::END_LINE;
constexpr EnumBase __Regexp__Op::BEGIN_TEXT;
constexpr EnumBase __Regexp__Op::END_TEXT;
constexpr EnumBase __Regexp__Op::WORD_BOUNDARY;
constexpr EnumBase __Regexp__Op::NO_WORD_BOUNDARY;
constexpr EnumBase __Regexp__Op::CAPTURE;
constexpr EnumBase __Regexp__Op::STAR;
constexpr EnumBase __Regexp__Op::PLUS;
constexpr EnumBase __Regexp__Op::QUEST;
constexpr EnumBase __Regexp__Op::REPEAT;
constexpr EnumBase __Regexp__Op::CONCAT;
constexpr EnumBase __Regexp__Op::ALTERNATE;
constexpr EnumBase __Regexp__Op::LEFT_PAREN;
constexpr EnumBase __Regexp__Op::VERTICAL_BAR;


const StaticArrayObject<Regexp> Regexp::__EMPTY_SUBS = {};
IArrayObject<Regexp>* Regexp::EMPTY_SUBS = (IArrayObject<Regexp>*)const_cast<StaticArrayObject<Regexp>*>(&__EMPTY_SUBS);
bool Regexp::__init_done = __init_static_variables();
bool Regexp::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Regexp", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Regexp::Regexp(Regexp::Op op, ThreadContext* ctx) throw()  : IObject(ctx), flags(0), subs(nullptr), runes(nullptr), min(0), max(0), cap(0), name(nullptr)
{
	this->op = op;
}
void Regexp::__construct_impl(Regexp::Op op, ThreadContext* ctx) throw() 
{
	this->op = op;
}
 Regexp::Regexp(Regexp* that, ThreadContext* ctx) throw()  : IObject(ctx), flags(0), subs(nullptr), runes(nullptr), min(0), max(0), cap(0), name(nullptr)
{
	this->op = that->op;
	this->flags = that->flags;
	__GC_MV(this, &(this->subs), that->subs, IArrayObject<Regexp>);
	__GC_MV(this, &(this->runes), that->runes, IArrayObjectPrimitive<int>);
	this->min = that->min;
	this->max = that->max;
	this->cap = that->cap;
	__GC_MV(this, &(this->name), that->name, String);
}
void Regexp::__construct_impl(Regexp* that, ThreadContext* ctx) throw() 
{
	this->op = that->op;
	this->flags = that->flags;
	__GC_MV(this, &(this->subs), that->subs, IArrayObject<Regexp>);
	__GC_MV(this, &(this->runes), that->runes, IArrayObjectPrimitive<int>);
	this->min = that->min;
	this->max = that->max;
	this->cap = that->cap;
	__GC_MV(this, &(this->name), that->name, String);
}
 Regexp::~Regexp() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Regexp::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Regexp", L"~Regexp");
	__e_obj1.add(this->subs, this);
	subs = nullptr;
	__e_obj1.add(this->runes, this);
	runes = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	if(!prepare){
		return;
	}
}
String* Regexp::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* out = (new(ctx) StringBuilder(ctx));
	appendTo(out, ctx);
	return out->toString(ctx);
}
bool Regexp::equals(IObject* that, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<Regexp*>(that) != 0)))
	{
		return false;
	}
	Regexp* x = this;
	Regexp* y = dynamic_cast<Regexp*>(that);
	if(x->op != y->op)
	{
		return false;
	}
	switch(x->op) {
	case Regexp::Op::END_TEXT:
		if((x->flags & RE2::WAS_DOLLAR) != (y->flags & RE2::WAS_DOLLAR))
		{
			return false;
		}
		break ;
	case Regexp::Op::LITERAL:
	case Regexp::Op::CHAR_CLASS:
		if(!Arrays::equals(x->runes, y->runes, ctx))
		{
			return false;
		}
		break ;
	case Regexp::Op::ALTERNATE:
	case Regexp::Op::CONCAT:
		if(x->subs->length != y->subs->length)
		{
			return false;
		}
		for(int i = 0; i < x->subs->length; ++i)
		{
			if(!x->subs->get(i)->equals(y->subs->get(i), ctx))
			{
				return false;
			}
		}
		break ;
	case Regexp::Op::STAR:
	case Regexp::Op::PLUS:
	case Regexp::Op::QUEST:
		if((x->flags & RE2::NON_GREEDY) != (y->flags & RE2::NON_GREEDY) || !x->subs->get(0)->equals(y->subs->get(0), ctx))
		{
			return false;
		}
		break ;
	case Regexp::Op::REPEAT:
		if((x->flags & RE2::NON_GREEDY) != (y->flags & RE2::NON_GREEDY) || x->min != y->min || x->max != y->max || !x->subs->get(0)->equals(y->subs->get(0), ctx))
		{
			return false;
		}
		break ;
	case Regexp::Op::CAPTURE:
		if(x->cap != y->cap || x->name != y->name || !x->subs->get(0)->equals(y->subs->get(0), ctx))
		{
			return false;
		}
		break ;
	default:
		break ;
	}
	return true;
}
void Regexp::reinit(ThreadContext* ctx) throw() 
{
	this->flags = 0;
	__GC_MV(this, &(subs), EMPTY_SUBS, IArrayObject<Regexp>);
	__GC_MV(this, &(runes), nullptr, IArrayObjectPrimitive<int>);
	cap = min = max = 0;
	__GC_MV(this, &(name), nullptr, String);
}
int Regexp::maxCap(ThreadContext* ctx) throw() 
{
	int m = 0;
	if(op == Op::CAPTURE)
	{
		m = cap;
	}
	if(subs != nullptr)
	{
		{
			const int __max_for = subs->length;
			for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
				Regexp* sub = subs->get(__i_loop);
				{
					int n = sub->maxCap(ctx);
					if(m < n)
					{
						m = n;
					}
				}
			}
		}
	}
	return m;
}
void Regexp::appendTo(StringBuilder* out, ThreadContext* ctx) throw() 
{
	switch(op) {
	case Regexp::Op::NO_MATCH:
		out->append(ConstStr::getCNST_STR_74(), ctx);
		break ;
	case Regexp::Op::EMPTY_MATCH:
		out->append(ConstStr::getCNST_STR_75(), ctx);
		break ;
	case Regexp::Op::STAR:
	case Regexp::Op::PLUS:
	case Regexp::Op::QUEST:
	case Regexp::Op::REPEAT:
		{
			Regexp* sub = subs->get(0);
			if(sub->op.ordinal(ctx) > Op::CAPTURE.ordinal(ctx) || (sub->op == Op::LITERAL && sub->runes->length > 1))
			{
				out->append(ConstStr::getCNST_STR_76(), ctx);
				sub->appendTo(out, ctx);
				out->append(L')', ctx);
			}
						else 
			{
				sub->appendTo(out, ctx);
			}
			switch(op) {
			case Regexp::Op::STAR:
				out->append(L'*', ctx);
				break ;
			case Regexp::Op::PLUS:
				out->append(L'+', ctx);
				break ;
			case Regexp::Op::QUEST:
				out->append(L'?', ctx);
				break ;
			case Regexp::Op::REPEAT:
				out->append(L'{', ctx)->append(min, ctx);
				if(min != max)
				{
					out->append(L',', ctx);
					if(max >= 0)
					{
						out->append(max, ctx);
					}
				}
				out->append(L'}', ctx);
				break ;
			default:
				break ;
			}
			if((flags & RE2::NON_GREEDY) != 0)
			{
				out->append(L'?', ctx);
			}
			break ;
		}
	case Regexp::Op::CONCAT:
		{
			const int __max_for = subs->length;
			for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
				Regexp* sub = subs->get(__i_loop);
				{
					if(sub->op == Op::ALTERNATE)
					{
						out->append(ConstStr::getCNST_STR_76(), ctx);
						sub->appendTo(out, ctx);
						out->append(L')', ctx);
					}
										else 
					{
						sub->appendTo(out, ctx);
					}
				}
			}
		}
		break ;
	case Regexp::Op::ALTERNATE:
		{
			String* sep = ConstStr::getCNST_STR_4();
			{
				const int __max_for = subs->length;
				for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
					Regexp* sub = subs->get(__i_loop);
					{
						out->append(sep, ctx);
						sep = ConstStr::getCNST_STR_77();
						sub->appendTo(out, ctx);
					}
				}
			}
			break ;
		}
	case Regexp::Op::LITERAL:
		if((flags & RE2::FOLD_CASE) != 0)
		{
			out->append(ConstStr::getCNST_STR_78(), ctx);
		}
		{
			const int __max_for = runes->length;
			for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
				int rune = runes->get(__i_loop);
				{
					Utils::escapeRune(out, rune, ctx);
				}
			}
		}
		if((flags & RE2::FOLD_CASE) != 0)
		{
			out->append(L')', ctx);
		}
		break ;
	case Regexp::Op::ANY_CHAR_NOT_NL:
		out->append(ConstStr::getCNST_STR_79(), ctx);
		break ;
	case Regexp::Op::ANY_CHAR:
		out->append(ConstStr::getCNST_STR_80(), ctx);
		break ;
	case Regexp::Op::CAPTURE:
		if(name == nullptr || name->isEmpty(ctx))
		{
			out->append(L'(', ctx);
		}
				else 
		{
			out->append(ConstStr::getCNST_STR_81(), ctx);
			out->append(name, ctx);
			out->append(ConstStr::getCNST_STR_82(), ctx);
		}
		if(subs->get(0)->op != Op::EMPTY_MATCH)
		{
			subs->get(0)->appendTo(out, ctx);
		}
		out->append(L')', ctx);
		break ;
	case Regexp::Op::BEGIN_TEXT:
		out->append(ConstStr::getCNST_STR_83(), ctx);
		break ;
	case Regexp::Op::END_TEXT:
		if((flags & RE2::WAS_DOLLAR) != 0)
		{
			out->append(ConstStr::getCNST_STR_84(), ctx);
		}
				else 
		{
			out->append(ConstStr::getCNST_STR_85(), ctx);
		}
		break ;
	case Regexp::Op::BEGIN_LINE:
		out->append(L'^', ctx);
		break ;
	case Regexp::Op::END_LINE:
		out->append(L'$', ctx);
		break ;
	case Regexp::Op::WORD_BOUNDARY:
		out->append(ConstStr::getCNST_STR_86(), ctx);
		break ;
	case Regexp::Op::NO_WORD_BOUNDARY:
		out->append(ConstStr::getCNST_STR_87(), ctx);
		break ;
	case Regexp::Op::CHAR_CLASS:
		if(runes->length % 2 != 0)
		{
			out->append(ConstStr::getCNST_STR_88(), ctx);
			break ;
		}
		out->append(L'[', ctx);
		if(runes->length == 0)
		{
			out->append(ConstStr::getCNST_STR_89(), ctx);
		}
				else 
		{
			if(runes->get(0) == 0 && runes->get(runes->length - 1) == Unicode::MAX_RUNE)
			{
				out->append(L'^', ctx);
				for(int i = 1; i < runes->length - 1; i += 2)
				{
					int lo = runes->get(i) + 1;
					int hi = runes->get(i + 1) - 1;
					quoteIfHyphen(out, lo, ctx);
					Utils::escapeRune(out, lo, ctx);
					if(lo != hi)
					{
						out->append(L'-', ctx);
						quoteIfHyphen(out, hi, ctx);
						Utils::escapeRune(out, hi, ctx);
					}
				}
			}
						else 
			{
				for(int i = 0; i < runes->length; i += 2)
				{
					int lo = runes->get(i);
					int hi = runes->get(i + 1);
					quoteIfHyphen(out, lo, ctx);
					Utils::escapeRune(out, lo, ctx);
					if(lo != hi)
					{
						out->append(L'-', ctx);
						quoteIfHyphen(out, hi, ctx);
						Utils::escapeRune(out, hi, ctx);
					}
				}
			}
		}
		out->append(L']', ctx);
		break ;
	default:
		out->append(op, ctx);
		break ;
	}
}
bool Regexp::isPseudo(Regexp::Op op, ThreadContext* ctx) throw() 
{
	return op == Op::LEFT_PAREN || op == Op::VERTICAL_BAR;
}
void Regexp::quoteIfHyphen(StringBuilder* out, int rune, ThreadContext* ctx) throw() 
{
	if(rune == (int)L'-')
	{
		out->append(L'\\', ctx);
	}
}
}}}

