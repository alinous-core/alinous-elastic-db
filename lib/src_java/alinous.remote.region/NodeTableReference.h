#ifndef ALINOUS_REMOTE_REGION_NODETABLEREFERENCE_H_
#define ALINOUS_REMOTE_REGION_NODETABLEREFERENCE_H_
namespace alinous {namespace remote {namespace region {
class NodeReference;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionRangeCollection;}}}

namespace alinous {namespace remote {namespace region {
class NodeTableReference;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::TablePartitionRangeCollection;



class NodeTableReference final : public virtual IObject {
public:
	NodeTableReference(const NodeTableReference& base) = default;
public:
	NodeTableReference(String* host, int port, bool ipv6, NodeReference* nodeAccessRef, TablePartitionRangeCollection* range, ThreadContext* ctx) throw() ;
	void __construct_impl(String* host, int port, bool ipv6, NodeReference* nodeAccessRef, TablePartitionRangeCollection* range, ThreadContext* ctx) throw() ;
	virtual ~NodeTableReference() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* host;
	int port;
	bool ipv6;
	TablePartitionRangeCollection* range;
	NodeReference* nodeAccessRef;
public:
	String* getHost(ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	bool isIpv6(ThreadContext* ctx) throw() ;
	TablePartitionRangeCollection* getRange(ThreadContext* ctx) throw() ;
	void setRange(TablePartitionRangeCollection* range, ThreadContext* ctx) throw() ;
	NodeReference* getNodeAccessRef(ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	bool equals(NodeTableReference* ref, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODETABLEREFERENCE_H_ */
