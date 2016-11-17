#ifndef ALINOUS_NET_UNKNOWNHOSTEXCEPTION_H_
#define ALINOUS_NET_UNKNOWNHOSTEXCEPTION_H_
namespace java {namespace io {
class IOException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace net {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;



class UnknownHostException final : public IOException {
public:
	UnknownHostException(const UnknownHostException& base) = default;
public:
	UnknownHostException(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	UnknownHostException(String* detailMessage, ThreadContext* ctx) throw() ;
	void __construct_impl(String* detailMessage, ThreadContext* ctx) throw() ;
	virtual ~UnknownHostException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{-4639126076052875403L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_NET_UNKNOWNHOSTEXCEPTION_H_ */
