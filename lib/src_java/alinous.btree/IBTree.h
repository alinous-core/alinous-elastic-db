#ifndef ALINOUS_BTREE_IBTREE_H_
#define ALINOUS_BTREE_IBTREE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace java {namespace io {
class IOException;}}

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

namespace alinous {namespace btree {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class IBTree : public virtual IObject {
public:
	IBTree(const IBTree& base) = default;
public:
	IBTree(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IBTree() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void initTreeStorage(int nodeCapacity, int keyType, int valueType, long long capacity, long long BLOCK_SIZE, ThreadContext* ctx) = 0;
	virtual void open(ThreadContext* ctx) = 0;
	virtual void close(ThreadContext* ctx) = 0;
	virtual bool isOpened(ThreadContext* ctx) throw()  = 0;
	virtual IBTreeNode* findByKey(IBTreeKey* longKey, ThreadContext* ctx) = 0;
	virtual bool isEmpty(ThreadContext* ctx) throw()  = 0;
	virtual IBTreeNode* getRootNode(ThreadContext* ctx) = 0;
	virtual void putKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx) = 0;
	virtual void putKey(IBTreeKey* key, ThreadContext* ctx) = 0;
	virtual void appendKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_IBTREE_H_ */
