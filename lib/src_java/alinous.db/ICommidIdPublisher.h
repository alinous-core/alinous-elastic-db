#ifndef ALINOUS_DB_ICOMMIDIDPUBLISHER_H_
#define ALINOUS_DB_ICOMMIDIDPUBLISHER_H_
namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::system::AlinousException;



class ICommidIdPublisher : public virtual IObject {
public:
	ICommidIdPublisher(const ICommidIdPublisher& base) = default;
public:
	ICommidIdPublisher(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ICommidIdPublisher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void setMaxCommitId(long long maxCommitId, ThreadContext* ctx) throw()  = 0;
	virtual long long getMaxCommitId(ThreadContext* ctx) = 0;
	virtual long long newCommitId(ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_ICOMMIDIDPUBLISHER_H_ */
