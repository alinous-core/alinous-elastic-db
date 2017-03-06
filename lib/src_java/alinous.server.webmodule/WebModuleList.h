#ifndef ALINOUS_SERVER_WEBMODULE_WEBMODULELIST_H_
#define ALINOUS_SERVER_WEBMODULE_WEBMODULELIST_H_
namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace alinous {namespace server {namespace webmodule {
class AbstractWebModule;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace webmodule {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::buffer::FifoElement;



class WebModuleList final : public virtual IObject {
public:
	WebModuleList(const WebModuleList& base) = default;
public:
	WebModuleList(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~WebModuleList() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<FifoElement<AbstractWebModule>>* list;
public:
	void add(FifoElement<AbstractWebModule>* module, ThreadContext* ctx) throw() ;
	FifoElement<AbstractWebModule>* find(String* path, ThreadContext* ctx) throw() ;
	void removeElement(String* path, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_WEBMODULELIST_H_ */
