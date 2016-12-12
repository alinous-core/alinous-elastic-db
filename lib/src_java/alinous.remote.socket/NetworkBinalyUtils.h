#ifndef ALINOUS_REMOTE_SOCKET_NETWORKBINALYUTILS_H_
#define ALINOUS_REMOTE_SOCKET_NETWORKBINALYUTILS_H_
namespace java {namespace io {
class InputStream;}}

namespace java {namespace nio {
class ByteBuffer;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace socket {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::nio::ByteBuffer;



class NetworkBinalyUtils final : public virtual IObject {
public:
	NetworkBinalyUtils(const NetworkBinalyUtils& base) = default;
public:
	NetworkBinalyUtils(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NetworkBinalyUtils() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static long long readLong(InputStream* stream, ThreadContext* ctx);
	static int readInt(InputStream* stream, ThreadContext* ctx);
	static short readShort(InputStream* stream, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_SOCKET_NETWORKBINALYUTILS_H_ */
