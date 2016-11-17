#include "includes.h"


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
}}}}

