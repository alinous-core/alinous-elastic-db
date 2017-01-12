#ifndef ALINOUS_COMPILE_ALINOUSELEMENTNETWORKFACTORY_H_
#define ALINOUS_COMPILE_ALINOUSELEMENTNETWORKFACTORY_H_
namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {
class AlinousSrc;}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class CheckDefinition;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class ColumnTypeDescriptor;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class DdlColumnDescriptor;}}}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {namespace declare {
class ClassExtends;}}}

namespace alinous {namespace compile {namespace declare {
class ClassImplements;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMemberModifiers;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentsListDefine;}}}}

namespace alinous {namespace compile {namespace declare {
class ClassMemberVariable;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class ReturnValueDefinition;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class ThrowsDefine;}}}}

namespace alinous {namespace compile {namespace expression {
class DomIndexSegment;}}}

namespace alinous {namespace compile {namespace expression {
class DomNameSegment;}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class AndExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class ConditionalAndExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class ConditionalOrExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class ExclusiveOrExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class InclusiveOrExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class EqualityExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class InstanceOfExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class RelationalExpression;}}}}

namespace alinous {namespace compile {namespace expression {
class AdditiveExpression;}}}

namespace alinous {namespace compile {namespace expression {
class MultiplicativeExpression;}}}

namespace alinous {namespace compile {namespace expression {
class ShiftExpression;}}}

namespace alinous {namespace compile {namespace expression {
class AllocationExpression;}}}

namespace alinous {namespace compile {namespace expression {
class BitReverseExpression;}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class BooleanSubExpression;}}}}

namespace alinous {namespace compile {namespace expression {
class CastExpression;}}}

namespace alinous {namespace compile {namespace expression {
class ConditionalExpression;}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpStreamCast;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpStreamParenthesis;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpStreamSegment;}}}}

namespace alinous {namespace compile {namespace expression {
class FunctionArguments;}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class FunctionCallExpression;}}}}

namespace alinous {namespace compile {namespace expression {
class Literal;}}}

namespace alinous {namespace compile {namespace expression {
class BooleanLiteral;}}}

namespace alinous {namespace compile {namespace expression {
class NullLiteral;}}}

namespace alinous {namespace compile {namespace expression {
class ParenthesisExpression;}}}

namespace alinous {namespace compile {namespace expression {
class PreDecrementExpression;}}}

namespace alinous {namespace compile {namespace expression {
class PreIncrementExpression;}}}

namespace alinous {namespace compile {namespace expression {
class SubExpression;}}}

namespace alinous {namespace compile {namespace expression {
class UnaryExpression;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpressionStream;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLAdditiveExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLMultiplicativeExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLSubqueryExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLLiteral;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLParenthesisExpression;}}}}

namespace alinous {namespace compile {namespace sql {
class InsertValues;}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLAndExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLOrExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLBooleanLiteral;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLBoolSubExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLEqualityExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLInExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLIsNullExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class SQLJoinCondition;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLLikeExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLNotExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLRelationalExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLSubExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class SQLExpressionList;}}}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class SQLExpressionListAll;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLExpressionStream;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLFrom;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLGroupBy;}}}}

namespace alinous {namespace compile {namespace sql {
class UpdateSet;}}}

namespace alinous {namespace compile {
class IncludePreprocessor;}}

namespace alinous {namespace compile {namespace stmt {
class AssignmentStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class BreakStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class CaseStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class DefaultStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class CatchBlock;}}}

namespace alinous {namespace compile {namespace stmt {
class ContinueStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class DoWhileStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ExpressionStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class FinallyBlock;}}}

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
class ThrowStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class TryBlock;}}}

namespace alinous {namespace compile {namespace stmt {
class TypedVariableDeclare;}}}

namespace alinous {namespace compile {namespace stmt {
class WhileStatement;}}}

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
class InsertStatement;}}}

namespace alinous {namespace compile {namespace sql {
class RollbackStatement;}}}

namespace alinous {namespace compile {namespace sql {
class UpdateStatement;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class InnerJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class CrossJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class RightJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class NaturalJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class DomVariableJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class JoinSubQueryTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class TableJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class WrappedJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {
class SelectStatement;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class TableList;}}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class PrimaryKeys;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLLimitOffset;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class Unique;}}}}

