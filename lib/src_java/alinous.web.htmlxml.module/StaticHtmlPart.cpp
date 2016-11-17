#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {namespace module {





bool StaticHtmlPart::__init_done = __init_static_variables();
bool StaticHtmlPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StaticHtmlPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StaticHtmlPart::StaticHtmlPart(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSerializedHtmlPart(ctx), buff(__GC_INS(this, (new(ctx) StringBuilder(ctx)), StringBuilder)), text(nullptr)
{
	this->type = AbstractSerializedHtmlPart::TYPE_STATIC_PART;
}
void StaticHtmlPart::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractSerializedHtmlPart::TYPE_STATIC_PART;
}
 StaticHtmlPart::~StaticHtmlPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StaticHtmlPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StaticHtmlPart", L"~StaticHtmlPart");
	__e_obj1.add(this->buff, this);
	buff = nullptr;
	__e_obj1.add(this->text, this);
	text = nullptr;
	if(!prepare){
		return;
	}
	AbstractSerializedHtmlPart::__releaseRegerences(true, ctx);
}
void StaticHtmlPart::add(String* str, ThreadContext* ctx) throw() 
{
	this->buff->append(str, ctx);
}
String* StaticHtmlPart::toString(ThreadContext* ctx) throw() 
{
	return this->buff->toString(ctx);
}
void StaticHtmlPart::prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->text), this->buff->toString(ctx), String);
}
void StaticHtmlPart::execute(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx)
{
	writer->write(this->text, ctx);
}
}}}}

