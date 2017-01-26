#include "includes.h"


namespace alinous {namespace parser {namespace xpath {





const StaticArrayObjectPrimitive<long long> AlinousXpathParserTokenManager::__jjnextStates = {3, 4, 5};
IArrayObjectPrimitive<long long>* AlinousXpathParserTokenManager::jjnextStates = (IArrayObjectPrimitive<long long>*)const_cast<StaticArrayObjectPrimitive<long long>*>(&__jjnextStates);
const StaticArrayObject<UnicodeStringWrapper> AlinousXpathParserTokenManager::__jjstrLiteralImages = {ConstStr::getCNST_STR_4(), (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, ConstStr::getCNST_STR_1534(), ConstStr::getCNST_STR_1535(), ConstStr::getCNST_STR_1536(), ConstStr::getCNST_STR_1537(), ConstStr::getCNST_STR_1538(), ConstStr::getCNST_STR_1539(), ConstStr::getCNST_STR_1540(), ConstStr::getCNST_STR_1541(), ConstStr::getCNST_STR_1542(), ConstStr::getCNST_STR_1543(), ConstStr::getCNST_STR_1544(), ConstStr::getCNST_STR_1545(), ConstStr::getCNST_STR_1546(), ConstStr::getCNST_STR_1547(), ConstStr::getCNST_STR_1548(), ConstStr::getCNST_STR_1549(), ConstStr::getCNST_STR_1550(), ConstStr::getCNST_STR_1551(), ConstStr::getCNST_STR_1552(), ConstStr::getCNST_STR_1553(), ConstStr::getCNST_STR_1629(), ConstStr::getCNST_STR_1554(), ConstStr::getCNST_STR_1555(), ConstStr::getCNST_STR_1556(), ConstStr::getCNST_STR_1557(), ConstStr::getCNST_STR_1558(), ConstStr::getCNST_STR_1559(), ConstStr::getCNST_STR_1560(), ConstStr::getCNST_STR_1561(), ConstStr::getCNST_STR_1562(), ConstStr::getCNST_STR_1563(), ConstStr::getCNST_STR_1564(), ConstStr::getCNST_STR_1565(), (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr, (UnicodeStringWrapper*)nullptr};
IArrayObject<String>* AlinousXpathParserTokenManager::jjstrLiteralImages = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__jjstrLiteralImages);
const StaticArrayObject<UnicodeStringWrapper> AlinousXpathParserTokenManager::__lexStateNames = {ConstStr::getCNST_STR_1630(), ConstStr::getCNST_STR_1782(), ConstStr::getCNST_STR_1783()};
IArrayObject<String>* AlinousXpathParserTokenManager::lexStateNames = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__lexStateNames);
const StaticArrayObjectPrimitive<long long> AlinousXpathParserTokenManager::__jjnewLexState = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, 1, 0, -1, -1, -1, 0, -1, -1, -1, -1};
IArrayObjectPrimitive<long long>* AlinousXpathParserTokenManager::jjnewLexState = (IArrayObjectPrimitive<long long>*)const_cast<StaticArrayObjectPrimitive<long long>*>(&__jjnewLexState);
const StaticArrayObjectPrimitive<long long> AlinousXpathParserTokenManager::__jjtoToken = {0x44fffffffffe01L};
IArrayObjectPrimitive<long long>* AlinousXpathParserTokenManager::jjtoToken = (IArrayObjectPrimitive<long long>*)const_cast<StaticArrayObjectPrimitive<long long>*>(&__jjtoToken);
const StaticArrayObjectPrimitive<long long> AlinousXpathParserTokenManager::__jjtoSkip = {0x1eL};
IArrayObjectPrimitive<long long>* AlinousXpathParserTokenManager::jjtoSkip = (IArrayObjectPrimitive<long long>*)const_cast<StaticArrayObjectPrimitive<long long>*>(&__jjtoSkip);
const StaticArrayObjectPrimitive<long long> AlinousXpathParserTokenManager::__jjtoMore = {0x7bb000000000000L};
IArrayObjectPrimitive<long long>* AlinousXpathParserTokenManager::jjtoMore = (IArrayObjectPrimitive<long long>*)const_cast<StaticArrayObjectPrimitive<long long>*>(&__jjtoMore);
bool AlinousXpathParserTokenManager::__init_done = __init_static_variables();
bool AlinousXpathParserTokenManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousXpathParserTokenManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousXpathParserTokenManager::AlinousXpathParserTokenManager(JavaCharStream* stream, ThreadContext* ctx) : IObject(ctx), AlinousXpathParserConstants(ctx), debugStream(__GC_INS(this, System::out, java::io::PrintStream)), curLexState(0), defaultLexState(0), jjnewStateCnt(0), jjround(0), jjmatchedPos(0), jjmatchedKind(0), input_stream(nullptr), curChar(0), jjrounds(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 9), ctx)), IArrayObjectPrimitive<long long>)), jjstateSet(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 2 * 9), ctx)), IArrayObjectPrimitive<long long>)), jjimage(__GC_INS(this, (new(ctx) StringBuilder(ctx)), StringBuilder)), image(__GC_INS(this, jjimage, StringBuilder)), jjimageLen(0), lengthOfMatch(0)
{
	if(JavaCharStream::staticFlag)
	{
		throw (new(ctx) Error(ConstStr::getCNST_STR_1531(), ctx));
	}
	__GC_MV(this, &(input_stream), stream, JavaCharStream);
}
void AlinousXpathParserTokenManager::__construct_impl(JavaCharStream* stream, ThreadContext* ctx)
{
	if(JavaCharStream::staticFlag)
	{
		throw (new(ctx) Error(ConstStr::getCNST_STR_1531(), ctx));
	}
	__GC_MV(this, &(input_stream), stream, JavaCharStream);
}
 AlinousXpathParserTokenManager::AlinousXpathParserTokenManager(JavaCharStream* stream, long long lexState, ThreadContext* ctx) : IObject(ctx), AlinousXpathParserConstants(ctx), debugStream(__GC_INS(this, System::out, java::io::PrintStream)), curLexState(0), defaultLexState(0), jjnewStateCnt(0), jjround(0), jjmatchedPos(0), jjmatchedKind(0), input_stream(nullptr), curChar(0), jjrounds(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 9), ctx)), IArrayObjectPrimitive<long long>)), jjstateSet(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 2 * 9), ctx)), IArrayObjectPrimitive<long long>)), jjimage(__GC_INS(this, (new(ctx) StringBuilder(ctx)), StringBuilder)), image(__GC_INS(this, jjimage, StringBuilder)), jjimageLen(0), lengthOfMatch(0)
{
	ReInit(stream, ctx);
	SwitchTo(lexState, ctx);
}
void AlinousXpathParserTokenManager::__construct_impl(JavaCharStream* stream, long long lexState, ThreadContext* ctx)
{
	ReInit(stream, ctx);
	SwitchTo(lexState, ctx);
}
 AlinousXpathParserTokenManager::~AlinousXpathParserTokenManager()
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousXpathParserTokenManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousXpathParserTokenManager", L"~AlinousXpathParserTokenManager");
	__e_obj1.add(this->debugStream, this);
	debugStream = nullptr;
	__e_obj1.add(this->input_stream, this);
	input_stream = nullptr;
	__e_obj1.add(this->jjrounds, this);
	jjrounds = nullptr;
	__e_obj1.add(this->jjstateSet, this);
	jjstateSet = nullptr;
	__e_obj1.add(this->jjimage, this);
	jjimage = nullptr;
	__e_obj1.add(this->image, this);
	image = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousXpathParserTokenManager::setDebugStream(java::io::PrintStream* ds, ThreadContext* ctx)
{
	__GC_MV(this, &(debugStream), ds, java::io::PrintStream);
}
Token* AlinousXpathParserTokenManager::getNextToken(ThreadContext* ctx)
{
	Token* matchedToken = 0;
	long long curPos = 0;
	for(; ; )
	{
		EOFLoop_continue:
		{
			try
			{
				curChar = input_stream->BeginToken(ctx);
			}
			catch(java::io::IOException* e)
			{
				jjmatchedKind = 0;
				jjmatchedPos = -1;
				matchedToken = jjFillToken(ctx);
				return matchedToken;
			}
		}
		__GC_MV(this, &(image), jjimage, StringBuilder);
		image->setLength(0, ctx);
		jjimageLen = 0;
		for(; ; )
		{
			switch(curLexState) {
			case 0:
				jjmatchedKind = 0x7fffffff;
				jjmatchedPos = 0;
				curPos = jjMoveStringLiteralDfa0_0(ctx);
				break ;
			case 1:
				jjmatchedKind = 0x7fffffff;
				jjmatchedPos = 0;
				curPos = jjMoveStringLiteralDfa0_1(ctx);
				if(jjmatchedPos == (long long)0 && jjmatchedKind > (long long)58)
				{
					jjmatchedKind = 58;
				}
				break ;
			case 2:
				jjmatchedKind = 0x7fffffff;
				jjmatchedPos = 0;
				curPos = jjMoveStringLiteralDfa0_2(ctx);
				if(jjmatchedPos == (long long)0 && jjmatchedKind > (long long)53)
				{
					jjmatchedKind = 53;
				}
				break ;
			}
			if(jjmatchedKind != (long long)0x7fffffff)
			{
				if(jjmatchedPos + 1 < curPos)
				{
					input_stream->backup((int)curPos - jjmatchedPos - 1, ctx);
				}
				if((jjtoToken->get(jjmatchedKind >> 6) & (1L << (jjmatchedKind & 077))) != (long long)0L)
				{
					matchedToken = jjFillToken(ctx);
					TokenLexicalActions(matchedToken, ctx);
					if(jjnewLexState->get(jjmatchedKind) != (long long)-1)
					{
						curLexState = jjnewLexState->get(jjmatchedKind);
					}
					return matchedToken;
				}
								else 
				{
					if((jjtoSkip->get(jjmatchedKind >> 6) & (1L << (jjmatchedKind & 077))) != (long long)0L)
					{
						if(jjnewLexState->get(jjmatchedKind) != (long long)-1)
						{
							curLexState = jjnewLexState->get(jjmatchedKind);
						}
						goto EOFLoop_continue;
					}
				}
				jjimageLen += jjmatchedPos + 1;
				if(jjnewLexState->get(jjmatchedKind) != (long long)-1)
				{
					curLexState = jjnewLexState->get(jjmatchedKind);
				}
				curPos = 0;
				jjmatchedKind = 0x7fffffff;
				{
					try
					{
						curChar = input_stream->readChar(ctx);
						continue;
					}
					catch(java::io::IOException* e1)
					{
					}
				}
			}
			long long error_line = input_stream->getEndLine(ctx);
			long long error_column = input_stream->getEndColumn(ctx);
			String* error_after = nullptr;
			bool EOFSeen = false;
			{
				try
				{
					input_stream->readChar(ctx);
					input_stream->backup(1, ctx);
				}
				catch(java::io::IOException* e1)
				{
					EOFSeen = true;
					error_after = curPos <= (long long)1 ? ConstStr::getCNST_STR_4() : input_stream->GetImage(ctx);
					if(curChar == L'\n' || curChar == L'\r')
					{
						error_line ++ ;
						error_column = 0;
					}
										else 
					{
						error_column ++ ;
					}
				}
			}
			if(!EOFSeen)
			{
				input_stream->backup(1, ctx);
				error_after = curPos <= (long long)1 ? ConstStr::getCNST_STR_4() : input_stream->GetImage(ctx);
			}
			throw (new(ctx) TokenMgrError(EOFSeen, curLexState, error_line, error_column, error_after, curChar, TokenMgrError::LEXICAL_ERROR, ctx));
		}
	}
}
void AlinousXpathParserTokenManager::ReInit(JavaCharStream* stream, ThreadContext* ctx)
{
	jjmatchedPos = jjnewStateCnt = 0;
	curLexState = defaultLexState;
	__GC_MV(this, &(input_stream), stream, JavaCharStream);
	ReInitRounds(ctx);
}
void AlinousXpathParserTokenManager::ReInit(JavaCharStream* stream, long long lexState, ThreadContext* ctx)
{
	ReInit(stream, ctx);
	SwitchTo(lexState, ctx);
}
void AlinousXpathParserTokenManager::SwitchTo(long long lexState, ThreadContext* ctx)
{
	if(lexState >= (long long)3 || lexState < (long long)0)
	{
		throw (new(ctx) TokenMgrError(ConstStr::getCNST_STR_1532()->clone(ctx)->append(lexState, ctx)->append(ConstStr::getCNST_STR_1533(), ctx), TokenMgrError::INVALID_LEXICAL_STATE, ctx));
	}
		else 
	{
		curLexState = lexState;
	}
}
Token* AlinousXpathParserTokenManager::jjFillToken(ThreadContext* ctx)
{
	Token* t = 0;
	String* curTokenImage = 0;
	long long beginLine = 0;
	long long endLine = 0;
	long long beginColumn = 0;
	long long endColumn = 0;
	String* im = jjstrLiteralImages->get(jjmatchedKind);
	curTokenImage = (im == nullptr) ? input_stream->GetImage(ctx) : im;
	beginLine = input_stream->getBeginLine(ctx);
	beginColumn = input_stream->getBeginColumn(ctx);
	endLine = input_stream->getEndLine(ctx);
	endColumn = input_stream->getEndColumn(ctx);
	t = Token::newToken((int)jjmatchedKind, curTokenImage, ctx);
	t->beginLine = beginLine;
	t->endLine = endLine;
	t->beginColumn = beginColumn;
	t->endColumn = endColumn;
	return t;
}
void AlinousXpathParserTokenManager::TokenLexicalActions(Token* matchedToken, ThreadContext* ctx)
{
	switch(jjmatchedKind) {
	case 50:
		lengthOfMatch = jjmatchedPos + 1;
		image->append(input_stream->GetSuffix((int)jjimageLen + (lengthOfMatch), ctx), ctx);
		__GC_MV(matchedToken, &(matchedToken->image), image->substring(1, image->length(ctx) - 1, ctx), String);
		break ;
	case 54:
		{
		lengthOfMatch = jjmatchedPos + 1;
		image->append(input_stream->GetSuffix((int)jjimageLen + (lengthOfMatch), ctx), ctx);
		String* img = image->substring(1, image->length(ctx) - 1, ctx);
		__GC_MV(matchedToken, &(matchedToken->image), img->replaceAll(ConstStr::getCNST_STR_1781(), ConstStr::getCNST_STR_1741(), ctx), String);
		break ;
		}
	default:
		break ;
	}
}
long long AlinousXpathParserTokenManager::jjStopAtPos(long long pos, long long kind, ThreadContext* ctx)
{
	jjmatchedKind = kind;
	jjmatchedPos = pos;
	return pos + 1;
}
long long AlinousXpathParserTokenManager::jjMoveStringLiteralDfa0_0(ThreadContext* ctx)
{
	switch(curChar) {
	case 9:
		jjmatchedKind = 2;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 10:
		jjmatchedKind = 3;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 13:
		jjmatchedKind = 4;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 32:
		jjmatchedKind = 1;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 33:
		jjmatchedKind = 40;
		return jjMoveStringLiteralDfa1_0((long long)0x800000000L, ctx);
	case 34:
		jjmatchedKind = 48;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 36:
		jjmatchedKind = 26;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 37:
		jjmatchedKind = 17;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 38:
		jjmatchedKind = 20;
		return jjMoveStringLiteralDfa1_0((long long)0x40000L, ctx);
	case 39:
		jjmatchedKind = 49;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 40:
		jjmatchedKind = 22;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 41:
		jjmatchedKind = 23;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 42:
		jjmatchedKind = 11;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 43:
		jjmatchedKind = 13;
		return jjMoveStringLiteralDfa1_0((long long)0x1000L, ctx);
	case 44:
		jjmatchedKind = 28;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 45:
		jjmatchedKind = 15;
		return jjMoveStringLiteralDfa1_0((long long)0x4000L, ctx);
	case 46:
		jjmatchedKind = 27;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 47:
		jjmatchedKind = 16;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 58:
		jjmatchedKind = 41;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 59:
		jjmatchedKind = 9;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 60:
		jjmatchedKind = 38;
		return jjMoveStringLiteralDfa1_0((long long)0x8020000000L, ctx);
	case 61:
		jjmatchedKind = 10;
		return jjMoveStringLiteralDfa1_0((long long)0x400000000L, ctx);
	case 62:
		jjmatchedKind = 36;
		return jjMoveStringLiteralDfa1_0((long long)0x2000000000L, ctx);
	case 64:
		jjmatchedKind = 31;
		return jjMoveStringLiteralDfa1_0((long long)0x40000000L, ctx);
	case 65:
		return jjMoveStringLiteralDfa1_0((long long)0x40000000000L, ctx);
	case 78:
		return jjMoveStringLiteralDfa1_0((long long)0x100000000000L, ctx);
	case 79:
		return jjMoveStringLiteralDfa1_0((long long)0x80000000000L, ctx);
	case 91:
		jjmatchedKind = 24;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 93:
		jjmatchedKind = 25;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 97:
		return jjMoveStringLiteralDfa1_0((long long)0x40000000000L, ctx);
	case 110:
		return jjMoveStringLiteralDfa1_0((long long)0x100000000000L, ctx);
	case 111:
		return jjMoveStringLiteralDfa1_0((long long)0x80000000000L, ctx);
	case 123:
		jjmatchedKind = 32;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	case 124:
		jjmatchedKind = 21;
		return jjMoveStringLiteralDfa1_0((long long)0x80000L, ctx);
	case 125:
		jjmatchedKind = 33;
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
	default:
		return jjMoveNfa_0((long long)0, (long long)0, ctx);
		break;
	}
}
long long AlinousXpathParserTokenManager::jjMoveStringLiteralDfa1_0(long long active0, ThreadContext* ctx)
{
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)0, ctx);
		}
	}
	switch(curChar) {
	case 38:
		if((active0 & 0x40000L) != (long long)0L)
		{
			jjmatchedKind = 18;
			jjmatchedPos = 1;
		}
		break ;
	case 43:
		if((active0 & 0x1000L) != (long long)0L)
		{
			jjmatchedKind = 12;
			jjmatchedPos = 1;
		}
		break ;
	case 45:
		if((active0 & 0x4000L) != (long long)0L)
		{
			jjmatchedKind = 14;
			jjmatchedPos = 1;
		}
		break ;
	case 61:
		if((active0 & 0x400000000L) != (long long)0L)
		{
			jjmatchedKind = 34;
			jjmatchedPos = 1;
		}
				else 
		{
			if((active0 & 0x800000000L) != (long long)0L)
			{
				jjmatchedKind = 35;
				jjmatchedPos = 1;
			}
						else 
			{
				if((active0 & 0x2000000000L) != (long long)0L)
				{
					jjmatchedKind = 37;
					jjmatchedPos = 1;
				}
								else 
				{
					if((active0 & 0x8000000000L) != (long long)0L)
					{
						jjmatchedKind = 39;
						jjmatchedPos = 1;
					}
				}
			}
		}
		break ;
	case 62:
		if((active0 & 0x20000000L) != (long long)0L)
		{
			jjmatchedKind = 29;
			jjmatchedPos = 1;
		}
		break ;
	case 64:
		if((active0 & 0x40000000L) != (long long)0L)
		{
			jjmatchedKind = 30;
			jjmatchedPos = 1;
		}
		break ;
	case 78:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x40000000000L, ctx);
	case 79:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x100000000000L, ctx);
	case 82:
		if((active0 & 0x80000000000L) != (long long)0L)
		{
			jjmatchedKind = 43;
			jjmatchedPos = 1;
		}
		break ;
	case 110:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x40000000000L, ctx);
	case 111:
		return jjMoveStringLiteralDfa2_0(active0, (long long)0x100000000000L, ctx);
	case 114:
		if((active0 & 0x80000000000L) != (long long)0L)
		{
			jjmatchedKind = 43;
			jjmatchedPos = 1;
		}
		break ;
	case 124:
		if((active0 & 0x80000L) != (long long)0L)
		{
			jjmatchedKind = 19;
			jjmatchedPos = 1;
		}
		break ;
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)1, ctx);
}
long long AlinousXpathParserTokenManager::jjMoveStringLiteralDfa2_0(long long old0, long long active0, ThreadContext* ctx)
{
	active0 = active0 & (old0);
	if(((active0)) == (long long)0L)
	{
		return jjMoveNfa_0((long long)0, (long long)1, ctx);
	}
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return jjMoveNfa_0((long long)0, (long long)1, ctx);
		}
	}
	switch(curChar) {
	case 68:
		if((active0 & 0x40000000000L) != (long long)0L)
		{
			jjmatchedKind = 42;
			jjmatchedPos = 2;
		}
		break ;
	case 84:
		if((active0 & 0x100000000000L) != (long long)0L)
		{
			jjmatchedKind = 44;
			jjmatchedPos = 2;
		}
		break ;
	case 100:
		if((active0 & 0x40000000000L) != (long long)0L)
		{
			jjmatchedKind = 42;
			jjmatchedPos = 2;
		}
		break ;
	case 116:
		if((active0 & 0x100000000000L) != (long long)0L)
		{
			jjmatchedKind = 44;
			jjmatchedPos = 2;
		}
		break ;
	default:
		break ;
	}
	return jjMoveNfa_0((long long)0, (long long)2, ctx);
}
long long AlinousXpathParserTokenManager::jjMoveNfa_0(long long startState, long long curPos, ThreadContext* ctx)
{
	long long strKind = jjmatchedKind;
	long long strPos = jjmatchedPos;
	long long seenUpto = 0;
	seenUpto = curPos + 1;
	input_stream->backup((int)seenUpto, ctx);
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			throw (new(ctx) Error(ConstStr::getCNST_STR_1529(), ctx));
		}
	}
	curPos = 0;
	long long startsAt = 0;
	jjnewStateCnt = 9;
	long long i = 1;
	jjstateSet->set(startState,0, ctx);
	long long kind = 0x7fffffff;
	for(; ; )
	{
		if(++jjround == (long long)0x7fffffff)
		{
			ReInitRounds(ctx);
		}
		if(curChar < (wchar_t)64)
		{
			long long l = 1L << curChar;
			do
			{
				switch(jjstateSet->get(--i)) {
				case 0:
					if((0x3ff000000000000L & l) != 0L)
					{
						if(kind > (long long)46)
						{
							kind = 46;
						}
						{
							jjCheckNAddStates((long long)0, (long long)2, ctx);
						}
					}
										else 
					{
						if(curChar == (wchar_t)45)
						{
							jjCheckNAddTwoStates((long long)3, (long long)4, ctx);
						}
					}
					break ;
				case 1:
					if((0x3ff200000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)45)
					{
						kind = 45;
					}
					jjstateSet->set(1,jjnewStateCnt++, ctx);
					break ;
				case 2:
					if(curChar == (wchar_t)45)
					{
						jjCheckNAddTwoStates((long long)3, (long long)4, ctx);
					}
					break ;
				case 3:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)46)
					{
						kind = 46;
					}
					{
						jjCheckNAdd((long long)3, ctx);
					}
					break ;
				case 4:
					if((0x3ff000000000000L & l) != 0L)
					{
						jjCheckNAddTwoStates((long long)4, (long long)5, ctx);
					}
					break ;
				case 5:
					if(curChar == (wchar_t)46)
					{
						jjCheckNAddTwoStates((long long)6, (long long)7, ctx);
					}
					break ;
				case 6:
					if(curChar == (wchar_t)45)
					{
						jjCheckNAdd((long long)7, ctx);
					}
					break ;
				case 7:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)47)
					{
						kind = 47;
					}
					{
						jjCheckNAdd((long long)7, ctx);
					}
					break ;
				case 8:
					if((0x3ff000000000000L & l) == 0L)
					{
						break ;
					}
					if(kind > (long long)46)
					{
						kind = 46;
					}
					{
						jjCheckNAddStates((long long)0, (long long)2, ctx);
					}
					break ;
				default:
					break ;
				}
			}
			while(i != startsAt);
		}
				else 
		{
			if(curChar < (wchar_t)128)
			{
				long long l = 1L << (curChar & 077);
				do
				{
					switch(jjstateSet->get(--i)) {
					case 0:
					case 1:
						if((0x7fffffe87fffffeL & l) == 0L)
						{
							break ;
						}
						if(kind > (long long)45)
						{
							kind = 45;
						}
						{
							jjCheckNAdd((long long)1, ctx);
						}
						break ;
					default:
						break ;
					}
				}
				while(i != startsAt);
			}
						else 
			{
				long long hiByte = (curChar >> 8);
				long long i1 = hiByte >> 6;
				long long l1 = 1L << (hiByte & 077);
				long long i2 = (curChar & 0xff) >> 6;
				long long l2 = 1L << (curChar & 077);
				do
				{
					switch(jjstateSet->get(--i)) {
					default:
						if(i1 == (long long)0 || l1 == (long long)0 || i2 == (long long)0 || l2 == (long long)0)
						{
							break ;
						}
												else 
						{
							break ;
						}
						break;
					}
				}
				while(i != startsAt);
			}
		}
		if(kind != (long long)0x7fffffff)
		{
			jjmatchedKind = kind;
			jjmatchedPos = curPos;
			kind = 0x7fffffff;
		}
		++curPos;
		i = jjnewStateCnt;
		startsAt = 9 - (jjnewStateCnt = startsAt);
		if((i) == (startsAt))
		{
			break ;
		}
		{
			try
			{
				curChar = input_stream->readChar(ctx);
			}
			catch(java::io::IOException* e)
			{
				break ;
			}
		}
	}
	if(jjmatchedPos > strPos)
	{
		return curPos;
	}
	long long toRet = Math::max(curPos, seenUpto, ctx);
	if(curPos < toRet)
	{
		for(i = toRet - Math::min(curPos, seenUpto, ctx); i-- > (long long)0; )
		{
			try
			{
				curChar = input_stream->readChar(ctx);
			}
			catch(java::io::IOException* e)
			{
				throw (new(ctx) Error(ConstStr::getCNST_STR_1530(), ctx));
			}
		}
	}
	if(jjmatchedPos < strPos)
	{
		jjmatchedKind = strKind;
		jjmatchedPos = strPos;
	}
		else 
	{
		if(jjmatchedPos == strPos && jjmatchedKind > strKind)
		{
			jjmatchedKind = strKind;
		}
	}
	return toRet;
}
long long AlinousXpathParserTokenManager::jjMoveStringLiteralDfa0_1(ThreadContext* ctx)
{
	switch(curChar) {
	case 39:
		jjmatchedKind = 54;
		return jjMoveStringLiteralDfa1_1((long long)0x80000000000000L, ctx);
	case 92:
		return jjMoveStringLiteralDfa1_1((long long)0x300000000000000L, ctx);
	default:
		return 1;
		break;
	}
}
long long AlinousXpathParserTokenManager::jjMoveStringLiteralDfa1_1(long long active0, ThreadContext* ctx)
{
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return 1;
		}
	}
	switch(curChar) {
	case 39:
		if((active0 & 0x80000000000000L) != (long long)0L)
		{
			return jjStopAtPos((long long)1, (long long)55, ctx);
		}
				else 
		{
			if((active0 & 0x200000000000000L) != (long long)0L)
			{
				return jjStopAtPos((long long)1, (long long)57, ctx);
			}
		}
		break ;
	case 92:
		if((active0 & 0x100000000000000L) != (long long)0L)
		{
			return jjStopAtPos((long long)1, (long long)56, ctx);
		}
		break ;
	default:
		return 2;
		break;
	}
	return 2;
}
long long AlinousXpathParserTokenManager::jjMoveStringLiteralDfa0_2(ThreadContext* ctx)
{
	switch(curChar) {
	case 34:
		return jjStopAtPos((long long)0, (long long)50, ctx);
	case 92:
		return jjMoveStringLiteralDfa1_2((long long)0x18000000000000L, ctx);
	default:
		return 1;
		break;
	}
}
long long AlinousXpathParserTokenManager::jjMoveStringLiteralDfa1_2(long long active0, ThreadContext* ctx)
{
	{
		try
		{
			curChar = input_stream->readChar(ctx);
		}
		catch(java::io::IOException* e)
		{
			return 1;
		}
	}
	switch(curChar) {
	case 34:
		if((active0 & 0x10000000000000L) != (long long)0L)
		{
			return jjStopAtPos((long long)1, (long long)52, ctx);
		}
		break ;
	case 92:
		if((active0 & 0x8000000000000L) != (long long)0L)
		{
			return jjStopAtPos((long long)1, (long long)51, ctx);
		}
		break ;
	default:
		return 2;
		break;
	}
	return 2;
}
void AlinousXpathParserTokenManager::jjCheckNAdd(long long state, ThreadContext* ctx)
{
	if(jjrounds->get(state) != jjround)
	{
		jjstateSet->set(state,jjnewStateCnt++, ctx);
		jjrounds->set(jjround,state, ctx);
	}
}
void AlinousXpathParserTokenManager::jjAddStates(long long start, long long end, ThreadContext* ctx)
{
	do
	{
		jjstateSet->set(jjnextStates->get(start),jjnewStateCnt++, ctx);
	}
	while(start++ != end);
}
void AlinousXpathParserTokenManager::jjCheckNAddTwoStates(long long state1, long long state2, ThreadContext* ctx)
{
	jjCheckNAdd(state1, ctx);
	jjCheckNAdd(state2, ctx);
}
void AlinousXpathParserTokenManager::jjCheckNAddStates(long long start, long long end, ThreadContext* ctx)
{
	do
	{
		jjCheckNAdd(jjnextStates->get(start), ctx);
	}
	while(start++ != end);
}
void AlinousXpathParserTokenManager::ReInitRounds(ThreadContext* ctx)
{
	long long i = 0;
	jjround = 0x80000001;
	for(i = 9; i-- > (long long)0; )
	jjrounds->set(0x80000000,i, ctx);
}
}}}

