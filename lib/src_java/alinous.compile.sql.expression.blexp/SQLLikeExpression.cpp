#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





bool SQLLikeExpression::__init_done = __init_static_variables();
bool SQLLikeExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLLikeExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLLikeExpression::~SQLLikeExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLLikeExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLLikeExpression", L"~SQLLikeExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->esc, this);
	esc = nullptr;
	__e_obj1.add(this->escapeStr, this);
	escapeStr = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLLikeExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->first != nullptr && !this->first->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->esc != nullptr && !esc->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLLikeExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && !this->first->isConstant(ctx))
	{
		return false;
	}
	if(this->esc != nullptr && !esc->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLLikeExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr)
	{
		this->first->analyse(context, leftValue, ctx);
	}
	if(this->esc != nullptr)
	{
		this->esc->analyse(context, leftValue, ctx);
	}
	return true;
}
ISQLExpression* SQLLikeExpression::getFirst(ThreadContext* ctx) throw() 
{
	return first;
}
void SQLLikeExpression::setFirst(ISQLExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, ISQLExpression);
}
ISQLExpression* SQLLikeExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void SQLLikeExpression::setExp(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
ISQLExpression* SQLLikeExpression::getEsc(ThreadContext* ctx) throw() 
{
	return esc;
}
void SQLLikeExpression::setEsc(ISQLExpression* esc, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->esc), esc, ISQLExpression);
}
IAlinousVariable* SQLLikeExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
VariantValue* SQLLikeExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
ExpressionSourceId* SQLLikeExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool SQLLikeExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->first != nullptr && !this->first->analyseSQL(context, leftValue, debug, ctx))
	{
		return false;
	}
	if(this->esc != nullptr && !esc->analyseSQL(context, leftValue, debug, ctx))
	{
		return false;
	}
	if(this->esc != nullptr)
	{
		{
			try
			{
				IAlinousVariable* esval = esc->resolveExpression(context->getMachine(ctx), debug, ctx);
				if(esval != nullptr)
				{
					__GC_MV(this, &(this->escapeStr), esval->toString(ctx), String);
				}
			}
			catch(AlinousException* e)
			{
				e->printStackTrace(ctx);
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1075(), ctx));
			}
		}
	}
	return true;
}
bool SQLLikeExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && this->first->hasTable(table, ctx))
	{
		return true;
	}
	if(this->esc != nullptr && this->esc->hasTable(table, ctx))
	{
		return true;
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLLikeExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->first != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->first, ctx);
	}
	if(this->esc != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->esc, ctx);
	}
	return list;
}
bool SQLLikeExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLLikeExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLLikeExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLLikeExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLLikeExpression::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* cols = this->first->getColumns(ctx);
	return cols;
}
IndexColumnMatchCondition* SQLLikeExpression::getIndexScanPart(ThreadContext* ctx) throw() 
{
	if(isJoinCondition(ctx))
	{
		return nullptr;
	}
	return nullptr;
}
String* SQLLikeExpression::getEscapeStr(ThreadContext* ctx) throw() 
{
	return escapeStr;
}
ScanTableColumnIdentifier* SQLLikeExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLLikeExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLLikeExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
int SQLLikeExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLLikeExpression;
}
void SQLLikeExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->esc), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->escapeStr), buff->getString(ctx), String);
	}
}
void SQLLikeExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLLikeExpression, ctx);
	__writeData(buff, ctx);
	bool isnull = (this->first == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->writeData(buff, ctx);
	}
	isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
	isnull = (this->esc == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->esc->writeData(buff, ctx);
	}
	isnull = (this->escapeStr == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->escapeStr, ctx);
	}
}
int SQLLikeExpression::fileSize(ThreadContext* ctx)
{
	int total = __fileSize(ctx);
	bool isnull = (this->first == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->first->fileSize(ctx);
	}
	isnull = (this->exp == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->exp->fileSize(ctx);
	}
	isnull = (this->esc == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->esc->fileSize(ctx);
	}
	isnull = (this->escapeStr == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->escapeStr->length(ctx) * 2 + 4;
	}
	return total;
}
void SQLLikeExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLLikeExpression, ctx);
	__toFileEntry(builder, ctx);
	bool isnull = (this->first == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->toFileEntry(builder, ctx);
	}
	isnull = (this->exp == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->toFileEntry(builder, ctx);
	}
	isnull = (this->esc == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->esc->toFileEntry(builder, ctx);
	}
	isnull = (this->escapeStr == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->escapeStr, ctx);
	}
}
void SQLLikeExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	__fromFileEntry(fetcher, ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->esc), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->escapeStr), fetcher->fetchString(ctx), String);
	}
}
}}}}}

