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
#include "alinous.db.table.scan/IndexRangeScannerParam.h"

namespace alinous {namespace db {namespace table {namespace scan {





bool IndexRangeScannerParam::__init_done = __init_static_variables();
bool IndexRangeScannerParam::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexRangeScannerParam", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexRangeScannerParam::IndexRangeScannerParam(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), start(nullptr), startEq(0), end(nullptr), endEq(0)
{
}
void IndexRangeScannerParam::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IndexRangeScannerParam::~IndexRangeScannerParam() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexRangeScannerParam::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IndexRangeScannerParam", L"~IndexRangeScannerParam");
	__e_obj1.add(this->start, this);
	start = nullptr;
	__e_obj1.add(this->end, this);
	end = nullptr;
	if(!prepare){
		return;
	}
}
ScanResultIndexKey* IndexRangeScannerParam::getStart(ThreadContext* ctx) throw() 
{
	return start;
}
void IndexRangeScannerParam::setStart(ScanResultIndexKey* start, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->start), start, ScanResultIndexKey);
}
bool IndexRangeScannerParam::isStartEq(ThreadContext* ctx) throw() 
{
	return startEq;
}
void IndexRangeScannerParam::setStartEq(bool startEq, ThreadContext* ctx) throw() 
{
	this->startEq = startEq;
}
void IndexRangeScannerParam::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->start), ScanResultIndexKey::fromNetwork(buff, ctx), ScanResultIndexKey);
	}
	this->startEq = buff->getBoolean(ctx);
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->end), ScanResultIndexKey::fromNetwork(buff, ctx), ScanResultIndexKey);
	}
	this->endEq = buff->getBoolean(ctx);
}
void IndexRangeScannerParam::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = (this->start == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->start->writeData(buff, ctx);
	}
	buff->putBoolean(this->startEq, ctx);
	isnull = (this->end == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->end->writeData(buff, ctx);
	}
	buff->putBoolean(this->endEq, ctx);
}
IndexRangeScannerParam* IndexRangeScannerParam::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	IndexRangeScannerParam* param = (new(ctx) IndexRangeScannerParam(ctx));
	param->readData(buff, ctx);
	return param;
}
void IndexRangeScannerParam::__cleanUp(ThreadContext* ctx){
}
}}}}

