#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.db.table.scan/UpdateHistoryValuesIterator.h"
#include "alinous.db.table.scan/UpdateHistoryBTreeIndexScanner.h"

namespace alinous {namespace db {namespace table {namespace scan {





bool UpdateHistoryBTreeIndexScanner::__init_done = __init_static_variables();
bool UpdateHistoryBTreeIndexScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UpdateHistoryBTreeIndexScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UpdateHistoryBTreeIndexScanner::UpdateHistoryBTreeIndexScanner(ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), storage(nullptr), scanner(nullptr), commitId(0), iterator(nullptr), trx(nullptr), tableId(nullptr)
{
}
void UpdateHistoryBTreeIndexScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 UpdateHistoryBTreeIndexScanner::~UpdateHistoryBTreeIndexScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UpdateHistoryBTreeIndexScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UpdateHistoryBTreeIndexScanner", L"~UpdateHistoryBTreeIndexScanner");
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->scanner, this);
	scanner = nullptr;
	__e_obj1.add(this->iterator, this);
	iterator = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	if(!prepare){
		return;
	}
}
UpdateHistoryBTreeIndexScanner* UpdateHistoryBTreeIndexScanner::init(ScanTableIdentifier* tableId, DbTransaction* trx, IBTree* storage, long long commitId, ThreadContext* ctx)
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->storage), storage, IBTree);
	__GC_MV(this, &(this->scanner), (new(ctx) BTreeScanner(this->storage, ctx)), BTreeScanner);
	this->commitId = commitId;
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
	return this;
}
void UpdateHistoryBTreeIndexScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	{
		try
		{
			this->scanner->startScan(indexKeyValue, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
	}
}
void UpdateHistoryBTreeIndexScanner::endScan(ThreadContext* ctx)
{
	{
		try
		{
			this->scanner->endScan(ctx);
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
	}
}
bool UpdateHistoryBTreeIndexScanner::hasNext(bool debug, ThreadContext* ctx)
{
	if(this->iterator != nullptr && this->iterator->hasNext(ctx))
	{
		return true;
	}
	{
		try
		{
			if(this->scanner->hasNext(ctx))
			{
				IBTreeNode* node = this->scanner->next(ctx);
				__GC_MV(this, &(this->iterator), (new(ctx) UpdateHistoryValuesIterator(node->getValues(ctx), this->commitId, ctx)), UpdateHistoryValuesIterator);
				return this->iterator->hasNext(ctx);
			}
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
	}
	__GC_MV(this, &(this->iterator), nullptr, UpdateHistoryValuesIterator);
	return false;
}
ScanResultRecord* UpdateHistoryBTreeIndexScanner::next(bool debug, ThreadContext* ctx)
{
	DatabaseRecord* record = this->iterator->next(ctx);
	ScanResultRecord* retrecord = nullptr;
	{
		try
		{
			retrecord = (new(ctx) ScanResultRecord(this->tableId, IDatabaseRecord::TRX_CACHE, record->getOid(ctx), trx, record, IndexScannerLockRequirement::NO_LOCK, ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
	}
	return retrecord;
}
void UpdateHistoryBTreeIndexScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	__GC_MV(this, &(this->iterator), nullptr, UpdateHistoryValuesIterator);
}
void UpdateHistoryBTreeIndexScanner::includes(ISQLExpression* arg0, IndexScannerLockRequirement* arg1, ThreadContext* ctx) throw() 
{
}
void UpdateHistoryBTreeIndexScanner::__cleanUp(ThreadContext* ctx){
}
}}}}

