#ifndef ALINOUS_DB_TABLE_OIDPUBLISHERFACTORY_H_
#define ALINOUS_DB_TABLE_OIDPUBLISHERFACTORY_H_
namespace alinous {namespace db {namespace table {
class IOidPublisher;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

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
using ::alinous::buffer::storage::FileStorage;



class OidPublisherFactory final : public virtual IObject {
public:
	OidPublisherFactory(const OidPublisherFactory& base) = default;
public:
	OidPublisherFactory(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~OidPublisherFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static IOidPublisher* create(FileStorage* storage, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_OIDPUBLISHERFACTORY_H_ */
