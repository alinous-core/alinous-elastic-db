#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.compile.sql.select.join.scan/RightindexJoinScanner.h"
#include "alinous.db.trx.scan/ScannedOids.h"
#include "alinous.compile.sql.select.join.scan/ReverseIndexScanner.h"
#include "alinous.compile.sql.select.join.scan/CrossJoinScanner.h"
#include "alinous.compile.sql.select.join.scan/JoinedCollectionScanner.h"

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {





bool ReverseIndexScanner::__init_done = __init_static_variables();
bool ReverseIndexScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ReverseIndexScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ReverseIndexScanner::ReverseIndexScanner(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, bool inner, JoinMatchExpression* match, SQLJoinCondition* condition, ScriptMachine* machine, ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), left(nullptr), right(nullptr), leftIndex(nullptr), rightColumnIndex(0), leftColumnIndex(0), nextLeftResult(nullptr), currentRight(nullptr), rightValue(nullptr), rightNumCols(0), nextResult(nullptr), joinedCount(0), inner(0), firstScanDone(0), scannedoids(nullptr), joinCondition(nullptr), machine(nullptr), lockContext(nullptr), trx(nullptr)
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->left), left, ITableTargetScanner);
	__GC_MV(this, &(this->right), right, ITableTargetScanner);
	this->inner = inner;
	this->leftColumnIndex = leftMetadata->getColumnOrder(match->getLeftColumn(ctx), ctx);
	this->rightColumnIndex = rightMetadata->getColumnOrder(match->getRightColumn(ctx), ctx);
	this->rightNumCols = rightMetadata->getColumns(ctx)->size(ctx);
	__GC_MV(this, &(this->leftIndex), match->getLeftIndex(ctx), ScanTableIndexMetadata);
	if(!this->inner)
	{
		__GC_MV(this, &(this->scannedoids), (new(ctx) ScannedOids(ctx)), ScannedOids);
	}
	if(condition != nullptr)
	{
		condition->getCondition(ctx);
	}
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
	this->firstScanDone = false;
	__GC_MV(this, &(this->lockContext), trx->lockContext, TrxLockContext);
}
void ReverseIndexScanner::__construct_impl(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, bool inner, JoinMatchExpression* match, SQLJoinCondition* condition, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->left), left, ITableTargetScanner);
	__GC_MV(this, &(this->right), right, ITableTargetScanner);
	this->inner = inner;
	this->leftColumnIndex = leftMetadata->getColumnOrder(match->getLeftColumn(ctx), ctx);
	this->rightColumnIndex = rightMetadata->getColumnOrder(match->getRightColumn(ctx), ctx);
	this->rightNumCols = rightMetadata->getColumns(ctx)->size(ctx);
	__GC_MV(this, &(this->leftIndex), match->getLeftIndex(ctx), ScanTableIndexMetadata);
	if(!this->inner)
	{
		__GC_MV(this, &(this->scannedoids), (new(ctx) ScannedOids(ctx)), ScannedOids);
	}
	if(condition != nullptr)
	{
		condition->getCondition(ctx);
	}
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
	this->firstScanDone = false;
	__GC_MV(this, &(this->lockContext), trx->lockContext, TrxLockContext);
}
 ReverseIndexScanner::~ReverseIndexScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ReverseIndexScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ReverseIndexScanner", L"~ReverseIndexScanner");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	__e_obj1.add(this->leftIndex, this);
	leftIndex = nullptr;
	__e_obj1.add(this->nextLeftResult, this);
	nextLeftResult = nullptr;
	__e_obj1.add(this->currentRight, this);
	currentRight = nullptr;
	__e_obj1.add(this->rightValue, this);
	rightValue = nullptr;
	__e_obj1.add(this->nextResult, this);
	nextResult = nullptr;
	__e_obj1.add(this->scannedoids, this);
	scannedoids = nullptr;
	__e_obj1.add(this->joinCondition, this);
	joinCondition = nullptr;
	__e_obj1.add(this->machine, this);
	machine = nullptr;
	__e_obj1.add(this->lockContext, this);
	lockContext = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	if(!prepare){
		return;
	}
}
bool ReverseIndexScanner::hasNext(bool debug, ThreadContext* ctx)
{
	if(!this->firstScanDone)
	{
		return firstHasNext(debug, ctx);
	}
	return hasNextAfter(debug, ctx);
}
ScanResultRecord* ReverseIndexScanner::next(bool debug, ThreadContext* ctx)
{
	ScanResultRecord* retValue = this->nextResult;
	__GC_MV(this, &(this->nextResult), nullptr, ScanResultRecord);
	return retValue;
}
void ReverseIndexScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	this->right->startScan(indexKeyValue, ctx);
}
void ReverseIndexScanner::endScan(ThreadContext* ctx)
{
	this->left->endScan(ctx);
}
void ReverseIndexScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	this->left->dispose(logger, ctx);
	this->right->dispose(logger, ctx);
	if(this->scannedoids != nullptr)
	{
		this->scannedoids->dispose(ctx);
	}
}
bool ReverseIndexScanner::firstHasNext(bool debug, ThreadContext* ctx)
{
	while(this->nextResult == nullptr)
	{
		if(this->currentRight == nullptr)
		{
			if(!this->right->hasNext(debug, ctx))
			{
				this->firstScanDone = true;
				if(this->inner)
				{
					return false;
				}
				this->right->endScan(ctx);
				this->left->startScan(nullptr, ctx);
				return hasNextAfter(debug, ctx);
			}
			__GC_MV(this, &(this->currentRight), this->right->next(debug, ctx), ScanResultRecord);
			__GC_MV(this, &(this->rightValue), this->currentRight->get(this->rightColumnIndex, ctx), VariantValue);
			ScanResultIndexKey* indexKey = (new(ctx) ScanResultIndexKey(ctx));
			indexKey->addKeyValue(this->rightValue, ctx);
			int indexCols = this->leftIndex->getColumns(ctx)->size(ctx);
			for(int i = 1; i < indexCols; ++i)
			{
				indexKey->addKeyValue((new(ctx) VariantValue(ctx)), ctx);
			}
			this->left->startScan(indexKey, ctx);
			this->joinedCount = 0;
		}
		if(!leftHasNext(debug, ctx))
		{
			if(this->joinedCount == 0)
			{
				this->currentRight->releaseLocks(lockContext, ctx);
			}
			__GC_MV(this, &(this->rightValue), nullptr, VariantValue);
			__GC_MV(this, &(this->currentRight), nullptr, ScanResultRecord);
			this->joinedCount = 0;
			this->left->endScan(ctx);
			continue;
		}
		ScanResultRecord* leftRecord = this->nextLeftResult;
		ScanResultRecord* record = 0;
		{
			try
			{
				record = leftRecord->join(this->currentRight, this->trx, ctx);
			}
			catch(VariableException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1096(), e, ctx));
			}
		}
		{
			try
			{
				if(this->joinCondition == nullptr || this->joinCondition->resolveSQLExpression(record, machine, debug, ctx)->isTrue(ctx))
				{
					this->joinedCount ++ ;
					__GC_MV(this, &(this->nextResult), record, ScanResultRecord);
					if(!this->inner)
					{
						this->scannedoids->addOid(leftRecord, ctx);
					}
					return true;
				}
								else 
				{
					leftRecord->releaseLocks(this->lockContext, ctx);
				}
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1097(), e, ctx));
			}
		}
	}
	return true;
}
bool ReverseIndexScanner::leftHasNext(bool debug, ThreadContext* ctx)
{
	if(this->left->hasNext(debug, ctx))
	{
		__GC_MV(this, &(this->nextLeftResult), this->left->next(debug, ctx), ScanResultRecord);
	}
		else 
	{
		return false;
	}
	VariantValue* key = this->rightValue;
	VariantValue* keyValue = this->nextLeftResult->get(this->leftColumnIndex, ctx);
	return key->compareTo(keyValue, ctx) == 0;
}
bool ReverseIndexScanner::hasNextAfter(bool debug, ThreadContext* ctx)
{
	while(this->nextResult == nullptr)
	{
		if(!this->left->hasNext(debug, ctx))
		{
			return false;
		}
		ScanResultRecord* rec = this->left->next(debug, ctx);
		if(!this->scannedoids->contains(rec, ctx))
		{
			__GC_MV(this, &(this->nextResult), rec, ScanResultRecord);
			this->nextResult->addNullRecord(this->rightNumCols, ctx);
			break ;
		}
	}
	return true;
}
void ReverseIndexScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}}

