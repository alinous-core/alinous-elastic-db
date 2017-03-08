#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.runtime.dom/DomArray.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom/IVariableClassOperationCaller.h"
#include "alinous.runtime.dom/VariableOperationCaller.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.dom/DocumentVariable.h"
#include "alinous.runtime.dom/NetworkAlinousVariableFactory.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.runtime.dom/DomVariableDebugXmlFactory.h"
#include "alinous.runtime.dom/DomVariableContainer.h"

namespace alinous {namespace runtime {namespace dom {





bool NetworkAlinousVariableFactory::__init_done = __init_static_variables();
bool NetworkAlinousVariableFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NetworkAlinousVariableFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NetworkAlinousVariableFactory::NetworkAlinousVariableFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void NetworkAlinousVariableFactory::__construct_impl(ThreadContext* ctx) throw() 
{
}
 NetworkAlinousVariableFactory::~NetworkAlinousVariableFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NetworkAlinousVariableFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* NetworkAlinousVariableFactory::fromNetworkData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	IAlinousVariable* val = nullptr;
	int type = buff->getInt(ctx);
	switch(type) {
	case ICommandData::__IdentifierVariable:
		val = (new(ctx) IdentifierVariable(ctx));
		break ;
	case ICommandData::__VariantValue:
		val = (new(ctx) VariantValue(ctx));
		break ;
	case ICommandData::__DocumentVariable:
		val = (new(ctx) DocumentVariable(ctx));
		break ;
	case ICommandData::__DomArray:
		val = (new(ctx) DomArray(ctx));
		break ;
	case ICommandData::__DomVariable:
		val = (new(ctx) DomVariable(ctx));
		break ;
	case ICommandData::__BigDecimalVariable:
		val = (new(ctx) BigDecimalVariable(ctx));
		break ;
	case ICommandData::__BoolVariable:
		val = (new(ctx) BoolVariable(ctx));
		break ;
	case ICommandData::__ByteVariable:
		val = (new(ctx) ByteVariable(ctx));
		break ;
	case ICommandData::__CharVariable:
		val = (new(ctx) CharVariable(ctx));
		break ;
	case ICommandData::__DoubleVariable:
		val = (new(ctx) DoubleVariable(ctx));
		break ;
	case ICommandData::__FloatVariable:
		val = (new(ctx) FloatVariable(ctx));
		break ;
	case ICommandData::__IntegerVariable:
		val = (new(ctx) IntegerVariable(ctx));
		break ;
	case ICommandData::__LongVariable:
		val = (new(ctx) LongVariable(ctx));
		break ;
	case ICommandData::__ShortVariable:
		val = (new(ctx) ShortVariable(ctx));
		break ;
	case ICommandData::__StringVariable:
		val = (new(ctx) StringVariable(ctx));
		break ;
	case ICommandData::__TimestampVariable:
		val = (new(ctx) TimestampVariable(ctx));
		break ;
	case ICommandData::__TimeVariable:
		val = (new(ctx) TimeVariable(ctx));
		break ;
	case ICommandData::__TypedVariableArray:
		val = (new(ctx) TypedVariableArray(ctx));
		break ;
	case ICommandData::__AlinousClassVariable:
		val = (new(ctx) AlinousClassVariable(ctx));
		break ;
	default:
		return nullptr;
		break;
	}
	val->readData(buff, ctx);
	return val;
}
void NetworkAlinousVariableFactory::__cleanUp(ThreadContext* ctx){
}
}}}

