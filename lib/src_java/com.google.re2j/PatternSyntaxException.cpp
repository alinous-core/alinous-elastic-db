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
#include "com.google.re2j/Utils.h"
#include "com.google.re2j/Unicode.h"
#include "com.google.re2j/CharGroup.h"
#include "com.google.re2j/CharClass.h"
#include "com.google.re2j/Parser.h"
#include "com.google.re2j/Compiler.h"
#include "com.google.re2j/UnicodeTable2.h"
#include "com.google.re2j/UnicodeTables.h"
#include "com.google.re2j/Pattern.h"
#include "com.google.re2j/Matcher.h"

namespace com {namespace google {namespace re2j {





constexpr const long long PatternSyntaxException::serialVersionUID;
bool PatternSyntaxException::__init_done = __init_static_variables();
bool PatternSyntaxException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"PatternSyntaxException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 PatternSyntaxException::PatternSyntaxException(String* error, String* input, ThreadContext* ctx) throw()  : IObject(ctx), Exception(ConstStr::getCNST_STR_115()->clone(ctx)->append(error, ctx)->append(ConstStr::getCNST_STR_116(), ctx)->append(input, ctx)->append(ConstStr::getCNST_STR_117(), ctx), ctx), error(nullptr), input(nullptr)
{
	__GC_MV(this, &(this->error), error, String);
	__GC_MV(this, &(this->input), input, String);
}
void PatternSyntaxException::__construct_impl(String* error, String* input, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->error), error, String);
	__GC_MV(this, &(this->input), input, String);
}
 PatternSyntaxException::PatternSyntaxException(String* error, ThreadContext* ctx) throw()  : IObject(ctx), Exception(ConstStr::getCNST_STR_115()->clone(ctx)->append(error, ctx), ctx), error(nullptr), input(nullptr)
{
	__GC_MV(this, &(this->error), error, String);
	__GC_MV(this, &(this->input), ConstStr::getCNST_STR_4(), String);
}
void PatternSyntaxException::__construct_impl(String* error, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->error), error, String);
	__GC_MV(this, &(this->input), ConstStr::getCNST_STR_4(), String);
}
 PatternSyntaxException::~PatternSyntaxException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void PatternSyntaxException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"PatternSyntaxException", L"~PatternSyntaxException");
	__e_obj1.add(this->error, this);
	error = nullptr;
	__e_obj1.add(this->input, this);
	input = nullptr;
	if(!prepare){
		return;
	}
	Exception::__releaseRegerences(true, ctx);
}
int PatternSyntaxException::getIndex(ThreadContext* ctx) throw() 
{
	return -1;
}
String* PatternSyntaxException::getDescription(ThreadContext* ctx) throw() 
{
	return error;
}
String* PatternSyntaxException::getPattern(ThreadContext* ctx) throw() 
{
	return input;
}
void PatternSyntaxException::__cleanUp(ThreadContext* ctx){
}
}}}

