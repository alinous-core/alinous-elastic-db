#ifndef ALINOUS_COMPILE_SQL_ANALYZE_JOINSTRATEGY_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_JOINSTRATEGY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexConditionDetector;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinConditionDetector;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinStrategyPart;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

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



class JoinStrategy final : public virtual IObject {
public:
	JoinStrategy(const JoinStrategy& base) = default;
public:
	JoinStrategy(bool inner, ThreadContext* ctx) throw() ;
	void __construct_impl(bool inner, ThreadContext* ctx) throw() ;
	virtual ~JoinStrategy() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ISQLExpression* joinCondition;
	ISQLExpression* whereCondition;
	ArrayList<JoinStrategyPart>* joinPart;
	ArrayList<JoinStrategyPart>* innerPart;
	bool inner;
	ArrayList<JoinStrategyPart>* bestParts;
public:
	void analyze(SQLAnalyseContext* context, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ThreadContext* ctx) throw() ;
	void setJoinCondition(ISQLExpression* joinCondition, ThreadContext* ctx) throw() ;
	void setWhereCondition(ISQLExpression* whereCondition, ThreadContext* ctx) throw() ;
	ISQLExpression* getJoinCondition(ThreadContext* ctx) throw() ;
	ArrayList<JoinStrategyPart>* getJoinPart(ThreadContext* ctx) throw() ;
	ArrayList<JoinStrategyPart>* getInnerPart(ThreadContext* ctx) throw() ;
	bool isInner(ThreadContext* ctx) throw() ;
	ArrayList<JoinStrategyPart>* getBestParts(ThreadContext* ctx) throw() ;
private:
	void analyzeBestJoinKey(ThreadContext* ctx) throw() ;
public:
	static void includes(IndexConditionDetector* arg0, JoinConditionDetector* arg1, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_JOINSTRATEGY_H_ */
