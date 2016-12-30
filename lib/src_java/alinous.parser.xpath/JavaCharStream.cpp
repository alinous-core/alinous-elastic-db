#include "includes.h"


namespace alinous {namespace parser {namespace xpath {





constexpr const bool JavaCharStream::staticFlag;
bool JavaCharStream::__init_done = __init_static_variables();
bool JavaCharStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JavaCharStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JavaCharStream::JavaCharStream(java::io::Reader* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__GC_MV(this, &(inputStream), dstream, java::io::Reader);
	line = startline;
	column = startcolumn - 1;
	available = bufsize = buffersize;
	__GC_MV(this, &(buffer), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, buffersize), IArrayObjectPrimitive<wchar_t>);
	__GC_MV(this, &(bufline), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(bufcolumn), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(nextCharBuf), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 4096), IArrayObjectPrimitive<wchar_t>);
}
void JavaCharStream::__construct_impl(java::io::Reader* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(inputStream), dstream, java::io::Reader);
	line = startline;
	column = startcolumn - 1;
	available = bufsize = buffersize;
	__GC_MV(this, &(buffer), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, buffersize), IArrayObjectPrimitive<wchar_t>);
	__GC_MV(this, &(bufline), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(bufcolumn), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(nextCharBuf), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 4096), IArrayObjectPrimitive<wchar_t>);
}
 JavaCharStream::JavaCharStream(java::io::Reader* dstream, int startline, int startcolumn, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::Reader* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() 
{
	__construct_impl(dstream, startline, startcolumn, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::Reader* dstream, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, 1, 1, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::Reader* dstream, ThreadContext* ctx) throw() 
{
	__construct_impl(dstream, 1, 1, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, int buffersize, ThreadContext* ctx) : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(encoding == nullptr ? (new(ctx) java::io::InputStreamReader(dstream, ctx)) : (new(ctx) java::io::InputStreamReader(dstream, encoding, ctx)), startline, startcolumn, buffersize, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, int buffersize, ThreadContext* ctx)
{
	__construct_impl(encoding == nullptr ? (new(ctx) java::io::InputStreamReader(dstream, ctx)) : (new(ctx) java::io::InputStreamReader(dstream, encoding, ctx)), startline, startcolumn, buffersize, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl((new(ctx) java::io::InputStreamReader(dstream, ctx)), startline, startcolumn, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() 
{
	__construct_impl((new(ctx) java::io::InputStreamReader(dstream, ctx)), startline, startcolumn, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, ThreadContext* ctx) : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, encoding, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, ThreadContext* ctx)
{
	__construct_impl(dstream, encoding, startline, startcolumn, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, int startline, int startcolumn, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() 
{
	__construct_impl(dstream, startline, startcolumn, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, String* encoding, ThreadContext* ctx) : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, encoding, 1, 1, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, String* encoding, ThreadContext* ctx)
{
	__construct_impl(dstream, encoding, 1, 1, 4096, ctx);
}
 JavaCharStream::JavaCharStream(java::io::InputStream* dstream, ThreadContext* ctx) throw()  : IObject(ctx), bufpos(-1), bufsize(0), available(0), tokenBegin(0), bufline(nullptr), bufcolumn(nullptr), column(0), line(1), prevCharIsCR(false), prevCharIsLF(false), inputStream(nullptr), nextCharBuf(nullptr), buffer(nullptr), maxNextCharInd(0), nextCharInd(-1), inBuf(0), tabSize(8), trackLineColumn(true)
{
	__construct_impl(dstream, 1, 1, 4096, ctx);
}
void JavaCharStream::__construct_impl(java::io::InputStream* dstream, ThreadContext* ctx) throw() 
{
	__construct_impl(dstream, 1, 1, 4096, ctx);
}
 JavaCharStream::~JavaCharStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JavaCharStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JavaCharStream", L"~JavaCharStream");
	__e_obj1.add(this->bufline, this);
	bufline = nullptr;
	__e_obj1.add(this->bufcolumn, this);
	bufcolumn = nullptr;
	__e_obj1.add(this->inputStream, this);
	inputStream = nullptr;
	__e_obj1.add(this->nextCharBuf, this);
	nextCharBuf = nullptr;
	__e_obj1.add(this->buffer, this);
	buffer = nullptr;
	if(!prepare){
		return;
	}
}
void JavaCharStream::setTabSize(int i, ThreadContext* ctx) throw() 
{
	tabSize = i;
}
int JavaCharStream::getTabSize(ThreadContext* ctx) throw() 
{
	return tabSize;
}
wchar_t JavaCharStream::BeginToken(ThreadContext* ctx)
{
	if(inBuf > 0)
	{
		--inBuf;
		if(++bufpos == bufsize)
		{
			bufpos = 0;
		}
		tokenBegin = bufpos;
		return buffer->get(bufpos);
	}
	tokenBegin = 0;
	bufpos = -1;
	return readChar(ctx);
}
wchar_t JavaCharStream::readChar(ThreadContext* ctx)
{
	if(inBuf > 0)
	{
		--inBuf;
		if(++bufpos == bufsize)
		{
			bufpos = 0;
		}
		return buffer->get(bufpos);
	}
	wchar_t c = 0;
	if(++bufpos == available)
	{
		AdjustBuffSize(ctx);
	}
	buffer->set(c = ReadByte(ctx),bufpos, ctx);
	if((buffer->get(bufpos)) == L'\\')
	{
		if(trackLineColumn)
		{
			UpdateLineColumn(c, ctx);
		}
		int backSlashCnt = 1;
		for(; ; )
		{
			if(++bufpos == available)
			{
				AdjustBuffSize(ctx);
			}
			{
				try
				{
					buffer->set(c = ReadByte(ctx),bufpos, ctx);
					if((buffer->get(bufpos)) != L'\\')
					{
						if(trackLineColumn)
						{
							UpdateLineColumn(c, ctx);
						}
						if((c == L'u') && ((backSlashCnt & 1) == 1))
						{
							if(--bufpos < 0)
							{
								bufpos = bufsize - 1;
							}
							break ;
						}
						backup(backSlashCnt, ctx);
						return L'\\';
					}
				}
				catch(java::io::IOException* e)
				{
					if(backSlashCnt > 1)
					{
						backup(backSlashCnt - 1, ctx);
					}
					return L'\\';
				}
			}
			if(trackLineColumn)
			{
				UpdateLineColumn(c, ctx);
			}
			backSlashCnt ++ ;
		}
		{
			try
			{
				c = ReadByte(ctx);
				while((c) == L'u')
				++column;
				buffer->set(c = ((wchar_t)(hexval(c, ctx) << 12 | hexval(ReadByte(ctx), ctx) << 8 | hexval(ReadByte(ctx), ctx) << 4 | hexval(ReadByte(ctx), ctx))),bufpos, ctx);
				column += 4;
			}
			catch(java::io::IOException* e)
			{
				throw (new(ctx) Error(ConstStr::getCNST_STR_1258()->clone(ctx)->append(line, ctx)->append(ConstStr::getCNST_STR_1259(), ctx)->append(column, ctx)->append(ConstStr::getCNST_STR_947(), ctx), ctx));
			}
		}
		if(backSlashCnt == 1)
		{
			return c;
		}
				else 
		{
			backup(backSlashCnt - 1, ctx);
			return L'\\';
		}
	}
		else 
	{
		UpdateLineColumn(c, ctx);
		return c;
	}
}
int JavaCharStream::getColumn(ThreadContext* ctx) throw() 
{
	return bufcolumn->get(bufpos);
}
int JavaCharStream::getLine(ThreadContext* ctx) throw() 
{
	return bufline->get(bufpos);
}
int JavaCharStream::getEndColumn(ThreadContext* ctx) throw() 
{
	return bufcolumn->get(bufpos);
}
int JavaCharStream::getEndLine(ThreadContext* ctx) throw() 
{
	return bufline->get(bufpos);
}
int JavaCharStream::getBeginColumn(ThreadContext* ctx) throw() 
{
	return bufcolumn->get(tokenBegin);
}
int JavaCharStream::getBeginLine(ThreadContext* ctx) throw() 
{
	return bufline->get(tokenBegin);
}
void JavaCharStream::backup(int amount, ThreadContext* ctx) throw() 
{
	inBuf += amount;
	bufpos -= amount;
	if((bufpos) < 0)
	{
		bufpos += bufsize;
	}
}
void JavaCharStream::ReInit(java::io::Reader* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(inputStream), dstream, java::io::Reader);
	line = startline;
	column = startcolumn - 1;
	if(buffer == (IArrayObjectPrimitive<wchar_t>*)nullptr || buffersize != buffer->length)
	{
		available = bufsize = buffersize;
		__GC_MV(this, &(buffer), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, buffersize), IArrayObjectPrimitive<wchar_t>);
		__GC_MV(this, &(bufline), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
		__GC_MV(this, &(bufcolumn), ArrayAllocatorPrimitive<int>::allocatep(ctx, buffersize), IArrayObjectPrimitive<int>);
		__GC_MV(this, &(nextCharBuf), ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 4096), IArrayObjectPrimitive<wchar_t>);
	}
	prevCharIsLF = prevCharIsCR = false;
	tokenBegin = inBuf = maxNextCharInd = 0;
	nextCharInd = bufpos = -1;
}
void JavaCharStream::ReInit(java::io::Reader* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() 
{
	ReInit(dstream, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::ReInit(java::io::Reader* dstream, ThreadContext* ctx) throw() 
{
	ReInit(dstream, 1, 1, 4096, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, int buffersize, ThreadContext* ctx)
{
	ReInit(encoding == nullptr ? (new(ctx) java::io::InputStreamReader(dstream, ctx)) : (new(ctx) java::io::InputStreamReader(dstream, encoding, ctx)), startline, startcolumn, buffersize, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, int startline, int startcolumn, int buffersize, ThreadContext* ctx) throw() 
{
	ReInit((new(ctx) java::io::InputStreamReader(dstream, ctx)), startline, startcolumn, buffersize, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, String* encoding, int startline, int startcolumn, ThreadContext* ctx)
{
	ReInit(dstream, encoding, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, int startline, int startcolumn, ThreadContext* ctx) throw() 
{
	ReInit(dstream, startline, startcolumn, 4096, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, String* encoding, ThreadContext* ctx)
{
	ReInit(dstream, encoding, 1, 1, 4096, ctx);
}
void JavaCharStream::ReInit(java::io::InputStream* dstream, ThreadContext* ctx) throw() 
{
	ReInit(dstream, 1, 1, 4096, ctx);
}
String* JavaCharStream::GetImage(ThreadContext* ctx) throw() 
{
	if(bufpos >= tokenBegin)
	{
		return (new(ctx) String(buffer, tokenBegin, bufpos - tokenBegin + 1, ctx));
	}
		else 
	{
		return (new(ctx) String(buffer, tokenBegin, bufsize - tokenBegin, ctx))->clone(ctx)->append((new(ctx) String(buffer, 0, bufpos + 1, ctx)), ctx);
	}
}
IArrayObjectPrimitive<wchar_t>* JavaCharStream::GetSuffix(int len, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<wchar_t>* ret = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, len);
	if((bufpos + 1) >= len)
	{
		System::arraycopy(buffer, bufpos - len + 1, ret, 0, len, ctx);
	}
		else 
	{
		System::arraycopy(buffer, bufsize - (len - bufpos - 1), ret, 0, len - bufpos - 1, ctx);
		System::arraycopy(buffer, 0, ret, len - bufpos - 1, bufpos + 1, ctx);
	}
	return ret;
}
void JavaCharStream::Done(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(nextCharBuf), nullptr, IArrayObjectPrimitive<wchar_t>);
	__GC_MV(this, &(buffer), nullptr, IArrayObjectPrimitive<wchar_t>);
	__GC_MV(this, &(bufline), nullptr, IArrayObjectPrimitive<int>);
	__GC_MV(this, &(bufcolumn), nullptr, IArrayObjectPrimitive<int>);
}
void JavaCharStream::adjustBeginLineColumn(int newLine, int newCol, ThreadContext* ctx) throw() 
{
	int start = tokenBegin;
	int len = 0;
	if(bufpos >= tokenBegin)
	{
		len = bufpos - tokenBegin + inBuf + 1;
	}
		else 
	{
		len = bufsize - tokenBegin + bufpos + 1 + inBuf;
	}
	int i = 0;int j = 0;int k = 0;
	int nextColDiff = 0;int columnDiff = 0;
	if(i < len){
		j = start % bufsize;
	}
	if(i < len){
		k = ++start % bufsize;
	}
	while(i < len && bufline->get(j) == bufline->get(k))
	{
		bufline->set(newLine,j, ctx);
		nextColDiff = columnDiff + bufcolumn->get(k) - bufcolumn->get(j);
		bufcolumn->set(newCol + columnDiff,j, ctx);
		columnDiff = nextColDiff;
		i ++ ;
	}
	if(i < len)
	{
		bufline->set(newLine++,j, ctx);
		bufcolumn->set(newCol + columnDiff,j, ctx);
		while(i++ < len)
		{
			j = start % bufsize;
			if(bufline->get(j) != bufline->get(++start % bufsize))
			{
				bufline->set(newLine++,j, ctx);
			}
						else 
			{
				bufline->set(newLine,j, ctx);
			}
		}
	}
	line = bufline->get(j);
	column = bufcolumn->get(j);
}
void JavaCharStream::ExpandBuff(bool wrapAround, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<wchar_t>* newbuffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, bufsize + 2048);
	IArrayObjectPrimitive<int>* newbufline = ArrayAllocatorPrimitive<int>::allocatep(ctx, bufsize + 2048);
	IArrayObjectPrimitive<int>* newbufcolumn = ArrayAllocatorPrimitive<int>::allocatep(ctx, bufsize + 2048);
	{
		try
		{
			if(wrapAround)
			{
				System::arraycopy(buffer, tokenBegin, newbuffer, 0, bufsize - tokenBegin, ctx);
				System::arraycopy(buffer, 0, newbuffer, bufsize - tokenBegin, bufpos, ctx);
				__GC_MV(this, &(buffer), newbuffer, IArrayObjectPrimitive<wchar_t>);
				System::arraycopy(bufline, tokenBegin, newbufline, 0, bufsize - tokenBegin, ctx);
				System::arraycopy(bufline, 0, newbufline, bufsize - tokenBegin, bufpos, ctx);
				__GC_MV(this, &(bufline), newbufline, IArrayObjectPrimitive<int>);
				System::arraycopy(bufcolumn, tokenBegin, newbufcolumn, 0, bufsize - tokenBegin, ctx);
				System::arraycopy(bufcolumn, 0, newbufcolumn, bufsize - tokenBegin, bufpos, ctx);
				__GC_MV(this, &(bufcolumn), newbufcolumn, IArrayObjectPrimitive<int>);
				bufpos += (bufsize - tokenBegin);
			}
						else 
			{
				System::arraycopy(buffer, tokenBegin, newbuffer, 0, bufsize - tokenBegin, ctx);
				__GC_MV(this, &(buffer), newbuffer, IArrayObjectPrimitive<wchar_t>);
				System::arraycopy(bufline, tokenBegin, newbufline, 0, bufsize - tokenBegin, ctx);
				__GC_MV(this, &(bufline), newbufline, IArrayObjectPrimitive<int>);
				System::arraycopy(bufcolumn, tokenBegin, newbufcolumn, 0, bufsize - tokenBegin, ctx);
				__GC_MV(this, &(bufcolumn), newbufcolumn, IArrayObjectPrimitive<int>);
				bufpos -= tokenBegin;
			}
		}
		catch(Throwable* t)
		{
			throw (new(ctx) Error(t->getMessage(ctx), ctx));
		}
	}
	available = (bufsize += 2048);
	tokenBegin = 0;
}
void JavaCharStream::FillBuff(ThreadContext* ctx)
{
	int i = 0;
	if(maxNextCharInd == 4096)
	{
		maxNextCharInd = nextCharInd = 0;
	}
	{
		try
		{
			i = inputStream->read(nextCharBuf, maxNextCharInd, 4096 - maxNextCharInd, ctx);
			if((i) == -1)
			{
				inputStream->close(ctx);
				throw (new(ctx) java::io::IOException(ctx));
			}
						else 
			{
				maxNextCharInd += i;
			}
			return;
		}
		catch(java::io::IOException* e)
		{
			if(bufpos != 0)
			{
				--bufpos;
				backup(0, ctx);
			}
						else 
			{
				bufline->set(line,bufpos, ctx);
				bufcolumn->set(column,bufpos, ctx);
			}
			throw e;
		}
	}
}
wchar_t JavaCharStream::ReadByte(ThreadContext* ctx)
{
	if(++nextCharInd >= maxNextCharInd)
	{
		FillBuff(ctx);
	}
	return nextCharBuf->get(nextCharInd);
}
void JavaCharStream::AdjustBuffSize(ThreadContext* ctx) throw() 
{
	if(available == bufsize)
	{
		if(tokenBegin > 2048)
		{
			bufpos = 0;
			available = tokenBegin;
		}
				else 
		{
			ExpandBuff(false, ctx);
		}
	}
		else 
	{
		if(available > tokenBegin)
		{
			available = bufsize;
		}
				else 
		{
			if((tokenBegin - available) < 2048)
			{
				ExpandBuff(true, ctx);
			}
						else 
			{
				available = tokenBegin;
			}
		}
	}
}
void JavaCharStream::UpdateLineColumn(wchar_t c, ThreadContext* ctx) throw() 
{
	column ++ ;
	if(prevCharIsLF)
	{
		prevCharIsLF = false;
		line += (column = 1);
	}
		else 
	{
		if(prevCharIsCR)
		{
			prevCharIsCR = false;
			if(c == L'\n')
			{
				prevCharIsLF = true;
			}
						else 
			{
				line += (column = 1);
			}
		}
	}
	switch(c) {
	case L'\r':
		prevCharIsCR = true;
		break ;
	case L'\n':
		prevCharIsLF = true;
		break ;
	case L'\t':
		column -- ;
		column += (tabSize - (column % tabSize));
		break ;
	default:
		break ;
	}
	bufline->set(line,bufpos, ctx);
	bufcolumn->set(column,bufpos, ctx);
}
bool JavaCharStream::getTrackLineColumn(ThreadContext* ctx) throw() 
{
	return trackLineColumn;
}
void JavaCharStream::setTrackLineColumn(bool tlc, ThreadContext* ctx) throw() 
{
	trackLineColumn = tlc;
}
int JavaCharStream::hexval(wchar_t c, ThreadContext* ctx)
{
	switch(c) {
	case L'0':
		return 0;
	case L'1':
		return 1;
	case L'2':
		return 2;
	case L'3':
		return 3;
	case L'4':
		return 4;
	case L'5':
		return 5;
	case L'6':
		return 6;
	case L'7':
		return 7;
	case L'8':
		return 8;
	case L'9':
		return 9;
	case L'a':
	case L'A':
		return 10;
	case L'b':
	case L'B':
		return 11;
	case L'c':
	case L'C':
		return 12;
	case L'd':
	case L'D':
		return 13;
	case L'e':
	case L'E':
		return 14;
	case L'f':
	case L'F':
		return 15;
	}
	throw (new(ctx) java::io::IOException(ctx));
}
}}}

