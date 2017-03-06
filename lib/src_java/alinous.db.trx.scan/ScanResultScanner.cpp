#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
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
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/IBTree.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.trx.scan/PadddingRecord.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.trx.scan/GroupedScanResultRecord.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.db.trx.scan/JoinedRecords.h"
#include "alinous.db.trx.scan/ScannedOids.h"
#include "alinous.db.trx.scan/ScanResultScanner.h"

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
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1753(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1753(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1753(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1753(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1753(), e, ctx));
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
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1754(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1754(), e, ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1754(), e, ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1754(), e, ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1754(), e, ctx));
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
void ScanResultScanner::__cleanUp(ThreadContext* ctx){
}
}}}}

