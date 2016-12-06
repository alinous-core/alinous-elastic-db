#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_TABLE_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_TABLE_H_
namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace system {namespace config {namespace remote {
class NodeRef;}}}}

namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {namespace remote {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::system::config::IAlinousConfigElement;



class Table final : public IAlinousConfigElement, public virtual IObject {
public:
	Table(const Table& base) = default;
public:
	Table(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), scheme(__GC_INS(this, ConstStr::getCNST_STR_951(), String)), name(nullptr), keys(GCUtils<List<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), nodeRefs(GCUtils<List<NodeRef> >::ins(this, (new(ctx) ArrayList<NodeRef>(ctx)), ctx, __FILEW__, __LINE__, L"")), max(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Table() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* scheme;
	String* name;
	List<String>* keys;
	List<NodeRef>* nodeRefs;
	String* max;
public:
	String* getScheme(ThreadContext* ctx) throw() ;
	void setScheme(String* scheme, ThreadContext* ctx) throw() ;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	List<String>* getKeys(ThreadContext* ctx) throw() ;
	void addKey(String* key, ThreadContext* ctx) throw() ;
	void addNodeRef(NodeRef* node, ThreadContext* ctx) throw() ;
	List<NodeRef>* getNodeRefs(ThreadContext* ctx) throw() ;
	String* getMax(ThreadContext* ctx) throw() ;
	void setMax(String* max, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_TABLE_H_ */
