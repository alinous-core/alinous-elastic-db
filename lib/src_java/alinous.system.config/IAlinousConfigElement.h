#ifndef ALINOUS_SYSTEM_CONFIG_IALINOUSCONFIGELEMENT_H_
#define ALINOUS_SYSTEM_CONFIG_IALINOUSCONFIGELEMENT_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IAlinousConfigElement : public virtual IObject {
public:
	IAlinousConfigElement(const IAlinousConfigElement& base) = default;
public:
	IAlinousConfigElement(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IAlinousConfigElement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_IALINOUSCONFIGELEMENT_H_ */
