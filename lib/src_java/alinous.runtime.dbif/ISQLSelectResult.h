#ifndef ALINOUS_RUNTIME_DBIF_ISQLSELECTRESULT_H_
#define ALINOUS_RUNTIME_DBIF_ISQLSELECTRESULT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dbif {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class ISQLSelectResult : public virtual IObject {
public:
	ISQLSelectResult(const ISQLSelectResult& base) = default;
public:
	ISQLSelectResult(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ISQLSelectResult() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_DBIF_ISQLSELECTRESULT_H_ */
