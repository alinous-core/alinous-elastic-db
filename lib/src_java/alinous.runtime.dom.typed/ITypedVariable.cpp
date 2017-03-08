#include "include/global.h"


#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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

namespace alinous {namespace runtime {namespace dom {namespace typed {




constexpr const int ITypedVariable::TYPE_BOOL;
constexpr const int ITypedVariable::TYPE_BYTE;
constexpr const int ITypedVariable::TYPE_CHAR;
constexpr const int ITypedVariable::TYPE_DOUBLE;
constexpr const int ITypedVariable::TYPE_FLOAT;
constexpr const int ITypedVariable::TYPE_INT;
constexpr const int ITypedVariable::TYPE_LONG;
constexpr const int ITypedVariable::TYPE_SHORT;
constexpr const int ITypedVariable::TYPE_STRING;
constexpr const int ITypedVariable::TYPE_BIGDECIMAL;
constexpr const int ITypedVariable::TYPE_TIME;
constexpr const int ITypedVariable::TYPE_TIMESTAMP;
constexpr const int ITypedVariable::TYPE_ARRAY;
constexpr const int ITypedVariable::TYPE_CLASS_OBJECT;
String* ITypedVariable::TYPED_VARIABLE = ConstStr::getCNST_STR_1151();
bool ITypedVariable::__init_done = __init_static_variables();
bool ITypedVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ITypedVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ITypedVariable::ITypedVariable(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx)
{
}
void ITypedVariable::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ITypedVariable::~ITypedVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ITypedVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IAlinousVariable::__releaseRegerences(true, ctx);
}
void ITypedVariable::__cleanUp(ThreadContext* ctx){
}
}}}}

