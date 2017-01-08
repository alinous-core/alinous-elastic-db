#ifndef ALINOUS_REMOTE_REGION_NODETABLECLASTER_H_
#define ALINOUS_REMOTE_REGION_NODETABLECLASTER_H_
namespace alinous {namespace remote {namespace region {
class NodeTableReference;}}}

namespace java {namespace util {
template <typename  T> class List;}}

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
using ::java::util::ArrayList;
using ::java::util::List;



class NodeTableClaster final : public virtual IObject {
public:
	NodeTableClaster(const NodeTableClaster& base) = default;
public:
	NodeTableClaster(ThreadContext* ctx) throw()  : IObject(ctx), nodes(GCUtils<List<NodeTableReference> >::ins(this, (new(ctx) ArrayList<NodeTableReference>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NodeTableClaster() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<NodeTableReference>* nodes;
public:
	void addNode(NodeTableReference* nodeRef, ThreadContext* ctx) throw() ;
	List<NodeTableReference>* getNodes(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODETABLECLASTER_H_ */
