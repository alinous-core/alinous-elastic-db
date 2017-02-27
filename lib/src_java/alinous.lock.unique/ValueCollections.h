#ifndef ALINOUS_LOCK_UNIQUE_VALUECOLLECTIONS_H_
#define ALINOUS_LOCK_UNIQUE_VALUECOLLECTIONS_H_
namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace lock {namespace unique {
class ValueCollections;}}}

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

namespace alinous {namespace lock {namespace unique {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::btree::IBTreeKey;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::runtime::dom::VariableException;



class ValueCollections final : public IBTreeKey, public virtual IObject {
public:
	ValueCollections(const ValueCollections& base) = default;
public:
	ValueCollections(IDatabaseRecord* value, ThreadContext* ctx) throw() ;
	void __construct_impl(IDatabaseRecord* value, ThreadContext* ctx) throw() ;
	virtual ~ValueCollections() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IDatabaseRecord* value;
public:
	int compareTo(IBTreeKey* another, ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int size(ThreadContext* ctx) final;
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

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_VALUECOLLECTIONS_H_ */
