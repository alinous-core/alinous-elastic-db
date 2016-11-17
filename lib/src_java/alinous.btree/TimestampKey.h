#ifndef ALINOUS_BTREE_TIMESTAMPKEY_H_
#define ALINOUS_BTREE_TIMESTAMPKEY_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class TimestampKey;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

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



class TimestampKey final : public IBTreeKey, public virtual IObject {
public:
	TimestampKey(const TimestampKey& base) = default;
public:
	TimestampKey(long long mills, ThreadContext* ctx) throw() ;
	void __construct_impl(long long mills, ThreadContext* ctx) throw() ;
	virtual ~TimestampKey() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long value;
public:
	constexpr static const int BASE_SIZE{8};
public:
	int compareTo(IBTreeKey* another, ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	bool equals(TimestampKey* obj, ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw()  final;
	int size(ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
	class ValueCompare {
	public:
		int operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of ALINOUS_BTREE_TIMESTAMPKEY_H_ */
