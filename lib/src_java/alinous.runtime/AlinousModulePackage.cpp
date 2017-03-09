#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.runtime/AlinousModulePackage.h"

namespace alinous {namespace runtime {





bool AlinousModulePackage::__init_done = __init_static_variables();
bool AlinousModulePackage::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModulePackage", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModulePackage::AlinousModulePackage(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), segments(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AlinousModulePackage::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousModulePackage::AlinousModulePackage(String* path, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), segments(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	IArrayObject<String>* segments = path->split(ConstStr::getCNST_STR_949(), ctx);
	int maxLoop = segments->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* seg = segments->get(i);
		int dot = seg->indexOf((int)L'.', ctx);
		if(dot >= 0)
		{
			seg = seg->substring(0, dot, ctx);
		}
		if(seg->length(ctx) == 0)
		{
			continue;
		}
		this->segments->add(seg, ctx);
	}
}
void AlinousModulePackage::__construct_impl(String* path, ThreadContext* ctx) throw() 
{
	IArrayObject<String>* segments = path->split(ConstStr::getCNST_STR_949(), ctx);
	int maxLoop = segments->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* seg = segments->get(i);
		int dot = seg->indexOf((int)L'.', ctx);
		if(dot >= 0)
		{
			seg = seg->substring(0, dot, ctx);
		}
		if(seg->length(ctx) == 0)
		{
			continue;
		}
		this->segments->add(seg, ctx);
	}
}
 AlinousModulePackage::~AlinousModulePackage() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModulePackage::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousModulePackage", L"~AlinousModulePackage");
	__e_obj1.add(this->segments, this);
	segments = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
bool AlinousModulePackage::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<AlinousModulePackage*>(obj) != 0)))
	{
		return false;
	}
	AlinousModulePackage* other = dynamic_cast<AlinousModulePackage*>(obj);
	int maxLoop = this->segments->size(ctx);
	if(maxLoop != other->segments->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->segments->get(i, ctx)->equals(other->segments->get(i, ctx), ctx))
		{
			return false;
		}
	}
	return true;
}
String* AlinousModulePackage::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int maxLoop = segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* seg = this->segments->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_953(), ctx);
		}
		buff->append(seg, ctx);
	}
	return buff->toString(ctx);
}
void AlinousModulePackage::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* str = buff->getString(ctx);
		this->segments->add(str, ctx);
	}
}
void AlinousModulePackage::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__AlinousModulePackage, ctx);
	int maxLoop = this->segments->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* str = this->segments->get(i, ctx);
		buff->putString(str, ctx);
	}
}
bool AlinousModulePackage::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
void AlinousModulePackage::__cleanUp(ThreadContext* ctx){
}
}}

