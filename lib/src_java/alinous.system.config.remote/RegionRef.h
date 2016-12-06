#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_REGIONREF_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_REGIONREF_H_
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



class RegionRef final : public IAlinousConfigElement, public virtual IObject {
public:
	RegionRef(const RegionRef& base) = default;
public:
	RegionRef(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), name(nullptr), url(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RegionRef() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	String* url;
public:
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
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

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_REGIONREF_H_ */
