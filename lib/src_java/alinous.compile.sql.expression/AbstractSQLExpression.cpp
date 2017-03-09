#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanExpression.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"

namespace alinous {namespace compile {namespace sql {namespace expression {





constexpr const int AbstractSQLExpression::PLUS;
constexpr const int AbstractSQLExpression::MINUS;
constexpr const int AbstractSQLExpression::MUL;
constexpr const int AbstractSQLExpression::DIV;
constexpr const int AbstractSQLExpression::MOD;
bool AbstractSQLExpression::__init_done = __init_static_variables();
bool AbstractSQLExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSQLExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSQLExpression::AbstractSQLExpression(ThreadContext* ctx) throw()  : IObject(ctx), ISQLExpression(ctx), asName(nullptr)
{
}
void AbstractSQLExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractSQLExpression::~AbstractSQLExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSQLExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractSQLExpression", L"~AbstractSQLExpression");
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	if(!prepare){
		return;
	}
	ISQLExpression::__releaseRegerences(true, ctx);
}
int AbstractSQLExpression::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getLine(ctx);
}
int AbstractSQLExpression::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getStartPosition(ctx);
}
int AbstractSQLExpression::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndLine(ctx);
}
int AbstractSQLExpression::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndPosition(ctx);
}
AbstractSrcElement* AbstractSQLExpression::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getParent(ctx);
}
void AbstractSQLExpression::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpression::setParent(parent, ctx);
}
bool AbstractSQLExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* AbstractSQLExpression::getAsName(ThreadContext* ctx) throw() 
{
	return this->asName;
}
void AbstractSQLExpression::setAsName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), name, String);
}
int AbstractSQLExpression::operatorFromString(String* opStr, ThreadContext* ctx) throw() 
{
	if(opStr->equals(ConstStr::getCNST_STR_1041(), ctx))
	{
		return AbstractBooleanExpression::PLUS;
	}
		else 
	{
		if(opStr->equals(ConstStr::getCNST_STR_98(), ctx))
		{
			return AbstractBooleanExpression::MINUS;
		}
				else 
		{
			if(opStr->equals(ConstStr::getCNST_STR_1042(), ctx))
			{
				return AbstractBooleanExpression::MUL;
			}
						else 
			{
				if(opStr->equals(ConstStr::getCNST_STR_949(), ctx))
				{
					return AbstractBooleanExpression::DIV;
				}
								else 
				{
					if(opStr->equals(ConstStr::getCNST_STR_1043(), ctx))
					{
						return AbstractBooleanExpression::MOD;
					}
				}
			}
		}
	}
	return -1;
}
void AbstractSQLExpression::__cleanUp(ThreadContext* ctx){
}
}}}}

