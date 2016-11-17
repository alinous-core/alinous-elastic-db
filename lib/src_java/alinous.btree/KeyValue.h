#ifndef ALINOUS_BTREE_KEYVALUE_H_
#define ALINOUS_BTREE_KEYVALUE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class BTreeValues;}}

namespace alinous {namespace btree {
class KeyValue;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

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
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::runtime::dom::VariableException;



class KeyValue final : public virtual IObject {
public:
	KeyValue(const KeyValue& base) = default;
public:
	KeyValue(IBTreeKey* key, BTreeValues* values, ThreadContext* ctx) throw() ;
	void __construct_impl(IBTreeKey* key, BTreeValues* values, ThreadContext* ctx) throw() ;
	KeyValue(IBTreeKey* key, ThreadContext* ctx) throw() ;
	void __construct_impl(IBTreeKey* key, ThreadContext* ctx) throw() ;
	virtual ~KeyValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTreeKey* key;
	BTreeValues* values;
public:
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	int keySize(ThreadContext* ctx);
	int valueSize(ThreadContext* ctx);
	IBTreeKey* getKey(ThreadContext* ctx) throw() ;
	void setKey(IBTreeKey* key, ThreadContext* ctx) throw() ;
	BTreeValues* getValues(ThreadContext* ctx) throw() ;
	void setValues(BTreeValues* values, ThreadContext* ctx) throw() ;
public:
	static KeyValue* fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_KEYVALUE_H_ */
