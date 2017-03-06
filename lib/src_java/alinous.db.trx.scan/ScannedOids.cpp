#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTree.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
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
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
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





bool ScannedOids::__init_done = __init_static_variables();
bool ScannedOids::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScannedOids", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScannedOids::ScannedOids(ThreadContext* ctx) throw()  : IObject(ctx), numHash(256 * 256), numHashMask((256 * 256) - 1), hasheddArray(nullptr)
{
	__GC_MV(this, &(this->hasheddArray), ArrayAllocator<OidsArray>::allocate(ctx, this->numHash), IArrayObject<OidsArray>);
	int maxLoop = this->numHash;
	for(int i = 0; i != maxLoop; ++i)
	{
		this->hasheddArray->set(nullptr,i, ctx);
	}
}
void ScannedOids::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->hasheddArray), ArrayAllocator<OidsArray>::allocate(ctx, this->numHash), IArrayObject<OidsArray>);
	int maxLoop = this->numHash;
	for(int i = 0; i != maxLoop; ++i)
	{
		this->hasheddArray->set(nullptr,i, ctx);
	}
}
 ScannedOids::~ScannedOids() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScannedOids::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScannedOids", L"~ScannedOids");
	__e_obj1.add(this->hasheddArray, this);
	hasheddArray = nullptr;
	if(!prepare){
		return;
	}
}
void ScannedOids::dispose(ThreadContext* ctx) throw() 
{
	int maxLoop = this->numHash;
	for(int i = 0; i != maxLoop; ++i)
	{
		this->hasheddArray->set(nullptr,i, ctx);
	}
}
void ScannedOids::addOid(ScanResultRecord* record, ThreadContext* ctx) throw() 
{
	ScannedOids::Oids* oid = (new(ctx) ScannedOids::Oids(record, ctx));
	ScannedOids::OidsArray* array = getHashedArray(oid, ctx);
	array->addOid(oid, ctx);
}
bool ScannedOids::contains(ScanResultRecord* record, ThreadContext* ctx) throw() 
{
	ScannedOids::Oids* oid = (new(ctx) ScannedOids::Oids(record, ctx));
	ScannedOids::OidsArray* array = getHashedArray(oid, ctx);
	return array != nullptr ? array->contains(oid, ctx) : false;
}
ScannedOids::OidsArray* ScannedOids::getHashedArray(ScannedOids::Oids* oid, ThreadContext* ctx) throw() 
{
	int code = ((int)(oid->getHash(ctx) & this->numHashMask));
	ScannedOids::OidsArray* array = this->hasheddArray->get(code);
	if(array == nullptr)
	{
		array = (new(ctx) ScannedOids::OidsArray(ctx));
		this->hasheddArray->set(array,code, ctx);
	}
	return array;
}
void ScannedOids::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace db {namespace trx {namespace scan {





bool ScannedOids::Oids::__init_done = __init_static_variables();
bool ScannedOids::Oids::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScannedOids::Oids", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScannedOids::Oids::Oids(ScanResultRecord* record, ThreadContext* ctx) throw()  : IObject(ctx), oids(nullptr)
{
	ArrayList<IDatabaseRecord>* list = record->getRecords(ctx);
	int maxLoop = list->size(ctx);
	__GC_MV(this, &(this->oids), ArrayAllocatorPrimitive<long long>::allocatep(ctx, maxLoop), IArrayObjectPrimitive<long long>);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->oids->set(list->get(i, ctx)->getOid(ctx),i, ctx);
	}
}
void ScannedOids::Oids::__construct_impl(ScanResultRecord* record, ThreadContext* ctx) throw() 
{
	ArrayList<IDatabaseRecord>* list = record->getRecords(ctx);
	int maxLoop = list->size(ctx);
	__GC_MV(this, &(this->oids), ArrayAllocatorPrimitive<long long>::allocatep(ctx, maxLoop), IArrayObjectPrimitive<long long>);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->oids->set(list->get(i, ctx)->getOid(ctx),i, ctx);
	}
}
 ScannedOids::Oids::~Oids() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScannedOids::Oids::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Oids", L"~Oids");
	__e_obj1.add(this->oids, this);
	oids = nullptr;
	if(!prepare){
		return;
	}
}
bool ScannedOids::Oids::equals(IObject* other, ThreadContext* ctx) throw() 
{
	ScannedOids::Oids* otherOids = dynamic_cast<ScannedOids::Oids*>(other);
	if(this->oids->length != otherOids->oids->length)
	{
		return false;
	}
	int maxLoop = this->oids->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		if(this->oids->get(i) != otherOids->oids->get(i))
		{
			return false;
		}
	}
	return true;
}
long long ScannedOids::Oids::getHash(ThreadContext* ctx) throw() 
{
	int maxLoop = this->oids->length;
	long long hash = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		hash = hash | this->oids->get(i);
	}
	return hash;
}
void ScannedOids::Oids::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace db {namespace trx {namespace scan {





bool ScannedOids::OidsArray::__init_done = __init_static_variables();
bool ScannedOids::OidsArray::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScannedOids::OidsArray", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScannedOids::OidsArray::OidsArray(ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<ScannedOids::Oids> >::ins(this, (new(ctx) ArrayList<ScannedOids::Oids>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void ScannedOids::OidsArray::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ScannedOids::OidsArray::~OidsArray() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScannedOids::OidsArray::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"OidsArray", L"~OidsArray");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void ScannedOids::OidsArray::addOid(ScannedOids::Oids* oid, ThreadContext* ctx) throw() 
{
	this->list->add(oid, ctx);
}
bool ScannedOids::OidsArray::contains(ScannedOids::Oids* oid, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScannedOids::Oids* lobj = this->list->get(i, ctx);
		if(lobj->equals(oid, ctx))
		{
			return true;
		}
	}
	return false;
}
void ScannedOids::OidsArray::__cleanUp(ThreadContext* ctx){
}
}}}}

