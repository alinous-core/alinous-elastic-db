#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/LongValue.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"

namespace alinous {namespace db {namespace trx {namespace scan {





bool ScannedResultIndexScanner::__init_done = __init_static_variables();
bool ScannedResultIndexScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScannedResultIndexScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScannedResultIndexScanner::ScannedResultIndexScanner(ScanResult* result, ArrayList<ScanTableColumnIdentifier>* indexColumns, ThreadContext* ctx) : IObject(ctx), ITableTargetScanner(ctx), result(nullptr), btree(nullptr), scanner(nullptr), values(nullptr), current(0)
{
	__GC_MV(this, &(this->result), result, ScanResult);
	ScanResultIndex* idx = this->result->getIndex(indexColumns, ctx);
	if(idx == nullptr)
	{
		throw (new(ctx) ScanException(ConstStr::getCNST_STR_1701()->clone(ctx)->append(indexColumns->toString(ctx), ctx), ctx));
	}
	__GC_MV(this, &(this->btree), idx->getBtree(ctx), IBTree);
}
void ScannedResultIndexScanner::__construct_impl(ScanResult* result, ArrayList<ScanTableColumnIdentifier>* indexColumns, ThreadContext* ctx)
{
	__GC_MV(this, &(this->result), result, ScanResult);
	ScanResultIndex* idx = this->result->getIndex(indexColumns, ctx);
	if(idx == nullptr)
	{
		throw (new(ctx) ScanException(ConstStr::getCNST_STR_1701()->clone(ctx)->append(indexColumns->toString(ctx), ctx), ctx));
	}
	__GC_MV(this, &(this->btree), idx->getBtree(ctx), IBTree);
}
 ScannedResultIndexScanner::~ScannedResultIndexScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScannedResultIndexScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScannedResultIndexScanner", L"~ScannedResultIndexScanner");
	__e_obj1.add(this->result, this);
	result = nullptr;
	__e_obj1.add(this->btree, this);
	btree = nullptr;
	__e_obj1.add(this->scanner, this);
	scanner = nullptr;
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
void ScannedResultIndexScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	GCUtils<ArrayList<IBTreeValue> >::mv(this, &(this->values), nullptr, ctx);
	this->current = 0;
	__GC_MV(this, &(this->scanner), (new(ctx) BTreeScanner(this->btree, ctx)), BTreeScanner);
	if(indexKeyValue == nullptr)
	{
		{
			try
			{
				this->scanner->startScan(false, ctx);
			}
			catch(VariableException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
		}
	}
		else 
	{
		{
			try
			{
				this->scanner->startScan(indexKeyValue, ctx);
			}
			catch(VariableException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
		}
	}
}
bool ScannedResultIndexScanner::hasNext(bool debug, ThreadContext* ctx)
{
	if(this->values == nullptr || this->values->size(ctx) == this->current)
	{
		{
			try
			{
				if(!this->scanner->hasNext(ctx))
				{
					return false;
				}
			}
			catch(VariableException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1703(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1703(), e, ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1703(), e, ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1703(), e, ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1703(), e, ctx));
			}
		}
		IBTreeNode* node = nullptr;
		{
			try
			{
				node = this->scanner->next(ctx);
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) ScanException(e, ctx));
			}
		}
		GCUtils<ArrayList<IBTreeValue> >::mv(this, &(this->values), node->getValues(ctx), ctx);
		this->current = 0;
	}
	return true;
}
ScanResultRecord* ScannedResultIndexScanner::next(bool debug, ThreadContext* ctx)
{
	LongValue* soid = static_cast<LongValue*>(this->values->get(this->current++, ctx));
	ScanResultRecord* record = nullptr;
	{
		try
		{
			record = this->result->getRecord(soid->value, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
	}
	return record;
}
void ScannedResultIndexScanner::endScan(ThreadContext* ctx)
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
void ScannedResultIndexScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	{
		try
		{
			this->result->dispose(logger, ctx);
		}
		catch(Throwable* e)
		{
			logger->logError(e, ctx);
		}
	}
}
void ScannedResultIndexScanner::__cleanUp(ThreadContext* ctx){
}
}}}}

