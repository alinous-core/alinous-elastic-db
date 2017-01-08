#ifndef ALINOUS_REMOTE_SOCKET_ICOMMANDDATA_H_
#define ALINOUS_REMOTE_SOCKET_ICOMMANDDATA_H_
namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

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



class ICommandData : public virtual IObject {
public:
	ICommandData(const ICommandData& base) = default;
public:
	ICommandData(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ICommandData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  = 0;
	virtual void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_SOCKET_ICOMMANDDATA_H_ */
