#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile/IncludePreprocessor.h"

namespace alinous {namespace compile {





bool IncludePreprocessor::__init_done = __init_static_variables();
bool IncludePreprocessor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IncludePreprocessor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IncludePreprocessor::IncludePreprocessor(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), path(nullptr), module(nullptr)
{
}
void IncludePreprocessor::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IncludePreprocessor::~IncludePreprocessor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IncludePreprocessor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IncludePreprocessor", L"~IncludePreprocessor");
	__e_obj1.add(this->path, this);
	path = nullptr;
	__e_obj1.add(this->module, this);
	module = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
void IncludePreprocessor::setPath(Literal* path, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->path), path, Literal);
}
String* IncludePreprocessor::getPath(ThreadContext* ctx) throw() 
{
	return this->path->getValue(ctx);
}
bool IncludePreprocessor::analyseDependency(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	return true;
}
bool IncludePreprocessor::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return this->module->getModuleSource(ctx)->analyse(context, leftValue, ctx);
}
int IncludePreprocessor::getLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getLine(ctx);
}
int IncludePreprocessor::getStartPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getStartPosition(ctx);
}
int IncludePreprocessor::getEndLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndLine(ctx);
}
int IncludePreprocessor::getEndPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndPosition(ctx);
}
AbstractSrcElement* IncludePreprocessor::getParent(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getParent(ctx);
}
void IncludePreprocessor::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IAlinousElement::setParent(parent, ctx);
}
AlinousModule* IncludePreprocessor::getModule(ThreadContext* ctx) throw() 
{
	return module;
}
void IncludePreprocessor::setModule(AlinousModule* module, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->module), module, AlinousModule);
}
bool IncludePreprocessor::visit(IAlinousElementVisitor* visitor, AlinousSrc* alinousSrc, ThreadContext* ctx) throw() 
{
	return this->module->getModuleSource(ctx)->visit(visitor, alinousSrc, ctx);
}
void IncludePreprocessor::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->path), (new(ctx) Literal(ctx)), Literal);
		this->path->readData(buff, ctx);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->module), (new(ctx) AlinousModule(ctx)), AlinousModule);
		this->module->readData(buff, ctx);
	}
}
void IncludePreprocessor::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__IncludePreprocessor, ctx);
	bool isnull = (this->path == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->path->writeData(buff, ctx);
	}
	isnull = (this->module == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->module->writeData(buff, ctx);
	}
}
void IncludePreprocessor::__cleanUp(ThreadContext* ctx){
}
}}

