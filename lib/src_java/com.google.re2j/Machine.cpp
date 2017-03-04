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
#include "com.google.re2j/Compiler.h"
#include "com.google.re2j/UnicodeTable2.h"
#include "com.google.re2j/Utils.h"
#include "com.google.re2j/UnicodeTables.h"
#include "com.google.re2j/Pattern.h"
#include "com.google.re2j/Matcher.h"

namespace com {namespace google {namespace re2j {





bool Machine::__init_done = __init_static_variables();
bool Machine::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Machine", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Machine::Machine(RE2* re2, ThreadContext* ctx) throw()  : IObject(ctx), re2(nullptr), prog(nullptr), q0(nullptr), q1(nullptr), pool(GCUtils<List<Machine::LogicalThread> >::ins(this, (new(ctx) ArrayList<Machine::LogicalThread>(ctx)), ctx, __FILEW__, __LINE__, L"")), matched(0), matchcap(nullptr)
{
	__GC_MV(this, &(this->prog), re2->prog, Prog);
	__GC_MV(this, &(this->re2), re2, RE2);
	__GC_MV(this, &(this->q0), (new(ctx) Machine::Queue(prog->numInst(ctx), ctx)), Machine::Queue);
	__GC_MV(this, &(this->q1), (new(ctx) Machine::Queue(prog->numInst(ctx), ctx)), Machine::Queue);
	__GC_MV(this, &(this->matchcap), ArrayAllocatorPrimitive<int>::allocatep(ctx, prog->numCap < 2 ? 2 : prog->numCap), IArrayObjectPrimitive<int>);
}
void Machine::__construct_impl(RE2* re2, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->prog), re2->prog, Prog);
	__GC_MV(this, &(this->re2), re2, RE2);
	__GC_MV(this, &(this->q0), (new(ctx) Machine::Queue(prog->numInst(ctx), ctx)), Machine::Queue);
	__GC_MV(this, &(this->q1), (new(ctx) Machine::Queue(prog->numInst(ctx), ctx)), Machine::Queue);
	__GC_MV(this, &(this->matchcap), ArrayAllocatorPrimitive<int>::allocatep(ctx, prog->numCap < 2 ? 2 : prog->numCap), IArrayObjectPrimitive<int>);
}
 Machine::~Machine() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Machine::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Machine", L"~Machine");
	__e_obj1.add(this->re2, this);
	re2 = nullptr;
	__e_obj1.add(this->prog, this);
	prog = nullptr;
	__e_obj1.add(this->q0, this);
	q0 = nullptr;
	__e_obj1.add(this->q1, this);
	q1 = nullptr;
	__e_obj1.add(this->pool, this);
	pool = nullptr;
	__e_obj1.add(this->matchcap, this);
	matchcap = nullptr;
	if(!prepare){
		return;
	}
}
void Machine::init(int ncap, ThreadContext* ctx) throw() 
{
	{
		Iterator<Machine::LogicalThread>* __tit = pool->iterator(ctx);
		Machine::LogicalThread* t = nullptr;
		while(__tit->hasNext(ctx)){
			t = __tit->next(ctx);
			{
				__GC_MV(t, &(t->cap), ArrayAllocatorPrimitive<int>::allocatep(ctx, ncap), IArrayObjectPrimitive<int>);
			}
		}
	}
	__GC_MV(this, &(this->matchcap), ArrayAllocatorPrimitive<int>::allocatep(ctx, ncap), IArrayObjectPrimitive<int>);
}
IArrayObjectPrimitive<int>* Machine::submatches(ThreadContext* ctx) throw() 
{
	if(matchcap->length == 0)
	{
		return Utils::EMPTY_INTS;
	}
	IArrayObjectPrimitive<int>* cap = ArrayAllocatorPrimitive<int>::allocatep(ctx, matchcap->length);
	System::arraycopy(matchcap, 0, cap, 0, matchcap->length, ctx);
	return cap;
}
bool Machine::match(MachineInput* in, int pos, int anchor, ThreadContext* ctx) throw() 
{
	int startCond = re2->cond;
	if(startCond == Utils::EMPTY_ALL)
	{
		return false;
	}
	if((anchor == RE2::ANCHOR_START || anchor == RE2::ANCHOR_BOTH) && pos != 0)
	{
		return false;
	}
	matched = false;
	Arrays::fill(matchcap, -1, ctx);
	Machine::Queue* runq = q0;Machine::Queue* nextq = q1;
	int r = in->step(pos, ctx);
	int rune = r >> 3;
	int width = r & 7;
	int rune1 = -1;
	int width1 = 0;
	if(r != MachineInput::_EOF)
	{
		r = in->step(pos + width, ctx);
		rune1 = r >> 3;
		width1 = r & 7;
	}
	int flag = 0;
	if(pos == 0)
	{
		flag = Utils::emptyOpContext(-1, rune, ctx);
	}
		else 
	{
		flag = in->context(pos, ctx);
	}
	for(; ; )
	{
		if(runq->isEmpty(ctx))
		{
			if((startCond & Utils::EMPTY_BEGIN_TEXT) != 0 && pos != 0)
			{
				break ;
			}
			if(matched)
			{
				break ;
			}
			if(!re2->prefix->isEmpty(ctx) && rune1 != re2->prefixRune && in->canCheckPrefix(ctx))
			{
				int advance = in->index(re2, pos, ctx);
				if(advance < 0)
				{
					break ;
				}
				pos += advance;
				r = in->step(pos, ctx);
				rune = r >> 3;
				width = r & 7;
				r = in->step(pos + width, ctx);
				rune1 = r >> 3;
				width1 = r & 7;
			}
		}
		if(!matched && (pos == 0 || anchor == RE2::UNANCHORED))
		{
			if(matchcap->length > 0)
			{
				matchcap->set(pos,0, ctx);
			}
			add(runq, prog->start, pos, matchcap, flag, nullptr, ctx);
		}
		flag = Utils::emptyOpContext(rune, rune1, ctx);
		step(runq, nextq, pos, pos + width, rune, flag, anchor, pos == in->endPos(ctx), ctx);
		if(width == 0)
		{
			break ;
		}
		if(matchcap->length == 0 && matched)
		{
			break ;
		}
		pos += width;
		rune = rune1;
		width = width1;
		if(rune != -1)
		{
			r = in->step(pos + width, ctx);
			rune1 = r >> 3;
			width1 = r & 7;
		}
		Machine::Queue* tmpq = runq;
		runq = nextq;
		nextq = tmpq;
	}
	nextq->clear(pool, ctx);
	return matched;
}
Machine::LogicalThread* Machine::alloc(Inst* inst, ThreadContext* ctx) throw() 
{
	int n = pool->size(ctx);
	Machine::LogicalThread* t = n > 0 ? pool->remove(n - 1, ctx) : (new(ctx) Machine::LogicalThread(matchcap->length, ctx));
	__GC_MV(t, &(t->inst), inst, Inst);
	return t;
}
void Machine::step(Machine::Queue* runq, Machine::Queue* nextq, int pos, int nextPos, int c, int nextCond, int anchor, bool atEnd, ThreadContext* ctx) throw() 
{
	bool longest = re2->longest;
	for(int j = 0; j < runq->size; ++j)
	{
		Machine::Entry* entry = runq->dense->get(j);
		if(entry == nullptr)
		{
			continue;
		}
		Machine::LogicalThread* t = entry->thread;
		if(t == nullptr)
		{
			continue;
		}
		if(longest && matched && t->cap->length > 0 && matchcap->get(0) < t->cap->get(0))
		{
			pool->add(t, ctx);
			continue;
		}
		Inst* i = t->inst;
		bool _add = false;
		switch(i->_op) {
		case Inst::Op::MATCH:
			if(anchor == RE2::ANCHOR_BOTH && !atEnd)
			{
				break ;
			}
			if(t->cap->length > 0 && (!longest || !matched || matchcap->get(1) < pos))
			{
				t->cap->set(pos,1, ctx);
				System::arraycopy(t->cap, 0, matchcap, 0, t->cap->length, ctx);
			}
			if(!longest)
			{
				for(int k = j + 1; k < runq->size; ++k)
				{
					Machine::Entry* d = runq->dense->get(k);
					if(d->thread != nullptr)
					{
						pool->add(d->thread, ctx);
					}
				}
				runq->size = 0;
			}
			matched = true;
			break ;
		case Inst::Op::RUNE:
			_add = i->matchRune(c, ctx);
			break ;
		case Inst::Op::RUNE1:
			_add = c == i->runes->get(0);
			break ;
		case Inst::Op::RUNE_ANY:
			_add = true;
			break ;
		case Inst::Op::RUNE_ANY_NOT_NL:
			_add = c != (int)L'\n';
			break ;
		default:
			throw (new(ctx) IllegalStateException(ConstStr::getCNST_STR_71(), ctx));
			break;
		}
		if(_add)
		{
			t = add(nextq, i->out, nextPos, t->cap, nextCond, t, ctx);
		}
		if(t != nullptr)
		{
			pool->add(t, ctx);
		}
	}
	runq->size = 0;
}
Machine::LogicalThread* Machine::add(Machine::Queue* q, int pc, int pos, IArrayObjectPrimitive<int>* cap, int cond, Machine::LogicalThread* t, ThreadContext* ctx) throw() 
{
	if(pc == 0)
	{
		return t;
	}
	if(q->contains(pc, ctx))
	{
		return t;
	}
	Machine::Entry* d = q->add(pc, ctx);
	Inst* inst = prog->getInst(pc, ctx);
	switch(inst->op(ctx)) {
	default:
		throw (new(ctx) IllegalStateException(ConstStr::getCNST_STR_72(), ctx));
		break;
	case Inst::Op::FAIL:
		break ;
	case Inst::Op::ALT:
	case Inst::Op::ALT_MATCH:
		t = add(q, inst->out, pos, cap, cond, t, ctx);
		t = add(q, inst->arg, pos, cap, cond, t, ctx);
		break ;
	case Inst::Op::EMPTY_WIDTH:
		if((inst->arg & ~cond) == 0)
		{
			t = add(q, inst->out, pos, cap, cond, t, ctx);
		}
		break ;
	case Inst::Op::NOP:
		t = add(q, inst->out, pos, cap, cond, t, ctx);
		break ;
	case Inst::Op::CAPTURE:
		if(inst->arg < cap->length)
		{
			int opos = cap->get(inst->arg);
			cap->set(pos,inst->arg, ctx);
			add(q, inst->out, pos, cap, cond, nullptr, ctx);
			cap->set(opos,inst->arg, ctx);
		}
				else 
		{
			t = add(q, inst->out, pos, cap, cond, t, ctx);
		}
		break ;
	case Inst::Op::MATCH:
	case Inst::Op::RUNE:
	case Inst::Op::RUNE1:
	case Inst::Op::RUNE_ANY:
	case Inst::Op::RUNE_ANY_NOT_NL:
		if(t == nullptr)
		{
			t = alloc(inst, ctx);
		}
				else 
		{
			__GC_MV(t, &(t->inst), inst, Inst);
		}
		if(cap->length > 0 && t->cap != cap)
		{
			System::arraycopy(cap, 0, t->cap, 0, cap->length, ctx);
		}
		__GC_MV(d, &(d->thread), t, Machine::LogicalThread);
		t = nullptr;
		break ;
	}
	return t;
}
}}}

