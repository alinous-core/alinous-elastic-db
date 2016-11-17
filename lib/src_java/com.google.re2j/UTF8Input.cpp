#include "includes.h"


namespace com {namespace google {namespace re2j {





bool UTF8Input::__init_done = __init_static_variables();
bool UTF8Input::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UTF8Input", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UTF8Input::UTF8Input(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw()  : IObject(ctx), MachineInput(ctx), b(nullptr), start(0), end(0)
{
	__GC_MV(this, &(this->b), b, IArrayObjectPrimitive<char>);
	start = 0;
	end = b->length;
}
void UTF8Input::__construct_impl(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->b), b, IArrayObjectPrimitive<char>);
	start = 0;
	end = b->length;
}
 UTF8Input::UTF8Input(IArrayObjectPrimitive<char>* b, int start, int end, ThreadContext* ctx) throw()  : IObject(ctx), MachineInput(ctx), b(nullptr), start(0), end(0)
{
	if(end > b->length)
	{
		throw (new(ctx) ArrayIndexOutOfBoundsException(ConstStr::getCNST_STR_113()->clone(ctx)->append(end, ctx)->append(ConstStr::getCNST_STR_114(), ctx)->append(b->length, ctx), ctx));
	}
	__GC_MV(this, &(this->b), b, IArrayObjectPrimitive<char>);
	this->start = start;
	this->end = end;
}
void UTF8Input::__construct_impl(IArrayObjectPrimitive<char>* b, int start, int end, ThreadContext* ctx) throw() 
{
	if(end > b->length)
	{
		throw (new(ctx) ArrayIndexOutOfBoundsException(ConstStr::getCNST_STR_113()->clone(ctx)->append(end, ctx)->append(ConstStr::getCNST_STR_114(), ctx)->append(b->length, ctx), ctx));
	}
	__GC_MV(this, &(this->b), b, IArrayObjectPrimitive<char>);
	this->start = start;
	this->end = end;
}
 UTF8Input::~UTF8Input() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UTF8Input::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UTF8Input", L"~UTF8Input");
	__e_obj1.add(this->b, this);
	b = nullptr;
	if(!prepare){
		return;
	}
	MachineInput::__releaseRegerences(true, ctx);
}
int UTF8Input::step(int i, ThreadContext* ctx) throw() 
{
	i += start;
	if(i >= end)
	{
		return _EOF;
	}
	int x = b->get(i++) & 0xff;
	if((x & 0x80) == 0)
	{
		return x << 3 | 1;
	}
		else 
	{
		if((x & 0xE0) == 0xC0)
		{
			x = x & 0x1F;
			if(i >= end)
			{
				return _EOF;
			}
			x = x << 6 | (b->get(i++) & 0x3F);
			return x << 3 | 2;
		}
				else 
		{
			if((x & 0xF0) == 0xE0)
			{
				x = x & 0x0F;
				if(i + 1 >= end)
				{
					return _EOF;
				}
				x = x << 6 | (b->get(i++) & 0x3F);
				x = x << 6 | (b->get(i++) & 0x3F);
				return x << 3 | 3;
			}
						else 
			{
				x = x & 0x07;
				if(i + 2 >= end)
				{
					return _EOF;
				}
				x = x << 6 | (b->get(i++) & 0x3F);
				x = x << 6 | (b->get(i++) & 0x3F);
				x = x << 6 | (b->get(i++) & 0x3F);
				return x << 3 | 4;
			}
		}
	}
}
bool UTF8Input::canCheckPrefix(ThreadContext* ctx) throw() 
{
	return true;
}
int UTF8Input::index(RE2* re2, int pos, ThreadContext* ctx) throw() 
{
	pos += start;
	int i = Utils::indexOf(b, re2->prefixUTF8, pos, ctx);
	return i < 0 ? i : i - pos;
}
int UTF8Input::context(int pos, ThreadContext* ctx) throw() 
{
	pos += this->start;
	int r1 = -1;
	if(pos > this->start && pos <= this->end)
	{
		int start = pos - 1;
		r1 = b->get(start--);
		if(r1 >= 0x80)
		{
			int lim = pos - 4;
			if(lim < this->start)
			{
				lim = this->start;
			}
			while(start >= lim && (b->get(start) & 0xC0) == (char)0x80)
			{
				start -- ;
			}
			if(start < this->start)
			{
				start = this->start;
			}
			r1 = step(start, ctx) >> 3;
		}
	}
	int r2 = pos < this->end ? (step(pos, ctx) >> 3) : -1;
	return Utils::emptyOpContext(r1, r2, ctx);
}
int UTF8Input::endPos(ThreadContext* ctx) throw() 
{
	return end;
}
}}}

