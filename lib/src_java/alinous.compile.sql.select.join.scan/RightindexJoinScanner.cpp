#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {





bool RightindexJoinScanner::__init_done = __init_static_variables();
bool RightindexJoinScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RightindexJoinScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RightindexJoinScanner::RightindexJoinScanner(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, bool inner, JoinMatchExpression* match, SQLJoinCondition* condition, ScriptMachine* machine, ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), left(nullptr), right(nullptr), inner(0), rightIndex(nullptr), rightMetadata(nullptr), leftColumnIndex(0), rightColumnIndex(0), currentLeft(nullptr), leftValue(nullptr), joinedCount(0), joinCondition(nullptr), machine(nullptr), nextRightResult(nullptr), nextResult(nullptr), locker(nullptr), trx(nullptr)
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->left), left, ITableTargetScanner);
	__GC_MV(this, &(this->right), right, ITableTargetScanner);
	this->inner = inner;
	__GC_MV(this, &(this->locker), trx->lockContext, TrxLockContext);
	this->leftColumnIndex = leftMetadata->getColumnOrder(match->getLeftColumn(ctx), ctx);
	this->rightColumnIndex = rightMetadata->getColumnOrder(match->getRightColumn(ctx), ctx);
	__GC_MV(this, &(this->rightMetadata), rightMetadata, ScanTableMetadata);
	__GC_MV(this, &(this->rightIndex), match->getRightIndex(ctx), ScanTableIndexMetadata);
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
	if(condition != nullptr)
	{
		__GC_MV(this, &(this->joinCondition), condition->getCondition(ctx), ISQLExpression);
	}
}
void RightindexJoinScanner::__construct_impl(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, bool inner, JoinMatchExpression* match, SQLJoinCondition* condition, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->left), left, ITableTargetScanner);
	__GC_MV(this, &(this->right), right, ITableTargetScanner);
	this->inner = inner;
	__GC_MV(this, &(this->locker), trx->lockContext, TrxLockContext);
	this->leftColumnIndex = leftMetadata->getColumnOrder(match->getLeftColumn(ctx), ctx);
	this->rightColumnIndex = rightMetadata->getColumnOrder(match->getRightColumn(ctx), ctx);
	__GC_MV(this, &(this->rightMetadata), rightMetadata, ScanTableMetadata);
	__GC_MV(this, &(this->rightIndex), match->getRightIndex(ctx), ScanTableIndexMetadata);
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
	if(condition != nullptr)
	{
		__GC_MV(this, &(this->joinCondition), condition->getCondition(ctx), ISQLExpression);
	}
}
 RightindexJoinScanner::~RightindexJoinScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RightindexJoinScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RightindexJoinScanner", L"~RightindexJoinScanner");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	__e_obj1.add(this->rightIndex, this);
	rightIndex = nullptr;
	__e_obj1.add(this->rightMetadata, this);
	rightMetadata = nullptr;
	__e_obj1.add(this->currentLeft, this);
	currentLeft = nullptr;
	__e_obj1.add(this->leftValue, this);
	leftValue = nullptr;
	__e_obj1.add(this->joinCondition, this);
	joinCondition = nullptr;
	__e_obj1.add(this->machine, this);
	machine = nullptr;
	__e_obj1.add(this->nextRightResult, this);
	nextRightResult = nullptr;
	__e_obj1.add(this->nextResult, this);
	nextResult = nullptr;
	__e_obj1.add(this->locker, this);
	locker = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	if(!prepare){
		return;
	}
}
void RightindexJoinScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	this->left->startScan(indexKeyValue, ctx);
}
void RightindexJoinScanner::endScan(ThreadContext* ctx)
{
	this->left->endScan(ctx);
}
bool RightindexJoinScanner::hasNext(bool debug, ThreadContext* ctx)
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
			__GC_MV(this, &(this->leftValue), this->currentLeft->get(this->leftColumnIndex, ctx), VariantValue);
			ScanResultIndexKey* indexKey = (new(ctx) ScanResultIndexKey(ctx));
			indexKey->addKeyValue(this->leftValue, ctx);
			int indexCols = this->rightIndex->getColumns(ctx)->size(ctx);
			for(int i = 1; i < indexCols; ++i)
			{
				indexKey->addKeyValue((new(ctx) VariantValue(ctx)), ctx);
			}
			this->right->startScan(indexKey, ctx);
			this->joinedCount = 0;
		}
		if(!rightHasNext(debug, ctx))
		{
			if(this->inner && this->joinedCount == 0)
			{
				this->currentLeft->releaseLocks(locker, ctx);
				__GC_MV(this, &(this->leftValue), nullptr, VariantValue);
				__GC_MV(this, &(this->currentLeft), nullptr, ScanResultRecord);
				this->joinedCount = 0;
				this->right->endScan(ctx);
				continue;
			}
						else 
			{
				if(this->inner)
				{
					__GC_MV(this, &(this->leftValue), nullptr, VariantValue);
					__GC_MV(this, &(this->currentLeft), nullptr, ScanResultRecord);
					this->joinedCount = 0;
					this->right->endScan(ctx);
					continue;
				}
								else 
				{
					if(!this->inner && this->joinedCount != 0)
					{
						__GC_MV(this, &(this->leftValue), nullptr, VariantValue);
						__GC_MV(this, &(this->currentLeft), nullptr, ScanResultRecord);
						this->joinedCount = 0;
						this->right->endScan(ctx);
						continue;
					}
				}
			}
			int numCols = rightMetadata->getColumns(ctx)->size(ctx);
			__GC_MV(this, &(this->nextResult), this->currentLeft, ScanResultRecord);
			this->nextResult->addNullRecord(numCols, ctx);
			__GC_MV(this, &(this->leftValue), nullptr, VariantValue);
			__GC_MV(this, &(this->currentLeft), nullptr, ScanResultRecord);
			this->joinedCount = 0;
			this->right->endScan(ctx);
			return true;
		}
		ScanResultRecord* rightRecord = this->nextRightResult;
		ScanResultRecord* record = 0;
		{
			try
			{
				record = this->currentLeft->join(rightRecord, trx, ctx);
			}
			catch(VariableException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1091(), e, ctx));
			}
		}
		{
			try
			{
				if(this->joinCondition == nullptr || this->joinCondition->resolveSQLExpression(record, machine, debug, ctx)->isTrue(ctx))
				{
					this->joinedCount ++ ;
					__GC_MV(this, &(this->nextResult), record, ScanResultRecord);
					return true;
				}
								else 
				{
					rightRecord->releaseLocks(this->locker, ctx);
				}
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1092(), e, ctx));
			}
		}
	}
	return true;
}
ScanResultRecord* RightindexJoinScanner::next(bool debug, ThreadContext* ctx)
{
	ScanResultRecord* retValue = this->nextResult;
	__GC_MV(this, &(this->nextResult), nullptr, ScanResultRecord);
	return retValue;
}
void RightindexJoinScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	this->left->dispose(logger, ctx);
	this->right->dispose(logger, ctx);
}
bool RightindexJoinScanner::rightHasNext(bool debug, ThreadContext* ctx)
{
	if(this->right->hasNext(debug, ctx))
	{
		__GC_MV(this, &(this->nextRightResult), this->right->next(debug, ctx), ScanResultRecord);
	}
		else 
	{
		return false;
	}
	VariantValue* key = this->leftValue;
	VariantValue* keyValue = this->nextRightResult->get(this->rightColumnIndex, ctx);
	return key->compareTo(keyValue, ctx) == 0;
}
}}}}}}

