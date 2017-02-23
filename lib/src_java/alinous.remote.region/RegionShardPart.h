#ifndef ALINOUS_REMOTE_REGION_REGIONSHARDPART_H_
#define ALINOUS_REMOTE_REGION_REGIONSHARDPART_H_
namespace alinous {namespace remote {namespace region {
class NodeTableReference;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionRangeCollection;}}}

namespace alinous {namespace remote {namespace region {
class NodeReference;}}}

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



class RegionShardPart final : public virtual IObject {
public:
	RegionShardPart(const RegionShardPart& base) = default;
public:
	RegionShardPart(NodeTableReference* nodeRef, ThreadContext* ctx) throw() ;
	void __construct_impl(NodeTableReference* nodeRef, ThreadContext* ctx) throw() ;
	virtual ~RegionShardPart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TablePartitionRangeCollection* partitionRange;
	NodeReference* nodeAccessRef;
public:
	TablePartitionRangeCollection* getPartitionRange(ThreadContext* ctx) throw() ;
	NodeReference* getNodeAccessRef(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_REGIONSHARDPART_H_ */
