#ifndef ALINOUS_DB_TABLE_SCAN_UPDATEHISTORYVALUESITERATOR_H_
#define ALINOUS_DB_TABLE_SCAN_UPDATEHISTORYVALUESITERATOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::btree::IBTreeValue;
using ::alinous::db::table::DatabaseRecord;



class UpdateHistoryValuesIterator final : public virtual IObject {
public:
	UpdateHistoryValuesIterator(const UpdateHistoryValuesIterator& base) = default;
public:
	UpdateHistoryValuesIterator(ArrayList<IBTreeValue>* values, long long commitId, ThreadContext* ctx) throw() ;
	void __construct_impl(ArrayList<IBTreeValue>* values, long long commitId, ThreadContext* ctx) throw() ;
	virtual ~UpdateHistoryValuesIterator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long commitId;
	ArrayList<IBTreeValue>* values;
	int maxCount;
	int current;
public:
	DatabaseRecord* next(ThreadContext* ctx) throw() ;
	bool hasNext(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_SCAN_UPDATEHISTORYVALUESITERATOR_H_ */
