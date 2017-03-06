#ifndef ALINOUS_COMPILE_SQL_SELECT_JOIN_IJOINTARGET_H_
#define ALINOUS_COMPILE_SQL_SELECT_JOIN_IJOINTARGET_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoin;}}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IJoinTarget : public IJoin {
public:
	IJoinTarget(const IJoinTarget& base) = default;
public:
	IJoinTarget(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IJoinTarget() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_SELECT_JOIN_IJOINTARGET_H_ */
