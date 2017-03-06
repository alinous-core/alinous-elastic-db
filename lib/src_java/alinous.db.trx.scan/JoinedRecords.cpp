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





bool JoinedRecords::__init_done = __init_static_variables();
bool JoinedRecords::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JoinedRecords", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JoinedRecords::JoinedRecords(ThreadContext* ctx) throw()  : IObject(ctx), oid(0), lockingMode(0), tableId(nullptr)
{
}
void JoinedRecords::__construct_impl(ThreadContext* ctx) throw() 
{
}
 JoinedRecords::JoinedRecords(ScanTableIdentifier* tableId, long long oid, int lockingMode, ThreadContext* ctx) throw()  : IObject(ctx), oid(0), lockingMode(0), tableId(nullptr)
{
	this->oid = oid;
	this->lockingMode = lockingMode;
}
void JoinedRecords::__construct_impl(ScanTableIdentifier* tableId, long long oid, int lockingMode, ThreadContext* ctx) throw() 
{
	this->oid = oid;
	this->lockingMode = lockingMode;
}
 JoinedRecords::~JoinedRecords() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JoinedRecords::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JoinedRecords", L"~JoinedRecords");
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	if(!prepare){
		return;
	}
}
JoinedRecords* JoinedRecords::copy(ThreadContext* ctx) throw() 
{
	JoinedRecords* newRec = (new(ctx) JoinedRecords(ctx));
	newRec->oid = this->oid;
	newRec->lockingMode = this->lockingMode;
	__GC_MV(newRec, &(newRec->tableId), this->tableId, ScanTableIdentifier);
	return newRec;
}
int JoinedRecords::getArchiveSize(ThreadContext* ctx) throw() 
{
	return 8 + 4 + tableId->getArchiveSize(ctx);
}
void JoinedRecords::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putLong(this->oid, ctx);
	builder->putInt(this->lockingMode, ctx);
	this->tableId->appendToEntry(builder, ctx);
}
long long JoinedRecords::getOid(ThreadContext* ctx) throw() 
{
	return oid;
}
void JoinedRecords::setOid(long long oid, ThreadContext* ctx) throw() 
{
	this->oid = oid;
}
int JoinedRecords::getLockingMode(ThreadContext* ctx) throw() 
{
	return lockingMode;
}
void JoinedRecords::setLockingMode(int lockingMode, ThreadContext* ctx) throw() 
{
	this->lockingMode = lockingMode;
}
ScanTableIdentifier* JoinedRecords::getTableId(ThreadContext* ctx) throw() 
{
	return tableId;
}
JoinedRecords* JoinedRecords::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	JoinedRecords* rec = (new(ctx) JoinedRecords(ctx));
	rec->oid = fetcher->fetchLong(ctx);
	rec->lockingMode = fetcher->fetchInt(ctx);
	__GC_MV(rec, &(rec->tableId), ScanTableIdentifier::valueFromFetcher(fetcher, ctx), ScanTableIdentifier);
	return rec;
}
void JoinedRecords::__cleanUp(ThreadContext* ctx){
}
}}}}

