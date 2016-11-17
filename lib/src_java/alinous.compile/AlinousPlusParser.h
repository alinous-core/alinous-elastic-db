#ifndef ALINOUS_COMPILE_ALINOUSPLUSPARSER_H_
#define ALINOUS_COMPILE_ALINOUSPLUSPARSER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class AlinousSrc;}}

namespace alinous {namespace compile {namespace stmt {
class StatementList;}}}

namespace alinous {namespace compile {namespace declare {
class IDeclare;}}}

namespace alinous {namespace compile {
class ParseException;}}

namespace java {namespace lang {
class Error;}}

namespace alinous {namespace compile {
class IncludePreprocessor;}}

namespace alinous {namespace compile {namespace expression {
class Literal;}}}

namespace alinous {namespace compile {
class Token;}}

namespace alinous {namespace compile {
class IStatement;}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {namespace declare {
class ClassExtends;}}}

namespace alinous {namespace compile {namespace declare {
class IClassMember;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMemberVariable;}}}

namespace alinous {namespace compile {namespace declare {
class ClassImplements;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMemberModifiers;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class ReturnValueDefinition;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentsListDefine;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class ThrowsDefine;}}}}

namespace alinous {namespace compile {namespace stmt {
class StatementBlock;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace stmt {
class IfStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class SwitchStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class LabeledStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class SwitchCasePart;}}}

namespace alinous {namespace compile {namespace stmt {
class CaseStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class DefaultStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ForStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ForUpdatePart;}}}

namespace alinous {namespace compile {namespace stmt {
class DoWhileStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class WhileStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class BreakStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ContinueStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class TypedVariableDeclare;}}}

namespace alinous {namespace compile {namespace stmt {
class AssignmentStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ExpressionStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ReturnStatement;}}}

namespace alinous {namespace compile {namespace expression {
class ConditionalExpression;}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class ConditionalOrExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class BooleanSubExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class ConditionalAndExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class InclusiveOrExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class ExclusiveOrExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class AndExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class EqualityExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class InstanceOfExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class RelationalExpression;}}}}

namespace alinous {namespace compile {namespace expression {
class ShiftExpression;}}}

namespace alinous {namespace compile {namespace expression {
class SubExpression;}}}

namespace alinous {namespace compile {namespace expression {
class AdditiveExpression;}}}

namespace alinous {namespace compile {namespace expression {
class MultiplicativeExpression;}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class NotExpression;}}}}

namespace alinous {namespace compile {namespace expression {
class AllocationExpression;}}}

namespace alinous {namespace compile {namespace expression {
class FunctionArguments;}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpressionStream;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class FunctionCallExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpStreamSegment;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpStreamCast;}}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class ExpStreamParenthesis;}}}}

namespace alinous {namespace compile {namespace expression {
class PreIncrementExpression;}}}

namespace alinous {namespace compile {namespace expression {
class PreDecrementExpression;}}}

namespace alinous {namespace compile {namespace expression {
class BitReverseExpression;}}}

namespace alinous {namespace compile {namespace expression {
class ParenthesisExpression;}}}

namespace alinous {namespace compile {namespace expression {
class CastExpression;}}}

namespace alinous {namespace compile {namespace expression {
class BooleanLiteral;}}}

namespace alinous {namespace compile {namespace expression {
class NullLiteral;}}}

namespace alinous {namespace compile {namespace expression {
class IDomSegment;}}}

namespace alinous {namespace compile {namespace expression {
class DomNameSegment;}}}

namespace alinous {namespace compile {namespace expression {
class DomIndexSegment;}}}

namespace alinous {namespace compile {namespace sql {
class ISqlStatement;}}}

namespace alinous {namespace compile {namespace sql {
class SelectStatement;}}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class SQLExpressionList;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLFrom;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLGroupBy;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLLimitOffset;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class AbstractSQLJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class SQLJoinCondition;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class TableList;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class InnerJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class CrossJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class LeftJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class RightJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class NaturalJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class WrappedJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class TableJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class DomVariableJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class JoinSubQueryTarget;}}}}}

namespace alinous {namespace compile {namespace sql {
class InsertStatement;}}}

namespace alinous {namespace compile {namespace sql {
class InsertValues;}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLExpressionStream;}}}}

namespace alinous {namespace compile {namespace sql {
class UpdateStatement;}}}

namespace alinous {namespace compile {namespace sql {
class UpdateSet;}}}

namespace alinous {namespace compile {namespace sql {
class DeleteStatement;}}}

namespace alinous {namespace compile {namespace sql {
class BeginStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CommitStatement;}}}

namespace alinous {namespace compile {namespace sql {
class RollbackStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CreateTableStatement;}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class DdlColumnDescriptor;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class Unique;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class PrimaryKeys;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class CheckDefinition;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class ColumnTypeDescriptor;}}}}

