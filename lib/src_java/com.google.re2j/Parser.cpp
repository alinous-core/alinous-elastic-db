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





String* Parser::ERR_INTERNAL_ERROR = ConstStr::getCNST_STR_101();
String* Parser::ERR_INVALID_CHAR_CLASS = ConstStr::getCNST_STR_102();
String* Parser::ERR_INVALID_CHAR_RANGE = ConstStr::getCNST_STR_103();
String* Parser::ERR_INVALID_ESCAPE = ConstStr::getCNST_STR_104();
String* Parser::ERR_INVALID_NAMED_CAPTURE = ConstStr::getCNST_STR_105();
String* Parser::ERR_INVALID_PERL_OP = ConstStr::getCNST_STR_106();
String* Parser::ERR_INVALID_REPEAT_OP = ConstStr::getCNST_STR_107();
String* Parser::ERR_INVALID_REPEAT_SIZE = ConstStr::getCNST_STR_108();
String* Parser::ERR_MISSING_BRACKET = ConstStr::getCNST_STR_109();
String* Parser::ERR_MISSING_PAREN = ConstStr::getCNST_STR_110();
String* Parser::ERR_MISSING_REPEAT_ARGUMENT = ConstStr::getCNST_STR_111();
String* Parser::ERR_TRAILING_BACKSLASH = ConstStr::getCNST_STR_112();
const StaticArrayObject<StaticArrayObjectPrimitive<int>> Parser::__ANY_TABLE = {{0, Unicode::MAX_RUNE, 1}};
IArrayObject<IArrayObjectPrimitive<int>>* Parser::ANY_TABLE = (IArrayObject<IArrayObjectPrimitive<int>>*)const_cast<StaticArrayObject<StaticArrayObjectPrimitive<int>>*>(&__ANY_TABLE);
bool Parser::__init_done = __init_static_variables();
bool Parser::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Parser", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Parser::Parser(String* wholeRegexp, int flags, ThreadContext* ctx) throw()  : IObject(ctx), wholeRegexp(nullptr), flags(0), stack(__GC_INS(this, (new(ctx) Parser::Stack(ctx)), Parser::Stack)), free(nullptr), numCap(0)
{
	__GC_MV(this, &(this->wholeRegexp), wholeRegexp, String);
	this->flags = flags;
}
void Parser::__construct_impl(String* wholeRegexp, int flags, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->wholeRegexp), wholeRegexp, String);
	this->flags = flags;
}
 Parser::~Parser() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Parser::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Parser", L"~Parser");
	__e_obj1.add(this->wholeRegexp, this);
	wholeRegexp = nullptr;
	__e_obj1.add(this->stack, this);
	stack = nullptr;
	__e_obj1.add(this->free, this);
	free = nullptr;
	if(!prepare){
		return;
	}
}
Regexp* Parser::newRegexp(Regexp::Op op, ThreadContext* ctx) throw() 
{
	Regexp* re = free;
	if(re != nullptr && re->subs != nullptr && re->subs->length > 0)
	{
		__GC_MV(this, &(free), re->subs->get(0), Regexp);
		re->reinit(ctx);
		re->op = op;
	}
		else 
	{
		re = (new(ctx) Regexp(op, ctx));
	}
	return re;
}
void Parser::reuse(Regexp* re, ThreadContext* ctx) throw() 
{
	if(re->subs != nullptr && re->subs->length > 0)
	{
		re->subs->set(free,0, ctx);
	}
	__GC_MV(this, &(free), re, Regexp);
}
Regexp* Parser::pop(ThreadContext* ctx) throw() 
{
	return stack->remove(stack->size(ctx) - 1, ctx);
}
IArrayObject<Regexp>* Parser::popToPseudo(ThreadContext* ctx) throw() 
{
	int n = stack->size(ctx);int i = n;
	while(i > 0 && !Regexp::isPseudo(stack->get(i - 1, ctx)->op, ctx))
	{
		i -- ;
	}
	IArrayObject<Regexp>* r = stack->subList(i, n, ctx)->toArray(ArrayAllocator<Regexp>::allocate(ctx, n - i), ctx);
	stack->removeRange(i, n, ctx);
	return r;
}
Regexp* Parser::push(Regexp* re, ThreadContext* ctx) throw() 
{
	if(re->op == Regexp::Op::CHAR_CLASS && re->runes->length == 2 && re->runes->get(0) == re->runes->get(1))
	{
		if(maybeConcat(re->runes->get(0), flags & ~RE2::FOLD_CASE, ctx))
		{
			return nullptr;
		}
		re->op = Regexp::Op::LITERAL;
		__GC_MV(re, &(re->runes), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({re->runes->get(0)}, ctx)), IArrayObjectPrimitive<int>);
		re->flags = flags & ~RE2::FOLD_CASE;
	}
		else 
	{
		if((re->op == Regexp::Op::CHAR_CLASS && re->runes->length == 4 && re->runes->get(0) == re->runes->get(1) && re->runes->get(2) == re->runes->get(3) && Unicode::simpleFold(re->runes->get(0), ctx) == re->runes->get(2) && Unicode::simpleFold(re->runes->get(2), ctx) == re->runes->get(0)) || (re->op == Regexp::Op::CHAR_CLASS && re->runes->length == 2 && re->runes->get(0) + 1 == re->runes->get(1) && Unicode::simpleFold(re->runes->get(0), ctx) == re->runes->get(1) && Unicode::simpleFold(re->runes->get(1), ctx) == re->runes->get(0)))
		{
			if(maybeConcat(re->runes->get(0), (int)flags | RE2::FOLD_CASE, ctx))
			{
				return nullptr;
			}
			re->op = Regexp::Op::LITERAL;
			__GC_MV(re, &(re->runes), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({re->runes->get(0)}, ctx)), IArrayObjectPrimitive<int>);
			re->flags = flags | RE2::FOLD_CASE;
		}
				else 
		{
			maybeConcat(-1, 0, ctx);
		}
	}
	stack->add(re, ctx);
	return re;
}
bool Parser::maybeConcat(int r, int flags, ThreadContext* ctx) throw() 
{
	int n = stack->size(ctx);
	if(n < 2)
	{
		return false;
	}
	Regexp* re1 = stack->get(n - 1, ctx);
	Regexp* re2 = stack->get(n - 2, ctx);
	if(re1->op != Regexp::Op::LITERAL || re2->op != Regexp::Op::LITERAL || (re1->flags & RE2::FOLD_CASE) != (re2->flags & RE2::FOLD_CASE))
	{
		return false;
	}
	__GC_MV(re2, &(re2->runes), concatRunes(re2->runes, re1->runes, ctx), IArrayObjectPrimitive<int>);
	if(r >= 0)
	{
		__GC_MV(re1, &(re1->runes), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({r}, ctx)), IArrayObjectPrimitive<int>);
		re1->flags = flags;
		return true;
	}
	pop(ctx);
	reuse(re1, ctx);
	return false;
}
Regexp* Parser::newLiteral(int r, int flags, ThreadContext* ctx) throw() 
{
	Regexp* re = newRegexp(Regexp::Op::LITERAL, ctx);
	re->flags = flags;
	if((flags & RE2::FOLD_CASE) != 0)
	{
		r = minFoldRune(r, ctx);
	}
	__GC_MV(re, &(re->runes), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({r}, ctx)), IArrayObjectPrimitive<int>);
	return re;
}
void Parser::literal(int r, ThreadContext* ctx) throw() 
{
	push(newLiteral(r, flags, ctx), ctx);
}
Regexp* Parser::op(Regexp::Op op, ThreadContext* ctx) throw() 
{
	Regexp* re = newRegexp(op, ctx);
	re->flags = flags;
	return push(re, ctx);
}
void Parser::repeat(Regexp::Op op, int min, int max, int beforePos, Parser::StringIterator* t, int lastRepeatPos, ThreadContext* ctx)
{
	int flags = this->flags;
	if((flags & RE2::PERL_X) != 0)
	{
		if(t->more(ctx) && t->lookingAt(L'?', ctx))
		{
			t->skip(1, ctx);
			flags = flags ^ (RE2::NON_GREEDY);
		}
		if(lastRepeatPos != -1)
		{
			throw (new(ctx) PatternSyntaxException(ERR_INVALID_REPEAT_OP, t->from(lastRepeatPos, ctx), ctx));
		}
	}
	int n = stack->size(ctx);
	if(n == 0)
	{
		throw (new(ctx) PatternSyntaxException(ERR_MISSING_REPEAT_ARGUMENT, t->from(beforePos, ctx), ctx));
	}
	Regexp* sub = stack->get(n - 1, ctx);
	if(Regexp::isPseudo(sub->op, ctx))
	{
		throw (new(ctx) PatternSyntaxException(ERR_MISSING_REPEAT_ARGUMENT, t->from(beforePos, ctx), ctx));
	}
	Regexp* re = newRegexp(op, ctx);
	re->min = min;
	re->max = max;
	re->flags = flags;
	__GC_MV(re, &(re->subs), ((IArrayObject<Regexp>*)new(ctx) ArrayObject<Regexp>({sub}, ctx)), IArrayObject<Regexp>);
	stack->set(n - 1, re, ctx);
}
Regexp* Parser::concat(ThreadContext* ctx) throw() 
{
	maybeConcat(-1, 0, ctx);
	IArrayObject<Regexp>* subs = popToPseudo(ctx);
	if(subs->length == 0)
	{
		return push(newRegexp(Regexp::Op::EMPTY_MATCH, ctx), ctx);
	}
	return push(collapse(subs, Regexp::Op::CONCAT, ctx), ctx);
}
Regexp* Parser::alternate(ThreadContext* ctx) throw() 
{
	IArrayObject<Regexp>* subs = popToPseudo(ctx);
	if(subs->length > 0)
	{
		cleanAlt(subs->get(subs->length - 1), ctx);
	}
	if(subs->length == 0)
	{
		return push(newRegexp(Regexp::Op::NO_MATCH, ctx), ctx);
	}
	return push(collapse(subs, Regexp::Op::ALTERNATE, ctx), ctx);
}
void Parser::cleanAlt(Regexp* re, ThreadContext* ctx) throw() 
{
	switch(re->op) {
	case Regexp::Op::CHAR_CLASS:
		__GC_MV(re, &(re->runes), (new(ctx) CharClass(re->runes, ctx))->cleanClass(ctx)->toArray(ctx), IArrayObjectPrimitive<int>);
		if(re->runes->length == 2 && re->runes->get(0) == 0 && re->runes->get(1) == Unicode::MAX_RUNE)
		{
			__GC_MV(re, &(re->runes), nullptr, IArrayObjectPrimitive<int>);
			re->op = Regexp::Op::ANY_CHAR;
			return;
		}
		if(re->runes->length == 4 && re->runes->get(0) == 0 && re->runes->get(1) == (int)L'\n' - 1 && re->runes->get(2) == (int)L'\n' + 1 && re->runes->get(3) == Unicode::MAX_RUNE)
		{
			__GC_MV(re, &(re->runes), nullptr, IArrayObjectPrimitive<int>);
			re->op = Regexp::Op::ANY_CHAR_NOT_NL;
			return;
		}
		break ;
	default:
		break ;
	}
}
Regexp* Parser::collapse(IArrayObject<Regexp>* subs, Regexp::Op op, ThreadContext* ctx) throw() 
{
	if(subs->length == 1)
	{
		return subs->get(0);
	}
	int len = 0;
	{
		const int __max_for = subs->length;
		for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
			Regexp* sub = subs->get(__i_loop);
			{
				len += (sub->op == op) ? sub->subs->length : 1;
			}
		}
	}
	IArrayObject<Regexp>* newsubs = ArrayAllocator<Regexp>::allocate(ctx, len);
	int i = 0;
	{
		const int __max_for = subs->length;
		for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
			Regexp* sub = subs->get(__i_loop);
			{
				if(sub->op == op)
				{
					System::arraycopy(sub->subs, 0, newsubs, i, sub->subs->length, ctx);
					i += sub->subs->length;
					reuse(sub, ctx);
				}
								else 
				{
					newsubs->set(sub,i++, ctx);
				}
			}
		}
	}
	Regexp* re = newRegexp(op, ctx);
	__GC_MV(re, &(re->subs), newsubs, IArrayObject<Regexp>);
	if(op == Regexp::Op::ALTERNATE)
	{
		__GC_MV(re, &(re->subs), factor(re->subs, re->flags, ctx), IArrayObject<Regexp>);
		if(re->subs->length == 1)
		{
			Regexp* old = re;
			re = re->subs->get(0);
			reuse(old, ctx);
		}
	}
	return re;
}
IArrayObject<Regexp>* Parser::factor(IArrayObject<Regexp>* array, int flags, ThreadContext* ctx) throw() 
{
	if(array->length < 2)
	{
		return array;
	}
	int s = 0;
	int lensub = array->length;
	int lenout = 0;
	IArrayObjectPrimitive<int>* str = nullptr;
	int strlen = 0;
	int strflags = 0;
	int start = 0;
	for(int i = 0; i <= lensub; i ++ )
	{
		IArrayObjectPrimitive<int>* istr = nullptr;
		int istrlen = 0;
		int iflags = 0;
		if(i < lensub)
		{
			Regexp* re = array->get(s + i);
			if(re->op == Regexp::Op::CONCAT && re->subs->length > 0)
			{
				re = re->subs->get(0);
			}
			if(re->op == Regexp::Op::LITERAL)
			{
				istr = re->runes;
				istrlen = re->runes->length;
				iflags = re->flags & RE2::FOLD_CASE;
			}
			if(iflags == strflags)
			{
				int same = 0;
				while(same < strlen && same < istrlen && str->get(same) == istr->get(same))
				{
					same ++ ;
				}
				if(same > 0)
				{
					strlen = same;
					continue;
				}
			}
		}
		if(i == start)
		{
		}
				else 
		{
			if(i == start + 1)
			{
				array->set(array->get(s + start),lenout++, ctx);
			}
						else 
			{
				Regexp* prefix = newRegexp(Regexp::Op::LITERAL, ctx);
				prefix->flags = strflags;
				__GC_MV(prefix, &(prefix->runes), Utils::subarray(str, 0, strlen, ctx), IArrayObjectPrimitive<int>);
				for(int j = start; j < i; j ++ )
				{
					array->set(removeLeadingString(array->get(s + j), strlen, ctx),s + j, ctx);
				}
				Regexp* suffix = collapse(subarray(array, s + start, s + i, ctx), Regexp::Op::ALTERNATE, ctx);
				Regexp* re = newRegexp(Regexp::Op::CONCAT, ctx);
				__GC_MV(re, &(re->subs), ((IArrayObject<Regexp>*)new(ctx) ArrayObject<Regexp>({prefix, suffix}, ctx)), IArrayObject<Regexp>);
				array->set(re,lenout++, ctx);
			}
		}
		start = i;
		str = istr;
		strlen = istrlen;
		strflags = iflags;
	}
	lensub = lenout;
	s = 0;
	start = 0;
	lenout = 0;
	Regexp* first = nullptr;
	for(int i = 0; i <= lensub; i ++ )
	{
		Regexp* ifirst = nullptr;
		if(i < lensub)
		{
			ifirst = leadingRegexp(array->get(s + i), ctx);
			if(first != nullptr && first->equals(ifirst, ctx))
			{
				continue;
			}
		}
		if(i == start)
		{
		}
				else 
		{
			if(i == start + 1)
			{
				array->set(array->get(s + start),lenout++, ctx);
			}
						else 
			{
				Regexp* prefix = first;
				for(int j = start; j < i; j ++ )
				{
					bool reuse = j != start;
					array->set(removeLeadingRegexp(array->get(s + j), reuse, ctx),s + j, ctx);
				}
				Regexp* suffix = collapse(subarray(array, s + start, s + i, ctx), Regexp::Op::ALTERNATE, ctx);
				Regexp* re = newRegexp(Regexp::Op::CONCAT, ctx);
				__GC_MV(re, &(re->subs), ((IArrayObject<Regexp>*)new(ctx) ArrayObject<Regexp>({prefix, suffix}, ctx)), IArrayObject<Regexp>);
				array->set(re,lenout++, ctx);
			}
		}
		start = i;
		first = ifirst;
	}
	lensub = lenout;
	s = 0;
	start = 0;
	lenout = 0;
	for(int i = 0; i <= lensub; i ++ )
	{
		if(i < lensub && isCharClass(array->get(s + i), ctx))
		{
			continue;
		}
		if(i == start)
		{
		}
				else 
		{
			if(i == start + 1)
			{
				array->set(array->get(s + start),lenout++, ctx);
			}
						else 
			{
				int max = start;
				for(int j = start + 1; j < i; j ++ )
				{
					Regexp* subMax = array->get(s + max);Regexp* subJ = array->get(s + j);
					if(subMax->op.ordinal(ctx) < subJ->op.ordinal(ctx) || (subMax->op == subJ->op && subMax->runes->length < subJ->runes->length))
					{
						max = j;
					}
				}
				Regexp* tmp = array->get(s + start);
				array->set(array->get(s + max),s + start, ctx);
				array->set(tmp,s + max, ctx);
				for(int j = start + 1; j < i; j ++ )
				{
					mergeCharClass(array->get(s + start), array->get(s + j), ctx);
					reuse(array->get(s + j), ctx);
				}
				cleanAlt(array->get(s + start), ctx);
				array->set(array->get(s + start),lenout++, ctx);
			}
		}
		if(i < lensub)
		{
			array->set(array->get(s + i),lenout++, ctx);
		}
		start = i + 1;
	}
	lensub = lenout;
	s = 0;
	start = 0;
	lenout = 0;
	for(int i = 0; i < lensub; ++i)
	{
		if(i + 1 < lensub && array->get(s + i)->op == Regexp::Op::EMPTY_MATCH && array->get(s + i + 1)->op == Regexp::Op::EMPTY_MATCH)
		{
			continue;
		}
		array->set(array->get(s + i),lenout++, ctx);
	}
	lensub = lenout;
	s = 0;
	return subarray(array, s, lensub, ctx);
}
Regexp* Parser::removeLeadingString(Regexp* re, int n, ThreadContext* ctx) throw() 
{
	if(re->op == Regexp::Op::CONCAT && re->subs->length > 0)
	{
		Regexp* sub = removeLeadingString(re->subs->get(0), n, ctx);
		re->subs->set(sub,0, ctx);
		if(sub->op == Regexp::Op::EMPTY_MATCH)
		{
			reuse(sub, ctx);
			switch(re->subs->length) {
			case 0:
			case 1:
				re->op = Regexp::Op::EMPTY_MATCH;
				__GC_MV(re, &(re->subs), nullptr, IArrayObject<Regexp>);
				break ;
			case 2:
				{
					Regexp* old = re;
					re = re->subs->get(1);
					reuse(old, ctx);
					break ;
				}
			default:
				__GC_MV(re, &(re->subs), subarray(re->subs, 1, re->subs->length, ctx), IArrayObject<Regexp>);
				break ;
			}
		}
		return re;
	}
	if(re->op == Regexp::Op::LITERAL)
	{
		__GC_MV(re, &(re->runes), Utils::subarray(re->runes, n, re->runes->length, ctx), IArrayObjectPrimitive<int>);
		if(re->runes->length == 0)
		{
			re->op = Regexp::Op::EMPTY_MATCH;
		}
	}
	return re;
}
Regexp* Parser::removeLeadingRegexp(Regexp* re, bool _reuse, ThreadContext* ctx) throw() 
{
	if(re->op == Regexp::Op::CONCAT && re->subs->length > 0)
	{
		if(_reuse)
		{
			reuse(re->subs->get(0), ctx);
		}
		__GC_MV(re, &(re->subs), subarray(re->subs, 1, re->subs->length, ctx), IArrayObject<Regexp>);
		switch(re->subs->length) {
		case 0:
			re->op = Regexp::Op::EMPTY_MATCH;
			__GC_MV(re, &(re->subs), Regexp::EMPTY_SUBS, IArrayObject<Regexp>);
			break ;
		case 1:
			{
			Regexp* old = re;
			re = re->subs->get(0);
			reuse(old, ctx);
			break ;
			}
		}
		return re;
	}
	if(_reuse)
	{
		reuse(re, ctx);
	}
	return newRegexp(Regexp::Op::EMPTY_MATCH, ctx);
}
Regexp* Parser::parseInternal(ThreadContext* ctx)
{
	if((flags & RE2::LITERAL) != 0)
	{
		return literalRegexp(wholeRegexp, flags, ctx);
	}
	int lastRepeatPos = -1;int min = -1;int max = -1;
	Parser::StringIterator* t = (new(ctx) Parser::StringIterator(wholeRegexp, ctx));
	while(t->more(ctx))
	{
		int repeatPos = -1;
		switch(t->peek(ctx)) {
		default:
			literal(t->pop(ctx), ctx);
			break ;
		case L'(':
			if((flags & RE2::PERL_X) != 0 && t->lookingAt(ConstStr::getCNST_STR_90(), ctx))
			{
				parsePerlFlags(t, ctx);
				break ;
			}
			op(Regexp::Op::LEFT_PAREN, ctx)->cap = ++numCap;
			t->skip(1, ctx);
			break ;
		case L'|':
			parseVerticalBar(ctx);
			t->skip(1, ctx);
			break ;
		case L')':
			parseRightParen(ctx);
			t->skip(1, ctx);
			break ;
		case L'^':
			if((flags & RE2::ONE_LINE) != 0)
			{
				op(Regexp::Op::BEGIN_TEXT, ctx);
			}
						else 
			{
				op(Regexp::Op::BEGIN_LINE, ctx);
			}
			t->skip(1, ctx);
			break ;
		case L'$':
			if((flags & RE2::ONE_LINE) != 0)
			{
				op(Regexp::Op::END_TEXT, ctx)->flags = op(Regexp::Op::END_TEXT, ctx)->flags | (RE2::WAS_DOLLAR);
			}
						else 
			{
				op(Regexp::Op::END_LINE, ctx);
			}
			t->skip(1, ctx);
			break ;
		case L'.':
			if((flags & RE2::DOT_NL) != 0)
			{
				op(Regexp::Op::ANY_CHAR, ctx);
			}
						else 
			{
				op(Regexp::Op::ANY_CHAR_NOT_NL, ctx);
			}
			t->skip(1, ctx);
			break ;
		case L'[':
			parseClass(t, ctx);
			break ;
		case L'*':
		case L'+':
		case L'?':
			{
				repeatPos = t->pos(ctx);
				Regexp::Op op = EnumBase(0);
				switch(t->pop(ctx)) {
				case L'*':
					op = Regexp::Op::STAR;
					break ;
				case L'+':
					op = Regexp::Op::PLUS;
					break ;
				case L'?':
					op = Regexp::Op::QUEST;
					break ;
				}
				repeat(op, min, max, repeatPos, t, lastRepeatPos, ctx);
				break ;
			}
		case L'{':
			{
				repeatPos = t->pos(ctx);
				int minMax = parseRepeat(t, ctx);
				if(minMax < 0)
				{
					t->rewindTo(repeatPos, ctx);
					literal(t->pop(ctx), ctx);
					break ;
				}
				min = minMax >> 16;
				max = ((short)(minMax & 0xffff));
				repeat(Regexp::Op::REPEAT, min, max, repeatPos, t, lastRepeatPos, ctx);
				break ;
			}
		case L'\\':
			{
				int savedPos = t->pos(ctx);
				t->skip(1, ctx);
				if((flags & RE2::PERL_X) != 0 && t->more(ctx))
				{
					int c = t->pop(ctx);
					switch(c) {
					case L'A':
						op(Regexp::Op::BEGIN_TEXT, ctx);
						goto bigswitch_out_break;
					case L'b':
						op(Regexp::Op::WORD_BOUNDARY, ctx);
						goto bigswitch_out_break;
					case L'B':
						op(Regexp::Op::NO_WORD_BOUNDARY, ctx);
						goto bigswitch_out_break;
					case L'C':
						throw (new(ctx) PatternSyntaxException(ERR_INVALID_ESCAPE, ConstStr::getCNST_STR_91(), ctx));
					case L'Q':
						{
							String* lit = t->rest(ctx);
							int i = lit->indexOf(ConstStr::getCNST_STR_92(), ctx);
							if(i >= 0)
							{
								lit = lit->substring(0, i, ctx);
							}
							t->skipString(lit, ctx);
							t->skipString(ConstStr::getCNST_STR_92(), ctx);
							push(literalRegexp(lit, flags, ctx), ctx);
							goto bigswitch_out_break;
						}
					case L'z':
						op(Regexp::Op::END_TEXT, ctx);
						goto bigswitch_out_break;
					default:
						t->rewindTo(savedPos, ctx);
						break ;
					}
				}
				Regexp* re = newRegexp(Regexp::Op::CHAR_CLASS, ctx);
				re->flags = flags;
				if(t->lookingAt(ConstStr::getCNST_STR_93(), ctx) || t->lookingAt(ConstStr::getCNST_STR_94(), ctx))
				{
					CharClass* cc = (new(ctx) CharClass(ctx));
					if(parseUnicodeClass(t, cc, ctx))
					{
						__GC_MV(re, &(re->runes), cc->toArray(ctx), IArrayObjectPrimitive<int>);
						push(re, ctx);
						goto bigswitch_out_break;
					}
				}
				CharClass* cc = (new(ctx) CharClass(ctx));
				if(parsePerlClassEscape(t, cc, ctx))
				{
					__GC_MV(re, &(re->runes), cc->toArray(ctx), IArrayObjectPrimitive<int>);
					push(re, ctx);
					goto bigswitch_out_break;
				}
				t->rewindTo(savedPos, ctx);
				reuse(re, ctx);
				literal(parseEscape(t, ctx), ctx);
				break ;
			}
		}
		bigswitch_out_break: ;
		lastRepeatPos = repeatPos;
	}
	concat(ctx);
	if(swapVerticalBar(ctx))
	{
		pop(ctx);
	}
	alternate(ctx);
	int n = stack->size(ctx);
	if(n != 1)
	{
		throw (new(ctx) PatternSyntaxException(ERR_MISSING_PAREN, wholeRegexp, ctx));
	}
	return stack->get(0, ctx);
}
void Parser::parsePerlFlags(Parser::StringIterator* t, ThreadContext* ctx)
{
	int startPos = t->pos(ctx);
	String* s = t->rest(ctx);
	if(s->startsWith(ConstStr::getCNST_STR_81(), ctx))
	{
		int end = s->indexOf((int)L'>', ctx);
		if(end < 0)
		{
			throw (new(ctx) PatternSyntaxException(ERR_INVALID_NAMED_CAPTURE, s, ctx));
		}
		String* name = s->substring(4, end, ctx);
		t->skipString(name, ctx);
		t->skip(5, ctx);
		if(!isValidCaptureName(name, ctx))
		{
			throw (new(ctx) PatternSyntaxException(ERR_INVALID_NAMED_CAPTURE, s->substring(0, end, ctx), ctx));
		}
		Regexp* re = op(Regexp::Op::LEFT_PAREN, ctx);
		re->cap = ++numCap;
		__GC_MV(re, &(re->name), name, String);
		return;
	}
	t->skip(2, ctx);
	int flags = this->flags;
	int sign = +1;
	bool sawFlag = false;
	while(t->more(ctx))
	{
		int c = t->pop(ctx);
		switch(c) {
		default:
			goto loop_out_break;
		case L'i':
			flags = flags | (RE2::FOLD_CASE);
			sawFlag = true;
			break ;
		case L'm':
			flags = flags & (~RE2::ONE_LINE);
			sawFlag = true;
			break ;
		case L's':
			flags = flags | (RE2::DOT_NL);
			sawFlag = true;
			break ;
		case L'U':
			flags = flags | (RE2::NON_GREEDY);
			sawFlag = true;
			break ;
		case L'-':
			if(sign < 0)
			{
				goto loop_out_break;
			}
			sign = -1;
			flags = ~flags;
			sawFlag = false;
			break ;
		case L':':
		case L')':
			if(sign < 0)
			{
				if(!sawFlag)
				{
					goto loop_out_break;
				}
				flags = ~flags;
			}
			if(c == (int)L':')
			{
				op(Regexp::Op::LEFT_PAREN, ctx);
			}
			this->flags = flags;
			return;
		}
	}
	loop_out_break: ;
	throw (new(ctx) PatternSyntaxException(ERR_INVALID_PERL_OP, t->from(startPos, ctx), ctx));
}
void Parser::parseVerticalBar(ThreadContext* ctx) throw() 
{
	concat(ctx);
	if(!swapVerticalBar(ctx))
	{
		op(Regexp::Op::VERTICAL_BAR, ctx);
	}
}
bool Parser::swapVerticalBar(ThreadContext* ctx) throw() 
{
	int n = stack->size(ctx);
	if(n >= 3 && stack->get(n - 2, ctx)->op == Regexp::Op::VERTICAL_BAR && isCharClass(stack->get(n - 1, ctx), ctx) && isCharClass(stack->get(n - 3, ctx), ctx))
	{
		Regexp* re1 = stack->get(n - 1, ctx);
		Regexp* re3 = stack->get(n - 3, ctx);
		if(re1->op.ordinal(ctx) > re3->op.ordinal(ctx))
		{
			Regexp* tmp = re3;
			re3 = re1;
			re1 = tmp;
			stack->set(n - 3, re3, ctx);
		}
		mergeCharClass(re3, re1, ctx);
		reuse(re1, ctx);
		pop(ctx);
		return true;
	}
	if(n >= 2)
	{
		Regexp* re1 = stack->get(n - 1, ctx);
		Regexp* re2 = stack->get(n - 2, ctx);
		if(re2->op == Regexp::Op::VERTICAL_BAR)
		{
			if(n >= 3)
			{
				cleanAlt(stack->get(n - 3, ctx), ctx);
			}
			stack->set(n - 2, re1, ctx);
			stack->set(n - 1, re2, ctx);
			return true;
		}
	}
	return false;
}
void Parser::parseRightParen(ThreadContext* ctx)
{
	concat(ctx);
	if(swapVerticalBar(ctx))
	{
		pop(ctx);
	}
	alternate(ctx);
	int n = stack->size(ctx);
	if(n < 2)
	{
		throw (new(ctx) PatternSyntaxException(ERR_INTERNAL_ERROR, ConstStr::getCNST_STR_95(), ctx));
	}
	Regexp* re1 = pop(ctx);
	Regexp* re2 = pop(ctx);
	if(re2->op != Regexp::Op::LEFT_PAREN)
	{
		throw (new(ctx) PatternSyntaxException(ERR_MISSING_PAREN, wholeRegexp, ctx));
	}
	this->flags = re2->flags;
	if(re2->cap == 0)
	{
		push(re1, ctx);
	}
		else 
	{
		re2->op = Regexp::Op::CAPTURE;
		__GC_MV(re2, &(re2->subs), ((IArrayObject<Regexp>*)new(ctx) ArrayObject<Regexp>({re1}, ctx)), IArrayObject<Regexp>);
		push(re2, ctx);
	}
}
bool Parser::parsePerlClassEscape(Parser::StringIterator* t, CharClass* cc, ThreadContext* ctx) throw() 
{
	int beforePos = t->pos(ctx);
	if((flags & RE2::PERL_X) == 0 || !t->more(ctx) || t->pop(ctx) != (int)L'\\' || !t->more(ctx))
	{
		return false;
	}
	t->pop(ctx);
	CharGroup* g = CharGroup::PERL_GROUPS->get(t->from(beforePos, ctx), ctx);
	if(g == nullptr)
	{
		return false;
	}
	cc->appendGroup(g, (flags & RE2::FOLD_CASE) != 0, ctx);
	return true;
}
bool Parser::parseNamedClass(Parser::StringIterator* t, CharClass* cc, ThreadContext* ctx)
{
	String* cls = t->rest(ctx);
	int i = cls->indexOf(ConstStr::getCNST_STR_96(), ctx);
	if(i < 0)
	{
		return false;
	}
	String* name = cls->substring(0, i + 2, ctx);
	t->skipString(name, ctx);
	CharGroup* g = CharGroup::POSIX_GROUPS->get(name, ctx);
	if(g->sign == 0)
	{
		throw (new(ctx) PatternSyntaxException(ERR_INVALID_CHAR_RANGE, name, ctx));
	}
	cc->appendGroup(g, (flags & RE2::FOLD_CASE) != 0, ctx);
	return true;
}
bool Parser::parseUnicodeClass(Parser::StringIterator* t, CharClass* cc, ThreadContext* ctx)
{
	int startPos = t->pos(ctx);
	if((flags & RE2::UNICODE_GROUPS) == 0 || (!t->lookingAt(ConstStr::getCNST_STR_93(), ctx) && !t->lookingAt(ConstStr::getCNST_STR_94(), ctx)))
	{
		return false;
	}
	t->skip(1, ctx);
	int sign = +1;
	int c = t->pop(ctx);
	if(c == (int)L'P')
	{
		sign = -1;
	}
	c = t->pop(ctx);
	String* name = 0;
	if(c != (int)L'{')
	{
		name = Utils::runeToString(c, ctx);
	}
		else 
	{
		String* rest = t->rest(ctx);
		int end = rest->indexOf((int)L'}', ctx);
		if(end < 0)
		{
			t->rewindTo(startPos, ctx);
			throw (new(ctx) PatternSyntaxException(ERR_INVALID_CHAR_RANGE, t->rest(ctx), ctx));
		}
		name = rest->substring(0, end, ctx);
		t->skipString(name, ctx);
		t->skip(1, ctx);
	}
	if(!name->isEmpty(ctx) && name->charAt(0, ctx) == L'^')
	{
		sign = -sign;
		name = name->substring(1, ctx);
	}
	Parser::Pair<IArrayObject<IArrayObjectPrimitive<int>>,IArrayObject<IArrayObjectPrimitive<int>>>* pair = unicodeTable(name, ctx);
	if(pair == nullptr)
	{
		throw (new(ctx) PatternSyntaxException(ERR_INVALID_CHAR_RANGE, t->from(startPos, ctx), ctx));
	}
	IArrayObject<IArrayObjectPrimitive<int>>* tab = pair->first;
	IArrayObject<IArrayObjectPrimitive<int>>* fold = pair->second;
	if((flags & RE2::FOLD_CASE) == 0 || fold == (IArrayObject<IArrayObjectPrimitive<int>>*)nullptr)
	{
		cc->appendTableWithSign(tab, sign, ctx);
	}
		else 
	{
		IArrayObjectPrimitive<int>* tmp = (new(ctx) CharClass(ctx))->appendTable(tab, ctx)->appendTable(fold, ctx)->cleanClass(ctx)->toArray(ctx);
		cc->appendClassWithSign(tmp, sign, ctx);
	}
	return true;
}
void Parser::parseClass(Parser::StringIterator* t, ThreadContext* ctx)
{
	int startPos = t->pos(ctx);
	t->skip(1, ctx);
	Regexp* re = newRegexp(Regexp::Op::CHAR_CLASS, ctx);
	re->flags = flags;
	CharClass* cc = (new(ctx) CharClass(ctx));
	int sign = +1;
	if(t->more(ctx) && t->lookingAt(L'^', ctx))
	{
		sign = -1;
		t->skip(1, ctx);
		if((flags & RE2::CLASS_NL) == 0)
		{
			cc->appendRange((int)L'\n', (int)L'\n', ctx);
		}
	}
	bool first = true;
	while(!t->more(ctx) || t->peek(ctx) != (int)L']' || first)
	{
		if(t->more(ctx) && t->lookingAt(L'-', ctx) && (flags & RE2::PERL_X) == 0 && !first)
		{
			String* s = t->rest(ctx);
			if(s->equals(ConstStr::getCNST_STR_98(), ctx) || !s->startsWith(ConstStr::getCNST_STR_99(), ctx))
			{
				t->rewindTo(startPos, ctx);
				throw (new(ctx) PatternSyntaxException(ERR_INVALID_CHAR_RANGE, t->rest(ctx), ctx));
			}
		}
		first = false;
		int beforePos = t->pos(ctx);
		if(t->lookingAt(ConstStr::getCNST_STR_100(), ctx))
		{
			if(parseNamedClass(t, cc, ctx))
			{
				continue;
			}
			t->rewindTo(beforePos, ctx);
		}
		if(parseUnicodeClass(t, cc, ctx))
		{
			continue;
		}
		if(parsePerlClassEscape(t, cc, ctx))
		{
			continue;
		}
		t->rewindTo(beforePos, ctx);
		int lo = parseClassChar(t, startPos, ctx);
		int hi = lo;
		if(t->more(ctx) && t->lookingAt(L'-', ctx))
		{
			t->skip(1, ctx);
			if(t->more(ctx) && t->lookingAt(L']', ctx))
			{
				t->skip(-1, ctx);
			}
						else 
			{
				hi = parseClassChar(t, startPos, ctx);
				if(hi < lo)
				{
					throw (new(ctx) PatternSyntaxException(ERR_INVALID_CHAR_RANGE, t->from(beforePos, ctx), ctx));
				}
			}
		}
		if((flags & RE2::FOLD_CASE) == 0)
		{
			cc->appendRange(lo, hi, ctx);
		}
				else 
		{
			cc->appendFoldedRange(lo, hi, ctx);
		}
	}
	t->skip(1, ctx);
	cc->cleanClass(ctx);
	if(sign < 0)
	{
		cc->negateClass(ctx);
	}
	__GC_MV(re, &(re->runes), cc->toArray(ctx), IArrayObjectPrimitive<int>);
	push(re, ctx);
}
Regexp* Parser::parse(String* pattern, int flags, ThreadContext* ctx)
{
	return (new(ctx) Parser(pattern, flags, ctx))->parseInternal(ctx);
}
IArrayObject<Regexp>* Parser::subarray(IArrayObject<Regexp>* array, int start, int end, ThreadContext* ctx) throw() 
{
	IArrayObject<Regexp>* r = ArrayAllocator<Regexp>::allocate(ctx, end - start);
	for(int i = start; i < end; ++i)
	{
		r->set(array->get(i),i - start, ctx);
	}
	return r;
}
int Parser::minFoldRune(int r, ThreadContext* ctx) throw() 
{
	if(r < Unicode::MIN_FOLD || r > Unicode::MAX_FOLD)
	{
		return r;
	}
	int min = r;
	int r0 = r;
	for(r = Unicode::simpleFold(r, ctx); r != r0; r = Unicode::simpleFold(r, ctx))
	{
		if(min > r)
		{
			min = r;
		}
	}
	return min;
}
Regexp* Parser::leadingRegexp(Regexp* re, ThreadContext* ctx) throw() 
{
	if(re->op == Regexp::Op::EMPTY_MATCH)
	{
		return nullptr;
	}
	if(re->op == Regexp::Op::CONCAT && re->subs->length > 0)
	{
		Regexp* sub = re->subs->get(0);
		if(sub->op == Regexp::Op::EMPTY_MATCH)
		{
			return nullptr;
		}
		return sub;
	}
	return re;
}
Regexp* Parser::literalRegexp(String* s, int flags, ThreadContext* ctx) throw() 
{
	Regexp* re = (new(ctx) Regexp(Regexp::Op::LITERAL, ctx));
	re->flags = flags;
	__GC_MV(re, &(re->runes), Utils::stringToRunes(s, ctx), IArrayObjectPrimitive<int>);
	return re;
}
int Parser::parseRepeat(Parser::StringIterator* t, ThreadContext* ctx)
{
	int start = t->pos(ctx);
	if(!t->more(ctx) || !t->lookingAt(L'{', ctx))
	{
		return -1;
	}
	t->skip(1, ctx);
	int min = parseInt(t, ctx);
	if(min == -1)
	{
		return -1;
	}
	if(!t->more(ctx))
	{
		return -1;
	}
	int max = 0;
	if(!t->lookingAt(L',', ctx))
	{
		max = min;
	}
		else 
	{
		t->skip(1, ctx);
		if(!t->more(ctx))
		{
			return -1;
		}
		if(t->lookingAt(L'}', ctx))
		{
			max = -1;
		}
				else 
		{
			max = parseInt(t, ctx);
			if((max) == -1)
			{
				return -1;
			}
		}
	}
	if(!t->more(ctx) || !t->lookingAt(L'}', ctx))
	{
		return -1;
	}
	t->skip(1, ctx);
	if(min < 0 || min > 1000 || max == -2 || max > 1000 || (max >= 0 && min > max))
	{
		throw (new(ctx) PatternSyntaxException(ERR_INVALID_REPEAT_SIZE, t->from(start, ctx), ctx));
	}
	return (min << 16) | (max & 0xffff);
}
bool Parser::isValidCaptureName(String* name, ThreadContext* ctx) throw() 
{
	if(name->isEmpty(ctx))
	{
		return false;
	}
	for(int i = 0; i < name->length(ctx); ++i)
	{
		wchar_t c = name->charAt(i, ctx);
		if(c != L'_' && !Utils::isalnum((int)c, ctx))
		{
			return false;
		}
	}
	return true;
}
int Parser::parseInt(Parser::StringIterator* t, ThreadContext* ctx) throw() 
{
	int start = t->pos(ctx);
	int c = 0;
	if(t->more(ctx)){
		c = t->peek(ctx);
	}
	while(t->more(ctx) && (c) >= (int)L'0' && c <= (int)L'9')
	{
		t->skip(1, ctx);
	}
	String* n = t->from(start, ctx);
	if(n->isEmpty(ctx) || (n->length(ctx) > 1 && n->charAt(0, ctx) == L'0'))
	{
		return -1;
	}
	if(n->length(ctx) > 8)
	{
		return -2;
	}
	return Integer::valueOf(n, 10, ctx)->intValue(ctx);
}
bool Parser::isCharClass(Regexp* re, ThreadContext* ctx) throw() 
{
	return ((re->op == Regexp::Op::LITERAL && re->runes->length == 1) || re->op == Regexp::Op::CHAR_CLASS || re->op == Regexp::Op::ANY_CHAR_NOT_NL || re->op == Regexp::Op::ANY_CHAR);
}
bool Parser::matchRune(Regexp* re, int r, ThreadContext* ctx) throw() 
{
	switch(re->op) {
	case Regexp::Op::LITERAL:
		return re->runes->length == 1 && re->runes->get(0) == r;
	case Regexp::Op::CHAR_CLASS:
		for(int i = 0; i < re->runes->length; i += 2)
		{
			if(re->runes->get(i) <= r && r <= re->runes->get(i + 1))
			{
				return true;
			}
		}
		return false;
	case Regexp::Op::ANY_CHAR_NOT_NL:
		return r != (int)L'\n';
	case Regexp::Op::ANY_CHAR:
		return true;
	default:
		break ;
	}
	return false;
}
void Parser::mergeCharClass(Regexp* dst, Regexp* src, ThreadContext* ctx) throw() 
{
	switch(dst->op) {
	case Regexp::Op::ANY_CHAR:
		break ;
	case Regexp::Op::ANY_CHAR_NOT_NL:
		if(matchRune(src, (int)L'\n', ctx))
		{
			dst->op = Regexp::Op::ANY_CHAR;
		}
		break ;
	case Regexp::Op::CHAR_CLASS:
		if(src->op == Regexp::Op::LITERAL)
		{
			__GC_MV(dst, &(dst->runes), (new(ctx) CharClass(dst->runes, ctx))->appendLiteral(src->runes->get(0), src->flags, ctx)->toArray(ctx), IArrayObjectPrimitive<int>);
		}
				else 
		{
			__GC_MV(dst, &(dst->runes), (new(ctx) CharClass(dst->runes, ctx))->appendClass(src->runes, ctx)->toArray(ctx), IArrayObjectPrimitive<int>);
		}
		break ;
	case Regexp::Op::LITERAL:
		if(src->runes->get(0) == dst->runes->get(0) && src->flags == dst->flags)
		{
			break ;
		}
		dst->op = Regexp::Op::CHAR_CLASS;
		__GC_MV(dst, &(dst->runes), (new(ctx) CharClass(ctx))->appendLiteral(dst->runes->get(0), dst->flags, ctx)->appendLiteral(src->runes->get(0), src->flags, ctx)->toArray(ctx), IArrayObjectPrimitive<int>);
		break ;
	default:
		break ;
	}
}
int Parser::parseEscape(Parser::StringIterator* t, ThreadContext* ctx)
{
	int startPos = t->pos(ctx);
	t->skip(1, ctx);
	if(!t->more(ctx))
	{
		throw (new(ctx) PatternSyntaxException(ERR_TRAILING_BACKSLASH, ctx));
	}
	int c = t->pop(ctx);
	int r = 0;
	switch(c) {
	default:
		if(!Utils::isalnum(c, ctx))
		{
			return c;
		}
		break ;
	case L'1':
	case L'2':
	case L'3':
	case L'4':
	case L'5':
	case L'6':
	case L'7':
		if(!t->more(ctx) || t->peek(ctx) < (int)L'0' || t->peek(ctx) > (int)L'7')
		{
			break ;
		}
	case L'0':
		r = c - L'0';
		for(int i = 1; i < 3; i ++ )
		{
			if(!t->more(ctx) || t->peek(ctx) < (int)L'0' || t->peek(ctx) > (int)L'7')
			{
				break ;
			}
			r = r * 8 + t->peek(ctx) - L'0';
			t->skip(1, ctx);
		}
		return r;
	case L'x':
		{
		if(!t->more(ctx))
		{
			break ;
		}
		c = t->pop(ctx);
		if(c == (int)L'{')
		{
			int nhex = 0;
			r = 0;
			for(; ; )
			{
				if(!t->more(ctx))
				{
					goto bigswitch_out_break;
				}
				c = t->pop(ctx);
				if(c == (int)L'}')
				{
					break ;
				}
				int v = Utils::unhex(c, ctx);
				if(v < 0)
				{
					goto bigswitch_out_break;
				}
				r = r * 16 + v;
				if(r > Unicode::MAX_RUNE)
				{
					goto bigswitch_out_break;
				}
				nhex ++ ;
			}
			if(nhex == 0)
			{
				goto bigswitch_out_break;
			}
			return r;
		}
		int x = Utils::unhex(c, ctx);
		c = t->pop(ctx);
		int y = Utils::unhex(c, ctx);
		if(x < 0 || y < 0)
		{
			break ;
		}
		return x * 16 + y;
		}
	case L'a':
		return 7;
	case L'f':
		return L'\f';
	case L'n':
		return L'\n';
	case L'r':
		return L'\r';
	case L't':
		return L'\t';
	case L'v':
		return 11;
	}
	bigswitch_out_break: ;
	throw (new(ctx) PatternSyntaxException(ERR_INVALID_ESCAPE, t->from(startPos, ctx), ctx));
}
int Parser::parseClassChar(Parser::StringIterator* t, int wholeClassPos, ThreadContext* ctx)
{
	if(!t->more(ctx))
	{
		throw (new(ctx) PatternSyntaxException(ERR_MISSING_BRACKET, t->from(wholeClassPos, ctx), ctx));
	}
	if(t->lookingAt(L'\\', ctx))
	{
		return parseEscape(t, ctx);
	}
	return t->pop(ctx);
}
Parser::Pair<IArrayObject<IArrayObjectPrimitive<int>>,IArrayObject<IArrayObjectPrimitive<int>>>* Parser::unicodeTable(String* name, ThreadContext* ctx) throw() 
{
	if(name->equals(ConstStr::getCNST_STR_97(), ctx))
	{
		return (new(ctx) Parser::Pair<IArrayObject<IArrayObjectPrimitive<int>>,IArrayObject<IArrayObjectPrimitive<int>>>(ANY_TABLE, ANY_TABLE, ctx));
	}
	IArrayObject<IArrayObjectPrimitive<int>>* table = UnicodeTables::CATEGORIES->get(name, ctx);
	if(table != (IArrayObject<IArrayObjectPrimitive<int>>*)nullptr)
	{
		return (new(ctx) Parser::Pair<IArrayObject<IArrayObjectPrimitive<int>>,IArrayObject<IArrayObjectPrimitive<int>>>(table, UnicodeTables::FOLD_CATEGORIES->get(name, ctx), ctx));
	}
	table = UnicodeTables::SCRIPTS->get(name, ctx);
	if(table != (IArrayObject<IArrayObjectPrimitive<int>>*)nullptr)
	{
		return (new(ctx) Parser::Pair<IArrayObject<IArrayObjectPrimitive<int>>,IArrayObject<IArrayObjectPrimitive<int>>>(table, UnicodeTables::FOLD_SCRIPT->get(name, ctx), ctx));
	}
	return nullptr;
}
IArrayObjectPrimitive<int>* Parser::concatRunes(IArrayObjectPrimitive<int>* x, IArrayObjectPrimitive<int>* y, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* z = ArrayAllocatorPrimitive<int>::allocatep(ctx, x->length + y->length);
	System::arraycopy(x, 0, z, 0, x->length, ctx);
	System::arraycopy(y, 0, z, x->length, y->length, ctx);
	return z;
}
}}}

