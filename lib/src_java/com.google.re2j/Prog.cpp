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





bool Prog::__init_done = __init_static_variables();
bool Prog::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Prog", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Prog::~Prog() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Prog::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Prog", L"~Prog");
	__e_obj1.add(this->inst, this);
	inst = nullptr;
	if(!prepare){
		return;
	}
}
String* Prog::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* out = (new(ctx) StringBuilder(ctx));
	for(int pc = 0; pc < inst->size(ctx); ++pc)
	{
		int len = out->length(ctx);
		out->append(pc, ctx);
		if(pc == start)
		{
			out->append(L'*', ctx);
		}
		out->append(ConstStr::getCNST_STR_118()->substring(out->length(ctx) - len, ctx), ctx)->append(inst->get(pc, ctx), ctx)->append(L'\n', ctx);
	}
	return out->toString(ctx);
}
Inst* Prog::getInst(int pc, ThreadContext* ctx) throw() 
{
	return inst->get(pc, ctx);
}
int Prog::numInst(ThreadContext* ctx) throw() 
{
	return inst->size(ctx);
}
void Prog::addInst(Inst::Op op, ThreadContext* ctx) throw() 
{
	inst->add((new(ctx) Inst(op, ctx)), ctx);
}
Inst* Prog::skipNop(int pc, ThreadContext* ctx) throw() 
{
	Inst* i = inst->get(pc, ctx);
	while(i->_op == Inst::Op::NOP || i->_op == Inst::Op::CAPTURE)
	{
		i = inst->get(pc, ctx);
		pc = i->out;
	}
	return i;
}
bool Prog::prefix(StringBuilder* prefix, ThreadContext* ctx) throw() 
{
	Inst* i = skipNop(start, ctx);
	if(i->op(ctx) != Inst::Op::RUNE || i->runes->length != 1)
	{
		return i->_op == Inst::Op::MATCH;
	}
	while(i->op(ctx) == Inst::Op::RUNE && i->runes->length == 1 && (i->arg & RE2::FOLD_CASE) == 0)
	{
		prefix->appendCodePoint(i->runes->get(0), ctx);
		i = skipNop(i->out, ctx);
	}
	return i->_op == Inst::Op::MATCH;
}
int Prog::startCond(ThreadContext* ctx) throw() 
{
	int flag = 0;
	int pc = start;
	for(; ; )
	{
		Inst* i = inst->get(pc, ctx);
		switch(i->_op) {
		case Inst::Op::EMPTY_WIDTH:
			flag = flag | (i->arg);
			break ;
		case Inst::Op::FAIL:
			return -1;
		case Inst::Op::CAPTURE:
		case Inst::Op::NOP:
			break ;
		default:
			goto loop_out_break;
		}
		pc = i->out;
	}
	loop_out_break: ;
	return flag;
}
int Prog::next(int l, ThreadContext* ctx) throw() 
{
	Inst* i = inst->get(l >> 1, ctx);
	if((l & 1) == 0)
	{
		return i->out;
	}
	return i->arg;
}
void Prog::patch(int l, int val, ThreadContext* ctx) throw() 
{
	while(l != 0)
	{
		Inst* i = inst->get(l >> 1, ctx);
		if((l & 1) == 0)
		{
			l = i->out;
			i->out = val;
		}
				else 
		{
			l = i->arg;
			i->arg = val;
		}
	}
}
int Prog::append(int l1, int l2, ThreadContext* ctx) throw() 
{
	if(l1 == 0)
	{
		return l2;
	}
	if(l2 == 0)
	{
		return l1;
	}
	int last = l1;
	for(; ; )
	{
		int _next = next(last, ctx);
		if(_next == 0)
		{
			break ;
		}
		last = _next;
	}
	Inst* i = inst->get(last >> 1, ctx);
	if((last & 1) == 0)
	{
		i->out = l2;
	}
		else 
	{
		i->arg = l2;
	}
	return l1;
}
}}}

