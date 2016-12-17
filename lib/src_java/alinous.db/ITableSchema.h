#ifndef ALINOUS_DB_ITABLESCHEMA_H_
#define ALINOUS_DB_ITABLESCHEMA_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::IDatabaseTable;



class ITableSchema : public virtual IObject {
public:
	ITableSchema(const ITableSchema& base) = default;
public:
	ITableSchema(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ITableSchema() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual IDatabaseTable* getTableStore(String* tableName, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_ITABLESCHEMA_H_ */
