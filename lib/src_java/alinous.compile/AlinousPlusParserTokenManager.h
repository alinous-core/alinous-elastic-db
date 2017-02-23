#ifndef ALINOUS_COMPILE_ALINOUSPLUSPARSERTOKENMANAGER_H_
#define ALINOUS_COMPILE_ALINOUSPLUSPARSERTOKENMANAGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace io {
class PrintStream;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class Error;}}

namespace alinous {namespace compile {
class Token;}}

namespace alinous {namespace compile {
class TokenMgrError;}}

namespace alinous {namespace compile {
class JavaCharStream;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace compile {
class AlinousPlusParserConstants;}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {namespace declare {
class ClassExtends;}}}

namespace alinous {namespace compile {namespace declare {
class ClassImplements;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMemberModifiers;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMemberVariable;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace compile {namespace declare {
class IClassMember;}}}

namespace alinous {namespace compile {namespace declare {
class IDeclare;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentsListDefine;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class ReturnValueDefinition;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class ThrowsDefine;}}}}

namespace alinous {namespace compile {namespace expression {
class AdditiveExpression;}}}

namespace alinous {namespace compile {namespace expression {
class AllocationExpression;}}}

namespace alinous {namespace compile {namespace expression {
class BitReverseExpression;}}}

namespace alinous {namespace compile {namespace expression {
class BooleanLiteral;}}}

namespace alinous {namespace compile {namespace expression {
class CastExpression;}}}

namespace alinous {namespace compile {namespace expression {
class ConditionalExpression;}}}

namespace alinous {namespace compile {namespace expression {
class DomIndexSegment;}}}

namespace alinous {namespace compile {namespace expression {
class DomNameSegment;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace expression {
class FunctionArguments;}}}

namespace alinous {namespace compile {namespace expression {
class IDomSegment;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace expression {
class Literal;}}}

namespace alinous {namespace compile {namespace expression {
class MultiplicativeExpression;}}}

namespace alinous {namespace compile {namespace expression {
class NullLiteral;}}}

namespace alinous {namespace compile {namespace expression {
class ParenthesisExpression;}}}

namespace alinous {namespace compile {namespace expression {
class PreDecrementExpression;}}}

namespace alinous {namespace compile {namespace expression {
class PreIncrementExpression;}}}

namespace alinous {namespace compile {namespace expression {
class ShiftExpression;}}}

namespace alinous {namespace compile {namespace expression {
class SubExpression;}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class AndExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class BooleanSubExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class ConditionalAndExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class ConditionalOrExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class EqualityExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class ExclusiveOrExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class InclusiveOrExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class InstanceOfExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class NotExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class RelationalExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpStreamCast;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpStreamParenthesis;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpStreamSegment;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpressionStream;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class FunctionCallExpression;}}}}

namespace alinous {namespace compile {namespace sql {
class BeginStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CommitStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CreateIndexStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CreateTableStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DeleteStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DropIndexStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DropTableStatement;}}}

namespace alinous {namespace compile {namespace sql {
class ISqlStatement;}}}

namespace alinous {namespace compile {namespace sql {
class InsertStatement;}}}

namespace alinous {namespace compile {namespace sql {
class InsertValues;}}}

namespace alinous {namespace compile {namespace sql {
class RollbackStatement;}}}

namespace alinous {namespace compile {namespace sql {
class SelectStatement;}}}

namespace alinous {namespace compile {namespace sql {
class UpdateSet;}}}

namespace alinous {namespace compile {namespace sql {
class UpdateStatement;}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class CheckDefinition;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class ColumnTypeDescriptor;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class DdlColumnDescriptor;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class PrimaryKeys;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class ShardKeys;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class Unique;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLAdditiveExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLExpressionStream;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLLiteral;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLMultiplicativeExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLParenthesisExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLSubExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLSubqueryExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class ISQLBoolExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLAndExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLBoolSubExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLBooleanLiteral;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLEqualityExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLInExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLIsNullExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLLikeExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLNotExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLOrExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLRelationalExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class SQLExpressionList;}}}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class SQLExpressionListAll;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLFrom;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLGroupBy;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLLimitOffset;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class DomVariableJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class InnerJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class JoinSubQueryTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class LeftJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class NaturalJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class RightJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class AbstractSQLJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class CrossJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class SQLJoinCondition;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class TableJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class TableList;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class WrappedJoinTarget;}}}}}

