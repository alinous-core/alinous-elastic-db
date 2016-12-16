#ifndef ALINOUS_DB_TABLE_LOCALOIDPUBLISHER_H_
#define ALINOUS_DB_TABLE_LOCALOIDPUBLISHER_H_
namespace alinous {namespace db {namespace table {
class IOidPublisher;}}}

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



class LocalOidPublisher final : public IOidPublisher, public virtual IObject {
public:
	LocalOidPublisher(const LocalOidPublisher& base) = default;
public:
	LocalOidPublisher(int nextOid, ThreadContext* ctx) throw() ;
	void __construct_impl(int nextOid, ThreadContext* ctx) throw() ;
	virtual ~LocalOidPublisher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long nextOid;
public:
	long long newOid(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_LOCALOIDPUBLISHER_H_ */
