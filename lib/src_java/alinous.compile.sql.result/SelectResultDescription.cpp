#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.parts/SQLExpressionListAll.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/AllColumnResult.h"
#include "alinous.compile.sql.result/ColumnResult.h"
#include "alinous.compile.sql.result/FunctionResult.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"

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
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1146(), ctx));
			}
		case AbstructSelectResult::FUNCTION:
		default:
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1147(), ctx));
			break;
		}
	}
	return cols;
}
void SelectResultDescription::__cleanUp(ThreadContext* ctx){
}
}}}}

