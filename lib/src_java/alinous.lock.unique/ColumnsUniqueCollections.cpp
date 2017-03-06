#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.lock/LockObject.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.db/AlinousDbException.h"
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
#include "alinous.runtime.variant/IVariantData.h"
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
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.lock.unique/UniqueExclusiveException.h"
#include "alinous.lock.unique/ColumnsUniqueCollections.h"
#include "alinous.lock.unique/TableUniqueCollections.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.lock.unique/UniqueLockClientFactory.h"

namespace alinous {namespace lock {namespace unique {





bool ColumnsUniqueCollections::__init_done = __init_static_variables();
bool ColumnsUniqueCollections::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ColumnsUniqueCollections", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ColumnsUniqueCollections::ColumnsUniqueCollections(ThreadContext* ctx) throw()  : IObject(ctx), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), locks(GCUtils<Map<String,UniqueExclusiveLock> >::ins(this, (new(ctx) HashMap<String,UniqueExclusiveLock>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void ColumnsUniqueCollections::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ColumnsUniqueCollections::~ColumnsUniqueCollections() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ColumnsUniqueCollections::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ColumnsUniqueCollections", L"~ColumnsUniqueCollections");
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->locks, this);
	locks = nullptr;
	if(!prepare){
		return;
	}
}
UniqueExclusiveLock* ColumnsUniqueCollections::lockWithCheck(ScanUnique* unique, IDatabaseRecord* record, bool throwex, ThreadContext* ctx)
{
	String* lockString = getLockValueString(unique, record, ctx);
	UniqueExclusiveLock* lock = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		lock = this->locks->get(lockString, ctx);
		if(lock != nullptr)
		{
			if(throwex)
			{
				throw (new(ctx) UniqueExclusiveException(lockString->clone(ctx)->append(ConstStr::getCNST_STR_1759(), ctx), ctx));
			}
			{
				try
				{
					lock->lock(ctx);
				}
				catch(InterruptedException* e)
				{
					throw (new(ctx) UniqueExclusiveException(ConstStr::getCNST_STR_1760(), e, ctx));
				}
			}
			return lock;
		}
		lock = (new(ctx) UniqueExclusiveLock(unique, record, ctx));
		this->locks->put(lockString, lock, ctx);
		{
			try
			{
				lock->lock(ctx);
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) UniqueExclusiveException(ConstStr::getCNST_STR_1760(), e, ctx));
			}
		}
	}
	return lock;
}
bool ColumnsUniqueCollections::unlock(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	String* lockString = getLockValueString(unique, record, ctx);
	UniqueExclusiveLock* lock = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		lock = this->locks->get(lockString, ctx);
		if(lock == nullptr)
		{
			return this->locks->isEmpty(ctx);
		}
		lock->unlock(ctx);
		if(lock->getCount(ctx) == 0)
		{
			this->locks->remove(lockString, ctx);
			return this->locks->isEmpty(ctx);
		}
	}
	return false;
}
UniqueExclusiveLock* ColumnsUniqueCollections::getLock(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx)
{
	String* lockString = getLockValueString(unique, value, ctx);
	UniqueExclusiveLock* lock = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		lock = this->locks->get(lockString, ctx);
	}
	return lock;
}
void ColumnsUniqueCollections::dispose(ThreadContext* ctx) throw() 
{
}
String* ColumnsUniqueCollections::getLockValueString(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	ArrayList<TableColumnMetadata>* colslist = unique->getUniqueColList(ctx);
	int maxLoop = colslist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = colslist->get(i, ctx);
		VariantValue* vv = value->getColumnValue(col->columnOrder, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_888(), ctx);
		}
		String* str = vv->toString(ctx);
		buff->append(str, ctx);
	}
	return buff->toString(ctx);
}
void ColumnsUniqueCollections::__cleanUp(ThreadContext* ctx){
}
}}}

