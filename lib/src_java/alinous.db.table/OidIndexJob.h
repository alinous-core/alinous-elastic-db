#ifndef ALINOUS_DB_TABLE_OIDINDEXJOB_H_
#define ALINOUS_DB_TABLE_OIDINDEXJOB_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace btree {
class LongValue;}}

namespace alinous {namespace db {namespace table {
class BTreeIndexKey;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::btree::BTree;
using ::alinous::btree::LongValue;
using ::alinous::lock::ConcurrentGate;
using ::alinous::runtime::parallel::IThreadAction;
using ::alinous::runtime::variant::VariantValue;



class OidIndexJob final : public IThreadAction, public virtual IObject {
public:
	OidIndexJob(const OidIndexJob& base) = default;
public:
	OidIndexJob(long long nextOid, BTree* oidIndex, long long position, ThreadContext* ctx) throw() ;
	void __construct_impl(long long nextOid, BTree* oidIndex, long long position, ThreadContext* ctx) throw() ;
	virtual ~OidIndexJob() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long nextOid;
	BTree* oidIndex;
	long long position;
public:
	void execute(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_OIDINDEXJOB_H_ */
