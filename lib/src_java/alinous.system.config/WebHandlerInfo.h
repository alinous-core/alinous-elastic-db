#ifndef ALINOUS_SYSTEM_CONFIG_WEBHANDLERINFO_H_
#define ALINOUS_SYSTEM_CONFIG_WEBHANDLERINFO_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

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



class WebHandlerInfo final : public IAlinousConfigElement, public virtual IObject {
public:
	WebHandlerInfo(const WebHandlerInfo& base) = default;
public:
	WebHandlerInfo(String* alinousHome, ThreadContext* ctx) throw() ;
	void __construct_impl(String* alinousHome, ThreadContext* ctx) throw() ;
	virtual ~WebHandlerInfo() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* documentRoot;
	String* alinousHome;
	int port;
public:
	String* getDocumentRoot(ThreadContext* ctx) throw() ;
	void setDocumentRoot(String* documentRoot, ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	void setPort(int port, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_WEBHANDLERINFO_H_ */
