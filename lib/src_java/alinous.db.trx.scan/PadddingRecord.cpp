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





bool PadddingRecord::__init_done = __init_static_variables();
bool PadddingRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"PadddingRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 PadddingRecord::PadddingRecord(int paddingSize, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseRecord(ctx), paddingSize(0), nullValue(__GC_INS(this, (new(ctx) VariantValue(ctx)), VariantValue))
{
	this->paddingSize = paddingSize;
}
void PadddingRecord::__construct_impl(int paddingSize, ThreadContext* ctx) throw() 
{
	this->paddingSize = paddingSize;
}
 PadddingRecord::~PadddingRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void PadddingRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"PadddingRecord", L"~PadddingRecord");
	__e_obj1.add(this->nullValue, this);
	nullValue = nullptr;
	if(!prepare){
		return;
	}
}
void PadddingRecord::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeValue::TYPE_PADDING_RECORD, ctx);
	builder->putInt(this->paddingSize, ctx);
}
int PadddingRecord::diskSize(ThreadContext* ctx)
{
	return 8;
}
bool PadddingRecord::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return IObject::equals(obj, ctx);
}
IValueFetcher* PadddingRecord::getFetcher(ThreadContext* ctx) throw() 
{
	return nullptr;
}
int PadddingRecord::getKind(ThreadContext* ctx) throw() 
{
	return IDatabaseRecord::NULL_PADDING;
}
VariantValue* PadddingRecord::getColumnValue(int colOrder, ThreadContext* ctx) throw() 
{
	return this->nullValue;
}
int PadddingRecord::getNumValues(ThreadContext* ctx) throw() 
{
	return this->paddingSize;
}
long long PadddingRecord::getInsertedCommitId(ThreadContext* ctx) throw() 
{
	return 0;
}
long long PadddingRecord::getLastUpdateCommitId(ThreadContext* ctx) throw() 
{
	return 0;
}
long long PadddingRecord::getDeletedCommitId(ThreadContext* ctx) throw() 
{
	return 0;
}
ArrayList<VariantValue>* PadddingRecord::getValues(ThreadContext* ctx) throw() 
{
	int maxLoop = this->paddingSize;
	ArrayList<VariantValue>* list = (new(ctx) ArrayList<VariantValue>(ctx));
	for(int i = 0; i != maxLoop; ++i)
	{
		list->add(this->nullValue, ctx);
	}
	return list;
}
void PadddingRecord::setValue(int index, VariantValue* value, ThreadContext* ctx) throw() 
{
}
void PadddingRecord::addValue(VariantValue* vv, ThreadContext* ctx) throw() 
{
}
long long PadddingRecord::getOid(ThreadContext* ctx) throw() 
{
	return -1;
}
long long PadddingRecord::getMaxCommitId(ThreadContext* ctx) throw() 
{
	return 0;
}
int PadddingRecord::getNumColumn(ThreadContext* ctx) throw() 
{
	return 0;
}
void PadddingRecord::setLastUpdateCommitId(long long commitId, ThreadContext* ctx) throw() 
{
}
void PadddingRecord::setInsertedCommitId(long long insertedCommitId, ThreadContext* ctx) throw() 
{
}
PadddingRecord* PadddingRecord::fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	PadddingRecord* rec = (new(ctx) PadddingRecord(fetcher->fetchInt(ctx), ctx));
	return rec;
}
void PadddingRecord::__cleanUp(ThreadContext* ctx){
}
}}}}

