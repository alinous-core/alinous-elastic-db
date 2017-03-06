#ifndef ALINOUS_DB_TABLE_DATATABLELOCKSUPPORT_H_
#define ALINOUS_DB_TABLE_DATATABLELOCKSUPPORT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class DataTableStorageSupport;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class DatatableLockSupport : public DataTableStorageSupport {
public:
	DatatableLockSupport(const DatatableLockSupport& base) = default;
public:
	DatatableLockSupport(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	void __construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	virtual ~DatatableLockSupport() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void lockStorage(ThreadContext* ctx) final;
	void unlockStorage(ThreadContext* ctx) final;
	void sharelockStorage(ThreadContext* ctx);
	void shareunlockStorage(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATATABLELOCKSUPPORT_H_ */
