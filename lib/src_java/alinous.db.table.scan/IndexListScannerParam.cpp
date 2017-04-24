#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.table.scan/IndexListScannerParam.h"

namespace alinous {namespace db {namespace table {namespace scan {





bool IndexListScannerParam::__init_done = __init_static_variables();
bool IndexListScannerParam::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexListScannerParam", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexListScannerParam::IndexListScannerParam(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), list(GCUtils<ArrayList<ScanResultIndexKey> >::ins(this, (new(ctx) ArrayList<ScanResultIndexKey>(ctx)), ctx, __FILEW__, __LINE__, L"")), current(0)
{
}
void IndexListScannerParam::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IndexListScannerParam::~IndexListScannerParam() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexListScannerParam::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IndexListScannerParam", L"~IndexListScannerParam");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void IndexListScannerParam::addIndexKey(ScanResultIndexKey* key, ThreadContext* ctx) throw() 
{
	this->list->add(key, ctx);
}
ArrayList<ScanResultIndexKey>* IndexListScannerParam::getList(ThreadContext* ctx) throw() 
{
	return list;
}
bool IndexListScannerParam::hasNext(ThreadContext* ctx) throw() 
{
	return this->current < list->size(ctx);
}
ScanResultIndexKey* IndexListScannerParam::nextKey(ThreadContext* ctx) throw() 
{
	return list->get(current++, ctx);
}
void IndexListScannerParam::reset(ThreadContext* ctx) throw() 
{
	this->current = 0;
}
void IndexListScannerParam::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanResultIndexKey* key = ScanResultIndexKey::fromNetwork(buff, ctx);
		this->list->add(key, ctx);
	}
}
void IndexListScannerParam::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = this->list->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanResultIndexKey* key = this->list->get(i, ctx);
		key->writeData(buff, ctx);
	}
}
IndexListScannerParam* IndexListScannerParam::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	IndexListScannerParam* param = (new(ctx) IndexListScannerParam(ctx));
	param->readData(buff, ctx);
	return param;
}
void IndexListScannerParam::__cleanUp(ThreadContext* ctx){
}
}}}}

