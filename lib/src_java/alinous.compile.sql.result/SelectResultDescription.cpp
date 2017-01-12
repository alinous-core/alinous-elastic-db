#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace result {





bool SelectResultDescription::__init_done = __init_static_variables();
bool SelectResultDescription::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SelectResultDescription", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SelectResultDescription::SelectResultDescription(SQLExpressionList* list, ScanTableMetadata* metadata, ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<AbstructSelectResult> >::ins(this, (new(ctx) ArrayList<AbstructSelectResult>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	ArrayList<ISQLExpression>* explist = list->list;
	int maxLoop = explist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* sqlexp = explist->get(i, ctx);
		if((dynamic_cast<SQLExpressionListAll*>(sqlexp) != 0))
		{
			this->list->add((new(ctx) AllColumnResult(metadata, ctx)), ctx);
			break ;
		}
		if(sqlexp->isColumnIdentifier(ctx))
		{
			ScanTableColumnIdentifier* colId = sqlexp->getColumns(ctx)->get(0, ctx);
			int colOrder = metadata->getColumnOrder(colId, ctx);
			ColumnResult* col = (new(ctx) ColumnResult(colOrder, sqlexp, colId, ctx));
			this->list->add(col, ctx);
		}
				else 
		{
			if((dynamic_cast<SQLExpressionStream*>(sqlexp) != 0))
			{
				FunctionResult* funcResult = (new(ctx) FunctionResult(static_cast<SQLExpressionStream*>(sqlexp), ctx));
				this->list->add(funcResult, ctx);
			}
		}
	}
}
void SelectResultDescription::__construct_impl(SQLExpressionList* list, ScanTableMetadata* metadata, ThreadContext* ctx) throw() 
{
	ArrayList<ISQLExpression>* explist = list->list;
	int maxLoop = explist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* sqlexp = explist->get(i, ctx);
		if((dynamic_cast<SQLExpressionListAll*>(sqlexp) != 0))
		{
			this->list->add((new(ctx) AllColumnResult(metadata, ctx)), ctx);
			break ;
		}
		if(sqlexp->isColumnIdentifier(ctx))
		{
			ScanTableColumnIdentifier* colId = sqlexp->getColumns(ctx)->get(0, ctx);
			int colOrder = metadata->getColumnOrder(colId, ctx);
			ColumnResult* col = (new(ctx) ColumnResult(colOrder, sqlexp, colId, ctx));
			this->list->add(col, ctx);
		}
				else 
		{
			if((dynamic_cast<SQLExpressionStream*>(sqlexp) != 0))
			{
				FunctionResult* funcResult = (new(ctx) FunctionResult(static_cast<SQLExpressionStream*>(sqlexp), ctx));
				this->list->add(funcResult, ctx);
			}
		}
	}
}
 SelectResultDescription::~SelectResultDescription() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SelectResultDescription::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SelectResultDescription", L"~SelectResultDescription");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
DomVariable* SelectResultDescription::fetchDom(ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ArrayList<AbstructSelectResult>* list = this->list;
	DomVariable* domVariable = (new(ctx) DomVariable(ctx));
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstructSelectResult* result = list->get(i, ctx);
		result->fetchFromRecord(domVariable, srecord, machine, debug, ctx);
	}
	return domVariable;
}
ArrayList<ScanTableColumnIdentifier>* SelectResultDescription::getGroupByIndexColumns(ThreadContext* ctx)
{
	ArrayList<AbstructSelectResult>* list = this->list;
	ArrayList<ScanTableColumnIdentifier>* cols = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstructSelectResult* result = list->get(i, ctx);
		int type = result->getType(ctx);
		switch(type) {
		case AbstructSelectResult::COLUMN:
			{
				ColumnResult* col = static_cast<ColumnResult*>(result);
				cols->add(col->colId, ctx);
				break ;
			}
		case AbstructSelectResult::ALL_COLUMNS:
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1076(), ctx));
			}
		case AbstructSelectResult::FUNCTION:
		default:
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1077(), ctx));
			break;
		}
	}
	return cols;
}
}}}}

