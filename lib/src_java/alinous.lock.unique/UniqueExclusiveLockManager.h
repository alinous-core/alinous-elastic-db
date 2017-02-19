#ifndef ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCKMANAGER_H_
#define ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCKMANAGER_H_
namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace lock {namespace unique {
class TableUniqueCollections;}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace lock {namespace unique {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;



class UniqueExclusiveLockManager final : public virtual IObject {
public:
	UniqueExclusiveLockManager(const UniqueExclusiveLockManager& base) = default;
public:
	UniqueExclusiveLockManager(ThreadContext* ctx) throw()  : IObject(ctx), tables(GCUtils<Map<String,TableUniqueCollections> >::ins(this, (new(ctx) HashMap<String,TableUniqueCollections>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~UniqueExclusiveLockManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,TableUniqueCollections>* tables;
public:
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCKMANAGER_H_ */
