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
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"

namespace alinous {namespace compile {namespace sql {namespace parts {





bool AbstractExpressionPart::__init_done = __init_static_variables();
bool AbstractExpressionPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractExpressionPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractExpressionPart::AbstractExpressionPart(ThreadContext* ctx) throw()  : IObject(ctx), ISQLExpressionPart(ctx)
{
}
void AbstractExpressionPart::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractExpressionPart::~AbstractExpressionPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractExpressionPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ISQLExpressionPart::__releaseRegerences(true, ctx);
}
int AbstractExpressionPart::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpressionPart::getLine(ctx);
}
int AbstractExpressionPart::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpressionPart::getStartPosition(ctx);
}
int AbstractExpressionPart::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpressionPart::getEndLine(ctx);
}
int AbstractExpressionPart::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpressionPart::getEndPosition(ctx);
}
AbstractSrcElement* AbstractExpressionPart::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpressionPart::getParent(ctx);
}
void AbstractExpressionPart::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpressionPart::setParent(parent, ctx);
}
bool AbstractExpressionPart::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
void AbstractExpressionPart::__cleanUp(ThreadContext* ctx){
}
}}}}

