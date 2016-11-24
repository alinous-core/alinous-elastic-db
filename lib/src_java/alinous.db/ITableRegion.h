#ifndef ALINOUS_DB_ITABLEREGION_H_
#define ALINOUS_DB_ITABLEREGION_H_
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



class ITableRegion : public virtual IObject {
public:
	ITableRegion(const ITableRegion& base) = default;
public:
	ITableRegion(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ITableRegion() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_ITABLEREGION_H_ */
