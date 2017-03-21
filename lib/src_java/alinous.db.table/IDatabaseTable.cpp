#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"

namespace alinous {namespace db {namespace table {




bool IDatabaseTable::__init_done = __init_static_variables();
bool IDatabaseTable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDatabaseTable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDatabaseTable::IDatabaseTable(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IDatabaseTable::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IDatabaseTable::~IDatabaseTable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDatabaseTable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IDatabaseTable::__cleanUp(ThreadContext* ctx){
}
}}}

