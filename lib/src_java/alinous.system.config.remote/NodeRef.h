#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_NODEREF_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_NODEREF_H_
namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {namespace remote {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::system::config::IAlinousConfigElement;



class NodeRef final : public IAlinousConfigElement, public virtual IObject {
public:
	NodeRef(const NodeRef& base) = default;
public:
	NodeRef(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), url(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NodeRef() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* url;
public:
	String* getUrl(ThreadContext* ctx) throw() ;
	void setUrl(String* url, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_NODEREF_H_ */
