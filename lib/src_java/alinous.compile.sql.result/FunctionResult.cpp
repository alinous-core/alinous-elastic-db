#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
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
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/FunctionResult.h"

namespace alinous {namespace compile {namespace sql {namespace result {





bool FunctionResult::__init_done = __init_static_variables();
bool FunctionResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FunctionResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FunctionResult::FunctionResult(SQLExpressionStream* sqlexp, ThreadContext* ctx) throw()  : IObject(ctx), AbstructSelectResult(ctx), sqlexp(nullptr)
{
	__GC_MV(this, &(this->sqlexp), sqlexp, SQLExpressionStream);
	String* asName = sqlexp->getAsName(ctx);
	if(asName != nullptr)
	{
		__GC_MV(this, &(this->outputName), asName, String);
	}
		else 
	{
		__GC_MV(this, &(this->outputName), sqlexp->toString(ctx), String);
	}
}
void FunctionResult::__construct_impl(SQLExpressionStream* sqlexp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->sqlexp), sqlexp, SQLExpressionStream);
	String* asName = sqlexp->getAsName(ctx);
	if(asName != nullptr)
	{
		__GC_MV(this, &(this->outputName), asName, String);
	}
		else 
	{
		__GC_MV(this, &(this->outputName), sqlexp->toString(ctx), String);
	}
}
 FunctionResult::~FunctionResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FunctionResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FunctionResult", L"~FunctionResult");
	__e_obj1.add(this->sqlexp, this);
	sqlexp = nullptr;
	if(!prepare){
		return;
	}
	AbstructSelectResult::__releaseRegerences(true, ctx);
}
void FunctionResult::fetchFromRecord(DomVariable* domVariable, ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* value = this->sqlexp->resolveSQLExpression(srecord, machine, debug, ctx);
	domVariable->setProperty(this->outputName, (new(ctx) DomVariable(value, ctx)), ctx);
}
int FunctionResult::getType(ThreadContext* ctx) throw() 
{
	return AbstructSelectResult::FUNCTION;
}
void FunctionResult::__cleanUp(ThreadContext* ctx){
}
}}}}

