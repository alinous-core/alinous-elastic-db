#ifndef ALINOUS_COMPILE_SQL_ANALYZE_BOOLEANFILTERCONDITIONUTIL_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_BOOLEANFILTERCONDITIONUTIL_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class InnerNecessaryCondition;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class AbstractSQLBooleanCollectionExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLOrExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLBoolSubExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLParenthesisExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLAndExpression;}}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::compile::sql::expression::SQLParenthesisExpression;
using ::alinous::compile::sql::expression::blexp::AbstractSQLBooleanCollectionExpression;
using ::alinous::compile::sql::expression::blexp::SQLAndExpression;
using ::alinous::compile::sql::expression::blexp::SQLBoolSubExpression;
using ::alinous::compile::sql::expression::blexp::SQLOrExpression;



class BooleanFilterConditionUtil final : public virtual IObject {
public:
	BooleanFilterConditionUtil(const BooleanFilterConditionUtil& base) = default;
public:
	BooleanFilterConditionUtil(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~BooleanFilterConditionUtil() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static ArrayList<InnerNecessaryCondition>* fetchCondition(ISQLExpression* boolExpression, ScanTableIdentifier* table, ThreadContext* ctx) throw() ;
private:
	static ISQLExpression* handleExpression(ISQLExpression* currentExpression, ScanTableIdentifier* table, ThreadContext* ctx) throw() ;
	static ISQLExpression* handleContainerExpression(AbstractSQLBooleanCollectionExpression* currentExpression, ScanTableIdentifier* table, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_BOOLEANFILTERCONDITIONUTIL_H_ */
