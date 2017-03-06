#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
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
#include "alinous.btree/IBTree.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.trx.scan/PadddingRecord.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.trx.scan/GroupedScanResultRecord.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.db.trx.scan/JoinedRecords.h"
#include "alinous.db.trx.scan/ScannedOids.h"
#include "alinous.db.trx.scan/ScanResultScanner.h"

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
 ScanResultIndexKey::ScanResultIndexKey(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
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
void ScanResultIndexKey::__cleanUp(ThreadContext* ctx){
}
int ScanResultIndexKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}}}

