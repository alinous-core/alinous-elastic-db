#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.compile/DebugProbeSection.h"
#include "alinous.compile/DebugProbe.h"
#include "alinous.compile/TokenMgrError.h"
#include "alinous.compile/ParseException.h"
#include "alinous.compile/JavaCharStream.h"
#include "alinous.compile/AlinousPlusParserConstants.h"
#include "alinous.compile/AlinousPlusParserTokenManager.h"
#include "alinous.compile/AlinousPlusParser.h"

namespace alinous {namespace compile {





constexpr const long long TokenMgrError::serialVersionUID;
constexpr const int TokenMgrError::LEXICAL_ERROR;
constexpr const int TokenMgrError::STATIC_LEXER_ERROR;
constexpr const int TokenMgrError::INVALID_LEXICAL_STATE;
constexpr const int TokenMgrError::LOOP_DETECTED;
bool TokenMgrError::__init_done = __init_static_variables();
bool TokenMgrError::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TokenMgrError", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TokenMgrError::TokenMgrError(ThreadContext* ctx) throw()  : IObject(ctx), Error(ctx), errorCode(0)
{
}
void TokenMgrError::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TokenMgrError::TokenMgrError(String* message, int reason, ThreadContext* ctx) throw()  : IObject(ctx), Error(message, ctx), errorCode(0)
{
	errorCode = reason;
}
void TokenMgrError::__construct_impl(String* message, int reason, ThreadContext* ctx) throw() 
{
	errorCode = reason;
}
 TokenMgrError::TokenMgrError(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, int reason, ThreadContext* ctx) throw()  : IObject(ctx), Error(ctx), errorCode(0)
{
	__construct_impl(LexicalError(EOFSeen, lexState, errorLine, errorColumn, errorAfter, curChar, ctx), reason, ctx);
}
void TokenMgrError::__construct_impl(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, int reason, ThreadContext* ctx) throw() 
{
	__construct_impl(LexicalError(EOFSeen, lexState, errorLine, errorColumn, errorAfter, curChar, ctx), reason, ctx);
}
 TokenMgrError::~TokenMgrError() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TokenMgrError::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TokenMgrError", L"~TokenMgrError");
	if(!prepare){
		return;
	}
	Error::__releaseRegerences(true, ctx);
}
String* TokenMgrError::getMessage(ThreadContext* ctx) throw() 
{
	return Error::getMessage(ctx);
}
String* TokenMgrError::addEscapes(String* str, ThreadContext* ctx) throw() 
{
	StringBuffer* retval = (new(ctx) StringBuffer(ctx));
	wchar_t ch = 0;
	for(int i = 0; i < str->length(ctx); i ++ )
	{
		switch(str->charAt(i, ctx)) {
		case 0:
			continue;
		case L'\b':
			retval->append(ConstStr::getCNST_STR_86(), ctx);
			continue;
		case L'\t':
			retval->append(ConstStr::getCNST_STR_125(), ctx);
			continue;
		case L'\n':
			retval->append(ConstStr::getCNST_STR_126(), ctx);
			continue;
		case L'\f':
			retval->append(ConstStr::getCNST_STR_128(), ctx);
			continue;
		case L'\r':
			retval->append(ConstStr::getCNST_STR_127(), ctx);
			continue;
		case L'\"':
			retval->append(ConstStr::getCNST_STR_123(), ctx);
			continue;
		case L'\'':
			retval->append(ConstStr::getCNST_STR_1311(), ctx);
			continue;
		case L'\\':
			retval->append(ConstStr::getCNST_STR_124(), ctx);
			continue;
		default:
			ch = str->charAt(i, ctx);
			if((ch) < (wchar_t)0x20 || ch > (wchar_t)0x7e)
			{
				String* s = ConstStr::getCNST_STR_384()->clone(ctx)->append(Integer::toString((int)ch, 16, ctx), ctx);
				retval->append(ConstStr::getCNST_STR_1312()->clone(ctx)->append(s->substring(s->length(ctx) - 4, s->length(ctx), ctx), ctx), ctx);
			}
						else 
			{
				retval->append(ch, ctx);
			}
			continue;
			break;
		}
	}
	return retval->toString(ctx);
}
String* TokenMgrError::LexicalError(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, ThreadContext* ctx) throw() 
{
	return (ConstStr::getCNST_STR_1313()->clone(ctx)->append(errorLine, ctx)->append(ConstStr::getCNST_STR_1314(), ctx)->append(errorColumn, ctx)->append(ConstStr::getCNST_STR_1315(), ctx)->append((EOFSeen ? ConstStr::getCNST_STR_1316() : (ConstStr::getCNST_STR_1317()->clone(ctx)->append(addEscapes(String::valueOf(curChar, ctx), ctx), ctx)->append(ConstStr::getCNST_STR_1317(), ctx))->clone(ctx)->append(ConstStr::getCNST_STR_887(), ctx)->append(((int)curChar), ctx)->append(ConstStr::getCNST_STR_1318(), ctx)), ctx)->append(ConstStr::getCNST_STR_1319(), ctx)->append(addEscapes(errorAfter, ctx), ctx)->append(ConstStr::getCNST_STR_1317(), ctx));
}
void TokenMgrError::__cleanUp(ThreadContext* ctx){
}
}}

