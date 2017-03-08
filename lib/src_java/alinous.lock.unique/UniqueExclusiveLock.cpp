#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"

namespace alinous {namespace lock {namespace unique {





bool UniqueExclusiveLock::__init_done = __init_static_variables();
bool UniqueExclusiveLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveLock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueExclusiveLock::UniqueExclusiveLock(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx) throw()  : IObject(ctx), gate(nullptr), unique(nullptr), record(nullptr), count(0)
{
	__GC_MV(this, &(this->gate), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
	__GC_MV(this, &(this->unique), unique, ScanUnique);
	__GC_MV(this, &(this->record), record, IDatabaseRecord);
	this->count = 0;
}
void UniqueExclusiveLock::__construct_impl(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->gate), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
	__GC_MV(this, &(this->unique), unique, ScanUnique);
	__GC_MV(this, &(this->record), record, IDatabaseRecord);
	this->count = 0;
}
 UniqueExclusiveLock::~UniqueExclusiveLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueExclusiveLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveLock", L"~UniqueExclusiveLock");
	__e_obj1.add(this->gate, this);
	gate = nullptr;
	__e_obj1.add(this->unique, this);
	unique = nullptr;
	__e_obj1.add(this->record, this);
	record = nullptr;
	if(!prepare){
		return;
	}
}
String* UniqueExclusiveLock::toString(ThreadContext* ctx) throw() 
{
	return makeString(unique, record, ctx);
}
void UniqueExclusiveLock::lock(ThreadContext* ctx)
{
	gate->close(ctx);
	this->count ++ ;
}
void UniqueExclusiveLock::unlock(ThreadContext* ctx) throw() 
{
	{
		try
		{
			gate->open(ctx);
		}
		catch(InterruptedException* ignore)
		{
			ignore->printStackTrace(ctx);
		}
	}
	this->count -- ;
}
ScanUnique* UniqueExclusiveLock::getUnique(ThreadContext* ctx) throw() 
{
	return unique;
}
IDatabaseRecord* UniqueExclusiveLock::getRecord(ThreadContext* ctx) throw() 
{
	return record;
}
int UniqueExclusiveLock::getCount(ThreadContext* ctx) throw() 
{
	return count;
}
String* UniqueExclusiveLock::makeString(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	StringBuffer* vbuff = (new(ctx) StringBuffer(ctx));
	buff->append(unique->getTableFullName(ctx), ctx);
	ArrayList<TableColumnMetadata>* list = unique->getUniqueColList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = list->get(i, ctx);
		buff->append(ConstStr::getCNST_STR_888(), ctx);
		buff->append(col->name, ctx);
		if(i != 0)
		{
			vbuff->append(ConstStr::getCNST_STR_888(), ctx);
		}
		VariantValue* vv = record->getColumnValue(col->columnOrder, ctx);
		vbuff->append(vv->getString(ctx), ctx);
	}
	buff->append(vbuff->toString(ctx), ctx);
	return buff->toString(ctx);
}
void UniqueExclusiveLock::__cleanUp(ThreadContext* ctx){
}
}}}

