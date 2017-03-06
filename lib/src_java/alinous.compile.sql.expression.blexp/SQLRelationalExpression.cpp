#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLEqualityExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.expression.blexp/SQLInExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLIsNullExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLLikeExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLNotExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLOrExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLRelationalExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql.expression.blexp/SQLBooleanLiteral.h"

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





constexpr const int SQLRelationalExpression::LT;
constexpr const int SQLRelationalExpression::GT;
constexpr const int SQLRelationalExpression::LT_EQ;
constexpr const int SQLRelationalExpression::GT_EQ;
bool SQLRelationalExpression::__init_done = __init_static_variables();
bool SQLRelationalExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLRelationalExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLRelationalExpression::SQLRelationalExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanExpression(ctx), left(nullptr), ope(0), right(nullptr)
{
}
void SQLRelationalExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLRelationalExpression::~SQLRelationalExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLRelationalExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLRelationalExpression", L"~SQLRelationalExpression");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLRelationalExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(!this->left->visit(visitor, this, ctx))
	{
		return false;
	}
	if(!this->right->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLRelationalExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(!this->left->isConstant(ctx))
	{
		return false;
	}
	if(!this->right->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLRelationalExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	this->left->analyse(context, leftValue, ctx);
	this->right->analyse(context, leftValue, ctx);
	return true;
}
ISQLExpression* SQLRelationalExpression::getLeft(ThreadContext* ctx) throw() 
{
	return left;
}
void SQLRelationalExpression::setLeft(ISQLExpression* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), left, ISQLExpression);
}
ISQLExpression* SQLRelationalExpression::getRight(ThreadContext* ctx) throw() 
{
	return right;
}
void SQLRelationalExpression::setRight(ISQLExpression* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), right, ISQLExpression);
}
ArrayList<ScanTableColumnIdentifier>* SQLRelationalExpression::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* cols = this->left->getColumns(ctx);
	return cols;
}
int SQLRelationalExpression::getOpe(ThreadContext* ctx) throw() 
{
	return ope;
}
void SQLRelationalExpression::setOpe(String* opeStr, ThreadContext* ctx) throw() 
{
	if(opeStr->equals(ConstStr::getCNST_STR_1010(), ctx))
	{
		this->ope = LT;
	}
		else 
	{
		if(opeStr->equals(ConstStr::getCNST_STR_82(), ctx))
		{
			this->ope = GT;
		}
				else 
		{
			if(opeStr->equals(ConstStr::getCNST_STR_1011(), ctx))
			{
				this->ope = LT_EQ;
			}
						else 
			{
				if(opeStr->equals(ConstStr::getCNST_STR_1012(), ctx))
				{
					this->ope = GT_EQ;
				}
			}
		}
	}
}
IAlinousVariable* SQLRelationalExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->left->resolveExpression(machine, debug, ctx);
	if(this->right == nullptr)
	{
		return val;
	}
	IAlinousVariable* rightVal = this->right->resolveExpression(machine, debug, ctx);
	if((this->ope == LT && val->compareTo(rightVal, ctx) < 0) || (this->ope == LT_EQ && val->compareTo(rightVal, ctx) <= 0) || (this->ope == GT && val->compareTo(rightVal, ctx) > 0) || (this->ope == GT_EQ && val->compareTo(rightVal, ctx) >= 0))
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
VariantValue* SQLRelationalExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* val = this->left->resolveSQLExpression(record, machine, debug, ctx);
	if(this->right == nullptr)
	{
		return val;
	}
	VariantValue* rightVal = this->right->resolveSQLExpression(record, machine, debug, ctx);
	if((this->ope == LT && val->compareTo(rightVal, ctx) < 0) || (this->ope == LT_EQ && val->compareTo(rightVal, ctx) <= 0) || (this->ope == GT && val->compareTo(rightVal, ctx) > 0) || (this->ope == GT_EQ && val->compareTo(rightVal, ctx) >= 0))
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
ExpressionSourceId* SQLRelationalExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool SQLRelationalExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->left != nullptr)
	{
		this->left->analyseSQL(context, leftValue, debug, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLRelationalExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr && this->left->hasTable(table, ctx))
	{
		return true;
	}
	if(this->right != nullptr && this->right->hasTable(table, ctx))
	{
		return true;
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLRelationalExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->left != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->left, ctx);
	}
	if(this->right != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->right, ctx);
	}
	return list;
}
bool SQLRelationalExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLRelationalExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLRelationalExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLRelationalExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
IndexColumnMatchCondition* SQLRelationalExpression::getIndexScanPart(ThreadContext* ctx) throw() 
{
	if(isJoinCondition(ctx) || (!this->left->isColumnIdentifier(ctx) && !this->right->isColumnIdentifier(ctx)))
	{
		return nullptr;
	}
	ScanTableColumnIdentifier* colId = this->left->isColumnIdentifier(ctx) ? this->left->toColumnIdentifier(ctx) : this->right->toColumnIdentifier(ctx);
	IndexColumnMatchCondition* part = nullptr;
	switch(this->ope) {
	case LT:
		part = (new(ctx) IndexColumnMatchCondition(colId, IndexColumnMatchCondition::INDEX_BEFORE, nullptr, this->right, ctx));
		break ;
	case GT:
		part = (new(ctx) IndexColumnMatchCondition(colId, IndexColumnMatchCondition::INDEX_AFTER, this->right, nullptr, ctx));
		break ;
	case LT_EQ:
		part = (new(ctx) IndexColumnMatchCondition(colId, IndexColumnMatchCondition::INDEX_BEFORE, nullptr, this->right, ctx));
		part->setEndEq(true, ctx);
		break ;
	case GT_EQ:
	default:
		part = (new(ctx) IndexColumnMatchCondition(colId, IndexColumnMatchCondition::INDEX_AFTER, this->right, nullptr, ctx));
		part->setStartEq(true, ctx);
		break ;
	}
	return part;
}
ScanTableColumnIdentifier* SQLRelationalExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLRelationalExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLRelationalExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
int SQLRelationalExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLRelationalExpression;
}
void SQLRelationalExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->left), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	this->ope = buff->getInt(ctx);
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->right), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
void SQLRelationalExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SQLRelationalExpression, ctx);
	__writeData(buff, ctx);
	bool isnull = (this->left == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->left->writeData(buff, ctx);
	}
	buff->putInt(this->ope, ctx);
	isnull = (this->right == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->right->writeData(buff, ctx);
	}
}
int SQLRelationalExpression::fileSize(ThreadContext* ctx)
{
	int total = __fileSize(ctx);
	bool isnull = (this->left == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->left->fileSize(ctx);
	}
	total += 4;
	isnull = (this->right == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->right->fileSize(ctx);
	}
	return total;
}
void SQLRelationalExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLRelationalExpression, ctx);
	__toFileEntry(builder, ctx);
	bool isnull = (this->left == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->left->toFileEntry(builder, ctx);
	}
	builder->putInt(this->ope, ctx);
	isnull = (this->right == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->right->toFileEntry(builder, ctx);
	}
}
void SQLRelationalExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	__fromFileEntry(fetcher, ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->left), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	this->ope = fetcher->fetchInt(ctx);
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->right), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
void SQLRelationalExpression::__cleanUp(ThreadContext* ctx){
}
}}}}}