namespace alinous {namespace compile {namespace sql {
class DropTableStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CreateIndexStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DropIndexStatement;}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLOrExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLBoolSubExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLAndExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLNotExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLEqualityExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLRelationalExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLIsNullExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLLikeExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLInExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLAdditiveExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLSubExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLMultiplicativeExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLParenthesisExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class ISQLBoolExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLBooleanLiteral;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLLiteral;}}}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class SQLExpressionListAll;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLSubqueryExpression;}}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace compile {
class JavaCharStream;}}

namespace java {namespace lang {
class RuntimeException;}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace alinous {namespace compile {
class AlinousPlusParserTokenManager;}}

namespace java {namespace io {
class Reader;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace compile {
class AlinousPlusParserConstants;}}

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



class AlinousPlusParser final : public AlinousPlusParserConstants, public virtual IObject {
public:
	class LookaheadSuccess;
	class JJCalls;
	AlinousPlusParser(const AlinousPlusParser& base) = default;
public:
	AlinousPlusParser(java::io::InputStream* stream, ThreadContext* ctx);
	void __construct_impl(java::io::InputStream* stream, ThreadContext* ctx);
	AlinousPlusParser(java::io::InputStream* stream, String* encoding, ThreadContext* ctx);
	void __construct_impl(java::io::InputStream* stream, String* encoding, ThreadContext* ctx);
	AlinousPlusParser(java::io::Reader* stream, ThreadContext* ctx);
	void __construct_impl(java::io::Reader* stream, ThreadContext* ctx);
	AlinousPlusParser(AlinousPlusParserTokenManager* tm, ThreadContext* ctx);
	void __construct_impl(AlinousPlusParserTokenManager* tm, ThreadContext* ctx);
	virtual ~AlinousPlusParser() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	AlinousPlusParserTokenManager* token_source;
	Token* token;
	Token* jj_nt;
	JavaCharStream* jj_input_stream;
private:
	long long jj_ntk;
	Token* jj_scanpos; Token* jj_lastpos;
	long long jj_la;
	long long jj_gen;
	IArrayObjectPrimitive<long long>* jj_la1;
	IArrayObject<JJCalls>* jj_2_rtns;
	bool jj_rescan;
	long long jj_gc;
	AlinousPlusParser::LookaheadSuccess* jj_ls;
	java::util::List<IArrayObjectPrimitive<long long>>* jj_expentries;
	IArrayObjectPrimitive<long long>* jj_expentry;
	long long jj_kind;
	IArrayObjectPrimitive<long long>* jj_lasttokens;
	long long jj_endpos;
private:
	static IArrayObjectPrimitive<long long>* jj_la1_0;
	static IArrayObjectPrimitive<long long>* jj_la1_1;
	static IArrayObjectPrimitive<long long>* jj_la1_2;
	static IArrayObjectPrimitive<long long>* jj_la1_3;
	static IArrayObjectPrimitive<long long>* jj_la1_4;
	static IArrayObjectPrimitive<long long>* jj_la1_5;
	static IArrayObjectPrimitive<long long>* jj_la1_6;
public:
	AlinousSrc* parse(ThreadContext* ctx);
	void headerSection(AlinousSrc* src, ThreadContext* ctx);
	IncludePreprocessor* includePreprocessor(ThreadContext* ctx);
	StatementList* statementList(ThreadContext* ctx);
	IStatement* allStatements(ThreadContext* ctx);
	IDeclare* alinousDeclare(ThreadContext* ctx);
	AlinousClass* alinousInterface(ThreadContext* ctx);
	AlinousClass* alinousClass(ThreadContext* ctx);
	ArrayList<ClassImplements>* classImplements(ThreadContext* ctx);
	ClassExtends* classExtends(ThreadContext* ctx);
	IClassMember* classMember(ThreadContext* ctx);
	void classMemberVariableLookAhead(ThreadContext* ctx);
	ClassMemberVariable* classMemberVariable(ThreadContext* ctx);
	ClassMethodFunction* classMethodFunction(ThreadContext* ctx);
	ClassMemberModifiers* classMemberModifiers(ThreadContext* ctx);
	void alinousFunctionLookAhead(ThreadContext* ctx);
	AlinousFunction* alinousFunction(ThreadContext* ctx);
	ReturnValueDefinition* returnValueDefinition(ThreadContext* ctx);
	FunctionArgumentsListDefine* functionArgumentsListDefine(ThreadContext* ctx);
	FunctionArgumentDefine* functionArgumentDefine(ThreadContext* ctx);
	ThrowsDefine* throwsDefine(ThreadContext* ctx);
	IStatement* alinousStatement(ThreadContext* ctx);
	IfStatement* ifStatement(ThreadContext* ctx);
	SwitchStatement* switchStatement(ThreadContext* ctx);
	SwitchCasePart* switchCasePart(ThreadContext* ctx);
	CaseStatement* caseStatement(ThreadContext* ctx);
	DefaultStatement* defaultStatement(ThreadContext* ctx);
	ForStatement* forStatement(ThreadContext* ctx);
	ForUpdatePart* forUpdatePart(ThreadContext* ctx);
	DoWhileStatement* doWhileStatement(ThreadContext* ctx);
	WhileStatement* whileStatement(ThreadContext* ctx);
	BreakStatement* breakStatement(ThreadContext* ctx);
	ContinueStatement* continueStatement(ThreadContext* ctx);
	LabeledStatement* labeledStatement(ThreadContext* ctx);
	TypedVariableDeclare* typedVariableDeclare(ThreadContext* ctx);
	void assignmentStatementLookAhead(ThreadContext* ctx);
	AssignmentStatement* assignmentStatement(ThreadContext* ctx);
	StatementBlock* statementBlock(ThreadContext* ctx);
	ExpressionStatement* expressionStatement(ThreadContext* ctx);
	ReturnStatement* returnStatement(ThreadContext* ctx);
	IExpression* conditionalExpression(ThreadContext* ctx);
	IExpression* conditionalOrExpression(ThreadContext* ctx);
	IExpression* conditionalAndExpression(ThreadContext* ctx);
	IExpression* inclusiveOrExpression(ThreadContext* ctx);
	IExpression* exclusiveOrExpression(ThreadContext* ctx);
	IExpression* andExpression(ThreadContext* ctx);
	IExpression* equalityExpression(ThreadContext* ctx);
	IExpression* instanceOfExpression(ThreadContext* ctx);
	IExpression* relationalExpression(ThreadContext* ctx);
	IExpression* shiftExpression(ThreadContext* ctx);
	IExpression* additiveExpression(ThreadContext* ctx);
	IExpression* multiplicativeExpression(ThreadContext* ctx);
	IExpression* notExpression(ThreadContext* ctx);
	IExpression* unaryExpression(ThreadContext* ctx);
	AllocationExpression* allocationExpression(ThreadContext* ctx);
	ExpressionStream* expressionStream(ThreadContext* ctx);
	FunctionCallExpression* functionCallExpression(ThreadContext* ctx);
	ExpStreamSegment* expStreamSegment(ThreadContext* ctx);
	ExpStreamCast* expStreamCast(ThreadContext* ctx);
	ExpStreamParenthesis* expStreamParenthesis(ThreadContext* ctx);
	PreIncrementExpression* preIncrementExpression(ThreadContext* ctx);
	PreDecrementExpression* preDecrementExpression(ThreadContext* ctx);
	BitReverseExpression* bitReverseExpression(ThreadContext* ctx);
	void parenthesisLookahead(ThreadContext* ctx);
	ParenthesisExpression* parenthesisExpression(ThreadContext* ctx);
	CastExpression* castExpression(ThreadContext* ctx);
	FunctionArguments* functionArguments(ThreadContext* ctx);
	Literal* literal(ThreadContext* ctx);
	BooleanLiteral* booleanLiteral(ThreadContext* ctx);
	NullLiteral* nullLiteral(ThreadContext* ctx);
	DomVariableDescriptor* domVariableDescriptor(ThreadContext* ctx);
	DomNameSegment* domNameSegment(ThreadContext* ctx);
	DomIndexSegment* domIndexSegment(ThreadContext* ctx);
	AlinousName* alinousName(ThreadContext* ctx);
	Token* nameIdentifier(ThreadContext* ctx);
	Token* assignmentOperator(ThreadContext* ctx);
	ISqlStatement* sqlStatement(ThreadContext* ctx);
	SelectStatement* selectStatement(ThreadContext* ctx);
	SQLFrom* sqlFrom(ThreadContext* ctx);
	IJoin* sqlJoin(ThreadContext* ctx);
	SQLJoinCondition* sqlJoinCondition(ThreadContext* ctx);
	IJoin* joinTarget(ThreadContext* ctx);
	IJoinTarget* tableJoinTarget(ThreadContext* ctx);
	IJoinTarget* domVariableJoinTarget(ThreadContext* ctx);
	IJoinTarget* joinSubQueryTarget(ThreadContext* ctx);
	SQLWhere* sqlWhere(ThreadContext* ctx);
	SQLGroupBy* sqlGroupBy(ThreadContext* ctx);
	SQLLimitOffset* sqlLimitOffset(ThreadContext* ctx);
	InsertStatement* insertStatement(ThreadContext* ctx);
	InsertValues* insertValues(ThreadContext* ctx);
	UpdateStatement* updateStatement(ThreadContext* ctx);
	UpdateSet* updateSet(ThreadContext* ctx);
	DeleteStatement* deleteStatement(ThreadContext* ctx);
	BeginStatement* beginStatement(ThreadContext* ctx);
	CommitStatement* commitStatement(ThreadContext* ctx);
	RollbackStatement* rollbackStatement(ThreadContext* ctx);
	CreateTableStatement* createTableStatement(ThreadContext* ctx);
	PrimaryKeys* primaryKeys(ThreadContext* ctx);
	Unique* unique(ThreadContext* ctx);
	DdlColumnDescriptor* ddlColumnDescriptor(ThreadContext* ctx);
	ColumnTypeDescriptor* columnTypeDescriptor(ThreadContext* ctx);
	CheckDefinition* check(ThreadContext* ctx);
	DropTableStatement* dropTableStatement(ThreadContext* ctx);
	CreateIndexStatement* createIndexStatement(ThreadContext* ctx);
	DropIndexStatement* dropIndexStatement(ThreadContext* ctx);
	ISQLExpression* sqlOrExpression(ThreadContext* ctx);
	ISQLExpression* sqlAndExpression(ThreadContext* ctx);
	ISQLExpression* sqlNotExpression(ThreadContext* ctx);
	ISQLExpression* sqlEqualityExpression(ThreadContext* ctx);
	ISQLExpression* sqlRelationalExpression(ThreadContext* ctx);
	ISQLExpression* sqlIsNullExpression(ThreadContext* ctx);
	ISQLExpression* sqlLikeExpression(ThreadContext* ctx);
	ISQLExpression* sqlInExpression(ThreadContext* ctx);
	ISQLExpression* sqlAdditiveExpression(ThreadContext* ctx);
	ISQLExpression* sqlMultiplicativeExpression(ThreadContext* ctx);
	ISQLExpression* sqlBaseExpression(ThreadContext* ctx);
	SQLExpressionStream* sqlExpressionStream(ThreadContext* ctx);
	SQLParenthesisExpression* sqlParenthesisExpression(ThreadContext* ctx);
	ISQLExpression* sqlColumnIdentifier(ThreadContext* ctx);
	ISQLBoolExpression* sqlBooleanLiteral(ThreadContext* ctx);
	ISQLExpression* sqlLiteral(ThreadContext* ctx);
	SQLExpressionList* sqlExpressionList(ThreadContext* ctx);
	ISQLExpression* sqlExpressionListElement(ThreadContext* ctx);
	ISQLExpression* sqlSubqueryExpression(ThreadContext* ctx);
	void ReInit(java::io::InputStream* stream, ThreadContext* ctx);
	void ReInit(java::io::InputStream* stream, String* encoding, ThreadContext* ctx);
	void ReInit(java::io::Reader* stream, ThreadContext* ctx);
	void ReInit(AlinousPlusParserTokenManager* tm, ThreadContext* ctx);
	Token* getNextToken(ThreadContext* ctx);
	Token* getToken(long long index, ThreadContext* ctx);
	ParseException* generateParseException(ThreadContext* ctx);
	void enable_tracing(ThreadContext* ctx);
	void disable_tracing(ThreadContext* ctx);
private:
	bool jj_2_1(long long xla, ThreadContext* ctx);
	bool jj_2_2(long long xla, ThreadContext* ctx);
	bool jj_2_3(long long xla, ThreadContext* ctx);
	bool jj_2_4(long long xla, ThreadContext* ctx);
	bool jj_2_5(long long xla, ThreadContext* ctx);
	bool jj_2_6(long long xla, ThreadContext* ctx);
	bool jj_2_7(long long xla, ThreadContext* ctx);
	bool jj_2_8(long long xla, ThreadContext* ctx);
	bool jj_2_9(long long xla, ThreadContext* ctx);
	bool jj_2_10(long long xla, ThreadContext* ctx);
	bool jj_2_11(long long xla, ThreadContext* ctx);
	bool jj_2_12(long long xla, ThreadContext* ctx);
	bool jj_2_13(long long xla, ThreadContext* ctx);
	bool jj_2_14(long long xla, ThreadContext* ctx);
	bool jj_2_15(long long xla, ThreadContext* ctx);
	bool jj_2_16(long long xla, ThreadContext* ctx);
	bool jj_2_17(long long xla, ThreadContext* ctx);
	bool jj_2_18(long long xla, ThreadContext* ctx);
	bool jj_2_19(long long xla, ThreadContext* ctx);
	bool jj_2_20(long long xla, ThreadContext* ctx);
	bool jj_2_21(long long xla, ThreadContext* ctx);
	bool jj_2_22(long long xla, ThreadContext* ctx);
	bool jj_2_23(long long xla, ThreadContext* ctx);
	bool jj_2_24(long long xla, ThreadContext* ctx);
	bool jj_2_25(long long xla, ThreadContext* ctx);
	bool jj_2_26(long long xla, ThreadContext* ctx);
	bool jj_2_27(long long xla, ThreadContext* ctx);
	bool jj_2_28(long long xla, ThreadContext* ctx);
	bool jj_2_29(long long xla, ThreadContext* ctx);
	bool jj_2_30(long long xla, ThreadContext* ctx);
	bool jj_2_31(long long xla, ThreadContext* ctx);
	bool jj_2_32(long long xla, ThreadContext* ctx);
	bool jj_2_33(long long xla, ThreadContext* ctx);
	bool jj_2_34(long long xla, ThreadContext* ctx);
	bool jj_2_35(long long xla, ThreadContext* ctx);
	bool jj_2_36(long long xla, ThreadContext* ctx);
	bool jj_2_37(long long xla, ThreadContext* ctx);
	bool jj_2_38(long long xla, ThreadContext* ctx);
	bool jj_2_39(long long xla, ThreadContext* ctx);
	bool jj_2_40(long long xla, ThreadContext* ctx);
	bool jj_2_41(long long xla, ThreadContext* ctx);
	bool jj_2_42(long long xla, ThreadContext* ctx);
	bool jj_2_43(long long xla, ThreadContext* ctx);
	bool jj_2_44(long long xla, ThreadContext* ctx);
	bool jj_2_45(long long xla, ThreadContext* ctx);
	bool jj_2_46(long long xla, ThreadContext* ctx);
	bool jj_2_47(long long xla, ThreadContext* ctx);
	bool jj_2_48(long long xla, ThreadContext* ctx);
	bool jj_2_49(long long xla, ThreadContext* ctx);
	bool jj_2_50(long long xla, ThreadContext* ctx);
	bool jj_2_51(long long xla, ThreadContext* ctx);
	bool jj_2_52(long long xla, ThreadContext* ctx);
	bool jj_2_53(long long xla, ThreadContext* ctx);
	bool jj_2_54(long long xla, ThreadContext* ctx);
	bool jj_2_55(long long xla, ThreadContext* ctx);
	bool jj_2_56(long long xla, ThreadContext* ctx);
	bool jj_2_57(long long xla, ThreadContext* ctx);
	bool jj_2_58(long long xla, ThreadContext* ctx);
	bool jj_2_59(long long xla, ThreadContext* ctx);
	bool jj_2_60(long long xla, ThreadContext* ctx);
	bool jj_2_61(long long xla, ThreadContext* ctx);
	bool jj_2_62(long long xla, ThreadContext* ctx);
	bool jj_2_63(long long xla, ThreadContext* ctx);
	bool jj_2_64(long long xla, ThreadContext* ctx);
	bool jj_2_65(long long xla, ThreadContext* ctx);
	bool jj_2_66(long long xla, ThreadContext* ctx);
	bool jj_2_67(long long xla, ThreadContext* ctx);
	bool jj_3R_96(ThreadContext* ctx);
	bool jj_3R_193(ThreadContext* ctx);
	bool jj_3R_132(ThreadContext* ctx);
	bool jj_3R_229(ThreadContext* ctx);
	bool jj_3R_162(ThreadContext* ctx);
	bool jj_3R_152(ThreadContext* ctx);
	bool jj_3R_69(ThreadContext* ctx);
	bool jj_3_60(ThreadContext* ctx);
	bool jj_3R_95(ThreadContext* ctx);
	bool jj_3R_209(ThreadContext* ctx);
	bool jj_3R_203(ThreadContext* ctx);
	bool jj_3_47(ThreadContext* ctx);
	bool jj_3R_53(ThreadContext* ctx);
	bool jj_3R_71(ThreadContext* ctx);
	bool jj_3R_124(ThreadContext* ctx);
	bool jj_3_46(ThreadContext* ctx);
	bool jj_3R_228(ThreadContext* ctx);
	bool jj_3R_123(ThreadContext* ctx);
	bool jj_3R_122(ThreadContext* ctx);
	bool jj_3_59(ThreadContext* ctx);
	bool jj_3R_198(ThreadContext* ctx);
	bool jj_3R_88(ThreadContext* ctx);
	bool jj_3_58(ThreadContext* ctx);
	bool jj_3_45(ThreadContext* ctx);
	bool jj_3R_55(ThreadContext* ctx);
	bool jj_3R_197(ThreadContext* ctx);
	bool jj_3R_78(ThreadContext* ctx);
	bool jj_3R_224(ThreadContext* ctx);
	bool jj_3R_196(ThreadContext* ctx);
	bool jj_3R_77(ThreadContext* ctx);
	bool jj_3_57(ThreadContext* ctx);
	bool jj_3R_207(ThreadContext* ctx);
	bool jj_3R_175(ThreadContext* ctx);
	bool jj_3_56(ThreadContext* ctx);
	bool jj_3R_206(ThreadContext* ctx);
	bool jj_3R_220(ThreadContext* ctx);
	bool jj_3R_133(ThreadContext* ctx);
	bool jj_3R_102(ThreadContext* ctx);
	bool jj_3_55(ThreadContext* ctx);
	bool jj_3_4(ThreadContext* ctx);
	bool jj_3_44(ThreadContext* ctx);
	bool jj_3R_204(ThreadContext* ctx);
	bool jj_3R_205(ThreadContext* ctx);
	bool jj_3R_135(ThreadContext* ctx);
	bool jj_3_43(ThreadContext* ctx);
	bool jj_3_3(ThreadContext* ctx);
	bool jj_3R_47(ThreadContext* ctx);
	bool jj_3R_189(ThreadContext* ctx);
	bool jj_3R_227(ThreadContext* ctx);
	bool jj_3R_134(ThreadContext* ctx);
	bool jj_3R_74(ThreadContext* ctx);
	bool jj_3R_179(ThreadContext* ctx);
	bool jj_3_2(ThreadContext* ctx);
	bool jj_3R_178(ThreadContext* ctx);
	bool jj_3R_177(ThreadContext* ctx);
	bool jj_3R_176(ThreadContext* ctx);
	bool jj_3R_46(ThreadContext* ctx);
	bool jj_3R_72(ThreadContext* ctx);
	bool jj_3R_136(ThreadContext* ctx);
	bool jj_3R_226(ThreadContext* ctx);
	bool jj_3R_73(ThreadContext* ctx);
	bool jj_3_41(ThreadContext* ctx);
	bool jj_3R_141(ThreadContext* ctx);
	bool jj_3_33(ThreadContext* ctx);
	bool jj_3_32(ThreadContext* ctx);
	bool jj_3R_79(ThreadContext* ctx);
	bool jj_3_40(ThreadContext* ctx);
	bool jj_3R_131(ThreadContext* ctx);
	bool jj_3R_138(ThreadContext* ctx);
	bool jj_3_31(ThreadContext* ctx);
	bool jj_3R_130(ThreadContext* ctx);
	bool jj_3_54(ThreadContext* ctx);
	bool jj_3_39(ThreadContext* ctx);
	bool jj_3R_93(ThreadContext* ctx);
	bool jj_3_30(ThreadContext* ctx);
	bool jj_3R_253(ThreadContext* ctx);
	bool jj_3R_137(ThreadContext* ctx);
	bool jj_3R_70(ThreadContext* ctx);
	bool jj_3R_86(ThreadContext* ctx);
	bool jj_3R_251(ThreadContext* ctx);
	bool jj_3_1(ThreadContext* ctx);
	bool jj_3R_250(ThreadContext* ctx);
	bool jj_3R_249(ThreadContext* ctx);
	bool jj_3R_85(ThreadContext* ctx);
	bool jj_3_53(ThreadContext* ctx);
	bool jj_3_38(ThreadContext* ctx);
	bool jj_3R_84(ThreadContext* ctx);
	bool jj_3R_92(ThreadContext* ctx);
	bool jj_3R_126(ThreadContext* ctx);
	bool jj_3_29(ThreadContext* ctx);
	bool jj_3R_199(ThreadContext* ctx);
	bool jj_3R_83(ThreadContext* ctx);
	bool jj_3R_174(ThreadContext* ctx);
	bool jj_3_28(ThreadContext* ctx);
	bool jj_3_27(ThreadContext* ctx);
	bool jj_3R_125(ThreadContext* ctx);
	bool jj_3R_173(ThreadContext* ctx);
	bool jj_3R_172(ThreadContext* ctx);
	bool jj_3R_82(ThreadContext* ctx);
	bool jj_3R_171(ThreadContext* ctx);
	bool jj_3_52(ThreadContext* ctx);
	bool jj_3R_170(ThreadContext* ctx);
	bool jj_3R_169(ThreadContext* ctx);
	bool jj_3R_168(ThreadContext* ctx);
	bool jj_3R_167(ThreadContext* ctx);
	bool jj_3R_87(ThreadContext* ctx);
	bool jj_3R_81(ThreadContext* ctx);
	bool jj_3R_129(ThreadContext* ctx);
	bool jj_3R_57(ThreadContext* ctx);
	bool jj_3R_56(ThreadContext* ctx);
	bool jj_3_13(ThreadContext* ctx);
	bool jj_3R_80(ThreadContext* ctx);
	bool jj_3_26(ThreadContext* ctx);
	bool jj_3R_159(ThreadContext* ctx);
	bool jj_3R_68(ThreadContext* ctx);
	bool jj_3_12(ThreadContext* ctx);
	bool jj_3R_235(ThreadContext* ctx);
	bool jj_3_42(ThreadContext* ctx);
	bool jj_3R_210(ThreadContext* ctx);
	bool jj_3_25(ThreadContext* ctx);
	bool jj_3R_67(ThreadContext* ctx);
	bool jj_3R_188(ThreadContext* ctx);
	bool jj_3R_158(ThreadContext* ctx);
	bool jj_3R_76(ThreadContext* ctx);
	bool jj_3_37(ThreadContext* ctx);
	bool jj_3_36(ThreadContext* ctx);
	bool jj_3_9(ThreadContext* ctx);
	bool jj_3_24(ThreadContext* ctx);
	bool jj_3R_187(ThreadContext* ctx);
	bool jj_3R_66(ThreadContext* ctx);
	bool jj_3_10(ThreadContext* ctx);
	bool jj_3_11(ThreadContext* ctx);
	bool jj_3R_186(ThreadContext* ctx);
	bool jj_3R_185(ThreadContext* ctx);
	bool jj_3R_140(ThreadContext* ctx);
	bool jj_3R_184(ThreadContext* ctx);
	bool jj_3R_183(ThreadContext* ctx);
	bool jj_3R_244(ThreadContext* ctx);
	bool jj_3R_182(ThreadContext* ctx);
	bool jj_3R_151(ThreadContext* ctx);
	bool jj_3R_150(ThreadContext* ctx);
	bool jj_3R_242(ThreadContext* ctx);
	bool jj_3R_192(ThreadContext* ctx);
	bool jj_3R_111(ThreadContext* ctx);
	bool jj_3_35(ThreadContext* ctx);
	bool jj_3_23(ThreadContext* ctx);
	bool jj_3R_110(ThreadContext* ctx);
	bool jj_3R_65(ThreadContext* ctx);
	bool jj_3R_237(ThreadContext* ctx);
	bool jj_3_34(ThreadContext* ctx);
	bool jj_3R_109(ThreadContext* ctx);
	bool jj_3R_161(ThreadContext* ctx);
	bool jj_3R_108(ThreadContext* ctx);
	bool jj_3R_107(ThreadContext* ctx);
	bool jj_3R_106(ThreadContext* ctx);
	bool jj_3R_105(ThreadContext* ctx);
	bool jj_3R_104(ThreadContext* ctx);
	bool jj_3R_103(ThreadContext* ctx);
	bool jj_3R_212(ThreadContext* ctx);
	bool jj_3_21(ThreadContext* ctx);
	bool jj_3R_48(ThreadContext* ctx);
	bool jj_3R_243(ThreadContext* ctx);
	bool jj_3R_238(ThreadContext* ctx);
	bool jj_3R_239(ThreadContext* ctx);
	bool jj_3_22(ThreadContext* ctx);
	bool jj_3R_191(ThreadContext* ctx);
	bool jj_3R_128(ThreadContext* ctx);
	bool jj_3R_211(ThreadContext* ctx);
	bool jj_3R_190(ThreadContext* ctx);
	bool jj_3R_139(ThreadContext* ctx);
	bool jj_3R_160(ThreadContext* ctx);
	bool jj_3R_222(ThreadContext* ctx);
	bool jj_3R_64(ThreadContext* ctx);
	bool jj_3R_248(ThreadContext* ctx);
	bool jj_3R_113(ThreadContext* ctx);
	bool jj_3R_246(ThreadContext* ctx);
	bool jj_3R_52(ThreadContext* ctx);
	bool jj_3R_247(ThreadContext* ctx);
	bool jj_3_20(ThreadContext* ctx);
	bool jj_3R_63(ThreadContext* ctx);
	bool jj_3R_245(ThreadContext* ctx);
	bool jj_3R_241(ThreadContext* ctx);
	bool jj_3R_240(ThreadContext* ctx);
	bool jj_3_19(ThreadContext* ctx);
	bool jj_3R_62(ThreadContext* ctx);
	bool jj_3R_91(ThreadContext* ctx);
	bool jj_3R_234(ThreadContext* ctx);
	bool jj_3_8(ThreadContext* ctx);
	bool jj_3R_90(ThreadContext* ctx);
	bool jj_3R_181(ThreadContext* ctx);
	bool jj_3R_114(ThreadContext* ctx);
	bool jj_3R_120(ThreadContext* ctx);
	bool jj_3_51(ThreadContext* ctx);
	bool jj_3R_149(ThreadContext* ctx);
	bool jj_3_18(ThreadContext* ctx);
	bool jj_3R_148(ThreadContext* ctx);
	bool jj_3R_75(ThreadContext* ctx);
	bool jj_3R_61(ThreadContext* ctx);
	bool jj_3_7(ThreadContext* ctx);
	bool jj_3R_121(ThreadContext* ctx);
	bool jj_3_67(ThreadContext* ctx);
	bool jj_3R_100(ThreadContext* ctx);
	bool jj_3R_115(ThreadContext* ctx);
	bool jj_3R_51(ThreadContext* ctx);
	bool jj_3R_112(ThreadContext* ctx);
	bool jj_3R_157(ThreadContext* ctx);
	bool jj_3R_101(ThreadContext* ctx);
	bool jj_3_17(ThreadContext* ctx);
	bool jj_3_6(ThreadContext* ctx);
	bool jj_3R_60(ThreadContext* ctx);
	bool jj_3R_49(ThreadContext* ctx);
	bool jj_3R_156(ThreadContext* ctx);
	bool jj_3R_223(ThreadContext* ctx);
	bool jj_3_66(ThreadContext* ctx);
	bool jj_3R_89(ThreadContext* ctx);
	bool jj_3R_194(ThreadContext* ctx);
	bool jj_3R_155(ThreadContext* ctx);
	bool jj_3R_163(ThreadContext* ctx);
	bool jj_3R_116(ThreadContext* ctx);
	bool jj_3R_145(ThreadContext* ctx);
	bool jj_3R_144(ThreadContext* ctx);
	bool jj_3_16(ThreadContext* ctx);
	bool jj_3R_143(ThreadContext* ctx);
	bool jj_3_50(ThreadContext* ctx);
	bool jj_3R_59(ThreadContext* ctx);
	bool jj_3R_142(ThreadContext* ctx);
	bool jj_3R_94(ThreadContext* ctx);
	bool jj_3R_214(ThreadContext* ctx);
	bool jj_3R_154(ThreadContext* ctx);
	bool jj_3R_213(ThreadContext* ctx);
	bool jj_3R_195(ThreadContext* ctx);
	bool jj_3R_180(ThreadContext* ctx);
	bool jj_3R_232(ThreadContext* ctx);
	bool jj_3_15(ThreadContext* ctx);
	bool jj_3R_164(ThreadContext* ctx);
	bool jj_3_14(ThreadContext* ctx);
	bool jj_3R_166(ThreadContext* ctx);
	bool jj_3R_127(ThreadContext* ctx);
	bool jj_3R_233(ThreadContext* ctx);
	bool jj_3_49(ThreadContext* ctx);
	bool jj_3R_201(ThreadContext* ctx);
	bool jj_3_65(ThreadContext* ctx);
	bool jj_3_64(ThreadContext* ctx);
	bool jj_3R_153(ThreadContext* ctx);
	bool jj_3R_98(ThreadContext* ctx);
	bool jj_3R_165(ThreadContext* ctx);
	bool jj_3R_200(ThreadContext* ctx);
	bool jj_3R_58(ThreadContext* ctx);
	bool jj_3R_119(ThreadContext* ctx);
	bool jj_3R_99(ThreadContext* ctx);
	bool jj_3R_118(ThreadContext* ctx);
	bool jj_3R_221(ThreadContext* ctx);
	bool jj_3R_219(ThreadContext* ctx);
	bool jj_3R_117(ThreadContext* ctx);
	bool jj_3R_218(ThreadContext* ctx);
	bool jj_3R_236(ThreadContext* ctx);
	bool jj_3R_217(ThreadContext* ctx);
	bool jj_3R_216(ThreadContext* ctx);
	bool jj_3R_215(ThreadContext* ctx);
	bool jj_3R_252(ThreadContext* ctx);
	bool jj_3R_202(ThreadContext* ctx);
	bool jj_3R_50(ThreadContext* ctx);
	bool jj_3_5(ThreadContext* ctx);
	bool jj_3R_230(ThreadContext* ctx);
	bool jj_3_48(ThreadContext* ctx);
	bool jj_3R_208(ThreadContext* ctx);
	bool jj_3R_97(ThreadContext* ctx);
	bool jj_3R_225(ThreadContext* ctx);
	bool jj_3_62(ThreadContext* ctx);
	bool jj_3_63(ThreadContext* ctx);
	bool jj_3R_231(ThreadContext* ctx);
	bool jj_3_61(ThreadContext* ctx);
	bool jj_3R_147(ThreadContext* ctx);
	bool jj_3R_54(ThreadContext* ctx);
	bool jj_3R_146(ThreadContext* ctx);
	Token* jj_consume_token(long long kind, ThreadContext* ctx);
	bool jj_scan_token(long long kind, ThreadContext* ctx);
	long long jj_ntk_f(ThreadContext* ctx);
	void jj_add_error_token(long long kind, long long pos, ThreadContext* ctx);
	void jj_rescan_token(ThreadContext* ctx);
	void jj_save(long long index, long long xla, ThreadContext* ctx);
private:
	static void jj_la1_init_0(ThreadContext* ctx);
	static void jj_la1_init_1(ThreadContext* ctx);
	static void jj_la1_init_2(ThreadContext* ctx);
	static void jj_la1_init_3(ThreadContext* ctx);
	static void jj_la1_init_4(ThreadContext* ctx);
	static void jj_la1_init_5(ThreadContext* ctx);
	static void jj_la1_init_6(ThreadContext* ctx);
public:



	class LookaheadSuccess final : public java::lang::Error {
	public:
		LookaheadSuccess(const LookaheadSuccess& base) = default;
	public:
		LookaheadSuccess(ThreadContext* ctx) throw()  : IObject(ctx), java::lang::Error(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~LookaheadSuccess() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class JJCalls final : public virtual IObject {
	public:
		JJCalls(const JJCalls& base) = default;
	public:
		JJCalls(ThreadContext* ctx) throw()  : IObject(ctx), gen(0), first(nullptr), arg(0), next(nullptr)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~JJCalls() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		long long gen;
		Token* first;
		long long arg;
		AlinousPlusParser::JJCalls* next;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, AlinousPlusParser::jj_la1_0, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, AlinousPlusParser::jj_la1_1, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, AlinousPlusParser::jj_la1_2, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, AlinousPlusParser::jj_la1_3, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, AlinousPlusParser::jj_la1_4, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, AlinousPlusParser::jj_la1_5, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, AlinousPlusParser::jj_la1_6, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
	}
};

}}

#endif /* end of ALINOUS_COMPILE_ALINOUSPLUSPARSER_H_ */
