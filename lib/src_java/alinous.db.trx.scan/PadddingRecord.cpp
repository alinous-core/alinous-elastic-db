#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.trx.scan/PadddingRecord.h"

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
long long PadddingRecord::getPosition(ThreadContext* ctx) throw() 
{
	return -1;
}
PadddingRecord* PadddingRecord::fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	PadddingRecord* rec = (new(ctx) PadddingRecord(fetcher->fetchInt(ctx), ctx));
	return rec;
}
void PadddingRecord::__cleanUp(ThreadContext* ctx){
}
}}}}

