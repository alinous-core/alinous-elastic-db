#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
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
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
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
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"

namespace alinous {namespace db {namespace trx {namespace scan {





bool ScanResultIndexKey::__init_done = __init_static_variables();
bool ScanResultIndexKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanResultIndexKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanResultIndexKey::ScanResultIndexKey(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), ICommandData(ctx), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void ScanResultIndexKey::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ScanResultIndexKey::~ScanResultIndexKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanResultIndexKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanResultIndexKey", L"~ScanResultIndexKey");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
void ScanResultIndexKey::addKeyValue(VariantValue* vv, ThreadContext* ctx) throw() 
{
	this->values->add(vv, ctx);
}
int ScanResultIndexKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	ScanResultIndexKey* otherIndex = static_cast<ScanResultIndexKey*>(another);
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		VariantValue* other = otherIndex->values->get(i, ctx);
		int result = value->compareTo(other, ctx);
		if(result != 0)
		{
			return result;
		}
	}
	return 0;
}
int ScanResultIndexKey::getNumCols(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
VariantValue* ScanResultIndexKey::get(int index, ThreadContext* ctx) throw() 
{
	return this->values->get(index, ctx);
}
bool ScanResultIndexKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	ScanResultIndexKey* otherIndex = dynamic_cast<ScanResultIndexKey*>(obj);
	int maxLoop = this->values->size(ctx);
	if(otherIndex->getNumCols(ctx) != maxLoop)
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		VariantValue* other = otherIndex->values->get(i, ctx);
		int result = value->compareTo(other, ctx);
		if(result != 0)
		{
			return false;
		}
	}
	return true;
}
void ScanResultIndexKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeKey::TYPE_SCAN_RESULT_INDEX_KEY, ctx);
	int maxLoop = this->values->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		value->appendToEntry(builder, ctx);
	}
}
int ScanResultIndexKey::size(ThreadContext* ctx)
{
	int total = 4 + 4;
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		total += value->bufferSize(ctx);
	}
	return total;
}
void ScanResultIndexKey::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousVariable* value = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
		if(value == nullptr || !((dynamic_cast<VariantValue*>(value) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1700(), ctx));
		}
		VariantValue* vv = static_cast<VariantValue*>(value);
		this->values->add(vv, ctx);
	}
}
void ScanResultIndexKey::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = this->values->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		value->writeData(buff, ctx);
	}
}
BTreeIndexKey* ScanResultIndexKey::fetchFromEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue::valueFromFetcher(fetcher, ctx);
	}
	return indexKey;
}
ScanResultIndexKey* ScanResultIndexKey::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	ScanResultIndexKey* key = (new(ctx) ScanResultIndexKey(ctx));
	key->readData(buff, ctx);
	return key;
}
void ScanResultIndexKey::__cleanUp(ThreadContext* ctx){
}
int ScanResultIndexKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}}}

