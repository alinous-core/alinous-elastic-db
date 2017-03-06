#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"

namespace alinous {namespace compile {namespace declare {





bool VirtualTable::__init_done = __init_static_variables();
bool VirtualTable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VirtualTable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VirtualTable::VirtualTable(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), list(GCUtils<ArrayList<VirtualTable::MethodPair> >::ins(this, (new(ctx) ArrayList<VirtualTable::MethodPair>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void VirtualTable::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VirtualTable::~VirtualTable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VirtualTable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"VirtualTable", L"~VirtualTable");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
void VirtualTable::addVirtualFunction(AlinousClass* clazz, ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	VirtualTable::MethodPair* pair = (new(ctx) VirtualTable::MethodPair(clazz, method, ctx));
	this->list->add(pair, ctx);
}
ClassMethodFunction* VirtualTable::getMethod(AlinousClass* clazz, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VirtualTable::MethodPair* pair = this->list->get(i, ctx);
		if(pair->clazz == clazz)
		{
			return pair->func;
		}
	}
	return nullptr;
}
void VirtualTable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousElement* clazz = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(clazz == nullptr || !((dynamic_cast<AlinousClass*>(clazz) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_952(), ctx));
		}
		IAlinousElement* func = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(func == nullptr || !((dynamic_cast<ClassMethodFunction*>(func) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_971(), ctx));
		}
		VirtualTable::MethodPair* pair = (new(ctx) VirtualTable::MethodPair(static_cast<AlinousClass*>(clazz), static_cast<ClassMethodFunction*>(func), ctx));
		this->list->add(pair, ctx);
	}
}
void VirtualTable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__VirtualTable, ctx);
	int maxLoop = this->list->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VirtualTable::MethodPair* pair = this->list->get(i, ctx);
		pair->clazz->writeData(buff, ctx);
		pair->func->writeData(buff, ctx);
	}
}
bool VirtualTable::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
void VirtualTable::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace compile {namespace declare {





bool VirtualTable::MethodPair::__init_done = __init_static_variables();
bool VirtualTable::MethodPair::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VirtualTable::MethodPair", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VirtualTable::MethodPair::MethodPair(AlinousClass* clazz, ClassMethodFunction* func, ThreadContext* ctx) throw()  : IObject(ctx), clazz(nullptr), func(nullptr)
{
	__GC_MV(this, &(this->clazz), clazz, AlinousClass);
	__GC_MV(this, &(this->func), func, ClassMethodFunction);
}
void VirtualTable::MethodPair::__construct_impl(AlinousClass* clazz, ClassMethodFunction* func, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->clazz), clazz, AlinousClass);
	__GC_MV(this, &(this->func), func, ClassMethodFunction);
}
 VirtualTable::MethodPair::~MethodPair() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VirtualTable::MethodPair::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MethodPair", L"~MethodPair");
	__e_obj1.add(this->clazz, this);
	clazz = nullptr;
	__e_obj1.add(this->func, this);
	func = nullptr;
	if(!prepare){
		return;
	}
}
void VirtualTable::MethodPair::__cleanUp(ThreadContext* ctx){
}
}}}

