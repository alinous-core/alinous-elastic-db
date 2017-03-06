#ifndef ALINOUS_COMPILE_SQL_ANALYZE_INDEXSCANSTRATEGY_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_INDEXSCANSTRATEGY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexScanStrategyPlan;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class AbstractSQLBooleanExpression;}}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexColumnMatchCondition;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIndexMetadata;}}}}

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
using ::alinous::compile::sql::expression::blexp::AbstractSQLBooleanExpression;
using ::alinous::system::AlinousException;



class IndexScanStrategy final : public virtual IObject {
public:
	IndexScanStrategy(const IndexScanStrategy& base) = default;
public:
	IndexScanStrategy(ScanTableMetadata* metadata, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableMetadata* metadata, ThreadContext* ctx) throw() ;
	virtual ~IndexScanStrategy() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<IndexScanStrategyPlan>* list;
	ScanTableMetadata* metadata;
	bool alwaysEmpty;
	IndexScanStrategyPlan* bestplan;
public:
	bool calcBestIndexPlan(ArrayList<ScanTableColumnIdentifier>* joinRequest, ThreadContext* ctx) throw() ;
	IndexScanStrategyPlan* getBestPlan(ArrayList<ScanTableColumnIdentifier>* joinRequest, ThreadContext* ctx) throw() ;
	void addExpression(ISQLExpression* boolExpression, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx);
	bool isAlwaysEmpty(ThreadContext* ctx) throw() ;
	void setAlwaysEmpty(bool alwaysEmpty, ThreadContext* ctx) throw() ;
	void copy(ThreadContext* ctx) throw() ;
private:
	void joinEqIndex(IndexColumnMatchCondition* matchingCondition, bool debug, ThreadContext* ctx);
	void joinIntoRangeWithAfter(IndexColumnMatchCondition* matchingCondition, ThreadContext* ctx) throw() ;
	void joinIntoRangeWithBefore(IndexColumnMatchCondition* matchingCondition, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_INDEXSCANSTRATEGY_H_ */
