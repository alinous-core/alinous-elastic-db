#include "includes.h"


namespace com {namespace google {namespace re2j {





bool Matcher::__init_done = __init_static_variables();
bool Matcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Matcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Matcher::Matcher(Pattern* pattern, ThreadContext* ctx) throw()  : IObject(ctx), _pattern(nullptr), groups(nullptr), _groupCount(0), inputSequence(nullptr), _inputLength(0), appendPos(0), hasMatch(0), hasGroups(0), anchorFlag(0)
{
	if(pattern == nullptr)
	{
		throw (new(ctx) NullPointerException(ConstStr::getCNST_STR_309(), ctx));
	}
	__GC_MV(this, &(this->_pattern), pattern, Pattern);
	RE2* re2 = pattern->re2(ctx);
	_groupCount = re2->numberOfCapturingGroups(ctx);
	__GC_MV(this, &(groups), ArrayAllocatorPrimitive<int>::allocatep(ctx, 2 + 2 * _groupCount), IArrayObjectPrimitive<int>);
}
void Matcher::__construct_impl(Pattern* pattern, ThreadContext* ctx) throw() 
{
	if(pattern == nullptr)
	{
		throw (new(ctx) NullPointerException(ConstStr::getCNST_STR_309(), ctx));
	}
	__GC_MV(this, &(this->_pattern), pattern, Pattern);
	RE2* re2 = pattern->re2(ctx);
	_groupCount = re2->numberOfCapturingGroups(ctx);
	__GC_MV(this, &(groups), ArrayAllocatorPrimitive<int>::allocatep(ctx, 2 + 2 * _groupCount), IArrayObjectPrimitive<int>);
}
 Matcher::Matcher(Pattern* pattern, CharSequence* input, ThreadContext* ctx) throw()  : IObject(ctx), _pattern(nullptr), groups(nullptr), _groupCount(0), inputSequence(nullptr), _inputLength(0), appendPos(0), hasMatch(0), hasGroups(0), anchorFlag(0)
{
	__construct_impl(pattern, ctx);
	reset(input, ctx);
}
void Matcher::__construct_impl(Pattern* pattern, CharSequence* input, ThreadContext* ctx) throw() 
{
	__construct_impl(pattern, ctx);
	reset(input, ctx);
}
 Matcher::~Matcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Matcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Matcher", L"~Matcher");
	__e_obj1.add(this->_pattern, this);
	_pattern = nullptr;
	__e_obj1.add(this->groups, this);
	groups = nullptr;
	__e_obj1.add(this->inputSequence, this);
	inputSequence = nullptr;
	if(!prepare){
		return;
	}
}
Pattern* Matcher::pattern(ThreadContext* ctx) throw() 
{
	return _pattern;
}
Matcher* Matcher::reset(ThreadContext* ctx) throw() 
{
	appendPos = 0;
	hasMatch = false;
	hasGroups = false;
	return this;
}
Matcher* Matcher::reset(CharSequence* input, ThreadContext* ctx) throw() 
{
	if(input == nullptr)
	{
		throw (new(ctx) NullPointerException(ConstStr::getCNST_STR_310(), ctx));
	}
	reset(ctx);
	__GC_MV(this, &(inputSequence), input, CharSequence);
	_inputLength = input->length(ctx);
	return this;
}
int Matcher::start(ThreadContext* ctx) throw() 
{
	return start(0, ctx);
}
int Matcher::end(ThreadContext* ctx) throw() 
{
	return end(0, ctx);
}
int Matcher::start(int group, ThreadContext* ctx) throw() 
{
	loadGroup(group, ctx);
	return groups->get(2 * group);
}
int Matcher::end(int group, ThreadContext* ctx) throw() 
{
	loadGroup(group, ctx);
	return groups->get(2 * group + 1);
}
String* Matcher::group(ThreadContext* ctx) throw() 
{
	return group(0, ctx);
}
String* Matcher::group(int group, ThreadContext* ctx) throw() 
{
	int _start = start(group, ctx);
	int _end = end(group, ctx);
	if(_start < 0 && _end < 0)
	{
		return nullptr;
	}
	return substring(_start, _end, ctx);
}
int Matcher::groupCount(ThreadContext* ctx) throw() 
{
	return _groupCount;
}
bool Matcher::matches(ThreadContext* ctx) throw() 
{
	return genMatch(0, RE2::ANCHOR_BOTH, ctx);
}
bool Matcher::lookingAt(ThreadContext* ctx) throw() 
{
	return genMatch(0, RE2::ANCHOR_START, ctx);
}
bool Matcher::find(ThreadContext* ctx) throw() 
{
	int start = 0;
	if(hasMatch)
	{
		start = groups->get(1);
		if(groups->get(0) == groups->get(1))
		{
			start ++ ;
		}
	}
	return genMatch(start, RE2::UNANCHORED, ctx);
}
bool Matcher::find(int start, ThreadContext* ctx) throw() 
{
	if(start < 0 || start > _inputLength)
	{
		throw (new(ctx) IndexOutOfBoundsException(ConstStr::getCNST_STR_314()->clone(ctx)->append(start, ctx), ctx));
	}
	reset(ctx);
	return genMatch(start, 0, ctx);
}
Matcher* Matcher::appendReplacement(StringBuffer* sb, String* replacement, ThreadContext* ctx) throw() 
{
	int s = start(ctx);
	int e = end(ctx);
	if(appendPos < s)
	{
		sb->append(substring(appendPos, s, ctx), ctx);
	}
	appendPos = e;
	int last = 0;
	int i = 0;
	int m = replacement->length(ctx);
	for(; i < m - 1; i ++ )
	{
		if(replacement->charAt(i, ctx) == L'\\')
		{
			if(last < i)
			{
				sb->append(replacement->substring(last, i, ctx), ctx);
			}
			i ++ ;
			last = i;
			continue;
		}
		if(replacement->charAt(i, ctx) == L'$')
		{
			int c = replacement->charAt(i + 1, ctx);
			if(L'0' <= (wchar_t)c && c <= (int)L'9')
			{
				int n = c - L'0';
				if(last < i)
				{
					sb->append(replacement->substring(last, i, ctx), ctx);
				}
				for(i += 2; i < m; i ++ )
				{
					c = replacement->charAt(i, ctx);
					if(c < (int)L'0' || c > (int)L'9' || n * 10 + c - L'0' > _groupCount)
					{
						break ;
					}
					n = n * 10 + c - L'0';
				}
				if(n > _groupCount)
				{
					throw (new(ctx) IndexOutOfBoundsException(ConstStr::getCNST_STR_315()->clone(ctx)->append(n, ctx), ctx));
				}
				String* _group = group(n, ctx);
				if(_group != nullptr)
				{
					sb->append(_group, ctx);
				}
				last = i;
				i -- ;
				continue;
			}
		}
	}
	if(last < m)
	{
		sb->append(replacement->substring(last, m, ctx), ctx);
	}
	return this;
}
StringBuffer* Matcher::appendTail(StringBuffer* sb, ThreadContext* ctx) throw() 
{
	sb->append(substring(appendPos, _inputLength, ctx), ctx);
	return sb;
}
String* Matcher::replaceAll(String* replacement, ThreadContext* ctx) throw() 
{
	return replace(replacement, true, ctx);
}
String* Matcher::replaceFirst(String* replacement, ThreadContext* ctx) throw() 
{
	return replace(replacement, false, ctx);
}
String* Matcher::substring(int start, int end, ThreadContext* ctx) throw() 
{
	return inputSequence->subSequence(start, end, ctx)->toString(ctx);
}
int Matcher::inputLength(ThreadContext* ctx) throw() 
{
	return _inputLength;
}
void Matcher::loadGroup(int group, ThreadContext* ctx) throw() 
{
	if(group < 0 || group > _groupCount)
	{
		throw (new(ctx) IndexOutOfBoundsException(ConstStr::getCNST_STR_311()->clone(ctx)->append(group, ctx), ctx));
	}
	if(!hasMatch)
	{
		throw (new(ctx) IllegalStateException(ConstStr::getCNST_STR_312(), ctx));
	}
	if(group == 0 || hasGroups)
	{
		return;
	}
	int end = groups->get(1) + 1;
	if(end > _inputLength)
	{
		end = _inputLength;
	}
	bool ok = _pattern->re2(ctx)->match(inputSequence, groups->get(0), end, anchorFlag, groups, 1 + _groupCount, ctx);
	if(!ok)
	{
		throw (new(ctx) IllegalStateException(ConstStr::getCNST_STR_313(), ctx));
	}
	hasGroups = true;
}
bool Matcher::genMatch(int startByte, int anchor, ThreadContext* ctx) throw() 
{
	bool ok = _pattern->re2(ctx)->match(inputSequence, startByte, _inputLength, anchor, groups, 1, ctx);
	if(!ok)
	{
		return false;
	}
	hasMatch = true;
	hasGroups = false;
	anchorFlag = anchor;
	return true;
}
String* Matcher::replace(String* replacement, bool all, ThreadContext* ctx) throw() 
{
	reset(ctx);
	StringBuffer* sb = (new(ctx) StringBuffer(ctx));
	while(find(ctx))
	{
		appendReplacement(sb, replacement, ctx);
		if(!all)
		{
			break ;
		}
	}
	appendTail(sb, ctx);
	return sb->toString(ctx);
}
}}}