namespace com {namespace google {namespace re2j {





bool Machine::LogicalThread::__init_done = __init_static_variables();
bool Machine::LogicalThread::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Machine::LogicalThread", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Machine::LogicalThread::LogicalThread(int n, ThreadContext* ctx) throw()  : IObject(ctx), cap(nullptr), inst(nullptr)
{
	__GC_MV(this, &(this->cap), ArrayAllocatorPrimitive<int>::allocatep(ctx, n), IArrayObjectPrimitive<int>);
}
void Machine::LogicalThread::__construct_impl(int n, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->cap), ArrayAllocatorPrimitive<int>::allocatep(ctx, n), IArrayObjectPrimitive<int>);
}
 Machine::LogicalThread::~LogicalThread() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Machine::LogicalThread::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LogicalThread", L"~LogicalThread");
	__e_obj1.add(this->cap, this);
	cap = nullptr;
	__e_obj1.add(this->inst, this);
	inst = nullptr;
	if(!prepare){
		return;
	}
}
}}}

namespace com {namespace google {namespace re2j {





bool Machine::Entry::__init_done = __init_static_variables();
bool Machine::Entry::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Machine::Entry", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Machine::Entry::~Entry() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Machine::Entry::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Entry", L"~Entry");
	__e_obj1.add(this->thread, this);
	thread = nullptr;
	if(!prepare){
		return;
	}
}
}}}

