#ifndef ALINOUS_REMOTE_REGION_NODEREFERENCE_H_
#define ALINOUS_REMOTE_REGION_NODEREFERENCE_H_
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



class NodeReference final : public virtual IObject {
public:
	NodeReference(const NodeReference& base) = default;
public:
	NodeReference(String* host, int port, ThreadContext* ctx) throw() ;
	void __construct_impl(String* host, int port, ThreadContext* ctx) throw() ;
	virtual ~NodeReference() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* host;
	int port;
public:
	String* getHost(ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODEREFERENCE_H_ */
