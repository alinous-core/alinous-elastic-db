#ifndef ALINOUS_DB_TABLE_LOCALOIDCOUNTER_H_
#define ALINOUS_DB_TABLE_LOCALOIDCOUNTER_H_
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class LocalOidCounter;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IValueFetcher;}}

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
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IValueFetcher;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class LocalOidCounter final : public IBTreeValue, public virtual IObject {
public:
	class ValueFetcher;
	LocalOidCounter(const LocalOidCounter& base) = default;
public:
	LocalOidCounter(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	LocalOidCounter(long long nextOid, ThreadContext* ctx) throw() ;
	void __construct_impl(long long nextOid, ThreadContext* ctx) throw() ;
	virtual ~LocalOidCounter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long nextOid;
public:
	const static LocalOidCounter::ValueFetcher __fetcher;
	constexpr static LocalOidCounter::ValueFetcher* fetcher{const_cast<LocalOidCounter::ValueFetcher*>(&__fetcher)};
public:
	long long newOid(ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int diskSize(ThreadContext* ctx) final;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
public:
	static LocalOidCounter* fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() ;
public:



	class ValueFetcher final : public IValueFetcher, public virtual IObject {
	public:
		ValueFetcher(const ValueFetcher& base) = default;
	public:
		ValueFetcher(ThreadContext* ctx) throw()  : IObject(ctx), IValueFetcher(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~ValueFetcher() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IBTreeValue* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw()  final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_LOCALOIDCOUNTER_H_ */
