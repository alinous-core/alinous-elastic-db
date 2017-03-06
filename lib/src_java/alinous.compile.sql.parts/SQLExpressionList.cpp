#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionListAll.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"

namespace alinous {namespace compile {namespace sql {namespace parts {





bool SQLExpressionList::__init_done = __init_static_variables();
bool SQLExpressionList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLExpressionList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLExpressionList::SQLExpressionList(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpressionPart(ctx), list(GCUtils<ArrayList<ISQLExpression> >::ins(this, (new(ctx) ArrayList<ISQLExpression>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void SQLExpressionList::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLExpressionList::~SQLExpressionList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLExpressionList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLExpressionList", L"~SQLExpressionList");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpressionPart::__releaseRegerences(true, ctx);
}
bool SQLExpressionList::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* exp = this->list->get(i, ctx);
		if(!exp->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool SQLExpressionList::isConstant(ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* exp = this->list->get(i, ctx);
		if(!exp->isConstant(ctx))
		{
			return false;
		}
	}
	return true;
}
bool SQLExpressionList::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* exp = this->list->get(i, ctx);
		exp->analyse(context, leftValue, ctx);
	}
	return true;
}
void SQLExpressionList::addElement(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	this->list->add(exp, ctx);
}
ArrayList<ISQLExpression>* SQLExpressionList::getList(ThreadContext* ctx) throw() 
{
	return this->list;
}
IAlinousVariable* SQLExpressionList::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
ExpressionSourceId* SQLExpressionList::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
bool SQLExpressionList::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* exp = this->list->get(i, ctx);
		exp->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLExpressionList::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* exp = this->list->get(i, ctx);
		bool ans = exp->hasTable(table, ctx);
		if(ans)
		{
			return true;
		}
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLExpressionList::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* exp = this->list->get(i, ctx);
		list = SQLAnalyseContext::joinList(list, exp, ctx);
	}
	return list;
}
bool SQLExpressionList::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLExpressionList::isJoinCondition(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = getColumns(ctx);
	return !list->isEmpty(ctx);
}
void SQLExpressionList::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLExpressionList::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* SQLExpressionList::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLExpressionList::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
bool SQLExpressionList::hasArrayResult(ThreadContext* ctx) throw() 
{
	return true;
}
ArrayList<VariantValue>* SQLExpressionList::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ArrayList<VariantValue>* retList = (new(ctx) ArrayList<VariantValue>(ctx));
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* exp = this->list->get(i, ctx);
		if(exp->hasArrayResult(ctx))
		{
			ArrayList<VariantValue>* array = exp->resolveSQLExpressionAsArray(record, machine, debug, ctx);
			retList->addAll(array, ctx);
		}
				else 
		{
			VariantValue* val = exp->resolveSQLExpression(record, machine, debug, ctx);
			retList->add(val, ctx);
		}
	}
	return retList;
}
String* SQLExpressionList::getAsName(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void SQLExpressionList::setAsName(String* name, ThreadContext* ctx) throw() 
{
}
int SQLExpressionList::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLExpressionList;
}
void SQLExpressionList::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		this->list->add(static_cast<ISQLExpression*>(el), ctx);
	}
}
void SQLExpressionList::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SQLExpressionList, ctx);
	int maxLoop = this->list->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		ISQLExpression* exp = this->list->get(i, ctx);
		exp->writeData(buff, ctx);
	}
}
int SQLExpressionList::fileSize(ThreadContext* ctx)
{
	int total = 4;
	int maxLoop = this->list->size(ctx);
	total += 1;
	for(int i = 0; i < maxLoop; ++i)
	{
		ISQLExpression* exp = this->list->get(i, ctx);
		total += exp->fileSize(ctx);
	}
	return total;
}
void SQLExpressionList::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLExpressionList, ctx);
	int maxLoop = this->list->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		ISQLExpression* exp = this->list->get(i, ctx);
		exp->toFileEntry(builder, ctx);
	}
}
void SQLExpressionList::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		this->list->add(static_cast<ISQLExpression*>(el), ctx);
	}
}
void SQLExpressionList::__cleanUp(ThreadContext* ctx){
}
}}}}

