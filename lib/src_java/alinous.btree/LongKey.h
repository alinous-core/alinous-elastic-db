#ifndef ALINOUS_BTREE_LONGKEY_H_
#define ALINOUS_BTREE_LONGKEY_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class LongKey;}}

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



class LongKey final : public IBTreeKey, public virtual IObject {
public:
	LongKey(const LongKey& base) = default;
public:
	LongKey(long long v, ThreadContext* ctx) throw() ;
	void __construct_impl(long long v, ThreadContext* ctx) throw() ;
	virtual ~LongKey() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long value;
public:
	constexpr static const int BASE_SIZE{8};
public:
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw()  final;
	int size(ThreadContext* ctx) throw()  final;
	int compareTo(IBTreeKey* another, ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	bool equals(LongKey* obj, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of ALINOUS_BTREE_LONGKEY_H_ */
