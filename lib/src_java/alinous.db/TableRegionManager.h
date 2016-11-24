#ifndef ALINOUS_DB_TABLEREGIONMANAGER_H_
#define ALINOUS_DB_TABLEREGIONMANAGER_H_
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



class TableRegionManager final : public virtual IObject {
public:
	TableRegionManager(const TableRegionManager& base) = default;
public:
	TableRegionManager(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TableRegionManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_TABLEREGIONMANAGER_H_ */
