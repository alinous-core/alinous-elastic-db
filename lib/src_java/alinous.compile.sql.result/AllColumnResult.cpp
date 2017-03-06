#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
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
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.result/AbstructSelectResult.h"
#include "alinous.compile.sql.result/AllColumnResult.h"
#include "alinous.compile.sql.result/ColumnResult.h"
#include "alinous.compile.sql.result/FunctionResult.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"

namespace alinous {namespace compile {namespace sql {namespace result {





bool AllColumnResult::__init_done = __init_static_variables();
bool AllColumnResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AllColumnResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AllColumnResult::AllColumnResult(ScanTableMetadata* metadata, ThreadContext* ctx) throw()  : IObject(ctx), AbstructSelectResult(ctx), metadata(nullptr)
{
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
}
void AllColumnResult::__construct_impl(ScanTableMetadata* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
}
 AllColumnResult::~AllColumnResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AllColumnResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AllColumnResult", L"~AllColumnResult");
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
	AbstructSelectResult::__releaseRegerences(true, ctx);
}
void AllColumnResult::fetchFromRecord(DomVariable* domVariable, ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
	int numColmns = srecord->numColumns(ctx);
	ArrayList<ScanTableColumnMetadata>* cols = this->metadata->getColumns(ctx);
	for(int i = 0; i != numColmns; ++i)
	{
		VariantValue* vv = srecord->get(i, ctx);
		String* name = cols->get(i, ctx)->getName(ctx);
		domVariable->setProperty(name, (new(ctx) DomVariable(vv, ctx)), ctx);
	}
}
int AllColumnResult::getType(ThreadContext* ctx) throw() 
{
	return AbstructSelectResult::ALL_COLUMNS;
}
void AllColumnResult::__cleanUp(ThreadContext* ctx){
}
}}}}

