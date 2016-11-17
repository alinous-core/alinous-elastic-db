#ifndef ALINOUS_BTREE_IBTREEVALUE_H_
#define ALINOUS_BTREE_IBTREEVALUE_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::alinous::runtime::dom::VariableException;



class IBTreeValue : public virtual IObject {
public:
	IBTreeValue(const IBTreeValue& base) = default;
public:
	IBTreeValue(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IBTreeValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int TYPE_SIZE{4};
	constexpr static const int TYPE_INT{1};
	constexpr static const int TYPE_LONG{2};
	constexpr static const int TYPE_STRING{3};
	constexpr static const int TYPE_TIMESTAMP{4};
	constexpr static const int TYPE_DOUBLE{5};
	constexpr static const int TYPE_SCHEME{6};
	constexpr static const int TYPE_CACHE_RECORD{7};
	constexpr static const int TYPE_DATABASE_RECORD{8};
	constexpr static const int TYPE_SCAN_RESULT_RECORD{9};
	constexpr static const int TYPE_DOM_VARIABLE_RECORD{10};
	constexpr static const int TYPE_TABLE_INDEX_VALUE{11};
	constexpr static const int TYPE_PADDING_RECORD{12};
public:
	virtual void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) = 0;
	virtual int diskSize(ThreadContext* ctx) = 0;
	virtual bool equals(IObject* obj, ThreadContext* ctx) throw()  = 0;
	virtual IValueFetcher* getFetcher(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_IBTREEVALUE_H_ */
