#ifndef ALINOUS_COMPILE_SQL_ANALYZE_JOINSTRATEGYPART_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_JOINSTRATEGYPART_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinMatchExpression;}}}}

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



class JoinStrategyPart final : public virtual IObject {
public:
	JoinStrategyPart(const JoinStrategyPart& base) = default;
public:
	JoinStrategyPart(ThreadContext* ctx) throw()  : IObject(ctx), andexpressions(GCUtils<ArrayList<JoinMatchExpression> >::ins(this, (new(ctx) ArrayList<JoinMatchExpression>(ctx)), ctx, __FILEW__, __LINE__, L"")), bestExp(nullptr), indexStatus(-1)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~JoinStrategyPart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<JoinMatchExpression>* andexpressions;
	JoinMatchExpression* bestExp;
	int indexStatus;
public:
	void calcIindexStatus(ThreadContext* ctx) throw() ;
	JoinMatchExpression* getBestExp(ThreadContext* ctx) throw() ;
	void addExpression(JoinMatchExpression* matchExp, ThreadContext* ctx) throw() ;
	ArrayList<JoinMatchExpression>* getExpressions(ThreadContext* ctx) throw() ;
	bool requireFullScan(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_JOINSTRATEGYPART_H_ */
