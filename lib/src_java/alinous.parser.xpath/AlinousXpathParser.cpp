#include "include/global.h"


#include "alinous.parser.xpath/TokenMgrError.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/XPathParser.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath/XpathReference.h"
#include "alinous.html.xpath/Xpath2Compare.h"
#include "alinous.html.xpath/XpathNumber.h"
#include "alinous.html.xpath/XpathFunctionArgument.h"
#include "alinous.html.xpath/XpathFunction.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath/AbstractContainerStatement.h"
#include "alinous.html.xpath/XpathAndStatement.h"
#include "alinous.html.xpath/XpathNotStatement.h"
#include "alinous.html.xpath/XpathOrStatement.h"
#include "alinous.html.xpath/XpathString.h"
#include "alinous.parser.xpath/Token.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.parser.xpath/JavaCharStream.h"
#include "alinous.parser.xpath/AlinousXpathParserConstants.h"
#include "alinous.parser.xpath/AlinousXpathParserTokenManager.h"
#include "alinous.parser.xpath/AlinousXpathParser.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/JavaCharStream.h"
#include "alinous.compile/ParseException.h"

namespace alinous {namespace parser {namespace xpath {





IArrayObjectPrimitive<long long>* AlinousXpathParser::jj_la1_0 = nullptr;
IArrayObjectPrimitive<long long>* AlinousXpathParser::jj_la1_1 = nullptr;
bool AlinousXpathParser::__init_done = __init_static_variables();
bool AlinousXpathParser::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousXpathParser", L"__init_static_variables");
		__GC_MV(nullptr, &(jj_la1_0), nullptr, IArrayObjectPrimitive<long long>);
		__GC_MV(nullptr, &(jj_la1_1), nullptr, IArrayObjectPrimitive<long long>);
		{
			jj_la1_init_0(ctx);
			jj_la1_init_1(ctx);
		}
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousXpathParser::AlinousXpathParser(java::io::InputStream* stream, ThreadContext* ctx) : IObject(ctx), AlinousXpathParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 17), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 5), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) AlinousXpathParser::LookaheadSuccess(ctx)), AlinousXpathParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	__construct_impl(stream, nullptr, ctx);
}
void AlinousXpathParser::__construct_impl(java::io::InputStream* stream, ThreadContext* ctx)
{
	__construct_impl(stream, nullptr, ctx);
}
 AlinousXpathParser::AlinousXpathParser(java::io::InputStream* stream, String* encoding, ThreadContext* ctx) : IObject(ctx), AlinousXpathParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 17), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 5), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) AlinousXpathParser::LookaheadSuccess(ctx)), AlinousXpathParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
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
	__GC_MV(this, &(token_source), (new(ctx) AlinousXpathParserTokenManager(jj_input_stream, ctx)), AlinousXpathParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)17; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousXpathParser::JJCalls(ctx)),i, ctx);
}
void AlinousXpathParser::__construct_impl(java::io::InputStream* stream, String* encoding, ThreadContext* ctx)
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
	__GC_MV(this, &(token_source), (new(ctx) AlinousXpathParserTokenManager(jj_input_stream, ctx)), AlinousXpathParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)17; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousXpathParser::JJCalls(ctx)),i, ctx);
}
 AlinousXpathParser::AlinousXpathParser(java::io::Reader* stream, ThreadContext* ctx) : IObject(ctx), AlinousXpathParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 17), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 5), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) AlinousXpathParser::LookaheadSuccess(ctx)), AlinousXpathParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	__GC_MV(this, &(jj_input_stream), (new(ctx) JavaCharStream(stream, 1, 1, ctx)), JavaCharStream);
	__GC_MV(this, &(token_source), (new(ctx) AlinousXpathParserTokenManager(jj_input_stream, ctx)), AlinousXpathParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)17; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousXpathParser::JJCalls(ctx)),i, ctx);
}
void AlinousXpathParser::__construct_impl(java::io::Reader* stream, ThreadContext* ctx)
{
	__GC_MV(this, &(jj_input_stream), (new(ctx) JavaCharStream(stream, 1, 1, ctx)), JavaCharStream);
	__GC_MV(this, &(token_source), (new(ctx) AlinousXpathParserTokenManager(jj_input_stream, ctx)), AlinousXpathParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)17; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousXpathParser::JJCalls(ctx)),i, ctx);
}
 AlinousXpathParser::AlinousXpathParser(AlinousXpathParserTokenManager* tm, ThreadContext* ctx) : IObject(ctx), AlinousXpathParserConstants(ctx), token_source(nullptr), token(nullptr), jj_nt(nullptr), jj_input_stream(nullptr), jj_ntk(0), jj_scanpos(nullptr), jj_lastpos(nullptr), jj_la(0), jj_gen(0), jj_la1(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 17), ctx)), IArrayObjectPrimitive<long long>)), jj_2_rtns(__GC_INS(this, ((IArrayObject<JJCalls>*)new(ctx) ArrayObject<JJCalls>(ArrayAllocator<JJCalls>::allocate(ctx, 5), ctx)), IArrayObject<JJCalls>)), jj_rescan(false), jj_gc(0), jj_ls(__GC_INS(this, (new(ctx) AlinousXpathParser::LookaheadSuccess(ctx)), AlinousXpathParser::LookaheadSuccess)), jj_expentries(GCUtils<java::util::List<IArrayObjectPrimitive<long long>> >::ins(this, (new(ctx) java::util::ArrayList<IArrayObjectPrimitive<long long>>(ctx)), ctx, __FILEW__, __LINE__, L"")), jj_expentry(nullptr), jj_kind(-1), jj_lasttokens(__GC_INS(this, ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>(ArrayAllocatorPrimitive<long long>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<long long>)), jj_endpos(0)
{
	__GC_MV(this, &(token_source), tm, AlinousXpathParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)17; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousXpathParser::JJCalls(ctx)),i, ctx);
}
void AlinousXpathParser::__construct_impl(AlinousXpathParserTokenManager* tm, ThreadContext* ctx)
{
	__GC_MV(this, &(token_source), tm, AlinousXpathParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)17; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousXpathParser::JJCalls(ctx)),i, ctx);
}
 AlinousXpathParser::~AlinousXpathParser()
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousXpathParser::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousXpathParser", L"~AlinousXpathParser");
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
Xpath* AlinousXpathParser::xpath(ThreadContext* ctx)
{
	Xpath* xpath = (new(ctx) Xpath(ctx));
	XpathContext* xctx = nullptr;
	while(true)
	{
		xctx = context(ctx);
		xpath->addContext(xctx, ctx);
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case ASTERISK:
		case DIV:
		case DOT:
		case AT_MARK:
		case IDENTIFIER:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,0, ctx);
			goto label_1_out_break;
		}
	}
	label_1_out_break: ;
	{
		{
			return xpath;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XpathContext* AlinousXpathParser::context(ThreadContext* ctx)
{
	XpathContext* context = (new(ctx) XpathContext(ctx));
	XpathFilter* f = nullptr;
	IXpathStatement* id = 0;
	IXpathStatement* index = 0;
	XpathContextLocation* loc = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case DIV:
	case DOT:
		{
			loc = location(ctx);
			context->setLocation(loc, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,1, ctx);
		;
		break;
	}
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case AT_MARK:
		{
			id = attributeIdentifier(ctx);
			break ;
		}
	case ASTERISK:
	case IDENTIFIER:
		{
			id = identifier(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,2, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	context->setIdentifier(id, ctx);
	if(jj_2_1((long long)2, ctx))
	{
		f = filter(ctx);
		context->addFilter(f, ctx);
	}
		else 
	{
		;
	}
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case L_BRACKET:
		{
			index = filterindex(ctx);
			context->setIndex(index, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,3, ctx);
		;
		break;
	}
	{
		{
			return context;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XpathContextLocation* AlinousXpathParser::location(ThreadContext* ctx)
{
	XpathContextLocation* loc = (new(ctx) XpathContextLocation(ctx));
	XpathContextLocationCtrl* ctrl = nullptr;
	while(true)
	{
		if(jj_2_2((long long)2, ctx))
		{
			jj_consume_token(DOT, ctx);
			jj_consume_token(DOT, ctx);
			ctrl = (new(ctx) XpathContextLocationCtrl(XpathContextLocationCtrl::CtrlType::parent, ctx));
			loc->addCtrl(ctrl, ctx);
		}
				else 
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case DOT:
				{
					jj_consume_token(DOT, ctx);
					ctrl = (new(ctx) XpathContextLocationCtrl(XpathContextLocationCtrl::CtrlType::current, ctx));
					loc->addCtrl(ctrl, ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,4, ctx);
				if(jj_2_3((long long)2, ctx))
				{
					jj_consume_token(DIV, ctx);
					jj_consume_token(DIV, ctx);
					ctrl = (new(ctx) XpathContextLocationCtrl(XpathContextLocationCtrl::CtrlType::all, ctx));
					loc->addCtrl(ctrl, ctx);
				}
								else 
				{
					switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
					case DIV:
						{
							jj_consume_token(DIV, ctx);
							ctrl = (new(ctx) XpathContextLocationCtrl(XpathContextLocationCtrl::CtrlType::children, ctx));
							loc->addCtrl(ctrl, ctx);
							break ;
						}
					default:
						jj_la1->set(jj_gen,5, ctx);
						jj_consume_token((long long)-1, ctx);
						throw (new(ctx) ParseException(ctx));
						break;
					}
				}
				break;
			}
		}
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case DIV:
		case DOT:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,6, ctx);
			goto label_2_out_break;
		}
	}
	label_2_out_break: ;
	{
		{
			return loc;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
IXpathStatement* AlinousXpathParser::filterindex(ThreadContext* ctx)
{
	IXpathStatement* p = nullptr;
	jj_consume_token(L_BRACKET, ctx);
	p = param(ctx);
	jj_consume_token(R_BRACKET, ctx);
	{
		{
			return p;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XpathFilter* AlinousXpathParser::filter(ThreadContext* ctx)
{
	XpathFilter* filter = (new(ctx) XpathFilter(ctx));
	IXpathBooleanCondition* condition = nullptr;
	jj_consume_token(L_BRACKET, ctx);
	condition = orStatement(ctx);
	jj_consume_token(R_BRACKET, ctx);
	filter->setCondition(condition, ctx);
	{
		{
			return filter;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
IXpathBooleanCondition* AlinousXpathParser::orStatement(ThreadContext* ctx)
{
	IXpathBooleanCondition* fstmt = nullptr;
	IXpathBooleanCondition* stmt = nullptr;
	XpathOrStatement* containerStmt = nullptr;
	fstmt = andStatement(ctx);
	while(true)
	{
		switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
		case XPATH_OR:
			{
				;
				break ;
			}
		default:
			jj_la1->set(jj_gen,7, ctx);
			goto label_3_out_break;
		}
		jj_consume_token(XPATH_OR, ctx);
		stmt = andStatement(ctx);
		if(containerStmt == nullptr)
		{
			containerStmt = (new(ctx) XpathOrStatement(ctx));
			containerStmt->addStatement(fstmt, ctx);
		}
		containerStmt->addStatement(stmt, ctx);
	}
	label_3_out_break: ;
	if(containerStmt == nullptr)
	{
		{
			{
				return fstmt;
			}
		}
	}
	{
		{
			return containerStmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
IXpathBooleanCondition* AlinousXpathParser::andStatement(ThreadContext* ctx)
{
	IXpathBooleanCondition* fstmt = nullptr;
	IXpathBooleanCondition* stmt = nullptr;
	XpathAndStatement* containerStmt = nullptr;
	fstmt = notStatement(ctx);
	while(true)
	{
		if(jj_2_4((long long)2, ctx))
		{
			;
		}
				else 
		{
			goto label_4_out_break;
		}
		jj_consume_token(XPATH_AND, ctx);
		stmt = notStatement(ctx);
		if(containerStmt == nullptr)
		{
			containerStmt = (new(ctx) XpathAndStatement(ctx));
			containerStmt->addStatement(fstmt, ctx);
		}
		containerStmt->addStatement(stmt, ctx);
	}
	label_4_out_break: ;
	if(containerStmt == nullptr)
	{
		{
			{
				return fstmt;
			}
		}
	}
	{
		{
			return containerStmt;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
IXpathBooleanCondition* AlinousXpathParser::notStatement(ThreadContext* ctx)
{
	IXpathBooleanCondition* stmt = nullptr;
	IXpathBooleanCondition* cstmt = nullptr;
	Token* tnot = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case L_PARENTHESIS:
	case NOT:
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case NOT:
				{
					tnot = jj_consume_token(NOT, ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,8, ctx);
				;
				break;
			}
			jj_consume_token(L_PARENTHESIS, ctx);
			cstmt = orStatement(ctx);
			jj_consume_token(R_PARENTHESIS, ctx);
			XpathNotStatement* notStmt = (new(ctx) XpathNotStatement(ctx));
			notStmt->setNot(tnot != nullptr, ctx);
			notStmt->setStmt(cstmt, ctx);
			stmt = notStmt;
			{
				{
					return stmt;
				}
			}
			break ;
		}
	case ASTERISK:
	case DIV:
	case DOT:
	case AT_MARK:
	case IDENTIFIER:
	case NUMERIC:
	case SQSTRLIT:
		{
			stmt = compareStatement(ctx);
			{
				{
					return stmt;
				}
			}
			break ;
		}
	default:
		jj_la1->set(jj_gen,9, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
IXpathBooleanCondition* AlinousXpathParser::compareStatement(ThreadContext* ctx)
{
	Xpath2Compare* compare = (new(ctx) Xpath2Compare(ctx));
	IXpathStatement* lparam = nullptr;
	IXpathStatement* rparam = nullptr;
	Token* t = nullptr;
	lparam = param(ctx);
	compare->setLparam(lparam, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case EQUALS:
	case CMP_NOTEQUALS:
	case GT:
	case GEQ:
	case LT:
	case LEQ:
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case EQUALS:
				{
					t = jj_consume_token(EQUALS, ctx);
					break ;
				}
			case CMP_NOTEQUALS:
				{
					t = jj_consume_token(CMP_NOTEQUALS, ctx);
					break ;
				}
			case GT:
				{
					t = jj_consume_token(GT, ctx);
					break ;
				}
			case GEQ:
				{
					t = jj_consume_token(GEQ, ctx);
					break ;
				}
			case LT:
				{
					t = jj_consume_token(LT, ctx);
					break ;
				}
			case LEQ:
				{
					t = jj_consume_token(LEQ, ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,10, ctx);
				jj_consume_token((long long)-1, ctx);
				throw (new(ctx) ParseException(ctx));
				break;
			}
			rparam = param(ctx);
			compare->setRparam(rparam, ctx);
			compare->setOperator(t->image, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,11, ctx);
		;
		break;
	}
	{
		{
			return compare;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
IXpathStatement* AlinousXpathParser::param(ThreadContext* ctx)
{
	IXpathStatement* element = 0;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case SQSTRLIT:
		{
			element = xpathString(ctx);
			break ;
		}
	case NUMERIC:
		{
			element = xpathNumber(ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,12, ctx);
		if(jj_2_5((long long)2, ctx))
		{
			element = xpathFunction(ctx);
		}
				else 
		{
			switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
			case ASTERISK:
			case DIV:
			case DOT:
			case AT_MARK:
			case IDENTIFIER:
				{
					element = xpathReference(ctx);
					break ;
				}
			default:
				jj_la1->set(jj_gen,13, ctx);
				jj_consume_token((long long)-1, ctx);
				throw (new(ctx) ParseException(ctx));
				break;
			}
		}
		break;
	}
	{
		{
			return element;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XpathFunction* AlinousXpathParser::xpathFunction(ThreadContext* ctx)
{
	XpathFunction* func = (new(ctx) XpathFunction(ctx));
	IXpathElement* element = nullptr;
	XpathFunctionArgument* arg = nullptr;
	Token* t = nullptr;
	t = jj_consume_token(IDENTIFIER, ctx);
	jj_consume_token(L_PARENTHESIS, ctx);
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case ASTERISK:
	case DIV:
	case DOT:
	case AT_MARK:
	case IDENTIFIER:
	case NUMERIC:
	case SQSTRLIT:
		{
			element = param(ctx);
			arg = (new(ctx) XpathFunctionArgument(element, ctx));
			func->addArgument(arg, ctx);
			while(true)
			{
				switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
				case COMMA:
					{
						;
						break ;
					}
				default:
					jj_la1->set(jj_gen,14, ctx);
					goto label_5_out_break;
				}
				jj_consume_token(COMMA, ctx);
				element = param(ctx);
				arg = (new(ctx) XpathFunctionArgument(element, ctx));
				func->addArgument(arg, ctx);
			}
			label_5_out_break: ;
			break ;
		}
	default:
		jj_la1->set(jj_gen,15, ctx);
		;
		break;
	}
	jj_consume_token(R_PARENTHESIS, ctx);
	func->setName(t->image, ctx);
	{
		{
			return func;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XpathReference* AlinousXpathParser::xpathReference(ThreadContext* ctx)
{
	XpathReference* ref = (new(ctx) XpathReference(ctx));
	Xpath* xpth = nullptr;
	xpth = xpath(ctx);
	ref->setXpath(xpth, ctx);
	{
		{
			return ref;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XpathNumber* AlinousXpathParser::xpathNumber(ThreadContext* ctx)
{
	XpathNumber* num = (new(ctx) XpathNumber(ctx));
	Token* t = nullptr;
	t = jj_consume_token(NUMERIC, ctx);
	num->setNumber(t->image, ctx);
	{
		{
			return num;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XpathString* AlinousXpathParser::xpathString(ThreadContext* ctx)
{
	XpathString* str = (new(ctx) XpathString(ctx));
	Token* t = nullptr;
	t = jj_consume_token(SQSTRLIT, ctx);
	str->setText(t->image, ctx);
	{
		{
			return str;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
AttributeIdentifier* AlinousXpathParser::attributeIdentifier(ThreadContext* ctx)
{
	AttributeIdentifier* aid = nullptr;
	XpathIdentifier* id = nullptr;
	jj_consume_token(AT_MARK, ctx);
	id = identifier(ctx);
	aid = (new(ctx) AttributeIdentifier(id->getId(ctx), ctx));
	{
		{
			return aid;
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
XpathIdentifier* AlinousXpathParser::identifier(ThreadContext* ctx)
{
	Token* t = nullptr;
	switch((jj_ntk == (long long)-1) ? jj_ntk_f(ctx) : jj_ntk) {
	case IDENTIFIER:
		{
			t = jj_consume_token(IDENTIFIER, ctx);
			break ;
		}
	case ASTERISK:
		{
			t = jj_consume_token(ASTERISK, ctx);
			break ;
		}
	default:
		jj_la1->set(jj_gen,16, ctx);
		jj_consume_token((long long)-1, ctx);
		throw (new(ctx) ParseException(ctx));
		break;
	}
	{
		{
			return (new(ctx) XpathIdentifier(t->image, ctx));
		}
	}
	throw (new(ctx) Error(ConstStr::getCNST_STR_1318(), ctx));
}
void AlinousXpathParser::ReInit(java::io::InputStream* stream, ThreadContext* ctx)
{
	ReInit(stream, nullptr, ctx);
}
void AlinousXpathParser::ReInit(java::io::InputStream* stream, String* encoding, ThreadContext* ctx)
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
	for(long long i = 0; i < (long long)17; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousXpathParser::JJCalls(ctx)),i, ctx);
}
void AlinousXpathParser::ReInit(java::io::Reader* stream, ThreadContext* ctx)
{
	jj_input_stream->ReInit(stream, 1, 1, ctx);
	token_source->ReInit(jj_input_stream, ctx);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)17; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousXpathParser::JJCalls(ctx)),i, ctx);
}
void AlinousXpathParser::ReInit(AlinousXpathParserTokenManager* tm, ThreadContext* ctx)
{
	__GC_MV(this, &(token_source), tm, AlinousXpathParserTokenManager);
	__GC_MV(this, &(token), (new(ctx) Token(ctx)), Token);
	jj_ntk = -1;
	jj_gen = 0;
	for(long long i = 0; i < (long long)17; i ++ )
	jj_la1->set(-1,i, ctx);
	for(long long i = 0; i < (long long)jj_2_rtns->length; i ++ )
	jj_2_rtns->set((new(ctx) AlinousXpathParser::JJCalls(ctx)),i, ctx);
}
Token* AlinousXpathParser::getNextToken(ThreadContext* ctx)
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
Token* AlinousXpathParser::getToken(long long index, ThreadContext* ctx)
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
ParseException* AlinousXpathParser::generateParseException(ThreadContext* ctx)
{
	jj_expentries->clear(ctx);
	IArrayObjectPrimitive<bool>* la1tokens = ArrayAllocatorPrimitive<bool>::allocatep(ctx, 59);
	if(jj_kind >= (long long)0)
	{
		la1tokens->set(true,jj_kind, ctx);
		jj_kind = -1;
	}
	for(long long i = 0; i < (long long)17; i ++ )
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
			}
		}
	}
	for(long long i = 0; i < (long long)59; i ++ )
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
void AlinousXpathParser::enable_tracing(ThreadContext* ctx)
{
}
void AlinousXpathParser::disable_tracing(ThreadContext* ctx)
{
}
bool AlinousXpathParser::jj_2_1(long long xla, ThreadContext* ctx)
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
		catch(AlinousXpathParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousXpathParser::jj_2_2(long long xla, ThreadContext* ctx)
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
		catch(AlinousXpathParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousXpathParser::jj_2_3(long long xla, ThreadContext* ctx)
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
		catch(AlinousXpathParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousXpathParser::jj_2_4(long long xla, ThreadContext* ctx)
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
		catch(AlinousXpathParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousXpathParser::jj_2_5(long long xla, ThreadContext* ctx)
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
		catch(AlinousXpathParser::LookaheadSuccess* ls)
		{
			return true;
		}
	}
}
bool AlinousXpathParser::jj_3R_32(ThreadContext* ctx)
{
	if(jj_scan_token(DIV, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_18(ThreadContext* ctx)
{
	if(jj_scan_token(SQSTRLIT, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_21(ThreadContext* ctx)
{
	Token* xsp = 0;
	if(jj_3R_22(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_22(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousXpathParser::jj_3_1(ThreadContext* ctx)
{
	if(jj_3R_6(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_7(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_10(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_11(ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousXpathParser::jj_3R_10(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)40, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_26(ThreadContext* ctx)
{
	if(jj_3R_29(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_31(ThreadContext* ctx)
{
	if(jj_scan_token(DOT, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3_3(ThreadContext* ctx)
{
	if(jj_scan_token(DIV, ctx))
	{
		return true;
	}
	if(jj_scan_token(DIV, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_9(ThreadContext* ctx)
{
	if(jj_3R_12(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_8(ThreadContext* ctx)
{
	if(jj_scan_token(IDENTIFIER, ctx))
	{
		return true;
	}
	if(jj_scan_token(L_PARENTHESIS, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_25(ThreadContext* ctx)
{
	if(jj_3R_28(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_19(ThreadContext* ctx)
{
	if(jj_scan_token(NUMERIC, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_24(ThreadContext* ctx)
{
	if(jj_3R_27(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_17(ThreadContext* ctx)
{
	if(jj_3R_20(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_13(ThreadContext* ctx)
{
	if(jj_3R_14(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3_5(ThreadContext* ctx)
{
	if(jj_3R_8(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_29(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_scan_token((long long)45, ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_scan_token((long long)11, ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousXpathParser::jj_3_4(ThreadContext* ctx)
{
	if(jj_scan_token(XPATH_AND, ctx))
	{
		return true;
	}
	if(jj_3R_7(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_16(ThreadContext* ctx)
{
	if(jj_3R_19(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_30(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3_2(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_31(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3_3(ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_3R_32(ctx))
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool AlinousXpathParser::jj_3_2(ThreadContext* ctx)
{
	if(jj_scan_token(DOT, ctx))
	{
		return true;
	}
	if(jj_scan_token(DOT, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_15(ThreadContext* ctx)
{
	if(jj_3R_18(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_23(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_24(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
	}
	xsp = jj_scanpos;
	if(jj_3R_25(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_26(ctx))
		{
			return true;
		}
	}
	return false;
}
bool AlinousXpathParser::jj_3R_20(ThreadContext* ctx)
{
	if(jj_3R_21(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_6(ThreadContext* ctx)
{
	if(jj_scan_token(L_BRACKET, ctx))
	{
		return true;
	}
	if(jj_3R_9(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_12(ThreadContext* ctx)
{
	if(jj_3R_7(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_27(ThreadContext* ctx)
{
	Token* xsp = 0;
	if(jj_3R_30(ctx))
	{
		return true;
	}
	while(true)
	{
		xsp = jj_scanpos;
		if(jj_3R_30(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			break ;
		}
	}
	return false;
}
bool AlinousXpathParser::jj_3R_28(ThreadContext* ctx)
{
	if(jj_scan_token(AT_MARK, ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_14(ThreadContext* ctx)
{
	Token* xsp = 0;
	xsp = jj_scanpos;
	if(jj_3R_15(ctx))
	{
		__GC_MV(this, &(jj_scanpos), xsp, Token);
		if(jj_3R_16(ctx))
		{
			__GC_MV(this, &(jj_scanpos), xsp, Token);
			if(jj_3_5(ctx))
			{
				__GC_MV(this, &(jj_scanpos), xsp, Token);
				if(jj_3R_17(ctx))
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool AlinousXpathParser::jj_3R_11(ThreadContext* ctx)
{
	if(jj_3R_13(ctx))
	{
		return true;
	}
	return false;
}
bool AlinousXpathParser::jj_3R_22(ThreadContext* ctx)
{
	if(jj_3R_23(ctx))
	{
		return true;
	}
	return false;
}
Token* AlinousXpathParser::jj_consume_token(long long kind, ThreadContext* ctx)
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
				AlinousXpathParser::JJCalls* c = jj_2_rtns->get(i);
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
bool AlinousXpathParser::jj_scan_token(long long kind, ThreadContext* ctx)
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
long long AlinousXpathParser::jj_ntk_f(ThreadContext* ctx)
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
void AlinousXpathParser::jj_add_error_token(long long kind, long long pos, ThreadContext* ctx)
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
void AlinousXpathParser::jj_rescan_token(ThreadContext* ctx)
{
	jj_rescan = true;
	for(long long i = 0; i < (long long)5; i ++ )
	{
		{
			try
			{
				AlinousXpathParser::JJCalls* p = jj_2_rtns->get(i);
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
						}
					}
					p = p->next;
				}
				while(p != nullptr);
			}
			catch(AlinousXpathParser::LookaheadSuccess* ls)
			{
			}
		}
	}
	jj_rescan = false;
}
void AlinousXpathParser::jj_save(long long index, long long xla, ThreadContext* ctx)
{
	AlinousXpathParser::JJCalls* p = jj_2_rtns->get(index);
	while(p->gen > jj_gen)
	{
		if(p->next == nullptr)
		{
			p = __GC_MV(p, &(p->next), (new(ctx) AlinousXpathParser::JJCalls(ctx)), AlinousXpathParser::JJCalls);
			break ;
		}
		p = p->next;
	}
	p->gen = jj_gen + xla - jj_la;
	__GC_MV(p, &(p->first), token, Token);
	p->arg = xla;
}
void AlinousXpathParser::jj_la1_init_0(ThreadContext* ctx)
{
	__GC_MV(nullptr, &(jj_la1_0), ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({0x88010800, 0x8010000, 0x80000800, 0x1000000, 0x8000000, 0x10000, 0x8010000, 0x0, 0x0, 0x88410800, 0x400, 0x400, 0x0, 0x88010800, 0x10000000, 0x88010800, 0x800}, ctx)), IArrayObjectPrimitive<long long>);
}
void AlinousXpathParser::jj_la1_init_1(ThreadContext* ctx)
{
	__GC_MV(nullptr, &(jj_la1_1), ((IArrayObjectPrimitive<long long>*)new(ctx) ArrayObjectPrimitive<long long>({0x2000, 0x0, 0x2000, 0x0, 0x0, 0x0, 0x0, 0x800, 0x100, 0x406100, 0xf8, 0xf8, 0x404000, 0x2000, 0x0, 0x406000, 0x2000}, ctx)), IArrayObjectPrimitive<long long>);
}
}}}

namespace alinous {namespace parser {namespace xpath {





bool AlinousXpathParser::LookaheadSuccess::__init_done = __init_static_variables();
bool AlinousXpathParser::LookaheadSuccess::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousXpathParser::LookaheadSuccess", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousXpathParser::LookaheadSuccess::~LookaheadSuccess() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousXpathParser::LookaheadSuccess::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	java::lang::Error::__releaseRegerences(true, ctx);
}
}}}

namespace alinous {namespace parser {namespace xpath {





bool AlinousXpathParser::JJCalls::__init_done = __init_static_variables();
bool AlinousXpathParser::JJCalls::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousXpathParser::JJCalls", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousXpathParser::JJCalls::~JJCalls() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousXpathParser::JJCalls::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
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
}}}

