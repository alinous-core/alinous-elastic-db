#ifndef ALINOUS_DB_TABLE_LOCALOIDPUBLISHER_H_
#define ALINOUS_DB_TABLE_LOCALOIDPUBLISHER_H_
namespace alinous {namespace db {namespace table {
class LocalOidCounter;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace db {namespace table {
class LocalOidPublisher;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace db {namespace table {
class IOidPublisher;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IValueFetcher;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::lock::LockObject;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class LocalOidPublisher final : public IOidPublisher, public virtual IObject {
public:
	LocalOidPublisher(const LocalOidPublisher& base) = default;
public:
	LocalOidPublisher(ThreadContext* ctx) throw()  : IObject(ctx), IOidPublisher(ctx), tables(GCUtils<Map<String,LocalOidCounter> >::ins(this, (new(ctx) HashMap<String,LocalOidCounter>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~LocalOidPublisher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,LocalOidCounter>* tables;
	LockObject* lock;
public:
	long long newOid(String* tableFullName, ThreadContext* ctx) throw()  final;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int diskSize(ThreadContext* ctx) final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
public:
	static LocalOidPublisher* fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_LOCALOIDPUBLISHER_H_ */
