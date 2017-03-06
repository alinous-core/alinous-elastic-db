#ifndef ALINOUS_COMPILE_SQL_ANALYZE_INDEXCONDITIONDETECTOR_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_INDEXCONDITIONDETECTOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexScanStrategy;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class AbstractSQLBooleanCollectionExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLAndExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLParenthesisExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLBoolSubExpression;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::alinous::system::AlinousException;



class IndexConditionDetector final : public virtual IObject {
public:
	IndexConditionDetector(const IndexConditionDetector& base) = default;
public:
	IndexConditionDetector(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IndexConditionDetector() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static IndexScanStrategy* detect(ISQLExpression* boolExpression, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx);
private:
	static void andExpression(SQLAndExpression* expression, IndexScanStrategy* indexes, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx);
	static void handleExpression(ISQLExpression* expression, IndexScanStrategy* indexes, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_INDEXCONDITIONDETECTOR_H_ */
