#ifndef ALINOUS_DB_TABLE_INDEXINSERTJOB_H_
#define ALINOUS_DB_TABLE_INDEXINSERTJOB_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class TableIndex;}}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

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
using ::alinous::runtime::parallel::IThreadAction;



class IndexInsertJob final : public IThreadAction, public virtual IObject {
public:
	IndexInsertJob(const IndexInsertJob& base) = default;
public:
	IndexInsertJob(TableIndex* tableIndex, DatabaseRecord* dbrecord, ThreadContext* ctx) throw() ;
	void __construct_impl(TableIndex* tableIndex, DatabaseRecord* dbrecord, ThreadContext* ctx) throw() ;
	virtual ~IndexInsertJob() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TableIndex* tableIndex;
	DatabaseRecord* dbrecord;
public:
	void execute(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_INDEXINSERTJOB_H_ */
