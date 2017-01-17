#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {





bool CrossJoinScanner::__init_done = __init_static_variables();
bool CrossJoinScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CrossJoinScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CrossJoinScanner::CrossJoinScanner(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ScriptMachine* machine, ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), left(nullptr), right(nullptr), currentLeft(nullptr), nextResult(nullptr), trx(nullptr)
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->left), left, ITableTargetScanner);
	__GC_MV(this, &(this->right), right, ITableTargetScanner);
}
void CrossJoinScanner::__construct_impl(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->left), left, ITableTargetScanner);
	__GC_MV(this, &(this->right), right, ITableTargetScanner);
}
 CrossJoinScanner::~CrossJoinScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CrossJoinScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CrossJoinScanner", L"~CrossJoinScanner");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	__e_obj1.add(this->currentLeft, this);
	currentLeft = nullptr;
	__e_obj1.add(this->nextResult, this);
	nextResult = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	if(!prepare){
		return;
	}
}
void CrossJoinScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	this->left->startScan(indexKeyValue, ctx);
}
void CrossJoinScanner::endScan(ThreadContext* ctx)
{
	this->left->endScan(ctx);
}
bool CrossJoinScanner::hasNext(bool debug, ThreadContext* ctx)
{
	while(this->nextResult == nullptr)
	{
		if(this->currentLeft == nullptr)
		{
			if(!this->left->hasNext(debug, ctx))
			{
				return false;
			}
			__GC_MV(this, &(this->currentLeft), this->left->next(debug, ctx), ScanResultRecord);
			this->right->startScan(nullptr, ctx);
		}
		if(!this->right->hasNext(debug, ctx))
		{
			this->right->endScan(ctx);
			if(!this->left->hasNext(debug, ctx))
			{
				__GC_MV(this, &(this->currentLeft), nullptr, ScanResultRecord);
				return false;
			}
			__GC_MV(this, &(this->currentLeft), this->left->next(debug, ctx), ScanResultRecord);
			this->right->startScan(nullptr, ctx);
			if(!this->right->hasNext(debug, ctx))
			{
				__GC_MV(this, &(this->currentLeft), nullptr, ScanResultRecord);
				continue;
			}
		}
		ScanResultRecord* rightRecord = this->right->next(debug, ctx);
		{
			try
			{
				__GC_MV(this, &(this->nextResult), this->currentLeft->join(rightRecord, trx, ctx), ScanResultRecord);
			}
			catch(VariableException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1089(), e, ctx));
			}
		}
		return true;
	}
	return true;
}
ScanResultRecord* CrossJoinScanner::next(bool debug, ThreadContext* ctx)
{
	ScanResultRecord* retValue = this->nextResult;
	__GC_MV(this, &(this->nextResult), nullptr, ScanResultRecord);
	return retValue;
}
void CrossJoinScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	this->left->dispose(logger, ctx);
	this->right->dispose(logger, ctx);
}
}}}}}}

