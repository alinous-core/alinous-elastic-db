#ifndef ALINOUS_COMPILE_SQL_ANALYZE_INNERNECESSARYCONDITION_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_INNERNECESSARYCONDITION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexConditionDetector;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexScanStrategy;}}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

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
using ::alinous::db::AlinousDatabase;
using ::alinous::system::AlinousException;



class InnerNecessaryCondition final : public virtual IObject {
public:
	InnerNecessaryCondition(const InnerNecessaryCondition& base) = default;
public:
	InnerNecessaryCondition(ISQLExpression* exp, ThreadContext* ctx) throw() ;
	void __construct_impl(ISQLExpression* exp, ThreadContext* ctx) throw() ;
	virtual ~InnerNecessaryCondition() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ISQLExpression* exp;
	IndexScanStrategy* strategy;
public:
	void analyze(ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx);
	ISQLExpression* getExp(ThreadContext* ctx) throw() ;
	IndexScanStrategy* getStrategy(ThreadContext* ctx) throw() ;
	bool optimizeIndexStrategy(AlinousDatabase* database, ArrayList<ScanTableColumnIdentifier>* joinRequest, ThreadContext* ctx) throw() ;
public:
	static void includes(IndexConditionDetector* arg0, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_INNERNECESSARYCONDITION_H_ */
