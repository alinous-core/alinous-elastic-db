#include "include/global.h"


#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
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
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/ColumnResult.h"

namespace alinous {namespace compile {namespace sql {namespace result {





bool ColumnResult::__init_done = __init_static_variables();
bool ColumnResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ColumnResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ColumnResult::ColumnResult(int colOrder, ISQLExpression* sqlexp, ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw()  : IObject(ctx), AbstructSelectResult(ctx), colId(nullptr), colOrder(0)
{
	this->colOrder = colOrder;
	__GC_MV(this, &(this->colId), colId, ScanTableColumnIdentifier);
	String* asName = sqlexp->getAsName(ctx);
	if(asName != nullptr)
	{
		__GC_MV(this, &(this->outputName), asName, String);
	}
		else 
	{
		__GC_MV(this, &(this->outputName), colId->getColumn(ctx), String);
	}
}
void ColumnResult::__construct_impl(int colOrder, ISQLExpression* sqlexp, ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() 
{
	this->colOrder = colOrder;
	__GC_MV(this, &(this->colId), colId, ScanTableColumnIdentifier);
	String* asName = sqlexp->getAsName(ctx);
	if(asName != nullptr)
	{
		__GC_MV(this, &(this->outputName), asName, String);
	}
		else 
	{
		__GC_MV(this, &(this->outputName), colId->getColumn(ctx), String);
	}
}
 ColumnResult::~ColumnResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ColumnResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ColumnResult", L"~ColumnResult");
	__e_obj1.add(this->colId, this);
	colId = nullptr;
	if(!prepare){
		return;
	}
	AbstructSelectResult::__releaseRegerences(true, ctx);
}
void ColumnResult::fetchFromRecord(DomVariable* domVariable, ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
	VariantValue* value = srecord->get(this->colOrder, ctx);
	domVariable->setProperty(this->outputName, (new(ctx) DomVariable(value, ctx)), ctx);
}
int ColumnResult::getType(ThreadContext* ctx) throw() 
{
	return AbstructSelectResult::COLUMN;
}
void ColumnResult::__cleanUp(ThreadContext* ctx){
}
}}}}

