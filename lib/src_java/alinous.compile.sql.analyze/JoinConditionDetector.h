#ifndef ALINOUS_COMPILE_SQL_ANALYZE_JOINCONDITIONDETECTOR_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_JOINCONDITIONDETECTOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinStrategyPart;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class AbstractSQLBooleanCollectionExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLAndExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLBoolSubExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLOrExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLParenthesisExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinMatchExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLEqualityExpression;}}}}}

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
using ::alinous::compile::sql::expression::blexp::SQLEqualityExpression;
using ::alinous::compile::sql::expression::blexp::SQLOrExpression;



class JoinConditionDetector final : public virtual IObject {
public:
	JoinConditionDetector(const JoinConditionDetector& base) = default;
public:
	JoinConditionDetector(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~JoinConditionDetector() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static ArrayList<JoinStrategyPart>* getJoinPart(SQLAnalyseContext* context, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ISQLExpression* joinCondition, ThreadContext* ctx) throw() ;
private:
	static JoinMatchExpression* checkExpression(SQLAnalyseContext* context, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ISQLExpression* joinCondition, ThreadContext* ctx) throw() ;
	static void handleStrategyPart(SQLAnalyseContext* context, ISQLExpression* joinCondition, ArrayList<JoinStrategyPart>* list, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, JoinStrategyPart* current, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_JOINCONDITIONDETECTOR_H_ */
