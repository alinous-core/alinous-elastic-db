#ifndef ALINOUS_REMOTE_REGION_CLIENT_REMOTETABLESCHEME_H_
#define ALINOUS_REMOTE_REGION_CLIENT_REMOTETABLESCHEME_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {
class ITableSchema;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::ITableSchema;
using ::alinous::db::table::IDatabaseTable;



class RemoteTableScheme final : public ITableSchema, public virtual IObject {
public:
	RemoteTableScheme(const RemoteTableScheme& base) = default;
public:
	RemoteTableScheme(ThreadContext* ctx) throw()  : IObject(ctx), ITableSchema(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RemoteTableScheme() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IDatabaseTable* getTableStore(String* tableName, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_REMOTETABLESCHEME_H_ */
