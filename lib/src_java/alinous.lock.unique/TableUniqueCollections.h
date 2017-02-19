#ifndef ALINOUS_LOCK_UNIQUE_TABLEUNIQUECOLLECTIONS_H_
#define ALINOUS_LOCK_UNIQUE_TABLEUNIQUECOLLECTIONS_H_
namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace lock {namespace unique {
class ColumnsUniqueCollections;}}}

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



class TableUniqueCollections final : public virtual IObject {
public:
	TableUniqueCollections(const TableUniqueCollections& base) = default;
public:
	TableUniqueCollections(ThreadContext* ctx) throw()  : IObject(ctx), uniqueLocks(GCUtils<Map<String,ColumnsUniqueCollections> >::ins(this, (new(ctx) HashMap<String,ColumnsUniqueCollections>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TableUniqueCollections() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,ColumnsUniqueCollections>* uniqueLocks;
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

#endif /* end of ALINOUS_LOCK_UNIQUE_TABLEUNIQUECOLLECTIONS_H_ */
