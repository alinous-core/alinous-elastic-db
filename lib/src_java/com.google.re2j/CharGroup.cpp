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





const StaticArrayObjectPrimitive<int> CharGroup::__code1 = {0x30, 0x39};
IArrayObjectPrimitive<int>* CharGroup::code1 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code1);
const StaticArrayObjectPrimitive<int> CharGroup::__code2 = {0x9, 0xa, 0xc, 0xd, 0x20, 0x20};
IArrayObjectPrimitive<int>* CharGroup::code2 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code2);
const StaticArrayObjectPrimitive<int> CharGroup::__code3 = {0x30, 0x39, 0x41, 0x5a, 0x5f, 0x5f, 0x61, 0x7a};
IArrayObjectPrimitive<int>* CharGroup::code3 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code3);
StaticMap<String, CharGroup> CharGroup::__HASH__PERL_GROUPS = {{ConstStr::getCNST_STR_324(), (CharGroup(+1, code1, nullptr))}, {ConstStr::getCNST_STR_325(), (CharGroup(-1, code1, nullptr))}, {ConstStr::getCNST_STR_326(), (CharGroup(+1, code2, nullptr))}, {ConstStr::getCNST_STR_327(), (CharGroup(-1, code2, nullptr))}, {ConstStr::getCNST_STR_328(), (CharGroup(+1, code3, nullptr))}, {ConstStr::getCNST_STR_329(), (CharGroup(-1, code3, nullptr))}};
StaticMap<String,CharGroup>* CharGroup::PERL_GROUPS = (StaticMap<String,CharGroup>*)&CharGroup::__HASH__PERL_GROUPS;
const StaticArrayObjectPrimitive<int> CharGroup::__code4 = {0x30, 0x39, 0x41, 0x5a, 0x61, 0x7a};
IArrayObjectPrimitive<int>* CharGroup::code4 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code4);
const StaticArrayObjectPrimitive<int> CharGroup::__code5 = {0x41, 0x5a, 0x61, 0x7a};
IArrayObjectPrimitive<int>* CharGroup::code5 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code5);
const StaticArrayObjectPrimitive<int> CharGroup::__code6 = {0x0, 0x7f};
IArrayObjectPrimitive<int>* CharGroup::code6 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code6);
const StaticArrayObjectPrimitive<int> CharGroup::__code7 = {0x9, 0x9, 0x20, 0x20};
IArrayObjectPrimitive<int>* CharGroup::code7 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code7);
const StaticArrayObjectPrimitive<int> CharGroup::__code8 = {0x0, 0x1f, 0x7f, 0x7f};
IArrayObjectPrimitive<int>* CharGroup::code8 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code8);
const StaticArrayObjectPrimitive<int> CharGroup::__code9 = {0x30, 0x39};
IArrayObjectPrimitive<int>* CharGroup::code9 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code9);
const StaticArrayObjectPrimitive<int> CharGroup::__code10 = {0x21, 0x7e};
IArrayObjectPrimitive<int>* CharGroup::code10 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code10);
const StaticArrayObjectPrimitive<int> CharGroup::__code11 = {0x61, 0x7a};
IArrayObjectPrimitive<int>* CharGroup::code11 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code11);
const StaticArrayObjectPrimitive<int> CharGroup::__code12 = {0x20, 0x7e};
IArrayObjectPrimitive<int>* CharGroup::code12 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code12);
const StaticArrayObjectPrimitive<int> CharGroup::__code13 = {0x21, 0x2f, 0x3a, 0x40, 0x5b, 0x60, 0x7b, 0x7e};
IArrayObjectPrimitive<int>* CharGroup::code13 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code13);
const StaticArrayObjectPrimitive<int> CharGroup::__code14 = {0x9, 0xd, 0x20, 0x20};
IArrayObjectPrimitive<int>* CharGroup::code14 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code14);
const StaticArrayObjectPrimitive<int> CharGroup::__code15 = {0x41, 0x5a};
IArrayObjectPrimitive<int>* CharGroup::code15 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code15);
const StaticArrayObjectPrimitive<int> CharGroup::__code16 = {0x30, 0x39, 0x41, 0x5a, 0x5f, 0x5f, 0x61, 0x7a};
IArrayObjectPrimitive<int>* CharGroup::code16 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code16);
const StaticArrayObjectPrimitive<int> CharGroup::__code17 = {0x30, 0x39, 0x41, 0x46, 0x61, 0x66};
IArrayObjectPrimitive<int>* CharGroup::code17 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__code17);
StaticMap<String, CharGroup> CharGroup::__HASH__POSIX_GROUPS = {{ConstStr::getCNST_STR_330(), (CharGroup(+1, code4, nullptr))}, {ConstStr::getCNST_STR_331(), (CharGroup(-1, code4, nullptr))}, {ConstStr::getCNST_STR_332(), (CharGroup(+1, code5, nullptr))}, {ConstStr::getCNST_STR_333(), (CharGroup(-1, code5, nullptr))}, {ConstStr::getCNST_STR_334(), (CharGroup(+1, code6, nullptr))}, {ConstStr::getCNST_STR_335(), (CharGroup(-1, code6, nullptr))}, {ConstStr::getCNST_STR_336(), (CharGroup(+1, code7, nullptr))}, {ConstStr::getCNST_STR_337(), (CharGroup(-1, code7, nullptr))}, {ConstStr::getCNST_STR_338(), (CharGroup(+1, code8, nullptr))}, {ConstStr::getCNST_STR_339(), (CharGroup(-1, code8, nullptr))}, {ConstStr::getCNST_STR_340(), (CharGroup(+1, code9, nullptr))}, {ConstStr::getCNST_STR_341(), (CharGroup(-1, code9, nullptr))}, {ConstStr::getCNST_STR_342(), (CharGroup(+1, code10, nullptr))}, {ConstStr::getCNST_STR_343(), (CharGroup(-1, code10, nullptr))}, {ConstStr::getCNST_STR_344(), (CharGroup(+1, code11, nullptr))}, {ConstStr::getCNST_STR_345(), (CharGroup(-1, code11, nullptr))}, {ConstStr::getCNST_STR_346(), (CharGroup(+1, code12, nullptr))}, {ConstStr::getCNST_STR_347(), (CharGroup(-1, code12, nullptr))}, {ConstStr::getCNST_STR_348(), (CharGroup(+1, code13, nullptr))}, {ConstStr::getCNST_STR_349(), (CharGroup(-1, code13, nullptr))}, {ConstStr::getCNST_STR_350(), (CharGroup(+1, code14, nullptr))}, {ConstStr::getCNST_STR_351(), (CharGroup(-1, code14, nullptr))}, {ConstStr::getCNST_STR_352(), (CharGroup(+1, code15, nullptr))}, {ConstStr::getCNST_STR_353(), (CharGroup(-1, code15, nullptr))}, {ConstStr::getCNST_STR_354(), (CharGroup(+1, code16, nullptr))}, {ConstStr::getCNST_STR_355(), (CharGroup(-1, code16, nullptr))}, {ConstStr::getCNST_STR_356(), (CharGroup(+1, code17, nullptr))}, {ConstStr::getCNST_STR_357(), (CharGroup(-1, code17, nullptr))}};
StaticMap<String,CharGroup>* CharGroup::POSIX_GROUPS = (StaticMap<String,CharGroup>*)&CharGroup::__HASH__POSIX_GROUPS;
bool CharGroup::__init_done = __init_static_variables();
bool CharGroup::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CharGroup", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CharGroup::CharGroup(int sign, IArrayObjectPrimitive<int>* cls, ThreadContext* ctx) throw()  : IObject(ctx), sign(0), cls(nullptr)
{
	this->sign = sign;
	__GC_MV(this, &(this->cls), cls, IArrayObjectPrimitive<int>);
}
void CharGroup::__construct_impl(int sign, IArrayObjectPrimitive<int>* cls, ThreadContext* ctx) throw() 
{
	this->sign = sign;
	__GC_MV(this, &(this->cls), cls, IArrayObjectPrimitive<int>);
}
 CharGroup::~CharGroup() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CharGroup::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CharGroup", L"~CharGroup");
	__e_obj1.add(this->cls, this);
	cls = nullptr;
	if(!prepare){
		return;
	}
}
void CharGroup::__cleanUp(ThreadContext* ctx){
}
}}}

