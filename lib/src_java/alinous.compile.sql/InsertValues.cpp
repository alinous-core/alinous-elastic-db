#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool InsertValues::__init_done = __init_static_variables();
bool InsertValues::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InsertValues", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InsertValues::InsertValues(ThreadContext* ctx) throw()  : IObject(ctx), ISQLExpression(ctx), ThreadMonitor(ctx), vlist(nullptr), domDesc(nullptr)
{
}
void InsertValues::__construct_impl(ThreadContext* ctx) throw() 
{
}
 InsertValues::~InsertValues() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InsertValues::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InsertValues", L"~InsertValues");
	__e_obj1.add(this->vlist, this);
	vlist = nullptr;
	__e_obj1.add(this->domDesc, this);
	domDesc = nullptr;
	if(!prepare){
		return;
	}
	ISQLExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* InsertValues::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
ExpressionSourceId* InsertValues::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
IDomVariable* InsertValues::getValues(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(domDesc != nullptr)
	{
		return static_cast<IDomVariable*>(this->domDesc->resolveExpression(machine, debug, ctx));
	}
	DomArray* array = (new(ctx) DomArray(ctx));
	ArrayList<ISQLExpression>* values = this->vlist->getList(ctx);
	int maxLoop = values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* exp = values->get(i, ctx);
		IAlinousVariable* v = exp->resolveExpression(machine, debug, ctx);
		if(v->getVariableClass(ctx) == IAlinousVariable::CLASS_VARIANT)
		{
			DomVariable* dom = (new(ctx) DomVariable(ctx));
			dom->setValue(static_cast<VariantValue*>(v), ctx);
			array->put(dom, ctx);
		}
				else 
		{
			if(v->getVariableClass(ctx) == IAlinousVariable::CLASS_DOM)
			{
				array->put(static_cast<IDomVariable*>(v), ctx);
			}
		}
	}
	return array;
}
bool InsertValues::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->vlist != nullptr && !this->vlist->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->domDesc != nullptr && !this->domDesc->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool InsertValues::isConstant(ThreadContext* ctx) throw() 
{
	if(this->domDesc != nullptr)
	{
		return false;
	}
	if(this->vlist != nullptr && !this->vlist->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool InsertValues::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		if(this->vlist != nullptr)
		{
			this->vlist->analyse(context, leftValue, ctx);
		}
		if(this->domDesc != nullptr)
		{
			this->domDesc->analyse(context, leftValue, ctx);
		}
	}
	return true;
}
SQLExpressionList* InsertValues::getVlist(ThreadContext* ctx) throw() 
{
	return vlist;
}
void InsertValues::setVlist(SQLExpressionList* vlist, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vlist), vlist, SQLExpressionList);
}
SQLExpressionStream* InsertValues::getDomDesc(ThreadContext* ctx) throw() 
{
	return domDesc;
}
void InsertValues::setDomDesc(SQLExpressionStream* domDesc, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domDesc), domDesc, SQLExpressionStream);
}
bool InsertValues::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		if(this->vlist != nullptr)
		{
			this->vlist->analyseSQL(context, leftValue, debug, ctx);
		}
		if(this->domDesc != nullptr)
		{
			this->domDesc->analyseSQL(context, leftValue, debug, ctx);
		}
	}
	return true;
}
bool InsertValues::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* InsertValues::getColumns(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool InsertValues::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool InsertValues::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void InsertValues::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool InsertValues::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* InsertValues::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* InsertValues::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
	return nullptr;
}
int InsertValues::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getLine(ctx);
}
int InsertValues::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getStartPosition(ctx);
}
int InsertValues::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndLine(ctx);
}
int InsertValues::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndPosition(ctx);
}
AbstractSrcElement* InsertValues::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getParent(ctx);
}
void InsertValues::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpression::setParent(parent, ctx);
}
bool InsertValues::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* InsertValues::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
bool InsertValues::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* InsertValues::getAsName(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void InsertValues::setAsName(String* name, ThreadContext* ctx) throw() 
{
}
int InsertValues::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::insertValues;
}
void InsertValues::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1037(), ctx));
		}
		__GC_MV(this, &(this->vlist), static_cast<SQLExpressionList*>(el), SQLExpressionList);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionStream*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1038(), ctx));
		}
		__GC_MV(this, &(this->domDesc), static_cast<SQLExpressionStream*>(el), SQLExpressionStream);
	}
}
void InsertValues::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__InsertValues, ctx);
	bool isnull = (this->vlist == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vlist->writeData(buff, ctx);
	}
	isnull = (this->domDesc == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->domDesc->writeData(buff, ctx);
	}
}
int InsertValues::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->vlist == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->vlist->fileSize(ctx);
	}
	isnull = (this->domDesc == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->domDesc->fileSize(ctx);
	}
	return total;
}
void InsertValues::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__InsertValues, ctx);
	bool isnull = (this->vlist == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vlist->toFileEntry(builder, ctx);
	}
	isnull = (this->domDesc == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->domDesc->toFileEntry(builder, ctx);
	}
}
void InsertValues::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* exp = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(exp != nullptr || !((dynamic_cast<SQLExpressionList*>(exp) != 0)))
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1038(), ctx));
		}
		__GC_MV(this, &(this->vlist), static_cast<SQLExpressionList*>(exp), SQLExpressionList);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* exp = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(exp != nullptr || !((dynamic_cast<SQLExpressionStream*>(exp) != 0)))
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1038(), ctx));
		}
		__GC_MV(this, &(this->domDesc), static_cast<SQLExpressionStream*>(exp), SQLExpressionStream);
	}
}
}}}

