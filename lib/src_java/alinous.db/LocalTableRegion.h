#ifndef ALINOUS_DB_LOCALTABLEREGION_H_
#define ALINOUS_DB_LOCALTABLEREGION_H_
namespace alinous {namespace db {
class ITableRegion;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class LocalTableRegion final : public ITableRegion, public virtual IObject {
public:
	LocalTableRegion(const LocalTableRegion& base) = default;
public:
	LocalTableRegion(ThreadContext* ctx) throw()  : IObject(ctx), ITableRegion(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~LocalTableRegion() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_LOCALTABLEREGION_H_ */
