#ifndef ALINOUS_COMPILE_SQL_SELECT_JOIN_RIGHTJOIN_H_
#define ALINOUS_COMPILE_SQL_SELECT_JOIN_RIGHTJOIN_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class LeftJoin;}}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class RightJoin final : public LeftJoin {
public:
	RightJoin(const RightJoin& base) = default;
public:
	RightJoin(ThreadContext* ctx) throw()  : IObject(ctx), LeftJoin(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RightJoin() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void setLeft(IJoin* left, ThreadContext* ctx) throw()  final;
	void setRight(IJoin* right, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_SELECT_JOIN_RIGHTJOIN_H_ */
