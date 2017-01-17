#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace parts {





bool SQLExpressionListAll::__init_done = __init_static_variables();
bool SQLExpressionListAll::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLExpressionListAll", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLExpressionListAll::~SQLExpressionListAll() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLExpressionListAll::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLExpressionListAll", L"~SQLExpressionListAll");
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpressionPart::__releaseRegerences(true, ctx);
}
bool SQLExpressionListAll::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLExpressionListAll::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	return false;
}
bool SQLExpressionListAll::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLExpressionListAll::getColumns(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLExpressionListAll::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLExpressionListAll::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLExpressionListAll::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* SQLExpressionListAll::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLExpressionListAll::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
IAlinousVariable* SQLExpressionListAll::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
ExpressionSourceId* SQLExpressionListAll::getSourceId(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLExpressionListAll::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLExpressionListAll::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
bool SQLExpressionListAll::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool SQLExpressionListAll::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLExpressionListAll::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
String* SQLExpressionListAll::getAsName(ThreadContext* ctx) throw() 
{
	return this->asName;
}
void SQLExpressionListAll::setAsName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), name, String);
}
int SQLExpressionListAll::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLExpressionListAll;
}
void SQLExpressionListAll::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), buff->getString(ctx), String);
	}
}
void SQLExpressionListAll::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLExpressionListAll, ctx);
	bool isnull = (this->asName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->asName, ctx);
	}
}
int SQLExpressionListAll::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->asName == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->asName->length(ctx) * 2 + 4;
	}
	return total;
}
void SQLExpressionListAll::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLExpressionListAll, ctx);
	bool isnull = (this->asName == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->asName, ctx);
	}
}
void SQLExpressionListAll::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), fetcher->fetchString(ctx), String);
	}
}
}}}}

