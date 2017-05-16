#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"

namespace alinous {namespace db {namespace table {




constexpr const int IDatabaseRecord::NORMAL_RECORD;
constexpr const int IDatabaseRecord::TRX_CACHE;
constexpr const int IDatabaseRecord::DOM_VARIABLE;
constexpr const int IDatabaseRecord::NULL_PADDING;
constexpr const int IDatabaseRecord::NETWORK_RECORD;
bool IDatabaseRecord::__init_done = __init_static_variables();
bool IDatabaseRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDatabaseRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDatabaseRecord::IDatabaseRecord(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx)
{
}
void IDatabaseRecord::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IDatabaseRecord::~IDatabaseRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDatabaseRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IBTreeValue::__releaseRegerences(true, ctx);
}
void IDatabaseRecord::__cleanUp(ThreadContext* ctx){
}
}}}

