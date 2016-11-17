#ifndef ALINOUS_DB_TABLE_IDATABASERECORD_H_
#define ALINOUS_DB_TABLE_IDATABASERECORD_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::btree::IBTreeValue;
using ::alinous::runtime::variant::VariantValue;



class IDatabaseRecord : public virtual IObject, public IBTreeValue {
public:
	IDatabaseRecord(const IDatabaseRecord& base) = default;
public:
	IDatabaseRecord(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IDatabaseRecord() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int NORMAL_RECORD{0};
	constexpr static const int TRX_CACHE{1};
	constexpr static const int DOM_VARIABLE{3};
	constexpr static const int NULL_PADDING{4};
public:
	virtual int getKind(ThreadContext* ctx) throw()  = 0;
	virtual VariantValue* getColumnValue(int colOrder, ThreadContext* ctx) throw()  = 0;
	virtual int getNumValues(ThreadContext* ctx) throw()  = 0;
	virtual long long getInsertedCommitId(ThreadContext* ctx) throw()  = 0;
	virtual long long getLastUpdateCommitId(ThreadContext* ctx) throw()  = 0;
	virtual long long getDeletedCommitId(ThreadContext* ctx) throw()  = 0;
	virtual ArrayList<VariantValue>* getValues(ThreadContext* ctx) throw()  = 0;
	virtual void setValue(int index, VariantValue* value, ThreadContext* ctx) throw()  = 0;
	virtual void addValue(VariantValue* vv, ThreadContext* ctx) throw()  = 0;
	virtual long long getOid(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_IDATABASERECORD_H_ */
