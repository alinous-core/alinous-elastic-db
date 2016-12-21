#include "includes.h"


namespace alinous {namespace db {namespace trx {namespace scan {





bool ScanResultScanner::__init_done = __init_static_variables();
bool ScanResultScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanResultScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanResultScanner::ScanResultScanner(ScanResult* result, ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), result(nullptr), btree(nullptr), scanner(nullptr), values(nullptr), current(0)
{
	__GC_MV(this, &(this->result), result, ScanResult);
	__GC_MV(this, &(this->btree), this->result->getStore(ctx), IBTree);
}
void ScanResultScanner::__construct_impl(ScanResult* result, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->result), result, ScanResult);
	__GC_MV(this, &(this->btree), this->result->getStore(ctx), IBTree);
}
 ScanResultScanner::~ScanResultScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanResultScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanResultScanner", L"~ScanResultScanner");
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
void ScanResultScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	GCUtils<ArrayList<IBTreeValue> >::mv(this, &(this->values), nullptr, ctx);
	this->current = 0;
	__GC_MV(this, &(this->scanner), (new(ctx) BTreeScanner(this->btree, ctx)), BTreeScanner);
	{
		try
		{
			this->scanner->startScan(false, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1660(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1660(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1660(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1660(), e, ctx));
		}
	}
}
bool ScanResultScanner::hasNext(bool debug, ThreadContext* ctx)
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
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1661(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1661(), e, ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1661(), e, ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1661(), e, ctx));
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
ScanResultRecord* ScanResultScanner::next(bool debug, ThreadContext* ctx)
{
	ScanResultRecord* soid = static_cast<ScanResultRecord*>(this->values->get(this->current++, ctx));
	return soid;
}
void ScanResultScanner::endScan(ThreadContext* ctx)
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
void ScanResultScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	{
		try
		{
			this->result->dispose(logger, ctx);
		}
		catch(AlinousException* e)
		{
			logger->logError(e, ctx);
		}
	}
}
}}}}

