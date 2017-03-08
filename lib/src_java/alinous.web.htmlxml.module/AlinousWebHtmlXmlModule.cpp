#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.web.htmlxml.module/AbstractSerializedHtmlPart.h"
#include "alinous.web.htmlxml.module/SerializeContext.h"
#include "alinous.web.htmlxml/HtmlTopObject.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParserConstants.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParser.h"
#include "alinous.web.htmlxml.module/AlinousWebHtmlXmlModule.h"

namespace alinous {namespace web {namespace htmlxml {namespace module {





bool AlinousWebHtmlXmlModule::__init_done = __init_static_variables();
bool AlinousWebHtmlXmlModule::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousWebHtmlXmlModule", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousWebHtmlXmlModule::AlinousWebHtmlXmlModule(String* path, ThreadContext* ctx) throw()  : IObject(ctx), file(nullptr), obj(nullptr), stack(nullptr)
{
	__GC_MV(this, &(this->file), (new(ctx) File(path, ctx)), File);
}
void AlinousWebHtmlXmlModule::__construct_impl(String* path, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->file), (new(ctx) File(path, ctx)), File);
}
 AlinousWebHtmlXmlModule::AlinousWebHtmlXmlModule(File* file, ThreadContext* ctx) throw()  : IObject(ctx), file(nullptr), obj(nullptr), stack(nullptr)
{
	__GC_MV(this, &(this->file), file, File);
}
void AlinousWebHtmlXmlModule::__construct_impl(File* file, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->file), file, File);
}
 AlinousWebHtmlXmlModule::~AlinousWebHtmlXmlModule() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousWebHtmlXmlModule::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousWebHtmlXmlModule", L"~AlinousWebHtmlXmlModule");
	__e_obj1.add(this->file, this);
	file = nullptr;
	__e_obj1.add(this->obj, this);
	obj = nullptr;
	__e_obj1.add(this->stack, this);
	stack = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousWebHtmlXmlModule::compile(ThreadContext* ctx)
{
	FileReader* reader = 0;
	{
		try
		{
			reader = (new(ctx) FileReader(this->file, ctx));
			HtmlXmlParser* parser = (new(ctx) HtmlXmlParser(reader, ctx));
			__GC_MV(this, &(this->obj), parser->parse(ctx), HtmlTopObject);
		}
		catch(Throwable* e)
		{
			throw e;
		}
	}
	SerializeContext* context = (new(ctx) SerializeContext(ctx));
	this->obj->serialize(context, ctx);
	GCUtils<Stack<AbstractSerializedHtmlPart> >::mv(this, &(this->stack), context->stack, ctx);
}
void AlinousWebHtmlXmlModule::prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	Stack<AbstractSerializedHtmlPart>* stack = this->stack;
	int maxLoop = stack->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractSerializedHtmlPart* part = stack->get(i, ctx);
		part->prepare(context, ctx);
	}
}
String* AlinousWebHtmlXmlModule::toStaticString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int maxLoop = stack->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractSerializedHtmlPart* part = stack->get(i, ctx);
		buff->append(part->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
void AlinousWebHtmlXmlModule::execute(ScriptMachine* machine, AlinousModule* alnsModule, Writer* writer, bool debug, ThreadContext* ctx)
{
	int maxLoop = stack->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractSerializedHtmlPart* part = stack->get(i, ctx);
		part->execute(machine, writer, debug, ctx);
	}
}
File* AlinousWebHtmlXmlModule::getFile(ThreadContext* ctx) throw() 
{
	return file;
}
void AlinousWebHtmlXmlModule::__cleanUp(ThreadContext* ctx){
}
}}}}

