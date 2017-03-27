#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/IScannableIndex.h"

namespace alinous {namespace db {namespace table {




bool IScannableIndex::__init_done = __init_static_variables();
bool IScannableIndex::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IScannableIndex", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IScannableIndex::IScannableIndex(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IScannableIndex::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IScannableIndex::~IScannableIndex() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IScannableIndex::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IScannableIndex::__cleanUp(ThreadContext* ctx){
}
}}}

