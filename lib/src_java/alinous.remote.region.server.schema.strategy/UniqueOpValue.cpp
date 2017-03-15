#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom/DomArray.h"
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
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.dom/DocumentVariable.h"
#include "alinous.runtime.dom/NetworkAlinousVariableFactory.h"
#include "alinous.remote.region.server.schema.strategy/UniqueOpValue.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {





bool UniqueOpValue::__init_done = __init_static_variables();
bool UniqueOpValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueOpValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueOpValue::UniqueOpValue(List<VariantValue>* values, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), values(nullptr)
{
	GCUtils<List<VariantValue> >::mv(this, &(this->values), values, ctx);
}
void UniqueOpValue::__construct_impl(List<VariantValue>* values, ThreadContext* ctx) throw() 
{
	GCUtils<List<VariantValue> >::mv(this, &(this->values), values, ctx);
}
 UniqueOpValue::~UniqueOpValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueOpValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UniqueOpValue", L"~UniqueOpValue");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
List<VariantValue>* UniqueOpValue::getValues(ThreadContext* ctx) throw() 
{
	return values;
}
void UniqueOpValue::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousVariable* v = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
		if(v == nullptr || !((dynamic_cast<VariantValue*>(v) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1192(), ctx));
		}
		this->values->add(static_cast<VariantValue*>(v), ctx);
	}
}
void UniqueOpValue::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = this->values->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		value->writeData(buff, ctx);
	}
}
UniqueOpValue* UniqueOpValue::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	UniqueOpValue* op = (new(ctx) UniqueOpValue((new(ctx) ArrayList<VariantValue>(ctx)), ctx));
	op->readData(buff, ctx);
	return op;
}
void UniqueOpValue::__cleanUp(ThreadContext* ctx){
}
}}}}}}

