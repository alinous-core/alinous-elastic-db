#ifndef ALINOUS_BTREE_IBTREEKEY_H_
#define ALINOUS_BTREE_IBTREEKEY_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace java {namespace lang {
template <typename  T> class Comparable;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btree {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::runtime::dom::VariableException;



class IBTreeKey : public virtual IObject, public Comparable<IBTreeKey> {
public:
	IBTreeKey(const IBTreeKey& base) = default;
public:
	IBTreeKey(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IBTreeKey() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int TYPE_SIZE{4};
	constexpr static const int TYPE_INT{1};
	constexpr static const int TYPE_LONG{2};
	constexpr static const int TYPE_STRING{3};
	constexpr static const int TYPE_TIMESTAMP{4};
	constexpr static const int TYPE_DOUBLE{5};
	constexpr static const int TYPE_BTREE_INDEX_KEY{6};
	constexpr static const int TYPE_SCAN_RESULT_INDEX_KEY{7};
	constexpr static const int TYPE_TABLE_FULL_NAME_KEY{8};
public:
	virtual void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) = 0;
	virtual int size(ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BTREE_IBTREEKEY_H_ */
