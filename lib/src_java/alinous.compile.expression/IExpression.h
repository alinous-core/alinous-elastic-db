#ifndef ALINOUS_COMPILE_EXPRESSION_IEXPRESSION_H_
#define ALINOUS_COMPILE_EXPRESSION_IEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace compile {
class IAlinousVisitorContainer;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousVisitorContainer;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class IExpression : public IAlinousElement, public IAlinousVisitorContainer {
public:
	IExpression(const IExpression& base) = default;
public:
	IExpression(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int andExpression{1};
	constexpr static const int conditionalAndExpression{2};
	constexpr static const int exclusiveOrExpression{3};
	constexpr static const int inclusiveOrExpression{4};
	constexpr static const int equalityExpression{5};
	constexpr static const int instanceOfExpression{6};
	constexpr static const int notExpression{7};
	constexpr static const int relationalExpression{8};
	constexpr static const int additiveExpression{9};
	constexpr static const int multiplicativeExpression{10};
	constexpr static const int shiftExpression{11};
	constexpr static const int allocationExpressionType{12};
	constexpr static const int bitReverseExpression{13};
	constexpr static const int booleanSubExpression{14};
	constexpr static const int castExpression{15};
	constexpr static const int conditionalExpression{16};
	constexpr static const int expStreamCast{17};
	constexpr static const int expStreamParenthesis{18};
	constexpr static const int expStreamSegment{19};
	constexpr static const int functionArguments{20};
	constexpr static const int functionCallExpression{21};
	constexpr static const int literalType{22};
	constexpr static const int booleanLiteral{23};
	constexpr static const int nullLiteral{24};
	constexpr static const int parenthesisExpression{25};
	constexpr static const int preDecrementExpression{26};
	constexpr static const int preIncrementExpression{27};
	constexpr static const int subExpression{28};
	constexpr static const int unaryExpression{29};
	constexpr static const int domVariableDescriptor{30};
	constexpr static const int expressionStream{31};
	constexpr static const int sQLAdditiveExpression{32};
	constexpr static const int sQLMultiplicativeExpression{33};
	constexpr static const int sQLSubqueryExpression{34};
	constexpr static const int sQLColumnIdentifier{35};
	constexpr static const int sQLLiteralType{36};
	constexpr static const int sQLParenthesisExpression{37};
	constexpr static const int insertValues{38};
	constexpr static const int sQLExpressionStream{39};
	constexpr static const int sQLFrom{40};
	constexpr static const int sQLGroupBy{41};
	constexpr static const int updateSet{42};
	constexpr static const int sQLAndExpression{43};
	constexpr static const int sQLOrExpression{44};
	constexpr static const int sQLBooleanLiteral{45};
	constexpr static const int sQLBoolSubExpression{46};
	constexpr static const int sQLEqualityExpression{47};
	constexpr static const int sQLInExpression{48};
	constexpr static const int sQLIsNullExpression{49};
	constexpr static const int sQLJoinCondition{50};
	constexpr static const int sQLLikeExpression{51};
	constexpr static const int sQLNotExpression{52};
	constexpr static const int sQLRelationalExpression{53};
	constexpr static const int sQLSubExpression{54};
	constexpr static const int sQLExpressionList{55};
	constexpr static const int sQLExpressionListAll{56};
public:
	virtual int getExpressionType(ThreadContext* ctx) throw()  = 0;
	virtual IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  = 0;
	virtual bool isConstant(ThreadContext* ctx) throw()  = 0;
	virtual bool isSQLExp(ThreadContext* ctx) throw()  = 0;
	virtual int fileSize(ThreadContext* ctx) = 0;
	virtual void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) = 0;
	virtual void fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_IEXPRESSION_H_ */
