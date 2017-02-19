#ifndef ALINOUS_DB_TABLE_IOIDPUBLISHER_H_
#define ALINOUS_DB_TABLE_IOIDPUBLISHER_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IOidPublisher : public virtual IObject {
public:
	IOidPublisher(const IOidPublisher& base) = default;
public:
	IOidPublisher(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IOidPublisher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual long long newOid(String* tableFullName, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_IOIDPUBLISHER_H_ */