namespace alinous {namespace compile {namespace stmt {
class AssignmentStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class BreakStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class CaseStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ContinueStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class DefaultStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class DoWhileStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ExpressionStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ForStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ForUpdatePart;}}}

namespace alinous {namespace compile {namespace stmt {
class IfStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class LabeledStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ReturnStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class StatementBlock;}}}

namespace alinous {namespace compile {namespace stmt {
class StatementList;}}}

namespace alinous {namespace compile {namespace stmt {
class SwitchCasePart;}}}

namespace alinous {namespace compile {namespace stmt {
class SwitchStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class TypedVariableDeclare;}}}

namespace alinous {namespace compile {namespace stmt {
class WhileStatement;}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::declare::ClassExtends;
using ::alinous::compile::declare::ClassImplements;
using ::alinous::compile::declare::ClassMemberModifiers;
using ::alinous::compile::declare::ClassMemberVariable;
using ::alinous::compile::declare::ClassMethodFunction;
using ::alinous::compile::declare::IClassMember;
using ::alinous::compile::declare::IDeclare;
using ::alinous::compile::declare::function::AlinousFunction;
using ::alinous::compile::declare::function::FunctionArgumentDefine;
using ::alinous::compile::declare::function::FunctionArgumentsListDefine;
using ::alinous::compile::declare::function::ReturnValueDefinition;
using ::alinous::compile::declare::function::ThrowsDefine;
using ::alinous::compile::expression::AdditiveExpression;
using ::alinous::compile::expression::AllocationExpression;
using ::alinous::compile::expression::BitReverseExpression;
using ::alinous::compile::expression::BooleanLiteral;
using ::alinous::compile::expression::CastExpression;
using ::alinous::compile::expression::ConditionalExpression;
using ::alinous::compile::expression::DomIndexSegment;
using ::alinous::compile::expression::DomNameSegment;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::compile::expression::FunctionArguments;
using ::alinous::compile::expression::IDomSegment;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::expression::Literal;
using ::alinous::compile::expression::MultiplicativeExpression;
using ::alinous::compile::expression::NullLiteral;
using ::alinous::compile::expression::ParenthesisExpression;
using ::alinous::compile::expression::PreDecrementExpression;
using ::alinous::compile::expression::PreIncrementExpression;
using ::alinous::compile::expression::ShiftExpression;
using ::alinous::compile::expression::SubExpression;
using ::alinous::compile::expression::blexp::AndExpression;
using ::alinous::compile::expression::blexp::BooleanSubExpression;
using ::alinous::compile::expression::blexp::ConditionalAndExpression;
using ::alinous::compile::expression::blexp::ConditionalOrExpression;
using ::alinous::compile::expression::blexp::EqualityExpression;
using ::alinous::compile::expression::blexp::ExclusiveOrExpression;
using ::alinous::compile::expression::blexp::InclusiveOrExpression;
using ::alinous::compile::expression::blexp::InstanceOfExpression;
using ::alinous::compile::expression::blexp::NotExpression;
using ::alinous::compile::expression::blexp::RelationalExpression;
using ::alinous::compile::expression::expstream::ExpStreamCast;
using ::alinous::compile::expression::expstream::ExpStreamParenthesis;
using ::alinous::compile::expression::expstream::ExpStreamSegment;
using ::alinous::compile::expression::expstream::ExpressionStream;
using ::alinous::compile::expression::expstream::FunctionCallExpression;
using ::alinous::compile::sql::BeginStatement;
using ::alinous::compile::sql::CommitStatement;
using ::alinous::compile::sql::CreateIndexStatement;
using ::alinous::compile::sql::CreateTableStatement;
using ::alinous::compile::sql::DeleteStatement;
using ::alinous::compile::sql::DropIndexStatement;
using ::alinous::compile::sql::DropTableStatement;
using ::alinous::compile::sql::ISqlStatement;
using ::alinous::compile::sql::InsertStatement;
using ::alinous::compile::sql::InsertValues;
using ::alinous::compile::sql::RollbackStatement;
using ::alinous::compile::sql::SelectStatement;
using ::alinous::compile::sql::UpdateSet;
using ::alinous::compile::sql::UpdateStatement;
using ::alinous::compile::sql::ddl::CheckDefinition;
using ::alinous::compile::sql::ddl::ColumnTypeDescriptor;
using ::alinous::compile::sql::ddl::DdlColumnDescriptor;
using ::alinous::compile::sql::ddl::PrimaryKeys;
using ::alinous::compile::sql::ddl::ShardKeys;
using ::alinous::compile::sql::ddl::Unique;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::compile::sql::expression::SQLAdditiveExpression;
using ::alinous::compile::sql::expression::SQLColumnIdentifier;
using ::alinous::compile::sql::expression::SQLExpressionStream;
using ::alinous::compile::sql::expression::SQLLiteral;
using ::alinous::compile::sql::expression::SQLMultiplicativeExpression;
using ::alinous::compile::sql::expression::SQLParenthesisExpression;
using ::alinous::compile::sql::expression::SQLSubExpression;
using ::alinous::compile::sql::expression::SQLSubqueryExpression;
using ::alinous::compile::sql::expression::blexp::ISQLBoolExpression;
using ::alinous::compile::sql::expression::blexp::SQLAndExpression;
using ::alinous::compile::sql::expression::blexp::SQLBoolSubExpression;
using ::alinous::compile::sql::expression::blexp::SQLBooleanLiteral;
using ::alinous::compile::sql::expression::blexp::SQLEqualityExpression;
using ::alinous::compile::sql::expression::blexp::SQLInExpression;
using ::alinous::compile::sql::expression::blexp::SQLIsNullExpression;
using ::alinous::compile::sql::expression::blexp::SQLLikeExpression;
using ::alinous::compile::sql::expression::blexp::SQLNotExpression;
using ::alinous::compile::sql::expression::blexp::SQLOrExpression;
using ::alinous::compile::sql::expression::blexp::SQLRelationalExpression;
using ::alinous::compile::sql::parts::SQLExpressionList;
using ::alinous::compile::sql::parts::SQLExpressionListAll;
using ::alinous::compile::sql::select::SQLFrom;
using ::alinous::compile::sql::select::SQLGroupBy;
using ::alinous::compile::sql::select::SQLLimitOffset;
using ::alinous::compile::sql::select::SQLWhere;
using ::alinous::compile::sql::select::join::DomVariableJoinTarget;
using ::alinous::compile::sql::select::join::IJoin;
using ::alinous::compile::sql::select::join::IJoinTarget;
using ::alinous::compile::sql::select::join::InnerJoin;
using ::alinous::compile::sql::select::join::JoinSubQueryTarget;
using ::alinous::compile::sql::select::join::LeftJoin;
using ::alinous::compile::sql::select::join::NaturalJoin;
using ::alinous::compile::sql::select::join::RightJoin;
using ::alinous::compile::sql::select::join::AbstractSQLJoin;
using ::alinous::compile::sql::select::join::CrossJoin;
using ::alinous::compile::sql::select::join::SQLJoinCondition;
using ::alinous::compile::sql::select::join::TableJoinTarget;
using ::alinous::compile::sql::select::join::TableList;
using ::alinous::compile::sql::select::join::WrappedJoinTarget;
using ::alinous::compile::stmt::AssignmentStatement;
using ::alinous::compile::stmt::BreakStatement;
using ::alinous::compile::stmt::CaseStatement;
using ::alinous::compile::stmt::ContinueStatement;
using ::alinous::compile::stmt::DefaultStatement;
using ::alinous::compile::stmt::DoWhileStatement;
using ::alinous::compile::stmt::ExpressionStatement;
using ::alinous::compile::stmt::ForStatement;
using ::alinous::compile::stmt::ForUpdatePart;
using ::alinous::compile::stmt::IfStatement;
using ::alinous::compile::stmt::LabeledStatement;
using ::alinous::compile::stmt::ReturnStatement;
using ::alinous::compile::stmt::StatementBlock;
using ::alinous::compile::stmt::StatementList;
using ::alinous::compile::stmt::SwitchCasePart;
using ::alinous::compile::stmt::SwitchStatement;
using ::alinous::compile::stmt::TypedVariableDeclare;
using ::alinous::compile::stmt::WhileStatement;
using ::alinous::runtime::dbif::IDatabaseDriver;



class AlinousPlusParserTokenManager final : public AlinousPlusParserConstants, public virtual IObject {
public:
	AlinousPlusParserTokenManager(const AlinousPlusParserTokenManager& base) = default;
public:
	AlinousPlusParserTokenManager(JavaCharStream* stream, ThreadContext* ctx);
	void __construct_impl(JavaCharStream* stream, ThreadContext* ctx);
	AlinousPlusParserTokenManager(JavaCharStream* stream, long long lexState, ThreadContext* ctx);
	void __construct_impl(JavaCharStream* stream, long long lexState, ThreadContext* ctx);
	virtual ~AlinousPlusParserTokenManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	java::io::PrintStream* debugStream;
	long long curLexState;
	long long defaultLexState;
	long long jjnewStateCnt;
	long long jjround;
	long long jjmatchedPos;
	long long jjmatchedKind;
	JavaCharStream* input_stream;
	wchar_t curChar;
private:
	IArrayObjectPrimitive<uint64_t>* jjrounds;
	IArrayObjectPrimitive<uint64_t>* jjstateSet;
	StringBuilder* jjimage;
	StringBuilder* image;
	long long jjimageLen;
	long long lengthOfMatch;
public:
	static const StaticArrayObject<UnicodeStringWrapper> __jjstrLiteralImages;
	static IArrayObject<String>* jjstrLiteralImages;
	static const StaticArrayObject<UnicodeStringWrapper> __lexStateNames;
	static IArrayObject<String>* lexStateNames;
	static const StaticArrayObjectPrimitive<long long> __jjnewLexState;
	static IArrayObjectPrimitive<long long>* jjnewLexState;
	static const StaticArrayObjectPrimitive<uint64_t> __jjbitVec0;
	static IArrayObjectPrimitive<uint64_t>* jjbitVec0;
	static const StaticArrayObjectPrimitive<uint64_t> __jjbitVec2;
	static IArrayObjectPrimitive<uint64_t>* jjbitVec2;
	static const StaticArrayObjectPrimitive<uint64_t> __jjnextStates;
	static IArrayObjectPrimitive<uint64_t>* jjnextStates;
	static const StaticArrayObjectPrimitive<uint64_t> __jjtoToken;
	static IArrayObjectPrimitive<uint64_t>* jjtoToken;
	static const StaticArrayObjectPrimitive<uint64_t> __jjtoSkip;
	static IArrayObjectPrimitive<uint64_t>* jjtoSkip;
	static const StaticArrayObjectPrimitive<uint64_t> __jjtoSpecial;
	static IArrayObjectPrimitive<uint64_t>* jjtoSpecial;
	static const StaticArrayObjectPrimitive<uint64_t> __jjtoMore;
	static IArrayObjectPrimitive<uint64_t>* jjtoMore;
public:
	void setDebugStream(java::io::PrintStream* ds, ThreadContext* ctx);
	Token* getNextToken(ThreadContext* ctx);
	void ReInit(JavaCharStream* stream, ThreadContext* ctx);
	void ReInit(JavaCharStream* stream, long long lexState, ThreadContext* ctx);
	void SwitchTo(long long lexState, ThreadContext* ctx);
	Token* jjFillToken(ThreadContext* ctx);
	void SkipLexicalActions(Token* matchedToken, ThreadContext* ctx);
private:
	long long jjStopAtPos(long long pos, long long kind, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa0_2(ThreadContext* ctx);
	long long jjMoveStringLiteralDfa0_0(ThreadContext* ctx);
	long long jjMoveStringLiteralDfa1_0(long long active0, long long active1, long long active2, long long active3, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa2_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, long long old3, long long active3, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa3_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, long long old3, long long active3, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa4_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa5_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa6_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa7_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa8_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa9_0(long long old0, long long active0, long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa10_0(long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa11_0(long long old1, long long active1, long long old2, long long active2, ThreadContext* ctx);
	long long jjMoveNfa_0(long long startState, long long curPos, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa0_1(ThreadContext* ctx);
	long long jjMoveStringLiteralDfa1_1(long long active3, ThreadContext* ctx);
	void jjCheckNAdd(long long state, ThreadContext* ctx);
	void jjAddStates(long long start, long long end, ThreadContext* ctx);
	void jjCheckNAddTwoStates(long long state1, long long state2, ThreadContext* ctx);
	void jjCheckNAddStates(long long start, long long end, ThreadContext* ctx);
	void ReInitRounds(ThreadContext* ctx);
private:
	static bool jjCanMove_0(long long hiByte, long long i1, long long i2, long long l1, long long l2, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_ALINOUSPLUSPARSERTOKENMANAGER_H_ */
