#ifndef ALINOUS_SERVER_ALINOUSCORESERVER_H_
#define ALINOUS_SERVER_ALINOUSCORESERVER_H_
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace server {namespace http {
class AlinousHttpServer;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::server::http::AlinousHttpServer;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class AlinousCoreServer final : public virtual IObject {
public:
	AlinousCoreServer(const AlinousCoreServer& base) = default;
public:
	AlinousCoreServer(String* home, bool debug, int debugPort, ThreadContext* ctx);
	void __construct_impl(String* home, bool debug, int debugPort, ThreadContext* ctx);
	virtual ~AlinousCoreServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousCore* core;
	AlinousHttpServer* httpServer;
public:
	void startHttpServer(int maxThread, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_SERVER_ALINOUSCORESERVER_H_ */
