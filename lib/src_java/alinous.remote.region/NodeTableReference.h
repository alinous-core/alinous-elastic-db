#ifndef ALINOUS_REMOTE_REGION_NODETABLEREFERENCE_H_
#define ALINOUS_REMOTE_REGION_NODETABLEREFERENCE_H_
namespace alinous {namespace remote {namespace region {
class NodeReference;}}}

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



class NodeTableReference final : public virtual IObject {
public:
	NodeTableReference(const NodeTableReference& base) = default;
public:
	NodeTableReference(String* host, int port, ThreadContext* ctx) throw() ;
	void __construct_impl(String* host, int port, ThreadContext* ctx) throw() ;
	virtual ~NodeTableReference() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* host;
	int port;
public:
	String* getHost(ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODETABLEREFERENCE_H_ */
