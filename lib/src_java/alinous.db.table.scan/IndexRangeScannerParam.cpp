#include "includes.h"


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
}}}}

