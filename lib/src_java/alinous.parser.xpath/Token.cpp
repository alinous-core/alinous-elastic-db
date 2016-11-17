#include "includes.h"


namespace alinous {namespace parser {namespace xpath {





constexpr const long long Token::serialVersionUID;
bool Token::__init_done = __init_static_variables();
bool Token::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Token", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Token::Token(int kind, ThreadContext* ctx) throw()  : IObject(ctx), java::io::Serializable(ctx), kind(0), beginLine(0), beginColumn(0), endLine(0), endColumn(0), image(nullptr), next(nullptr), specialToken(nullptr)
{
	__construct_impl(kind, nullptr, ctx);
}
void Token::__construct_impl(int kind, ThreadContext* ctx) throw() 
{
	__construct_impl(kind, nullptr, ctx);
}
 Token::Token(int kind, String* image, ThreadContext* ctx) throw()  : IObject(ctx), java::io::Serializable(ctx), kind(0), beginLine(0), beginColumn(0), endLine(0), endColumn(0), image(nullptr), next(nullptr), specialToken(nullptr)
{
	this->kind = kind;
	__GC_MV(this, &(this->image), image, String);
}
void Token::__construct_impl(int kind, String* image, ThreadContext* ctx) throw() 
{
	this->kind = kind;
	__GC_MV(this, &(this->image), image, String);
}
 Token::~Token() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Token::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Token", L"~Token");
	__e_obj1.add(this->image, this);
	image = nullptr;
	__e_obj1.add(this->next, this);
	next = nullptr;
	__e_obj1.add(this->specialToken, this);
	specialToken = nullptr;
	if(!prepare){
		return;
	}
}
IObject* Token::getValue(ThreadContext* ctx) throw() 
{
	return nullptr;
}
String* Token::toString(ThreadContext* ctx) throw() 
{
	return image;
}
Token* Token::newToken(int ofKind, String* image, ThreadContext* ctx) throw() 
{
	switch(ofKind) {
	default:
		return (new(ctx) Token(ofKind, image, ctx));
		break;
	}
}
Token* Token::newToken(int ofKind, ThreadContext* ctx) throw() 
{
	return newToken(ofKind, nullptr, ctx);
}
}}}

