#include "includes.h"


namespace alinous {namespace compile {





IArrayObjectPrimitive<long long>* AlinousPlusParser::jj_la1_0 = nullptr;
IArrayObjectPrimitive<long long>* AlinousPlusParser::jj_la1_1 = nullptr;
IArrayObjectPrimitive<long long>* AlinousPlusParser::jj_la1_2 = nullptr;
IArrayObjectPrimitive<long long>* AlinousPlusParser::jj_la1_3 = nullptr;
IArrayObjectPrimitive<long long>* AlinousPlusParser::jj_la1_4 = nullptr;
IArrayObjectPrimitive<long long>* AlinousPlusParser::jj_la1_5 = nullptr;
IArrayObjectPrimitive<long long>* AlinousPlusParser::jj_la1_6 = nullptr;
bool AlinousPlusParser::__init_done = __init_static_variables();
bool AlinousPlusParser::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousPlusParser", L"__init_static_variables");
		__GC_MV(nullptr, &(jj_la1_0), nullptr, IArrayObjectPrimitive<long long>);
		__GC_MV(nullptr, &(jj_la1_1), nullptr, IArrayObjectPrimitive<long long>);
		__GC_MV(nullptr, &(jj_la1_2), nullptr, IArrayObjectPrimitive<long long>);
		__GC_MV(nullptr, &(jj_la1_3), nullptr, IArrayObjectPrimitive<long long>);
		__GC_MV(nullptr, &(jj_la1_4), nullptr, IArrayObjectPrimitive<long long>);
		__GC_MV(nullptr, &(jj_la1_5), nullptr, IArrayObjectPrimitive<long long>);
		__GC_MV(nullptr, &(jj_la1_6), nullptr, IArrayObjectPrimitive<long long>);
		{
			jj_la1_init_0(ctx);
			jj_la1_init_1(ctx);
			jj_la1_init_2(ctx);
			jj_la1_init_3(ctx);
			jj_la1_init_4(ctx);
			jj_la1_init_5(ctx);
			jj_la1_init_6(ctx);
		}
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousPlusParser::AlinousPlusParser(java::io::InputStream* stream, ThreadContext* ctx) : IObject(ctx), AlinousPlusParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 115), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 67), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) AlinousPlusParser::LookaheadSuccess(ctx)), AlinousPlusParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	__construct_impl(stream, nullptr, ctx);
}
void AlinousPlusParser::__construct_impl(java::io::InputStream* stream, ThreadContext* ctx)
{
	__construct_impl(stream, nullptr, ctx);
}
 AlinousPlusParser::AlinousPlusParser(java::io::InputStream* stream, String* encoding, ThreadContext* ctx) : IObject(ctx), AlinousPlusParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 115), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 67), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) AlinousPlusParser::LookaheadSuccess(ctx)), AlinousPlusParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	{
		try
		{
			__GC_MV(this, &(jj_input_stream), (new(ctx) JavaCharStream(stream, encoding, 1, 1, ctx)), JavaCharStream);
		}
		catch(java::io::UnsupportedEncodingException* e)
		{
			throw (new(ctx) RuntimeException(e, ctx));
		}
	}
	__GC_MV(this, &(token_source), (new(ctx) AlinousPlusParserTokenManager(jj_input_stream, ctx)), AlinousPlusParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)115; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousPlusParser::JJCalls(ctx)),i, ctx);
}
void AlinousPlusParser::__construct_impl(java::io::InputStream* stream, String* encoding, ThreadContext* ctx)
{
	{
		try
		{
			__GC_MV(this, &(jj_input_stream), (new(ctx) JavaCharStream(stream, encoding, 1, 1, ctx)), JavaCharStream);
		}
		catch(java::io::UnsupportedEncodingException* e)
		{
			throw (new(ctx) RuntimeException(e, ctx));
		}
	}
	__GC_MV(this, &(token_source), (new(ctx) AlinousPlusParserTokenManager(jj_input_stream, ctx)), AlinousPlusParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)115; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousPlusParser::JJCalls(ctx)),i, ctx);
}
 AlinousPlusParser::AlinousPlusParser(java::io::Reader* stream, ThreadContext* ctx) : IObject(ctx), AlinousPlusParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 115), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 67), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) AlinousPlusParser::LookaheadSuccess(ctx)), AlinousPlusParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	__GC_MV(this, &(jj_input_stream), (new(ctx) JavaCharStream(stream, 1, 1, ctx)), JavaCharStream);
	__GC_MV(this, &(token_source), (new(ctx) AlinousPlusParserTokenManager(jj_input_stream, ctx)), AlinousPlusParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)115; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousPlusParser::JJCalls(ctx)),i, ctx);
}
void AlinousPlusParser::__construct_impl(java::io::Reader* stream, ThreadContext* ctx)
{
	__GC_MV(this, &(jj_input_stream), (new(ctx) JavaCharStream(stream, 1, 1, ctx)), JavaCharStream);
	__GC_MV(this, &(token_source), (new(ctx) AlinousPlusParserTokenManager(jj_input_stream, ctx)), AlinousPlusParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)115; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousPlusParser::JJCalls(ctx)),i, ctx);
}
 AlinousPlusParser::AlinousPlusParser(AlinousPlusParserTokenManager* tm, ThreadContext* ctx) : IObject(ctx), AlinousPlusParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 115), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 67), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) AlinousPlusParser::LookaheadSuccess(ctx)), AlinousPlusParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	__GC_MV(this, &(token_source), tm, AlinousPlusParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)115; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousPlusParser::JJCalls(ctx)),i, ctx);
}
void AlinousPlusParser::__construct_impl(AlinousPlusParserTokenManager* tm, ThreadContext* ctx)
{
	__GC_MV(this, &(token_source), tm, AlinousPlusParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)115; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousPlusParser::JJCalls(ctx)),i, ctx);
}
 AlinousPlusParser::~AlinousPlusParser()
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousPlusParser::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousPlusParser", L"~AlinousPlusParser");
	__e_obj1.add(this->token_source, this);
	token_source = nullptr;
	__e_obj1.add(this->token, this);
	token = nullptr;
	__e_obj1.add(this->jj_nt, this);
	jj_nt = nullptr;
	__e_obj1.add(this->jj_input_stream, this);
	jj_input_stream = nullptr;
	__e_obj1.add(this->jj_scanpos, this);
	jj_scanpos = nullptr;
	__e_obj1.add(this->jj_lastpos, this);
	jj_lastpos = nullptr;
	__e_obj1.add(this->jj_la1, this);
	jj_la1 = nullptr;
	__e_obj1.add(this->jj_2_rtns, this);
	jj_2_rtns = nullptr;
	__e_obj1.add(this->jj_ls, this);
	jj_ls = nullptr;
	__e_obj1.add(this->jj_expentries, this);
	jj_expentries = nullptr;
	__e_obj1.add(this->jj_expentry, this);
	jj_expentry = nullptr;
	__e_obj1.add(this->jj_lasttokens, this);
	jj_lasttokens = nullptr;
	if(!prepare){
		return;
	}
}
AlinousSrc* AlinousPlusParser::parse(ThreadContext* ctx)
{
	AlinousSrc* src = (new(ctx) AlinousSrc(ctx));
	StatementList* list = nullptr;
	IDeclare* dec = 0;
	headerSection(src, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case INTEGER_LITERAL:
		case FLOATING_POINT_LITERAL:
		case STRING_LITERAL:
		case CHARACTER_LITERAL:
		case SQL_STRING_LITERAL:
		case PLUSPLUS:
		case MINUSMINUS:
		case L_PARENTHESIS:
		case DOLLAR:
		case AT_MARK:
		case L_BRACE:
		case NOT:
		case CLASS:
		case CLASS_INTERFACE:
		case BREAK:
		case CONTINUE:
		case NATIVE:
		case NEW:
		case RETURN:
		case SUPER:
		case THIS:
		case VOID:
		case DOWNLOAD:
		case REDIRECT:
		case REFERER_FROM:
		case VALIDATOR:
		case LOCAL:
		case TRUE:
		case FALSE:
		case SELECT:
		case INSERT:
		case UPDATE:
		case DELETE:
		case INTO:
		case FROM:
		case WHERE:
		case OR:
		case SQLAND:
		case LIKE:
		case ESCAPE:
		case LEFT:
		case RIGHT:
		case NATURAL:
		case INNER:
		case OUTER:
		case FULL:
		case CROSS:
		case SET:
		case VALUES:
		case GROUP:
		case BY:
		case HAVING:
		case ORDER:
		case ASC:
		case DESC:
		case LIMIT:
		case OFFSET:
		case ON:
		case AS:
		case DISTINCT:
		case SHARE:
		case NOWAIT:
		case OF:
		case IN:
		case BETWEEN:
		case IS:
		case BEGIN:
		case PREPARE:
		case TRANSACTION:
		case ISOLATION:
		case LEVEL:
		case COMMIT:
		case PREPARED:
		case END:
		case ROLLBACK:
		case CREATE:
		case DROP:
		case ALTER:
		case TABLE:
		case SQL_DEFAULT:
		case ADD:
		case RENAME:
		case COLUMN:
		case TO:
		case PRIMARY:
		case KEY:
		case UNIQUE:
		case CHECK:
		case RETURNS:
		case SETOF:
		case LANGUAGE:
		case REPLACE:
		case INDEX:
		case USING:
		case EACH:
		case ROW:
		case STATEMENT:
		case EXECUTE:
		case PROCEDURE:
		case EXISTS:
		case TRIGGER:
		case BEFORE:
		case AFTER:
		case FOREIGN:
		case REFERENCES:
		case ADJUST_WHERE:
		case ADJUST_SET:
		case _NULL:
		case FUNCTION:
		case USE:
		case IDENTIFIER:
		case 196:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,0, ctx);
			goto label_1_out_break;
		}
		if(jj_2_1((long long)3, ctx))
		{
			list = statementList(ctx);
			src->addStatementList(list, ctx);
		}
				else 
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case NOT:
			case CLASS:
			case CLASS_INTERFACE:
			case NATIVE:
			case SUPER:
			case THIS:
			case VOID:
			case DOWNLOAD:
			case REDIRECT:
			case REFERER_FROM:
			case VALIDATOR:
			case LOCAL:
			case SELECT:
			case INSERT:
			case UPDATE:
			case DELETE:
			case INTO:
			case FROM:
			case WHERE:
			case OR:
			case SQLAND:
			case LIKE:
			case ESCAPE:
			case LEFT:
			case RIGHT:
			case NATURAL:
			case INNER:
			case OUTER:
			case FULL:
			case CROSS:
			case SET:
			case VALUES:
			case GROUP:
			case BY:
			case HAVING:
			case ORDER:
			case ASC:
			case DESC:
			case LIMIT:
			case OFFSET:
			case ON:
			case AS:
			case DISTINCT:
			case SHARE:
			case NOWAIT:
			case OF:
			case IN:
			case BETWEEN:
			case IS:
			case BEGIN:
			case PREPARE:
			case TRANSACTION:
			case ISOLATION:
			case LEVEL:
			case COMMIT:
			case PREPARED:
			case END:
			case ROLLBACK:
			case CREATE:
			case DROP:
			case ALTER:
			case TABLE:
			case SQL_DEFAULT:
			case ADD:
			case RENAME:
			case COLUMN:
			case TO:
			case PRIMARY:
			case KEY:
			case UNIQUE:
			case CHECK:
			case RETURNS:
			case SETOF:
			case LANGUAGE:
			case REPLACE:
			case INDEX:
			case USING:
			case EACH:
			case ROW:
			case STATEMENT:
			case EXECUTE:
			case PROCEDURE:
			case EXISTS:
			case TRIGGER:
			case BEFORE:
			case AFTER:
			case FOREIGN:
			case REFERENCES:
			case ADJUST_WHERE:
			case ADJUST_SET:
			case FUNCTION:
			case USE:
			case IDENTIFIER:
				{
					dec = alinousDeclare(ctx);
					src->addDeclare(dec, ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,1, ctx);
				jj_consume_token((long long)-1, ctx);
				throw (new(ctx) ParseException(ctx));
				break;
			}
		}
	}
	label_1_out_break: ;
	{
		{
			return src;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
void AlinousPlusParser::headerSection(AlinousSrc* src, ThreadContext* ctx)
{
	IncludePreprocessor* inc = nullptr;
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case INCLUDE:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,2, ctx);
			goto label_2_out_break;
		}
		inc = includePreprocessor(ctx);
		src->addInclude(inc, ctx);
	}
	label_2_out_break: ;
}
IncludePreprocessor* AlinousPlusParser::includePreprocessor(ThreadContext* ctx)
{
	IncludePreprocessor* inc = (new(ctx) IncludePreprocessor(ctx));
	Literal* lit = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(INCLUDE, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case L_PARENTHESIS:
		{
			jj_consume_token(L_PARENTHESIS, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,3, ctx);
		;
		break;
	}
	lit = literal(ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case R_PARENTHESIS:
		{
			jj_consume_token(R_PARENTHESIS, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,4, ctx);
		;
		break;
	}
	t2 = jj_consume_token(SEMI_COLON, ctx);
	inc->position(t, t2, ctx);
	inc->setPath(lit, ctx);
	{
		{
			return inc;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
StatementList* AlinousPlusParser::statementList(ThreadContext* ctx)
{
	StatementList* list = (new(ctx) StatementList(ctx));
	IStatement* stmt = nullptr;
	IStatement* start = nullptr;
	IStatement* end = nullptr;
	while(true)
	{
		stmt = allStatements(ctx);
		if(start == nullptr)
		{
			start = stmt;
			end = stmt;
		}
				else 
		{
			end = stmt;
		}
		list->add(stmt, ctx);
		if(jj_2_2((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_3_out_break;
		}
	}
	label_3_out_break: ;
	list->position(start, end, ctx);
	{
		{
			return list;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IStatement* AlinousPlusParser::allStatements(ThreadContext* ctx)
{
	IStatement* stmt = nullptr;
	if(jj_2_3((long long)3, ctx))
	{
		stmt = sqlStatement(ctx);
	}
		else 
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case INTEGER_LITERAL:
		case FLOATING_POINT_LITERAL:
		case STRING_LITERAL:
		case CHARACTER_LITERAL:
		case SQL_STRING_LITERAL:
		case PLUSPLUS:
		case MINUSMINUS:
		case L_PARENTHESIS:
		case DOLLAR:
		case AT_MARK:
		case L_BRACE:
		case NOT:
		case BREAK:
		case CONTINUE:
		case NATIVE:
		case NEW:
		case RETURN:
		case SUPER:
		case THIS:
		case VOID:
		case DOWNLOAD:
		case REDIRECT:
		case REFERER_FROM:
		case VALIDATOR:
		case LOCAL:
		case TRUE:
		case FALSE:
		case SELECT:
		case INSERT:
		case UPDATE:
		case DELETE:
		case INTO:
		case FROM:
		case WHERE:
		case OR:
		case SQLAND:
		case LIKE:
		case ESCAPE:
		case LEFT:
		case RIGHT:
		case NATURAL:
		case INNER:
		case OUTER:
		case FULL:
		case CROSS:
		case SET:
		case VALUES:
		case GROUP:
		case BY:
		case HAVING:
		case ORDER:
		case ASC:
		case DESC:
		case LIMIT:
		case OFFSET:
		case ON:
		case AS:
		case DISTINCT:
		case SHARE:
		case NOWAIT:
		case OF:
		case IN:
		case BETWEEN:
		case IS:
		case BEGIN:
		case PREPARE:
		case TRANSACTION:
		case ISOLATION:
		case LEVEL:
		case COMMIT:
		case PREPARED:
		case END:
		case ROLLBACK:
		case CREATE:
		case DROP:
		case ALTER:
		case TABLE:
		case SQL_DEFAULT:
		case ADD:
		case RENAME:
		case COLUMN:
		case TO:
		case PRIMARY:
		case KEY:
		case UNIQUE:
		case CHECK:
		case RETURNS:
		case SETOF:
		case LANGUAGE:
		case REPLACE:
		case INDEX:
		case USING:
		case EACH:
		case ROW:
		case STATEMENT:
		case EXECUTE:
		case PROCEDURE:
		case EXISTS:
		case TRIGGER:
		case BEFORE:
		case AFTER:
		case FOREIGN:
		case REFERENCES:
		case ADJUST_WHERE:
		case ADJUST_SET:
		case _NULL:
		case USE:
		case IDENTIFIER:
		case 196:
			{
				stmt = alinousStatement(ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,5, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IDeclare* AlinousPlusParser::alinousDeclare(ThreadContext* ctx)
{
	IDeclare* dec = nullptr;
	if(jj_2_4((long long)2147483647, ctx))
	{
		dec = alinousFunction(ctx);
	}
		else 
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case CLASS:
			{
				dec = alinousClass(ctx);
				break ;
			}
		case CLASS_INTERFACE:
			{
				dec = alinousInterface(ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,6, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	{
		{
			return dec;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
AlinousClass* AlinousPlusParser::alinousInterface(ThreadContext* ctx)
{
	AlinousClass* clazz = (new(ctx) AlinousClass(ctx));
	clazz->setInterfaceClass(true, ctx);
	AlinousName* name = nullptr;
	ClassExtends* extendsClasses = nullptr;
	IClassMember* member = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(CLASS_INTERFACE, ctx);
	name = alinousName(ctx);
	clazz->setName(name, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case EXTENDS:
		{
			extendsClasses = classExtends(ctx);
			clazz->setExtendsClasses(extendsClasses, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,7, ctx);
		;
		break;
	}
	jj_consume_token(L_BRACE, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case _CONST:
		case PRIVATE:
		case PROTECTED:
		case PUBLIC:
		case STATIC:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,8, ctx);
			goto label_4_out_break;
		}
		member = classMember(ctx);
		switch(member->getMemberType(ctx)) {
		case IClassMember::CLASS_METHOD:
			clazz->addMethod(static_cast<ClassMethodFunction*>(member), ctx);
			break ;
		case IClassMember::CLASS_VARIABLE:
			clazz->addVariable(static_cast<ClassMemberVariable*>(member), ctx);
			break ;
		case IClassMember::STATIC_CLASS_METHOD:
			clazz->addStaticMethod(static_cast<ClassMethodFunction*>(member), ctx);
			break ;
		case IClassMember::STATIC_CLASS_VARIABLE:
			clazz->addStaticVariable(static_cast<ClassMemberVariable*>(member), ctx);
			break ;
		default:
			break ;
		}
	}
	label_4_out_break: ;
	t2 = jj_consume_token(R_BRACE, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case SEMI_COLON:
		{
			t2 = jj_consume_token(SEMI_COLON, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,9, ctx);
		;
		break;
	}
	clazz->position(t, t2, ctx);
	{
		{
			return clazz;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
AlinousClass* AlinousPlusParser::alinousClass(ThreadContext* ctx)
{
	AlinousClass* clazz = (new(ctx) AlinousClass(ctx));
	AlinousName* name = nullptr;
	ClassExtends* extendsClasses = nullptr;
	ArrayList<ClassImplements>* implClasses = nullptr;
	IClassMember* member = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(CLASS, ctx);
	name = alinousName(ctx);
	clazz->setName(name, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case EXTENDS:
		{
			extendsClasses = classExtends(ctx);
			clazz->setExtendsClasses(extendsClasses, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,10, ctx);
		;
		break;
	}
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case IMPLEMENTS:
		{
			implClasses = classImplements(ctx);
			clazz->setImplementsClass(implClasses, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,11, ctx);
		;
		break;
	}
	jj_consume_token(L_BRACE, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case _CONST:
		case PRIVATE:
		case PROTECTED:
		case PUBLIC:
		case STATIC:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,12, ctx);
			goto label_5_out_break;
		}
		member = classMember(ctx);
		switch(member->getMemberType(ctx)) {
		case IClassMember::CLASS_METHOD:
			clazz->addMethod(static_cast<ClassMethodFunction*>(member), ctx);
			break ;
		case IClassMember::CLASS_VARIABLE:
			clazz->addVariable(static_cast<ClassMemberVariable*>(member), ctx);
			break ;
		case IClassMember::STATIC_CLASS_METHOD:
			clazz->addStaticMethod(static_cast<ClassMethodFunction*>(member), ctx);
			break ;
		case IClassMember::STATIC_CLASS_VARIABLE:
			clazz->addStaticVariable(static_cast<ClassMemberVariable*>(member), ctx);
			break ;
		default:
			break ;
		}
	}
	label_5_out_break: ;
	t2 = jj_consume_token(R_BRACE, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case SEMI_COLON:
		{
			t2 = jj_consume_token(SEMI_COLON, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,13, ctx);
		;
		break;
	}
	clazz->position(t, t2, ctx);
	{
		{
			return clazz;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ArrayList<ClassImplements>* AlinousPlusParser::classImplements(ThreadContext* ctx)
{
	ArrayList<ClassImplements>* list = (new(ctx) ArrayList<ClassImplements>(ctx));
	AlinousName* type = nullptr;
	ClassImplements* impl = nullptr;
	jj_consume_token(IMPLEMENTS, ctx);
	while(true)
	{
		type = alinousName(ctx);
		impl = (new(ctx) ClassImplements(ctx));
		impl->setClassName(type, ctx);
		impl->position(type, type, ctx);
		list->add(impl, ctx);
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case NOT:
		case NATIVE:
		case SUPER:
		case THIS:
		case VOID:
		case DOWNLOAD:
		case REDIRECT:
		case REFERER_FROM:
		case VALIDATOR:
		case LOCAL:
		case SELECT:
		case INSERT:
		case UPDATE:
		case DELETE:
		case INTO:
		case FROM:
		case WHERE:
		case OR:
		case SQLAND:
		case LIKE:
		case ESCAPE:
		case LEFT:
		case RIGHT:
		case NATURAL:
		case INNER:
		case OUTER:
		case FULL:
		case CROSS:
		case SET:
		case VALUES:
		case GROUP:
		case BY:
		case HAVING:
		case ORDER:
		case ASC:
		case DESC:
		case LIMIT:
		case OFFSET:
		case ON:
		case AS:
		case DISTINCT:
		case SHARE:
		case NOWAIT:
		case OF:
		case IN:
		case BETWEEN:
		case IS:
		case BEGIN:
		case PREPARE:
		case TRANSACTION:
		case ISOLATION:
		case LEVEL:
		case COMMIT:
		case PREPARED:
		case END:
		case ROLLBACK:
		case CREATE:
		case DROP:
		case ALTER:
		case TABLE:
		case SQL_DEFAULT:
		case ADD:
		case RENAME:
		case COLUMN:
		case TO:
		case PRIMARY:
		case KEY:
		case UNIQUE:
		case CHECK:
		case RETURNS:
		case SETOF:
		case LANGUAGE:
		case REPLACE:
		case INDEX:
		case USING:
		case EACH:
		case ROW:
		case STATEMENT:
		case EXECUTE:
		case PROCEDURE:
		case EXISTS:
		case TRIGGER:
		case BEFORE:
		case AFTER:
		case FOREIGN:
		case REFERENCES:
		case ADJUST_WHERE:
		case ADJUST_SET:
		case USE:
		case IDENTIFIER:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,14, ctx);
			goto label_6_out_break;
		}
	}
	label_6_out_break: ;
	{
		{
			return list;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ClassExtends* AlinousPlusParser::classExtends(ThreadContext* ctx)
{
	ClassExtends* exts = (new(ctx) ClassExtends(ctx));
	AlinousName* type = nullptr;
	Token* t = nullptr;
	t = jj_consume_token(EXTENDS, ctx);
	type = alinousName(ctx);
	exts->position(t, type, ctx);
	exts->setClassName(type, ctx);
	{
		{
			return exts;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IClassMember* AlinousPlusParser::classMember(ThreadContext* ctx)
{
	IClassMember* member = nullptr;
	if(jj_2_5((long long)2147483647, ctx))
	{
		member = classMemberVariable(ctx);
	}
		else 
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case _CONST:
		case PRIVATE:
		case PROTECTED:
		case PUBLIC:
		case STATIC:
			{
				member = classMethodFunction(ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,15, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	{
		{
			return member;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
void AlinousPlusParser::classMemberVariableLookAhead(ThreadContext* ctx)
{
	classMemberModifiers(ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case DOLLAR:
	case AT_MARK:
		{
			domVariableDescriptor(ctx);
			break ;
		}
	case NOT:
	case NATIVE:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case USE:
	case IDENTIFIER:
		{
			alinousName(ctx);
			while(true)
			{
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case L_BRACKET:
					{
						;
						break ;
					}
				default:
					jj_la1->set(jj_gen,16, ctx);
					goto label_7_out_break;
				}
				jj_consume_token(L_BRACKET, ctx);
				jj_consume_token(R_BRACKET, ctx);
			}
			label_7_out_break: ;
			alinousName(ctx);
			while(true)
			{
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case L_BRACKET:
					{
						;
						break ;
					}
				default:
					jj_la1->set(jj_gen,17, ctx);
					goto label_8_out_break;
				}
				jj_consume_token(L_BRACKET, ctx);
				jj_consume_token(R_BRACKET, ctx);
			}
			label_8_out_break: ;
			break ;
		}
	default:
		jj_la1->set(jj_gen,18, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case EQUALS:
		{
			jj_consume_token(EQUALS, ctx);
			conditionalExpression(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,19, ctx);
		;
		break;
	}
	jj_consume_token(SEMI_COLON, ctx);
}
ClassMemberVariable* AlinousPlusParser::classMemberVariable(ThreadContext* ctx)
{
	ClassMemberVariable* val = (new(ctx) ClassMemberVariable(ctx));
	ClassMemberModifiers* mod = nullptr;
	AlinousName* type = nullptr;
	AlinousName* name = nullptr;
	DomVariableDescriptor* domDescriptor = nullptr;
	Token* tend = nullptr;
	IExpression* init = nullptr;
	long long dimension = 0;
	mod = classMemberModifiers(ctx);
	val->position(mod, mod, ctx);
	val->setModifier(mod, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case DOLLAR:
	case AT_MARK:
		{
			domDescriptor = domVariableDescriptor(ctx);
			val->setDomDescriptor(domDescriptor, ctx);
			break ;
		}
	case NOT:
	case NATIVE:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case USE:
	case IDENTIFIER:
		{
			type = alinousName(ctx);
			while(true)
			{
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case L_BRACKET:
					{
						;
						break ;
					}
				default:
					jj_la1->set(jj_gen,20, ctx);
					goto label_9_out_break;
				}
				jj_consume_token(L_BRACKET, ctx);
				jj_consume_token(R_BRACKET, ctx);
				dimension ++ ;
			}
			label_9_out_break: ;
			name = alinousName(ctx);
			val->setType(type, ctx);
			val->setName(name, ctx);
			while(true)
			{
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case L_BRACKET:
					{
						;
						break ;
					}
				default:
					jj_la1->set(jj_gen,21, ctx);
					goto label_10_out_break;
				}
				jj_consume_token(L_BRACKET, ctx);
				jj_consume_token(R_BRACKET, ctx);
				dimension ++ ;
			}
			label_10_out_break: ;
			break ;
		}
	default:
		jj_la1->set(jj_gen,22, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case EQUALS:
		{
			jj_consume_token(EQUALS, ctx);
			init = conditionalExpression(ctx);
			val->setInit(init, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,23, ctx);
		;
		break;
	}
	tend = jj_consume_token(SEMI_COLON, ctx);
	val->setDimension((int)dimension, ctx);
	val->endPosition(tend, ctx);
	{
		{
			return val;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ClassMethodFunction* AlinousPlusParser::classMethodFunction(ThreadContext* ctx)
{
	ClassMethodFunction* method = (new(ctx) ClassMethodFunction(ctx));
	ClassMemberModifiers* mod = nullptr;
	AlinousFunction* func = 0;
	mod = classMemberModifiers(ctx);
	func = alinousFunction(ctx);
	method->position(mod, func, ctx);
	method->setModifier(mod, ctx);
	method->setFunc(func, ctx);
	{
		{
			return method;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ClassMemberModifiers* AlinousPlusParser::classMemberModifiers(ThreadContext* ctx)
{
	ClassMemberModifiers* mod = (new(ctx) ClassMemberModifiers(ctx));
	Token* t = nullptr;
	Token* begin = nullptr;
	Token* last = nullptr;
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case PUBLIC:
			{
				t = jj_consume_token(PUBLIC, ctx);
				break ;
			}
		case PRIVATE:
			{
				t = jj_consume_token(PRIVATE, ctx);
				break ;
			}
		case PROTECTED:
			{
				t = jj_consume_token(PROTECTED, ctx);
				break ;
			}
		case STATIC:
			{
				t = jj_consume_token(STATIC, ctx);
				break ;
			}
		case _CONST:
			{
				t = jj_consume_token(_CONST, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,24, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		if(begin == nullptr)
		{
			begin = t;
			last = t;
		}
				else 
		{
			last = t;
		}
		mod->addModifier(t->image, ctx);
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case _CONST:
		case PRIVATE:
		case PROTECTED:
		case PUBLIC:
		case STATIC:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,25, ctx);
			goto label_11_out_break;
		}
	}
	label_11_out_break: ;
	mod->position(begin, last, ctx);
	{
		{
			return mod;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
void AlinousPlusParser::alinousFunctionLookAhead(ThreadContext* ctx)
{
	if(jj_2_6((long long)2, ctx))
	{
		jj_consume_token(FUNCTION, ctx);
		alinousName(ctx);
	}
		else 
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case NOT:
		case NATIVE:
		case SUPER:
		case THIS:
		case VOID:
		case DOWNLOAD:
		case REDIRECT:
		case REFERER_FROM:
		case VALIDATOR:
		case LOCAL:
		case SELECT:
		case INSERT:
		case UPDATE:
		case DELETE:
		case INTO:
		case FROM:
		case WHERE:
		case OR:
		case SQLAND:
		case LIKE:
		case ESCAPE:
		case LEFT:
		case RIGHT:
		case NATURAL:
		case INNER:
		case OUTER:
		case FULL:
		case CROSS:
		case SET:
		case VALUES:
		case GROUP:
		case BY:
		case HAVING:
		case ORDER:
		case ASC:
		case DESC:
		case LIMIT:
		case OFFSET:
		case ON:
		case AS:
		case DISTINCT:
		case SHARE:
		case NOWAIT:
		case OF:
		case IN:
		case BETWEEN:
		case IS:
		case BEGIN:
		case PREPARE:
		case TRANSACTION:
		case ISOLATION:
		case LEVEL:
		case COMMIT:
		case PREPARED:
		case END:
		case ROLLBACK:
		case CREATE:
		case DROP:
		case ALTER:
		case TABLE:
		case SQL_DEFAULT:
		case ADD:
		case RENAME:
		case COLUMN:
		case TO:
		case PRIMARY:
		case KEY:
		case UNIQUE:
		case CHECK:
		case RETURNS:
		case SETOF:
		case LANGUAGE:
		case REPLACE:
		case INDEX:
		case USING:
		case EACH:
		case ROW:
		case STATEMENT:
		case EXECUTE:
		case PROCEDURE:
		case EXISTS:
		case TRIGGER:
		case BEFORE:
		case AFTER:
		case FOREIGN:
		case REFERENCES:
		case ADJUST_WHERE:
		case ADJUST_SET:
		case USE:
		case IDENTIFIER:
			{
				returnValueDefinition(ctx);
				alinousName(ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,26, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	functionArgumentsListDefine(ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case THROWS:
		{
			throwsDefine(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,27, ctx);
		;
		break;
	}
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case L_BRACE:
		{
			statementBlock(ctx);
			break ;
		}
	case SEMI_COLON:
		{
			jj_consume_token(SEMI_COLON, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,28, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
}
AlinousFunction* AlinousPlusParser::alinousFunction(ThreadContext* ctx)
{
	AlinousFunction* func = (new(ctx) AlinousFunction(ctx));
	ReturnValueDefinition* ret = nullptr;
	AlinousName* name = nullptr;
	FunctionArgumentsListDefine* arguments = nullptr;
	ThrowsDefine* throwsDef = nullptr;
	StatementBlock* block = nullptr;
	IAlinousElement* first = nullptr;
	Token* t = nullptr;
	Token* decT = nullptr;
	if(jj_2_7((long long)2, ctx))
	{
		t = jj_consume_token(FUNCTION, ctx);
		name = alinousName(ctx);
		if(first == nullptr)
		{
			first = name;
		}
		func->setName(name, ctx);
	}
		else 
	{
		if(jj_2_8((long long)3, ctx))
		{
			ret = returnValueDefinition(ctx);
			first = ret;
			func->setReturnType(ret, ctx);
			name = alinousName(ctx);
			func->setName(name, ctx);
		}
				else 
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case NOT:
			case NATIVE:
			case SUPER:
			case THIS:
			case VOID:
			case DOWNLOAD:
			case REDIRECT:
			case REFERER_FROM:
			case VALIDATOR:
			case LOCAL:
			case SELECT:
			case INSERT:
			case UPDATE:
			case DELETE:
			case INTO:
			case FROM:
			case WHERE:
			case OR:
			case SQLAND:
			case LIKE:
			case ESCAPE:
			case LEFT:
			case RIGHT:
			case NATURAL:
			case INNER:
			case OUTER:
			case FULL:
			case CROSS:
			case SET:
			case VALUES:
			case GROUP:
			case BY:
			case HAVING:
			case ORDER:
			case ASC:
			case DESC:
			case LIMIT:
			case OFFSET:
			case ON:
			case AS:
			case DISTINCT:
			case SHARE:
			case NOWAIT:
			case OF:
			case IN:
			case BETWEEN:
			case IS:
			case BEGIN:
			case PREPARE:
			case TRANSACTION:
			case ISOLATION:
			case LEVEL:
			case COMMIT:
			case PREPARED:
			case END:
			case ROLLBACK:
			case CREATE:
			case DROP:
			case ALTER:
			case TABLE:
			case SQL_DEFAULT:
			case ADD:
			case RENAME:
			case COLUMN:
			case TO:
			case PRIMARY:
			case KEY:
			case UNIQUE:
			case CHECK:
			case RETURNS:
			case SETOF:
			case LANGUAGE:
			case REPLACE:
			case INDEX:
			case USING:
			case EACH:
			case ROW:
			case STATEMENT:
			case EXECUTE:
			case PROCEDURE:
			case EXISTS:
			case TRIGGER:
			case BEFORE:
			case AFTER:
			case FOREIGN:
			case REFERENCES:
			case ADJUST_WHERE:
			case ADJUST_SET:
			case USE:
			case IDENTIFIER:
				{
					name = alinousName(ctx);
					first = name;
					func->setName(name, ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,29, ctx);
				jj_consume_token((long long)-1, ctx);
				throw (new(ctx) ParseException(ctx));
				break;
			}
		}
	}
	arguments = functionArgumentsListDefine(ctx);
	func->setArguments(arguments, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case THROWS:
		{
			throwsDef = throwsDefine(ctx);
			func->setThrowsDefine(throwsDef, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,30, ctx);
		;
		break;
	}
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case L_BRACE:
		{
			block = statementBlock(ctx);
			break ;
		}
	case SEMI_COLON:
		{
			decT = jj_consume_token(SEMI_COLON, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,31, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	func->setBlock(block, ctx);
	if(t == nullptr)
	{
		if(block != nullptr)
		{
			func->position(first, block, ctx);
		}
				else 
		{
			func->position(first, decT, ctx);
		}
	}
		else 
	{
		if(block != nullptr)
		{
			func->position(t, block, ctx);
		}
				else 
		{
			func->position(t, decT, ctx);
		}
	}
	{
		{
			return func;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ReturnValueDefinition* AlinousPlusParser::returnValueDefinition(ThreadContext* ctx)
{
	ReturnValueDefinition* retValue = (new(ctx) ReturnValueDefinition(ctx));
	AlinousName* type = nullptr;
	type = alinousName(ctx);
	retValue->position(type, type, ctx);
	retValue->setType(type, ctx);
	{
		{
			return retValue;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
FunctionArgumentsListDefine* AlinousPlusParser::functionArgumentsListDefine(ThreadContext* ctx)
{
	FunctionArgumentsListDefine* arguments = (new(ctx) FunctionArgumentsListDefine(ctx));
	FunctionArgumentDefine* arg = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(L_PARENTHESIS, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case DOLLAR:
	case AT_MARK:
	case NOT:
	case NATIVE:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case USE:
	case IDENTIFIER:
		{
			arg = functionArgumentDefine(ctx);
			arguments->addArgument(arg, ctx);
			while(true)
			{
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case COMMA:
					{
						;
						break ;
					}
				default:
					jj_la1->set(jj_gen,32, ctx);
					goto label_12_out_break;
				}
				jj_consume_token(COMMA, ctx);
				arg = functionArgumentDefine(ctx);
				arguments->addArgument(arg, ctx);
			}
			label_12_out_break: ;
			break ;
		}
	default:
		jj_la1->set(jj_gen,33, ctx);
		;
		break;
	}
	t2 = jj_consume_token(R_PARENTHESIS, ctx);
	arguments->position(t, t2, ctx);
	{
		{
			return arguments;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
FunctionArgumentDefine* AlinousPlusParser::functionArgumentDefine(ThreadContext* ctx)
{
	FunctionArgumentDefine* args = (new(ctx) FunctionArgumentDefine(ctx));
	AlinousName* type = nullptr;
	AlinousName* name = nullptr;
	DomVariableDescriptor* domDescriptor = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case DOLLAR:
	case AT_MARK:
		{
			domDescriptor = domVariableDescriptor(ctx);
			args->position(domDescriptor, domDescriptor, ctx);
			args->setDomDescriptor(domDescriptor, ctx);
			{
				{
					return args;
				}
			}
			break ;
		}
	case NOT:
	case NATIVE:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case USE:
	case IDENTIFIER:
		{
			type = alinousName(ctx);
			name = alinousName(ctx);
			args->position(type, name, ctx);
			args->setType(type, ctx);
			args->setName(name, ctx);
			{
				{
					return args;
				}
			}
			break ;
		}
	default:
		jj_la1->set(jj_gen,34, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ThrowsDefine* AlinousPlusParser::throwsDefine(ThreadContext* ctx)
{
	ThrowsDefine* throwsDef = (new(ctx) ThrowsDefine(ctx));
	AlinousName* type = nullptr;
	Token* t = nullptr;
	t = jj_consume_token(THROWS, ctx);
	type = alinousName(ctx);
	throwsDef->position(t, type, ctx);
	throwsDef->addException(type, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case COMMA:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,35, ctx);
			goto label_13_out_break;
		}
		jj_consume_token(COMMA, ctx);
		type = alinousName(ctx);
		throwsDef->addException(type, ctx);
		throwsDef->endPosition(type, ctx);
	}
	label_13_out_break: ;
	{
		{
			return throwsDef;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IStatement* AlinousPlusParser::alinousStatement(ThreadContext* ctx)
{
	IStatement* stmt = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case BREAK:
		{
			stmt = breakStatement(ctx);
			break ;
		}
	case CONTINUE:
		{
			stmt = continueStatement(ctx);
			break ;
		}
	case L_BRACE:
		{
			stmt = statementBlock(ctx);
			break ;
		}
	case RETURN:
		{
			stmt = returnStatement(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,36, ctx);
		if(jj_2_9((long long)2147483647, ctx))
		{
			stmt = assignmentStatement(ctx);
		}
				else 
		{
			if(jj_2_10((long long)3, ctx))
			{
				stmt = expressionStatement(ctx);
			}
						else 
			{
				if(jj_2_11((long long)3, ctx))
				{
					stmt = typedVariableDeclare(ctx);
				}
								else 
				{
					jj_consume_token((long long)-1, ctx);
					throw (new(ctx) ParseException(ctx));
				}
			}
		}
		break;
	}
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IfStatement* AlinousPlusParser::ifStatement(ThreadContext* ctx)
{
	IfStatement* stmt = (new(ctx) IfStatement(ctx));
	Token* t = nullptr;
	IExpression* exp = nullptr;
	IStatement* exec = nullptr;
	t = jj_consume_token(IF, ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	exp = conditionalExpression(ctx);
	jj_consume_token(R_PARENTHESIS, ctx);
	exec = alinousStatement(ctx);
	stmt->setExp(exp, ctx);
	stmt->setExec(exec, ctx);
	stmt->position(t, exec, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SwitchStatement* AlinousPlusParser::switchStatement(ThreadContext* ctx)
{
	SwitchStatement* stmt = (new(ctx) SwitchStatement(ctx));
	LabeledStatement* label = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	IExpression* exp = nullptr;
	SwitchCasePart* part = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case COLON:
		{
			label = labeledStatement(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,37, ctx);
		;
		break;
	}
	t = jj_consume_token(SWITCH, ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	exp = conditionalExpression(ctx);
	jj_consume_token(R_PARENTHESIS, ctx);
	jj_consume_token(L_BRACE, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case CASE:
		case SQL_DEFAULT:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,38, ctx);
			goto label_14_out_break;
		}
		part = switchCasePart(ctx);
		stmt->addCasePart(part, ctx);
	}
	label_14_out_break: ;
	t2 = jj_consume_token(R_BRACE, ctx);
	stmt->setExp(exp, ctx);
	if(label != nullptr)
	{
		stmt->setLabel(label, ctx);
		stmt->position(label, t2, ctx);
	}
		else 
	{
		stmt->position(t, t2, ctx);
	}
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SwitchCasePart* AlinousPlusParser::switchCasePart(ThreadContext* ctx)
{
	SwitchCasePart* part = (new(ctx) SwitchCasePart(ctx));
	CaseStatement* caseStmt = nullptr;
	CaseStatement* first = nullptr;
	IAlinousElement* last = nullptr;
	StatementList* list = nullptr;
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case CASE:
			{
				caseStmt = caseStatement(ctx);
				break ;
			}
		case SQL_DEFAULT:
			{
				caseStmt = defaultStatement(ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,39, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		part->addCase(caseStmt, ctx);
		if(first == nullptr)
		{
			first = caseStmt;
		}
		last = caseStmt;
		if(jj_2_12((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_15_out_break;
		}
	}
	label_15_out_break: ;
	if(jj_2_13((long long)2, ctx))
	{
		list = statementList(ctx);
		part->setStmtlist(list, ctx);
		last = list;
	}
		else 
	{
		;
	}
	part->position(first, last, ctx);
	{
		{
			return part;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
CaseStatement* AlinousPlusParser::caseStatement(ThreadContext* ctx)
{
	CaseStatement* stmt = (new(ctx) CaseStatement(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	AlinousName* constId = nullptr;
	t = jj_consume_token(CASE, ctx);
	constId = alinousName(ctx);
	t2 = jj_consume_token(COLON, ctx);
	stmt->position(t, t2, ctx);
	stmt->setConstId(constId, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
DefaultStatement* AlinousPlusParser::defaultStatement(ThreadContext* ctx)
{
	DefaultStatement* stmt = (new(ctx) DefaultStatement(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(SQL_DEFAULT, ctx);
	t2 = jj_consume_token(COLON, ctx);
	stmt->position(t, t2, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ForStatement* AlinousPlusParser::forStatement(ThreadContext* ctx)
{
	ForStatement* stmt = (new(ctx) ForStatement(ctx));
	LabeledStatement* label = nullptr;
	Token* t = nullptr;
	IStatement* initStatement = nullptr;
	IExpression* condition = nullptr;
	ForUpdatePart* updatePart = nullptr;
	IStatement* exec = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case COLON:
		{
			label = labeledStatement(ctx);
			stmt->setLabel(label, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,40, ctx);
		;
		break;
	}
	t = jj_consume_token(FOR, ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case SEMI_COLON:
		{
			jj_consume_token(SEMI_COLON, ctx);
			break ;
		}
	case INTEGER_LITERAL:
	case FLOATING_POINT_LITERAL:
	case STRING_LITERAL:
	case CHARACTER_LITERAL:
	case SQL_STRING_LITERAL:
	case PLUSPLUS:
	case MINUSMINUS:
	case L_PARENTHESIS:
	case DOLLAR:
	case AT_MARK:
	case L_BRACE:
	case NOT:
	case BREAK:
	case CONTINUE:
	case NATIVE:
	case NEW:
	case RETURN:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case TRUE:
	case FALSE:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case _NULL:
	case USE:
	case IDENTIFIER:
	case 196:
		{
			initStatement = alinousStatement(ctx);
			stmt->setInitStatement(initStatement, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,41, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case INTEGER_LITERAL:
	case FLOATING_POINT_LITERAL:
	case STRING_LITERAL:
	case CHARACTER_LITERAL:
	case SQL_STRING_LITERAL:
	case PLUSPLUS:
	case MINUSMINUS:
	case L_PARENTHESIS:
	case DOLLAR:
	case AT_MARK:
	case NOT:
	case NATIVE:
	case NEW:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case TRUE:
	case FALSE:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case _NULL:
	case USE:
	case IDENTIFIER:
	case 196:
		{
			condition = conditionalExpression(ctx);
			stmt->setCondition(condition, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,42, ctx);
		;
		break;
	}
	jj_consume_token(SEMI_COLON, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case INTEGER_LITERAL:
	case FLOATING_POINT_LITERAL:
	case STRING_LITERAL:
	case CHARACTER_LITERAL:
	case SQL_STRING_LITERAL:
	case PLUSPLUS:
	case MINUSMINUS:
	case L_PARENTHESIS:
	case DOLLAR:
	case AT_MARK:
	case NOT:
	case NATIVE:
	case NEW:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case TRUE:
	case FALSE:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case _NULL:
	case USE:
	case IDENTIFIER:
	case 196:
		{
			updatePart = forUpdatePart(ctx);
			stmt->setUpdatePart(updatePart, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,43, ctx);
		;
		break;
	}
	jj_consume_token(R_PARENTHESIS, ctx);
	exec = alinousStatement(ctx);
	stmt->setExec(exec, ctx);
	if(label != nullptr)
	{
		stmt->startPosition(label, ctx);
	}
		else 
	{
		stmt->startPosition(t, ctx);
	}
	stmt->endPosition(exec, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ForUpdatePart* AlinousPlusParser::forUpdatePart(ThreadContext* ctx)
{
	ForUpdatePart* part = (new(ctx) ForUpdatePart(ctx));
	IExpression* left = nullptr;
	IExpression* right = nullptr;
	Token* op = nullptr;
	left = conditionalExpression(ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case EQUALS:
	case 197:
	case 198:
	case 199:
	case 200:
	case 201:
	case 202:
	case 203:
	case 204:
	case 205:
	case 206:
		{
			op = assignmentOperator(ctx);
			right = conditionalExpression(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,44, ctx);
		;
		break;
	}
	if(right == nullptr)
	{
		part->position(left, right, ctx);
		part->setLeft(left, ctx);
	}
		else 
	{
		part->position(left, left, ctx);
		part->setLeft(left, ctx);
		part->setOpe(op->image, ctx);
		part->setRight(right, ctx);
	}
	{
		{
			return part;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
DoWhileStatement* AlinousPlusParser::doWhileStatement(ThreadContext* ctx)
{
	DoWhileStatement* stmt = (new(ctx) DoWhileStatement(ctx));
	LabeledStatement* label = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	IExpression* exp = nullptr;
	IStatement* exec = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case COLON:
		{
			label = labeledStatement(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,45, ctx);
		;
		break;
	}
	t = jj_consume_token(DO, ctx);
	exec = alinousStatement(ctx);
	jj_consume_token(WHILE, ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	exp = conditionalExpression(ctx);
	jj_consume_token(R_PARENTHESIS, ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	if(label != nullptr)
	{
		stmt->position(label, t2, ctx);
		stmt->setLabel(label, ctx);
	}
		else 
	{
		stmt->position(t, t2, ctx);
	}
	stmt->setExp(exp, ctx);
	stmt->setExec(exec, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
WhileStatement* AlinousPlusParser::whileStatement(ThreadContext* ctx)
{
	WhileStatement* stmt = (new(ctx) WhileStatement(ctx));
	LabeledStatement* label = nullptr;
	Token* t = nullptr;
	IExpression* exp = nullptr;
	IStatement* exec = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case COLON:
		{
			label = labeledStatement(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,46, ctx);
		;
		break;
	}
	t = jj_consume_token(WHILE, ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	exp = conditionalExpression(ctx);
	jj_consume_token(R_PARENTHESIS, ctx);
	exec = alinousStatement(ctx);
	if(label != nullptr)
	{
		stmt->position(label, exec, ctx);
		stmt->setLabel(label, ctx);
	}
		else 
	{
		stmt->position(t, exec, ctx);
	}
	stmt->setExp(exp, ctx);
	stmt->setExec(exec, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
BreakStatement* AlinousPlusParser::breakStatement(ThreadContext* ctx)
{
	BreakStatement* stmt = (new(ctx) BreakStatement(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	Token* lbl = nullptr;
	t = jj_consume_token(BREAK, ctx);
	lbl = nameIdentifier(ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(t, t2, ctx);
	stmt->setLabel(lbl->image, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ContinueStatement* AlinousPlusParser::continueStatement(ThreadContext* ctx)
{
	ContinueStatement* stmt = (new(ctx) ContinueStatement(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	Token* lbl = nullptr;
	t = jj_consume_token(CONTINUE, ctx);
	lbl = nameIdentifier(ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(t, t2, ctx);
	stmt->setLabel(lbl->image, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
LabeledStatement* AlinousPlusParser::labeledStatement(ThreadContext* ctx)
{
	LabeledStatement* stmt = (new(ctx) LabeledStatement(ctx));
	Token* t = nullptr;
	Token* lbl = nullptr;
	t = jj_consume_token(COLON, ctx);
	lbl = nameIdentifier(ctx);
	stmt->setLabel(lbl->image, ctx);
	stmt->position(t, lbl, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
TypedVariableDeclare* AlinousPlusParser::typedVariableDeclare(ThreadContext* ctx)
{
	TypedVariableDeclare* stmt = (new(ctx) TypedVariableDeclare(ctx));
	AlinousName* type = 0;
	AlinousName* name = 0;
	IExpression* init = nullptr;
	Token* t = nullptr;
	long long dimension = 0;
	type = alinousName(ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case L_BRACKET:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,47, ctx);
			goto label_16_out_break;
		}
		jj_consume_token(L_BRACKET, ctx);
		jj_consume_token(R_BRACKET, ctx);
		dimension ++ ;
	}
	label_16_out_break: ;
	name = alinousName(ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case L_BRACKET:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,48, ctx);
			goto label_17_out_break;
		}
		jj_consume_token(L_BRACKET, ctx);
		jj_consume_token(R_BRACKET, ctx);
		dimension ++ ;
	}
	label_17_out_break: ;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case EQUALS:
		{
			jj_consume_token(EQUALS, ctx);
			init = conditionalExpression(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,49, ctx);
		;
		break;
	}
	t = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(type, t, ctx);
	if(init != nullptr)
	{
		stmt->setInitExp(init, ctx);
	}
	stmt->setTypeName(type, ctx);
	stmt->setName(name, ctx);
	stmt->setDimension((int)dimension, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
void AlinousPlusParser::assignmentStatementLookAhead(ThreadContext* ctx)
{
	conditionalExpression(ctx);
	jj_consume_token(EQUALS, ctx);
	conditionalExpression(ctx);
	jj_consume_token(SEMI_COLON, ctx);
}
AssignmentStatement* AlinousPlusParser::assignmentStatement(ThreadContext* ctx)
{
	AssignmentStatement* stmt = (new(ctx) AssignmentStatement(ctx));
	IExpression* left = nullptr;
	IExpression* right = nullptr;
	Token* t = nullptr;
	Token* op = nullptr;
	left = conditionalExpression(ctx);
	op = assignmentOperator(ctx);
	right = conditionalExpression(ctx);
	t = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(left, t, ctx);
	stmt->setLeft(left, ctx);
	stmt->setOpe(op->image, ctx);
	stmt->setRight(right, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
StatementBlock* AlinousPlusParser::statementBlock(ThreadContext* ctx)
{
	StatementBlock* stmt = (new(ctx) StatementBlock(ctx));
	StatementList* list = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(L_BRACE, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case INTEGER_LITERAL:
	case FLOATING_POINT_LITERAL:
	case STRING_LITERAL:
	case CHARACTER_LITERAL:
	case SQL_STRING_LITERAL:
	case PLUSPLUS:
	case MINUSMINUS:
	case L_PARENTHESIS:
	case DOLLAR:
	case AT_MARK:
	case L_BRACE:
	case NOT:
	case BREAK:
	case CONTINUE:
	case NATIVE:
	case NEW:
	case RETURN:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case TRUE:
	case FALSE:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case _NULL:
	case USE:
	case IDENTIFIER:
	case 196:
		{
			list = statementList(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,50, ctx);
		;
		break;
	}
	t2 = jj_consume_token(R_BRACE, ctx);
	stmt->position(t, t2, ctx);
	stmt->setList(list, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ExpressionStatement* AlinousPlusParser::expressionStatement(ThreadContext* ctx)
{
	ExpressionStatement* stmt = (new(ctx) ExpressionStatement(ctx));
	IExpression* exp = nullptr;
	Token* t = nullptr;
	exp = conditionalExpression(ctx);
	t = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(exp, t, ctx);
	stmt->setExp(exp, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ReturnStatement* AlinousPlusParser::returnStatement(ThreadContext* ctx)
{
	ReturnStatement* stmt = (new(ctx) ReturnStatement(ctx));
	IExpression* exp = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(RETURN, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case INTEGER_LITERAL:
	case FLOATING_POINT_LITERAL:
	case STRING_LITERAL:
	case CHARACTER_LITERAL:
	case SQL_STRING_LITERAL:
	case PLUSPLUS:
	case MINUSMINUS:
	case L_PARENTHESIS:
	case DOLLAR:
	case AT_MARK:
	case NOT:
	case NATIVE:
	case NEW:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case TRUE:
	case FALSE:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case _NULL:
	case USE:
	case IDENTIFIER:
	case 196:
		{
			exp = conditionalExpression(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,51, ctx);
		;
		break;
	}
	t2 = jj_consume_token(SEMI_COLON, ctx);
	if(exp != nullptr)
	{
		stmt->position(t, t2, ctx);
		stmt->setExp(exp, ctx);
	}
		else 
	{
		stmt->position(t, t2, ctx);
	}
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::conditionalExpression(ThreadContext* ctx)
{
	ConditionalExpression* cond = nullptr;
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	IExpression* altexp = nullptr;
	Token* t = nullptr;
	first = conditionalOrExpression(ctx);
	if(jj_2_14((long long)2, ctx))
	{
		t = jj_consume_token((long long)193, ctx);
		exp = conditionalExpression(ctx);
		jj_consume_token(COLON, ctx);
		altexp = conditionalExpression(ctx);
	}
		else 
	{
		;
	}
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	cond = (new(ctx) ConditionalExpression(ctx));
	cond->position(first, altexp, ctx);
	cond->setFirst(first, ctx);
	cond->setExp(exp, ctx);
	cond->setAltexp(altexp, ctx);
	{
		{
			return cond;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::conditionalOrExpression(ThreadContext* ctx)
{
	ConditionalOrExpression* orExp = nullptr;
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	BooleanSubExpression* subExp = nullptr;
	first = conditionalAndExpression(ctx);
	while(true)
	{
		if(jj_2_15((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_18_out_break;
		}
		t = jj_consume_token(LOGICAL_OR, ctx);
		exp = conditionalAndExpression(ctx);
		if(orExp == nullptr)
		{
			orExp = (new(ctx) ConditionalOrExpression(ctx));
		}
		subExp = (new(ctx) BooleanSubExpression(t->image, exp, ctx));
		subExp->position(t, exp, ctx);
		orExp->addSubExpression(subExp, ctx);
	}
	label_18_out_break: ;
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	orExp->position(first, exp, ctx);
	orExp->setFirst(first, ctx);
	{
		{
			return orExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::conditionalAndExpression(ThreadContext* ctx)
{
	ConditionalAndExpression* andExp = nullptr;
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	BooleanSubExpression* subExp = nullptr;
	first = inclusiveOrExpression(ctx);
	while(true)
	{
		if(jj_2_16((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_19_out_break;
		}
		t = jj_consume_token(LOGICAL_AND, ctx);
		exp = inclusiveOrExpression(ctx);
		if(andExp == nullptr)
		{
			andExp = (new(ctx) ConditionalAndExpression(ctx));
		}
		subExp = (new(ctx) BooleanSubExpression(t->image, exp, ctx));
		subExp->position(t, exp, ctx);
		andExp->addSubExpression(subExp, ctx);
	}
	label_19_out_break: ;
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	andExp->position(first, exp, ctx);
	andExp->setFirst(first, ctx);
	{
		{
			return andExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::inclusiveOrExpression(ThreadContext* ctx)
{
	InclusiveOrExpression* orExp = nullptr;
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	BooleanSubExpression* subExp = nullptr;
	first = exclusiveOrExpression(ctx);
	while(true)
	{
		if(jj_2_17((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_20_out_break;
		}
		t = jj_consume_token(BIT_OR, ctx);
		exp = exclusiveOrExpression(ctx);
		if(orExp == nullptr)
		{
			orExp = (new(ctx) InclusiveOrExpression(ctx));
		}
		subExp = (new(ctx) BooleanSubExpression(t->image, exp, ctx));
		subExp->position(t, exp, ctx);
		orExp->addSubExpression(subExp, ctx);
	}
	label_20_out_break: ;
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	orExp->position(first, exp, ctx);
	orExp->setFirst(first, ctx);
	{
		{
			return orExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::exclusiveOrExpression(ThreadContext* ctx)
{
	ExclusiveOrExpression* exor = nullptr;
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	BooleanSubExpression* subExp = nullptr;
	first = andExpression(ctx);
	while(true)
	{
		if(jj_2_18((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_21_out_break;
		}
		t = jj_consume_token((long long)194, ctx);
		exp = andExpression(ctx);
		if(exor == nullptr)
		{
			exor = (new(ctx) ExclusiveOrExpression(ctx));
		}
		subExp = (new(ctx) BooleanSubExpression(t->image, exp, ctx));
		subExp->position(t, exp, ctx);
		exor->addSubExpression(subExp, ctx);
	}
	label_21_out_break: ;
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	exor->position(first, exp, ctx);
	exor->setFirst(first, ctx);
	{
		{
			return exor;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::andExpression(ThreadContext* ctx)
{
	AndExpression* andExp = nullptr;
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	BooleanSubExpression* subExp = nullptr;
	first = equalityExpression(ctx);
	while(true)
	{
		if(jj_2_19((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_22_out_break;
		}
		t = jj_consume_token(BIT_AND, ctx);
		exp = equalityExpression(ctx);
		if(andExp == nullptr)
		{
			andExp = (new(ctx) AndExpression(ctx));
		}
		subExp = (new(ctx) BooleanSubExpression(t->image, exp, ctx));
		subExp->position(t, exp, ctx);
		andExp->addSubExpression(subExp, ctx);
	}
	label_22_out_break: ;
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	andExp->position(first, exp, ctx);
	andExp->setFirst(first, ctx);
	{
		{
			return andExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::equalityExpression(ThreadContext* ctx)
{
	EqualityExpression* eqexp = nullptr;
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	first = instanceOfExpression(ctx);
	if(jj_2_20((long long)2, ctx))
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case CMP_EQUALS:
			{
				t = jj_consume_token(CMP_EQUALS, ctx);
				break ;
			}
		case CMP_NOTEQUALS:
			{
				t = jj_consume_token(CMP_NOTEQUALS, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,52, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		exp = instanceOfExpression(ctx);
		if(eqexp == nullptr)
		{
			eqexp = (new(ctx) EqualityExpression(ctx));
		}
		eqexp->setRight(exp, ctx);
	}
		else 
	{
		;
	}
	if(exp == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	eqexp->position(first, exp, ctx);
	eqexp->setLeft(first, ctx);
	eqexp->setOpe(t->image, ctx);
	{
		{
			return eqexp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::instanceOfExpression(ThreadContext* ctx)
{
	InstanceOfExpression* instanceofexp = nullptr;
	IExpression* first = nullptr;
	Token* t = nullptr;
	AlinousName* ty = nullptr;
	first = relationalExpression(ctx);
	if(jj_2_21((long long)2, ctx))
	{
		t = jj_consume_token(INSTANCEOF, ctx);
		ty = alinousName(ctx);
	}
		else 
	{
		;
	}
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	instanceofexp = (new(ctx) InstanceOfExpression(ctx));
	instanceofexp->position(first, ty, ctx);
	instanceofexp->setLeft(first, ctx);
	instanceofexp->setRight(ty, ctx);
	{
		{
			return instanceofexp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::relationalExpression(ThreadContext* ctx)
{
	RelationalExpression* relational = nullptr;
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	first = shiftExpression(ctx);
	if(jj_2_22((long long)2, ctx))
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case LT:
			{
				t = jj_consume_token(LT, ctx);
				break ;
			}
		case GT:
			{
				t = jj_consume_token(GT, ctx);
				break ;
			}
		case LEQ:
			{
				t = jj_consume_token(LEQ, ctx);
				break ;
			}
		case GEQ:
			{
				t = jj_consume_token(GEQ, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,53, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		exp = shiftExpression(ctx);
	}
		else 
	{
		;
	}
	if(exp == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	relational = (new(ctx) RelationalExpression(ctx));
	relational->position(first, exp, ctx);
	relational->setLeft(first, ctx);
	relational->setOpe(t->image, ctx);
	relational->setRight(exp, ctx);
	{
		{
			return relational;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::shiftExpression(ThreadContext* ctx)
{
	ShiftExpression* shift = nullptr;
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	SubExpression* subExp = nullptr;
	first = additiveExpression(ctx);
	while(true)
	{
		if(jj_2_23((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_23_out_break;
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case 195:
			{
				t = jj_consume_token((long long)195, ctx);
				break ;
			}
		case RSIGNEDSHIFT:
			{
				t = jj_consume_token(RSIGNEDSHIFT, ctx);
				break ;
			}
		case RUNSIGNEDSHIFT:
			{
				t = jj_consume_token(RUNSIGNEDSHIFT, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,54, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		exp = additiveExpression(ctx);
		if(shift == nullptr)
		{
			shift = (new(ctx) ShiftExpression(ctx));
		}
		subExp = (new(ctx) SubExpression(t->image, exp, ctx));
		subExp->position(t, exp, ctx);
		shift->addSubExpression(subExp, ctx);
	}
	label_23_out_break: ;
	if(exp == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	shift->position(first, exp, ctx);
	shift->setFirst(first, ctx);
	{
		{
			return shift;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::additiveExpression(ThreadContext* ctx)
{
	AdditiveExpression* additive = nullptr;
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	SubExpression* subExp = nullptr;
	first = multiplicativeExpression(ctx);
	while(true)
	{
		if(jj_2_24((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_24_out_break;
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case PLUS:
			{
				t = jj_consume_token(PLUS, ctx);
				break ;
			}
		case MINUS:
			{
				t = jj_consume_token(MINUS, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,55, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		exp = multiplicativeExpression(ctx);
		if(additive == nullptr)
		{
			additive = (new(ctx) AdditiveExpression(ctx));
		}
		subExp = (new(ctx) SubExpression(t->image, exp, ctx));
		subExp->position(t, exp, ctx);
		additive->addSubExpression(subExp, ctx);
	}
	label_24_out_break: ;
	if(exp == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	additive->position(first, exp, ctx);
	additive->setFirst(first, ctx);
	{
		{
			return additive;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::multiplicativeExpression(ThreadContext* ctx)
{
	MultiplicativeExpression* mulExp = (new(ctx) MultiplicativeExpression(ctx));
	IExpression* first = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	SubExpression* subExp = nullptr;
	first = notExpression(ctx);
	while(true)
	{
		if(jj_2_25((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_25_out_break;
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case ASTERISK:
			{
				t = jj_consume_token(ASTERISK, ctx);
				break ;
			}
		case DIV:
			{
				t = jj_consume_token(DIV, ctx);
				break ;
			}
		case MODULO:
			{
				t = jj_consume_token(MODULO, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,56, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		exp = notExpression(ctx);
		subExp = (new(ctx) SubExpression(t->image, exp, ctx));
		subExp->position(t, exp, ctx);
		mulExp->addSubExpression(subExp, ctx);
	}
	label_25_out_break: ;
	if(exp == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	mulExp->position(first, exp, ctx);
	mulExp->setFirst(first, ctx);
	{
		{
			return mulExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::notExpression(ThreadContext* ctx)
{
	NotExpression* notexp = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	if(jj_2_26((long long)2, ctx))
	{
		t = jj_consume_token(NOT, ctx);
	}
		else 
	{
		;
	}
	exp = unaryExpression(ctx);
	if(t == nullptr)
	{
		{
			{
				return exp;
			}
		}
	}
	notexp = (new(ctx) NotExpression(ctx));
	notexp->position(t, exp, ctx);
	notexp->setExp(exp, ctx);
	{
		{
			return notexp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IExpression* AlinousPlusParser::unaryExpression(ThreadContext* ctx)
{
	IExpression* exp = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case PLUSPLUS:
		{
			exp = preIncrementExpression(ctx);
			break ;
		}
	case MINUSMINUS:
		{
			exp = preDecrementExpression(ctx);
			break ;
		}
	case 196:
		{
			exp = bitReverseExpression(ctx);
			break ;
		}
	case NEW:
		{
			exp = allocationExpression(ctx);
			break ;
		}
	case TRUE:
	case FALSE:
		{
			exp = booleanLiteral(ctx);
			break ;
		}
	case _NULL:
		{
			exp = nullLiteral(ctx);
			break ;
		}
	case INTEGER_LITERAL:
	case FLOATING_POINT_LITERAL:
	case STRING_LITERAL:
	case CHARACTER_LITERAL:
	case SQL_STRING_LITERAL:
		{
			exp = literal(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,57, ctx);
		if(jj_2_27((long long)2, ctx))
		{
			exp = castExpression(ctx);
		}
				else 
		{
			if(jj_2_28((long long)2, ctx))
			{
				exp = expressionStream(ctx);
			}
						else 
			{
				if(jj_2_29((long long)2147483647, ctx))
				{
					exp = parenthesisExpression(ctx);
				}
								else 
				{
					jj_consume_token((long long)-1, ctx);
					throw (new(ctx) ParseException(ctx));
				}
			}
		}
		break;
	}
	{
		{
			return exp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
AllocationExpression* AlinousPlusParser::allocationExpression(ThreadContext* ctx)
{
	AllocationExpression* exp = (new(ctx) AllocationExpression(ctx));
	AlinousName* objectClassName = nullptr;
	FunctionArguments* arguments = nullptr;
	Token* t = nullptr;
	Token* last = nullptr;
	IExpression* arrayCapacity = nullptr;
	t = jj_consume_token(NEW, ctx);
	objectClassName = alinousName(ctx);
	exp->position(t, objectClassName, ctx);
	exp->setObjectClassName(objectClassName, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case L_PARENTHESIS:
	case L_BRACKET:
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case L_PARENTHESIS:
				{
					arguments = functionArguments(ctx);
					exp->setArguments(arguments, ctx);
					break ;
				}
			case L_BRACKET:
				{
					while(true)
					{
						jj_consume_token(L_BRACKET, ctx);
						arrayCapacity = conditionalExpression(ctx);
						last = jj_consume_token(R_BRACKET, ctx);
						exp->addArrayCapacity(arrayCapacity, ctx);
						exp->endPosition(last, ctx);
						switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
						case L_BRACKET:
							{
								;
								break ;
							}
						default:
							jj_la1->set(jj_gen,58, ctx);
							goto label_26_out_break;
						}
					}
					label_26_out_break: ;
					break ;
				}
			default:
				jj_la1->set(jj_gen,59, ctx);
				jj_consume_token((long long)-1, ctx);
				throw (new(ctx) ParseException(ctx));
				break;
			}
			break ;
		}
	default:
		jj_la1->set(jj_gen,60, ctx);
		;
		break;
	}
	{
		{
			return exp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ExpressionStream* AlinousPlusParser::expressionStream(ThreadContext* ctx)
{
	ExpressionStream* stream = (new(ctx) ExpressionStream(ctx));
	IExpression* exp = nullptr;
	IExpression* exp2 = nullptr;
	if(jj_2_30((long long)2, ctx))
	{
		exp = functionCallExpression(ctx);
	}
		else 
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case DOLLAR:
		case AT_MARK:
		case NOT:
		case NATIVE:
		case SUPER:
		case THIS:
		case VOID:
		case DOWNLOAD:
		case REDIRECT:
		case REFERER_FROM:
		case VALIDATOR:
		case LOCAL:
		case SELECT:
		case INSERT:
		case UPDATE:
		case DELETE:
		case INTO:
		case FROM:
		case WHERE:
		case OR:
		case SQLAND:
		case LIKE:
		case ESCAPE:
		case LEFT:
		case RIGHT:
		case NATURAL:
		case INNER:
		case OUTER:
		case FULL:
		case CROSS:
		case SET:
		case VALUES:
		case GROUP:
		case BY:
		case HAVING:
		case ORDER:
		case ASC:
		case DESC:
		case LIMIT:
		case OFFSET:
		case ON:
		case AS:
		case DISTINCT:
		case SHARE:
		case NOWAIT:
		case OF:
		case IN:
		case BETWEEN:
		case IS:
		case BEGIN:
		case PREPARE:
		case TRANSACTION:
		case ISOLATION:
		case LEVEL:
		case COMMIT:
		case PREPARED:
		case END:
		case ROLLBACK:
		case CREATE:
		case DROP:
		case ALTER:
		case TABLE:
		case SQL_DEFAULT:
		case ADD:
		case RENAME:
		case COLUMN:
		case TO:
		case PRIMARY:
		case KEY:
		case UNIQUE:
		case CHECK:
		case RETURNS:
		case SETOF:
		case LANGUAGE:
		case REPLACE:
		case INDEX:
		case USING:
		case EACH:
		case ROW:
		case STATEMENT:
		case EXECUTE:
		case PROCEDURE:
		case EXISTS:
		case TRIGGER:
		case BEFORE:
		case AFTER:
		case FOREIGN:
		case REFERENCES:
		case ADJUST_WHERE:
		case ADJUST_SET:
		case USE:
		case IDENTIFIER:
			{
				exp = expStreamSegment(ctx);
				break ;
			}
		case L_PARENTHESIS:
			{
				exp = expStreamParenthesis(ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,61, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	stream->addSegment(exp, ctx);
	while(true)
	{
		if(jj_2_31((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_27_out_break;
		}
		jj_consume_token(DOT, ctx);
		if(jj_2_32((long long)2, ctx))
		{
			exp2 = functionCallExpression(ctx);
		}
				else 
		{
			if(jj_2_33((long long)2, ctx))
			{
				exp2 = expStreamSegment(ctx);
			}
						else 
			{
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case L_PARENTHESIS:
					{
						exp2 = expStreamCast(ctx);
						break ;
					}
				default:
					jj_la1->set(jj_gen,62, ctx);
					jj_consume_token((long long)-1, ctx);
					throw (new(ctx) ParseException(ctx));
					break;
				}
			}
		}
		stream->addSegment(exp2, ctx);
	}
	label_27_out_break: ;
	if(exp2 == nullptr)
	{
		stream->position(exp, exp, ctx);
	}
		else 
	{
		stream->position(exp, exp2, ctx);
	}
	{
		{
			return stream;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
FunctionCallExpression* AlinousPlusParser::functionCallExpression(ThreadContext* ctx)
{
	Token* body = nullptr;
	FunctionArguments* arguments = nullptr;
	FunctionCallExpression* exp = (new(ctx) FunctionCallExpression(ctx));
	body = nameIdentifier(ctx);
	arguments = functionArguments(ctx);
	exp->position(body, arguments, ctx);
	__GC_MV(exp, &(exp->body), body->image, String);
	exp->setArguments(arguments, ctx);
	{
		{
			return exp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ExpStreamSegment* AlinousPlusParser::expStreamSegment(ThreadContext* ctx)
{
	ExpStreamSegment* expStream = (new(ctx) ExpStreamSegment(ctx));
	Token* t = nullptr;
	Token* pt = nullptr;
	IExpression* arrayIndex = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case DOLLAR:
	case AT_MARK:
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case DOLLAR:
				{
					pt = jj_consume_token(DOLLAR, ctx);
					break ;
				}
			case AT_MARK:
				{
					pt = jj_consume_token(AT_MARK, ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,63, ctx);
				jj_consume_token((long long)-1, ctx);
				throw (new(ctx) ParseException(ctx));
				break;
			}
			break ;
		}
	default:
		jj_la1->set(jj_gen,64, ctx);
		;
		break;
	}
	t = nameIdentifier(ctx);
	if(pt != nullptr)
	{
		expStream->setPrefix(pt->image, ctx);
	}
	expStream->setName(t->image, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case L_BRACKET:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,65, ctx);
			goto label_28_out_break;
		}
		jj_consume_token(L_BRACKET, ctx);
		arrayIndex = conditionalExpression(ctx);
		jj_consume_token(R_BRACKET, ctx);
		expStream->addArrayIndex(arrayIndex, ctx);
	}
	label_28_out_break: ;
	if(arrayIndex == nullptr)
	{
		if(pt != nullptr)
		{
			expStream->position(pt, t, ctx);
		}
				else 
		{
			expStream->position(t, t, ctx);
		}
	}
		else 
	{
		if(pt != nullptr)
		{
			expStream->position(pt, arrayIndex, ctx);
		}
				else 
		{
			expStream->position(t, arrayIndex, ctx);
		}
	}
	{
		{
			return expStream;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ExpStreamCast* AlinousPlusParser::expStreamCast(ThreadContext* ctx)
{
	ExpStreamCast* castExp = (new(ctx) ExpStreamCast(ctx));
	AlinousName* type = nullptr;
	ExpressionStream* exp = nullptr;
	Token* t = nullptr;
	t = jj_consume_token(L_PARENTHESIS, ctx);
	type = alinousName(ctx);
	jj_consume_token(R_PARENTHESIS, ctx);
	exp = expressionStream(ctx);
	castExp->position(t, exp, ctx);
	castExp->setType(type, ctx);
	castExp->setExp(exp, ctx);
	{
		{
			return castExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ExpStreamParenthesis* AlinousPlusParser::expStreamParenthesis(ThreadContext* ctx)
{
	ExpStreamParenthesis* pareExp = (new(ctx) ExpStreamParenthesis(ctx));
	ExpressionStream* exp = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(L_PARENTHESIS, ctx);
	exp = expressionStream(ctx);
	t2 = jj_consume_token(R_PARENTHESIS, ctx);
	pareExp->position(t, t2, ctx);
	pareExp->setExp(exp, ctx);
	{
		{
			return pareExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
PreIncrementExpression* AlinousPlusParser::preIncrementExpression(ThreadContext* ctx)
{
	PreIncrementExpression* preExp = (new(ctx) PreIncrementExpression(ctx));
	IExpression* exp = nullptr;
	Token* t = nullptr;
	t = jj_consume_token(PLUSPLUS, ctx);
	exp = unaryExpression(ctx);
	preExp->position(t, exp, ctx);
	preExp->setExp(exp, ctx);
	{
		{
			return preExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
PreDecrementExpression* AlinousPlusParser::preDecrementExpression(ThreadContext* ctx)
{
	PreDecrementExpression* preExp = (new(ctx) PreDecrementExpression(ctx));
	IExpression* exp = nullptr;
	Token* t = nullptr;
	t = jj_consume_token(MINUSMINUS, ctx);
	exp = unaryExpression(ctx);
	preExp->position(t, exp, ctx);
	preExp->setExp(exp, ctx);
	{
		{
			return preExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
BitReverseExpression* AlinousPlusParser::bitReverseExpression(ThreadContext* ctx)
{
	BitReverseExpression* bitexp = (new(ctx) BitReverseExpression(ctx));
	IExpression* exp = nullptr;
	Token* t = nullptr;
	t = jj_consume_token((long long)196, ctx);
	exp = unaryExpression(ctx);
	bitexp->position(t, exp, ctx);
	bitexp->setExp(exp, ctx);
	{
		{
			return bitexp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
void AlinousPlusParser::parenthesisLookahead(ThreadContext* ctx)
{
	jj_consume_token(L_PARENTHESIS, ctx);
	conditionalExpression(ctx);
	jj_consume_token(R_PARENTHESIS, ctx);
}
ParenthesisExpression* AlinousPlusParser::parenthesisExpression(ThreadContext* ctx)
{
	ParenthesisExpression* parenthesisExp = (new(ctx) ParenthesisExpression(ctx));
	IExpression* exp = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(L_PARENTHESIS, ctx);
	exp = conditionalExpression(ctx);
	t2 = jj_consume_token(R_PARENTHESIS, ctx);
	parenthesisExp->position(t, t2, ctx);
	parenthesisExp->setExp(exp, ctx);
	{
		{
			return parenthesisExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
CastExpression* AlinousPlusParser::castExpression(ThreadContext* ctx)
{
	CastExpression* castExp = (new(ctx) CastExpression(ctx));
	AlinousName* type = nullptr;
	IExpression* exp = nullptr;
	Token* t = nullptr;
	t = jj_consume_token(L_PARENTHESIS, ctx);
	type = alinousName(ctx);
	jj_consume_token(R_PARENTHESIS, ctx);
	exp = conditionalExpression(ctx);
	castExp->position(t, exp, ctx);
	castExp->setType(type, ctx);
	{
		{
			return castExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
FunctionArguments* AlinousPlusParser::functionArguments(ThreadContext* ctx)
{
	FunctionArguments* args = (new(ctx) FunctionArguments(ctx));
	IExpression* exp = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(L_PARENTHESIS, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case INTEGER_LITERAL:
	case FLOATING_POINT_LITERAL:
	case STRING_LITERAL:
	case CHARACTER_LITERAL:
	case SQL_STRING_LITERAL:
	case PLUSPLUS:
	case MINUSMINUS:
	case L_PARENTHESIS:
	case DOLLAR:
	case AT_MARK:
	case NOT:
	case NATIVE:
	case NEW:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case TRUE:
	case FALSE:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case _NULL:
	case USE:
	case IDENTIFIER:
	case 196:
		{
			exp = conditionalExpression(ctx);
			args->addArgument(exp, ctx);
			while(true)
			{
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case COMMA:
					{
						;
						break ;
					}
				default:
					jj_la1->set(jj_gen,66, ctx);
					goto label_29_out_break;
				}
				jj_consume_token(COMMA, ctx);
				exp = conditionalExpression(ctx);
				args->addArgument(exp, ctx);
			}
			label_29_out_break: ;
			break ;
		}
	default:
		jj_la1->set(jj_gen,67, ctx);
		;
		break;
	}
	t2 = jj_consume_token(R_PARENTHESIS, ctx);
	args->position(t, t2, ctx);
	{
		{
			return args;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
Literal* AlinousPlusParser::literal(ThreadContext* ctx)
{
	Literal* lit = nullptr;
	Token* t = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case INTEGER_LITERAL:
		{
			t = jj_consume_token(INTEGER_LITERAL, ctx);
			lit = (new(ctx) Literal(Literal::literalTypes::INTEGER_LITERAL, ctx));
			break ;
		}
	case FLOATING_POINT_LITERAL:
		{
			t = jj_consume_token(FLOATING_POINT_LITERAL, ctx);
			lit = (new(ctx) Literal(Literal::literalTypes::FLOATING_POINT_LITERAL, ctx));
			break ;
		}
	case CHARACTER_LITERAL:
		{
			t = jj_consume_token(CHARACTER_LITERAL, ctx);
			lit = (new(ctx) Literal(Literal::literalTypes::CHARACTER_LITERAL, ctx));
			break ;
		}
	case STRING_LITERAL:
		{
			t = jj_consume_token(STRING_LITERAL, ctx);
			lit = (new(ctx) Literal(Literal::literalTypes::STRING_LITERAL, ctx));
			break ;
		}
	case SQL_STRING_LITERAL:
		{
			t = jj_consume_token(SQL_STRING_LITERAL, ctx);
			lit = (new(ctx) Literal(Literal::literalTypes::SQL_STRING_LITERAL, ctx));
			break ;
		}
	default:
		jj_la1->set(jj_gen,68, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	lit->position(t, t, ctx);
	lit->setValue(t->image, ctx);
	{
		{
			return lit;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
BooleanLiteral* AlinousPlusParser::booleanLiteral(ThreadContext* ctx)
{
	BooleanLiteral* lit = (new(ctx) BooleanLiteral(ctx));
	Token* t = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case TRUE:
		{
			t = jj_consume_token(TRUE, ctx);
			break ;
		}
	case FALSE:
		{
			t = jj_consume_token(FALSE, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,69, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	lit->position(t, t, ctx);
	lit->setValue(t->image, ctx);
	{
		{
			return lit;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
NullLiteral* AlinousPlusParser::nullLiteral(ThreadContext* ctx)
{
	NullLiteral* lit = (new(ctx) NullLiteral(ctx));
	Token* t = nullptr;
	t = jj_consume_token(_NULL, ctx);
	lit->position(t, t, ctx);
	{
		{
			return lit;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
DomVariableDescriptor* AlinousPlusParser::domVariableDescriptor(ThreadContext* ctx)
{
	DomVariableDescriptor* desc = (new(ctx) DomVariableDescriptor(ctx));
	IDomSegment* firstsegment = nullptr;
	IDomSegment* segment = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case DOLLAR:
		{
			t = jj_consume_token(DOLLAR, ctx);
			break ;
		}
	case AT_MARK:
		{
			t = jj_consume_token(AT_MARK, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,70, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	desc->setPrefix(t->image, ctx);
	firstsegment = domNameSegment(ctx);
	desc->addSegment(firstsegment, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case L_BRACKET:
		case DOT:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,71, ctx);
			goto label_30_out_break;
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case DOT:
			{
				t2 = jj_consume_token(DOT, ctx);
				segment = domNameSegment(ctx);
				desc->addSegment(segment, ctx);
				segment->position(t2, segment, ctx);
				break ;
			}
		case L_BRACKET:
			{
				segment = domIndexSegment(ctx);
				desc->markLastSegmentAsArray(ctx);
				desc->addSegment(segment, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,72, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	label_30_out_break: ;
	if(t->image->equals(ConstStr::getCNST_STR_1251(), ctx))
	{
		desc->markLastSegmentAsArray(ctx);
	}
	if(segment == nullptr)
	{
		desc->position(t, firstsegment, ctx);
	}
		else 
	{
		desc->position(t, segment, ctx);
	}
	{
		{
			return desc;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
DomNameSegment* AlinousPlusParser::domNameSegment(ThreadContext* ctx)
{
	DomNameSegment* seg = (new(ctx) DomNameSegment(ctx));
	Token* t = nullptr;
	t = jj_consume_token(IDENTIFIER, ctx);
	seg->setName(t->image, ctx);
	seg->position(t, t, ctx);
	{
		{
			return seg;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
DomIndexSegment* AlinousPlusParser::domIndexSegment(ThreadContext* ctx)
{
	DomIndexSegment* seg = (new(ctx) DomIndexSegment(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	IExpression* exp = nullptr;
	t = jj_consume_token(L_BRACKET, ctx);
	exp = conditionalExpression(ctx);
	t2 = jj_consume_token(R_BRACKET, ctx);
	seg->position(t, t2, ctx);
	seg->setIndex(exp, ctx);
	{
		{
			return seg;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
AlinousName* AlinousPlusParser::alinousName(ThreadContext* ctx)
{
	AlinousName* buff = (new(ctx) AlinousName(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = nameIdentifier(ctx);
	buff->addSegment(t->image, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case DOT:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,73, ctx);
			goto label_31_out_break;
		}
		jj_consume_token(DOT, ctx);
		t2 = nameIdentifier(ctx);
		buff->addSegment(t2->image, ctx);
	}
	label_31_out_break: ;
	if(t2 == nullptr)
	{
		buff->position(t, t, ctx);
	}
		else 
	{
		buff->position(t, t2, ctx);
	}
	{
		{
			return buff;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
Token* AlinousPlusParser::nameIdentifier(ThreadContext* ctx)
{
	Token* t = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case IDENTIFIER:
		{
			t = jj_consume_token(IDENTIFIER, ctx);
			break ;
		}
	case SELECT:
		{
			t = jj_consume_token(SELECT, ctx);
			break ;
		}
	case INSERT:
		{
			t = jj_consume_token(INSERT, ctx);
			break ;
		}
	case UPDATE:
		{
			t = jj_consume_token(UPDATE, ctx);
			break ;
		}
	case DELETE:
		{
			t = jj_consume_token(DELETE, ctx);
			break ;
		}
	case INTO:
		{
			t = jj_consume_token(INTO, ctx);
			break ;
		}
	case FROM:
		{
			t = jj_consume_token(FROM, ctx);
			break ;
		}
	case WHERE:
		{
			t = jj_consume_token(WHERE, ctx);
			break ;
		}
	case OR:
		{
			t = jj_consume_token(OR, ctx);
			break ;
		}
	case SQLAND:
		{
			t = jj_consume_token(SQLAND, ctx);
			break ;
		}
	case LIKE:
		{
			t = jj_consume_token(LIKE, ctx);
			break ;
		}
	case ESCAPE:
		{
			t = jj_consume_token(ESCAPE, ctx);
			break ;
		}
	case LEFT:
		{
			t = jj_consume_token(LEFT, ctx);
			break ;
		}
	case RIGHT:
		{
			t = jj_consume_token(RIGHT, ctx);
			break ;
		}
	case NATURAL:
		{
			t = jj_consume_token(NATURAL, ctx);
			break ;
		}
	case INNER:
		{
			t = jj_consume_token(INNER, ctx);
			break ;
		}
	case OUTER:
		{
			t = jj_consume_token(OUTER, ctx);
			break ;
		}
	case FULL:
		{
			t = jj_consume_token(FULL, ctx);
			break ;
		}
	case CROSS:
		{
			t = jj_consume_token(CROSS, ctx);
			break ;
		}
	case SET:
		{
			t = jj_consume_token(SET, ctx);
			break ;
		}
	case VALUES:
		{
			t = jj_consume_token(VALUES, ctx);
			break ;
		}
	case GROUP:
		{
			t = jj_consume_token(GROUP, ctx);
			break ;
		}
	case BY:
		{
			t = jj_consume_token(BY, ctx);
			break ;
		}
	case HAVING:
		{
			t = jj_consume_token(HAVING, ctx);
			break ;
		}
	case ORDER:
		{
			t = jj_consume_token(ORDER, ctx);
			break ;
		}
	case ASC:
		{
			t = jj_consume_token(ASC, ctx);
			break ;
		}
	case DESC:
		{
			t = jj_consume_token(DESC, ctx);
			break ;
		}
	case LIMIT:
		{
			t = jj_consume_token(LIMIT, ctx);
			break ;
		}
	case OFFSET:
		{
			t = jj_consume_token(OFFSET, ctx);
			break ;
		}
	case ON:
		{
			t = jj_consume_token(ON, ctx);
			break ;
		}
	case NOT:
		{
			t = jj_consume_token(NOT, ctx);
			break ;
		}
	case AS:
		{
			t = jj_consume_token(AS, ctx);
			break ;
		}
	case DISTINCT:
		{
			t = jj_consume_token(DISTINCT, ctx);
			break ;
		}
	case SHARE:
		{
			t = jj_consume_token(SHARE, ctx);
			break ;
		}
	case NOWAIT:
		{
			t = jj_consume_token(NOWAIT, ctx);
			break ;
		}
	case OF:
		{
			t = jj_consume_token(OF, ctx);
			break ;
		}
	case IN:
		{
			t = jj_consume_token(IN, ctx);
			break ;
		}
	case BETWEEN:
		{
			t = jj_consume_token(BETWEEN, ctx);
			break ;
		}
	case IS:
		{
			t = jj_consume_token(IS, ctx);
			break ;
		}
	case BEGIN:
		{
			t = jj_consume_token(BEGIN, ctx);
			break ;
		}
	case PREPARE:
		{
			t = jj_consume_token(PREPARE, ctx);
			break ;
		}
	case TRANSACTION:
		{
			t = jj_consume_token(TRANSACTION, ctx);
			break ;
		}
	case ISOLATION:
		{
			t = jj_consume_token(ISOLATION, ctx);
			break ;
		}
	case LEVEL:
		{
			t = jj_consume_token(LEVEL, ctx);
			break ;
		}
	case COMMIT:
		{
			t = jj_consume_token(COMMIT, ctx);
			break ;
		}
	case PREPARED:
		{
			t = jj_consume_token(PREPARED, ctx);
			break ;
		}
	case END:
		{
			t = jj_consume_token(END, ctx);
			break ;
		}
	case ROLLBACK:
		{
			t = jj_consume_token(ROLLBACK, ctx);
			break ;
		}
	case CREATE:
		{
			t = jj_consume_token(CREATE, ctx);
			break ;
		}
	case DROP:
		{
			t = jj_consume_token(DROP, ctx);
			break ;
		}
	case ALTER:
		{
			t = jj_consume_token(ALTER, ctx);
			break ;
		}
	case TABLE:
		{
			t = jj_consume_token(TABLE, ctx);
			break ;
		}
	case SQL_DEFAULT:
		{
			t = jj_consume_token(SQL_DEFAULT, ctx);
			break ;
		}
	case ADD:
		{
			t = jj_consume_token(ADD, ctx);
			break ;
		}
	case RENAME:
		{
			t = jj_consume_token(RENAME, ctx);
			break ;
		}
	case COLUMN:
		{
			t = jj_consume_token(COLUMN, ctx);
			break ;
		}
	case TO:
		{
			t = jj_consume_token(TO, ctx);
			break ;
		}
	case PRIMARY:
		{
			t = jj_consume_token(PRIMARY, ctx);
			break ;
		}
	case KEY:
		{
			t = jj_consume_token(KEY, ctx);
			break ;
		}
	case UNIQUE:
		{
			t = jj_consume_token(UNIQUE, ctx);
			break ;
		}
	case CHECK:
		{
			t = jj_consume_token(CHECK, ctx);
			break ;
		}
	case RETURNS:
		{
			t = jj_consume_token(RETURNS, ctx);
			break ;
		}
	case SETOF:
		{
			t = jj_consume_token(SETOF, ctx);
			break ;
		}
	case LANGUAGE:
		{
			t = jj_consume_token(LANGUAGE, ctx);
			break ;
		}
	case REPLACE:
		{
			t = jj_consume_token(REPLACE, ctx);
			break ;
		}
	case INDEX:
		{
			t = jj_consume_token(INDEX, ctx);
			break ;
		}
	case USING:
		{
			t = jj_consume_token(USING, ctx);
			break ;
		}
	case EACH:
		{
			t = jj_consume_token(EACH, ctx);
			break ;
		}
	case ROW:
		{
			t = jj_consume_token(ROW, ctx);
			break ;
		}
	case STATEMENT:
		{
			t = jj_consume_token(STATEMENT, ctx);
			break ;
		}
	case EXECUTE:
		{
			t = jj_consume_token(EXECUTE, ctx);
			break ;
		}
	case PROCEDURE:
		{
			t = jj_consume_token(PROCEDURE, ctx);
			break ;
		}
	case EXISTS:
		{
			t = jj_consume_token(EXISTS, ctx);
			break ;
		}
	case TRIGGER:
		{
			t = jj_consume_token(TRIGGER, ctx);
			break ;
		}
	case BEFORE:
		{
			t = jj_consume_token(BEFORE, ctx);
			break ;
		}
	case AFTER:
		{
			t = jj_consume_token(AFTER, ctx);
			break ;
		}
	case FOREIGN:
		{
			t = jj_consume_token(FOREIGN, ctx);
			break ;
		}
	case REFERENCES:
		{
			t = jj_consume_token(REFERENCES, ctx);
			break ;
		}
	case ADJUST_WHERE:
		{
			t = jj_consume_token(ADJUST_WHERE, ctx);
			break ;
		}
	case ADJUST_SET:
		{
			t = jj_consume_token(ADJUST_SET, ctx);
			break ;
		}
	case USE:
		{
			t = jj_consume_token(USE, ctx);
			break ;
		}
	case VOID:
		{
			t = jj_consume_token(VOID, ctx);
			break ;
		}
	case DOWNLOAD:
		{
			t = jj_consume_token(DOWNLOAD, ctx);
			break ;
		}
	case REDIRECT:
		{
			t = jj_consume_token(REDIRECT, ctx);
			break ;
		}
	case LOCAL:
		{
			t = jj_consume_token(LOCAL, ctx);
			break ;
		}
	case VALIDATOR:
		{
			t = jj_consume_token(VALIDATOR, ctx);
			break ;
		}
	case REFERER_FROM:
		{
			t = jj_consume_token(REFERER_FROM, ctx);
			break ;
		}
	case NATIVE:
		{
			t = jj_consume_token(NATIVE, ctx);
			break ;
		}
	case THIS:
		{
			t = jj_consume_token(THIS, ctx);
			break ;
		}
	case SUPER:
		{
			t = jj_consume_token(SUPER, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,74, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	{
		{
			return t;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
Token* AlinousPlusParser::assignmentOperator(ThreadContext* ctx)
{
	Token* t = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case EQUALS:
		{
			t = jj_consume_token(EQUALS, ctx);
			break ;
		}
	case 197:
		{
			t = jj_consume_token((long long)197, ctx);
			break ;
		}
	case 198:
		{
			t = jj_consume_token((long long)198, ctx);
			break ;
		}
	case 199:
		{
			t = jj_consume_token((long long)199, ctx);
			break ;
		}
	case 200:
		{
			t = jj_consume_token((long long)200, ctx);
			break ;
		}
	case 201:
		{
			t = jj_consume_token((long long)201, ctx);
			break ;
		}
	case 202:
		{
			t = jj_consume_token((long long)202, ctx);
			break ;
		}
	case 203:
		{
			t = jj_consume_token((long long)203, ctx);
			break ;
		}
	case 204:
		{
			t = jj_consume_token((long long)204, ctx);
			break ;
		}
	case 205:
		{
			t = jj_consume_token((long long)205, ctx);
			break ;
		}
	case 206:
		{
			t = jj_consume_token((long long)206, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,75, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	{
		{
			return t;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISqlStatement* AlinousPlusParser::sqlStatement(ThreadContext* ctx)
{
	ISqlStatement* stmt = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case SELECT:
		{
			stmt = selectStatement(ctx);
			break ;
		}
	case INSERT:
		{
			stmt = insertStatement(ctx);
			break ;
		}
	case UPDATE:
		{
			stmt = updateStatement(ctx);
			break ;
		}
	case DELETE:
		{
			stmt = deleteStatement(ctx);
			break ;
		}
	case BEGIN:
		{
			stmt = beginStatement(ctx);
			break ;
		}
	case COMMIT:
		{
			stmt = commitStatement(ctx);
			break ;
		}
	case ROLLBACK:
		{
			stmt = rollbackStatement(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,76, ctx);
		if(jj_2_34((long long)2, ctx))
		{
			stmt = createTableStatement(ctx);
		}
				else 
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case CREATE:
				{
					stmt = createIndexStatement(ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,77, ctx);
				if(jj_2_35((long long)2, ctx))
				{
					stmt = dropTableStatement(ctx);
				}
								else 
				{
					switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
					case DROP:
						{
							stmt = dropIndexStatement(ctx);
							break ;
						}
					default:
						jj_la1->set(jj_gen,78, ctx);
						jj_consume_token((long long)-1, ctx);
						throw (new(ctx) ParseException(ctx));
						break;
					}
				}
				break;
			}
		}
		break;
	}
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SelectStatement* AlinousPlusParser::selectStatement(ThreadContext* ctx)
{
	SelectStatement* stmt = (new(ctx) SelectStatement(ctx));
	Token* t = nullptr;
	SQLExpressionList* list = nullptr;
	SQLFrom* frm = nullptr;
	SQLWhere* wh = nullptr;
	SQLGroupBy* groupBy = nullptr;
	SQLLimitOffset* limitOffset = nullptr;
	Token* t2 = nullptr;
	AlinousName* into = nullptr;
	t = jj_consume_token(SELECT, ctx);
	list = sqlExpressionList(ctx);
	stmt->setList(list, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case INTO:
		{
			jj_consume_token(INTO, ctx);
			into = alinousName(ctx);
			stmt->setInto(into, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,79, ctx);
		;
		break;
	}
	frm = sqlFrom(ctx);
	stmt->setFrom(frm, ctx);
	if(jj_2_36((long long)2, ctx))
	{
		wh = sqlWhere(ctx);
		stmt->setWhere(wh, ctx);
	}
		else 
	{
		;
	}
	if(jj_2_37((long long)2, ctx))
	{
		groupBy = sqlGroupBy(ctx);
		stmt->setGroupBy(groupBy, ctx);
	}
		else 
	{
		;
	}
	limitOffset = sqlLimitOffset(ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->setLimitOffset(limitOffset, ctx);
	stmt->position(t, t2, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SQLFrom* AlinousPlusParser::sqlFrom(ThreadContext* ctx)
{
	SQLFrom* from = (new(ctx) SQLFrom(ctx));
	IJoin* join = nullptr;
	Token* t = nullptr;
	t = jj_consume_token(FROM, ctx);
	join = sqlJoin(ctx);
	from->position(t, join, ctx);
	from->setJoin(join, ctx);
	{
		{
			return from;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IJoin* AlinousPlusParser::sqlJoin(ThreadContext* ctx)
{
	AbstractSQLJoin* join = nullptr;
	IJoin* left = nullptr;
	IJoin* right = nullptr;
	SQLJoinCondition* cnd = nullptr;
	TableList* list = nullptr;
	Token* t = nullptr;
	left = joinTarget(ctx);
	if(jj_2_42((long long)2, ctx))
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case INNER:
			{
				t = jj_consume_token(INNER, ctx);
				jj_consume_token(JOIN, ctx);
				right = joinTarget(ctx);
				if(jj_2_38((long long)2, ctx))
				{
					cnd = sqlJoinCondition(ctx);
				}
								else 
				{
					;
				}
				join = (new(ctx) InnerJoin(ctx));
				join->setLeft(right, ctx);
				join->setRight(left, ctx);
				if(cnd != nullptr)
				{
					join->setCondition(cnd, ctx);
				}
				break ;
			}
		case JOIN:
			{
				t = jj_consume_token(JOIN, ctx);
				right = joinTarget(ctx);
				cnd = sqlJoinCondition(ctx);
				join = (new(ctx) CrossJoin(ctx));
				join->setLeft(left, ctx);
				join->setRight(right, ctx);
				if(cnd != nullptr)
				{
					join->setCondition(cnd, ctx);
				}
				break ;
			}
		case LEFT:
			{
				t = jj_consume_token(LEFT, ctx);
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case OUTER:
					{
						jj_consume_token(OUTER, ctx);
						break ;
					}
				default:
					jj_la1->set(jj_gen,80, ctx);
					;
					break;
				}
				jj_consume_token(JOIN, ctx);
				right = joinTarget(ctx);
				if(jj_2_39((long long)2, ctx))
				{
					cnd = sqlJoinCondition(ctx);
				}
								else 
				{
					;
				}
				join = (new(ctx) LeftJoin(ctx));
				join->setLeft(left, ctx);
				join->setRight(right, ctx);
				if(cnd != nullptr)
				{
					join->setCondition(cnd, ctx);
				}
				break ;
			}
		case RIGHT:
			{
				t = jj_consume_token(RIGHT, ctx);
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case OUTER:
					{
						jj_consume_token(OUTER, ctx);
						break ;
					}
				default:
					jj_la1->set(jj_gen,81, ctx);
					;
					break;
				}
				jj_consume_token(JOIN, ctx);
				right = joinTarget(ctx);
				if(jj_2_40((long long)2, ctx))
				{
					cnd = sqlJoinCondition(ctx);
				}
								else 
				{
					;
				}
				join = (new(ctx) RightJoin(ctx));
				join->setLeft(left, ctx);
				join->setRight(right, ctx);
				if(cnd != nullptr)
				{
					join->setCondition(cnd, ctx);
				}
				break ;
			}
		case NATURAL:
			{
				t = jj_consume_token(NATURAL, ctx);
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case LEFT:
				case RIGHT:
					{
						switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
						case RIGHT:
							{
								jj_consume_token(RIGHT, ctx);
								break ;
							}
						case LEFT:
							{
								jj_consume_token(LEFT, ctx);
								break ;
							}
						default:
							jj_la1->set(jj_gen,82, ctx);
							jj_consume_token((long long)-1, ctx);
							throw (new(ctx) ParseException(ctx));
							break;
						}
						switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
						case OUTER:
							{
								jj_consume_token(OUTER, ctx);
								break ;
							}
						default:
							jj_la1->set(jj_gen,83, ctx);
							;
							break;
						}
						break ;
					}
				default:
					jj_la1->set(jj_gen,84, ctx);
					;
					break;
				}
				jj_consume_token(JOIN, ctx);
				right = joinTarget(ctx);
				join = (new(ctx) NaturalJoin(ctx));
				join->setLeft(left, ctx);
				join->setRight(right, ctx);
				break ;
			}
		case CROSS:
			{
				t = jj_consume_token(CROSS, ctx);
				jj_consume_token(JOIN, ctx);
				right = joinTarget(ctx);
				if(jj_2_41((long long)2, ctx))
				{
					cnd = sqlJoinCondition(ctx);
				}
								else 
				{
					;
				}
				join = (new(ctx) CrossJoin(ctx));
				join->setLeft(left, ctx);
				join->setRight(right, ctx);
				if(cnd != nullptr)
				{
					join->setCondition(cnd, ctx);
				}
				break ;
			}
		case COMMA:
			{
				while(true)
				{
					t = jj_consume_token(COMMA, ctx);
					right = joinTarget(ctx);
					if(list == nullptr)
					{
						list = (new(ctx) TableList(ctx));
						list->addJoinTarget(left, ctx);
					}
					list->addJoinTarget(right, ctx);
					switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
					case COMMA:
						{
							;
							break ;
						}
					default:
						jj_la1->set(jj_gen,85, ctx);
						goto label_32_out_break;
					}
				}
				label_32_out_break: ;
				list->position(left, right, ctx);
				{
					{
						return list;
					}
				}
				break ;
			}
		default:
			jj_la1->set(jj_gen,86, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
		else 
	{
		;
	}
	if(t == nullptr)
	{
		{
			{
				return left;
			}
		}
	}
	if(cnd == nullptr)
	{
		join->position(left, right, ctx);
	}
		else 
	{
		join->position(left, cnd, ctx);
	}
	{
		{
			return join;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SQLJoinCondition* AlinousPlusParser::sqlJoinCondition(ThreadContext* ctx)
{
	SQLJoinCondition* joinCond = (new(ctx) SQLJoinCondition(ctx));
	ISQLExpression* cond = nullptr;
	Token* t = nullptr;
	t = jj_consume_token(ON, ctx);
	cond = sqlOrExpression(ctx);
	joinCond->position(t, cond, ctx);
	joinCond->setCondition(cond, ctx);
	{
		{
			return joinCond;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IJoin* AlinousPlusParser::joinTarget(ThreadContext* ctx)
{
	IJoin* target = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case NOT:
	case NATIVE:
	case SUPER:
	case THIS:
	case VOID:
	case DOWNLOAD:
	case REDIRECT:
	case REFERER_FROM:
	case VALIDATOR:
	case LOCAL:
	case SELECT:
	case INSERT:
	case UPDATE:
	case DELETE:
	case INTO:
	case FROM:
	case WHERE:
	case OR:
	case SQLAND:
	case LIKE:
	case ESCAPE:
	case LEFT:
	case RIGHT:
	case NATURAL:
	case INNER:
	case OUTER:
	case FULL:
	case CROSS:
	case SET:
	case VALUES:
	case GROUP:
	case BY:
	case HAVING:
	case ORDER:
	case ASC:
	case DESC:
	case LIMIT:
	case OFFSET:
	case ON:
	case AS:
	case DISTINCT:
	case SHARE:
	case NOWAIT:
	case OF:
	case IN:
	case BETWEEN:
	case IS:
	case BEGIN:
	case PREPARE:
	case TRANSACTION:
	case ISOLATION:
	case LEVEL:
	case COMMIT:
	case PREPARED:
	case END:
	case ROLLBACK:
	case CREATE:
	case DROP:
	case ALTER:
	case TABLE:
	case SQL_DEFAULT:
	case ADD:
	case RENAME:
	case COLUMN:
	case TO:
	case PRIMARY:
	case KEY:
	case UNIQUE:
	case CHECK:
	case RETURNS:
	case SETOF:
	case LANGUAGE:
	case REPLACE:
	case INDEX:
	case USING:
	case EACH:
	case ROW:
	case STATEMENT:
	case EXECUTE:
	case PROCEDURE:
	case EXISTS:
	case TRIGGER:
	case BEFORE:
	case AFTER:
	case FOREIGN:
	case REFERENCES:
	case ADJUST_WHERE:
	case ADJUST_SET:
	case USE:
	case IDENTIFIER:
		{
			target = tableJoinTarget(ctx);
			break ;
		}
	case DOLLAR:
	case AT_MARK:
		{
			target = domVariableJoinTarget(ctx);
			break ;
		}
	case L_PARENTHESIS:
		{
			t = jj_consume_token(L_PARENTHESIS, ctx);
			target = sqlJoin(ctx);
			t2 = jj_consume_token(R_PARENTHESIS, ctx);
			WrappedJoinTarget* wj = (new(ctx) WrappedJoinTarget(ctx));
			wj->position(t, t2, ctx);
			wj->setJoin(target, ctx);
			{
				{
					return wj;
				}
			}
			break ;
		}
	default:
		jj_la1->set(jj_gen,87, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	{
		{
			return target;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IJoinTarget* AlinousPlusParser::tableJoinTarget(ThreadContext* ctx)
{
	TableJoinTarget* table = (new(ctx) TableJoinTarget(ctx));
	AlinousName* name = nullptr;
	Token* t = nullptr;
	name = alinousName(ctx);
	if(jj_2_43((long long)2, ctx))
	{
		jj_consume_token(AS, ctx);
		t = jj_consume_token(IDENTIFIER, ctx);
	}
		else 
	{
		;
	}
	if(t != nullptr)
	{
		table->position(name, t, ctx);
		table->setAsName(t->image, ctx);
		table->setName(name, ctx);
	}
		else 
	{
		table->position(name, name, ctx);
		table->setName(name, ctx);
	}
	{
		{
			return table;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IJoinTarget* AlinousPlusParser::domVariableJoinTarget(ThreadContext* ctx)
{
	DomVariableJoinTarget* dom = (new(ctx) DomVariableJoinTarget(ctx));
	DomVariableDescriptor* domDesc = nullptr;
	Token* t = nullptr;
	domDesc = domVariableDescriptor(ctx);
	if(jj_2_44((long long)2, ctx))
	{
		jj_consume_token(AS, ctx);
		t = jj_consume_token(IDENTIFIER, ctx);
	}
		else 
	{
		;
	}
	if(t != nullptr)
	{
		dom->position(domDesc, domDesc, ctx);
		dom->setAsName(t->image, ctx);
		dom->setDomDesc(domDesc, ctx);
	}
		else 
	{
		dom->position(domDesc, domDesc, ctx);
		dom->setDomDesc(domDesc, ctx);
	}
	{
		{
			return dom;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
IJoinTarget* AlinousPlusParser::joinSubQueryTarget(ThreadContext* ctx)
{
	JoinSubQueryTarget* target = (new(ctx) JoinSubQueryTarget(ctx));
	SelectStatement* selectStmt = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(L_PARENTHESIS, ctx);
	selectStmt = selectStatement(ctx);
	jj_consume_token(R_PARENTHESIS, ctx);
	jj_consume_token(AS, ctx);
	t2 = jj_consume_token(IDENTIFIER, ctx);
	target->position(t, t2, ctx);
	target->setSelectStatement(selectStmt, ctx);
	target->setAsName(t->image, ctx);
	{
		{
			return target;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SQLWhere* AlinousPlusParser::sqlWhere(ThreadContext* ctx)
{
	SQLWhere* wh = (new(ctx) SQLWhere(ctx));
	Token* t = nullptr;
	ISQLExpression* cond = nullptr;
	t = jj_consume_token(WHERE, ctx);
	cond = sqlOrExpression(ctx);
	wh->position(t, cond, ctx);
	wh->setCondition(cond, ctx);
	{
		{
			return wh;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SQLGroupBy* AlinousPlusParser::sqlGroupBy(ThreadContext* ctx)
{
	SQLGroupBy* gby = (new(ctx) SQLGroupBy(ctx));
	SQLExpressionList* list = nullptr;
	ISQLExpression* cond = nullptr;
	Token* t = nullptr;
	IAlinousElement* last = nullptr;
	t = jj_consume_token(GROUP, ctx);
	jj_consume_token(BY, ctx);
	list = sqlExpressionList(ctx);
	gby->setGroupList(list, ctx);
	last = list;
	if(jj_2_45((long long)2, ctx))
	{
		jj_consume_token(HAVING, ctx);
		cond = sqlOrExpression(ctx);
		gby->setHavingCondition(cond, ctx);
		last = cond;
	}
		else 
	{
		;
	}
	gby->position(t, last, ctx);
	{
		{
			return gby;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SQLLimitOffset* AlinousPlusParser::sqlLimitOffset(ThreadContext* ctx)
{
	SQLLimitOffset* lim = (new(ctx) SQLLimitOffset(ctx));
	ISQLExpression* limit = nullptr;
	ISQLExpression* offset = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	ISQLExpression* last = nullptr;
	if(jj_2_46((long long)2, ctx))
	{
		t = jj_consume_token(LIMIT, ctx);
		limit = sqlAdditiveExpression(ctx);
		lim->setLimit(limit, ctx);
		last = limit;
	}
		else 
	{
		;
	}
	if(jj_2_47((long long)2, ctx))
	{
		t2 = jj_consume_token(OFFSET, ctx);
		offset = sqlAdditiveExpression(ctx);
		lim->setOffset(offset, ctx);
		last = offset;
	}
		else 
	{
		;
	}
	if(t == nullptr && t2 == nullptr)
	{
		{
			{
				return lim;
			}
		}
	}
	t = t == nullptr ? t2 : t;
	lim->position(t, last, ctx);
	{
		{
			return lim;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
InsertStatement* AlinousPlusParser::insertStatement(ThreadContext* ctx)
{
	InsertStatement* stmt = (new(ctx) InsertStatement(ctx));
	IJoinTarget* table = nullptr;
	SQLExpressionList* list = nullptr;
	InsertValues* values = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(INSERT, ctx);
	jj_consume_token(INTO, ctx);
	table = tableJoinTarget(ctx);
	stmt->setTable(table, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case L_PARENTHESIS:
		{
			jj_consume_token(L_PARENTHESIS, ctx);
			list = sqlExpressionList(ctx);
			jj_consume_token(R_PARENTHESIS, ctx);
			stmt->setList(list, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,88, ctx);
		;
		break;
	}
	jj_consume_token(VALUES, ctx);
	values = insertValues(ctx);
	stmt->addValue(values, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case COMMA:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,89, ctx);
			goto label_33_out_break;
		}
		jj_consume_token(COMMA, ctx);
		values = insertValues(ctx);
		stmt->addValue(values, ctx);
	}
	label_33_out_break: ;
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(t, t2, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
InsertValues* AlinousPlusParser::insertValues(ThreadContext* ctx)
{
	InsertValues* values = (new(ctx) InsertValues(ctx));
	SQLExpressionList* vlist = nullptr;
	SQLExpressionStream* domDesc = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	if(jj_2_48((long long)3, ctx))
	{
		t = jj_consume_token(L_PARENTHESIS, ctx);
		vlist = sqlExpressionList(ctx);
		t2 = jj_consume_token(R_PARENTHESIS, ctx);
		values->position(t, t2, ctx);
		values->setVlist(vlist, ctx);
		{
			{
				return values;
			}
		}
	}
		else 
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case L_PARENTHESIS:
		case DOLLAR:
		case AT_MARK:
		case NOT:
		case NATIVE:
		case SUPER:
		case THIS:
		case VOID:
		case DOWNLOAD:
		case REDIRECT:
		case REFERER_FROM:
		case VALIDATOR:
		case LOCAL:
		case SELECT:
		case INSERT:
		case UPDATE:
		case DELETE:
		case INTO:
		case FROM:
		case WHERE:
		case OR:
		case SQLAND:
		case LIKE:
		case ESCAPE:
		case LEFT:
		case RIGHT:
		case NATURAL:
		case INNER:
		case OUTER:
		case FULL:
		case CROSS:
		case SET:
		case VALUES:
		case GROUP:
		case BY:
		case HAVING:
		case ORDER:
		case ASC:
		case DESC:
		case LIMIT:
		case OFFSET:
		case ON:
		case AS:
		case DISTINCT:
		case SHARE:
		case NOWAIT:
		case OF:
		case IN:
		case BETWEEN:
		case IS:
		case BEGIN:
		case PREPARE:
		case TRANSACTION:
		case ISOLATION:
		case LEVEL:
		case COMMIT:
		case PREPARED:
		case END:
		case ROLLBACK:
		case CREATE:
		case DROP:
		case ALTER:
		case TABLE:
		case SQL_DEFAULT:
		case ADD:
		case RENAME:
		case COLUMN:
		case TO:
		case PRIMARY:
		case KEY:
		case UNIQUE:
		case CHECK:
		case RETURNS:
		case SETOF:
		case LANGUAGE:
		case REPLACE:
		case INDEX:
		case USING:
		case EACH:
		case ROW:
		case STATEMENT:
		case EXECUTE:
		case PROCEDURE:
		case EXISTS:
		case TRIGGER:
		case BEFORE:
		case AFTER:
		case FOREIGN:
		case REFERENCES:
		case ADJUST_WHERE:
		case ADJUST_SET:
		case USE:
		case IDENTIFIER:
			{
				domDesc = sqlExpressionStream(ctx);
				values->position(domDesc, domDesc, ctx);
				values->setDomDesc(domDesc, ctx);
				{
					{
						return values;
					}
				}
				break ;
			}
		default:
			jj_la1->set(jj_gen,90, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
UpdateStatement* AlinousPlusParser::updateStatement(ThreadContext* ctx)
{
	UpdateStatement* stmt = (new(ctx) UpdateStatement(ctx));
	IJoinTarget* table = nullptr;
	UpdateSet* updset = nullptr;
	SQLWhere* wh = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(UPDATE, ctx);
	table = tableJoinTarget(ctx);
	stmt->setTable(table, ctx);
	jj_consume_token(SET, ctx);
	updset = updateSet(ctx);
	stmt->addUpdateSet(updset, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case COMMA:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,91, ctx);
			goto label_34_out_break;
		}
		jj_consume_token(COMMA, ctx);
		updset = updateSet(ctx);
		stmt->addUpdateSet(updset, ctx);
	}
	label_34_out_break: ;
	if(jj_2_49((long long)2, ctx))
	{
		wh = sqlWhere(ctx);
		stmt->setWhere(wh, ctx);
	}
		else 
	{
		;
	}
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(t, t2, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
UpdateSet* AlinousPlusParser::updateSet(ThreadContext* ctx)
{
	UpdateSet* updateSet = (new(ctx) UpdateSet(ctx));
	AlinousName* name = nullptr;
	ISQLExpression* value = nullptr;
	name = alinousName(ctx);
	jj_consume_token(EQUALS, ctx);
	value = sqlAdditiveExpression(ctx);
	updateSet->position(name, value, ctx);
	updateSet->setName(name, ctx);
	updateSet->setValue(value, ctx);
	{
		{
			return updateSet;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
DeleteStatement* AlinousPlusParser::deleteStatement(ThreadContext* ctx)
{
	DeleteStatement* stmt = (new(ctx) DeleteStatement(ctx));
	IJoinTarget* table = nullptr;
	SQLWhere* wh = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(DELETE, ctx);
	jj_consume_token(FROM, ctx);
	table = tableJoinTarget(ctx);
	stmt->setTable(table, ctx);
	if(jj_2_50((long long)2, ctx))
	{
		wh = sqlWhere(ctx);
		stmt->setWhere(wh, ctx);
	}
		else 
	{
		;
	}
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(t, t2, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
BeginStatement* AlinousPlusParser::beginStatement(ThreadContext* ctx)
{
	BeginStatement* stmt = (new(ctx) BeginStatement(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(BEGIN, ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(t, t2, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
CommitStatement* AlinousPlusParser::commitStatement(ThreadContext* ctx)
{
	CommitStatement* stmt = (new(ctx) CommitStatement(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(COMMIT, ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(t, t2, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
RollbackStatement* AlinousPlusParser::rollbackStatement(ThreadContext* ctx)
{
	RollbackStatement* stmt = (new(ctx) RollbackStatement(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(ROLLBACK, ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(t, t2, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
CreateTableStatement* AlinousPlusParser::createTableStatement(ThreadContext* ctx)
{
	CreateTableStatement* stmt = (new(ctx) CreateTableStatement(ctx));
	IJoinTarget* table = nullptr;
	DdlColumnDescriptor* desc = nullptr;
	Unique* unq = nullptr;
	PrimaryKeys* keys = nullptr;
	CheckDefinition* chk = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(CREATE, ctx);
	jj_consume_token(TABLE, ctx);
	table = tableJoinTarget(ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	desc = ddlColumnDescriptor(ctx);
	stmt->addColumn(desc, ctx);
	while(true)
	{
		if(jj_2_51((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_35_out_break;
		}
		jj_consume_token(COMMA, ctx);
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case IDENTIFIER:
			{
				desc = ddlColumnDescriptor(ctx);
				stmt->addColumn(desc, ctx);
				break ;
			}
		case CHECK:
			{
				chk = check(ctx);
				stmt->addCheckDef(chk, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,92, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	label_35_out_break: ;
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case COMMA:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,93, ctx);
			goto label_36_out_break;
		}
		jj_consume_token(COMMA, ctx);
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case PRIMARY:
			{
				keys = primaryKeys(ctx);
				stmt->setPrimaryKeys(keys, ctx);
				break ;
			}
		case UNIQUE:
			{
				unq = unique(ctx);
				stmt->addUnique(unq, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,94, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	label_36_out_break: ;
	jj_consume_token(R_PARENTHESIS, ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(t, t2, ctx);
	stmt->setTable(table, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
PrimaryKeys* AlinousPlusParser::primaryKeys(ThreadContext* ctx)
{
	PrimaryKeys* primaryKeys = (new(ctx) PrimaryKeys(ctx));
	Token* t = nullptr;
	Token* t1 = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(PRIMARY, ctx);
	jj_consume_token(KEY, ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	t1 = jj_consume_token(IDENTIFIER, ctx);
	primaryKeys->addKey(t1->image, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case COMMA:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,95, ctx);
			goto label_37_out_break;
		}
		jj_consume_token(COMMA, ctx);
		t1 = jj_consume_token(IDENTIFIER, ctx);
		primaryKeys->addKey(t1->image, ctx);
	}
	label_37_out_break: ;
	t2 = jj_consume_token(R_PARENTHESIS, ctx);
	primaryKeys->position(t, t2, ctx);
	{
		{
			return primaryKeys;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
Unique* AlinousPlusParser::unique(ThreadContext* ctx)
{
	Unique* unq = (new(ctx) Unique(ctx));
	Token* t = nullptr;
	Token* t1 = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(UNIQUE, ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	t1 = jj_consume_token(IDENTIFIER, ctx);
	unq->addKey(t1->image, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case COMMA:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,96, ctx);
			goto label_38_out_break;
		}
		jj_consume_token(COMMA, ctx);
		t1 = jj_consume_token(IDENTIFIER, ctx);
		unq->addKey(t1->image, ctx);
	}
	label_38_out_break: ;
	t2 = jj_consume_token(R_PARENTHESIS, ctx);
	unq->position(t, t2, ctx);
	{
		{
			return unq;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
DdlColumnDescriptor* AlinousPlusParser::ddlColumnDescriptor(ThreadContext* ctx)
{
	DdlColumnDescriptor* desc = (new(ctx) DdlColumnDescriptor(ctx));
	ColumnTypeDescriptor* typeDesc = nullptr;
	Token* t1 = nullptr;
	Token* tuni = nullptr;
	Token* notnull = nullptr;
	ISQLExpression* defaultVal = nullptr;
	CheckDefinition* chk = nullptr;
	t1 = jj_consume_token(IDENTIFIER, ctx);
	typeDesc = columnTypeDescriptor(ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case SQL_NOT:
		case SQL_DEFAULT:
		case UNIQUE:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,97, ctx);
			goto label_39_out_break;
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case SQL_NOT:
			{
				notnull = jj_consume_token(SQL_NOT, ctx);
				jj_consume_token(_NULL, ctx);
				break ;
			}
		case UNIQUE:
			{
				tuni = jj_consume_token(UNIQUE, ctx);
				break ;
			}
		case SQL_DEFAULT:
			{
				jj_consume_token(SQL_DEFAULT, ctx);
				defaultVal = sqlAdditiveExpression(ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,98, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	label_39_out_break: ;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case CHECK:
		{
			chk = check(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,99, ctx);
		;
		break;
	}
	desc->position(t1, typeDesc, ctx);
	desc->setName(t1->image, ctx);
	desc->setTypeDescriptor(typeDesc, ctx);
	if(defaultVal != nullptr)
	{
		desc->setDefaultValue(defaultVal, ctx);
		desc->endPosition(defaultVal, ctx);
	}
	if(notnull != nullptr)
	{
		desc->setNotnull(true, ctx);
		desc->endPosition(notnull, ctx);
	}
	if(tuni != nullptr)
	{
		desc->setUnique(true, ctx);
		desc->endPosition(tuni, ctx);
	}
	if(chk != nullptr)
	{
		desc->setCheck(chk, ctx);
		desc->endPosition(chk, ctx);
	}
	{
		{
			return desc;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ColumnTypeDescriptor* AlinousPlusParser::columnTypeDescriptor(ThreadContext* ctx)
{
	ColumnTypeDescriptor* typeDesc = (new(ctx) ColumnTypeDescriptor(ctx));
	ISQLExpression* val = nullptr;
	Token* t1 = nullptr;
	Token* t2 = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case IDENTIFIER:
		{
			t1 = jj_consume_token(IDENTIFIER, ctx);
			break ;
		}
	case TRIGGER:
		{
			t1 = jj_consume_token(TRIGGER, ctx);
			break ;
		}
	case BOOL:
		{
			t1 = jj_consume_token(BOOL, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,100, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case L_PARENTHESIS:
		{
			jj_consume_token(L_PARENTHESIS, ctx);
			val = sqlAdditiveExpression(ctx);
			t2 = jj_consume_token(R_PARENTHESIS, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,101, ctx);
		;
		break;
	}
	if(val != nullptr)
	{
		typeDesc->position(t1, t2, ctx);
		typeDesc->setLength(val, ctx);
	}
		else 
	{
		typeDesc->position(t1, t1, ctx);
	}
	typeDesc->setTypeName(t1->image, ctx);
	{
		{
			return typeDesc;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
CheckDefinition* AlinousPlusParser::check(ThreadContext* ctx)
{
	CheckDefinition* check = (new(ctx) CheckDefinition(ctx));
	ISQLExpression* exp = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(CHECK, ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	exp = sqlOrExpression(ctx);
	check->setExp(exp, ctx);
	t2 = jj_consume_token(R_PARENTHESIS, ctx);
	check->position(t, t2, ctx);
	{
		{
			return check;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
DropTableStatement* AlinousPlusParser::dropTableStatement(ThreadContext* ctx)
{
	DropTableStatement* stmt = (new(ctx) DropTableStatement(ctx));
	IJoinTarget* table = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(DROP, ctx);
	jj_consume_token(TABLE, ctx);
	table = tableJoinTarget(ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->position(t, t2, ctx);
	stmt->setTable(table, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
CreateIndexStatement* AlinousPlusParser::createIndexStatement(ThreadContext* ctx)
{
	CreateIndexStatement* stmt = (new(ctx) CreateIndexStatement(ctx));
	IJoinTarget* name = nullptr;
	IJoinTarget* table = nullptr;
	Token* column = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(CREATE, ctx);
	jj_consume_token(INDEX, ctx);
	name = tableJoinTarget(ctx);
	jj_consume_token(ON, ctx);
	table = tableJoinTarget(ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	column = nameIdentifier(ctx);
	stmt->addColumn(column->image, ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case COMMA:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,102, ctx);
			goto label_40_out_break;
		}
		jj_consume_token(COMMA, ctx);
		column = nameIdentifier(ctx);
		stmt->addColumn(column->image, ctx);
	}
	label_40_out_break: ;
	jj_consume_token(R_PARENTHESIS, ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->setName(name, ctx);
	stmt->setTable(table, ctx);
	stmt->position(t, t2, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
DropIndexStatement* AlinousPlusParser::dropIndexStatement(ThreadContext* ctx)
{
	DropIndexStatement* stmt = (new(ctx) DropIndexStatement(ctx));
	IJoinTarget* indexName = nullptr;
	Token* t = nullptr;
	Token* t2 = nullptr;
	t = jj_consume_token(DROP, ctx);
	jj_consume_token(INDEX, ctx);
	indexName = tableJoinTarget(ctx);
	t2 = jj_consume_token(SEMI_COLON, ctx);
	stmt->setIndexName(indexName, ctx);
	stmt->position(t, t2, ctx);
	{
		{
			return stmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlOrExpression(ThreadContext* ctx)
{
	SQLOrExpression* orExp = nullptr;
	ISQLExpression* first = nullptr;
	ISQLExpression* exp = nullptr;
	Token* t = nullptr;
	SQLBoolSubExpression* sub = nullptr;
	first = sqlAndExpression(ctx);
	while(true)
	{
		if(jj_2_52((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_41_out_break;
		}
		t = jj_consume_token(OR, ctx);
		exp = sqlAndExpression(ctx);
		if(orExp == nullptr)
		{
			orExp = (new(ctx) SQLOrExpression(ctx));
		}
		sub = (new(ctx) SQLBoolSubExpression(t->image, exp, ctx));
		orExp->addSubExpression(sub, ctx);
	}
	label_41_out_break: ;
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	orExp->position(first, exp, ctx);
	orExp->setFirst(first, ctx);
	{
		{
			return orExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlAndExpression(ThreadContext* ctx)
{
	SQLAndExpression* andExp = nullptr;
	ISQLExpression* first = nullptr;
	ISQLExpression* exp = nullptr;
	Token* t = nullptr;
	SQLBoolSubExpression* sub = nullptr;
	first = sqlNotExpression(ctx);
	while(true)
	{
		if(jj_2_53((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_42_out_break;
		}
		t = jj_consume_token(SQLAND, ctx);
		exp = sqlNotExpression(ctx);
		if(andExp == nullptr)
		{
			andExp = (new(ctx) SQLAndExpression(ctx));
		}
		sub = (new(ctx) SQLBoolSubExpression(t->image, exp, ctx));
		andExp->addSubExpression(sub, ctx);
	}
	label_42_out_break: ;
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	andExp->position(first, exp, ctx);
	andExp->setFirst(first, ctx);
	{
		{
			return andExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlNotExpression(ThreadContext* ctx)
{
	SQLNotExpression* notExp = nullptr;
	ISQLExpression* first = nullptr;
	Token* t = nullptr;
	if(jj_2_54((long long)2, ctx))
	{
		t = jj_consume_token(NOT, ctx);
	}
		else 
	{
		;
	}
	first = sqlEqualityExpression(ctx);
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	notExp = (new(ctx) SQLNotExpression(ctx));
	notExp->position(t, first, ctx);
	notExp->setFirst(first, ctx);
	{
		{
			return notExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlEqualityExpression(ThreadContext* ctx)
{
	SQLEqualityExpression* eqExp = nullptr;
	ISQLExpression* first = nullptr;
	ISQLExpression* exp = nullptr;
	Token* t = nullptr;
	first = sqlRelationalExpression(ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case EQUALS:
	case CMP_NOTEQUALS:
	case 207:
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case EQUALS:
				{
					t = jj_consume_token(EQUALS, ctx);
					break ;
				}
			case 207:
				{
					t = jj_consume_token((long long)207, ctx);
					break ;
				}
			case CMP_NOTEQUALS:
				{
					t = jj_consume_token(CMP_NOTEQUALS, ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,103, ctx);
				jj_consume_token((long long)-1, ctx);
				throw (new(ctx) ParseException(ctx));
				break;
			}
			exp = sqlRelationalExpression(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,104, ctx);
		;
		break;
	}
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	eqExp = (new(ctx) SQLEqualityExpression(ctx));
	eqExp->position(first, exp, ctx);
	eqExp->setCheckEquals(t->image, ctx);
	eqExp->setLeft(first, ctx);
	eqExp->setRight(exp, ctx);
	{
		{
			return eqExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlRelationalExpression(ThreadContext* ctx)
{
	SQLRelationalExpression* relExp = nullptr;
	ISQLExpression* first = nullptr;
	ISQLExpression* exp = nullptr;
	Token* t = nullptr;
	first = sqlIsNullExpression(ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case GT:
	case GEQ:
	case LT:
	case LEQ:
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case LT:
				{
					t = jj_consume_token(LT, ctx);
					break ;
				}
			case GT:
				{
					t = jj_consume_token(GT, ctx);
					break ;
				}
			case LEQ:
				{
					t = jj_consume_token(LEQ, ctx);
					break ;
				}
			case GEQ:
				{
					t = jj_consume_token(GEQ, ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,105, ctx);
				jj_consume_token((long long)-1, ctx);
				throw (new(ctx) ParseException(ctx));
				break;
			}
			exp = sqlIsNullExpression(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,106, ctx);
		;
		break;
	}
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	relExp = (new(ctx) SQLRelationalExpression(ctx));
	relExp->position(first, exp, ctx);
	relExp->setLeft(first, ctx);
	relExp->setOpe(t->image, ctx);
	relExp->setRight(exp, ctx);
	{
		{
			return relExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlIsNullExpression(ThreadContext* ctx)
{
	SQLIsNullExpression* exp = nullptr;
	ISQLExpression* first = nullptr;
	Token* t = nullptr;
	Token* t_not = nullptr;
	first = sqlLikeExpression(ctx);
	if(jj_2_55((long long)2, ctx))
	{
		jj_consume_token(IS, ctx);
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case NOT:
			{
				t_not = jj_consume_token(NOT, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,107, ctx);
			;
			break;
		}
		t = jj_consume_token(_NULL, ctx);
	}
		else 
	{
		;
	}
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	exp = (new(ctx) SQLIsNullExpression(ctx));
	exp->position(first, t, ctx);
	exp->setFirst(first, ctx);
	if(t_not == nullptr)
	{
		exp->setNotNull(true, ctx);
	}
		else 
	{
		exp->setNotNull(false, ctx);
	}
	{
		{
			return exp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlLikeExpression(ThreadContext* ctx)
{
	SQLLikeExpression* likeExp = nullptr;
	ISQLExpression* first = nullptr;
	ISQLExpression* exp = nullptr;
	ISQLExpression* esc = nullptr;
	Token* t = nullptr;
	first = sqlInExpression(ctx);
	if(jj_2_57((long long)2, ctx))
	{
		jj_consume_token(LIKE, ctx);
		exp = sqlLiteral(ctx);
		if(jj_2_56((long long)2, ctx))
		{
			t = jj_consume_token(ESCAPE, ctx);
			esc = sqlLiteral(ctx);
		}
				else 
		{
			;
		}
	}
		else 
	{
		;
	}
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	likeExp = (new(ctx) SQLLikeExpression(ctx));
	likeExp->setFirst(first, ctx);
	likeExp->setExp(exp, ctx);
	if(t == nullptr)
	{
		likeExp->position(first, exp, ctx);
	}
		else 
	{
		likeExp->position(first, esc, ctx);
		likeExp->setEsc(esc, ctx);
	}
	{
		{
			return likeExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlInExpression(ThreadContext* ctx)
{
	SQLInExpression* inexp = nullptr;
	ISQLExpression* first = nullptr;
	SQLExpressionList* list = nullptr;
	Token* t = nullptr;
	first = sqlAdditiveExpression(ctx);
	if(jj_2_58((long long)2, ctx))
	{
		jj_consume_token(IN, ctx);
		jj_consume_token(L_PARENTHESIS, ctx);
		list = sqlExpressionList(ctx);
		t = jj_consume_token(R_PARENTHESIS, ctx);
	}
		else 
	{
		;
	}
	if(t == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	inexp = (new(ctx) SQLInExpression(ctx));
	inexp->position(first, t, ctx);
	inexp->setFirst(first, ctx);
	inexp->setList(list, ctx);
	{
		{
			return inexp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlAdditiveExpression(ThreadContext* ctx)
{
	SQLAdditiveExpression* additive = nullptr;
	ISQLExpression* first = nullptr;
	ISQLExpression* exp = nullptr;
	Token* t = nullptr;
	SQLSubExpression* subExp = nullptr;
	first = sqlMultiplicativeExpression(ctx);
	while(true)
	{
		if(jj_2_59((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_43_out_break;
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case PLUS:
			{
				t = jj_consume_token(PLUS, ctx);
				break ;
			}
		case MINUS:
			{
				t = jj_consume_token(MINUS, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,108, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		exp = sqlMultiplicativeExpression(ctx);
		if(additive == nullptr)
		{
			additive = (new(ctx) SQLAdditiveExpression(ctx));
		}
		subExp = (new(ctx) SQLSubExpression(t->image, exp, ctx));
		subExp->position(t, exp, ctx);
		additive->addSubExpression(subExp, ctx);
	}
	label_43_out_break: ;
	if(exp == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	additive->position(first, exp, ctx);
	additive->setFirst(first, ctx);
	{
		{
			return additive;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlMultiplicativeExpression(ThreadContext* ctx)
{
	SQLMultiplicativeExpression* mulExp = nullptr;
	ISQLExpression* first = nullptr;
	ISQLExpression* exp = nullptr;
	Token* t = nullptr;
	SQLSubExpression* subExp = nullptr;
	first = sqlBaseExpression(ctx);
	while(true)
	{
		if(jj_2_60((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_44_out_break;
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case ASTERISK:
			{
				t = jj_consume_token(ASTERISK, ctx);
				break ;
			}
		case DIV:
			{
				t = jj_consume_token(DIV, ctx);
				break ;
			}
		case MODULO:
			{
				t = jj_consume_token(MODULO, ctx);
				break ;
			}
		default:
			jj_la1->set(jj_gen,109, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
		exp = sqlBaseExpression(ctx);
		if(mulExp == nullptr)
		{
			mulExp = (new(ctx) SQLMultiplicativeExpression(ctx));
		}
		subExp = (new(ctx) SQLSubExpression(t->image, exp, ctx));
		subExp->position(t, exp, ctx);
		mulExp->addSubExpression(subExp, ctx);
	}
	label_44_out_break: ;
	if(exp == nullptr)
	{
		{
			{
				return first;
			}
		}
	}
	mulExp->position(first, exp, ctx);
	mulExp->setFirst(first, ctx);
	{
		{
			return mulExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlBaseExpression(ThreadContext* ctx)
{
	ISQLExpression* exp = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case INTEGER_LITERAL:
	case FLOATING_POINT_LITERAL:
	case CHARACTER_LITERAL:
	case SQL_STRING_LITERAL:
		{
			exp = sqlLiteral(ctx);
			break ;
		}
	case TRUE:
	case FALSE:
		{
			exp = sqlBooleanLiteral(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,110, ctx);
		if(jj_2_61((long long)3, ctx))
		{
			exp = sqlExpressionStream(ctx);
		}
				else 
		{
			if(jj_2_62((long long)3, ctx))
			{
				exp = sqlColumnIdentifier(ctx);
			}
						else 
			{
				if(jj_2_63((long long)3, ctx))
				{
					exp = sqlParenthesisExpression(ctx);
				}
								else 
				{
					jj_consume_token((long long)-1, ctx);
					throw (new(ctx) ParseException(ctx));
				}
			}
		}
		break;
	}
	{
		{
			return exp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SQLExpressionStream* AlinousPlusParser::sqlExpressionStream(ThreadContext* ctx)
{
	SQLExpressionStream* sqlExp = (new(ctx) SQLExpressionStream(ctx));
	ExpressionStream* expStream = nullptr;
	expStream = expressionStream(ctx);
	sqlExp->position(expStream, expStream, ctx);
	sqlExp->setExp(expStream, ctx);
	{
		{
			return sqlExp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SQLParenthesisExpression* AlinousPlusParser::sqlParenthesisExpression(ThreadContext* ctx)
{
	SQLParenthesisExpression* pexp = (new(ctx) SQLParenthesisExpression(ctx));
	Token* t = nullptr;
	Token* t2 = nullptr;
	ISQLExpression* exp = nullptr;
	t = jj_consume_token(L_PARENTHESIS, ctx);
	exp = sqlOrExpression(ctx);
	t2 = jj_consume_token(R_PARENTHESIS, ctx);
	pexp->setExp(exp, ctx);
	pexp->position(t, t2, ctx);
	{
		{
			return pexp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlColumnIdentifier(ThreadContext* ctx)
{
	SQLColumnIdentifier* identifier = (new(ctx) SQLColumnIdentifier(ctx));
	AlinousName* id = nullptr;
	Token* dt = nullptr;
	Token* t2 = nullptr;
	if(jj_2_64((long long)2, ctx))
	{
		dt = jj_consume_token(DISTINCT, ctx);
	}
		else 
	{
		;
	}
	id = alinousName(ctx);
	if(jj_2_65((long long)2, ctx))
	{
		jj_consume_token(AS, ctx);
		t2 = jj_consume_token(IDENTIFIER, ctx);
	}
		else 
	{
		;
	}
	if(dt == nullptr && t2 == nullptr)
	{
		identifier->position(id, id, ctx);
		identifier->setDistinct(false, ctx);
		identifier->setId(id, ctx);
	}
		else 
	{
		if(dt != nullptr && t2 == nullptr)
		{
			identifier->position(dt, id, ctx);
			identifier->setDistinct(true, ctx);
			identifier->setId(id, ctx);
		}
				else 
		{
			if(dt == nullptr && t2 != nullptr)
			{
				identifier->position(id, t2, ctx);
				identifier->setDistinct(false, ctx);
				identifier->setId(id, ctx);
				identifier->setAsName(t2->image, ctx);
			}
						else 
			{
				identifier->position(dt, t2, ctx);
				identifier->setDistinct(true, ctx);
				identifier->setId(id, ctx);
				identifier->setAsName(t2->image, ctx);
			}
		}
	}
	{
		{
			return identifier;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLBoolExpression* AlinousPlusParser::sqlBooleanLiteral(ThreadContext* ctx)
{
	SQLBooleanLiteral* lit = (new(ctx) SQLBooleanLiteral(ctx));
	Token* t = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case TRUE:
		{
			t = jj_consume_token(TRUE, ctx);
			break ;
		}
	case FALSE:
		{
			t = jj_consume_token(FALSE, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,111, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	lit->position(t, t, ctx);
	lit->setValue(t->image->equalsIgnoreCase(ConstStr::getCNST_STR_372(), ctx), ctx);
	{
		{
			return lit;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlLiteral(ThreadContext* ctx)
{
	SQLLiteral* lit = nullptr;
	Token* t = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case INTEGER_LITERAL:
		{
			t = jj_consume_token(INTEGER_LITERAL, ctx);
			lit = (new(ctx) SQLLiteral(SQLLiteral::sqlliteralType::INTEGER_LITERAL, ctx));
			break ;
		}
	case FLOATING_POINT_LITERAL:
		{
			t = jj_consume_token(FLOATING_POINT_LITERAL, ctx);
			lit = (new(ctx) SQLLiteral(SQLLiteral::sqlliteralType::FLOATING_POINT_LITERAL, ctx));
			break ;
		}
	case CHARACTER_LITERAL:
		{
			t = jj_consume_token(CHARACTER_LITERAL, ctx);
			lit = (new(ctx) SQLLiteral(SQLLiteral::sqlliteralType::CHARACTER_LITERAL, ctx));
			break ;
		}
	case SQL_STRING_LITERAL:
		{
			t = jj_consume_token(SQL_STRING_LITERAL, ctx);
			lit = (new(ctx) SQLLiteral(SQLLiteral::sqlliteralType::STRING_LITERAL, ctx));
			break ;
		}
	default:
		jj_la1->set(jj_gen,112, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	lit->position(t, t, ctx);
	lit->setValue(t->image, ctx);
	{
		{
			return lit;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
SQLExpressionList* AlinousPlusParser::sqlExpressionList(ThreadContext* ctx)
{
	SQLExpressionList* list = (new(ctx) SQLExpressionList(ctx));
	ISQLExpression* exp = nullptr;
	ISQLExpression* first = nullptr;
	if(jj_2_66((long long)2, ctx))
	{
		first = sqlExpressionListElement(ctx);
		list->addElement(first, ctx);
		while(true)
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case COMMA:
				{
					;
					break ;
				}
			default:
				jj_la1->set(jj_gen,113, ctx);
				goto label_45_out_break;
			}
			jj_consume_token(COMMA, ctx);
			exp = sqlExpressionListElement(ctx);
			list->addElement(exp, ctx);
		}
		label_45_out_break: ;
	}
		else 
	{
		;
	}
	if(first != nullptr)
	{
		if(exp == nullptr)
		{
			list->position(first, first, ctx);
		}
				else 
		{
			list->position(first, exp, ctx);
		}
	}
	{
		{
			return list;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlExpressionListElement(ThreadContext* ctx)
{
	ISQLExpression* exp = nullptr;
	Token* t = nullptr;
	SQLExpressionListAll* allList = nullptr;
	if(jj_2_67((long long)3, ctx))
	{
		exp = sqlAdditiveExpression(ctx);
	}
		else 
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case SELECT:
			{
				exp = sqlSubqueryExpression(ctx);
				break ;
			}
		case ASTERISK:
			{
				t = jj_consume_token(ASTERISK, ctx);
				allList = (new(ctx) SQLExpressionListAll(ctx));
				allList->position(t, t, ctx);
				exp = allList;
				break ;
			}
		default:
			jj_la1->set(jj_gen,114, ctx);
			jj_consume_token((long long)-1, ctx);
			throw (new(ctx) ParseException(ctx));
			break;
		}
	}
	{
		{
			return exp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
ISQLExpression* AlinousPlusParser::sqlSubqueryExpression(ThreadContext* ctx)
{
	SQLSubqueryExpression* exp = (new(ctx) SQLSubqueryExpression(ctx));
	SelectStatement* sel = nullptr;
	sel = selectStatement(ctx);
	exp->setSelectStatement(sel, ctx);
	{
		{
			return exp;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1250(), ctx));
}
void AlinousPlusParser::ReInit(java::io::InputStream* stream, ThreadContext* ctx)
{
	ReInit(stream, nullptr, ctx);
}
void AlinousPlusParser::ReInit(java::io::InputStream* stream, String* encoding, ThreadContext* ctx)
{
	{
		try
		{
			jj_input_stream->ReInit(stream, encoding, 1, 1, ctx);
		}
		catch(java::io::UnsupportedEncodingException* e)
		{
			throw (new(ctx) RuntimeException(e, ctx));
		}
	}
	token_source->ReInit(jj_input_stream, ctx);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)115; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousPlusParser::JJCalls(ctx)),i, ctx);
}
void AlinousPlusParser::ReInit(java::io::Reader* stream, ThreadContext* ctx)
{
	jj_input_stream->ReInit(stream, 1, 1, ctx);
	token_source->ReInit(jj_input_stream, ctx);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)115; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousPlusParser::JJCalls(ctx)),i, ctx);
}
void AlinousPlusParser::ReInit(AlinousPlusParserTokenManager* tm, ThreadContext* ctx)
{
	__GC_MV(this, &(token_source), tm, AlinousPlusParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)115; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousPlusParser::JJCalls(ctx)),i, ctx);
}
Token* AlinousPlusParser::getNextToken(ThreadContext* ctx)
{
	if(token->next != nullptr)
	{
		__GC_MV(this, &(token), token->next, Token);
	}
		else 
	{
		__GC_MV(this, &(token), __GC_MV(token, &(token->next), token_source->getNextToken(ctx), Token), Token);
	}
	jj_ntk = -1;
	jj_gen ++ ;
	return token;
}
Token* AlinousPlusParser::getToken(long long index, ThreadContext* ctx)
{
	Token* t = token;
	for(long long i = 0; i < index; i ++ )
	{
		if(t->next != nullptr)
		{
			t = t->next;
		}
				else 
		{
			t = __GC_MV(t, &(t->next), token_source->getNextToken(ctx), Token);
		}
	}
	return t;
}
ParseException* AlinousPlusParser::generateParseException(ThreadContext* ctx)
{
	jj_expentries->clear(ctx);
	IArrayObjectPrimitive<bool>* la1tokens = ArrayAllocatorPrimitive<bool>::allocatep(ctx, 208);
	if(jj_kind >= (long long)0)
	{
		la1tokens->set(true,jj_kind, ctx);
		jj_kind = -1;
	}
	for(long long i = 0; i < (long long)115; i ++ )
	{
		if(jj_la1->get(i) == jj_gen)
		{
			for(long long j = 0; j < (long long)32; j ++ )
			{
				if((jj_la1_0->get(i) & (1 << j)) != (long long)0)
				{
					la1tokens->set(true,j, ctx);
				}
				if((jj_la1_1->get(i) & (1 << j)) != (long long)0)
				{
					la1tokens->set(true,32 + j, ctx);
				}
				if((jj_la1_2->get(i) & (1 << j)) != (long long)0)
				{
					la1tokens->set(true,64 + j, ctx);
				}
				if((jj_la1_3->get(i) & (1 << j)) != (long long)0)
				{
					la1tokens->set(true,96 + j, ctx);
				}
				if((jj_la1_4->get(i) & (1 << j)) != (long long)0)
				{
					la1tokens->set(true,128 + j, ctx);
				}
				if((jj_la1_5->get(i) & (1 << j)) != (long long)0)
				{
					la1tokens->set(true,160 + j, ctx);
				}
				if((jj_la1_6->get(i) & (1 << j)) != (long long)0)
				{
					la1tokens->set(true,192 + j, ctx);
				}
			}
		}
	}
	for(long long i = 0; i < (long long)208; i ++ )
	{
		if(la1tokens->get(i))
		{
			__GC_MV(this, &(jj_expentry), ArrayAllocatorPrimitive<long long>::allocatep(ctx, 1), IArrayObjectPrimitive<long long>);
			jj_expentry->set(i,0, ctx);
			jj_expentries->add(jj_expentry, ctx);
		}
	}
	jj_endpos = 0;
	jj_rescan_token(ctx);
	jj_add_error_token((long long)0, (long long)0, ctx);
	IArrayObject<IArrayObjectPrimitive<long long>>* exptokseq = ArrayAllocatorPrimitive<long long>::allocatep(ctx, jj_expentries->size(ctx), 0);
	for(long long i = 0; i < (long long)jj_expentries->size(ctx); i ++ )
	{
		exptokseq->set(jj_expentries->get((int)i, ctx),i, ctx);
	}
	return (new(ctx) ParseException(token, exptokseq, tokenImage, ctx));
}
void AlinousPlusParser::enable_tracing(ThreadContext* ctx)
{
}
void AlinousPlusParser::disable_tracing(ThreadContext* ctx)
{
}
bool AlinousPlusParser::jj_2_1(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)0, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_1(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_2(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)1, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_2(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_3(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)2, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_3(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_4(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)3, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_4(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_5(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)4, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_5(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_6(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)5, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_6(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_7(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)6, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_7(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_8(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)7, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_8(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_9(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)8, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_9(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_10(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)9, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_10(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_11(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)10, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_11(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_12(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)11, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_12(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_13(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)12, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_13(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_14(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)13, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_14(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_15(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)14, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_15(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_16(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)15, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_16(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_17(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)16, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_17(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_18(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)17, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_18(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_19(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)18, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_19(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_20(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)19, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_20(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_21(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)20, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_21(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_22(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)21, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_22(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_23(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)22, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_23(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_24(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)23, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_24(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_25(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)24, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_25(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_26(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)25, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_26(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_27(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)26, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_27(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_28(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)27, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_28(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_29(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)28, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_29(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_30(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)29, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_30(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_31(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)30, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_31(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_32(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)31, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_32(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_33(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)32, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_33(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_34(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)33, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_34(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_35(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)34, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_35(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_36(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)35, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_36(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_37(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)36, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_37(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_38(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)37, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_38(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_39(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)38, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_39(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_40(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)39, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_40(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_41(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)40, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_41(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_42(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)41, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_42(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_43(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)42, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_43(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_44(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)43, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_44(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_45(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)44, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_45(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_46(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)45, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_46(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_47(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)46, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_47(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_48(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)47, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_48(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_49(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)48, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_49(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_50(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)49, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_50(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_51(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)50, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_51(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_52(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)51, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_52(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_53(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)52, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_53(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_54(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)53, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_54(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_55(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)54, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_55(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_56(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)55, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_56(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_57(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)56, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_57(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_58(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)57, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_58(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_59(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)58, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_59(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_60(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)59, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_60(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_61(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)60, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_61(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_62(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)61, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_62(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_63(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)62, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_63(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_64(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)63, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_64(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_65(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)64, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_65(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_66(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)65, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_66(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_2_67(long long xla, ThreadContext* ctx)
{
	jj_la = xla;
	__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), token, Token), Token);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			jj_save((long long)66, xla, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			return !jj_3_67(ctx);
		}
		catch(AlinousPlusParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousPlusParser::jj_3R_96(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_146(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_147(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3_61(ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_3_62(ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_3_63(ctx))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_193(ThreadContext* ctx)
{
	if(jj_3R_46(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_132(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_225(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_229(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_89(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_162(ThreadContext* ctx)
{
	if(jj_scan_token(L_BRACE, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_193(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(R_BRACE, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_152(ThreadContext* ctx)
{
	if(jj_scan_token(INSERT, ctx))
	{
		return true;
	}
	if(jj_scan_token(INTO, ctx))
	{
		return true;
	}
	if(jj_3R_189(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_229(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(VALUES, ctx))
	{
		return true;
	}
	if(jj_3R_230(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_231(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_69(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_60(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)23, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)28, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)29, ctx))
			{
				return true;
			}
		}
	}
	if(jj_3R_96(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_95(ThreadContext* ctx)
{
	if(jj_3R_96(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_60(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_209(ThreadContext* ctx)
{
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_3R_222(ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_203(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_47(ThreadContext* ctx)
{
	if(jj_scan_token(OFFSET, ctx))
	{
		return true;
	}
	if(jj_3R_88(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_53(ThreadContext* ctx)
{
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_scan_token(EQUALS, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_71(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_124(ThreadContext* ctx)
{
	if(jj_scan_token(EQUALS, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_46(ThreadContext* ctx)
{
	if(jj_scan_token(LIMIT, ctx))
	{
		return true;
	}
	if(jj_3R_88(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_228(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_46(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	xsp = jj_scanpos;
	if(jj_3_47(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_123(ThreadContext* ctx)
{
	if(jj_scan_token(L_BRACKET, ctx))
	{
		return true;
	}
	if(jj_scan_token(R_BRACKET, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_122(ThreadContext* ctx)
{
	if(jj_scan_token(L_BRACKET, ctx))
	{
		return true;
	}
	if(jj_scan_token(R_BRACKET, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_59(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)25, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)27, ctx))
		{
			return true;
		}
	}
	if(jj_3R_95(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_198(ThreadContext* ctx)
{
	if(jj_scan_token((long long)196, ctx))
	{
		return true;
	}
	if(jj_3R_129(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_88(ThreadContext* ctx)
{
	if(jj_3R_95(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_59(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3_58(ThreadContext* ctx)
{
	if(jj_scan_token(IN, ctx))
	{
		return true;
	}
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_89(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_45(ThreadContext* ctx)
{
	if(jj_scan_token(HAVING, ctx))
	{
		return true;
	}
	if(jj_3R_87(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_55(ThreadContext* ctx)
{
	if(jj_3R_51(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_122(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_123(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	xsp = jj_scanpos;
	if(jj_3R_124(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_197(ThreadContext* ctx)
{
	if(jj_scan_token(MINUSMINUS, ctx))
	{
		return true;
	}
	if(jj_3R_129(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_78(ThreadContext* ctx)
{
	if(jj_scan_token(GROUP, ctx))
	{
		return true;
	}
	if(jj_scan_token(BY, ctx))
	{
		return true;
	}
	if(jj_3R_89(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_45(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_224(ThreadContext* ctx)
{
	if(jj_3R_88(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_58(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_196(ThreadContext* ctx)
{
	if(jj_scan_token(PLUSPLUS, ctx))
	{
		return true;
	}
	if(jj_3R_129(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_77(ThreadContext* ctx)
{
	if(jj_scan_token(WHERE, ctx))
	{
		return true;
	}
	if(jj_3R_87(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_57(ThreadContext* ctx)
{
	if(jj_scan_token(LIKE, ctx))
	{
		return true;
	}
	if(jj_3R_94(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_56(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_207(ThreadContext* ctx)
{
	if(jj_scan_token(CONTINUE, ctx))
	{
		return true;
	}
	if(jj_3R_120(ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_175(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_70(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_56(ThreadContext* ctx)
{
	if(jj_scan_token(ESCAPE, ctx))
	{
		return true;
	}
	if(jj_3R_94(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_206(ThreadContext* ctx)
{
	if(jj_scan_token(BREAK, ctx))
	{
		return true;
	}
	if(jj_3R_120(ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_220(ThreadContext* ctx)
{
	if(jj_3R_224(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_57(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_133(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_70(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_102(ThreadContext* ctx)
{
	if(jj_3R_150(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_55(ThreadContext* ctx)
{
	if(jj_scan_token(IS, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)51, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(_NULL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_4(ThreadContext* ctx)
{
	if(jj_3R_49(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_44(ThreadContext* ctx)
{
	if(jj_scan_token(AS, ctx))
	{
		return true;
	}
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_204(ThreadContext* ctx)
{
	if(jj_3R_164(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_44(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_205(ThreadContext* ctx)
{
	if(jj_3R_220(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_55(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_135(ThreadContext* ctx)
{
	if(jj_scan_token(L_BRACKET, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_BRACKET, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_43(ThreadContext* ctx)
{
	if(jj_scan_token(AS, ctx))
	{
		return true;
	}
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_3(ThreadContext* ctx)
{
	if(jj_3R_48(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_47(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_3(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_102(ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_189(ThreadContext* ctx)
{
	if(jj_3R_51(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_43(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_227(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)49, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)47, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)50, ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_scan_token((long long)48, ctx))
				{
					return true;
				}
			}
		}
	}
	if(jj_3R_205(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_134(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)38, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)42, ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_74(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_134(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_3R_120(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_135(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_179(ThreadContext* ctx)
{
	if(jj_3R_205(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_227(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3_2(ThreadContext* ctx)
{
	if(jj_3R_47(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_178(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_210(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_177(ThreadContext* ctx)
{
	if(jj_3R_204(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_176(ThreadContext* ctx)
{
	if(jj_3R_189(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_46(ThreadContext* ctx)
{
	Token* xsp = 0;
	if(jj_3_2(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_2(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_72(ThreadContext* ctx)
{
	if(jj_3R_120(ctx))
	{
		return true;
	}
	if(jj_3R_132(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_136(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_176(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_177(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_178(ctx))
			{
				return true;
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_226(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)22, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)207, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)46, ctx))
			{
				return true;
			}
		}
	}
	if(jj_3R_179(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_73(ThreadContext* ctx)
{
	if(jj_3R_133(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_41(ThreadContext* ctx)
{
	if(jj_3R_79(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_141(ThreadContext* ctx)
{
	if(jj_3R_179(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_226(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3_33(ThreadContext* ctx)
{
	if(jj_3R_74(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_32(ThreadContext* ctx)
{
	if(jj_3R_72(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_79(ThreadContext* ctx)
{
	if(jj_scan_token(ON, ctx))
	{
		return true;
	}
	if(jj_3R_87(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_40(ThreadContext* ctx)
{
	if(jj_3R_79(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_131(ThreadContext* ctx)
{
	if(jj_3R_175(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_138(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	if(jj_3R_136(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_31(ThreadContext* ctx)
{
	if(jj_scan_token(DOT, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_32(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3_33(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_73(ctx))
			{
				return true;
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_130(ThreadContext* ctx)
{
	if(jj_3R_74(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_54(ThreadContext* ctx)
{
	if(jj_scan_token(NOT, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_39(ThreadContext* ctx)
{
	if(jj_3R_79(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_93(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_54(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_3R_141(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_30(ThreadContext* ctx)
{
	if(jj_3R_72(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_253(ThreadContext* ctx)
{
	if(jj_scan_token(L_BRACKET, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_BRACKET, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_137(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)114, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)113, ctx))
		{
			return true;
		}
	}
	xsp = jj_scanpos;
	if(jj_scan_token((long long)117, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_70(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_30(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_130(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_131(ctx))
			{
				return true;
			}
		}
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_31(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_86(ThreadContext* ctx)
{
	Token* xsp = 0;
	if(jj_3R_138(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_138(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_251(ThreadContext* ctx)
{
	Token* xsp = 0;
	if(jj_3R_253(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_253(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3_1(ThreadContext* ctx)
{
	if(jj_3R_46(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_250(ThreadContext* ctx)
{
	if(jj_3R_132(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_249(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_250(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_251(ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_85(ThreadContext* ctx)
{
	if(jj_scan_token(CROSS, ctx))
	{
		return true;
	}
	if(jj_scan_token(JOIN, ctx))
	{
		return true;
	}
	if(jj_3R_136(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_41(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3_53(ThreadContext* ctx)
{
	if(jj_scan_token(SQLAND, ctx))
	{
		return true;
	}
	if(jj_3R_93(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_38(ThreadContext* ctx)
{
	if(jj_3R_79(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_84(ThreadContext* ctx)
{
	if(jj_scan_token(NATURAL, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_137(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(JOIN, ctx))
	{
		return true;
	}
	if(jj_3R_136(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_92(ThreadContext* ctx)
{
	if(jj_3R_93(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_53(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_126(ThreadContext* ctx)
{
	if(jj_scan_token(SQL_DEFAULT, ctx))
	{
		return true;
	}
	if(jj_scan_token(COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_29(ThreadContext* ctx)
{
	if(jj_3R_71(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_199(ThreadContext* ctx)
{
	if(jj_scan_token(NEW, ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_249(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_83(ThreadContext* ctx)
{
	if(jj_scan_token(RIGHT, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)117, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(JOIN, ctx))
	{
		return true;
	}
	if(jj_3R_136(ctx))
	{
		return true;
	}
	xsp = jj_scanpos;
	if(jj_3_40(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_174(ThreadContext* ctx)
{
	if(jj_3R_203(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_28(ThreadContext* ctx)
{
	if(jj_3R_70(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_27(ThreadContext* ctx)
{
	if(jj_3R_69(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_125(ThreadContext* ctx)
{
	if(jj_scan_token(CASE, ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_173(ThreadContext* ctx)
{
	if(jj_3R_202(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_172(ThreadContext* ctx)
{
	if(jj_3R_201(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_82(ThreadContext* ctx)
{
	if(jj_scan_token(LEFT, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)117, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(JOIN, ctx))
	{
		return true;
	}
	if(jj_3R_136(ctx))
	{
		return true;
	}
	xsp = jj_scanpos;
	if(jj_3_39(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_171(ThreadContext* ctx)
{
	if(jj_3R_200(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_52(ThreadContext* ctx)
{
	if(jj_scan_token(OR, ctx))
	{
		return true;
	}
	if(jj_3R_92(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_170(ThreadContext* ctx)
{
	if(jj_3R_199(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_169(ThreadContext* ctx)
{
	if(jj_3R_198(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_168(ThreadContext* ctx)
{
	if(jj_3R_197(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_167(ThreadContext* ctx)
{
	if(jj_3R_196(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_87(ThreadContext* ctx)
{
	if(jj_3R_92(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_52(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_81(ThreadContext* ctx)
{
	if(jj_scan_token(JOIN, ctx))
	{
		return true;
	}
	if(jj_3R_136(ctx))
	{
		return true;
	}
	if(jj_3R_79(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_129(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_167(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_168(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_169(ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_3R_170(ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_3R_171(ctx))
					{
						__GC_MV(this, &(jj_scanpos), xsp, Token);
						if(jj_3R_172(ctx))
						{
							__GC_MV(this, &(jj_scanpos), xsp, Token);
							if(jj_3R_173(ctx))
							{
								__GC_MV(this, &(jj_scanpos), xsp, Token);
								if(jj_3_27(ctx))
								{
									__GC_MV(this, &(jj_scanpos), xsp, Token);
									if(jj_3_28(ctx))
									{
										__GC_MV(this, &(jj_scanpos), xsp, Token);
										if(jj_3R_174(ctx))
										{
											return true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_57(ThreadContext* ctx)
{
	if(jj_3R_126(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_56(ThreadContext* ctx)
{
	if(jj_3R_125(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_13(ThreadContext* ctx)
{
	if(jj_3R_46(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_80(ThreadContext* ctx)
{
	if(jj_scan_token(INNER, ctx))
	{
		return true;
	}
	if(jj_scan_token(JOIN, ctx))
	{
		return true;
	}
	if(jj_3R_136(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_38(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3_26(ThreadContext* ctx)
{
	if(jj_scan_token(NOT, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_159(ThreadContext* ctx)
{
	if(jj_scan_token(DROP, ctx))
	{
		return true;
	}
	if(jj_scan_token(INDEX, ctx))
	{
		return true;
	}
	if(jj_3R_189(ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_68(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_26(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_3R_129(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_12(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_56(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_57(ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_235(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	if(jj_3R_120(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_42(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_80(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_81(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_82(ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_3R_83(ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_3R_84(ctx))
					{
						__GC_MV(this, &(jj_scanpos), xsp, Token);
						if(jj_3R_85(ctx))
						{
							__GC_MV(this, &(jj_scanpos), xsp, Token);
							if(jj_3R_86(ctx))
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_210(ThreadContext* ctx)
{
	if(jj_3R_136(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_42(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3_25(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)23, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)28, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)29, ctx))
			{
				return true;
			}
		}
	}
	if(jj_3R_68(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_67(ThreadContext* ctx)
{
	if(jj_3R_68(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_25(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_188(ThreadContext* ctx)
{
	if(jj_scan_token(FROM, ctx))
	{
		return true;
	}
	if(jj_3R_210(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_158(ThreadContext* ctx)
{
	if(jj_scan_token(CREATE, ctx))
	{
		return true;
	}
	if(jj_scan_token(INDEX, ctx))
	{
		return true;
	}
	if(jj_3R_189(ctx))
	{
		return true;
	}
	if(jj_scan_token(ON, ctx))
	{
		return true;
	}
	if(jj_3R_189(ctx))
	{
		return true;
	}
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_120(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_235(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_76(ThreadContext* ctx)
{
	if(jj_scan_token(DROP, ctx))
	{
		return true;
	}
	if(jj_scan_token(TABLE, ctx))
	{
		return true;
	}
	if(jj_3R_189(ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_37(ThreadContext* ctx)
{
	if(jj_3R_78(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_36(ThreadContext* ctx)
{
	if(jj_3R_77(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_9(ThreadContext* ctx)
{
	if(jj_3R_53(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_24(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)25, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)27, ctx))
		{
			return true;
		}
	}
	if(jj_3R_67(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_187(ThreadContext* ctx)
{
	if(jj_scan_token(INTO, ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_66(ThreadContext* ctx)
{
	if(jj_3R_67(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_24(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3_10(ThreadContext* ctx)
{
	if(jj_3R_54(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_11(ThreadContext* ctx)
{
	if(jj_3R_55(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_186(ThreadContext* ctx)
{
	if(jj_3R_209(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_185(ThreadContext* ctx)
{
	if(jj_3R_208(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_140(ThreadContext* ctx)
{
	if(jj_scan_token(CHECK, ctx))
	{
		return true;
	}
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_87(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_184(ThreadContext* ctx)
{
	if(jj_3R_162(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_183(ThreadContext* ctx)
{
	if(jj_3R_207(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_244(ThreadContext* ctx)
{
	if(jj_scan_token(SQL_DEFAULT, ctx))
	{
		return true;
	}
	if(jj_3R_88(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_182(ThreadContext* ctx)
{
	if(jj_3R_206(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_151(ThreadContext* ctx)
{
	if(jj_scan_token(SELECT, ctx))
	{
		return true;
	}
	if(jj_3R_89(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_187(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_3R_188(ctx))
	{
		return true;
	}
	xsp = jj_scanpos;
	if(jj_3_36(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	xsp = jj_scanpos;
	if(jj_3_37(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_3R_228(ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_150(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_182(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_183(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_184(ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_3R_185(ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_3R_186(ctx))
					{
						__GC_MV(this, &(jj_scanpos), xsp, Token);
						if(jj_3_10(ctx))
						{
							__GC_MV(this, &(jj_scanpos), xsp, Token);
							if(jj_3_11(ctx))
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_242(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_88(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_192(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_111(ThreadContext* ctx)
{
	if(jj_3R_159(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_35(ThreadContext* ctx)
{
	if(jj_3R_76(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_23(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)195, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)53, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)54, ctx))
			{
				return true;
			}
		}
	}
	if(jj_3R_66(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_110(ThreadContext* ctx)
{
	if(jj_3R_158(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_65(ThreadContext* ctx)
{
	if(jj_3R_66(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_23(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_237(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)186, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)175, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)182, ctx))
			{
				return true;
			}
		}
	}
	xsp = jj_scanpos;
	if(jj_3R_242(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3_34(ThreadContext* ctx)
{
	if(jj_3R_75(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_109(ThreadContext* ctx)
{
	if(jj_3R_157(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_161(ThreadContext* ctx)
{
	if(jj_scan_token(THROWS, ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_192(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_108(ThreadContext* ctx)
{
	if(jj_3R_156(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_107(ThreadContext* ctx)
{
	if(jj_3R_155(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_106(ThreadContext* ctx)
{
	if(jj_3R_154(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_105(ThreadContext* ctx)
{
	if(jj_3R_153(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_104(ThreadContext* ctx)
{
	if(jj_3R_152(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_103(ThreadContext* ctx)
{
	if(jj_3R_151(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_212(ThreadContext* ctx)
{
	if(jj_3R_51(ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_21(ThreadContext* ctx)
{
	if(jj_scan_token(INSTANCEOF, ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_48(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_103(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_104(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_105(ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_3R_106(ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_3R_107(ctx))
					{
						__GC_MV(this, &(jj_scanpos), xsp, Token);
						if(jj_3R_108(ctx))
						{
							__GC_MV(this, &(jj_scanpos), xsp, Token);
							if(jj_3R_109(ctx))
							{
								__GC_MV(this, &(jj_scanpos), xsp, Token);
								if(jj_3_34(ctx))
								{
									__GC_MV(this, &(jj_scanpos), xsp, Token);
									if(jj_3R_110(ctx))
									{
										__GC_MV(this, &(jj_scanpos), xsp, Token);
										if(jj_3_35(ctx))
										{
											__GC_MV(this, &(jj_scanpos), xsp, Token);
											if(jj_3R_111(ctx))
											{
												return true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_243(ThreadContext* ctx)
{
	if(jj_scan_token(SQL_NOT, ctx))
	{
		return true;
	}
	if(jj_scan_token(_NULL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_238(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_243(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)161, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_244(ctx))
			{
				return true;
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_239(ThreadContext* ctx)
{
	if(jj_3R_140(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_22(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)49, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)47, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)50, ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_scan_token((long long)48, ctx))
				{
					return true;
				}
			}
		}
	}
	if(jj_3R_65(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_191(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	if(jj_3R_190(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_128(ThreadContext* ctx)
{
	if(jj_3R_65(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_22(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_211(ThreadContext* ctx)
{
	if(jj_3R_164(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_190(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_211(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_212(ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_139(ThreadContext* ctx)
{
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	if(jj_3R_237(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_238(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	xsp = jj_scanpos;
	if(jj_3R_239(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_160(ThreadContext* ctx)
{
	if(jj_3R_190(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_191(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_222(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)22, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)197, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)198, ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_scan_token((long long)199, ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_scan_token((long long)200, ctx))
					{
						__GC_MV(this, &(jj_scanpos), xsp, Token);
						if(jj_scan_token((long long)201, ctx))
						{
							__GC_MV(this, &(jj_scanpos), xsp, Token);
							if(jj_scan_token((long long)202, ctx))
							{
								__GC_MV(this, &(jj_scanpos), xsp, Token);
								if(jj_scan_token((long long)203, ctx))
								{
									__GC_MV(this, &(jj_scanpos), xsp, Token);
									if(jj_scan_token((long long)204, ctx))
									{
										__GC_MV(this, &(jj_scanpos), xsp, Token);
										if(jj_scan_token((long long)205, ctx))
										{
											__GC_MV(this, &(jj_scanpos), xsp, Token);
											if(jj_scan_token((long long)206, ctx))
											{
												return true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_64(ThreadContext* ctx)
{
	if(jj_3R_128(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_21(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_248(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_113(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_160(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_246(ThreadContext* ctx)
{
	if(jj_scan_token(UNIQUE, ctx))
	{
		return true;
	}
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_248(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_52(ThreadContext* ctx)
{
	if(jj_3R_51(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_247(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_20(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)45, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)46, ctx))
		{
			return true;
		}
	}
	if(jj_3R_64(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_63(ThreadContext* ctx)
{
	if(jj_3R_64(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_20(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_245(ThreadContext* ctx)
{
	if(jj_scan_token(PRIMARY, ctx))
	{
		return true;
	}
	if(jj_scan_token(KEY, ctx))
	{
		return true;
	}
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_247(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_241(ThreadContext* ctx)
{
	if(jj_3R_246(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_240(ThreadContext* ctx)
{
	if(jj_3R_245(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_19(ThreadContext* ctx)
{
	if(jj_scan_token(BIT_AND, ctx))
	{
		return true;
	}
	if(jj_3R_63(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_62(ThreadContext* ctx)
{
	if(jj_3R_63(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_19(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_91(ThreadContext* ctx)
{
	if(jj_3R_140(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_234(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_240(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_241(ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3_8(ThreadContext* ctx)
{
	if(jj_3R_52(ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_90(ThreadContext* ctx)
{
	if(jj_3R_139(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_181(ThreadContext* ctx)
{
	if(jj_3R_151(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_114(ThreadContext* ctx)
{
	if(jj_3R_161(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_120(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)186, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)102, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)103, ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_scan_token((long long)104, ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_scan_token((long long)105, ctx))
					{
						__GC_MV(this, &(jj_scanpos), xsp, Token);
						if(jj_scan_token((long long)106, ctx))
						{
							__GC_MV(this, &(jj_scanpos), xsp, Token);
							if(jj_scan_token((long long)107, ctx))
							{
								__GC_MV(this, &(jj_scanpos), xsp, Token);
								if(jj_scan_token((long long)108, ctx))
								{
									__GC_MV(this, &(jj_scanpos), xsp, Token);
									if(jj_scan_token((long long)109, ctx))
									{
										__GC_MV(this, &(jj_scanpos), xsp, Token);
										if(jj_scan_token((long long)110, ctx))
										{
											__GC_MV(this, &(jj_scanpos), xsp, Token);
											if(jj_scan_token((long long)111, ctx))
											{
												__GC_MV(this, &(jj_scanpos), xsp, Token);
												if(jj_scan_token((long long)112, ctx))
												{
													__GC_MV(this, &(jj_scanpos), xsp, Token);
													if(jj_scan_token((long long)113, ctx))
													{
														__GC_MV(this, &(jj_scanpos), xsp, Token);
														if(jj_scan_token((long long)114, ctx))
														{
															__GC_MV(this, &(jj_scanpos), xsp, Token);
															if(jj_scan_token((long long)115, ctx))
															{
																__GC_MV(this, &(jj_scanpos), xsp, Token);
																if(jj_scan_token((long long)116, ctx))
																{
																	__GC_MV(this, &(jj_scanpos), xsp, Token);
																	if(jj_scan_token((long long)117, ctx))
																	{
																		__GC_MV(this, &(jj_scanpos), xsp, Token);
																		if(jj_scan_token((long long)118, ctx))
																		{
																			__GC_MV(this, &(jj_scanpos), xsp, Token);
																			if(jj_scan_token((long long)120, ctx))
																			{
																				__GC_MV(this, &(jj_scanpos), xsp, Token);
																				if(jj_scan_token((long long)121, ctx))
																				{
																					__GC_MV(this, &(jj_scanpos), xsp, Token);
																					if(jj_scan_token((long long)122, ctx))
																					{
																						__GC_MV(this, &(jj_scanpos), xsp, Token);
																						if(jj_scan_token((long long)123, ctx))
																						{
																							__GC_MV(this, &(jj_scanpos), xsp, Token);
																							if(jj_scan_token((long long)124, ctx))
																							{
																								__GC_MV(this, &(jj_scanpos), xsp, Token);
																								if(jj_scan_token((long long)125, ctx))
																								{
																									__GC_MV(this, &(jj_scanpos), xsp, Token);
																									if(jj_scan_token((long long)126, ctx))
																									{
																										__GC_MV(this, &(jj_scanpos), xsp, Token);
																										if(jj_scan_token((long long)127, ctx))
																										{
																											__GC_MV(this, &(jj_scanpos), xsp, Token);
																											if(jj_scan_token((long long)128, ctx))
																											{
																												__GC_MV(this, &(jj_scanpos), xsp, Token);
																												if(jj_scan_token((long long)129, ctx))
																												{
																													__GC_MV(this, &(jj_scanpos), xsp, Token);
																													if(jj_scan_token((long long)130, ctx))
																													{
																														__GC_MV(this, &(jj_scanpos), xsp, Token);
																														if(jj_scan_token((long long)131, ctx))
																														{
																															__GC_MV(this, &(jj_scanpos), xsp, Token);
																															if(jj_scan_token((long long)51, ctx))
																															{
																																__GC_MV(this, &(jj_scanpos), xsp, Token);
																																if(jj_scan_token((long long)133, ctx))
																																{
																																	__GC_MV(this, &(jj_scanpos), xsp, Token);
																																	if(jj_scan_token((long long)134, ctx))
																																	{
																																		__GC_MV(this, &(jj_scanpos), xsp, Token);
																																		if(jj_scan_token((long long)135, ctx))
																																		{
																																			__GC_MV(this, &(jj_scanpos), xsp, Token);
																																			if(jj_scan_token((long long)136, ctx))
																																			{
																																				__GC_MV(this, &(jj_scanpos), xsp, Token);
																																				if(jj_scan_token((long long)137, ctx))
																																				{
																																					__GC_MV(this, &(jj_scanpos), xsp, Token);
																																					if(jj_scan_token((long long)138, ctx))
																																					{
																																						__GC_MV(this, &(jj_scanpos), xsp, Token);
																																						if(jj_scan_token((long long)139, ctx))
																																						{
																																							__GC_MV(this, &(jj_scanpos), xsp, Token);
																																							if(jj_scan_token((long long)140, ctx))
																																							{
																																								__GC_MV(this, &(jj_scanpos), xsp, Token);
																																								if(jj_scan_token((long long)141, ctx))
																																								{
																																									__GC_MV(this, &(jj_scanpos), xsp, Token);
																																									if(jj_scan_token((long long)142, ctx))
																																									{
																																										__GC_MV(this, &(jj_scanpos), xsp, Token);
																																										if(jj_scan_token((long long)143, ctx))
																																										{
																																											__GC_MV(this, &(jj_scanpos), xsp, Token);
																																											if(jj_scan_token((long long)144, ctx))
																																											{
																																												__GC_MV(this, &(jj_scanpos), xsp, Token);
																																												if(jj_scan_token((long long)145, ctx))
																																												{
																																													__GC_MV(this, &(jj_scanpos), xsp, Token);
																																													if(jj_scan_token((long long)146, ctx))
																																													{
																																														__GC_MV(this, &(jj_scanpos), xsp, Token);
																																														if(jj_scan_token((long long)147, ctx))
																																														{
																																															__GC_MV(this, &(jj_scanpos), xsp, Token);
																																															if(jj_scan_token((long long)148, ctx))
																																															{
																																																__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																if(jj_scan_token((long long)149, ctx))
																																																{
																																																	__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																	if(jj_scan_token((long long)150, ctx))
																																																	{
																																																		__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																		if(jj_scan_token((long long)151, ctx))
																																																		{
																																																			__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																			if(jj_scan_token((long long)152, ctx))
																																																			{
																																																				__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																				if(jj_scan_token((long long)153, ctx))
																																																				{
																																																					__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																					if(jj_scan_token((long long)154, ctx))
																																																					{
																																																						__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																						if(jj_scan_token((long long)155, ctx))
																																																						{
																																																							__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																							if(jj_scan_token((long long)156, ctx))
																																																							{
																																																								__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																								if(jj_scan_token((long long)157, ctx))
																																																								{
																																																									__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																									if(jj_scan_token((long long)158, ctx))
																																																									{
																																																										__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																										if(jj_scan_token((long long)159, ctx))
																																																										{
																																																											__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																											if(jj_scan_token((long long)160, ctx))
																																																											{
																																																												__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																												if(jj_scan_token((long long)161, ctx))
																																																												{
																																																													__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																													if(jj_scan_token((long long)162, ctx))
																																																													{
																																																														__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																														if(jj_scan_token((long long)163, ctx))
																																																														{
																																																															__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																															if(jj_scan_token((long long)164, ctx))
																																																															{
																																																																__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																if(jj_scan_token((long long)165, ctx))
																																																																{
																																																																	__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																	if(jj_scan_token((long long)166, ctx))
																																																																	{
																																																																		__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																		if(jj_scan_token((long long)167, ctx))
																																																																		{
																																																																			__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																			if(jj_scan_token((long long)168, ctx))
																																																																			{
																																																																				__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																				if(jj_scan_token((long long)169, ctx))
																																																																				{
																																																																					__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																					if(jj_scan_token((long long)170, ctx))
																																																																					{
																																																																						__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																						if(jj_scan_token((long long)171, ctx))
																																																																						{
																																																																							__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																							if(jj_scan_token((long long)172, ctx))
																																																																							{
																																																																								__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																								if(jj_scan_token((long long)173, ctx))
																																																																								{
																																																																									__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																									if(jj_scan_token((long long)174, ctx))
																																																																									{
																																																																										__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																										if(jj_scan_token((long long)175, ctx))
																																																																										{
																																																																											__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																											if(jj_scan_token((long long)176, ctx))
																																																																											{
																																																																												__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																												if(jj_scan_token((long long)177, ctx))
																																																																												{
																																																																													__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																													if(jj_scan_token((long long)178, ctx))
																																																																													{
																																																																														__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																														if(jj_scan_token((long long)179, ctx))
																																																																														{
																																																																															__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																															if(jj_scan_token((long long)180, ctx))
																																																																															{
																																																																																__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																if(jj_scan_token((long long)181, ctx))
																																																																																{
																																																																																	__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																	if(jj_scan_token((long long)185, ctx))
																																																																																	{
																																																																																		__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																		if(jj_scan_token((long long)91, ctx))
																																																																																		{
																																																																																			__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																			if(jj_scan_token((long long)94, ctx))
																																																																																			{
																																																																																				__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																				if(jj_scan_token((long long)95, ctx))
																																																																																				{
																																																																																					__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																					if(jj_scan_token((long long)99, ctx))
																																																																																					{
																																																																																						__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																						if(jj_scan_token((long long)97, ctx))
																																																																																						{
																																																																																							__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																							if(jj_scan_token((long long)96, ctx))
																																																																																							{
																																																																																								__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																								if(jj_scan_token((long long)77, ctx))
																																																																																								{
																																																																																									__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																									if(jj_scan_token((long long)87, ctx))
																																																																																									{
																																																																																										__GC_MV(this, &(jj_scanpos), xsp, Token);
																																																																																										if(jj_scan_token((long long)84, ctx))
																																																																																										{
																																																																																											return true;
																																																																																										}
																																																																																									}
																																																																																								}
																																																																																							}
																																																																																						}
																																																																																					}
																																																																																				}
																																																																																			}
																																																																																		}
																																																																																	}
																																																																																}
																																																																															}
																																																																														}
																																																																													}
																																																																												}
																																																																											}
																																																																										}
																																																																									}
																																																																								}
																																																																							}
																																																																						}
																																																																					}
																																																																				}
																																																																			}
																																																																		}
																																																																	}
																																																																}
																																																															}
																																																														}
																																																													}
																																																												}
																																																											}
																																																										}
																																																									}
																																																								}
																																																							}
																																																						}
																																																					}
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3_51(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_90(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_91(ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_149(ThreadContext* ctx)
{
	if(jj_scan_token(ASTERISK, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_18(ThreadContext* ctx)
{
	if(jj_scan_token((long long)194, ctx))
	{
		return true;
	}
	if(jj_3R_62(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_148(ThreadContext* ctx)
{
	if(jj_3R_181(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_75(ThreadContext* ctx)
{
	if(jj_scan_token(CREATE, ctx))
	{
		return true;
	}
	if(jj_scan_token(TABLE, ctx))
	{
		return true;
	}
	if(jj_3R_189(ctx))
	{
		return true;
	}
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_139(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_51(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_234(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_61(ThreadContext* ctx)
{
	if(jj_3R_62(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_18(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3_7(ThreadContext* ctx)
{
	if(jj_scan_token(FUNCTION, ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_121(ThreadContext* ctx)
{
	if(jj_scan_token(DOT, ctx))
	{
		return true;
	}
	if(jj_3R_120(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_67(ThreadContext* ctx)
{
	if(jj_3R_88(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_100(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_67(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_148(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_149(ctx))
			{
				return true;
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_115(ThreadContext* ctx)
{
	if(jj_3R_162(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_51(ThreadContext* ctx)
{
	if(jj_3R_120(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_121(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_112(ThreadContext* ctx)
{
	if(jj_3R_52(ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_157(ThreadContext* ctx)
{
	if(jj_scan_token(ROLLBACK, ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_101(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	if(jj_3R_100(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_17(ThreadContext* ctx)
{
	if(jj_scan_token(BIT_OR, ctx))
	{
		return true;
	}
	if(jj_3R_61(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_6(ThreadContext* ctx)
{
	if(jj_scan_token(FUNCTION, ctx))
	{
		return true;
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_60(ThreadContext* ctx)
{
	if(jj_3R_61(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_17(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_49(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_6(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_112(ctx))
		{
			return true;
		}
	}
	if(jj_3R_113(ctx))
	{
		return true;
	}
	xsp = jj_scanpos;
	if(jj_3R_114(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	xsp = jj_scanpos;
	if(jj_3R_115(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)21, ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_156(ThreadContext* ctx)
{
	if(jj_scan_token(COMMIT, ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_223(ThreadContext* ctx)
{
	if(jj_scan_token(L_BRACKET, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_BRACKET, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_66(ThreadContext* ctx)
{
	if(jj_3R_100(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_101(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_89(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_66(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_194(ThreadContext* ctx)
{
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_155(ThreadContext* ctx)
{
	if(jj_scan_token(BEGIN, ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_163(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)81, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)79, ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_scan_token((long long)80, ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_scan_token((long long)83, ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_scan_token((long long)64, ctx))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_116(ThreadContext* ctx)
{
	Token* xsp = 0;
	if(jj_3R_163(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_163(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_145(ThreadContext* ctx)
{
	if(jj_scan_token(SQL_STRING_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_144(ThreadContext* ctx)
{
	if(jj_scan_token(CHARACTER_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_16(ThreadContext* ctx)
{
	if(jj_scan_token(LOGICAL_AND, ctx))
	{
		return true;
	}
	if(jj_3R_60(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_143(ThreadContext* ctx)
{
	if(jj_scan_token(FLOATING_POINT_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_50(ThreadContext* ctx)
{
	if(jj_3R_77(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_59(ThreadContext* ctx)
{
	if(jj_3R_60(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_16(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_142(ThreadContext* ctx)
{
	if(jj_scan_token(INTEGER_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_94(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_142(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_143(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_144(ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_3R_145(ctx))
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_214(ThreadContext* ctx)
{
	if(jj_3R_223(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_154(ThreadContext* ctx)
{
	if(jj_scan_token(DELETE, ctx))
	{
		return true;
	}
	if(jj_scan_token(FROM, ctx))
	{
		return true;
	}
	if(jj_3R_189(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_50(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_213(ThreadContext* ctx)
{
	if(jj_scan_token(DOT, ctx))
	{
		return true;
	}
	if(jj_3R_194(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_195(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_213(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_214(ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_180(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)100, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)101, ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_232(ThreadContext* ctx)
{
	if(jj_3R_51(ctx))
	{
		return true;
	}
	if(jj_scan_token(EQUALS, ctx))
	{
		return true;
	}
	if(jj_3R_88(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_15(ThreadContext* ctx)
{
	if(jj_scan_token(LOGICAL_OR, ctx))
	{
		return true;
	}
	if(jj_3R_59(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_164(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)38, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)42, ctx))
		{
			return true;
		}
	}
	if(jj_3R_194(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_195(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3_14(ThreadContext* ctx)
{
	if(jj_scan_token((long long)193, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_scan_token(COLON, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_166(ThreadContext* ctx)
{
	if(jj_scan_token(L_BRACKET, ctx))
	{
		return true;
	}
	if(jj_scan_token(R_BRACKET, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_127(ThreadContext* ctx)
{
	if(jj_3R_59(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3_15(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_233(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	if(jj_3R_232(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_49(ThreadContext* ctx)
{
	if(jj_3R_77(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_201(ThreadContext* ctx)
{
	if(jj_scan_token(_NULL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_65(ThreadContext* ctx)
{
	if(jj_scan_token(AS, ctx))
	{
		return true;
	}
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_64(ThreadContext* ctx)
{
	if(jj_scan_token(DISTINCT, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_153(ThreadContext* ctx)
{
	if(jj_scan_token(UPDATE, ctx))
	{
		return true;
	}
	if(jj_3R_189(ctx))
	{
		return true;
	}
	if(jj_scan_token(SET, ctx))
	{
		return true;
	}
	if(jj_3R_232(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_233(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	xsp = jj_scanpos;
	if(jj_3_49(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_98(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_64(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	xsp = jj_scanpos;
	if(jj_3_65(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_165(ThreadContext* ctx)
{
	if(jj_scan_token(L_BRACKET, ctx))
	{
		return true;
	}
	if(jj_scan_token(R_BRACKET, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_200(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)100, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)101, ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_58(ThreadContext* ctx)
{
	if(jj_3R_127(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_14(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	return false;
}
bool AlinousPlusParser::jj_3R_119(ThreadContext* ctx)
{
	if(jj_scan_token(EQUALS, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_99(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_87(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_118(ThreadContext* ctx)
{
	if(jj_3R_51(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_165(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	if(jj_3R_51(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_166(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_221(ThreadContext* ctx)
{
	if(jj_3R_58(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_219(ThreadContext* ctx)
{
	if(jj_scan_token(SQL_STRING_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_117(ThreadContext* ctx)
{
	if(jj_3R_164(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_218(ThreadContext* ctx)
{
	if(jj_scan_token(STRING_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_236(ThreadContext* ctx)
{
	if(jj_3R_97(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_217(ThreadContext* ctx)
{
	if(jj_scan_token(CHARACTER_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_216(ThreadContext* ctx)
{
	if(jj_scan_token(FLOATING_POINT_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_215(ThreadContext* ctx)
{
	if(jj_scan_token(INTEGER_LITERAL, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_252(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	if(jj_3R_58(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_202(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_215(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_216(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3R_217(ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_3R_218(ctx))
				{
					__GC_MV(this, &(jj_scanpos), xsp, Token);
					if(jj_3R_219(ctx))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3R_50(ThreadContext* ctx)
{
	if(jj_3R_116(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_117(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_118(ctx))
		{
			return true;
		}
	}
	xsp = jj_scanpos;
	if(jj_3R_119(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_5(ThreadContext* ctx)
{
	if(jj_3R_50(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_230(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_48(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_236(ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3_48(ThreadContext* ctx)
{
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	if(jj_3R_89(ctx))
	{
		return true;
	}
	if(jj_scan_token(R_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_208(ThreadContext* ctx)
{
	if(jj_scan_token(RETURN, ctx))
	{
		return true;
	}
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_221(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_97(ThreadContext* ctx)
{
	if(jj_3R_70(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_225(ThreadContext* ctx)
{
	if(jj_3R_58(ctx))
	{
		return true;
	}
	Token* xsp = 0;
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_252(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousPlusParser::jj_3_62(ThreadContext* ctx)
{
	if(jj_3R_98(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_63(ThreadContext* ctx)
{
	if(jj_3R_99(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_231(ThreadContext* ctx)
{
	if(jj_scan_token(COMMA, ctx))
	{
		return true;
	}
	if(jj_3R_230(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3_61(ThreadContext* ctx)
{
	if(jj_3R_97(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_147(ThreadContext* ctx)
{
	if(jj_3R_180(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_54(ThreadContext* ctx)
{
	if(jj_3R_58(ctx))
	{
		return true;
	}
	if(jj_scan_token(SEMI_COLON, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousPlusParser::jj_3R_146(ThreadContext* ctx)
{
	if(jj_3R_94(ctx))
	{
		return true;
	}
	return false;
}
Token* AlinousPlusParser::jj_consume_token(long long kind, ThreadContext* ctx)
{
	Token* oldToken = 0;
	oldToken = token;
	if((oldToken)->next != nullptr)
	{
		__GC_MV(this, &(token), token->next, Token);
	}
		else 
	{
		__GC_MV(this, &(token), __GC_MV(token, &(token->next), token_source->getNextToken(ctx), Token), Token);
	}
	jj_ntk = -1;
	if(token->kind == (int)kind)
	{
		jj_gen ++ ;
		if(++jj_gc > (long long)100)
		{
			jj_gc = 0;
			for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
			{
				AlinousPlusParser::JJCalls* c = jj_2_rtns->get(i);
				while(c != nullptr)
				{
					if(c->gen < jj_gen)
					{
						__GC_MV(c, &(c->first), nullptr, Token);
					}
					c = c->next;
				}
			}
		}
		return token;
	}
	__GC_MV(this, &(token), oldToken, Token);
	jj_kind = kind;
	throw generateParseException(ctx);
}
bool AlinousPlusParser::jj_scan_token(long long kind, ThreadContext* ctx)
{
	if(jj_scanpos == jj_lastpos)
	{
		jj_la -- ;
		if(jj_scanpos->next == nullptr)
		{
			__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), __GC_MV(jj_scanpos, &(jj_scanpos->next), token_source->getNextToken(ctx), Token), Token), Token);
		}
				else 
		{
			__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), jj_scanpos->next, Token), Token);
		}
	}
		else 
	{
		__GC_MV(this, &(jj_scanpos), jj_scanpos->next, Token);
	}
	if(jj_rescan)
	{
		long long i = 0;
		Token* tok = token;
		while(tok != nullptr && tok != jj_scanpos)
		{
			i ++ ;
			tok = tok->next;
		}
		if(tok != nullptr)
		{
			jj_add_error_token(kind, i, ctx);
		}
	}
	if(jj_scanpos->kind != (int)kind)
	{
		return true;
	}
	if(jj_la == (long long)0 && jj_scanpos == jj_lastpos)
	{
		throw jj_ls;
	}
	return false;
}
long long AlinousPlusParser::jj_ntk_f(ThreadContext* ctx)
{
	__GC_MV(this, &(jj_nt), token->next, Token);
	if((jj_nt) == nullptr)
	{
		return (jj_ntk = (__GC_MV(token, &(token->next), token_source->getNextToken(ctx), Token))->kind);
	}
		else 
	{
		return (jj_ntk = jj_nt->kind);
	}
}
void AlinousPlusParser::jj_add_error_token(long long kind, long long pos, ThreadContext* ctx)
{
	if(pos >= (long long)100)
	{
		return;
	}
	if(pos == jj_endpos + 1)
	{
		jj_lasttokens->set(kind,jj_endpos++, ctx);
	}
		else 
	{
		if(jj_endpos != (long long)0)
		{
			__GC_MV(this, &(jj_expentry), ArrayAllocatorPrimitive<long long>::allocatep(ctx, jj_endpos), IArrayObjectPrimitive<long long>);
			for(long long i = 0; i < jj_endpos; i ++ )
			{
				jj_expentry->set(jj_lasttokens->get(i),i, ctx);
			}
			for(java::util::Iterator<IArrayObjectPrimitive<long long>>* it = jj_expentries->iterator(ctx); it->hasNext(ctx); )
			{
				jj_entries_loop_continue:
				IArrayObjectPrimitive<long long>* oldentry = ((IArrayObjectPrimitive<long long>*)(it->next(ctx)));
				if(oldentry->length == jj_expentry->length)
				{
					for(long long i = 0; i < (long long)jj_expentry->length; i ++ )
					{
						if(oldentry->get(i) != jj_expentry->get(i))
						{
							if(!it->hasNext(ctx)){
								goto jj_entries_loop_out_break;
							}
							goto jj_entries_loop_continue;
						}
					}
					jj_expentries->add(jj_expentry, ctx);
					goto jj_entries_loop_out_break;
				}
			}
			jj_entries_loop_out_break: ;
			if(pos != (long long)0)
			{
				jj_endpos = pos;
				jj_lasttokens->set(kind,(jj_endpos) - 1, ctx);
			}
		}
	}
}
void AlinousPlusParser::jj_rescan_token(ThreadContext* ctx)
{
	jj_rescan = true;
	for(long long i = 0; i < (long long)67; i ++ )
	{
		{
			try
			{
				AlinousPlusParser::JJCalls* p = jj_2_rtns->get(i);
				do
				{
					if(p->gen > jj_gen)
					{
						jj_la = p->arg;
						__GC_MV(this, &(jj_lastpos), __GC_MV(this, &(jj_scanpos), p->first, Token), Token);
						switch(i) {
						case 0:
							jj_3_1(ctx);
							break ;
						case 1:
							jj_3_2(ctx);
							break ;
						case 2:
							jj_3_3(ctx);
							break ;
						case 3:
							jj_3_4(ctx);
							break ;
						case 4:
							jj_3_5(ctx);
							break ;
						case 5:
							jj_3_6(ctx);
							break ;
						case 6:
							jj_3_7(ctx);
							break ;
						case 7:
							jj_3_8(ctx);
							break ;
						case 8:
							jj_3_9(ctx);
							break ;
						case 9:
							jj_3_10(ctx);
							break ;
						case 10:
							jj_3_11(ctx);
							break ;
						case 11:
							jj_3_12(ctx);
							break ;
						case 12:
							jj_3_13(ctx);
							break ;
						case 13:
							jj_3_14(ctx);
							break ;
						case 14:
							jj_3_15(ctx);
							break ;
						case 15:
							jj_3_16(ctx);
							break ;
						case 16:
							jj_3_17(ctx);
							break ;
						case 17:
							jj_3_18(ctx);
							break ;
						case 18:
							jj_3_19(ctx);
							break ;
						case 19:
							jj_3_20(ctx);
							break ;
						case 20:
							jj_3_21(ctx);
							break ;
						case 21:
							jj_3_22(ctx);
							break ;
						case 22:
							jj_3_23(ctx);
							break ;
						case 23:
							jj_3_24(ctx);
							break ;
						case 24:
							jj_3_25(ctx);
							break ;
						case 25:
							jj_3_26(ctx);
							break ;
						case 26:
							jj_3_27(ctx);
							break ;
						case 27:
							jj_3_28(ctx);
							break ;
						case 28:
							jj_3_29(ctx);
							break ;
						case 29:
							jj_3_30(ctx);
							break ;
						case 30:
							jj_3_31(ctx);
							break ;
						case 31:
							jj_3_32(ctx);
							break ;
						case 32:
							jj_3_33(ctx);
							break ;
						case 33:
							jj_3_34(ctx);
							break ;
						case 34:
							jj_3_35(ctx);
							break ;
						case 35:
							jj_3_36(ctx);
							break ;
						case 36:
							jj_3_37(ctx);
							break ;
						case 37:
							jj_3_38(ctx);
							break ;
						case 38:
							jj_3_39(ctx);
							break ;
						case 39:
							jj_3_40(ctx);
							break ;
						case 40:
							jj_3_41(ctx);
							break ;
						case 41:
							jj_3_42(ctx);
							break ;
						case 42:
							jj_3_43(ctx);
							break ;
						case 43:
							jj_3_44(ctx);
							break ;
						case 44:
							jj_3_45(ctx);
							break ;
						case 45:
							jj_3_46(ctx);
							break ;
						case 46:
							jj_3_47(ctx);
							break ;
						case 47:
							jj_3_48(ctx);
							break ;
						case 48:
							jj_3_49(ctx);
							break ;
						case 49:
							jj_3_50(ctx);
							break ;
						case 50:
							jj_3_51(ctx);
							break ;
						case 51:
							jj_3_52(ctx);
							break ;
						case 52:
							jj_3_53(ctx);
							break ;
						case 53:
							jj_3_54(ctx);
							break ;
						case 54:
							jj_3_55(ctx);
							break ;
						case 55:
							jj_3_56(ctx);
							break ;
						case 56:
							jj_3_57(ctx);
							break ;
						case 57:
							jj_3_58(ctx);
							break ;
						case 58:
							jj_3_59(ctx);
							break ;
						case 59:
							jj_3_60(ctx);
							break ;
						case 60:
							jj_3_61(ctx);
							break ;
						case 61:
							jj_3_62(ctx);
							break ;
						case 62:
							jj_3_63(ctx);
							break ;
						case 63:
							jj_3_64(ctx);
							break ;
						case 64:
							jj_3_65(ctx);
							break ;
						case 65:
							jj_3_66(ctx);
							break ;
						case 66:
							jj_3_67(ctx);
							break ;
						}
					}
					p = p->next;
				}
				while(p != nullptr);
			}
			catch(AlinousPlusParser::LookaheadSuccess* ls)
			{
			}
		}
	}
	jj_rescan = false;
}
void AlinousPlusParser::jj_save(long long index, long long xla, ThreadContext* ctx)
{
	AlinousPlusParser::JJCalls* p = jj_2_rtns->get(index);
	while(p->gen > jj_gen)
	{
		if(p->next == nullptr)
		{
			p = __GC_MV(p, &(p->next), (new(ctx) AlinousPlusParser::JJCalls(ctx)), AlinousPlusParser::JJCalls);
			break ;
		}
		p = p->next;
	}
	p->gen = jj_gen + xla - jj_la;
	__GC_MV(p, &(p->first), token, Token);
	p->arg = xla;
}
void AlinousPlusParser::jj_la1_init_0(ThreadContext* ctx)
{
	__GC_MV(nullptr, &(jj_la1_0), ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({0x51c2200, 0x0, 0x0, 0x0, 0x0, 0x51c2200, 0x0, 0x0, 0x0, 0x200000, 0x0, 0x0, 0x0, 0x200000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x400000, 0x0, 0x0, 0x0, 0x400000, 0x0, 0x0, 0x0, 0x0, 0x200000, 0x0, 0x0, 0x200000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x53c2200, 0x51c2200, 0x51c2200, 0x400000, 0x0, 0x0, 0x0, 0x0, 0x400000, 0x51c2200, 0x51c2200, 0x0, 0x0, 0x0, 0xa000000, 0x30800000, 0x51c2200, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x51c2200, 0x1c2200, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x400000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x400000, 0x400000, 0x0, 0x0, 0x0, 0xa000000, 0x30800000, 0x182200, 0x0, 0x182200, 0x0, 0x800000}, ctx)), IArrayObjectPrimitive<long long>);
}
void AlinousPlusParser::jj_la1_init_1(ThreadContext* ctx)
{
	__GC_MV(nullptr, &(jj_la1_1), ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({0x16080c44, 0x6080000, 0x0, 0x4, 0x8, 0x10080c44, 0x6000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80000, 0x0, 0x10, 0x10, 0x80440, 0x0, 0x10, 0x10, 0x80440, 0x0, 0x0, 0x0, 0x80000, 0x0, 0x800, 0x80000, 0x0, 0x800, 0x100, 0x80440, 0x80440, 0x100, 0x10000800, 0x100000, 0x40000000, 0x40000000, 0x100000, 0x10080c44, 0x80444, 0x80444, 0x0, 0x100000, 0x100000, 0x10, 0x10, 0x0, 0x10080c44, 0x80444, 0x6000, 0x78000, 0x600000, 0x0, 0x0, 0x0, 0x10, 0x14, 0x14, 0x80444, 0x4, 0x440, 0x440, 0x10, 0x100, 0x80444, 0x0, 0x0, 0x440, 0x90, 0x90, 0x80, 0x80000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x100, 0x100, 0x80444, 0x4, 0x100, 0x80444, 0x100, 0x0, 0x100, 0x0, 0x100, 0x100, 0x0, 0x0, 0x0, 0x0, 0x4, 0x100, 0x4000, 0x4000, 0x78000, 0x78000, 0x80000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x100, 0x0}, ctx)), IArrayObjectPrimitive<long long>);
}
void AlinousPlusParser::jj_la1_init_2(ThreadContext* ctx)
{
	__GC_MV(nullptr, &(jj_la1_2), ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({0xc8946002, 0xc8902000, 0x20000000, 0x0, 0x0, 0xc8946002, 0x0, 0x20, 0xb8001, 0x0, 0x20, 0x800, 0xb8001, 0x0, 0xc8902000, 0xb8001, 0x0, 0x0, 0xc8902000, 0x0, 0x0, 0x0, 0xc8902000, 0x0, 0xb8001, 0xb8001, 0xc8902000, 0x2000000, 0x0, 0xc8902000, 0x2000000, 0x0, 0x0, 0xc8902000, 0xc8902000, 0x0, 0x40002, 0x0, 0x0, 0x0, 0x0, 0xc8946002, 0xc8906000, 0xc8906000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc8946002, 0xc8906000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4000, 0x0, 0x0, 0x0, 0xc8902000, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc8906000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc8902000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc8902000, 0x0, 0x0, 0xc8902000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, ctx)), IArrayObjectPrimitive<long long>);
}
void AlinousPlusParser::jj_la1_init_3(ThreadContext* ctx)
{
	__GC_MV(nullptr, &(jj_la1_3), ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({0xff7ffffb, 0xff7fffcb, 0x0, 0x0, 0x0, 0xff7ffffb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff7fffcb, 0x0, 0x0, 0x0, 0xff7fffcb, 0x0, 0x0, 0x0, 0xff7fffcb, 0x0, 0x0, 0x0, 0xff7fffcb, 0x0, 0x0, 0xff7fffcb, 0x0, 0x0, 0x0, 0xff7fffcb, 0xff7fffcb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff7ffffb, 0xff7ffffb, 0xff7ffffb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff7ffffb, 0xff7ffffb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x0, 0x0, 0x0, 0xff7fffcb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff7ffffb, 0x0, 0x30, 0x0, 0x0, 0x0, 0x0, 0xff7fffcb, 0x0, 0x3c0, 0x0, 0x0, 0x400, 0x200000, 0x200000, 0x60000, 0x200000, 0x60000, 0x0, 0x19e0000, 0xff7fffcb, 0x0, 0x0, 0xff7fffcb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x30, 0x0, 0x0, 0x40}, ctx)), IArrayObjectPrimitive<long long>);
}
void AlinousPlusParser::jj_la1_init_4(ThreadContext* ctx)
{
	__GC_MV(nullptr, &(jj_la1_4), ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({0xffffffef, 0xffffffef, 0x0, 0x0, 0x0, 0xffffffef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xffffffef, 0x0, 0x0, 0x0, 0xffffffef, 0x0, 0x0, 0x0, 0xffffffef, 0x0, 0x0, 0x0, 0xffffffef, 0x0, 0x0, 0xffffffef, 0x0, 0x0, 0x0, 0xffffffef, 0xffffffef, 0x0, 0x0, 0x0, 0x4000000, 0x4000000, 0x0, 0xffffffef, 0xffffffef, 0xffffffef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xffffffef, 0xffffffef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xffffffef, 0x0, 0x0, 0x0, 0x0, 0x0, 0xffffffef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xffffffef, 0x0, 0x242000, 0x400000, 0x800000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xffffffef, 0x0, 0x0, 0xffffffef, 0x0, 0x0, 0x0, 0x80000000, 0x0, 0x0, 0x4000010, 0x4000010, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, ctx)), IArrayObjectPrimitive<long long>);
}
void AlinousPlusParser::jj_la1_init_5(ThreadContext* ctx)
{
	__GC_MV(nullptr, &(jj_la1_5), ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({0x7bfffff, 0x73fffff, 0x0, 0x0, 0x0, 0x6bfffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x63fffff, 0x0, 0x0, 0x0, 0x63fffff, 0x0, 0x0, 0x0, 0x63fffff, 0x0, 0x0, 0x0, 0x63fffff, 0x0, 0x0, 0x63fffff, 0x0, 0x0, 0x0, 0x63fffff, 0x63fffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6bfffff, 0x6bfffff, 0x6bfffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6bfffff, 0x6bfffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x800000, 0x0, 0x0, 0x0, 0x63fffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6bfffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x63fffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x63fffff, 0x0, 0x0, 0x63fffff, 0x0, 0x4000004, 0x0, 0x2, 0x0, 0x0, 0x2, 0x2, 0x4, 0x4408000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, ctx)), IArrayObjectPrimitive<long long>);
}
void AlinousPlusParser::jj_la1_init_6(ThreadContext* ctx)
{
	__GC_MV(nullptr, &(jj_la1_6), ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({0x10, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x10, 0x7fe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x8, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7fe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8000, 0x8000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, ctx)), IArrayObjectPrimitive<long long>);
}
}}

namespace alinous {namespace compile {





bool AlinousPlusParser::LookaheadSuccess::__init_done = __init_static_variables();
bool AlinousPlusParser::LookaheadSuccess::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousPlusParser::LookaheadSuccess", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousPlusParser::LookaheadSuccess::~LookaheadSuccess() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousPlusParser::LookaheadSuccess::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	java::lang::Error::__releaseRegerences(true, ctx);
}
}}

namespace alinous {namespace compile {





bool AlinousPlusParser::JJCalls::__init_done = __init_static_variables();
bool AlinousPlusParser::JJCalls::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousPlusParser::JJCalls", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousPlusParser::JJCalls::~JJCalls() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousPlusParser::JJCalls::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JJCalls", L"~JJCalls");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->next, this);
	next = nullptr;
	if(!prepare){
		return;
	}
}
}}

