#ifndef ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_
#define ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_
namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace remote {namespace region {
class NodeReference;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Map;



class NodeReferenceManager final : public virtual IObject {
public:
	NodeReferenceManager(const NodeReferenceManager& base) = default;
public:
	NodeReferenceManager(ThreadContext* ctx) throw()  : IObject(ctx), tablesDictinary(GCUtils<Map<String,NodeReference> >::ins(this, (new(ctx) HashMap<String,NodeReference>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NodeReferenceManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,NodeReference>* tablesDictinary;
public:
	Map<String,NodeReference>* getTablesDictinary(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_ */
