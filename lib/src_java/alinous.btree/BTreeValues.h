#ifndef ALINOUS_BTREE_BTREEVALUES_H_
#define ALINOUS_BTREE_BTREEVALUES_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace btree {
class IBTreeValue;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

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
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::runtime::dom::VariableException;



class BTreeValues final : public virtual IObject {
public:
	BTreeValues(const BTreeValues& base) = default;
public:
	BTreeValues(ThreadContext* ctx) throw()  : IObject(ctx), values(GCUtils<ArrayList<IBTreeValue> >::ins(this, (new(ctx) ArrayList<IBTreeValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~BTreeValues() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<IBTreeValue>* values;
public:
	void addValue(IBTreeValue* value, ThreadContext* ctx) throw() ;
	bool contains(IBTreeValue* value, ThreadContext* ctx) throw() ;
	void remove(IBTreeValue* value, ThreadContext* ctx) throw() ;
	void clearValues(ThreadContext* ctx) throw() ;
	IBTreeValue* get(int index, ThreadContext* ctx) throw() ;
	int numValues(ThreadContext* ctx) throw() ;
	int size(ThreadContext* ctx);
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	ArrayList<IBTreeValue>* getValues(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_BTREEVALUES_H_ */
