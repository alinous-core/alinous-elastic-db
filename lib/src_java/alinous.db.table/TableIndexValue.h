#ifndef ALINOUS_DB_TABLE_TABLEINDEXVALUE_H_
#define ALINOUS_DB_TABLE_TABLEINDEXVALUE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace alinous {namespace db {namespace table {
class TableIndexValue;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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



class TableIndexValue final : public IBTreeValue, public virtual IObject {
public:
	class ValueFetcher;
	TableIndexValue(const TableIndexValue& base) = default;
public:
	TableIndexValue(long long oid, long long position, ThreadContext* ctx) throw() ;
	void __construct_impl(long long oid, long long position, ThreadContext* ctx) throw() ;
	virtual ~TableIndexValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long oid;
	long long position;
public:
	const static TableIndexValue::ValueFetcher __fetcher;
	constexpr static TableIndexValue::ValueFetcher* fetcher{const_cast<TableIndexValue::ValueFetcher*>(&__fetcher)};
public:
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int diskSize(ThreadContext* ctx) final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
	long long getOid(ThreadContext* ctx) throw() ;
	void setOid(long long oid, ThreadContext* ctx) throw() ;
	long long getPosition(ThreadContext* ctx) throw() ;
	void setPosition(long long position, ThreadContext* ctx) throw() ;
public:



	class ValueFetcher final : public IValueFetcher, public virtual IObject {
	public:
		ValueFetcher(const ValueFetcher& base) = default;
	public:
		ValueFetcher(ThreadContext* ctx) throw() ;
		void __construct_impl(ThreadContext* ctx) throw() ;
		virtual ~ValueFetcher() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IBTreeValue* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw()  final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLEINDEXVALUE_H_ */
