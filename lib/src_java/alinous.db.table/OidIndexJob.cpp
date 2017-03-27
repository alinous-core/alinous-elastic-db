#include "include/global.h"


#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/LongValue.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.table/OidIndexJob.h"

namespace alinous {namespace db {namespace table {





bool OidIndexJob::__init_done = __init_static_variables();
bool OidIndexJob::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"OidIndexJob", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 OidIndexJob::OidIndexJob(long long nextOid, BTree* oidIndex, long long position, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), nextOid(0), oidIndex(nullptr), position(0)
{
	this->nextOid = nextOid;
	__GC_MV(this, &(this->oidIndex), oidIndex, BTree);
	this->position = position;
}
void OidIndexJob::__construct_impl(long long nextOid, BTree* oidIndex, long long position, ThreadContext* ctx) throw() 
{
	this->nextOid = nextOid;
	__GC_MV(this, &(this->oidIndex), oidIndex, BTree);
	this->position = position;
}
 OidIndexJob::~OidIndexJob() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void OidIndexJob::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"OidIndexJob", L"~OidIndexJob");
	__e_obj1.add(this->oidIndex, this);
	oidIndex = nullptr;
	if(!prepare){
		return;
	}
}
void OidIndexJob::execute(ThreadContext* ctx)
{
	LongValue* positionValue = (new(ctx) LongValue(this->position, ctx));
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(ctx));
	indexKey->values->add((new(ctx) VariantValue(nextOid, ctx)), ctx);
	this->oidIndex->closeGate(ctx);
	this->oidIndex->putKeyValue(indexKey, positionValue, ctx);
	this->oidIndex->openGate(ctx);
}
void OidIndexJob::__cleanUp(ThreadContext* ctx){
}
}}}

