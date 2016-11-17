#include "includes.h"


namespace com {namespace google {namespace re2j {





const StaticArrayObjectPrimitive<int> Compiler::__ANY_RUNE_NOT_NL = {0, L'\n' - 1, L'\n' + 1, Unicode::MAX_RUNE};
IArrayObjectPrimitive<int>* Compiler::ANY_RUNE_NOT_NL = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__ANY_RUNE_NOT_NL);
const StaticArrayObjectPrimitive<int> Compiler::__ANY_RUNE = {0, Unicode::MAX_RUNE};
IArrayObjectPrimitive<int>* Compiler::ANY_RUNE = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__ANY_RUNE);
bool Compiler::__init_done = __init_static_variables();
bool Compiler::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Compiler", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Compiler::Compiler(ThreadContext* ctx) throw()  : IObject(ctx), prog(__GC_INS(this, (new(ctx) Prog(ctx)), Prog))
{
	newInst(Inst::Op::FAIL, ctx);
}
void Compiler::__construct_impl(ThreadContext* ctx) throw() 
{
	newInst(Inst::Op::FAIL, ctx);
}
 Compiler::~Compiler() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Compiler::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Compiler", L"~Compiler");
	__e_obj1.add(this->prog, this);
	prog = nullptr;
	if(!prepare){
		return;
	}
}
Compiler::Frag* Compiler::newInst(Inst::Op op, ThreadContext* ctx) throw() 
{
	prog->addInst(op, ctx);
	return (new(ctx) Compiler::Frag(prog->numInst(ctx) - 1, ctx));
}
Compiler::Frag* Compiler::nop(ThreadContext* ctx) throw() 
{
	Compiler::Frag* f = newInst(Inst::Op::NOP, ctx);
	f->out = f->i << 1;
	return f;
}
Compiler::Frag* Compiler::fail(ThreadContext* ctx) throw() 
{
	return (new(ctx) Compiler::Frag(ctx));
}
Compiler::Frag* Compiler::cap(int arg, ThreadContext* ctx) throw() 
{
	Compiler::Frag* f = newInst(Inst::Op::CAPTURE, ctx);
	f->out = f->i << 1;
	prog->getInst(f->i, ctx)->arg = arg;
	if(prog->numCap < arg + 1)
	{
		prog->numCap = arg + 1;
	}
	return f;
}
Compiler::Frag* Compiler::cat(Compiler::Frag* f1, Compiler::Frag* f2, ThreadContext* ctx) throw() 
{
	if(f1->i == 0 || f2->i == 0)
	{
		return fail(ctx);
	}
	prog->patch(f1->out, f2->i, ctx);
	return (new(ctx) Compiler::Frag(f1->i, f2->out, ctx));
}
Compiler::Frag* Compiler::alt(Compiler::Frag* f1, Compiler::Frag* f2, ThreadContext* ctx) throw() 
{
	if(f1->i == 0)
	{
		return f2;
	}
	if(f2->i == 0)
	{
		return f1;
	}
	Compiler::Frag* f = newInst(Inst::Op::ALT, ctx);
	Inst* i = prog->getInst(f->i, ctx);
	i->out = f1->i;
	i->arg = f2->i;
	f->out = prog->append(f1->out, f2->out, ctx);
	return f;
}
Compiler::Frag* Compiler::quest(Compiler::Frag* f1, bool nongreedy, ThreadContext* ctx) throw() 
{
	Compiler::Frag* f = newInst(Inst::Op::ALT, ctx);
	Inst* i = prog->getInst(f->i, ctx);
	if(nongreedy)
	{
		i->arg = f1->i;
		f->out = f->i << 1;
	}
		else 
	{
		i->out = f1->i;
		f->out = f->i << 1 | 1;
	}
	f->out = prog->append(f->out, f1->out, ctx);
	return f;
}
Compiler::Frag* Compiler::star(Compiler::Frag* f1, bool nongreedy, ThreadContext* ctx) throw() 
{
	Compiler::Frag* f = newInst(Inst::Op::ALT, ctx);
	Inst* i = prog->getInst(f->i, ctx);
	if(nongreedy)
	{
		i->arg = f1->i;
		f->out = f->i << 1;
	}
		else 
	{
		i->out = f1->i;
		f->out = f->i << 1 | 1;
	}
	prog->patch(f1->out, f->i, ctx);
	return f;
}
Compiler::Frag* Compiler::plus(Compiler::Frag* f1, bool nongreedy, ThreadContext* ctx) throw() 
{
	return (new(ctx) Compiler::Frag(f1->i, star(f1, nongreedy, ctx)->out, ctx));
}
Compiler::Frag* Compiler::empty(int op, ThreadContext* ctx) throw() 
{
	Compiler::Frag* f = newInst(Inst::Op::EMPTY_WIDTH, ctx);
	prog->getInst(f->i, ctx)->arg = op;
	f->out = f->i << 1;
	return f;
}
Compiler::Frag* Compiler::rune(int _rune, int flags, ThreadContext* ctx) throw() 
{
	return rune(((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({_rune}, ctx)), flags, ctx);
}
Compiler::Frag* Compiler::rune(IArrayObjectPrimitive<int>* runes, int flags, ThreadContext* ctx) throw() 
{
	Compiler::Frag* f = newInst(Inst::Op::RUNE, ctx);
	Inst* i = prog->getInst(f->i, ctx);
	__GC_MV(i, &(i->runes), runes, IArrayObjectPrimitive<int>);
	flags = flags & (RE2::FOLD_CASE);
	if(runes->length != 1 || Unicode::simpleFold(runes->get(0), ctx) == runes->get(0))
	{
		flags = flags & (~RE2::FOLD_CASE);
	}
	i->arg = flags;
	f->out = f->i << 1;
	if(((flags & RE2::FOLD_CASE) == 0 && runes->length == 1) || (runes->length == 2 && runes->get(0) == runes->get(1)))
	{
		i->_op = Inst::Op::RUNE1;
	}
		else 
	{
		if(runes->length == 2 && runes->get(0) == 0 && runes->get(1) == Unicode::MAX_RUNE)
		{
			i->_op = Inst::Op::RUNE_ANY;
		}
				else 
		{
			if(runes->length == 4 && runes->get(0) == 0 && runes->get(1) == (int)L'\n' - 1 && runes->get(2) == (int)L'\n' + 1 && runes->get(3) == Unicode::MAX_RUNE)
			{
				i->_op = Inst::Op::RUNE_ANY_NOT_NL;
			}
		}
	}
	return f;
}
Compiler::Frag* Compiler::compile(Regexp* re, ThreadContext* ctx) throw() 
{
	switch(re->op) {
	case Regexp::Op::NO_MATCH:
		return fail(ctx);
	case Regexp::Op::EMPTY_MATCH:
		return nop(ctx);
	case Regexp::Op::LITERAL:
		if(re->runes->length == 0)
		{
			return nop(ctx);
		}
				else 
		{
			Compiler::Frag* f = nullptr;
			{
				const int __max_for = re->runes->length;
				for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
					int r = re->runes->get(__i_loop);
					{
						Compiler::Frag* f1 = rune(r, re->flags, ctx);
						f = (f == nullptr) ? f1 : cat(f, f1, ctx);
					}
				}
			}
			return f;
		}
	case Regexp::Op::CHAR_CLASS:
		return rune(re->runes, re->flags, ctx);
	case Regexp::Op::ANY_CHAR_NOT_NL:
		return rune(ANY_RUNE_NOT_NL, 0, ctx);
	case Regexp::Op::ANY_CHAR:
		return rune(ANY_RUNE, 0, ctx);
	case Regexp::Op::BEGIN_LINE:
		return empty(Utils::EMPTY_BEGIN_LINE, ctx);
	case Regexp::Op::END_LINE:
		return empty(Utils::EMPTY_END_LINE, ctx);
	case Regexp::Op::BEGIN_TEXT:
		return empty(Utils::EMPTY_BEGIN_TEXT, ctx);
	case Regexp::Op::END_TEXT:
		return empty(Utils::EMPTY_END_TEXT, ctx);
	case Regexp::Op::WORD_BOUNDARY:
		return empty(Utils::EMPTY_WORD_BOUNDARY, ctx);
	case Regexp::Op::NO_WORD_BOUNDARY:
		return empty(Utils::EMPTY_NO_WORD_BOUNDARY, ctx);
	case Regexp::Op::CAPTURE:
		{
			Compiler::Frag* bra = cap(re->cap << 1, ctx);Compiler::Frag* sub = compile(re->subs->get(0), ctx);Compiler::Frag* ket = cap((int)re->cap << 1 | 1, ctx);
			return cat(cat(bra, sub, ctx), ket, ctx);
		}
	case Regexp::Op::STAR:
		return star(compile(re->subs->get(0), ctx), (re->flags & RE2::NON_GREEDY) != 0, ctx);
	case Regexp::Op::PLUS:
		return plus(compile(re->subs->get(0), ctx), (re->flags & RE2::NON_GREEDY) != 0, ctx);
	case Regexp::Op::QUEST:
		return quest(compile(re->subs->get(0), ctx), (re->flags & RE2::NON_GREEDY) != 0, ctx);
	case Regexp::Op::CONCAT:
		if(re->subs->length == 0)
		{
			return nop(ctx);
		}
				else 
		{
			Compiler::Frag* f = nullptr;
			{
				const int __max_for = re->subs->length;
				for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
					Regexp* sub = re->subs->get(__i_loop);
					{
						Compiler::Frag* f1 = compile(sub, ctx);
						f = (f == nullptr) ? f1 : cat(f, f1, ctx);
					}
				}
			}
			return f;
		}
	case Regexp::Op::ALTERNATE:
		{
			if(re->subs->length == 0)
			{
				return nop(ctx);
			}
						else 
			{
				Compiler::Frag* f = nullptr;
				{
					const int __max_for = re->subs->length;
					for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
						Regexp* sub = re->subs->get(__i_loop);
						{
							Compiler::Frag* f1 = compile(sub, ctx);
							f = (f == nullptr) ? f1 : alt(f, f1, ctx);
						}
					}
				}
				return f;
			}
		}
	default:
		throw (new(ctx) IllegalStateException(ConstStr::getCNST_STR_119(), ctx));
		break;
	}
}
Prog* Compiler::compileRegexp(Regexp* re, ThreadContext* ctx) throw() 
{
	Compiler* c = (new(ctx) Compiler(ctx));
	Compiler::Frag* f = c->compile(re, ctx);
	c->prog->patch(f->out, c->newInst(Inst::Op::MATCH, ctx)->i, ctx);
	c->prog->start = f->i;
	return c->prog;
}
}}}

namespace com {namespace google {namespace re2j {





bool Compiler::Frag::__init_done = __init_static_variables();
bool Compiler::Frag::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Compiler::Frag", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Compiler::Frag::Frag(ThreadContext* ctx) throw()  : IObject(ctx), i(0), out(0)
{
	__construct_impl(0, 0, ctx);
}
void Compiler::Frag::__construct_impl(ThreadContext* ctx) throw() 
{
	__construct_impl(0, 0, ctx);
}
 Compiler::Frag::Frag(int i, ThreadContext* ctx) throw()  : IObject(ctx), i(0), out(0)
{
	__construct_impl(i, 0, ctx);
}
void Compiler::Frag::__construct_impl(int i, ThreadContext* ctx) throw() 
{
	__construct_impl(i, 0, ctx);
}
 Compiler::Frag::Frag(int i, int out, ThreadContext* ctx) throw()  : IObject(ctx), i(0), out(0)
{
	this->i = i;
	this->out = out;
}
void Compiler::Frag::__construct_impl(int i, int out, ThreadContext* ctx) throw() 
{
	this->i = i;
	this->out = out;
}
 Compiler::Frag::~Frag() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Compiler::Frag::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Frag", L"~Frag");
	if(!prepare){
		return;
	}
}
}}}