namespace com {namespace google {namespace re2j {





bool Machine::Queue::__init_done = __init_static_variables();
bool Machine::Queue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Machine::Queue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Machine::Queue::Queue(int n, ThreadContext* ctx) throw()  : IObject(ctx), dense(nullptr), sparse(nullptr), size(0)
{
	__GC_MV(this, &(this->sparse), ArrayAllocatorPrimitive<int>::allocatep(ctx, n), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(this->dense), ArrayAllocator<Entry>::allocate(ctx, n), IArrayObject<Entry>);
}
void Machine::Queue::__construct_impl(int n, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->sparse), ArrayAllocatorPrimitive<int>::allocatep(ctx, n), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(this->dense), ArrayAllocator<Entry>::allocate(ctx, n), IArrayObject<Entry>);
}
 Machine::Queue::~Queue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Machine::Queue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Queue", L"~Queue");
	__e_obj1.add(this->dense, this);
	dense = nullptr;
	__e_obj1.add(this->sparse, this);
	sparse = nullptr;
	if(!prepare){
		return;
	}
}
String* Machine::Queue::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* out = (new(ctx) StringBuilder(ctx));
	out->append(L'{', ctx);
	for(int i = 0; i < size; ++i)
	{
		if(i != 0)
		{
			out->append(ConstStr::getCNST_STR_73(), ctx);
		}
		out->append(dense->get(i)->pc, ctx);
	}
	out->append(L'}', ctx);
	return out->toString(ctx);
}
bool Machine::Queue::contains(int pc, ThreadContext* ctx) throw() 
{
	int j = sparse->get(pc);
	if(j >= size)
	{
		return false;
	}
	Machine::Entry* d = dense->get(j);
	return d != nullptr && d->pc == pc;
}
bool Machine::Queue::isEmpty(ThreadContext* ctx) throw() 
{
	return size == 0;
}
Machine::Entry* Machine::Queue::add(int pc, ThreadContext* ctx) throw() 
{
	int j = size++;
	sparse->set(j,pc, ctx);
	Machine::Entry* e = dense->get(j);
	if(e == nullptr)
	{
		dense->set((new(ctx) Machine::Entry(ctx)),j, ctx);
		e = dense->get(j);
	}
	__GC_MV(e, &(e->thread), nullptr, Machine::LogicalThread);
	e->pc = pc;
	return e;
}
void Machine::Queue::clear(List<Machine::LogicalThread>* freePool, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < size; ++i)
	{
		Machine::Entry* entry = dense->get(i);
		if(entry != nullptr && entry->thread != nullptr)
		{
			freePool->add(entry->thread, ctx);
		}
	}
	size = 0;
}
}}}