namespace alinous {namespace runtime {
class AlinousModule;}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class NotExpression;}}}}

namespace alinous {namespace runtime {
class AlinousModulePackage;}}

namespace alinous {namespace compile {namespace declare {
class VirtualTable;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class LeftJoin;}}}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::declare::ClassExtends;
using ::alinous::compile::declare::ClassImplements;
using ::alinous::compile::declare::ClassMemberModifiers;
using ::alinous::compile::declare::ClassMemberVariable;
using ::alinous::compile::declare::ClassMethodFunction;
using ::alinous::compile::declare::VirtualTable;
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
using ::alinous::compile::expression::Literal;
using ::alinous::compile::expression::MultiplicativeExpression;
using ::alinous::compile::expression::NullLiteral;
using ::alinous::compile::expression::ParenthesisExpression;
using ::alinous::compile::expression::PreDecrementExpression;
using ::alinous::compile::expression::PreIncrementExpression;
using ::alinous::compile::expression::ShiftExpression;
using ::alinous::compile::expression::SubExpression;
using ::alinous::compile::expression::UnaryExpression;
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
using ::alinous::compile::sql::ddl::Unique;
using ::alinous::compile::sql::expression::SQLAdditiveExpression;
using ::alinous::compile::sql::expression::SQLColumnIdentifier;
using ::alinous::compile::sql::expression::SQLExpressionStream;
using ::alinous::compile::sql::expression::SQLLiteral;
using ::alinous::compile::sql::expression::SQLMultiplicativeExpression;
using ::alinous::compile::sql::expression::SQLParenthesisExpression;
using ::alinous::compile::sql::expression::SQLSubExpression;
using ::alinous::compile::sql::expression::SQLSubqueryExpression;
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
using ::alinous::compile::sql::select::join::CrossJoin;
using ::alinous::compile::sql::select::join::DomVariableJoinTarget;
using ::alinous::compile::sql::select::join::InnerJoin;
using ::alinous::compile::sql::select::join::JoinSubQueryTarget;
using ::alinous::compile::sql::select::join::LeftJoin;
using ::alinous::compile::sql::select::join::NaturalJoin;
using ::alinous::compile::sql::select::join::RightJoin;
using ::alinous::compile::sql::select::join::SQLJoinCondition;
using ::alinous::compile::sql::select::join::TableJoinTarget;
using ::alinous::compile::sql::select::join::TableList;
using ::alinous::compile::sql::select::join::WrappedJoinTarget;
using ::alinous::compile::stmt::AssignmentStatement;
using ::alinous::compile::stmt::BreakStatement;
using ::alinous::compile::stmt::CaseStatement;
using ::alinous::compile::stmt::CatchBlock;
using ::alinous::compile::stmt::ContinueStatement;
using ::alinous::compile::stmt::DefaultStatement;
using ::alinous::compile::stmt::DoWhileStatement;
using ::alinous::compile::stmt::ExpressionStatement;
using ::alinous::compile::stmt::FinallyBlock;
using ::alinous::compile::stmt::ForStatement;
using ::alinous::compile::stmt::ForUpdatePart;
using ::alinous::compile::stmt::IfStatement;
using ::alinous::compile::stmt::LabeledStatement;
using ::alinous::compile::stmt::ReturnStatement;
using ::alinous::compile::stmt::StatementBlock;
using ::alinous::compile::stmt::StatementList;
using ::alinous::compile::stmt::SwitchCasePart;
using ::alinous::compile::stmt::SwitchStatement;
using ::alinous::compile::stmt::ThrowStatement;
using ::alinous::compile::stmt::TryBlock;
using ::alinous::compile::stmt::TypedVariableDeclare;
using ::alinous::compile::stmt::WhileStatement;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::AlinousModule;
using ::alinous::runtime::AlinousModulePackage;
using ::alinous::runtime::dom::VariableException;



class AlinousElementNetworkFactory final : public virtual IObject {
public:
	AlinousElementNetworkFactory(const AlinousElementNetworkFactory& base) = default;
public:
	AlinousElementNetworkFactory(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousElementNetworkFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static IAlinousElement* formNetworkData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_ALINOUSELEMENTNETWORKFACTORY_H_ */
