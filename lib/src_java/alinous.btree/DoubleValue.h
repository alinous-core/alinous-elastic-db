#ifndef ALINOUS_BTREE_DOUBLEVALUE_H_
#define ALINOUS_BTREE_DOUBLEVALUE_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class DoubleValue;}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btree {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;



class DoubleValue final : public IBTreeValue, public virtual IObject {
public:
	class ValueFetcher;
	DoubleValue(const DoubleValue& base) = default;
public:
	DoubleValue(double v, ThreadContext* ctx) throw() ;
	void __construct_impl(double v, ThreadContext* ctx) throw() ;
	virtual ~DoubleValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	double value;
public:
	const static DoubleValue::ValueFetcher __fetcher;
	constexpr static DoubleValue::ValueFetcher* fetcher{const_cast<DoubleValue::ValueFetcher*>(&__fetcher)};
public:
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw()  final;
	int diskSize(ThreadContext* ctx) throw()  final;
	double getValue(ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
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

}}

#endif /* end of ALINOUS_BTREE_DOUBLEVALUE_H_ */
