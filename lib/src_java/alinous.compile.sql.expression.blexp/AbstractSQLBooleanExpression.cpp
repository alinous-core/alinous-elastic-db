#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





constexpr const int AbstractSQLBooleanExpression::SQL_OR;
constexpr const int AbstractSQLBooleanExpression::SQL_AND;
bool AbstractSQLBooleanExpression::__init_done = __init_static_variables();
bool AbstractSQLBooleanExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSQLBooleanExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSQLBooleanExpression::~AbstractSQLBooleanExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSQLBooleanExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractSQLBooleanExpression", L"~AbstractSQLBooleanExpression");
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	if(!prepare){
		return;
	}
	ISQLBoolExpression::__releaseRegerences(true, ctx);
}
int AbstractSQLBooleanExpression::getLine(ThreadContext* ctx) throw() 
{
	return ISQLBoolExpression::getLine(ctx);
}
int AbstractSQLBooleanExpression::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLBoolExpression::getStartPosition(ctx);
}
int AbstractSQLBooleanExpression::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLBoolExpression::getEndLine(ctx);
}
int AbstractSQLBooleanExpression::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLBoolExpression::getEndPosition(ctx);
}
AbstractSrcElement* AbstractSQLBooleanExpression::getParent(ThreadContext* ctx) throw() 
{
	return ISQLBoolExpression::getParent(ctx);
}
void AbstractSQLBooleanExpression::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLBoolExpression::setParent(parent, ctx);
}
bool AbstractSQLBooleanExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* AbstractSQLBooleanExpression::getAsName(ThreadContext* ctx) throw() 
{
	return this->asName;
}
void AbstractSQLBooleanExpression::setAsName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), name, String);
}
void AbstractSQLBooleanExpression::__readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), buff->getString(ctx), String);
	}
}
void AbstractSQLBooleanExpression::__writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	bool isnull = (this->asName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->asName, ctx);
	}
}
int AbstractSQLBooleanExpression::__fileSize(ThreadContext* ctx)
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
void AbstractSQLBooleanExpression::__toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	bool isnull = (this->asName == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->asName, ctx);
	}
}
void AbstractSQLBooleanExpression::__fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), fetcher->fetchString(ctx), String);
	}
}
int AbstractSQLBooleanExpression::operatorFromString(String* opStr, ThreadContext* ctx) throw() 
{
	if(opStr->equalsIgnoreCase(ConstStr::getCNST_STR_1071(), ctx))
	{
		return AbstractSQLBooleanExpression::SQL_OR;
	}
		else 
	{
		if(opStr->equalsIgnoreCase(ConstStr::getCNST_STR_1072(), ctx))
		{
			return AbstractSQLBooleanExpression::SQL_AND;
		}
	}
	return -1;
}
}}}}}