namespace com {namespace google {namespace re2j {





constexpr const long long Parser::Stack::serialVersionUID;
bool Parser::Stack::__init_done = __init_static_variables();
bool Parser::Stack::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Parser::Stack", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Parser::Stack::~Stack() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Parser::Stack::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ArrayList<Regexp>::__releaseRegerences(true, ctx);
}
void Parser::Stack::removeRange(int fromIndex, int toIndex, ThreadContext* ctx) throw() 
{
	ArrayList<Regexp>::removeRange(fromIndex, toIndex, ctx);
}
}}}

namespace com {namespace google {namespace re2j {





bool Parser::StringIterator::__init_done = __init_static_variables();
bool Parser::StringIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Parser::StringIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Parser::StringIterator::StringIterator(String* str, ThreadContext* ctx) throw()  : IObject(ctx), str(nullptr), _pos(0)
{
	__GC_MV(this, &(this->str), str, String);
}
void Parser::StringIterator::__construct_impl(String* str, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->str), str, String);
}
 Parser::StringIterator::~StringIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Parser::StringIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StringIterator", L"~StringIterator");
	__e_obj1.add(this->str, this);
	str = nullptr;
	if(!prepare){
		return;
	}
}
String* Parser::StringIterator::toString(ThreadContext* ctx) throw() 
{
	return rest(ctx);
}
int Parser::StringIterator::pos(ThreadContext* ctx) throw() 
{
	return _pos;
}
void Parser::StringIterator::rewindTo(int pos, ThreadContext* ctx) throw() 
{
	this->_pos = pos;
}
bool Parser::StringIterator::more(ThreadContext* ctx) throw() 
{
	return _pos < str->length(ctx);
}
int Parser::StringIterator::peek(ThreadContext* ctx) throw() 
{
	return str->codePointAt(_pos, ctx);
}
void Parser::StringIterator::skip(int n, ThreadContext* ctx) throw() 
{
	_pos += n;
}
void Parser::StringIterator::skipString(String* s, ThreadContext* ctx) throw() 
{
	_pos += s->length(ctx);
}
int Parser::StringIterator::pop(ThreadContext* ctx) throw() 
{
	int r = str->codePointAt(_pos, ctx);
	_pos += Character::charCount(r, ctx);
	return r;
}
bool Parser::StringIterator::lookingAt(wchar_t c, ThreadContext* ctx) throw() 
{
	return str->charAt(_pos, ctx) == c;
}
bool Parser::StringIterator::lookingAt(String* s, ThreadContext* ctx) throw() 
{
	return rest(ctx)->startsWith(s, ctx);
}
String* Parser::StringIterator::rest(ThreadContext* ctx) throw() 
{
	return str->substring(_pos, ctx);
}
String* Parser::StringIterator::from(int beforePos, ThreadContext* ctx) throw() 
{
	return str->substring(beforePos, _pos, ctx);
}
}}}

namespace com {namespace google {namespace re2j {





template <typename F,typename S>
bool Parser::Pair<F, S>::__init_done = __init_static_variables();
template <typename F,typename S>
bool Parser::Pair<F, S>::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Parser::Pair<F, S>", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
template <typename F, typename S>
 Parser::Pair<F, S>::Pair(F* first, S* second, ThreadContext* ctx) throw()  : IObject(ctx), first(nullptr), second(nullptr)
{
	__GC_MV(this, &(this->first), first, F);
	__GC_MV(this, &(this->second), second, S);
}
template <typename F, typename S>
void Parser::Pair<F, S>::__construct_impl(F* first, S* second, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, F);
	__GC_MV(this, &(this->second), second, S);
}
template <typename F, typename S>
 Parser::Pair<F, S>::~Pair() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
template <typename F, typename S>
void Parser::Pair<F, S>::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Pair", L"~Pair");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->second, this);
	second = nullptr;
	if(!prepare){
		return;
	}
}
}}}

