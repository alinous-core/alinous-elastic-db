#ifndef ALINOUS_COMPILE_EXPRESSION_IEXPRESSIONFACTORY_H_
#define ALINOUS_COMPILE_EXPRESSION_IEXPRESSIONFACTORY_H_
namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

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
class NotExpression;}}}}

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

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
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
using ::alinous::compile::sql::InsertValues;
using ::alinous::compile::sql::UpdateSet;
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
using ::alinous::compile::sql::select::join::SQLJoinCondition;
using ::alinous::system::AlinousException;



class IExpressionFactory final : public virtual IObject {
public:
	IExpressionFactory(const IExpressionFactory& base) = default;
public:
	IExpressionFactory(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IExpressionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int __SQLAdditiveExpression{1};
	constexpr static const int __SQLMultiplicativeExpression{2};
	constexpr static const int __SQLSubqueryExpression{3};
	constexpr static const int __SQLColumnIdentifier{4};
	constexpr static const int __SQLLiteral{5};
	constexpr static const int __SQLParenthesisExpression{6};
	constexpr static const int __InsertValues{7};
	constexpr static const int __SQLAndExpression{8};
	constexpr static const int __SQLOrExpression{9};
	constexpr static const int __SQLBooleanLiteral{10};
	constexpr static const int __SQLBoolSubExpression{11};
	constexpr static const int __SQLEqualityExpression{12};
	constexpr static const int __SQLInExpression{13};
	constexpr static const int __SQLIsNullExpression{14};
	constexpr static const int __SQLJoinCondition{15};
	constexpr static const int __SQLLikeExpression{16};
	constexpr static const int __SQLNotExpression{17};
	constexpr static const int __SQLRelationalExpression{18};
	constexpr static const int __SQLSubExpression{19};
	constexpr static const int __SQLExpressionList{20};
	constexpr static const int __SQLExpressionListAll{21};
	constexpr static const int __SQLExpressionStream{22};
	constexpr static const int __SQLFrom{23};
	constexpr static const int __SQLGroupBy{24};
	constexpr static const int __UpdateSet{25};
	constexpr static const int __AndExpression{101};
	constexpr static const int __ConditionalAndExpression{102};
	constexpr static const int __ConditionalOrExpression{103};
	constexpr static const int __ExclusiveOrExpression{104};
	constexpr static const int __InclusiveOrExpression{105};
	constexpr static const int __EqualityExpression{106};
	constexpr static const int __InstanceOfExpression{107};
	constexpr static const int __NotExpression{108};
	constexpr static const int __RelationalExpression{109};
	constexpr static const int __AdditiveExpression{110};
	constexpr static const int __MultiplicativeExpression{111};
	constexpr static const int __ShiftExpression{112};
	constexpr static const int __AllocationExpression{113};
	constexpr static const int __BitReverseExpression{114};
	constexpr static const int __BooleanSubExpression{115};
	constexpr static const int __CastExpression{116};
	constexpr static const int __ConditionalExpression{117};
	constexpr static const int __ExpStreamCast{118};
	constexpr static const int __ExpStreamParenthesis{119};
	constexpr static const int __ExpStreamSegment{120};
	constexpr static const int __FunctionArguments{121};
	constexpr static const int __FunctionCallExpression{122};
	constexpr static const int __Literal{123};
	constexpr static const int __BooleanLiteral{124};
	constexpr static const int __NullLiteral{125};
	constexpr static const int __ParenthesisExpression{126};
	constexpr static const int __PreDecrementExpression{127};
	constexpr static const int __PreIncrementExpression{128};
	constexpr static const int __SubExpression{129};
	constexpr static const int __UnaryExpression{130};
	constexpr static const int __DomVariableDescriptor{131};
	constexpr static const int __ExpressionStream{132};
public:
	static IExpression* fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_IEXPRESSIONFACTORY_H_ */
