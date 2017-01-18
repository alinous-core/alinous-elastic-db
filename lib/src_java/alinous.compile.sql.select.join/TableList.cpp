#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool TableList::__init_done = __init_static_variables();
bool TableList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableList::~TableList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableList", L"~TableList");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	IJoin::__releaseRegerences(true, ctx);
}
bool TableList::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->list->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool TableList::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->list->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
ArrayList<IJoin>* TableList::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void TableList::addJoinTarget(IJoin* target, ThreadContext* ctx) throw() 
{
	this->list->add(target, ctx);
}
bool TableList::analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->list->get(i, ctx)->analyseSQLTables(context, leftValue, debug, ctx);
	}
	return true;
}
void TableList::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->list->get(i, ctx)->analyzeSQL(context, debug, ctx);
	}
}
bool TableList::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		bool bl = this->list->get(i, ctx)->hasTable(table, ctx);
		if(bl)
		{
			return true;
		}
	}
	return false;
}
void TableList::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
}
ScanTableMetadata* TableList::getScanTableMetadata(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool TableList::isOptimizerCacheable(ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IJoin* jin = this->list->get(i, ctx);
		if(!jin->isOptimizerCacheable(ctx))
		{
			return false;
		}
	}
	return true;
}
ITableTargetScanner* TableList::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) throw() 
{
	return nullptr;
}
SQLJoinCondition* TableList::getCondition(ThreadContext* ctx)
{
	return nullptr;
}
int TableList::getLine(ThreadContext* ctx) throw() 
{
	return IJoin::getLine(ctx);
}
int TableList::getStartPosition(ThreadContext* ctx) throw() 
{
	return IJoin::getStartPosition(ctx);
}
int TableList::getEndLine(ThreadContext* ctx) throw() 
{
	return IJoin::getEndLine(ctx);
}
int TableList::getEndPosition(ThreadContext* ctx) throw() 
{
	return IJoin::getEndPosition(ctx);
}
AbstractSrcElement* TableList::getParent(ThreadContext* ctx) throw() 
{
	return IJoin::getParent(ctx);
}
void TableList::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IJoin::setParent(parent, ctx);
}
IStatement::StatementType TableList::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void TableList::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void TableList::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IJoin*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1080(), ctx));
		}
		this->list->add(static_cast<IJoin*>(el), ctx);
	}
}
void TableList::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__TableList, ctx);
	int maxLoop = this->list->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IJoin* exp = this->list->get(i, ctx);
		exp->writeData(buff, ctx);
	}
}
}}}}}

